/********************************************************************************/
/*                            HEADER GUARD                                      */
/********************************************************************************/
#ifndef HANDLER_H_
#define HANDLER_H_

/********************************************************************************/
/*                                INCLUDES                                      */
/********************************************************************************/
#include "gpt_interface.h"

/********************************************************************************/
/*                           HandlerErrorStatus                                 */
/********************************************************************************/
typedef enum __timerHandlerErrorStatus_t
{
	TIMER_HANDLER_OK = 0,
	TIMER_HANDLER_ERROR
}enu_timerHandlerErrorStatus_t;	

/********************************************************************************/
/*                              PROTOTYPES                                      */
/********************************************************************************/

enu_timerHandlerErrorStatus_t timerHandlerInit(str_MTIMER_configurations_t *str_TIMER_configs);

enu_timerHandlerErrorStatus_t timerHandlerStartTimer(enu_MTIMER_timerSelect_t enu_arg_timerSelect ,uint32_t u32_arg_time , enu_timeUnit_t enu_arg_timeUnit);

enu_timerHandlerErrorStatus_t timerHandlerEnableInterrupt(enu_MTIMER_timerSelect_t enu_arg_timerSelect);

enu_timerHandlerErrorStatus_t timerHandlerDisableInterrupt(enu_MTIMER_timerSelect_t enu_arg_timerSelect);

enu_timerHandlerErrorStatus_t timerHandlerStopTimer(enu_MTIMER_timerSelect_t enu_arg_timerSelect);

enu_timerHandlerErrorStatus_t timerHandlergetElapsedTime   (enu_MTIMER_timerSelect_t enu_arg_timerSelect , uint32_t *u32_ptr_time);

enu_timerHandlerErrorStatus_t timerHandlerRemainingTime (enu_MTIMER_timerSelect_t enu_arg_timerSelect , uint32_t *u32_ptr_time);

enu_timerHandlerErrorStatus_t timerHandlerSetPwm(enu_MTIMER_timerSelect_t enu_arg_timerSelect , uint16_t u16_arg_durationMs ,uint8_t u8_arg_dutyCycle);

#endif /*HANDLER_H_*/
