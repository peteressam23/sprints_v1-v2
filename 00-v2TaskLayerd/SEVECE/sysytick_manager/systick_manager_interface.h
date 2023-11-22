/********************************************************************************/
/*                              HEADER GUARD                                    */
/********************************************************************************/
#ifndef SYSTICK_MANAGER_INTERFACE_H
#define SYSTICK_MANAGER_INTERFACE_H

/********************************************************************************/
/*                                   INCLUDES                                   */
/********************************************************************************/
#include <stdint.h>
#include "systick_interface.h"

/********************************************************************************/
/*                             SYSTICK CLOCK SOURCE ENUM                        */
/********************************************************************************/



/********************************************************************************/
/*                             SYSTICK ERROR STATE                              */
/********************************************************************************/
typedef enum {
    SYSTICK_MANAGER_OK = 0,
    SYSTICK_MANAGER_ERROR_INVALID_SOURCE,
    SYSTICK_MANAGER_ERROR_INVALID_OPERATION,
} enu_SysTickManager_Error_t;




/********************************************************************************/
/*                            FUNCTION PROTOTYPES                               */
/********************************************************************************/

/**
 * @brief      Initialize the SysTick timer.
 * @param      reload_value   The value to load into the SysTick Load register.
 * @param      clk_source     The clock source for the SysTick timer.
 * @return     enu_SysTickManager_Error_t   Error status.
 */
enu_SysTickManager_Error_t SysTickManager_Init(uint32_t reload_value, enu_SysTick_ClockSource_t clk_source);


/**
 * @brief      Start the SysTick timer.
 * @return     enu_SysTickManager_Error_t   Error status.
 */
enu_SysTickManager_Error_t SysTickManager_Start(void);


/**
 * @brief      Stop the SysTick timer.
 * @return     enu_SysTickManager_Error_t   Error status.
 */
enu_SysTickManager_Error_t SysTickManager_Stop(void);


/**
 * @brief      Check if the SysTick timer has counted down to zero.
 * @return     1 if the timer has counted down to zero, 0 otherwise.
 */
uint8_t SysTickManager_CheckTimeOut(void);


/**
 * @brief      Delay for a specified number of milliseconds using the SysTick timer.
 * @param      delay_ms   The number of milliseconds to delay.
 * @return     enu_SysTickManager_Error_t   Error status.
 */
enu_SysTickManager_Error_t SysTickManager_DelayMs(uint32_t delay_ms);


/**
 * @brief      Delay for a specified number of microseconds using the SysTick timer.
 * @param      delay_us   The number of microseconds to delay.
 * @return     enu_SysTickManager_Error_t   Error status.
 */
enu_SysTickManager_Error_t SysTickManager_DelayUs(uint32_t delay_us);


#endif /* SYSTICK_MANAGER_INTERFACE_H */