/**
 * Silicon Labs C8051F9x registers.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#ifndef BOOS_DRIVER_REGISTERS_H_
#define BOOS_DRIVER_REGISTERS_H_

#define REG_TYPE sfr
#define BIT_TYPE sbit

/**
 * Registers byte addresses
 */
REG_TYPE REG_P0          = 0x80;        /* Port 0 Latch                           */
REG_TYPE REG_SP          = 0x81;        /* Stack Pointer                          */
REG_TYPE REG_DPL         = 0x82;        /* Data Pointer - Low byte                */
REG_TYPE REG_DPH         = 0x83;        /* Data Pointer - High byte               */
REG_TYPE REG_SPI1CFG     = 0x84;        /*                                        */
REG_TYPE REG_SPI1CKR     = 0x85;        /*                                        */
REG_TYPE REG_TOFFL       = 0x85;        /*                                        */
REG_TYPE REG_SPI1DAT     = 0x86;        /*                                        */
REG_TYPE REG_TOFFH       = 0x86;        /*                                        */
REG_TYPE REG_PCON        = 0x87;        /* Power Control                          */
REG_TYPE REG_TCON        = 0x88;        /* Timer Control                          */
REG_TYPE REG_TMOD        = 0x89;        /* Timer Mode                             */
REG_TYPE REG_TL0         = 0x8A;        /* Timer 0 - Low byte                     */
REG_TYPE REG_TL1         = 0x8B;        /* Timer 1 - Low byte                     */
REG_TYPE REG_TH0         = 0x8C;        /* Timer 0 - High byte                    */
REG_TYPE REG_TH1         = 0x8D;        /* Timer 1 - High byte                    */
REG_TYPE REG_CKCON       = 0x8E;        /* Clock Control                          */
REG_TYPE REG_PSCTL       = 0x8F;        /* Program Store R/W Control              */
REG_TYPE REG_P1          = 0x90;        /* Port 1 Latch                           */
REG_TYPE REG_TMR3CN      = 0x91;        /*                                        */
REG_TYPE REG_CRC0DAT     = 0x91;        /*                                        */
REG_TYPE REG_TMR3RLL     = 0x92;        /*                                        */
REG_TYPE REG_CRC0CN      = 0x92;        /*                                        */
REG_TYPE REG_TMR3RLH     = 0x93;        /*                                        */
REG_TYPE REG_CRC0IN      = 0x93;        /*                                        */
REG_TYPE REG_TMR3L       = 0x94;        /*                                        */
REG_TYPE REG_CRC0FLIP    = 0x94;        /*                                        */
REG_TYPE REG_TMR3H       = 0x95;        /*                                        */
REG_TYPE REG_DC0CF       = 0x96;        /*                                        */
REG_TYPE REG_CRC0AUTO    = 0x96;        /*                                        */
REG_TYPE REG_DC0CN       = 0x97;        /*                                        */
REG_TYPE REG_CRC0CNT     = 0x97;        /*                                        */
REG_TYPE REG_SCON0       = 0x98;        /* UART0 Control                          */
REG_TYPE REG_SBUF0       = 0x99;        /* UART0 Buffer                           */
REG_TYPE REG_CPT1CN      = 0x9A;        /* Comparator 1 Control                   */
REG_TYPE REG_CPT0CN      = 0x9B;        /* Comparator 0 Control                   */
REG_TYPE REG_CPT1MD      = 0x9C;        /* Comparator 1 Mode Selection            */
REG_TYPE REG_CPT0MD      = 0x9D;        /* Comparator 0 Mode Selection            */
REG_TYPE REG_CPT1MX      = 0x9E;        /* Comparator 1 Input Channel Select      */
REG_TYPE REG_CPT0MX      = 0x9F;        /* Comparator 0 Input Channel Select      */
REG_TYPE REG_P2          = 0xA0;        /* Port 2 Latch                           */
REG_TYPE REG_SPI0CFG     = 0xA1;        /*                                        */
REG_TYPE REG_SPI0CKR     = 0xA2;        /*                                        */
REG_TYPE REG_SPI0DAT     = 0xA3;        /*                                        */
REG_TYPE REG_P0MDOUT     = 0xA4;        /*                                        */
REG_TYPE REG_P1MDOUT     = 0xA5;        /*                                        */
REG_TYPE REG_P2MDOUT     = 0xA6;        /*                                        */
REG_TYPE REG_SFRPAGE     = 0xA7;        /*                                        */
REG_TYPE REG_IE          = 0xA8;        /* Interrupt Enable                       */
REG_TYPE REG_CLKSEL      = 0xA9;        /* Clock Select                           */
REG_TYPE REG_EMI0CN      = 0xAA;        /*                                        */
REG_TYPE REG_EMI0CF      = 0xAB;        /*                                        */
REG_TYPE REG_RTC0ADR     = 0xAC;        /*                                        */
REG_TYPE REG_P0DRV       = 0xAC;        /*                                        */
REG_TYPE REG_RTC0DAT     = 0xAD;        /*                                        */
REG_TYPE REG_P1DRV       = 0xAD;        /*                                        */
REG_TYPE REG_RTC0KEY     = 0xAE;        /*                                        */
REG_TYPE REG_P2DRV       = 0xAE;        /*                                        */
REG_TYPE REG_EMI0TC      = 0xAF;        /*                                        */
REG_TYPE REG_OSCIFIN     = 0xB0;        /* Internal Fine Oscillator Calibration   */
REG_TYPE REG_OSCXCN      = 0xB1;        /* External Oscillator Control            */
REG_TYPE REG_OSCICN      = 0xB2;        /* Internal Oscillator Control            */
REG_TYPE REG_OSCICL      = 0xB3;        /* Internal Oscillator Calibration        */
REG_TYPE REG_PMU0CF      = 0xB5;        /*                                        */
REG_TYPE REG_FLSCL       = 0xB6;        /*                                        */
REG_TYPE REG_FLKEY       = 0xB7;        /* Flash Lock & Key                       */
REG_TYPE REG_IP          = 0xB8;        /* Interrupt Priority                     */
REG_TYPE REG_IREF0CN     = 0xB9;        /*                                        */
REG_TYPE REG_ADC0PWR     = 0xB9;        /*                                        */
REG_TYPE REG_ADC0AC      = 0xBA;        /*                                        */
REG_TYPE REG_ADC0MX      = 0xBB;        /* ADC0 Mux Channel Selection             */
REG_TYPE REG_ADC0CF      = 0xBC;        /* ADC0 CONFIGURATION                     */
REG_TYPE REG_ADC0L       = 0xBD;        /* ADC0 LSB Result                        */
REG_TYPE REG_ADC0TK      = 0xBD;        /*                                        */
REG_TYPE REG_ADC0H       = 0xBE;        /*                                        */
REG_TYPE REG_P1MASK      = 0xBF;        /*                                        */
REG_TYPE REG_SMB0CN      = 0xC0;        /*                                        */
REG_TYPE REG_SMB0CF      = 0xC1;        /*                                        */
REG_TYPE REG_SMB0DAT     = 0xC2;        /*                                        */
REG_TYPE REG_ADC0GTL     = 0xC3;        /* ADC0 Greater-Than Compare Low          */
REG_TYPE REG_ADC0GTH     = 0xC4;        /* ADC0 Greater-Than Compare High         */
REG_TYPE REG_ADC0LTL     = 0xC5;        /* ADC0 Less-Than Compare Word Low        */
REG_TYPE REG_ADC0LTH     = 0xC6;        /* ADC0 Less-Than Compare Word High       */
REG_TYPE REG_P0MASK      = 0xC7;        /* Port 1 Mask                            */
REG_TYPE REG_TMR2CN      = 0xC8;        /* Timer 2 Control                        */
REG_TYPE REG_REG0CN      = 0xC9;        /* Regulator Control                      */
REG_TYPE REG_TMR2RLL     = 0xCA;        /* Timer 2 Reload Low                     */
REG_TYPE REG_TMR2RLH     = 0xCB;        /* Timer 2 Reload High                    */
REG_TYPE REG_TMR2L       = 0xCC;        /* Timer 2 Low Byte                       */
REG_TYPE REG_TMR2H       = 0xCD;        /* Timer 2 High Byte                      */
REG_TYPE REG_PCA0CPM5    = 0xCE;        /*                                        */
REG_TYPE REG_P1MAT       = 0xCF;        /* Port1 Match                            */
REG_TYPE REG_PSW         = 0xD0;        /* Program Status Word                    */
REG_TYPE REG_REF0CN      = 0xD1;        /* Voltage Reference 0 Control            */
REG_TYPE REG_PCA0CPL5    = 0xD2;        /*                                        */
REG_TYPE REG_PCA0CPH5    = 0xD3;        /*                                        */
REG_TYPE REG_P0SKIP      = 0xD4;        /* Port 0 Skip                            */
REG_TYPE REG_P1SKIP      = 0xD5;        /* Port 1 Skip                            */
REG_TYPE REG_P0MAT       = 0xD7;        /* Port 0 Match                           */
REG_TYPE REG_PCA0CN      = 0xD8;        /* PCA0 Control                           */
REG_TYPE REG_PCA0MD      = 0xD9;        /* PCA0 Mode                              */
REG_TYPE REG_PCA0CPM0    = 0xDA;        /* PCA0 Module 0 Mode                     */
REG_TYPE REG_PCA0CPM1    = 0xDB;        /* PCA0 Module 1 Mode                     */
REG_TYPE REG_PCA0CPM2    = 0xDC;        /* PCA0 Module 2 Mode                     */
REG_TYPE REG_PCA0CPM3    = 0xDD;        /* PCA0 Module 3 Mode                     */
REG_TYPE REG_PCA0CPM4    = 0xDE;        /* PCA0 Module 4 Mode                     */
REG_TYPE REG_PCA0PWM     = 0xDF;        /*                                        */
REG_TYPE REG_ACC         = 0xE0;        /* Accumulator                            */
REG_TYPE REG_XBR0        = 0xE1;        /*                                        */
REG_TYPE REG_XBR1        = 0xE2;        /*                                        */
REG_TYPE REG_XBR2        = 0xE3;        /*                                        */
REG_TYPE REG_IT01CF      = 0xE4;        /*                                        */
REG_TYPE REG_EIE1        = 0xE6;        /*                                        */
REG_TYPE REG_EIE2        = 0xE7;        /*                                        */
REG_TYPE REG_ADC0CN      = 0xE8;        /*                                        */
REG_TYPE REG_PCA0CPL1    = 0xE9;        /*                                        */
REG_TYPE REG_PCA0CPH1    = 0xEA;        /*                                        */
REG_TYPE REG_PCA0CPL2    = 0xEB;        /*                                        */
REG_TYPE REG_PCA0CPH2    = 0xEC;        /*                                        */
REG_TYPE REG_PCA0CPL3    = 0xED;        /*                                        */
REG_TYPE REG_PCA0CPH3    = 0xEE;        /*                                        */
REG_TYPE REG_RSTSRC      = 0xEF;        /*                                        */
REG_TYPE REG_B           = 0xF0;        /* B Register                             */
REG_TYPE REG_P0MDIN      = 0xF1;        /* Port 0 Input Mode                      */
REG_TYPE REG_P1MDIN      = 0xF2;        /* Port 1 Input Mode                      */
REG_TYPE REG_P2MDIN      = 0xF3;        /* Port 2 Input Mode                      */
REG_TYPE REG_SMB0ADR     = 0xF4;        /*                                        */
REG_TYPE REG_SMB0ADM     = 0xF5;        /*                                        */
REG_TYPE REG_EIP1        = 0xF6;        /* Extended Interrupt Priority 1          */
REG_TYPE REG_EIP2        = 0xF7;        /* Extended Interrupt Priority 2          */
REG_TYPE REG_SPI0CN      = 0xF8;        /* SPI0 Control                           */
REG_TYPE REG_PCA0L       = 0xF9;        /* PCA0 Counter Low Byte                  */
REG_TYPE REG_PCA0H       = 0xFA;        /* PCA0 Counter High Byte                 */
REG_TYPE REG_PCA0CPL0    = 0xFB;        /* PCA Module 0 Capture/Compare Low Byte  */
REG_TYPE REG_PCA0CPH0    = 0xFC;        /* PCA Module 0 Capture/Compare High Byte */
REG_TYPE REG_PCA0CPL4    = 0xFD;        /*                                        */
REG_TYPE REG_PCA0CPH4    = 0xFE;        /*                                        */
REG_TYPE REG_VDM0CN      = 0xFF;        /*                                        */

/**
 * Registers bit definitions
 */
/* TCON */
BIT_TYPE REG_TCON_BIT_IT0 = REG_TCON^0;  /* External Interrupt 0 Type            */
BIT_TYPE REG_TCON_BIT_IE0 = REG_TCON^1;  /* External Interrupt 0 Edge Flag       */
BIT_TYPE REG_TCON_BIT_IT1 = REG_TCON^2;  /* External Interrupt 1 Type            */
BIT_TYPE REG_TCON_BIT_IE1 = REG_TCON^3;  /* External Interrupt 1 Edge Flag       */
BIT_TYPE REG_TCON_BIT_TR0 = REG_TCON^4;  /* Timer 0 On/Off Control               */
BIT_TYPE REG_TCON_BIT_TF0 = REG_TCON^5;  /* Timer 0 Overflow Flag                */
BIT_TYPE REG_TCON_BIT_TR1 = REG_TCON^6;  /* Timer 1 On/Off Control               */
BIT_TYPE REG_TCON_BIT_TF1 = REG_TCON^7;  /* Timer 1 Overflow Flag                */

/* SCON0 */
BIT_TYPE REG_SCON0_BIT_RI  = REG_SCON0^0;
BIT_TYPE REG_SCON0_BIT_TI  = REG_SCON0^1;
BIT_TYPE REG_SCON0_BIT_RB8 = REG_SCON0^2;
BIT_TYPE REG_SCON0_BIT_TB8 = REG_SCON0^3;
BIT_TYPE REG_SCON0_BIT_REN = REG_SCON0^4;
BIT_TYPE REG_SCON0_BIT_SM3 = REG_SCON0^5;
BIT_TYPE REG_SCON0_BIT_SM1 = REG_SCON0^6;
BIT_TYPE REG_SCON0_BIT_SM0 = REG_SCON0^7;

/* IE */
BIT_TYPE REG_IE_BIT_EX0 = REG_IE^0;
BIT_TYPE REG_IE_BIT_ET0 = REG_IE^1;
BIT_TYPE REG_IE_BIT_EX1 = REG_IE^2;
BIT_TYPE REG_IE_BIT_ET1 = REG_IE^3;
BIT_TYPE REG_IE_BIT_ES  = REG_IE^4;
BIT_TYPE REG_IE_BIT_EA  = REG_IE^7;

/* IP */
BIT_TYPE REG_IP_BIT_PX0 = REG_IP^0;
BIT_TYPE REG_IP_BIT_PT0 = REG_IP^1;
BIT_TYPE REG_IP_BIT_PX1 = REG_IP^2;
BIT_TYPE REG_IP_BIT_PT1 = REG_IP^3;
BIT_TYPE REG_IP_BIT_PS  = REG_IP^4;

/* PSW */
BIT_TYPE REG_PSW_BIT_P   = REG_PSW^0;
BIT_TYPE REG_PSW_BIT_OV  = REG_PSW^2;
BIT_TYPE REG_PSW_BIT_RS0 = REG_PSW^3;
BIT_TYPE REG_PSW_BIT_RS1 = REG_PSW^4;
BIT_TYPE REG_PSW_BIT_F0  = REG_PSW^5;
BIT_TYPE REG_PSW_BIT_AC  = REG_PSW^6;
BIT_TYPE REG_PSW_BIT_CY  = REG_PSW^7;

#endif /* BOOS_DRIVER_REGISTERS_H_ */

