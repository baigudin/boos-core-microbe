; ----------------------------------------------------------------------------
; Interrupt low level module.
;
; @author    Sergey Baigudin, sergey@baigudin.software
; @copyright 2017 Sergey Baigudin
; @license   http://baigudin.software/license/
; @link      http://baigudin.software
; ----------------------------------------------------------------------------
$INCLUDE (boos.driver.registers.ll.inc)

                EXTRN       CODE (?c_startup)
                
s_isr           SEGMENT     CODE                
                
; ----------------------------------------------------------------------------
; Hardware interrupts table.
; ----------------------------------------------------------------------------                
                ; Reset
                CSEG        AT 0000h
m_int_reset:    ljmp        ?c_startup

                ; External Interrupt 0 
                CSEG        AT 0003h 
m_int_00:       
                nop
                nop
                nop
                nop
                nop                
                ljmp        m_int_handler

                ; Timer 0 Overflow                
                CSEG        AT 000Bh 
m_int_01:
                nop
                nop
                nop
                nop
                nop                
                ljmp        m_int_handler

                ; External Interrupt 1                                
                CSEG        AT 0013h 
m_int_02:
                nop
                nop
                nop
                nop
                nop                
                ljmp        m_int_handler

                ; Timer 1 Overflow                                 
                CSEG        AT 001Bh
m_int_03:
                nop
                nop
                nop
                nop                
                nop
                ljmp        m_int_handler

                ; UART0                                
                CSEG        AT 0023h 
m_int_04:
                nop
                nop                
                nop
                nop
                nop
                ljmp        m_int_handler

                ; Timer 2 Overflow                                  
                CSEG        AT 002Bh 
m_int_05:
                nop
                nop                
                nop
                nop
                nop
                ljmp        m_int_handler

                ; SPI0                                
                CSEG        AT 0033h
m_int_06:
                nop
                nop                
                nop
                nop
                nop
                ljmp        m_int_handler

                ; SMB0                                
                CSEG        AT 003Bh 
m_int_07:
                nop
                nop                
                nop
                nop
                nop
                ljmp        m_int_handler

                ; SmaRTClock Alarm                                
                CSEG        AT 0043h 
m_int_08:
                nop
                nop
                nop
                nop                
                nop
                ljmp        m_int_handler

                ; ADC0 Window Comparator                                
                CSEG        AT 004Bh
m_int_09:
                nop
                nop
                nop
                nop                
                nop
                ljmp        m_int_handler

                ; ADC0 End of Conversion                                 
                CSEG        AT 0053h
m_int_10:
                nop
                nop
                nop                
                nop
                nop
                ljmp        m_int_handler

                ; Programmable Counter Array                                
                CSEG        AT 005Bh
m_int_11:
                nop
                nop
                nop
                nop                
                nop
                ljmp        m_int_handler

                ; Comparator 0                                
                CSEG        AT 0063h
m_int_12:
                nop
                nop
                nop
                nop                
                nop
                ljmp        m_int_handler

                ; Comparator1                                
                CSEG        AT 006Bh
m_int_13:
                nop
                nop                
                nop
                nop
                nop
                ljmp        m_int_handler

                ; Timer 3 Overflow                                
                CSEG        AT 0073h
m_int_14:
                nop
                nop
                nop                
                nop
                nop
                ljmp        m_int_handler

                ; Supply Monitor Early Warning                                
                CSEG        AT 007Bh
m_int_15:
                nop
                nop
                nop
                nop                
                nop
                ljmp        m_int_handler

                ; Port Match                                 
                CSEG        AT 0083h
m_int_16:
                nop
                nop
                nop
                nop                
                nop
                ljmp        m_int_handler

                ; SmaRTClock Oscillator Fail                                
                CSEG        AT 008Bh
m_int_17:
                nop
                nop                
                nop
                nop
                nop
                ljmp        m_int_handler

                ; SPI1                                
                CSEG        AT 0093h
m_int_18:
                nop
                nop
                nop
                nop                
                nop
                ljmp        m_int_handler

; ----------------------------------------------------------------------------
; Interrupt service routine.
; ----------------------------------------------------------------------------
                RSEG        s_isr
m_int_handler:  
                nop
                ajmp        m_int_handler

                END








