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
    uint16_t crc,rccrc;

    /*1.接收完毕                                           */
    if( rs485.RX4_rcv_end_Flag == 1 )
    {
        /*2.清空接收完毕标志位                              */    
        rs485.RX4_rcv_end_Flag = 0;

        /*3.CRC校验                                         */
        crc = MODBUS_CRC16(rs485.RX4_buf, rs485.RX4_rcv_cnt-2);
        rccrc = (rs485.RX4_buf[rs485.RX4_rcv_cnt-2]<<8) | (rs485.RX4_buf[rs485.RX4_rcv_cnt-1]);

        /*4.清空接收计数                                    */
        rs485.RX4_rcv_cnt = 0; 

        /*5.CRC校验通过，进行地址域校验                      */
        if( crc == rccrc )
        {
            /*6.地址域校验通过，进入相应功能函数进行处理      */
            if( rs485.RX4_buf[0] == MY_ADDR )
            {
                switch ( rs485.RX4_buf[1] )
                {
                    case 0x03:
                        Modbus_Fun3();
                        break;

                    case 0x04:
                        Modbus_Fun4();
                        break;

                    case 0x06:
                        Modbus_Fun6();
                        break;  

                    case 0x10:  
                        Modbus_Fun16();

                    default:
                        break;
                }
            }
        }
    }
}

/**
 * @brief	读输出寄存器  03
 *
 * @param   void
 *
 * @return  void 
**/
void Modbus_Fun3( void )
{
    uint16_t i;

    modbus.send_value_addr  = 3;                 //DATA1 H 位置
    modbus.byte_cnt   = (rs485.RX4_buf[4]<<8 | rs485.RX4_buf[5]) *2;
    modbus.start_addr = rs485.RX4_buf[2]<<8 | rs485.RX4_buf[3];

    rs485.TX4_buf[0]  = MY_ADDR;                //Addr
    rs485.TX4_buf[1]  = 0x03;                   //Fun
    rs485.TX4_buf[2]  = modbus.byte_cnt;        //Byte Count

    for( i = modbus.start_addr; i < modbus.start_addr + modbus.byte_cnt/2; i++ )
    {
        /*    每次循环前初始化byte_info                       */
        modbus.byte_info_H = modbus.byte_info_L = 0X00;
        switch (i)
        {
            /*  40001  两路PWM 开关状态及风速查询                 */
            case 0:

                break;

            /*  40002  LED开关状态查询                          */
            case 1:

                 break;

            /*  40003  220V CH4开关状态及功率查询               */
            case 2:

                break;

            /*  40004 NTC1 NTC2 alarm value查询                       */
            case 3:
     
                break;

            /*  40005 NTC3 alarm value查询                            */
            case 4:
       
                break;

            default:
                break;
        }
        rs485.TX4_buf[modbus.send_value_addr++] = modbus.byte_info_H;
        rs485.TX4_buf[modbus.send_value_addr++] = modbus.byte_info_L;
    }
    slave_to_master(3 + modbus.byte_cnt);
}


/**
 * @brief	读输入寄存器  04
 *
 * @param   void
 *
 * @return  void 
**/
void Modbus_Fun4( void )
{
    uint16_t i;

    modbus.send_value_addr  = 3;                //DATA1 H 位置
    modbus.byte_cnt   = (rs485.RX4_buf[4]<<8 | rs485.RX4_buf[5]) *2;
    modbus.start_addr = rs485.RX4_buf[2]<<8 | rs485.RX4_buf[3];

    rs485.TX4_buf[0]  = MY_ADDR;                //Addr
    rs485.TX4_buf[1]  = 0x04;                   //Fun
    rs485.TX4_buf[2]  = modbus.byte_cnt;        //Byte Count

    for( i = modbus.start_addr; i < modbus.start_addr + modbus.byte_cnt/2; i++ )
    {
        /*    每次循环前初始化byte_info                       */
        modbus.byte_info_H = modbus.byte_info_L = 0X00;
        switch (i)
        {   
            /*  30001 NTC1 NTC2温度查询                     */
            case 0:

                break;

            /*  30002 NTC3 NTC4温度查询                     */    
            case 1:

                break;

            /*    30003 2路IR查询                         */
            case 2:    
 
                break;

            // /*    30004 I_OUT1 I_OUT2 电流查询              */
            // case 3:    
            //     modbus.byte_info_H = get_current(I_OUT2);     
            //     modbus.byte_info_L = get_current(I_OUT1);     
            //     break;

            // /*    30005 I_OUT3 电流查询                     */
            // case 4:    
            //     modbus.byte_info_H = 0X00;                    
            //     modbus.byte_info_L = get_current(I_OUT3);     
            //     break;

            default:
                break;
        }
        rs485.TX4_buf[modbus.send_value_addr++] = modbus.byte_info_H;
        rs485.TX4_buf[modbus.send_value_addr++] = modbus.byte_info_L;
    }
    slave_to_master(3 + modbus.byte_cnt);
 }

/**
 * @brief	写单个输出寄存器  06
 *
 * @param   void
 *
 * @return  void 
**/
void Modbus_Fun6( void )
{
    switch (rs485.RX4_buf[3])
    {
        /*  40001  两路PWM 开关状态及风速设置                 */
        case 0:             


          break;

        /*  40002  24V LED开关状态设置                          */
        case 1:                                         

            break;

        /*  40003  220V 开关及大小设置                          */
        case 2:                                         


            break;  
            
        /*  40004  NTC1 NTC2 alarm value 设置                   */
        case 3:                                         

            break;

        /*  40005  NTC3 alarm value 设置                        */
        case 4:                                         

            break;
        default:
            break;   
    }
}

/**
 * @brief	写多个输出寄存器  16
 *
 * @param   void
 *
 * @return  void 
**/
void Modbus_Fun16( void )
{
    uint16_t crc;
    uint16_t i;

    modbus.rcv_value_addr = 7;                  //DATA1 H位置
    modbus.byte_cnt   = rs485.RX4_buf[6];
    modbus.start_addr = rs485.RX4_buf[2]<<8 | rs485.RX4_buf[3];

    memcpy(rs485.TX4_buf,rs485.RX4_buf,6);

    for( i = modbus.start_addr; i < modbus.start_addr + modbus.byte_cnt/2; i++)
    {
        modbus.byte_info_H = rs485.RX4_buf[modbus.rcv_value_addr];
        modbus.byte_info_L = rs485.RX4_buf[modbus.rcv_value_addr + 1];
        switch (i)
        {
            /*  40001  两路PWM 开关状态及风速设置                 */
            case 0:

                break;
            
            /*  40002  24V LED开关状态设置                          */
            case 1:

                break;

            /*  40003  220V 开关及大小设置                          */
            case 2:

                break;

            /*  40004  NTC1 NTC2 alarm value 设置                   */
            case 3:

                break;

            /*  40005  NTC3 alarm value 设置                        */
            case 4:

                break;

            default:
                break;
        }
        modbus.rcv_value_addr += 2;         //从Value1_H →→ 从Value2_H
    }
    
    crc = MODBUS_CRC16(rs485.TX4_buf,6);
    rs485.TX4_buf[6] = crc>>8;                 //CRC H
    rs485.TX4_buf[7] = crc;                    //CRC L

    rs485.TX4_send_bytelength = 8;

    //DR2 = 1;                                   //485可以发送
    delay_ms(5);
    S2CON |= S4TI;  

    eeprom_data_record();                      //记录更改后的值
}

/**
 * @brief	crc校验函数
 * 
 * @param   buf：  Address(1 byte) +Funtion(1 byte) ）+Data(n byte)   
 * @param   length:数据长度           
 * 
  @return  crc16:crc校验的值 2byte
 */
uint16_t MODBUS_CRC16(uint8_t *buf, uint8_t length)
{
	uint8_t	i;
	uint16_t	crc16;

    /* 1, 预置16位CRC寄存器为0xffff（即全为1）                          */
	crc16 = 0xffff;	

	do
	{
        /* 2, 把8位数据与16位CRC寄存器的低位相异或，把结果放于CRC寄存器     */        
		crc16 ^= (uint16_t)*buf;		//
		for(i=0; i<8; i++)		
		{
            /* 3, 如果最低位为1，把CRC寄存器的内容右移一位(朝低位)，用0填补最高位 再异或0xA001    */
			if(crc16 & 1)
            {
                crc16 = (crc16 >> 1) ^ 0xA001;
            }
            /* 4, 如果最低位为0，把CRC寄存器的内容右移一位(朝低位)，用0填补最高位                */
            else
            {
                crc16 >>= 1;
            }		
		}
		buf++;
	}while(--length != 0);

	return	(crc16);
}

/**
 * @brief	从机回复主机
 *  
 * @param   length:数据长度           
 * 
  @return  crc16:crc校验的值 2byte
 */
void slave_to_master(uint8_t length)
{
    uint16_t crc;

    crc = MODBUS_CRC16(rs485.TX4_buf,length);

    rs485.TX4_buf[length] = crc>>8;                 //CRC H
    rs485.TX4_buf[length+1] = crc;                  //CRC L

    rs485.TX4_send_bytelength = length + 2;

    //DR2 = 1;                                        //485可以发送
    delay_ms(5);
    S2CON |= S4TI;                                  //开始发送
}

// void slave_scan( void )
// {
//     uint8_t send_buf[12];
//     uint16_t crc;
//     if( rs485.send_scan_flag == 1)
//     {
//         send_buf[0] = 0x35;
//         send_buf[1] = 0x03;
//         send_buf[2] = temp.temp_value1;
//         send_buf[3] = temp.temp_value2;
//         send_buf[4] = temp.temp_value3;
//         send_buf[5] = get_current(I_OUT1); 
//         send_buf[6] = get_current(I_OUT2); 
//         send_buf[7] = get_current(I_OUT3); 
//         send_buf[8] = ((PWMB_CCR8/184)<<4 | (PWMB_CCR8/184));
//         if( INTCLKO & 0x10 )
//         {
//             send_buf[9] = 0x01;                             //220V运行状态
//         }else
//         {
//             send_buf[9] = 0x00;
//         }
//         send_buf[10]= (uint8_t)((ac_220.time_delay-58000)/75);

//         crc = MODBUS_CRC16(send_buf,11);
    
//         send_buf[11] = crc>>8;
//         send_buf[12] = crc;
    
//         memcpy(rs485.TX4_buf,send_buf,13);
    
//         rs485.TX4_send_bytelength = 13;
//         DR2 = 1;                                        //485可以发送
//         delay_ms(5);
//         S2CON |= S4TI;                                  //开始发送

//         rs485.send_scan_flag = 0;
//         //DR2 = 0;
//     }  
// }