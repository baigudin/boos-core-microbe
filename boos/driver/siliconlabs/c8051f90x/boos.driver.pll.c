/** 
 * Target processor phase-locked loop driver.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#include "boos.driver.pll.h" 
#include "boos.driver.registers.h"
#include "boos.driver.constants.h"
  
/**
 * Initializes the driver.
 *
 * @return error code or else zero if no errors have been occurred.
 */   
int8 pllInit(void)
{
  int8 error;
  #if CPU_CLOCK == 24300000
  volatile uint8 val;
  /* Enable spread spectrum clock dithering and
   * also reduce the factory frequency 
   * from 24.5 MHz to 24.3 MHz */
  REG_OSCICL |= 0x80;
  /* Enabled internal oscillator */
  REG_OSCICN |= 0x80;
  /* Wait internal oscillator is running */
  do{
    val = REG_OSCICN & 0x40;  
  }while(val == 0x0);
  /* Select system clock source as Precision Internal Oscillator 
   * and set system clock is divided by 1. */
  REG_CLKSEL = 0;
  /* Wait SYSCLK will be ready */
  do{
    val = REG_CLKSEL & 0x80;
  }while(val == 0x0);
  error = BOOS_OK;
  #else
  error = BOOS_ERROR;
  #endif /* CPU_CLOCK */
  return error;  
}
