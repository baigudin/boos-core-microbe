/** 
 * Silicon Labs C8051F9x MCUs timer driver.  
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2018, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#include "CpuTimer.h" 
#include "CpuRegisters.h"
#include "CpuConfiguration.h"

/**
 * Number of possible resources.
 */
#define RES_NUMBER (2)

/**
 * The resource owner ID.
 */
#define RES_OWNER_ID (0x80)

/**
 * The resource owner mask.
 */
#define RES_OWNER_MASK (0x80)

/**
 * The resource index mask.
 */
#define RES_INDEX_MASK (0x01)

/**
 * Timer 0/1 clock in Hz.
 */  
#define TIMER_CLOCK (CPU_CLOCK / TIMER_DIVIDER)

/**
 * Timer 0/1 clock in KHz.
 */  
#define TIMER_CLOCK_KHZ (TIMER_CLOCK / 1000)

/**
 * Locked flag of each resource.
 */
static int8 lock_[RES_NUMBER];

/**
 * The driver has been initialized successfully.
 */
static int8 isInitialized_;

/**
 * Tests if passed value is the resource.
 *
 * @param res - an driver resource. 
 * @return true if the value is a resource.
 */
static int8 isAlloced(int8 res)
{
    int8 index;    
    int8 ret = 0;
    if(isInitialized_)
    {  
        if( res != 0 ) 
        {
            if( (res & RES_OWNER_MASK) == RES_OWNER_MASK ) 
            {
                index = res & RES_INDEX_MASK;
                if( index >= 0 ) 
                {
                    if( index < RES_NUMBER )
                    {
                        if( lock_[index] != 0 )
                        {
                            ret = 1;                            
                        }
                    }
                }
            }
        }
    }    
    return ret;
}

/**
 * Returns an timer resource.
 *
 * @param index - an available timer index.
 * @return the timer resource, or zero if error has been occurred.
 */
int8 CpuTimer_create(int8 index)
{
    int8 res;
    res = 0;
    if( 0 <= index && index < RES_NUMBER )
    {
        do
        {
            if(lock_[index] == 1)
            { 
                break; 
            }
            /* Alloc the timer */      
            lock_[index] = 1;      
            res = index & RES_INDEX_MASK | RES_OWNER_ID;
        }
        while(0);
    }
    return res;  
}

/**
 * Deletes the timer resource.
 *
 * @param res - the timer resource.
 */
void CpuTimer_delete(int8 res)
{
    int8 index;
    if( isAlloced(res) )
    {
        index = res & RES_INDEX_MASK;    
        lock_[index] = 0;
    }
}

/**
 * Sets the timer period.
 *
 * @param res - the timer resource. 
 * @param time - timer period in microseconds, zero value sets a period to maximum value.
 */      
void CpuTimer_setPeriod(int8 res, int16 us)
{
    int8 index;
    uint8 reg;
    uint32 time, value;
    if( us >= 0 && isAlloced(res) )
    {
        index = res & RES_INDEX_MASK;    
        if(us == 0)
        {
            reg = 0x00;
        }
        else
        {
            time = us;
            value = time * TIMER_CLOCK_KHZ;
            value = value / 1000;
            /* If overflow has been occurred, set max value 
               The max value of passed time in microseconds 
               for the eight-bit timer is 503 us */
            if(value >> 8 > 0)
            {
                reg = 0x00;
            }
            /* Set desired value */
            else
            {
                reg = value & 0xff;
                reg = 0 - reg;
            } 
        }
        switch(index)
        {
            case 0:
            {
                /* Set up counter */
                REG_TL0 = reg;
                /* Set period */        
                REG_TH0 = reg;        
            }
            break;
            case 1:
            {
                /* Set up counter */
                REG_TL1 = reg;
                /* Set period */        
                REG_TH1 = reg;                
            }
            break;
            default: break;
        }
    }  
}

/**
 * Starts the timer count.
 *
 * @param res - the timer resource. 
 */      
void CpuTimer_start(int8 res)
{
    int8 index;
    if( isAlloced(res) )
    {
        index = res & RES_INDEX_MASK;    
        REG_TCON |= 0x1 << (index * 2 + 4);
    }  
}

/**
 * Stops the timer count.
 *
 * @param res - the timer resource. 
 */      
void CpuTimer_stop(int8 res)
{
    int8 index;
    if( isAlloced(res) )
    {
        index = res & RES_INDEX_MASK;    
        REG_TCON &= ~(0x1 << (index * 2 + 4));
    }    
}
 
/**
 * Initializes the driver.
 *
 * @return error code or else zero if no errors have been occurred.
 */   
int8 CpuTimer_initialize(void) 
{
    #ifdef BOOS_RESTARTING
    int8 i;
    #endif /* BOOS_RESTARTING */
    int8 error = ERROR_OK;
    isInitialized_ = 0;   
    
    REG_TCON &= 0x0F;
    REG_TCON |= 0x0 << 7  /* Timer 1 owerflow is cleared */
              | 0x0 << 6  /* Timer 1 is disabled */
              | 0x0 << 5  /* Timer 0 owerflow is cleared */  
              | 0x0 << 6; /* Timer 0 is disabled */
    
    REG_TMOD =  0x0 << 7  /* Timer 1 enabled when TR1 bit set */
              | 0x0 << 6  /* Timer 1 incremented by clock defined by T1M bit */
              | 0x2 << 4  /* Timer 1 is 8-bit Counter/Timer with Auto-Reload */
              | 0x0 << 3  /* Timer 0 enabled when TR0 bit set */
              | 0x0 << 2  /* Timer 0 incremented by clock defined by T0M bit */
              | 0x2 << 0; /* Timer 0 is 8-bit Counter/Timer with Auto-Reload */  
    
    REG_CKCON = 0x0 << 7  /* Timer 3 high byte uses the clock defined by the T3XCLK bit in TMR3CN */
              | 0x0 << 6  /* Timer 3 low byte uses the clock defined by the T3XCLK bit in TMR3CN */
              | 0x0 << 5  /* Timer 2 high byte uses the clock defined by the T2XCLK bit in TMR2CN */
              | 0x0 << 4  /* Timer 2 low byte uses the clock defined by the T2XCLK bit in TMR2CN */
              | 0x0 << 3  /* Timer 1 uses the clock defined by the prescale bits SCA[1:0] */
              | 0x0 << 2  /* Timer 0/Counter uses the clock defined by the prescale bits SCA[1:0] */
    #if TIMER_DIVIDER == 48
              | 0x2 << 0; /* System clock divided by 48 */  
    #elif TIMER_DIVIDER == 12
              | 0x0 << 0; /* System clock divided by 12 */    
    #elif TIMER_DIVIDER == 8
              | 0x3 << 0; /* System clock divided by 8 */      
    #elif TIMER_DIVIDER == 4
              | 0x1 << 0; /* System clock divided by 4 */        
    #elif TIMER_DIVIDER == 1
              | 0x1 << 3  /* Timer 1 uses the system clock */
              | 0x1 << 2  /* Timer 0/Counter uses the system clock */    
              | 0xC << 0; /* System clock divided by 1 */
    #else /* TIMER_DIVIDER == UNSUPPORTING */
              | 0x0 << 0; /* System clock divided by 4 */          
    error = ERROR_UNDEFINED;
    #endif /* TIMER_DIVIDER */
    
    #ifdef BOOS_RESTARTING
    for(i=0; i<RES_NUMBER; i++)
    {
        lock_[i] = 0;
    }
    #endif /* BOOS_RESTARTING */  
    
    if(error == ERROR_OK)
    {
        isInitialized_ = 1;  
    }  
    return error;
}

