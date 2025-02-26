#include "common.h"

void temp_level_scan( void )
{
    if( level.level_scan_flag == 1 )
    {
        temp.temp_value1 =  get_temp(NTC_1);
        if( temp.temp_value1 >= temp.temp_alarm_value1 ) 
        {
            ac_220.channel1_flag = 0;        //001
        }else
        {
            ac_220.channel1_flag = 1;
        }
        temp.temp_value2 =  get_temp(NTC_2);
        if( temp.temp_value2 >= temp.temp_alarm_value2 ) 
        {
            ac_220.channel2_flag = 0;        //001
        }else
        {
            ac_220.channel2_flag = 1;
        }
        temp.temp_value3 =  get_temp(NTC_3);
        if( temp.temp_value3 >= temp.temp_alarm_value3 ) 
        {
            ac_220.channel3_flag = 0;        //001
        }else
        {
            ac_220.channel3_flag = 1;
        }
        level.level1234    = L1_L | L1_H | L2_L  | L2_H  | L3_L  | L3_H  | L4_L  | L4_H;
        level.level5678    = L5_L | L5_H | L6_L  | L6_H  | L7_L  | L7_H  | L8_L  | L8_H;
        level.level9101112 = L9_L | L9_H | L10_L | L10_H | L11_L | L11_H | L12_L | L12_H;
        wk06_statu_send();
        level.level_scan_flag = 0;
    } 
}
void Tim3_ISR( void ) interrupt 19   //1ms
{
    static uint8_t level_sacn_cnt = 0;

    if( level.level_scan_flag == 0 )
    {
        level_sacn_cnt++;
        if( level_sacn_cnt == 100 )
        {
            level.level_scan_flag = 1; 
        }
    }
}
