#include "pwm_crl.h"

PWM_CRL pwm_info;

void pwm7_crl( uint8_t on_off )
{
    if( on_off == 1)
    {
        PWMB_CCR7 = 0x0451;
    }else
    {
        PWMB_CCR7 = 0;
    }
}

void pwm8_crl( uint8_t level )
{
    PWMB_CCR8 = level * 184;
}