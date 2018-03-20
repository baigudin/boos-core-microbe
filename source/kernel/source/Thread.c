/** 
 * The operating system main class.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2018, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#include "Thread.h"
#include "Program.h"
#include "CpuInterrupt.h"
#include "CpuWatchdog.h" 

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
     * The watchdog timer source.
     */  
    int8 wdt;
 
}; 

/**
 * The scheduler resources.
 */  
static struct Resource res_;

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
int8 Thread_execute()
{
    int8 error;
    CpuInterrupt_enableAll(1);
    error = Program_start();
    CpuInterrupt_disableAll();
    return error;
}

/**
 * Initializes the thread scheduling.
 *
 * @return error code or else zero if no errors have been occurred.
 */ 
int8 Thread_initialize(void)
{
    uint16 i;
    int8 error = SYS_OK;
    res_.wdt = CpuWatchdog_create(0);
    CpuWatchdog_start(res_.wdt);
    for(i=0; i<0xffff; i++)
    {
        if( (i & 0x7) == 0 )
        {
            CpuWatchdog_restart(res_.wdt);            
        }
    }
    CpuWatchdog_stop(res_.wdt);    
    CpuWatchdog_delete(res_.wdt);
    return error;
}