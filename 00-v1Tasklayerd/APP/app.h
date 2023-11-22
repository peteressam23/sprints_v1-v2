/********************************************************************************/
/*                              HEADER GUARD                                    */
/********************************************************************************/
#include "led_interface.h"
#include "button_interface.h"

/********************************************************************************/
/*                                TIME DELAY                                    */
/********************************************************************************/
#define TIME_DELAY   100000

/********************************************************************************/
/*                                 PROTOTYPES                                   */
/********************************************************************************/
/**
 * @brief  Delays the program
 * @param  void.
 * @return void.
 */
void timeDelay(void);

/**
 * @brief INIT buttons and LEDs     
*/
void app_init(void);

/**
 * @brief start app
 * @return void.
 */
void app_Start(void);

