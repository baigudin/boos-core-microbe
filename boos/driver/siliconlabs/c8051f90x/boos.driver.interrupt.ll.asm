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
                EXTRN       CODE (_interruptHandler)                
                
s_isr           SEGMENT     CODE
                
; ----------------------------------------------------------------------------
; Hardware interrupts table.
; ----------------------------------------------------------------------------                
                ; Reset
                CSEG        AT 0000h
m_int_reset:    ljmp        ?c_startup

                ; External Interrupt 0 
                CSEG        AT 0003h 
m_int_00:       clr         REG_IE_BIT_EA
                push        7h
                mov         r7, #0
                ajmp        m_int_handler

                ; Timer 0 Overflow                
                CSEG        AT 000Bh 
m_int_01:       clr         REG_IE_BIT_EA
                push        7h
                mov         r7, #1
                ajmp        m_int_handler

                ; External Interrupt 1                                
                CSEG        AT 0013h 
m_int_02:       clr         REG_IE_BIT_EA
                push        7h
                mov         r7, #2
                ajmp        m_int_handler

                ; Timer 1 Overflow                                 
                CSEG        AT 001Bh
m_int_03:       clr         REG_IE_BIT_EA
                push        7h
                mov         r7, #3
                ajmp        m_int_handler

                ; UART0                                
                CSEG        AT 0023h 
m_int_04:       clr         REG_IE_BIT_EA
                push        7h
                mov         r7, #4
                ajmp        m_int_handler

                ; Timer 2 Overflow                                  
                CSEG        AT 002Bh 
m_int_05:       clr         REG_IE_BIT_EA
                push        7h
                mov         r7, #5
                ajmp        m_int_handler

                ; SPI0                                
                CSEG        AT 0033h
m_int_06:       clr         REG_IE_BIT_EA
                push        7h
                mov         r7, #6
                ajmp        m_int_handler

                ; SMB0                                
                CSEG        AT 003Bh 
m_int_07:       clr         REG_IE_BIT_EA
                push        7h
                mov         r7, #7
                ajmp        m_int_handler

                ; SmaRTClock Alarm                                
                CSEG        AT 0043h 
m_int_08:       clr         REG_IE_BIT_EA
                push        7h
                mov         r7, #8
                ajmp        m_int_handler

                ; ADC0 Window Comparator                                
                CSEG        AT 004Bh
m_int_09:       clr         REG_IE_BIT_EA
                push        7h
                mov         r7, #9
                ajmp        m_int_handler

                ; ADC0 End of Conversion                                 
                CSEG        AT 0053h
m_int_10:       clr         REG_IE_BIT_EA
                push        7h
                mov         r7, #10
                ajmp        m_int_handler

                ; Programmable Counter Array                                
                CSEG        AT 005Bh
m_int_11:       clr         REG_IE_BIT_EA
                push        7h
                mov         r7, #11
                ajmp        m_int_handler

                ; Comparator 0                                
                CSEG        AT 0063h
m_int_12:       clr         REG_IE_BIT_EA
                push        7h
                mov         r7, #12
                ajmp        m_int_handler

                ; Comparator 1                                
                CSEG        AT 006Bh
m_int_13:       clr         REG_IE_BIT_EA
                push        7h
                mov         r7, #13
                ajmp        m_int_handler

                ; Timer 3 Overflow                                
                CSEG        AT 0073h
m_int_14:       clr         REG_IE_BIT_EA
                push        7h
                mov         r7, #14
                ajmp        m_int_handler

                ; Supply Monitor Early Warning                                
                CSEG        AT 007Bh
m_int_15:       clr         REG_IE_BIT_EA
                push        7h
                mov         r7, #15
                ajmp        m_int_handler

                ; Port Match                                 
                CSEG        AT 0083h
m_int_16:       clr         REG_IE_BIT_EA
                push        7h
                mov         r7, #16
                ajmp        m_int_handler

                ; SmaRTClock Oscillator Fail                                
                CSEG        AT 008Bh
m_int_17:       clr         REG_IE_BIT_EA
                push        7h
                mov         r7, #17
                ajmp        m_int_handler

                ; SPI1                                
                CSEG        AT 0093h
m_int_18:       clr         REG_IE_BIT_EA
                push        7h
                mov         r7, #18
                ajmp        m_int_handler

; ----------------------------------------------------------------------------
; Interrupt service routine.
; ----------------------------------------------------------------------------
                RSEG        s_isr
m_int_handler: 
                ; Save the contex
                push        6h
                push        5h
                push        4h
                push        3h
                push        2h
                push        1h
                push        0h
                push        REG_ACC
                push        REG_B
                push        REG_DPH
                push        REG_DPL
                push        REG_PSW
                mov         REG_PSW, #0h
                ; Call high-level handler
                lcall       _interruptHandler
                ; Restore the contex                
                pop         REG_PSW    
                pop         REG_DPL  
                pop         REG_DPH
                pop         REG_B  
                pop         REG_ACC
                pop         0h
                pop         1h
                pop         2h
                pop         3h
                pop         4h
                pop         5h
                pop         6h
                pop         7h                
                setb        REG_IE_BIT_EA                
                reti

                END








