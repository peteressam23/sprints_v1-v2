/********************************************************************************/
/*                               INCLUDES                                       */
/********************************************************************************/
#include "app.h"
#include "systick_manager_interface.h"
#include "button_interface.h"
#include "led_interface.h"

/********************************************************************************/
/*                               Global variable                                */
/********************************************************************************/
uint8_t uint8_g_applicationCounter = FALSE;
static uint8_t uint8_g_redFlag = 0;
static uint8_t uint8_g_greenFlag = 0;
static uint8_t uint8_g_blueFlag = 0;
static uint8_t uint8_g_alleds = 0;
/********************************************************************************/
/*                               Implementation                                 */
/********************************************************************************/
void timeDelay(void)
{
    static uint32_t uint32_ls_countTime = FALSE;
    for (uint32_ls_countTime = FALSE ; uint32_ls_countTime < TIME_DELAY ; uint32_ls_countTime++);
}

void app_init(void)
{
	 // SysTick_Init(0, SYSTICK_CLKSOURCE_AHB);
	  SysTickManager_Init(0, SYSTICK_CLKSOURCE_AHB);
    H_LED_init(PORT_RED_LED , PIN_RED_LED);
    H_LED_init(PORT_GREEN_LED , PIN_GREEN_LED);
    H_LED_init(PORT_BLUE_LED , PIN_BLUE_LED);
	  H_BUTTON_init();
}


void app_Start(void)
{
    boolean bool_l_buttonValue = TRUE;
    while (1) 
    {
        /*BUTTON_0*/
        (void)H_BUTTON_read(BUTTON_0, &bool_l_buttonValue);
        /*if BUTTON_0 low*/
        if (bool_l_buttonValue == FALSE) 
        {
            /*Stuck in  while 1*/
            while (bool_l_buttonValue == FALSE) 
            {
                (void)H_BUTTON_read(BUTTON_0, &bool_l_buttonValue);
            }
 
            /* Introduce a delay of 1000 milliseconds using SysTick */
          //  SysTick_DelayMs(1000);
            uint8_g_applicationCounter++;
        }


        switch (uint8_g_applicationCounter) 
        {
            /*Leds off*/
            case 0: 
							{
                (void)H_LED_off(PORT_RED_LED , PIN_RED_LED);
                (void)H_LED_off(PORT_GREEN_LED , PIN_GREEN_LED);
                (void)H_LED_off(PORT_BLUE_LED , PIN_BLUE_LED);
                break;
              }
             /*On Red led*/
            case 1: 
							{
								if(uint8_g_redFlag == 0)
								{
									(void)H_LED_on(PORT_RED_LED , PIN_RED_LED);
									(void)H_LED_off(PORT_GREEN_LED, PIN_GREEN_LED);
									(void)H_LED_off(PORT_BLUE_LED, PIN_BLUE_LED);
									//SysTick_DelayMs(500);
									SysTickManager_DelayMs(1000);									
                	uint8_g_redFlag=1;						
								}
								else
								{
									//SysTick_DelayMs(1000);
					        H_LED_off(PORT_RED_LED , PIN_RED_LED);
									
								}
									
                break;
              }
            /*On Green led*/
            case 2: 
							{
								if(uint8_g_greenFlag == 0)
								{
									(void)H_LED_off(PORT_RED_LED , PIN_RED_LED);
									(void)H_LED_on(PORT_GREEN_LED , PIN_GREEN_LED);
									(void)H_LED_off(PORT_BLUE_LED , PIN_BLUE_LED);
									//SysTick_DelayMs(500);
									SysTickManager_DelayMs(1000);	
									uint8_g_greenFlag = 1;
								}
								else
								{
									//SysTick_DelayMs(1000);
					        (void)H_LED_off(PORT_GREEN_LED , PIN_GREEN_LED);
								}
                break;
            }
            /*On Blue led*/
            case 3:
							{
								if(uint8_g_blueFlag == 0)
								{
									(void)H_LED_off(PORT_RED_LED , PIN_RED_LED);
									(void)H_LED_off(PORT_GREEN_LED, PIN_GREEN_LED);
									(void)H_LED_on(PORT_BLUE_LED , PIN_BLUE_LED);
									//SysTick_DelayMs(500);
									SysTickManager_DelayMs(1000);	
									uint8_g_blueFlag = 1;
								}
								else
								{
									//SysTick_DelayMs(1000);
					        (void)H_LED_off(PORT_BLUE_LED , PIN_BLUE_LED);
								}

                break;
              }
            // All LEDs on
            case 4: 
							{
								if(uint8_g_alleds == 0)
								{
									(void)H_LED_on(PORT_RED_LED , PIN_RED_LED);
									(void)H_LED_on(PORT_GREEN_LED , PIN_GREEN_LED);
									(void)H_LED_on(PORT_BLUE_LED , PIN_BLUE_LED);		
                  //SysTick_DelayMs(500);	
									SysTickManager_DelayMs(1000);	
                  uint8_g_alleds =1;									
								}
								else
								{
									//SysTick_DelayMs(1000);
									(void)H_LED_off(PORT_RED_LED , PIN_RED_LED);
									(void)H_LED_off(PORT_GREEN_LED , PIN_GREEN_LED);
									(void)H_LED_off(PORT_BLUE_LED , PIN_BLUE_LED);
								}

                break;
             }
            
            default: 
							{
                uint8_g_applicationCounter = 0;
								uint8_g_redFlag = 0;
								uint8_g_greenFlag = 0;
								uint8_g_blueFlag = 0;
								uint8_g_alleds = 0;
                break;
              }
        }
				
	
    }
}

