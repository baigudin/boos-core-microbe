; ----------------------------------------------------------------------------
; Silicon Labs C8051F9x registers.
;
; @author    Sergey Baigudin, sergey@baigudin.software
; @copyright 2017 Sergey Baigudin
; @license   http://baigudin.software/license/
; @link      http://baigudin.software
; ---------------------------------------------------------------------------- 

; 
; Registers byte addresses
; 
REG_P0        DATA  080h        ; Port 0 Latch                          
REG_SP        DATA  081h        ; Stack Pointer                         
REG_DPL       DATA  082h        ; Data Pointer - Low byte               
REG_DPH       DATA  083h        ; Data Pointer - High byte              
REG_SPI1CFG   DATA  084h        ;                                       
REG_SPI1CKR   DATA  085h        ;                                       
REG_TOFFL     DATA  085h        ;                                       
REG_SPI1DAT   DATA  086h        ;                                       
REG_TOFFH     DATA  086h        ;                                       
REG_PCON      DATA  087h        ; Power Control                         
REG_TCON      DATA  088h        ; Timer Control                         
REG_TMOD      DATA  089h        ; Timer Mode                            
REG_TL0       DATA  08Ah        ; Timer 0 - Low byte                    
REG_TL1       DATA  08Bh        ; Timer 1 - Low byte                    
REG_TH0       DATA  08Ch        ; Timer 0 - High byte                   
REG_TH1       DATA  08Dh        ; Timer 1 - High byte                   
REG_CKCON     DATA  08Eh        ; Clock Control                         
REG_PSCTL     DATA  08Fh        ; Program Store R/W Control             
REG_P1        DATA  090h        ; Port 1 Latch                          
REG_TMR3CN    DATA  091h        ;                                       
REG_CRC0DAT   DATA  091h        ;                                       
REG_TMR3RLL   DATA  092h        ;                                       
REG_CRC0CN    DATA  092h        ;                                       
REG_TMR3RLH   DATA  093h        ;                                       
REG_CRC0IN    DATA  093h        ;                                       
REG_TMR3L     DATA  094h        ;                                       
REG_CRC0FLIP  DATA  094h        ;                                       
REG_TMR3H     DATA  095h        ;                                       
REG_DC0CF     DATA  096h        ;                                       
REG_CRC0AUTO  DATA  096h        ;                                       
REG_DC0CN     DATA  097h        ;                                       
REG_CRC0CNT   DATA  097h        ;                                       
REG_SCON0     DATA  098h        ; UART0 Control                         
REG_SBUF0     DATA  099h        ; UART0 Buffer                          
REG_CPT1CN    DATA  09Ah        ;                                       
REG_CPT0CN    DATA  09Bh        ;                                       
REG_CPT1MD    DATA  09Ch        ;                                       
REG_CPT0MD    DATA  09Dh        ;                                       
REG_CPT1MX    DATA  09Eh        ;                                       
REG_CPT0MX    DATA  09Fh        ;                                       
REG_P2        DATA  0A0h        ; Port 2 Latch                          
REG_SPI0CFG   DATA  0A1h        ;                                       
REG_SPI0CKR   DATA  0A2h        ;                                       
REG_SPI0DAT   DATA  0A3h        ;                                       
REG_P0MDOUT   DATA  0A4h        ;                                       
REG_P1MDOUT   DATA  0A5h        ;                                       
REG_P2MDOUT   DATA  0A6h        ;                                       
REG_SFRPAGE   DATA  0A7h        ;                                       
REG_IE        DATA  0A8h        ; Interrupt Enable                      
REG_CLKSEL    DATA  0A9h        ; Clock Select                          
REG_EMI0CN    DATA  0AAh        ;                                       
REG_EMI0CF    DATA  0ABh        ;                                       
REG_RTC0ADR   DATA  0ACh        ;                                       
REG_P0DRV     DATA  0ACh        ;                                       
REG_RTC0DAT   DATA  0ADh        ;                                       
REG_P1DRV     DATA  0ADh        ;                                       
REG_RTC0KEY   DATA  0AEh        ;                                       
REG_P2DRV     DATA  0AEh        ;                                       
REG_EMI0TC    DATA  0AFh        ;                                       
REG_OSCIFIN   DATA  0B0h        ; Internal Fine Oscillator Calibration  
REG_OSCXCN    DATA  0B1h        ; External Oscillator Control           
REG_OSCICN    DATA  0B2h        ; Internal Oscillator Control           
REG_OSCICL    DATA  0B3h        ; Internal Oscillator Calibration       
REG_PMU0CF    DATA  0B5h        ;                                       
REG_FLSCL     DATA  0B6h        ;                                       
REG_FLKEY     DATA  0B7h        ; Flash Lock & Key                      
REG_IP        DATA  0B8h        ; Interrupt Priority                    
REG_IREF0CN   DATA  0B9h        ;                                       
REG_ADC0PWR   DATA  0B9h        ;                                       
REG_ADC0AC    DATA  0BAh        ;                                       
REG_ADC0MX    DATA  0BBh        ; ADC0 Mux Channel Selection            
REG_ADC0CF    DATA  0BCh        ; ADC0 CONFIGURATION                    
REG_ADC0L     DATA  0BDh        ; ADC0 LSB Result                       
REG_ADC0TK    DATA  0BDh        ;                                       
REG_ADC0H     DATA  0BEh        ;                                       
REG_P1MASK    DATA  0BFh        ;                                       
REG_SMB0CN    DATA  0C0h        ;                                       
REG_SMB0CF    DATA  0C1h        ;                                       
REG_SMB0DAT   DATA  0C2h        ;                                       
REG_ADC0GTL   DATA  0C3h        ; ADC0 Greater-Than Compare Low         
REG_ADC0GTH   DATA  0C4h        ; ADC0 Greater-Than Compare High        
REG_ADC0LTL   DATA  0C5h        ; ADC0 Less-Than Compare Word Low       
REG_ADC0LTH   DATA  0C6h        ; ADC0 Less-Than Compare Word High      
REG_P0MASK    DATA  0C7h        ; Port 1 Mask                           
REG_TMR2CN    DATA  0C8h        ; Timer 2 Control                       
REG_REG0CN    DATA  0C9h        ; Regulator Control                     
REG_TMR2RLL   DATA  0CAh        ; Timer 2 Reload Low                    
REG_TMR2RLH   DATA  0CBh        ; Timer 2 Reload High                   
REG_TMR2L     DATA  0CCh        ; Timer 2 Low Byte                      
REG_TMR2H     DATA  0CDh        ; Timer 2 High Byte                     
REG_PCA0CPM5  DATA  0CEh        ;                                       
REG_P1MAT     DATA  0CFh        ; Port1 Match                           
REG_PSW       DATA  0D0h        ; Program Status Word                   
REG_REF0CN    DATA  0D1h        ; Voltage Reference 0 Control           
REG_PCA0CPL5  DATA  0D2h        ;                                       
REG_PCA0CPH5  DATA  0D3h        ;                                       
REG_P0SKIP    DATA  0D4h        ; Port 0 Skip                           
REG_P1SKIP    DATA  0D5h        ; Port 1 Skip                           
REG_P0MAT     DATA  0D7h        ; Port 0 Match                          
REG_PCA0CN    DATA  0D8h        ; PCA0 Control                          
REG_PCA0MD    DATA  0D9h        ; PCA0 Mode                             
REG_PCA0CPM0  DATA  0DAh        ; PCA0 Module 0 Mode                    
REG_PCA0CPM1  DATA  0DBh        ; PCA0 Module 1 Mode                    
REG_PCA0CPM2  DATA  0DCh        ; PCA0 Module 2 Mode                    
REG_PCA0CPM3  DATA  0DDh        ; PCA0 Module 3 Mode                    
REG_PCA0CPM4  DATA  0DEh        ; PCA0 Module 4 Mode                    
REG_PCA0PWM   DATA  0DFh        ;                                       
REG_ACC       DATA  0E0h        ; Accumulator                           
REG_XBR0      DATA  0E1h        ;                                       
REG_XBR1      DATA  0E2h        ;                                       
REG_XBR2      DATA  0E3h        ;                                       
REG_IT01CF    DATA  0E4h        ;                                       
REG_EIE1      DATA  0E6h        ;                                       
REG_EIE2      DATA  0E7h        ;                                       
REG_ADC0CN    DATA  0E8h        ;                                       
REG_PCA0CPL1  DATA  0E9h        ;                                       
REG_PCA0CPH1  DATA  0EAh        ;                                       
REG_PCA0CPL2  DATA  0EBh        ;                                       
REG_PCA0CPH2  DATA  0ECh        ;                                       
REG_PCA0CPL3  DATA  0EDh        ;                                       
REG_PCA0CPH3  DATA  0EEh        ;                                       
REG_RSTSRC    DATA  0EFh        ;                                       
REG_B         DATA  0F0h        ; B Register                            
REG_P0MDIN    DATA  0F1h        ; Port 0 Input Mode                     
REG_P1MDIN    DATA  0F2h        ; Port 1 Input Mode                     
REG_P2MDIN    DATA  0F3h        ; Port 2 Input Mode                     
REG_SMB0ADR   DATA  0F4h        ;                                       
REG_SMB0ADM   DATA  0F5h        ;                                       
REG_EIP1      DATA  0F6h        ; Extended Interrupt Priority 1         
REG_EIP2      DATA  0F7h        ; Extended Interrupt Priority 2         
REG_SPI0CN    DATA  0F8h        ; SPI0 Control                          
REG_PCA0L     DATA  0F9h        ; PCA0 Counter Low Byte                 
REG_PCA0H     DATA  0FAh        ; PCA0 Counter High Byte                
REG_PCA0CPL0  DATA  0FBh        ; PCA Module 0 Capture/Compare Low Byte 
REG_PCA0CPH0  DATA  0FCh        ; PCA Module 0 Capture/Compare High Byte
REG_PCA0CPL4  DATA  0FDh        ;                                       
REG_PCA0CPH4  DATA  0FEh        ;                                       
REG_VDM0CN    DATA  0FFh        ;                                       

; 
; Registers bit definitions
; 

; TCON
REG_TCON_BIT_IT0  BIT  088h     ; External Interrupt 0 Type
REG_TCON_BIT_IE0  BIT  089h     ; External Interrupt 0 Edge Flag
REG_TCON_BIT_IT1  BIT  08Ah     ; External Interrupt 1 Type
REG_TCON_BIT_IE1  BIT  08Bh     ; External Interrupt 1 Edge Flag
REG_TCON_BIT_TR0  BIT  08Ch     ; Timer 0 On/Off Control
REG_TCON_BIT_TF0  BIT  08Dh     ; Timer 0 Overflow Flag
REG_TCON_BIT_TR1  BIT  08Eh     ; Timer 1 On/Off Control
REG_TCON_BIT_TF1  BIT  08Fh     ; Timer 1 Overflow Flag

; SCON0
REG_SCON0_BIT_RI   BIT  098h
REG_SCON0_BIT_TI   BIT  099h
REG_SCON0_BIT_RB8  BIT  09Ah
REG_SCON0_BIT_TB8  BIT  09Bh
REG_SCON0_BIT_REN  BIT  09Ch
REG_SCON0_BIT_SM3  BIT  09Dh
REG_SCON0_BIT_SM1  BIT  09Eh
REG_SCON0_BIT_SM0  BIT  09Fh

; IE
REG_IE_BIT_EX0  BIT  0A8h
REG_IE_BIT_ET0  BIT  0A9h
REG_IE_BIT_EX1  BIT  0AAh
REG_IE_BIT_ET1  BIT  0ABh
REG_IE_BIT_ES   BIT  0ACh
REG_IE_BIT_EA   BIT  0AFh

; IP
REG_IP_BIT_PX0  BIT  0B8h
REG_IP_BIT_PT0  BIT  0B9h
REG_IP_BIT_PX1  BIT  0BAh
REG_IP_BIT_PT1  BIT  0BBh
REG_IP_BIT_PS   BIT  0BCh

; PSW
REG_PSW_BIT_P    BIT  0D0h
REG_PSW_BIT_OV   BIT  0D2h
REG_PSW_BIT_RS0  BIT  0D3h
REG_PSW_BIT_RS1  BIT  0D4h
REG_PSW_BIT_F0   BIT  0D5h
REG_PSW_BIT_AC   BIT  0D6h
REG_PSW_BIT_CY   BIT  0D7h
