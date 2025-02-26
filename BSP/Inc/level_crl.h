#ifndef __LEVEL_CRL_H_
#define __LEVEL_CRL_H_

#include "sys.h"
#include "gpio.h"

typedef struct 
{
    uint8_t  level_info;
    uint8_t  level_scan_flag;
    uint8_t  level1234;
    uint8_t  level5678;
    uint8_t  level9101112;
}LEVEL;

extern LEVEL level;


#endif