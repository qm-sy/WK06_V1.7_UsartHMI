#include "eeprom_crl.h"

EEPROM_INFO eeprom;

/**
 * @brief	eeprom状态判定，是否写入过
 *
 * @param   
 *
 * @return  void
**/
void eeprom_statu_judge( void )
{
    uint8_t eeprom_statu_flag;

    eeprom_statu_flag = ISP_Read(EEPROM_STATU_JUDGE);
    //printf("The value of eeprom_statu_flag is 0x%02x \r\n",(int)eeprom_statu_flag);
    if( eeprom_statu_flag == 0xFF)
    {

        dc_24v.fan_level          = 3;
        eeprom.led_info          = 0;
        eeprom.stir_info         = 0;
        eeprom.cir_info          = 0;  
        dc_24v.stir_run_time     = 10; 
        dc_24v.stir_wait_time    = 10; 
        dc_24v.cir_run_time      = 10;
        dc_24v.cir_wait_time     = 10;
        level.level_info         = 60;
        temp.temp_alarm_value1   = 90;        
        temp.temp_alarm_value2   = 90;       
        temp.temp_alarm_value3   = 90;

        eeprom_data_record(); 
    }
    eeprom_data_init();    
}

/**
 * @brief	eeprom 数据写入
 *
 * @param   
 *
 * @return  void
**/
void eeprom_data_record( void )
{
    ISP_Earse(0x0000);

    eeprom.pwm_info = dc_24v.fan_level;
    ISP_Write(PWM_ADDR_EEPROM,eeprom.pwm_info);


    ISP_Write(LED_ADDR_EEPROM,eeprom.led_info);

    eeprom.stir_run_time = dc_24v.stir_run_time;
    eeprom.stir_wait_time = dc_24v.stir_wait_time;
    eeprom.cir_run_time = dc_24v.cir_run_time;
    eeprom.cir_wait_time = dc_24v.cir_wait_time;
    ISP_Write(STIR,eeprom.stir_info);
    ISP_Write(STIR_RUN,eeprom.stir_run_time);
    ISP_Write(STIR_WAIT,eeprom.stir_wait_time);
    ISP_Write(CIR,eeprom.cir_run_time);
    ISP_Write(CIR_RUN,eeprom.cir_run_time);
    ISP_Write(CIR_WAIT,eeprom.cir_wait_time);
    //ISP_Write(AC220_ADDR_EEPROM,eeprom.ac220_info);

    eeprom.level_delay_time = level.level_info;
    ISP_Write(LEVEL_DELAY,eeprom.level_delay_time);

    eeprom.temp_alarm_value1 = temp.temp_alarm_value1;
    eeprom.temp_alarm_value2 = temp.temp_alarm_value2;
    eeprom.temp_alarm_value3 = temp.temp_alarm_value3;
    ISP_Write(TEMP1_ALARM,eeprom.temp_alarm_value1);
    ISP_Write(TEMP2_ALARM,eeprom.temp_alarm_value2);
    ISP_Write(TEMP3_ALARM,eeprom.temp_alarm_value3);

    ISP_Write(EEPROM_STATU_JUDGE,0x58);

    printf("The value of stir_run_time is %d \r\n",(int)eeprom.stir_run_time);
    printf("The value of stir_stop_time is %d \r\n",(int)eeprom.stir_wait_time);
    printf("The value of cir_run_time is %d \r\n",(int)eeprom.cir_run_time);
    printf("The value of cir_stop_time is %d \r\n",(int)eeprom.cir_wait_time);
    printf("The value of temp_alarm_value1 is %d \r\n",(int)eeprom.temp_alarm_value1);
    printf("The value of temp_alarm_value2 is %d \r\n",(int)eeprom.temp_alarm_value2);
    printf("The value of temp_alarm_value3 is %d \r\n",(int)eeprom.temp_alarm_value3);
    printf("The value of level_delay_time is %d \r\n",(int)eeprom.level_delay_time);
}

/**
 * @brief	eeprom 数据初始化
 *
 * @param   
 *
 * @return  void
**/  
void eeprom_data_init( void )
{
    /*    PWM8 风速及开关状态初始化    */
    eeprom.pwm_info = ISP_Read(PWM_ADDR_EEPROM);
    pwm8_crl(eeprom.pwm_info);
    

    /*    LED开关状态初始化    */
    eeprom.led_info = ISP_Read(LED_ADDR_EEPROM);
    pwm7_crl(eeprom.led_info);

    //DC_24V_out(led1_statu,led2_statu);
    eeprom.stir_info = ISP_Read(STIR);
    DC_24V_out1(eeprom.stir_info);

    eeprom.stir_info = ISP_Read(CIR);
    DC_24V_out2(eeprom.cir_info);

    eeprom.stir_run_time = ISP_Read(STIR_RUN);
    dc_24v.stir_run_time = eeprom.stir_run_time;
    eeprom.stir_wait_time = ISP_Read(STIR_WAIT);
    dc_24v.stir_wait_time = eeprom.stir_wait_time;

    eeprom.cir_run_time = ISP_Read(CIR_RUN);
    dc_24v.cir_run_time = eeprom.cir_run_time;
    eeprom.cir_wait_time = ISP_Read(CIR_WAIT);
    dc_24v.cir_wait_time = eeprom.cir_wait_time;

    eeprom.temp_alarm_value1 = ISP_Read(TEMP1_ALARM);
    temp.temp_alarm_value1 = eeprom.temp_alarm_value1;
    eeprom.temp_alarm_value2 = ISP_Read(TEMP2_ALARM);
    temp.temp_alarm_value2 = eeprom.temp_alarm_value2;
    eeprom.temp_alarm_value3 = ISP_Read(TEMP3_ALARM);
    temp.temp_alarm_value3 = eeprom.temp_alarm_value3;
}
