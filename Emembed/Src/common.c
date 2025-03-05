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
        if( level.buzzer_scan_flag == 1 )
        {
            if((level.level1 != 0x04) || (level.level2 != 0x04) || (level.level3 != 0x04) ||    \
            (level.level4 != 0x04) || (level.level5 != 0x04) || (level.level6 != 0x04) ||    \
            (level.level7 != 0x04) || (level.level8 != 0x04) || (level.level9 != 0x04) ||    \
            (level.level10 != 0x04))
            {
                buzzer = 1;
            }
            if((level.level1 == 0x04) || (level.level2 == 0x04) || (level.level3 == 0x04) ||    \
            (level.level4 == 0x04) || (level.level5 == 0x04) || (level.level6 == 0x04) ||    \
            (level.level7 == 0x04) || (level.level8 == 0x04) || (level.level9 == 0x04) ||    \
            (level.level10 == 0x04))
            {
                buzzer = 0;
            }
        }

        /*          level 1         */
        if(( L1_L == 1 )&&( L1_H == 1 ))
        {
            level.level1 = 0x03;
            level.level1_alarm_flag = 0;
            level.level1_alarm_cnt = 0;
    
        }else if(( L1_L == 1 )&&( L1_H == 0 ))
        {
            level.level1 = 0x02;
            level.level1_alarm_flag = 0;
            level.level1_alarm_cnt = 0;
        }else if(( L1_L == 0 )&&( L1_H == 0 )&&(level.level1_alarm_flag == 0))
        {
            level.level1 = 0x01;
            level.level1_alarm_flag = 1;
            level.level1_alarm_cnt = level.level_info * 100;
        }
        /*          level 2         */
        if(( L2_L == 1 )&&( L2_H == 1 ))
        {
            level.level2 = 0x03;
            level.level2_alarm_flag = 0;
            level.level2_alarm_cnt = 0;
    
        }else if(( L2_L == 1 )&&( L2_H == 0 ))
        {
            level.level2 = 0x02;
            level.level2_alarm_flag = 0;
            level.level2_alarm_cnt = 0;
        }else if(( L2_L == 0 )&&( L2_H == 0 )&&(level.level2_alarm_flag == 0))
        {
            level.level2 = 0x01;
            level.level2_alarm_flag = 1;
            level.level2_alarm_cnt = level.level_info * 100;
        }

        /*          level 3         */
        if(( L3_L == 1 )&&( L3_H == 1 ))
        {
            level.level3 = 0x03;
            level.level3_alarm_flag = 0;
            level.level3_alarm_cnt = 0;
    
        }else if(( L3_L == 1 )&&( L3_H == 0 ))
        {
            level.level3 = 0x02;
            level.level3_alarm_flag = 0;
            level.level3_alarm_cnt = 0;
        }else if(( L3_L == 0 )&&( L3_H == 0 )&&(level.level3_alarm_flag == 0))
        {
            level.level3 = 0x01;
            level.level3_alarm_flag = 1;
            level.level3_alarm_cnt = level.level_info * 100;
        }

        /*          level 4         */
        if(( L4_L == 1 )&&( L4_H == 1 ))
        {
            level.level4 = 0x03;
            level.level4_alarm_flag = 0;
            level.level4_alarm_cnt = 0;
    
        }else if(( L4_L == 1 )&&( L4_H == 0 ))
        {
            level.level4 = 0x02;
            level.level4_alarm_flag = 0;
            level.level4_alarm_cnt = 0;
        }else if(( L4_L == 0 )&&( L4_H == 0 )&&(level.level4_alarm_flag == 0))
        {
            level.level4 = 0x01;
            level.level4_alarm_flag = 1;
            level.level4_alarm_cnt = level.level_info * 100;
        }

        /*          level 5         */
        if(( L5_L == 1 )&&( L5_H == 1 ))
        {
            level.level5 = 0x03;
            level.level5_alarm_flag = 0;
            level.level5_alarm_cnt = 0;
    
        }else if(( L5_L == 1 )&&( L5_H == 0 ))
        {
            level.level5 = 0x02;
            level.level5_alarm_flag = 0;
            level.level5_alarm_cnt = 0;
        }else if(( L5_L == 0 )&&( L5_H == 0 )&&(level.level5_alarm_flag == 0))
        {
            level.level5 = 0x01;
            level.level5_alarm_flag = 1;
            level.level5_alarm_cnt = level.level_info * 100;
        }

        /*          level 6         */
        if(( L6_L == 1 )&&( L6_H == 1 ))
        {
            level.level6 = 0x03;
            level.level6_alarm_flag = 0;
            level.level6_alarm_cnt = 0;
    
        }else if(( L6_L == 1 )&&( L6_H == 0 ))
        {
            level.level6 = 0x02;
            level.level6_alarm_flag = 0;
            level.level6_alarm_cnt = 0;
        }else if(( L6_L == 0 )&&( L6_H == 0 )&&(level.level6_alarm_flag == 0))
        {
            level.level6 = 0x01;
            level.level6_alarm_flag = 1;
            level.level6_alarm_cnt = level.level_info * 100;
        }

        /*          level 7         */
        if(( L7_L == 1 )&&( L7_H == 1 ))
        {
            level.level7 = 0x03;
            level.level7_alarm_flag = 0;
            level.level7_alarm_cnt = 0;
    
        }else if(( L7_L == 1 )&&( L7_H == 0 ))
        {
            level.level7 = 0x02;
            level.level7_alarm_flag = 0;
            level.level7_alarm_cnt = 0;
        }else if(( L7_L == 0 )&&( L7_H == 0 )&&(level.level7_alarm_flag == 0))
        {
            level.level7 = 0x01;
            level.level7_alarm_flag = 1;
            level.level7_alarm_cnt = level.level_info * 100;
        }

        /*          level 8         */
        if(( L8_L == 1 )&&( L8_H == 1 ))
        {
            level.level8 = 0x03;
            level.level8_alarm_flag = 0;
            level.level8_alarm_cnt = 0;
    
        }else if(( L8_L == 1 )&&( L8_H == 0 ))
        {
            level.level8 = 0x02;
            level.level8_alarm_flag = 0;
            level.level8_alarm_cnt = 0;
        }else if(( L8_L == 0 )&&( L8_H == 0 )&&(level.level8_alarm_flag == 0))
        {
            level.level8 = 0x01;
            level.level8_alarm_flag = 1;
            level.level8_alarm_cnt = level.level_info * 100;
        }

        /*          level 9         */
        if(( L9_L == 1 )&&( L9_H == 1 ))
        {
            level.level9 = 0x03;
            level.level9_alarm_flag = 0;
            level.level9_alarm_cnt = 0;
    
        }else if(( L9_L == 1 )&&( L9_H == 0 ))
        {
            level.level9 = 0x02;
            level.level9_alarm_flag = 0;
            level.level9_alarm_cnt = 0;
        }else if(( L9_L == 0 )&&( L9_H == 0 )&&(level.level9_alarm_flag == 0))
        {
            level.level9 = 0x01;
            level.level9_alarm_flag = 1;
            level.level9_alarm_cnt = level.level_info * 100;
        }

        /*          level 10         */
        if(( L10_L == 1 )&&( L10_H == 1 )&&(level.level10_alarm_flag == 0))
        {
            level.level10 = 0x03;
            level.level10_alarm_flag = 1;
            level.level10_alarm_cnt = level.level_info * 100;
    
        }else if(( L10_L == 1 )&&( L10_H == 0 ))
        {
            level.level10 = 0x02;
            level.level10_alarm_flag = 0;
            level.level10_alarm_cnt = 0;
        }else if(( L10_L == 0 )&&( L10_H == 0 ))
        {
            level.level10 = 0x01;
            level.level10_alarm_flag = 0;
            level.level10_alarm_cnt = 0;
        }
        wk06_statu_send();
        level.level_scan_flag = 0;
    } 
}
void Tim3_ISR( void ) interrupt 19   //10ms
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
    /*          level 1         */
    if(( level.level1_alarm_flag == 1 )&&(level.level1_alarm_cnt != 0 ))
    {
        level.level1_alarm_cnt--;
        if( level.level1_alarm_cnt == 0 )
        {
            level.level1 = 0x04;
            // buzzer = 0;
        }
    }
    /*          level 2         */
    if(( level.level2_alarm_flag == 1 )&&(level.level2_alarm_cnt != 0 ))
    {
        level.level2_alarm_cnt--;
        if( level.level2_alarm_cnt == 0 )
        {
            level.level2 = 0x04;
            // buzzer = 0;
        }
    }

    /*          level 3         */
    if(( level.level3_alarm_flag == 1 )&&(level.level3_alarm_cnt != 0 ))
    {
        level.level3_alarm_cnt--;
        if( level.level3_alarm_cnt == 0 )
        {
            level.level3 = 0x04;
            // buzzer = 0;
        }
    }
    /*          level 4         */
    if(( level.level4_alarm_flag == 1 )&&(level.level4_alarm_cnt != 0 ))
    {
        level.level4_alarm_cnt--;
        if( level.level4_alarm_cnt == 0 )
        {
            level.level4 = 0x04;
            // buzzer = 0;
        }
    }

    /*          level 5         */
    if(( level.level5_alarm_flag == 1 )&&(level.level5_alarm_cnt != 0 ))
    {
        level.level5_alarm_cnt--;
        if( level.level5_alarm_cnt == 0 )
        {
            level.level5 = 0x04;
            // buzzer = 0;
        }
    }
    /*          level 6         */
    if(( level.level6_alarm_flag == 1 )&&(level.level6_alarm_cnt != 0 ))
    {
        level.level6_alarm_cnt--;
        if( level.level6_alarm_cnt == 0 )
        {
            level.level6 = 0x04;
            // buzzer = 0;
        }
    }

    /*          level 7         */
    if(( level.level7_alarm_flag == 1 )&&(level.level7_alarm_cnt != 0 ))
    {
        level.level7_alarm_cnt--;
        if( level.level7_alarm_cnt == 0 )
        {
            level.level7 = 0x04;
            // buzzer = 0;
        }
    }
    /*          level 8         */
    if(( level.level8_alarm_flag == 1 )&&(level.level8_alarm_cnt != 0 ))
    {
        level.level8_alarm_cnt--;
        if( level.level8_alarm_cnt == 0 )
        {
            level.level8 = 0x04;
            // buzzer = 0;
        }
    }

    /*          level 9         */
    if(( level.level9_alarm_flag == 1 )&&(level.level9_alarm_cnt != 0 ))
    {
        level.level9_alarm_cnt--;
        if( level.level9_alarm_cnt == 0 )
        {
            level.level9 = 0x04;
            // buzzer = 0;
        }
    }
    /*          level 10         */
    if(( level.level10_alarm_flag == 1 )&&(level.level10_alarm_cnt != 0 ))
    {
        level.level10_alarm_cnt--;
        if( level.level10_alarm_cnt == 0 )
        {
            level.level10 = 0x04;
            // buzzer = 0;
        }
    }

    if( dc_24v.stir == 1 )
    {
        if(( DC_24V_1 == 0 )&&( dc_24v.stir_run_cnt != 0 ))
        {
            dc_24v.stir_run_cnt--;
            dc_24v.stir_wait_cnt = dc_24v.stir_wait_time * 100;
        }
        
        if( dc_24v.stir_run_cnt == 0 )
        {
            DC_24V_1 = 1;
            dc_24v.stir_wait_cnt--;
            if( dc_24v.stir_wait_cnt == 0 )
            {
                DC_24V_1 = 0;
                dc_24v.stir_run_cnt = dc_24v.stir_run_time * 100;
            }
        }
    }

    if( dc_24v.cir == 1 )
    {
        if(( DC_24V_2 == 1 )&&( dc_24v.cir_run_cnt != 0 ))
        {
            dc_24v.cir_run_cnt--;
            dc_24v.cir_wait_cnt = dc_24v.cir_wait_time * 100;
        }
        
        if( dc_24v.cir_run_cnt == 0 )
        {
            DC_24V_2 = 0;
            dc_24v.cir_wait_cnt--;
            if( dc_24v.cir_wait_cnt == 0 )
            {
                DC_24V_2 = 1;
                dc_24v.cir_run_cnt = dc_24v.cir_run_time * 100;
            }
        }
    }
}
