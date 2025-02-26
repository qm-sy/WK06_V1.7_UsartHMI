#ifndef __PWM_CRL_H_
#define __PWM_CRL_H_

#include "sys.h"
#include "pwm.h"

typedef struct 
{
    uint8_t  fan_level;

    uint8_t  stir;
    uint8_t  stir_run_time;   
    uint8_t  stir_wait_time; 
    uint16_t  stir_run_cnt;   
    uint16_t  stir_wait_cnt; 

    uint8_t  cir;
    uint8_t  cir_run_time;  
    uint8_t  cir_wait_time;
    uint16_t  cir_run_cnt;   
    uint16_t  cir_wait_cnt; 

    uint8_t  led_switch;
}DC_24V;

extern DC_24V dc_24v;
            
void pwm7_crl( uint8_t level );
void pwm8_crl( uint8_t level );
#endif
