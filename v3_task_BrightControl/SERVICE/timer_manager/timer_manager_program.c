/********************************************************************************/
/*                                INCLUDES                                      */
/********************************************************************************/
#include "timer_manager_interface.h"


/********************************************************************************/
/*                              IMPLEMENTATION                                  */
/********************************************************************************/
enu_timerHandlerErrorStatus_t timerHandlerInit(str_MTIMER_configurations_t *str_TIMER_configs)
{
	enu_timerHandlerErrorStatus_t enu_timerHandlerErrorStatus = TIMER_HANDLER_OK;
	enu_MTIMER_status_t enu_MTIMER_status = MTIMER_OKAY;
	enu_MTIMER_status = M_timerInit(str_TIMER_configs);
	if(enu_MTIMER_status != MTIMER_OKAY)
	{
		enu_timerHandlerErrorStatus = TIMER_HANDLER_ERROR;
	}
	else
	{

	}
	return enu_timerHandlerErrorStatus;
}

/**************************************************************************************************************/

enu_timerHandlerErrorStatus_t timerHandlerStartTimer(enu_MTIMER_timerSelect_t enu_arg_timerSelect ,uint32_t u32_arg_time , enu_timeUnit_t enu_arg_timeUnit)
{
	enu_timerHandlerErrorStatus_t enu_timerHandlerErrorStatus = TIMER_HANDLER_OK;
	enu_MTIMER_status_t enu_MTIMER_status = MTIMER_OKAY;
	enu_MTIMER_status = timerHandlerStartTimer(enu_arg_timerSelect , u32_arg_time , enu_arg_timeUnit);
	if(enu_MTIMER_status != MTIMER_OKAY)
	{
		enu_timerHandlerErrorStatus = TIMER_HANDLER_ERROR;
	}
	else
	{

	}
	return enu_timerHandlerErrorStatus;
}

/**************************************************************************************************************/

enu_timerHandlerErrorStatus_t timerHandlerEnableInterrupt(enu_MTIMER_timerSelect_t enu_arg_timerSelect)
{
	enu_timerHandlerErrorStatus_t enu_timerHandlerErrorStatus = TIMER_HANDLER_OK;
	enu_MTIMER_status_t enu_MTIMER_status = MTIMER_OKAY;
	enu_MTIMER_status = M_timerEnableInterrupt(enu_arg_timerSelect);
	if(enu_MTIMER_status != MTIMER_OKAY)
	{
		enu_timerHandlerErrorStatus = TIMER_HANDLER_ERROR;
	}
	else
	{

	}
	return enu_timerHandlerErrorStatus;
}

/**************************************************************************************************************/

enu_timerHandlerErrorStatus_t timerHandlerDisableInterrupt(enu_MTIMER_timerSelect_t enu_arg_timerSelect)
{
	enu_timerHandlerErrorStatus_t enu_timerHandlerErrorStatus = TIMER_HANDLER_OK;
	enu_MTIMER_status_t enu_MTIMER_status = MTIMER_OKAY;
	enu_MTIMER_status = M_timerDisableInterrupt(enu_arg_timerSelect);
	if(enu_MTIMER_status != MTIMER_OKAY)
	{
		enu_timerHandlerErrorStatus = TIMER_HANDLER_ERROR;
	}
	else
	{

	}
	return enu_timerHandlerErrorStatus;
}
/**************************************************************************************************************/

enu_timerHandlerErrorStatus_t timerHandlergetElapsedTime   (enu_MTIMER_timerSelect_t enu_arg_timerSelect , uint32_t *u32_ptr_time)
{
	enu_timerHandlerErrorStatus_t enu_timerHandlerErrorStatus = TIMER_HANDLER_OK;
	enu_MTIMER_status_t enu_MTIMER_status = MTIMER_OKAY;
	enu_MTIMER_status = M_Timer_getElapsedTime(enu_arg_timerSelect , u32_ptr_time);
	if(enu_MTIMER_status != MTIMER_OKAY)
	{
		enu_timerHandlerErrorStatus = TIMER_HANDLER_ERROR;
	}
	else
	{

	}
	return enu_timerHandlerErrorStatus;
}

/**************************************************************************************************************/

enu_timerHandlerErrorStatus_t timerHandlerRemainingTime (enu_MTIMER_timerSelect_t enu_arg_timerSelect , uint32_t *u32_ptr_time)
{
	enu_timerHandlerErrorStatus_t enu_timerHandlerErrorStatus = TIMER_HANDLER_OK;
	enu_MTIMER_status_t enu_MTIMER_status = MTIMER_OKAY;
	enu_MTIMER_status = M_TIMER_getRemainingTime(enu_arg_timerSelect , u32_ptr_time);
	if(enu_MTIMER_status != MTIMER_OKAY)
	{
		enu_timerHandlerErrorStatus = TIMER_HANDLER_ERROR;
	}
	else
	{

	}
	return enu_timerHandlerErrorStatus;
}

/**************************************************************************************************************/

enu_timerHandlerErrorStatus_t timerHandlerStopTimer(enu_MTIMER_timerSelect_t enu_arg_timerSelect)
{
	enu_timerHandlerErrorStatus_t enu_timerHandlerErrorStatus = TIMER_HANDLER_OK;
	enu_MTIMER_status_t enu_MTIMER_status = MTIMER_OKAY;
	enu_MTIMER_status = M_stopTimer(enu_arg_timerSelect);
	if(enu_MTIMER_status != MTIMER_OKAY)
	{
		enu_timerHandlerErrorStatus = TIMER_HANDLER_ERROR;
	}
	else
	{

	}
	return enu_timerHandlerErrorStatus;
}


/**************************************************************************************************************/

enu_timerHandlerErrorStatus_t timerHandlerSetPwm(enu_MTIMER_timerSelect_t enu_arg_timerSelect , uint16_t u16_arg_durationMs ,uint8_t u8_arg_dutyCycle)
{
	enu_timerHandlerErrorStatus_t enu_timerHandlerErrorStatus = TIMER_HANDLER_OK;
	enu_MTIMER_status_t enu_MTIMER_status = MTIMER_OKAY;
	enu_MTIMER_status = M_TIMER_set_pwm(enu_arg_timerSelect , u16_arg_durationMs , u8_arg_dutyCycle);
	if(enu_MTIMER_status != MTIMER_OKAY)
	{
		enu_timerHandlerErrorStatus = TIMER_HANDLER_ERROR;
	}
	else
	{

	}
	return enu_timerHandlerErrorStatus;
}

/**************************************************************************************************************/















