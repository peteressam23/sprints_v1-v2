/********************************************************************************/
/*                                   INCLUDES                                   */
/********************************************************************************/
#include "systick_private.h"
#include "systick_interface.h"


/********************************************************************************/
/*                           SYSTICK CONTROL MACROS                             */
/********************************************************************************/
// SysTick Control and Status Register (STCTRL) bits
#define SYSTICK_ENABLE      (1 << 0)  // Bit 0: Enables the counter
#define SYSTICK_INT_ENABLE  (1 << 1)  // Bit 1: Enables SysTick interrupt

// Macro for SysTick configuration with a specific clock source
#define SYSTICK_CONFIG_CLKSOURCE(source)   (((source) << 2) | SYSTICK_ENABLE)


/********************************************************************************/
/*                           SYSTICK CONTROL MACROS                             */
/********************************************************************************/

// SysTick Control and Status Register (STCTRL) bits
#define SYSTICK_ENABLE      (1 << 0)  // Bit 0: Enables the counter
#define SYSTICK_ENABLE_MASK (1 << 0)  // Bitmask for the enable bit

// SysTick Control Register (STCTRL) bits
#define SYSTICK_CTRL_CLKSOURCE_MASK  (1 << 2)  // Bitmask for the clock source bits


/********************************************************************************/
/*                                   Implementation                             */
/********************************************************************************/

enu_SysTick_Error_t SysTick_Init(uint32_t reload_value, enu_SysTick_ClockSource_t clk_source) 
{
    /*Validate the clock source*/
    if (clk_source != SYSTICK_CLKSOURCE_AHB)
		{
        return SYSTICK_ERROR_INVALID_SOURCE;
    }

    /*Disable SysTick during configuration*/
    SYSTICK_CTRL = 0;

    /*Set the reload value*/
    SYSTICK_LOAD = reload_value - 1;

    /*Use the specified clock source, enable SysTick*/
    SYSTICK_CTRL = SYSTICK_CONFIG_CLKSOURCE(clk_source);
    return SYSTICK_OK;
}

/*************************************************************************************/

enu_SysTick_Error_t SysTick_Start(void)
{
    /*Enable SysTick*/
    if ((SYSTICK_CTRL & SYSTICK_ENABLE_MASK) == 0)
		{
        SYSTICK_CTRL |= SYSTICK_ENABLE;
        return SYSTICK_OK;
    }
		else
		{
        return SYSTICK_ERROR_INVALID_OPERATION;
    }
}

/*************************************************************************************/
enu_SysTick_Error_t SysTick_Stop(void)
{
    /*Disable SysTick*/
    if ((SYSTICK_CTRL & SYSTICK_ENABLE_MASK) != 0)
		{
        SYSTICK_CTRL &= ~SYSTICK_ENABLE;
        return SYSTICK_OK;
    } 
		else 
		{
        return SYSTICK_ERROR_INVALID_OPERATION;
    }
}

/*************************************************************************************/

enu_SysTick_Error_t SysTick_DelayMs(uint32_t delay_ms)
{
    /*Validate the delay_ms parameter*/
    if (delay_ms == 0) 
		{
        return SYSTICK_ERROR_INVALID_OPERATION;
    }

    /*Calculate the reload value for the given delay in milliseconds*/
    uint32_t reload_value = delay_ms * 16000;  // Assuming a 16MHz clock

    /*Initialize and start the SysTick timer*/
    enu_SysTick_Error_t init_status = SysTick_Init(reload_value, SYSTICK_CLKSOURCE_AHB);
    if (init_status != SYSTICK_OK) 
		{
        return init_status;
    }

    /*Wait until the COUNTFLAG is set, indicating the delay has passed*/
    while (!SysTick_CheckTimeOut()) 
		{
        // Wait
    }

    // Stop the SysTick timer
    enu_SysTick_Error_t stop_status = SysTick_Stop();
    if (stop_status != SYSTICK_OK)
		{
        return stop_status;
    }

    return SYSTICK_OK;
}

enu_SysTick_Error_t SysTick_DelayUs(uint32_t delay_us)
{
    /*Validate the delay_us parameter*/
    if (delay_us == 0) 
		{
        return SYSTICK_ERROR_INVALID_OPERATION;
    }

    /*Calculate the reload value for the given delay in microseconds*/
    uint32_t reload_value = delay_us * 16;  // Assuming a 16MHz clock

    /*Initialize and start the SysTick timer*/
    enu_SysTick_Error_t init_status = SysTick_Init(reload_value, SYSTICK_CLKSOURCE_AHB);
    if (init_status != SYSTICK_OK) 
		{
        return init_status;
    }

    /* Wait until the COUNTFLAG is set, indicating the delay has passed*/
    while (!SysTick_CheckTimeOut())
		{
        // Wait
    }

    /*Stop the SysTick timer*/
    enu_SysTick_Error_t stop_status = SysTick_Stop();
    if (stop_status != SYSTICK_OK)
		{
        return stop_status;
    }

    return SYSTICK_OK;
}

uint8_t SysTick_CheckTimeOut(void) {
    // Check the COUNTFLAG bit in the SysTick Control and Status Register (STCTRL)
    return (SYSTICK_CTRL & (1 << 16)) != 0;
}