; ----------------------------------------------------------------------------
; Silicon Labs C8051F9x MCUs interrupt low level driver.  
;
; @author    Sergey Baigudin, sergey@baigudin.software
; @copyright 2017 Sergey Baigudin
; @license   http://baigudin.software/license/
; @link      http://baigudin.software
; ----------------------------------------------------------------------------
$INCLUDE (CpuRegisters.ll.inc)

                EXTRN       CODE (?c_startup)
                EXTRN       CODE (_CpuInterrupt_handle)                

; ----------------------------------------------------------------------------
; Hardware interrupt handler (the execution is 7 cycles).
;
; This is a macro command for interrupts table.
; It has to be fixed size that equals eight bytes.
; ----------------------------------------------------------------------------
handler         MACRO       num, addr
                clr         REG_IE_BIT_EA
                push        7h                
                mov         r7, #num                
                ajmp        addr
                ENDM
                               
; ----------------------------------------------------------------------------
; Hardware interrupts table.
; ----------------------------------------------------------------------------                
                ; Reset
                CSEG        AT 0000h
m_int_reset:    ljmp        ?c_startup

                ; External Interrupt 0 
                CSEG        AT 0003h 
                handler     0, m_int_0_handler

                ; Timer 0 Overflow                
                CSEG        AT 000Bh 
                handler     1, m_int_1_handler

                ; External Interrupt 1                                
                CSEG        AT 0013h 
                handler     2, m_int_2_handler

                ; Timer 1 Overflow                                 
                CSEG        AT 001Bh
                handler     3, m_int_3_handler

                ; UART0                                
                CSEG        AT 0023h 
                handler     4, m_int_4_handler

                ; Timer 2 Overflow                                  
                CSEG        AT 002Bh 
                handler     5, m_int_5_handler

                ; SPI0                                
                CSEG        AT 0033h
                handler     6, m_int_6_handler

                ; SMB0                                
                CSEG        AT 003Bh 
                handler     7, m_int_7_handler

                ; SmaRTClock Alarm                                
                CSEG        AT 0043h 
                handler     8, m_int_8_handler

                ; ADC0 Window Comparator                                
                CSEG        AT 004Bh
                handler     9, m_int_9_handler

                ; ADC0 End of Conversion                                 
                CSEG        AT 0053h
                handler     10, m_int_10_handler

                ; Programmable Counter Array                                
                CSEG        AT 005Bh
                handler     11, m_int_11_handler
                
                ; Comparator 0
                CSEG        AT 0063h
                handler     12, m_int_12_handler

                ; Comparator 1                                
                CSEG        AT 006Bh
                handler     13, m_int_13_handler

                ; Timer 3 Overflow                                
                CSEG        AT 0073h
                handler     14, m_int_14_handler

                ; Supply Monitor Early Warning                                
                CSEG        AT 007Bh
                handler     15, m_int_15_handler

                ; Port Match                                 
                CSEG        AT 0083h
                handler     16, m_int_16_handler

                ; SmaRTClock Oscillator Fail                                
                CSEG        AT 008Bh
                handler     17, m_int_17_handler

                ; SPI1                                
                CSEG        AT 0093h
                handler     18, m_int_18_handler

; ----------------------------------------------------------------------------
; Interrupt service routine of each vectors.
; ----------------------------------------------------------------------------
                CSEG        AT 09Bh
                ; External Interrupt 0 
m_int_0_handler:
                push        REG_ACC
                ajmp        m_int_handler

                ; Timer 0 Overflow                
m_int_1_handler:
                push        REG_ACC
                ajmp        m_int_handler

                ; External Interrupt 1                                
m_int_2_handler:
                push        REG_ACC
                ajmp        m_int_handler

                ; Timer 1 Overflow                                 
m_int_3_handler:
                push        REG_ACC
                ajmp        m_int_handler

                ; UART0                                
m_int_4_handler:
                push        REG_ACC
                clr         REG_SCON0.0
                clr         REG_SCON0.1                
                ajmp        m_int_handler

                ; Timer 2 Overflow                                  
m_int_5_handler:
                push        REG_ACC
                clr         REG_TMR2CN.7
                clr         REG_TMR2CN.6                
                ajmp        m_int_handler

                ; SPI0                                
m_int_6_handler:
                push        REG_ACC
                clr         REG_SPI0CN.7
                clr         REG_SPI0CN.6
                clr         REG_SPI0CN.5
                clr         REG_SPI0CN.4                
                ajmp        m_int_handler

                ; SMB0                                
m_int_7_handler:
                push        REG_ACC
                clr         REG_SMB0CN.0
                ajmp        m_int_handler

                ; SmaRTClock Alarm                                
m_int_8_handler:
                push        REG_ACC
                ; TODO: Clearing of RTC0CN.2 bit
                ajmp        m_int_handler

                ; ADC0 Window Comparator                                
m_int_9_handler:
                push        REG_ACC
                clr         REG_ADC0CN.3
                ajmp        m_int_handler

                ; ADC0 End of Conversion                                 
m_int_10_handler:
                push        REG_ACC
                ; TODO: Clearing of ADC0STA.5 bit
                ajmp        m_int_handler

                ; Programmable Counter Array                                
m_int_11_handler:
                push        REG_ACC
                clr         REG_PCA0CN.7                
                ; TODO: Clearing of PCA0CN.n bits
                ajmp        m_int_handler
                
                ; Comparator 0
m_int_12_handler:
                push        REG_ACC
                mov         acc, REG_CPT0CN
                anl         acc, #0CFh
                mov         REG_CPT0CN, acc
                ajmp        m_int_handler

                ; Comparator 1                                
m_int_13_handler:
                push        REG_ACC
                mov         acc, REG_CPT1CN
                anl         acc, #0CFh
                mov         REG_CPT1CN, acc
                ajmp        m_int_handler

                ; Timer 3 Overflow                                
m_int_14_handler:
                push        REG_ACC
                mov         acc, REG_TMR3CN
                anl         acc, #03Fh
                mov         REG_TMR3CN, acc                
                ajmp        m_int_handler

                ; Supply Monitor Early Warning                                
m_int_15_handler:
                push        REG_ACC
                ; TODO: Clearing of VDM0CN.5 and VDM0CN.4 bits
                ajmp        m_int_handler

                ; Port Match                                 
m_int_16_handler:
                push        REG_ACC
                ajmp        m_int_handler

                ; SmaRTClock Oscillator Fail                                
m_int_17_handler:
                push        REG_ACC
                ; TODO: Clearing of RTC0CN.5 bit
                ajmp        m_int_handler

                ; SPI1                                
m_int_18_handler:
                push        REG_ACC
                ; TODO: Clearing of SPI1CN.7-4 bits
                ajmp        m_int_handler                
                
; ----------------------------------------------------------------------------
; Interrupt service routine.
; ----------------------------------------------------------------------------
m_int_handler:
                ; Save the contex
                push        REG_B
                push        REG_DPH
                push        REG_DPL
                push        REG_PSW
                mov         REG_PSW, #0h
                push        6h
                push        5h
                push        4h
                push        3h
                push        2h
                push        1h
                push        0h
                ; Call high-level handler
                lcall       _CpuInterrupt_handle
                ; Restore the contex                
                pop         0h
                pop         1h
                pop         2h
                pop         3h
                pop         4h
                pop         5h
                pop         6h
                pop         REG_PSW
                pop         REG_DPL
                pop         REG_DPH
                pop         REG_B                
                pop         REG_ACC 
                pop         7h
                setb        REG_IE_BIT_EA
                reti

                END
