#ifndef __LEVEL_CRL_H_
#define __LEVEL_CRL_H_

#include "sys.h"
#include "gpio.h"

typedef struct 
{
    uint8_t  level_info;
    uint8_t  level_scan_flag;
    uint8_t  level_alarm;
    uint8_t  level_alarm_flag;
    uint8_t  level1;
    uint8_t  level2;
    uint8_t  level3;
    uint8_t  level4;
    uint8_t  level5;
    uint8_t  level6;
    uint8_t  level7;
    uint8_t  level8;
    uint8_t  level9;
    uint8_t  level10;
    uint8_t  level1_alarm_flag;
    uint8_t  level2_alarm_flag;
    uint8_t  level3_alarm_flag;
    uint8_t  level4_alarm_flag;
    uint8_t  level5_alarm_flag;
    uint8_t  level6_alarm_flag;
    uint8_t  level7_alarm_flag;
    uint8_t  level8_alarm_flag;
    uint8_t  level9_alarm_flag;
    uint8_t  level10_alarm_flag;
    uint16_t level1_alarm_cnt;
    uint16_t level2_alarm_cnt;
    uint16_t level3_alarm_cnt;
    uint16_t level4_alarm_cnt;
    uint16_t level5_alarm_cnt;
    uint16_t level6_alarm_cnt;
    uint16_t level7_alarm_cnt;
    uint16_t level8_alarm_cnt;
    uint16_t level9_alarm_cnt;
    uint16_t level10_alarm_cnt;

}LEVEL;

extern LEVEL level;


#endif