/** 
 * Silicon Labs C8051F9x MCUs comparator driver.  
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2018, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#include "CpuComparator.h"
#include "CpuInterrupt.h" 
#include "CpuRegisters.h"

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
 * Comparator interrupt handlers.
 */  
struct Handler
{
    /**
     * The driver interrupt handler.
     */  
    void(*drv)();
    
    /**
     * External interrupt handler.
     *
     * @param out - an output comparator value.
     */  
    void(*ext)(int8);  
  
};

/**
 * Comparator interrupt data.
 */  
struct Interrupt
{
    /**
     * The driver interrupt resource.
     */  
    int8 res;  
    
    /**
     * The driver interrupt source.
     */  
    int8 source;
 
}; 

/**
 * Comparator contex.
 */
struct Comparator
{
    /**
     * Resource locked flag.  
     */
    int8 lock;
    
    /**
     * Comparator interrupt handlers.
     */  
    struct Handler handler;  
    
    /**
     * Comparator interrupt data.
     */  
    struct Interrupt inter;    

};

/**
 * Comparator resource contex.
 */
static struct Comparator cmp_[RES_NUMBER];

/**
 * The driver has been initialized successfully.
 */
static int8 isInitialized_;

/**
 * Tests if passed value is the resource.
 *
 * @param res - an interrupt resource. 
 * @return the resource index, or -1 if the resource is wrong.
 */
static int8 getIndex(int8 res)
{
    int8 index;    
    int8 ret = -1;
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
                        if( cmp_[index].lock != 0 )
                        {
                            ret = index;                            
                        }
                    }
                }
            }
        }
    }
    return ret;
}

/**
 * Interrupt handler of comparator 0.
 */
static void handleComparator0(void)
{
    if(cmp_[0].handler.ext != 0)
    {
        cmp_[0].handler.ext( REG_CPT0CN & 0x40 ? 1 : 0 );
    }
}

/**
 * Interrupt handler of comparator 1.
 */
static void handleComparator1(void)
{
    if(cmp_[1].handler.ext != 0)
    {  
        cmp_[1].handler.ext( REG_CPT1CN & 0x40 ? 1 : 0 );  
    }
}

/**
 * Returns an comparator resource.
 *
 * @param handler - an interrupt handler function. 
 * @param index -an available comparator index.
 * @param neg - a negative input channel value.
 * @param pos - a positive input channel value.
 * @return the comparator resource, or zero if error has been occurred.
 */
int8 CpuComparator_create(void(*handler)(), int8 index, int8 neg, int8 pos)
{
    int8 res = 0;  
    if( 0 <= index && index < RES_NUMBER && cmp_[index].lock == 0 )
    {
        do
        {
            /* Set HW registers */      
            switch(index)
            {
                case 0:
                {
                    REG_CPT0MX = (neg & 0xf) << 4  /* Negative Input */
                               | (pos & 0xf) << 0; /* Positive Input */
                    
                    REG_CPT0MD = 0x1 << 7  /* Must Write 1b */
                               | 0x1 << 5  /* Comparator Rising-Edge interrupt enabled */
                               | 0x1 << 4  /* Comparator Falling-Edge interrupt enabled */
                               | 0x0 << 0; /* Fastest Response Time, Highest Power Consumption */
                    
                    REG_CPT0CN = 0x1 << 7  /* Comparator Enabled */
                               | 0x0 << 5  /* Comparator Rising-Edge has not occurred */
                               | 0x0 << 4  /* Comparator Falling-Edge has not occurred */
                               | 0x3 << 2  /* Positive Hysteresis */
                               | 0x3 << 0; /* Negative Hysteresis */
                }
                break;          
                case 1:
                {
                    REG_CPT1MX = (neg & 0xf) << 4  /* Negative Input */
                               | (pos & 0xf) << 0; /* Positive Input */
                    
                    REG_CPT1MD = 0x1 << 7  /* Must Write 1b */
                               | 0x1 << 5  /* Comparator Rising-Edge interrupt enabled */
                               | 0x1 << 4  /* Comparator Falling-Edge interrupt enabled */
                               | 0x0 << 0; /* Fastest Response Time, Highest Power Consumption */
                  
                    REG_CPT1CN = 0x1 << 7  /* Comparator Enabled */
                               | 0x0 << 5  /* Comparator Rising-Edge has not occurred */
                               | 0x0 << 4  /* Comparator Falling-Edge has not occurred */
                               | 0x3 << 2  /* Positive Hysteresis */
                               | 0x3 << 0; /* Negative Hysteresis */
                }
                break;
                default: break;
            }
            cmp_[index].inter.res = CpuInterrupt_create(cmp_[index].handler.drv, cmp_[index].inter.source);
            if(cmp_[index].inter.res == 0)
            {
                break;
            }
            cmp_[index].handler.ext = handler;
            cmp_[index].lock = 1;
            res = index & RES_INDEX_MASK | RES_OWNER_ID;
        }
        while(0);
    }
    return res;
}

/**
 * Deletes the comparator resource.
 *
 * @param res - the comparator resource.
 */
void CpuComparator_delete(int8 res)
{
    int8 index = getIndex(res);
    if( index != -1 )
    {
        switch(index)
        {
            case 0:
            {
                REG_CPT0CN = 0x0 << 7  /* Comparator Disabled */
                           | 0x0 << 5  /* Comparator Rising-Edge has not occurred */
                           | 0x0 << 4  /* Comparator Falling-Edge has not occurred */
                           | 0x0 << 2  /* Positive Hysteresis Disabled */
                           | 0x0 << 0; /* Negative Hysteresis Disabled */
            }
            break;          
            case 1:
            {
                REG_CPT1CN = 0x0 << 7  /* Comparator Disabled */
                           | 0x0 << 5  /* Comparator Rising-Edge has not occurred */
                           | 0x0 << 4  /* Comparator Falling-Edge has not occurred */
                           | 0x0 << 2  /* Positive Hysteresis Disabled */
                           | 0x0 << 0; /* Negative Hysteresis Disabled */
            }
            break;
            default: break;
        }
        CpuInterrupt_delete(cmp_[index].inter.res);
        cmp_[index].handler.ext = 0;    
        cmp_[index].inter.res = 0;
        cmp_[index].lock = 0;
    }  
}

/**
 * Locks the comparator interrupt source.
 *
 * @param res - the comparator resource. 
 * @return an interrupt enable source bit value before function was called.
 */    
int8 CpuComparator_disableInterrupt(int8 res)
{
    int8 is;
    int8 index = getIndex(res);
    if(index != -1)
    {
        is = CpuInterrupt_disable(cmp_[index].inter.res);
    }    
    else
    {
        is = 0;
    }
    return is;
}
    
/**
 * Unlocks the comparator interrupt source.
 *
 * @param res - the comparator resource. 
 * @param status - status returned by lock function.
 */
void CpuComparator_enableInterrupt(int8 res, int8 status)
{
    int8 index = getIndex(res);
    if(index != -1)
    {
        CpuInterrupt_enable(cmp_[index].inter.res, status);
    }    
}

/**
 * Initializes the driver.
 *
 * @return error code or else zero if no errors have been occurred.
 */   
extern int8 CpuComparator_initialize(void)
{  
    int8 i;
    isInitialized_ = 0;   
    for(i=0; i<RES_NUMBER; i++)
    {
        cmp_[i].lock = 0;
        cmp_[i].inter.res = 0;
        cmp_[i].handler.ext = 0;
        switch(i)
        {
            case 0:
            {
                cmp_[i].handler.drv = &handleComparator0;            
                cmp_[i].inter.source = 12;
            }
            break;      
            case 1:
            {
                cmp_[i].handler.drv = &handleComparator1;            
                cmp_[i].inter.source = 13;        
            }
            break;
            default: 
            {
                break;
            }
        }
        
    }
    #ifdef BOOS_RESTARTING  
    /* Disable the comparators */
    REG_CPT0CN = 0x0;
    REG_CPT1CN = 0x0;
    #endif /* BOOS_RESTARTING */
    isInitialized_ = 1;  
    return ERROR_OK;
}
