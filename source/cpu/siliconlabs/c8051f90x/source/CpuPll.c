/** 
 * Silicon Labs C8051F9x MCUs phase-locked loop driver.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2018, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#include "CpuPll.h" 
#include "CpuRegisters.h"
#include "CpuConfiguration.h"
  
/**
 * Initializes the driver.
 *
 * @return error code or else zero if no errors have been occurred.
 */   
int8 CpuPll_initialize(void)
{
    int8 error;
    #if (SOURCE_CLOCK == 24500000 || CPU_CLOCK == 24300000)
    volatile uint8 val;
    /* Enable spread spectrum clock dithering and
     * also reduce the factory frequency 
     * from 24.5 MHz to 24.3 MHz */
    REG_OSCICL |= 0x1 << 7; /* Spread Spectrum clock dithering enabled */
    /* Enabled internal oscillator */
    REG_OSCICN |= 0x1 << 7; /* Internal oscillator enabled */
    /* Wait internal oscillator is running */
    do
    {
        val = REG_OSCICN & 0x40;  
    }
    while(val == 0x0);
    /* Select system clock source as Precision Internal Oscillator 
     * and set system clock is divided by 1. */
    REG_CLKSEL = 0x0 << 4  /* System clock is divided by 1 */
               | 0x0 << 0; /* Precision Internal Oscillator */
    /* Wait SYSCLK will be ready */
    do
    {
        val = REG_CLKSEL & 0x80;
    }
    while(val == 0x0);
    error = SYS_OK;
    #else
    error = SYS_ERROR;
    #endif /* CPU_CLOCK */
    return error;  
}
