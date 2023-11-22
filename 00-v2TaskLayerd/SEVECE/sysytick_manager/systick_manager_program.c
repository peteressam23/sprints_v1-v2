/********************************************************************************/
/*                                   INCLUDES                                   */
/********************************************************************************/
#include "systick_manager_interface.h"

/********************************************************************************/
/*                                   Implementation                             */
/********************************************************************************/

enu_SysTickManager_Error_t SysTickManager_Init(uint32_t reload_value, enu_SysTick_ClockSource_t clk_source)
{
	SysTick_Init(reload_value, clk_source);
}

/*************************************************************************************/

enu_SysTickManager_Error_t SysTickManager_Start(void)
{
	 SysTick_Start();
}

/*************************************************************************************/
enu_SysTickManager_Error_t SysTickManager_Stop(void)
{
	SysTick_Stop();
}

/*************************************************************************************/

enu_SysTickManager_Error_t SysTickManager_DelayMs(uint32_t delay_ms)
{
	SysTick_DelayMs(delay_ms);
}

/***************************************************************************************/
enu_SysTickManager_Error_t SysTickManager_DelayUs(uint32_t delay_us)
{
    SysTick_DelayUs(delay_us);
    
}

/***************************************************************************************/
uint8_t SysTickManager_CheckTimeOut(void) 
{
    SysTick_CheckTimeOut();
}