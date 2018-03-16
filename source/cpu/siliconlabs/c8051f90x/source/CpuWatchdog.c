/** 
 * Silicon Labs C8051F9x MCUs watchdog driver. 
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2018, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#include "CpuWatchdog.h" 
#include "CpuRegisters.h"
  
/**
 * Initializes the driver.
 *
 * @return error code or else zero if no errors have been occurred.
 */   
int8 CpuWatchdog_initialize(void)
{
  /* Disable watchdog timer */
  REG_PCA0MD &= 0xbf;
  return SYS_OK;
}
