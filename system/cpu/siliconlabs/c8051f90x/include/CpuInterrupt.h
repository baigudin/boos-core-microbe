/** 
 * Silicon Labs C8051F9x MCUs interrupts driver.  
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2018, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef CPU_INTERRUPT_H_
#define CPU_INTERRUPT_H_

#include "Types.h"
#include "Error.h"

/**
 * MPU interrupt available sources.
 */
enum CpuInterruptSource
{    
    /**
     * External Interrupt 0.
     */    
    CIS_INT0 = 0,
    
    /**     
     * Timer 0 Overflow.
     */    
    CIS_TIMER0 = 1,
    
    /**     
     * External Interrupt 1.
     */    
    CIS_INT1 = 2,
    
    /**     
     * Timer 1 Overflow.
     */    
    CIS_TIMER1 = 3,
    
    /**     
     * UART 0.
     */    
    CIS_UART0 = 4,
    
    /**     
     * Timer 2 Overflow
     */    
    CIS_TIMER2 = 5,
    
    /**     
     * SPI 0.
     */    
    CIS_SPI0 = 6,
    
    /**     
     * SMB 0.
     */    
    CIS_SMB0 = 7,

    /**     
     * SmaRTClock Alarm.
     *
     * NOTE: RTC0CN.2 bit is not cleared by ISR, therefore
     * the source is locked till the ISR will do clearing of the bit.
     */    
    CIS_RTCLOCK = 8,
    
    /**     
     * ADC0 Window Comparator.
     */    
    CIS_ADC0_WIN_CMP = 9,
    
    /**     
     * ADC0 End of Conversion.
     *
     * NOTE: ADC0STA.5 bit is not cleared by ISR, therefore 
     * the source is locked till the ISR will do clearing of the bit.        
     */    
    CIS_ADC0_END = 10,
    
    /**     
     * Programmable Counter Array.
     *
     * NOTE: PCA0CN.n bits are not cleared by ISR, therefore 
     * the source is locked till the ISR will do clearing of the bits.     
     */    
    CIS_PCA = 11,
    
    /**     
     * Comparator 0.
     */    
    CIS_COMPARATOR_0 = 12,
    
    /**
     * Comparator 1.
     */    
    CIS_COMPARATOR1 = 13,
    
    /**     
     * Timer 3 Overflow.
     */    
    CIS_TIMER3 = 14,
    
    /**     
     * Supply Monitor Early Warning.
     *
     * NOTE: VDM0CN.5 and VDM0CN.4 bits are not cleared by ISR, therefore 
     * the source is locked till the ISR will do clearing of the bits.
     */
    CIS_SUPPLY_MONITOR_EARLY_WARNING = 15,
    
    /**     
     * Port Match.
     */    
    CIS_PORT_MATCH = 16,
    
    /**     
     * SmaRTClock Oscillator Fail.
     *
     * NOTE: RTC0CN.5 bit is not cleared by ISR, therefore 
     * the source is locked till the ISR will do clearing of the bit.
     */    
    CIS_RTCLOCK_OSC_FAIL = 17,
    
    /**     
     * SPI 1.
     *
     * NOTE: SPI1CN.7-4 bits are not cleared by ISR, therefore 
     * the source is locked till the ISR will do clearing of the bits.     
     */        
    CIS_SPI1 = 18

};

/**
 * Returns an interrupt resource.
 *
 * @param handler - an interrupt handler function.
 * @param source - an available interrupt source number.
 * @return the interrupt resource, or zero if error has been occurred.
 */
extern int8 CpuInterrupt_create(void(*handler)(), int8 source);

/**
 * Deletes the interrupt resource.
 *
 * @param res - the interrupt resource.
 */
extern void CpuInterrupt_delete(int8 res);

/**
 * Locks the interrupt source.
 *
 * @param res - the interrupt resource. 
 * @return an interrupt enable source bit value before function was called.
 */    
extern int8 CpuInterrupt_disable(int8 res);
    
/**
 * Unlocks this interrupt source.
 *
 * @param res - the interrupt resource. 
 * @param status - status returned by lock function.
 */
extern void CpuInterrupt_enable(int8 res, int8 status);

/**
 * Tests if this interrupt source can be polarized.
 *
 * @param res - the interrupt resource.  
 * @return true if this source is polarizing.
 */  
extern int8 CpuInterrupt_isPolarized(int8 res);

/**
 * Disables all maskable interrupts.
 *
 * @return global interrupts enable bit value before function was called.
 */
extern int8 CpuInterrupt_disableAll(void);

/**
 * Enables all maskable interrupts.
 *
 * The true passed argument directly turns all maskable interrupts on, 
 * and the false does nothing, the interrupts stay in the current state.     
 *
 * @param status - the returned status by disable function.
 */
extern void CpuInterrupt_enableAll(int8 status);

/**
 * This partially guards from calling these functions by a user program.
 */
#ifdef BOOS_SYSTEM_MODE

/**
 * Plugs the driver.
 *
 * @return error code or else zero if no errors have been occurred.
 */   
extern int8 CpuInterrupt_plug(void);

#endif /* BOOS_SYSTEM_MODE */

#endif /* CPU_INTERRUPT_H_ */
