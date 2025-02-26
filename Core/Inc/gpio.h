/*
P0.0:RX3    P1.0:L9_L   P2.0		P3.0:RX1    P4.0:L1_L   P5.0:L3_H   P6.0		P7.0:L6_L
P0.1:TX3    P1.1:L8_L   P2.1		P3.1:TX1    P4.1:220v_1 P5.1:L4_L   P6.1:L12_L  P7.1:L6_H
P0.2:RX4    P1.2		P2.2:PWM7   P3.2:INT0   P4.2:220v_2 P5.2		P6.2:L11_L  P7.2:L7_L
P0.3:TX4    P1.3:L11_H  P2.3:PWM8   P3.3:L2_H   P4.3:220v_3 P5.3        P6.3:L10_L  P7.3:L7_H
P0.4：T1    P1.4        P2.4		P3.4:L3_L   P4.4:220v_4 P5.4:L12_H  P6.4		P7.4
P0.5：T2    P1.5        P2.5		P3.5:L4_H   P4.5		P5.5		P6.5:L1_H   P7.5:buzzer
P0.6：T3    P1.6:L9_H   P2.6:24V_1  P3.6:L5_L   P4.6		P5.6		P6.6		P7.6:DR3
P0.7        P1.7:L10_H  P2.7:24V_2  P3.7:L5_H   P4.7:L8_H   P5.7		P6.7:L2_L   P7.7:DR4
                                                                                        */

#ifndef __GPIO_H_
#define __GPIO_H_

#include "sys.h"

sbit AC_Out1 = P4^1;
sbit AC_Out2 = P4^2;
sbit AC_Out3 = P4^3;
sbit AC_Out4 = P4^4;

sbit OUT24_2          = P2^7;
sbit relay            = P2^6;

sbit buzzer           = P7^5;

sbit extern_24out2    = P3^5;
sbit extern_24out3    = P5^0;

sbit extern_pwm6      = P2^1;

sbit DC_24V_1         = P2^6;
sbit DC_24V_2         = P2^7;

sbit extern_24in      = P7^4;


void GPIO_Init( void );
    
#endif