#include "main.h"

void main( void )
{
    P_SW2 |= 0x80;
    level.level_scan_flag = 0;
    dc_24v.stir = 0;
    dc_24v.cir = 0;
    modbus.scan_allow_flag = 0;
    level.buzzer_scan_flag = 1;
    GPIO_Init();

    /*  温度控制  */
    ADC_Init();

    /*  4路220输出控制  */
    Power_Statu_Init();
    INT0_Init();
    Timer1_Init();

    /*  PWM控制  */
    PWM_Init();

    /*  modbus控制  */
    Uart4_Send_Statu_Init();
    Timer0_Init();
    Uart4_Init();

    /*  调试使用  */
    Uart1_Init();

    Timer3Init();

    EA = 1;

    eeprom_statu_judge();
    printf("======== code start ========\r\n"); 

    while (1)
    { 
        Modbus_Event();
        if( modbus.scan_allow_flag == 1 )
        {
            temp_level_scan();
        }
    }
}
