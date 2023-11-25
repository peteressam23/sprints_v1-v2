/********************************************************************************/
/*                                INCLUDES                                      */
/********************************************************************************/
#include "app.h"

/********************************************************************************/
/*                               CONFIGURE STRUCT                               */
/********************************************************************************/
str_MTIMER_configurations_t str_gl_pwmConfiguration =
{
	.enu_timerSelect     = M_WIDE_TIMER0_SELECT,
	.enu_timerMode       = MTIMER_ONE_SHOT_MODE,
	.enu_timerType       = MTIMER_INDIVIDUAL_TYPE,
	.bool_interruptuOk   = TRUE,
	.ptrf_callBack       = appMainFunByPwm
};

str_MTIMER_configurations_t str_gl_timerDelay =
{
	.enu_timerSelect       = M_TIMER0_SELECT,
	.enu_timerMode         = MTIMER_ONE_SHOT_MODE,
	.enu_timerType         = MTIMER_INDIVIDUAL_TYPE,
	.bool_interruptuOk     = FALSE,
};

/********************************************************************************/
/*                               GL VAR TO STORE STATE                          */
/********************************************************************************/
uint8_t u8_gl_appState  = FALSE;
boolean u8_gl_lockState = FALSE;


/********************************************************************************/
/*                               IMPLEMENTATION                                 */
/********************************************************************************/

void appMainFunByPwm(void)
{
	H_LED_toggle(PORT_GREEN_LED , PIN_GREEN_LED);
}


void appInit(void)
{
	(void)H_LED_init(PORT_GREEN_LED , PIN_GREEN_LED);
	(void)H_BUTTON_init();
	(void)timerHandlerInit(&str_gl_pwmConfiguration);
	(void)timerHandlerInit(&str_gl_timerDelay);
	(void)timerHandlerEnableInterrupt(M_WIDE_TIMER0_SELECT);
}

void appStart(void)
{
	boolean value = TRUE;
	while(1)
	{
		(void)H_BUTTON_read(BUTTON_0 , &value);
		if(value == FALSE)
		{
			while(value == FALSE)
			{
				(void)H_BUTTON_read(BUTTON_0,&value);
			}
			
			timerHandlerStartTimer(M_TIMER0_SELECT , DELAY , TIME_IN_MILLIOSECONDS);
			u8_gl_lockState = TRUE;
			u8_gl_appState++;
		}
		else
		{
			if(u8_gl_appState == APP_FIRST_STATE)
			{

			}
			else if(u8_gl_appState == APP_SECOND_STATE)
			{
				if(u8_gl_lockState == TRUE)
				{
					H_LED_off(PORT_GREEN_LED , PIN_GREEN_LED);
					timerHandlerSetPwm(M_WIDE_TIMER0_SELECT , SIGNAL_DURATION_MS , DUTY_CYCLE_30);
					u8_gl_lockState = FALSE;
				}
			}
			else if(u8_gl_appState == APP_THIRD_STATE)
			{
				if(u8_gl_lockState == TRUE)
				{
					H_LED_off(PORT_GREEN_LED , PIN_GREEN_LED);
					timerHandlerSetPwm(M_WIDE_TIMER0_SELECT , SIGNAL_DURATION_MS , DUTY_CYCLE_60);
					u8_gl_lockState = FALSE;
				}
			}
			else if(u8_gl_appState == APP_FOURTH_STATE)
			{
				if(u8_gl_lockState == TRUE)
				{
					H_LED_off(PORT_GREEN_LED , PIN_GREEN_LED);
					timerHandlerSetPwm(M_WIDE_TIMER0_SELECT , SIGNAL_DURATION_MS , DUTY_CYCLE_90);
					u8_gl_lockState = FALSE;
				}
			}
			else
			{
				timerHandlerStopTimer(M_WIDE_TIMER0_SELECT);
			  H_LED_off(PORT_GREEN_LED , PIN_GREEN_LED);
				u8_gl_appState = APP_FIRST_STATE;
			}
		}
	}
}

