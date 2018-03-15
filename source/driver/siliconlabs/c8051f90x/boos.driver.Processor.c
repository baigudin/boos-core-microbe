/** 
 * Target processor. 
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#include "boos.driver.Processor.h" 
#include "boos.driver.Watchdog.h" 
#include "boos.driver.Pll.h"
#include "boos.driver.Interrupt.h"
#include "boos.driver.Timer.h"
#include "boos.driver.Comparator.h"
  
/**
 * Initializes the driver.
 *
 * @return error code or else zero if no errors have been occurred.
 */   
int8 processorInit(void)
{
  int8 error = BOOS_OK;
  do{
    /* Stage 1 */
    error = watchdogInit();	  
    if(error != BOOS_OK){ break; }
    /* Stage 2 */
    error = pllInit();
    if(error != BOOS_OK){ break; }
    /* Stage 3 */
    error = interruptInit();
    if(error != BOOS_OK){ break; }
    /* Stage 3 */
    error = timerInit();
    if(error != BOOS_OK){ break; }
    /* Stage 3 */
    error = comparatorInit();
    if(error != BOOS_OK){ break; }    
    /* Stage complete */
  }while(0);
  return error;
}

