#include "power_crl.h"

AC_220 ac_220;

/**
 * @brief	移相触发调用结构体初始化
 *
 * @param   
 *
 * @return  void
**/
void Power_Statu_Init( void )
{
    ac_220.zero_flag  = 0;
    ac_220.channel1_flag = 1;
    ac_220.channel2_flag = 1;
    ac_220.channel3_flag = 1;
    AC_Out1 = AC_Out2 = AC_Out3 = 1;
}

/**
 * @brief	外部中断0中断处理函数
 *
 * @param   
 *
 * @return  void
**/
void INT0_ISR( void ) interrupt 0
{
    /* 1, 检测到外部中断后，等待THL\TLI后触发TIM1中断       */
    TL1 = 65500;				
	TH1 = 65500 >> 8;				

    ac_220.zero_flag = 1;

    /* 2, 定时器1开始计时，打开TIM1中断                     */
    TR1 = 1;				     
    ET1 = 1; 
}

/**
 * @brief	Timer1中断处理函数
 *
 * @param   
 *
 * @return  void
**/
void Tim1_ISR( void ) interrupt 3   //1ms
{
    /* 1, 中断触发后，power_ch电平 由高电平变为低电平           */
    if( ac_220.zero_flag == 1 )
    {
        ac_220.zero_flag = 0;
        if(ac_220.channel1_flag == 1)
        {
            AC_Out1 = 0;
        }
        if(ac_220.channel2_flag == 1)
        {
            AC_Out2 = 0;
        }
        if(ac_220.channel3_flag == 1)
        {
            AC_Out3 = 0;
        }

         /* 2, 设置下一次Timer1中断触发所需时间，即脉冲时间       */
        TL1 = 0xF7;				
        TH1 = 0xFF;				
    }else
    {
        /* 3, 下一次进入Timer1中断，power_ch电平 由低电平变为高电平，完成一次10us脉冲，即斩波*/
        AC_Out1 = AC_Out2 = AC_Out3 = 1;

        /* 4, 定时器1停止计时，关闭TIM1中断，等待下一次外部中断     */
        TR1 = 0;				    
        ET1 = 0; 
    }
}

/**
 * @brief	24V cir开关控制函数
 *
 * @param   on_off：0：关闭 1：开启
 *
 * @return  void
**/
void DC_24V_out1( uint8_t on_off )
{
    if( on_off == 1 )
    {
        DC_24V_1 = 0;
        dc_24v.stir_run_cnt = dc_24v.stir_run_time * 100;
        dc_24v.stir_wait_cnt = dc_24v.stir_wait_time * 100;
        
    }else
    {
        DC_24V_1 = 1;
    }
}

/**
 * @brief	24V cir开关控制函数
 *
 * @param   on_off：0：关闭 1：开启
 *
 * @return  void
**/
void DC_24V_out2( uint8_t on_off )
{
    if( on_off == 1 )
    {
        DC_24V_2 = 1;
        dc_24v.cir_run_cnt = dc_24v.cir_run_time * 100;
        dc_24v.cir_wait_cnt = dc_24v.cir_wait_time * 100;
    }else
    {
        DC_24V_2 = 0;
    }
}