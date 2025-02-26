#ifndef __EEPROM_CRL_H_
#define __EEPROM_CRL_H_

#include "eeprom.h"
#include "sys.h"
#include "power_crl.h"
#include "ntc.h"
#include "stdio.h"
#include "pwm_crl.h"
#include "level_crl.h"

#define PWM_ADDR_EEPROM       0x0000
#define LED_ADDR_EEPROM       0x0001
#define AC220_ADDR_EEPROM     0x0002
#define STIR                  0X0003
#define STIR_RUN              0X0004
#define STIR_WAIT             0X0005
#define CIR                   0X0006
#define CIR_RUN               0X0007
#define CIR_WAIT              0X0008
#define LEVEL_DELAY           0X0009
#define TEMP1_ALARM           0X000A
#define TEMP2_ALARM           0X000B
#define TEMP3_ALARM           0X000C

#define EEPROM_STATU_JUDGE    0X0020         

typedef struct 
{
    uint8_t  pwm_info;
    uint8_t  led_info; 
    uint8_t  stir_info;  
    uint8_t  cir_info;   
    uint8_t  stir_run_time;  
    uint8_t  stir_wait_time; 
    uint8_t  cir_run_time;  
    uint8_t  cir_wait_time; 
    uint8_t  level_delay_time;
    uint8_t  ac220_info;        
    uint8_t  temp_alarm_value1;        
    uint8_t  temp_alarm_value2;         
    uint8_t  temp_alarm_value3;       
}EEPROM_INFO;

extern EEPROM_INFO eeprom;

void eeprom_statu_judge( void );
void eeprom_data_record( void );
void eeprom_data_init( void );

#endif