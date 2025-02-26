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
                    rs485.TX4_buf[0] = 0x15;
                    rs485.TX4_send_bytelength = 2;
                    S4CON |= S4TI;                                  //开始发送
                    break;

                case 0xA0:
                    EX0 = rs485.RX4_buf[2];
                    break;

                case 0xA1:
                    pwm8_crl(rs485.RX4_buf[2]);
                    break;

                case 0xA2:
                    buzzer = rs485.RX4_buf[2];
                    break;  

                case 0xA3:  
                    pwm7_crl(rs485.RX4_buf[2]);

                case 0xA4:  
                    DC_24V_out1(rs485.RX4_buf[2]);

                case 0xA5:  
                    DC_24V_out2(rs485.RX4_buf[2]);
                
                case 0xA6:  
                    temp.temp_alarm_value1 = rs485.RX4_buf[2];
                    temp.temp_alarm_value2 = rs485.RX4_buf[3];
                    temp.temp_alarm_value3 = rs485.RX4_buf[4];

                case 0xA7:  
                    pwm_info.stir_time = rs485.RX4_buf[2];
                    pwm_info.stir_wait_time = rs485.RX4_buf[3];
                    pwm_info.cir_time = rs485.RX4_buf[4];
                    pwm_info.cir_wait_time = rs485.RX4_buf[5];

                default:
                    break;
            }
        }
    }
}
