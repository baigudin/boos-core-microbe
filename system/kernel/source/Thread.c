/** 
 * The operating system thread.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2018, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#include "Thread.h"
#include "Program.h"
#include "CpuTimer.h"
#include "CpuInterrupt.h"
#include "CpuWatchdog.h" 

/**
 * Definition for creating of watchdog resource.
 */
#define WATCHDOG_RESOURCE_CREATION  

/**
 * HW timer period in microseconds.
 * 
 * The used eight-bit timer must have 503 us period as maximum.
 * Any other more values will be cropped by the driver to the maximum.
 */
#define TIMER_PERIOD (500ul)

/**
 * The scheduler resources.
 */  
struct Resource
{
    /**
     * The timer 0 resource.
     */  
    int8 tim;  
    /**
     * The timer 0 interrupt resource.
     */  
    int8 intr;      
    
    /**
     * The watchdog timer source.
     */  
    int8 wdt;
 
}; 

/**
 * The scheduler resources.
 */  
static struct Resource res_;

/**
 * The module has been plugged successfully.
 */
static int8 isPlugged_;

/**
 * Interrupt handler of Timer 1.
 */
static void handleTimerInterrupt(void)
{
    #ifdef WATCHDOG_RESOURCE_CREATION            
    CpuWatchdog_restart(res_.wdt);                
    #endif 
}

/**
 * Causes the currently executing thread to sleep.
 *
 * @param millis - a time to sleep in milliseconds.
 */  
void Thread_sleep(int16 millis)
{
    uint32 i, max, time;
    time = (uint16) millis;
    max = 0x167 * time;   
    for(i=0; i<max; i++){}
}

/**
 * Initiates the threads executing.
 *
 * @return error code, returned by application, or else zero if no errors have been occurred.
 */
int8 Thread_execute(void)
{
    int8 error;
    if( isPlugged_ )
    {
        /* Start all resources */
        CpuInterrupt_enableAll(1);
        CpuInterrupt_enable(res_.intr, 1); 
        CpuTimer_start(res_.tim);    
        #ifdef WATCHDOG_RESOURCE_CREATION        
        CpuWatchdog_start(res_.wdt);    
        #endif
        /* Start a user program */
        error = Program_start();
        /* Stop all resources */    
        #ifdef WATCHDOG_RESOURCE_CREATION        
        CpuWatchdog_stop(res_.wdt);    
        #endif
        CpuTimer_stop(res_.tim);        
        CpuInterrupt_disable(res_.intr);     
        CpuInterrupt_disableAll();
    }
    else
    {
        error = ERROR_UNDEFINED;
    }
    return error;
}

/**
 * Plugs the thread scheduling.
 *
 * @return error code or else zero if no errors have been occurred.
 */ 
int8 Thread_plug(void)
{
    int8 error = ERROR_OK;
    isPlugged_ = 0;
    /* Create timer 0 */
    res_.tim = CpuTimer_create(0);
    if(res_.tim == 0)
    {
        error = ERROR_UNDEFINED;        
    }    
    else
    {
        CpuTimer_setPeriod(res_.tim, TIMER_PERIOD);
    }
    /* Create interrupt of timer 0 */        
    if(error == ERROR_OK)
    {
        res_.intr = CpuInterrupt_create(&handleTimerInterrupt, CIS_TIMER0);
        if(res_.intr == 0)
        { 
            error = ERROR_UNDEFINED;
        }
    }
    #ifdef WATCHDOG_RESOURCE_CREATION
    /* Watchdog timer */        
    if(error == ERROR_OK)
    {
        res_.wdt = CpuWatchdog_create(0);
        if(res_.intr == 0)
        { 
            error = ERROR_UNDEFINED;
        }   
    }
    #endif /* WATCHDOG_RESOURCE_CREATION */
    if(error == ERROR_OK)
    {
        isPlugged_ = 1;
    }
    return error;
}
