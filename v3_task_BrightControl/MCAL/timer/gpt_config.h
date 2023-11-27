/********************************************************************************/
/*                              HEADER GUARD                                    */
/********************************************************************************/
#ifndef GPT_CONFIH_H_
#define GPT_CONFIH_H_

/********************************************************************************/
/*                                      SELECT TIMER                            */
/********************************************************************************/
typedef enum __MTIMER_timerSelect_t
{
	M_TIMER0_SELECT         = 0,
  M_TIMER1_SELECT            ,
  M_TIMER2_SELECT            ,
  M_TIMER3_SELECT	           ,
	M_TIMER4_SELECT            ,
	M_TIMER5_SELECT            ,
	M_WIDE_TIMER0_SELECT       ,
	M_WIDE_TIMER1_SELECT       ,
	M_WIDE_TIMER2_SELECT       ,
	M_WIDE_TIMER3_SELECT       ,
	M_WIDE_TIMER4_SELECT       ,
	M_WIDE_TIMER5_SELECT       ,
	M_INVALID_TIMER_SELECT      
}enu_MTIMER_timerSelect_t;

/********************************************************************************/
/*                                      SELECT MODE                             */
/********************************************************************************/
typedef enum __MTIMER_mode_t
{
	MTIMER_ONE_SHOT_MODE         = 0,
  MTIMER_PERIODIC_MODE            ,
  MTIMER_RTC_MODE                 ,
  MTIMER_INPUT_EDGE_COUNT_MODE	   ,
	MTIMER_INPUT_EDGE_TIME_MODE	   ,
	MTIMER_PWM_MODE                 ,
	MTIMER_INVALID_MODE
}enu_MTIMER_mode_t;

/********************************************************************************/
/*                                       SELECT TYPE                            */
/********************************************************************************/
typedef enum __MTIMER_type_t
{
	MTIMER_INDIVIDUAL_TYPE         = 0,
  MTIMER_CONCATENATED_TYPE          ,
	MTIMER_INVALID_TYPE
}enu_MTIMER_type_t;



#endif
