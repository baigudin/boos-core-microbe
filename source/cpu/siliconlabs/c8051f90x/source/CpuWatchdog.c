/** 
 * Silicon Labs C8051F9x MCUs watchdog driver. 
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2018, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#include "CpuWatchdog.h" 
#include "CpuRegisters.h"
#include "CpuConfiguration.h"

/**
 * Number of possible resources.
 */
#define RES_NUMBER (1)

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
 * A value.
 */
#define ANY_VALUE (0x77)

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
 * Returns an watchdog resource.
 *
 * @param index - any value.
 * @return the watchdog resource, or zero if error has been occurred.
 */
int8 CpuWatchdog_create(int8 index)
{
    int8 res;
    res = 0;
    index = 0;
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
    return res;     
}

/**
 * Deletes the watchdog resource.
 *
 * @param res - the watchdog resource.
 */
void CpuWatchdog_delete(int8 res)
{
    int8 index;
    if( isAlloced(res) )
    {
        index = res & RES_INDEX_MASK;    
        lock_[index] = 0;
    }    
}

/**
 * Enables the watchdog.
 *
 * @param res - the watchdog resource. 
 */      
void CpuWatchdog_start(int8 res)
{
    if( isAlloced(res) )
    {    
        /* Disable the WDT */
        REG_PCA0MD &= ~ 0x1 << 6;
        /* Select the desired PCA clock source */
        REG_PCA0MD &= ~ 0x7 << 1;
        REG_PCA0MD |= PCA_CLOCK_SOURCE << 1;
        /* Load PCA0CPL5 with the desired WDT update offset value */
        REG_PCA0CPL5 = 0x01;
        /* Enable the WDT */
        REG_PCA0MD |= 0x1 << 6;
        /* Reset the WDT timer by writing to PCA0CPH5 */
        REG_PCA0CPH5 = ANY_VALUE;
    }
}

/**
 * Disables the watchdog.
 *
 * @param res - the watchdog resource. 
 */      
void CpuWatchdog_stop(int8 res)
{
    if( isAlloced(res) )
    {    
        /* Disable the WDT */
        REG_PCA0MD &= ~ 0x1 << 6;
    }
}

/**
 * Restarts the watchdog counting.
 *
 * @param res - the watchdog resource. 
 */      
void CpuWatchdog_restart(int8 res)
{
    if( isAlloced(res) )
    {    
        /* Reset the WDT timer by writing to PCA0CPH5 */
        REG_PCA0CPH5 = ANY_VALUE;    
    }    
}
  
/**
 * Initializes the driver.
 *
 * @return error code or else zero if no errors have been occurred.
 */   
int8 CpuWatchdog_initialize(void)
{
    /* Disable watchdog timer */
    REG_PCA0MD &= 0xbf;
    isInitialized_ = 1;
    return SYS_OK;
}
