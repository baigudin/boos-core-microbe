; ----------------------------------------------------------------------------
; Silicon Labs C8051F902 MCU booting startup.
;
; @author    Sergey Baigudin, sergey@baigudin.software
; @copyright 2017-2018, Sergey Baigudin
; @license   http://embedded.team/license/
; ----------------------------------------------------------------------------
$INCLUDE (CpuRegisters.ll.inc)
                 
                PUBLIC      ?c_startup
                EXTRN       CODE (main)
                
?c_c51startup   SEGMENT     CODE
                
; ----------------------------------------------------------------------------
; Stack allocation.
;
; The stack model of ABI has to be Full Ascending, which means that the stack 
; has stack pointer, pointed to the last used location, and grows towards 
; increasing memory addresses.
;
; The stack is locked in internal data (IDATA) memory and occupies upper 
; 128 Bytes of memory.
; ----------------------------------------------------------------------------                
                ISEG AT     80h
v_stack:        DS          80h

; ----------------------------------------------------------------------------
; Memory blocks definitions for initializing by the startup.
; ----------------------------------------------------------------------------

; Internal data memory (IDATA) definition in byte
IDATA_LENGTH    EQU         100h

; External data memory (XDATA) definition in byte
XDATA_LENGTH    EQU         200h

; External data memory page (PDATA) definition
PDATA_PAGE      EQU         0h

; ----------------------------------------------------------------------------
; The bootstrap routine.
; ----------------------------------------------------------------------------
                RSEG        ?c_c51startup
?c_startup:                
m_bootstrap:    
                ; Disable watchdog timer, as it resets 
                ; MCU while it is being initialized.
                anl         REG_PCA0MD, #0BFh
                
                ; Fill the internal data memory (IDATA) with zero
                mov         r0, #IDATA_LENGTH - 1
                clr         a
mc_idata:       mov         @r0, a
                djnz        r0, mc_idata
                
                ; Fill the external data memory (XDATA) with zero 
                mov         dptr, #0
                mov         r7, #LOW(XDATA_LENGTH)
                IF          LOW(XDATA_LENGTH) <> 0
                mov         r6, #HIGH(XDATA_LENGTH) + 1
                ELSE
                mov         r6, #HIGH(XDATA_LENGTH)
                ENDIF
                clr         a
mc_xdata:       movx        @dptr, a
                inc         dptr
                djnz        r7, mc_xdata
                djnz        r6, mc_xdata
                
                ; Set the external data memory page (PDATA)
                mov         REG_EMI0CN, #PDATA_PAGE               

                mov         sp, #v_stack-1
                lcall       main
m_termination:
                ajmp        m_termination
                END
