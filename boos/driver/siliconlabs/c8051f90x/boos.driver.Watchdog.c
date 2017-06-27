/** 
 * Target processor watchdog driver. 
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#include "boos.driver.Watchdog.h" 
#include "boos.driver.Registers.h"
  
/**
 * Initializes the driver.
 *
 * @return error code or else zero if no errors have been occurred.
 */   
int8 watchdogInit(void)
{
  /* Disable watchdog timer */
  REG_PCA0MD &= 0xbf;
  return BOOS_OK;
}
