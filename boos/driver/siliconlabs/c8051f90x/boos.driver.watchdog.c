/** 
 * Target processor watchdog driver. 
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#include "boos.driver.watchdog.h" 
#include "boos.driver.registers.h"
  
/**
 * Initializes the driver.
 *
 * @return error code or else zero if no errors have been occurred.
 */   
int8 watchdogInit()
{
  // Disable watchdog timer
  REG_PCA0MD &= 0xbf;
  return BOOS_OK;
}
