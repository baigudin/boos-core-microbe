/** 
 * Target processor. 
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#include "boos.driver.processor.h" 
#include "boos.driver.watchdog.h" 
#include "boos.driver.pll.h"
#include "boos.driver.interrupt.h"
  
/**
 * Initializes the driver.
 *
 * @return error code or else zero if no errors have been occurred.
 */   
int8 processorInit()
{
  int8 error;
  // Stage 1 
  error = watchdogInit();
  if(error != BOOS_OK) return error;        
  // Stage 2 
  error = pllInit();
  if(error != BOOS_OK) return error;  
  // Stage 3
  error = interruptInit();
  if(error != BOOS_OK) return error;      
  // Stage complete
  return BOOS_OK;
}

