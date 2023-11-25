/********************************************************************************/
/*                              INCLUDES                                        */
/********************************************************************************/
#include "TM4C123.h"
#include "gpt_private.h"
#include "gpt_interface.h"

/********************************************************************************/
/*                              GLOBAL POINTER TO FUNCTION                               */
/********************************************************************************/
static ptrf_callBack_t  ptrf_gs_array[M_INVALID_TIMER_SELECT] = {NULL};

/********************************************************************************/
/*                              GLOBAL VARIABLES                                */
/********************************************************************************/
static boolean          bool_gs_timerInit[M_INVALID_TIMER_SELECT] = {FALSE};
static uint16_t         u16_gs_highPeriod 			 = FALSE;
static uint16_t         u16_gs_lowPeriod   			 = FALSE;
static boolean          bool_gs_isHighPeriod     = FALSE; 

/********************************************************************************/
/*                              IMPLEMETATION                                   */
/********************************************************************************/
enu_MTIMER_status_t M_timerInit(str_MTIMER_configurations_t *ptr_timerConfigurations)
{
	/*make variable to store error state*/
	enu_MTIMER_status_t  enu_MTIMER_status = MTIMER_OKAY;
	enu_MTIMER_timerSelect_t   enu_loc_selectedTimer = ptr_timerConfigurations->enu_timerSelect;
	if(ptr_timerConfigurations == NULL)
	{
		enu_MTIMER_status = MTIMER_NULL_REF_CB_ERROR;
	}
	else
	{
		/*check on selected timer*/
		if(enu_loc_selectedTimer < M_INVALID_TIMER_SELECT)
		{
			/*check if selected timer initilized before or not*/
			if(bool_gs_timerInit[enu_loc_selectedTimer] == FALSE)
			{
				if(enu_loc_selectedTimer < M_WIDE_TIMER0_SELECT)
				{
					/*Casenot wide timer*/
					SET_BIT(RCGCTIMER , enu_loc_selectedTimer);
				}
				else 
				{
					/*Case wide timer subtract offset 6 to make the bits from 0 to 5*/
					SET_BIT(RCGCWTIMER,(enu_loc_selectedTimer - M_WIDE_TIMER0_SELECT));
				}
        CLEAR_BIT(GPTMCTL(enu_loc_selectedTimer),GPTMCTL_TAEN);
        /* check mode range	*/
        if(ptr_timerConfigurations->enu_timerMode < MTIMER_INVALID_MODE)
				{
					if(ptr_timerConfigurations->enu_timerMode < MTIMER_RTC_MODE)
					{	
						if(ptr_timerConfigurations->enu_timerType == MTIMER_INDIVIDUAL_TYPE)
						{
							GPTMCFG(enu_loc_selectedTimer) = GPTMCFG_SINGLE; 
						}
						else if (ptr_timerConfigurations->enu_timerType == MTIMER_CONCATENATED_TYPE)
						{
							GPTMCFG(enu_loc_selectedTimer) = GPTMCFG_DOUBLE; 
						}
						else
						{
							enu_MTIMER_status = MTIMER_TYPE_SELECT_ERROR;
						}
						/*check cases pass*/
						 if(enu_MTIMER_status == MTIMER_OKAY)
						 {
							 if(ptr_timerConfigurations->enu_timerMode == MTIMER_ONE_SHOT_MODE)
							 {
								 GPTMTAMR(enu_loc_selectedTimer) = ONE_SHOT_VALUE;
							 }
							 else if(ptr_timerConfigurations->enu_timerMode == MTIMER_PERIODIC_MODE) 
							 {
								 GPTMTAMR(enu_loc_selectedTimer) = PERIODIC_VALUE;
							 }
							 else
							 {

							 }
               if (ptr_timerConfigurations->bool_interruptuOk == TRUE)
							 {
								 if(ptr_timerConfigurations->ptrf_callBack == NULL)
								 {
									 enu_MTIMER_status = MTIMER_NULL_REF_CB_ERROR;
								 }
								 else
								 {
								   CLEAR_BIT(GPTMIMR(enu_loc_selectedTimer),GPTMIMR_TATOIM);
									 ptrf_gs_array[enu_loc_selectedTimer] = ptr_timerConfigurations->ptrf_callBack;
								 }
							 }
               else
							 {
								 
							 }
               bool_gs_timerInit[enu_loc_selectedTimer] = TRUE;							 
						 }
						 else
						 {

						 }
					}
					else if(ptr_timerConfigurations->enu_timerMode == MTIMER_RTC_MODE)
					{
						
					}
					else if(ptr_timerConfigurations->enu_timerMode == MTIMER_INPUT_EDGE_COUNT_MODE)
					{
		
					}
					else if(ptr_timerConfigurations->enu_timerMode == MTIMER_INPUT_EDGE_TIME_MODE)
					{
	
					}
					else if(ptr_timerConfigurations->enu_timerMode == MTIMER_PWM_MODE)
					{
	
					}
					else
					{

					}
				}	
        else
				{
					enu_MTIMER_status = MTIMER_MODE_SELECT_ERROR;
				}					
			}
			else
			{
				enu_MTIMER_status = MTIMER_INVALID_OPERATION_ERROR;
			}
		}
		else
		{
			enu_MTIMER_status = MTIMER_SELECT_ERROR;
		}
	}
	
	return enu_MTIMER_status;
}


/*********************************************************************************************************/

enu_MTIMER_status_t M_timerStart(enu_MTIMER_timerSelect_t enu_arg_timerSelect , uint32_t u32_arg_desiredTime , enu_timeUnit_t enu_arg_timeUnit)
{
	/*make variable to store error state*/
	enu_MTIMER_status_t  enu_MTIMER_status = MTIMER_OKAY;
	
  double f64_tick_time   = ONE_F/CLK_FREQUENCY;
  double f64_total_ticks = ZERO_F;	
	
	/*check on selected timer*/
	if(enu_arg_timerSelect < M_INVALID_TIMER_SELECT)
	{
		/*check if timer is initialized or not*/
		if(bool_gs_timerInit[enu_arg_timerSelect] == TRUE)
		{
			if(enu_arg_timeUnit < TIME_UNIT_INVALID)
			{
				if(enu_arg_timeUnit == TIME_IN_MICROSECONDS)
				{
					f64_total_ticks = ((u32_arg_desiredTime/CONVERT_TO_MICRO)/(f64_tick_time));
				}
				else if(enu_arg_timeUnit == TIME_IN_MILLIOSECONDS)
				{
					f64_total_ticks = ((u32_arg_desiredTime/CONVERT_TO_MILLI)/(f64_tick_time));
				}
				else 
				{
					f64_total_ticks = ((u32_arg_desiredTime/ONE_F)/(f64_tick_time));
				}
				GPTMTAILR(enu_arg_timerSelect) = f64_total_ticks;
				SET_BIT(GPTMCTL(enu_arg_timerSelect),GPTMCTL_TAEN);
				/*interrupt case*/
				if(GET_BIT(GPTMIMR(enu_arg_timerSelect),GPTMIMR_TATOIM) == TRUE)
				{
				}
				else
				{
					while (GET_BIT(GPTMRIS(enu_arg_timerSelect),GPTMRIS_TATORIS) != TRUE);
					SET_BIT(GPTMICR(enu_arg_timerSelect),GPTMICR_TATOCINT);
					M_stopTimer(enu_arg_timerSelect);
				}
			}
			else
			{
				enu_MTIMER_status= MTIMER_INVALID_UNIT_ERROR;
			}
		}
		else
		{
			enu_MTIMER_status = MTIMER_INVALID_OPERATION_ERROR;
		}
	}
	else
	{
		enu_MTIMER_status = MTIMER_SELECT_ERROR;
	}
	return enu_MTIMER_status;
}

/*********************************************************************************************************/

enu_MTIMER_status_t M_timerEnableInterrupt(enu_MTIMER_timerSelect_t enu_arg_timerSelect)
{
	/*make variable to store error state*/
	enu_MTIMER_status_t  enu_MTIMER_status = MTIMER_OKAY;
	/*check selected timer */
	if(enu_arg_timerSelect < M_INVALID_TIMER_SELECT)
	{
    if(GET_BIT(GPTMIMR(enu_arg_timerSelect),GPTMIMR_TATOIM) == TRUE)
		{
			enu_MTIMER_status = MTIMER_INVALID_OPERATION_ERROR;
		}
		else
		{
			SET_BIT(GPTMIMR(enu_arg_timerSelect),GPTMIMR_TATOIM);
			if(enu_arg_timerSelect == M_TIMER0_SELECT)
			{
				NVIC_EnableIRQ(TIMER0A_IRQn);
			}
			else if(enu_arg_timerSelect == M_WIDE_TIMER0_SELECT)
			{
				NVIC_EnableIRQ(WTIMER0A_IRQn);
			}
			else
			{
			}
			__enable_irq();
		}
	}
	else
	{
		enu_MTIMER_status = MTIMER_SELECT_ERROR;
	}
	return enu_MTIMER_status;
}

/**********************************************************************************************/

enu_MTIMER_status_t M_timerDisableInterrupt(enu_MTIMER_timerSelect_t enu_arg_timerSelect)
{
	/*make variable to store error state*/
	enu_MTIMER_status_t  enu_MTIMER_status = MTIMER_OKAY;
	/*check selected timer */
	if(enu_arg_timerSelect < M_INVALID_TIMER_SELECT)
	{
    if(GET_BIT(GPTMIMR(enu_arg_timerSelect) , GPTMIMR_TATOIM) != TRUE)
		{
			enu_MTIMER_status = MTIMER_INVALID_OPERATION_ERROR;
		}
		else
		{
			CLEAR_BIT(GPTMIMR(enu_arg_timerSelect),GPTMIMR_TATOIM);
			if(enu_arg_timerSelect == M_TIMER0_SELECT)
			{
				NVIC_DisableIRQ(TIMER0A_IRQn);
			}
			else if(enu_arg_timerSelect == M_WIDE_TIMER0_SELECT)
			{
				NVIC_DisableIRQ(WTIMER0A_IRQn);
			}
			else
			{

			}
		}
	}
	else
	{
		enu_MTIMER_status = MTIMER_SELECT_ERROR;
	}
	return enu_MTIMER_status;
}


/****************************************************************************************************************************/

enu_MTIMER_status_t M_Timer_getElapsedTime(enu_MTIMER_timerSelect_t enu_arg_timerSelect , uint32_t *u32_ptr_timeMs)
{
	/*make variable to store error state*/
	enu_MTIMER_status_t  enu_MTIMER_status = MTIMER_OKAY;
	/*check selected timer */
	if(enu_arg_timerSelect < M_INVALID_TIMER_SELECT)
	{
		*u32_ptr_timeMs = (GPTMTAILR(enu_arg_timerSelect) - GPTMTAR(enu_arg_timerSelect))/(CLK_FREQUENCY * CONVERT_TO_MILLI);
	}
	else
	{
		enu_MTIMER_status = MTIMER_SELECT_ERROR;
	}
		
	return enu_MTIMER_status;
}

/****************************************************************************************************************************/

enu_MTIMER_status_t M_TIMER_getRemainingTime (enu_MTIMER_timerSelect_t enu_arg_timerSelect , uint32_t *u32_ptr_timeMs)
{
	/*make variable to store error state*/
	enu_MTIMER_status_t  enu_MTIMER_status = MTIMER_OKAY;
	/*check selected timer */
	if(enu_arg_timerSelect < M_INVALID_TIMER_SELECT)
	{
		*u32_ptr_timeMs = GPTMTAR(enu_arg_timerSelect) / (CLK_FREQUENCY * CONVERT_TO_MILLI);
	}
	else
	{
		enu_MTIMER_status = MTIMER_SELECT_ERROR;
	}
	return enu_MTIMER_status;
}

/****************************************************************************************************************************/


enu_MTIMER_status_t M_stopTimer(enu_MTIMER_timerSelect_t enu_arg_timerSelect)
{
	/*make variable to store error state*/
	enu_MTIMER_status_t  enu_MTIMER_status = MTIMER_OKAY;
	/*check selected timer */
	if(enu_arg_timerSelect < M_INVALID_TIMER_SELECT)
	{
	  CLEAR_BIT(GPTMCTL(enu_arg_timerSelect),GPTMCTL_TAEN);
	}
	else
	{
		enu_MTIMER_status = MTIMER_SELECT_ERROR;
	}
	return enu_MTIMER_status;
}

/****************************************************************************************************************************/

enu_MTIMER_status_t M_TIMER_set_pwm(enu_MTIMER_timerSelect_t enu_arg_timerSelect , uint16_t u16_arg_durationMs , uint8_t u8_arg_dutyCycle)
{
	/*make variable to store error state*/
	enu_MTIMER_status_t  enu_MTIMER_status = MTIMER_OKAY;
	/*check selected timer */
	if(enu_arg_timerSelect < M_INVALID_TIMER_SELECT)
	{
    if((GET_BIT(GPTMIMR(enu_arg_timerSelect),GPTMIMR_TATOIM) != TRUE) || (bool_gs_timerInit[enu_arg_timerSelect] != TRUE))
		{
			enu_MTIMER_status = MTIMER_INVALID_OPERATION_ERROR;
		}
		else
		{
			  bool_gs_isHighPeriod = FALSE;
				u16_gs_highPeriod = (u16_arg_durationMs * u8_arg_dutyCycle)/100;
				u16_gs_lowPeriod  = u16_arg_durationMs - u16_gs_highPeriod;
			  M_timerStart(enu_arg_timerSelect , u16_gs_lowPeriod , TIME_IN_MILLIOSECONDS);
		}
	}
	else
	{
		enu_MTIMER_status = MTIMER_SELECT_ERROR;
	}
	return enu_MTIMER_status;
}

/****************************************************************************************************************************/

void TIMER0A_Handler(void)
{
	if(ptrf_gs_array[M_TIMER0_SELECT] != NULL)
	{
		CLEAR_BIT(GPTMCTL(M_TIMER0_SELECT),GPTMCTL_TAEN);
		ptrf_gs_array[M_TIMER0_SELECT]();
	}
	else
	{
	}
}

/****************************************************************************************************************************/

void WTIMER0A_Handler(void)
{
	if(ptrf_gs_array[M_WIDE_TIMER0_SELECT] != NULL)
	{
		ptrf_gs_array[M_WIDE_TIMER0_SELECT]();
		SET_BIT(GPTMICR(M_WIDE_TIMER0_SELECT),GPTMICR_TATOCINT);
		M_stopTimer(M_WIDE_TIMER0_SELECT);
		if(bool_gs_isHighPeriod == TRUE)
		{
			M_timerStart(M_WIDE_TIMER0_SELECT , u16_gs_lowPeriod , TIME_IN_MILLIOSECONDS);
			bool_gs_isHighPeriod = FALSE;
		}
		else
		{
			M_timerStart(M_WIDE_TIMER0_SELECT , u16_gs_highPeriod , TIME_IN_MILLIOSECONDS);
			bool_gs_isHighPeriod = TRUE;
		}
	}
	else
	{

	}
}
