#ifndef __SERIAL_PORT_H_
#define __SERIAL_PORT_H_

#include "sys.h"
#include "uart.h"
#include "gpio.h"

typedef struct 
{
    uint8_t     TX4_busy_Flag;          //等待发送标志位
    uint8_t     RX4_rcv_end_Flag;       //数据包接收完毕标志
    uint8_t     TX4_buf[128];           //SBUF TI缓冲区
    uint8_t     RX4_buf[128];           //SBUF RI缓冲区
    uint8_t     TX4_send_bytelength;    //发送字节数
    uint8_t     TX4_send_cnt;           //发送计数
    uint16_t    RX4_rcv_timeout;        //接收超时
    uint8_t     RX4_rcv_cnt;            //接收计数
}RS485;

extern RS485 rs485;

void Uart4_Send_Statu_Init( void );

char putchar(char c);

#endif