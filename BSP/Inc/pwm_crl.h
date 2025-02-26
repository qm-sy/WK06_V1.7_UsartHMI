#ifndef __PWM_CRL_H_
#define __PWM_CRL_H_

#include "sys.h"
#include "pwm.h"

typedef struct 
{
    uint8_t  stir_time;   
    uint8_t  stir_wait_time;  
    uint8_t  cir_time;  
    uint8_t  cir_wait_time;

}PWM_CRL;

extern PWM_CRL pwm_info;

void pwm7_crl( uint8_t level );
void pwm8_crl( uint8_t level );
#endif
