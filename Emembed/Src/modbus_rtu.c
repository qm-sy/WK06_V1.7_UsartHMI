#include "modbus_rtu.h"

MODBIS_INFO modbus;

/**
 * @brief	modbus_rtu  无奇偶校验
 *
 * @param   void
 *
 * @return  void 
**/
void Modbus_Event( void )
{
    /*1.接收完毕                                           */
    if( rs485.RX4_rcv_end_Flag == 1 )
    {
        /*2.清空接收完毕标志位                              */    
        rs485.RX4_rcv_end_Flag = 0;

        /*3.清空接收计数                                    */
        rs485.RX4_rcv_cnt = 0; 


        /*6.地址域校验通过，进入相应功能进行处理      */
        if( rs485.RX4_buf[0] == MY_ADDR )
        {
            switch ( rs485.RX4_buf[1] )
            {
                case 0x15:
                    rs485.TX4_buf[0] = 0x51;
                    rs485.TX4_buf[1] = 0x15;
                    rs485.TX4_send_bytelength = 2;
                    S4CON |= S4TI;                                  //开始发送
                    break;
                    
                case 0x16:
                    wk06_params_send();                                 //开始发送
                    modbus.scan_allow_flag = 1;
                    break;

                case 0xA0:
                    EX0 = rs485.RX4_buf[2];
                    break;

                case 0xA1:
                    pwm7_crl(rs485.RX4_buf[2]);
                    break;

                case 0xA2:
                    if(rs485.RX4_buf[2] == 0x01)
                    { 
                        level.buzzer_scan_flag = 1;
                    }else
                    {
                        level.buzzer_scan_flag = 0;
                        buzzer = 1;
                    }
                    
                    break;  

                case 0xA3:  
                    dc_24v.fan_level = rs485.RX4_buf[2];
                    pwm8_crl(dc_24v.fan_level);
                    eeprom_data_record();
                    break; 

                case 0xA4:  
                    dc_24v.stir = rs485.RX4_buf[2];
                    DC_24V_out1(dc_24v.stir);
                    break; 

                case 0xA5:  
                    dc_24v.cir = rs485.RX4_buf[2];
                    DC_24V_out2(dc_24v.cir);
                    break; 
                    
                case 0xA6:  
                    temp.temp_alarm_value1 = rs485.RX4_buf[2];
                    temp.temp_alarm_value2 = rs485.RX4_buf[3];
                    temp.temp_alarm_value3 = rs485.RX4_buf[4];
                    eeprom_data_record();
                    break; 

                case 0xA7:  
                    dc_24v.stir_run_time = rs485.RX4_buf[2];
                    dc_24v.stir_wait_time = rs485.RX4_buf[3];
                    dc_24v.cir_run_time = rs485.RX4_buf[4];
                    dc_24v.cir_wait_time = rs485.RX4_buf[5];
                    eeprom_data_record();
                    break; 

                case 0xA8:
                    level.level_info = rs485.RX4_buf[2];
                    eeprom_data_record();
                    break; 

                default:
                    break;
            }
        }
    }
}

void wk06_statu_send( void )
{
    rs485.TX4_buf[0] = 0x51;
    rs485.TX4_buf[1] = 0x17;

    rs485.TX4_buf[2] = temp.temp_value1;
    rs485.TX4_buf[3] = temp.temp_value2;
    rs485.TX4_buf[4] = temp.temp_value3;

    rs485.TX4_buf[5] = level.level1;
    rs485.TX4_buf[6] = level.level2;
    rs485.TX4_buf[7] = level.level3;
    rs485.TX4_buf[8] = level.level4;
    rs485.TX4_buf[9] = level.level5;
    rs485.TX4_buf[10] = level.level6;
    rs485.TX4_buf[11] = level.level7;
    rs485.TX4_buf[12] = level.level8;
    rs485.TX4_buf[13] = level.level9;
    rs485.TX4_buf[14] = level.level10;
    if ( IN_24V == 1 )
    {
        rs485.TX4_buf[15] = 0;
    }else
    {
        rs485.TX4_buf[15] = 1;
    }
    
    rs485.TX4_send_bytelength = 16;
    S4CON |= S4TI;             
}

void wk06_params_send( void )
{
    rs485.TX4_buf[0] = 0x51;
    rs485.TX4_buf[1] = 0x16;
    rs485.TX4_buf[2] = dc_24v.fan_level;
    rs485.TX4_buf[3] = dc_24v.stir_run_time;
    rs485.TX4_buf[4] = dc_24v.stir_wait_time;
    rs485.TX4_buf[5] = dc_24v.cir_run_time;
    rs485.TX4_buf[6] = dc_24v.cir_wait_time;


    rs485.TX4_buf[7] = temp.temp_alarm_value1;
    rs485.TX4_buf[8] = temp.temp_alarm_value2;
    rs485.TX4_buf[9] = temp.temp_alarm_value3;

    rs485.TX4_buf[10] = level.level_info;

    rs485.TX4_send_bytelength = 11;
    S4CON |= S4TI;
}