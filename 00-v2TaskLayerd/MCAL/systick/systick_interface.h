/********************************************************************************/
/*                              HEADER GUARD                                    */
/********************************************************************************/
#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H

/********************************************************************************/
/*                                   INCLUDES                                   */
/********************************************************************************/
#include <stdint.h>

/********************************************************************************/
/*                             SYSTICK CLOCK SOURCE ENUM                        */
/********************************************************************************/
typedef enum {
    SYSTICK_CLKSOURCE_AHB = 0,
    // Add more clock source options if needed
} enu_SysTick_ClockSource_t;


/********************************************************************************/
/*                             SYSTICK ERROR STATE                              */
/********************************************************************************/
typedef enum {
    SYSTICK_OK = 0,
    SYSTICK_ERROR_INVALID_SOURCE,
    SYSTICK_ERROR_INVALID_OPERATION,
} enu_SysTick_Error_t;




/********************************************************************************/
/*                            FUNCTION PROTOTYPES                               */
/********************************************************************************/

/**
 * @brief      Initialize the SysTick timer.
 * @param      reload_value   The value to load into the SysTick Load register.
 * @param      clk_source     The clock source for the SysTick timer.
 * @return     enu_SysTick_Error_t   Error status.
 */
enu_SysTick_Error_t SysTick_Init(uint32_t reload_value, enu_SysTick_ClockSource_t clk_source);


/**
 * @brief      Start the SysTick timer.
 * @return     enu_SysTick_Error_t   Error status.
 */
enu_SysTick_Error_t SysTick_Start(void);


/**
 * @brief      Stop the SysTick timer.
 * @return     enu_SysTick_Error_t   Error status.
 */
enu_SysTick_Error_t SysTick_Stop(void);


/**
 * @brief      Check if the SysTick timer has counted down to zero.
 * @return     1 if the timer has counted down to zero, 0 otherwise.
 */
uint8_t SysTick_CheckTimeOut(void);


/**
 * @brief      Delay for a specified number of milliseconds using the SysTick timer.
 * @param      delay_ms   The number of milliseconds to delay.
 * @return     enu_SysTick_Error_t   Error status.
 */
enu_SysTick_Error_t SysTick_DelayMs(uint32_t delay_ms);


/**
 * @brief      Delay for a specified number of microseconds using the SysTick timer.
 * @param      delay_us   The number of microseconds to delay.
 * @return     enu_SysTick_Error_t   Error status.
 */
enu_SysTick_Error_t SysTick_DelayUs(uint32_t delay_us);


#endif /* SYSTICK_INTERFACE_H */