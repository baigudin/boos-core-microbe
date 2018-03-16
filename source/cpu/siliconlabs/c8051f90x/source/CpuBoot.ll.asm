; ----------------------------------------------------------------------------
; Silicon Labs C8051F9x MCUs booting startup.
;
; @author    Sergey Baigudin, sergey@baigudin.software
; @copyright 2017 Sergey Baigudin
; @license   http://embedded.team/license/
; ----------------------------------------------------------------------------
$INCLUDE (CpuRegisters.ll.inc)
                 
                PUBLIC      ?c_startup
                EXTRN       CODE (main)
                
?c_c51startup   SEGMENT     CODE
                
                ISEG AT     80h
v_stack:        DS          80h

; ----------------------------------------------------------------------------
; Memory blocks definitions for initializing by the startup.
; ----------------------------------------------------------------------------

; Indicates the number of bytes of idata that are to be initialized to 0
IDATALEN        EQU         100h

; Specifies the xdata address to start initializing to 0
XDATASTART      EQU         0h

; Indicates the number of bytes of xdata to be initialized to 0
XDATALEN        EQU         200h

; Specifies the pdata address to start initializing to 0
PDATASTART      EQU         0h

; Indicates the number of bytes of pdata to be initialized to 0
PDATALEN        EQU         100h

; ----------------------------------------------------------------------------
; Stack initialization.
; ----------------------------------------------------------------------------

; Indicates whether or not the small model reentrant stack pointer ( ?C_IBP )
; should be initialized. A value of 1 causes this pointer to be initialized. A
; value of 0 prevents initialization of this pointer.
IBPSTACK        EQU         0h

; Specifies the top start address of the small model reentrant stack area.
; The default is 0xFF in idata memory.
IBPSTACKTOP     EQU         0ffh + 1

; Indicates whether or not the large model reentrant stack pointer ( ?C_XBP )
; should be initialized. A value of 1 causes this pointer to be initialized. A
; value of 0 prevents initialization of this pointer.
XBPSTACK        EQU         0h

; Specifies the top start address of the large model reentrant stack area.
; The default is 0xFFFF in xdata memory.
XBPSTACKTOP     EQU         0ffffh + 1

; Indicates whether the compact model reentrant stack pointer ( ?C_PBP )
; should be initialized. A value of 1 causes this pointer to be initialized. A
; value of 0 prevents initialization of this pointer.
PBPSTACK        EQU         0h

; Specifies the top start address of the compact model reentrant stack area.
; The default is 0xFF in pdata memory.
PBPSTACKTOP     EQU         0ffh + 1

; ----------------------------------------------------------------------------
; Compact Memory Model initialization.
; ----------------------------------------------------------------------------

; Enables (a value of 1) or disables (a value of 0) the initialization of port 2 of
; the 8051 device. The default is 0. The addressing of port 2 allows the
; mapping of 256 byte variable memory in any arbitrary xdata page.
PPAGEENABLE     EQU         0

; Specifies the value to write to Port 2 of the 8051 for pdata memory access.
; This value represents the xdata memory page to use for pdata. This is the
; upper 8 bits of the absolute address range to use for pdata.
;
; For example, if the pdata area begins at address 1000h (page 10h) in the
; xdata memory, PPAGEENABLE should be set to 1, and PPAGE should be
; set to 10h. The BL51 Linker/Locator must contain a value between 1000h
; and 10FFh in the PDATA directive. For example:
;
; BL51 <input modules> PDATA (1050H)
;
; Neither BL51 nor Cx51 checks to see if the PDATA directive and the PPAGE
; assembler constant are correctly specified. You must ensure that these
; parameters contain suitable values.
PPAGE           EQU         0
                
; ----------------------------------------------------------------------------
; The bootstrap routine.
; ----------------------------------------------------------------------------
                RSEG        ?c_c51startup
?c_startup:                
m_bootstrap:    
                ; Disable watchdog timer
                anl         REG_PCA0MD, #0xbf
                ; Zero internal data memory
                IF          IDATALEN <> 0
                mov         r0, #IDATALEN - 1
                clr         a
mc_idata:       mov         @r0, a
                djnz        r0, mc_idata
                ENDIF
                ; Zero external data memory
                IF          XDATALEN <> 0
                mov         dptr, #XDATASTART
                mov         r7,   #LOW(XDATALEN)
                IF          LOW(XDATALEN) <> 0
                mov         r6, #HIGH(XDATALEN) + 1
                ELSE
                mov         r6, #HIGH(XDATALEN)
                ENDIF
                clr         a
mc_xdata:       movx        @dptr, a
                inc         dptr
                djnz        r7, mc_xdata
                djnz        r6, mc_xdata
                ENDIF
                ; Set a page of external data memory
                IF          PPAGEENABLE <> 0
                mov         REG_P2, #PPAGE
                ENDIF
                ; Zero a page of external data memory
                IF          PDATALEN <> 0
                mov         r0, #LOW(PDATASTART)
                mov         r7, #LOW(PDATALEN)
                clr         a
mc_pdata:       movx        @r0, a
                inc         r0
                djnz        r7, mc_pdata
                ENDIF
                
                IF          IBPSTACK <> 0
                EXTRN       DATA (?c_ibp)
                mov         ?c_ibp, #LOW(IBPSTACKTOP)
                ENDIF

                IF          XBPSTACK <> 0
                EXTRN       DATA (?c_xbp)
                mov         ?c_xbp, #HIGH(XBPSTACKTOP)
                mov         ?c_xbp+1, #LOW(XBPSTACKTOP)
                ENDIF

                IF          PBPSTACK <> 0
                EXTRN       DATA (?c_pbp)
                mov         ?c_pbp, #LOW(PBPSTACKTOP)
                ENDIF                

                mov         sp, #v_stack-1
                lcall       main
m_termination:
                ajmp        m_termination
                END
