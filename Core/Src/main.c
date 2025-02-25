#include "main.h"

void main( void )
{
    P_SW2 |= 0x80;

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

    EA = 1;

    eeprom_statu_judge();
    printf("======== code start ========\r\n"); 

    while (1)
    { 
        // temp.temp_value1 =  get_temp(NTC_1);
        // temp.temp_value2 =  get_temp(NTC_2);
        // temp.temp_value3 =  get_temp(NTC_3);
        // printf(" The value of tmep1 is %d \r\n",(int)temp.temp_value1);
        // printf(" The value of tmep2 is %d \r\n",(int)temp.temp_value2);
        // printf(" The value of tmep3 is %d \r\n",(int)temp.temp_value3);
        temp_scan();
        Modbus_Event();
    }
    
}
