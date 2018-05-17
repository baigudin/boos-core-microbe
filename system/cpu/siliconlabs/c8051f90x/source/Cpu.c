/** 
 * Silicon Labs C8051F9x MCUs. 
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2018 Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#include "Cpu.h" 
#include "CpuWatchdog.h" 
#include "CpuPll.h"
#include "CpuInterrupt.h"
#include "CpuTimer.h"
#include "CpuComparator.h"
  
/**
 * Initializes the driver.
 *
 * @return error code or else zero if no errors have been occurred.
 */   
int8 Cpu_initialize(void)
{
    int8 error = ERROR_OK;
    int8 stage = 1;    
    switch(stage)
    {
        /* Stage 1 */
        case 1:        
            error = CpuWatchdog_initialize();	  
            if(error != ERROR_OK)
            { 
                break; 
            }    
            stage++;

        /* Stage 2 */
        case 2:                  
            error = CpuPll_initialize();
            if(error != ERROR_OK)
            { 
                break; 
            }
            stage++;
        
        /* Stage 3 */
        case 3:                    
            error = CpuInterrupt_initialize();
            if(error != ERROR_OK)
            { 
                break; 
            }   
            stage++;
        
        /* Stage 4 */
        case 4:
            error = CpuTimer_initialize();
            if(error != ERROR_OK)
            { 
                break; 
            } 
            stage++;
        
        /* Stage 5 */
        case 5:                    
            error = CpuComparator_initialize();
            if(error != ERROR_OK)
            { 
                break; 
            }    
            stage++;
        
        /* Stage complete */            
        case 6:
            stage = 0;
            break;
        
        /* Stage error */
        default:
            stage = -1;
            break;
    }
    if(stage != 0 && error == ERROR_OK)
    {
        error = ERROR_UNDEFINED;
    }    
    return error;
}

