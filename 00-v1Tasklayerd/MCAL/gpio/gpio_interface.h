/********************************************************************************/
/*                              HEADER GUARD                                    */
/********************************************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/********************************************************************************/
/*                                   INCLUDES                                   */
/********************************************************************************/
#include "common.h"

/********************************************************************************/
/*                                   CALL BACK FUNC                             */
/********************************************************************************/
typedef void (*ptr_MGPIO_callBack_t)(void);


/********************************************************************************/
/*                                   GPIO PORTS                                 */
/********************************************************************************/
typedef enum __MGPIO_portNumber
{
	PORTA = 0 ,
	PORTB     ,
	PORTC     ,
	PORTD     ,
	PORTE     ,
	PORTF     ,
	INVALID_PORT
}enu_MGPIO_portNumber_t;

/********************************************************************************/
/*                                    GPIO PINS                                 */
/********************************************************************************/
typedef enum __MGPIO_pinNumber
{
	PIN0 = 0,
	PIN1    ,
	PIN2    ,
	PIN3    ,
	PIN4    ,
	PIN5    ,
	PIN6    ,
	PIN7    ,
	INVALID_PIN
}enu_MGPIO_pinNumber_t;

/********************************************************************************/
/*                                   GPIO PIN DIRECTION                         */
/********************************************************************************/
typedef enum __MGPIO_pinDirection
{
	INPUT_PIN_DIRECTION  = 0      ,
	OUTPUT_PIN_DIRECTION          ,
	INVALID_DIRECTION
}enu_MGPIO_pinDirection_t;

/********************************************************************************/
/*                                    GPIO PIN MODE                             */
/********************************************************************************/
typedef enum __MGPIO_pinMode
{
	DIGITAL_PIN_MODE  = 0,
	ANALOG_PIN_MODE      ,
	INVALID_MODE
}enu_MGPIO_pinMode_t;

/********************************************************************************/
/*                                   GPIO PIN VALUE (LEVEL)                     */
/********************************************************************************/
typedef enum __MGPIO_pinValue
{
	PIN_LOW_VALUE    = 0,
	PIN_HIGH_VALUE      ,
	INVALID_PIN_VALUE
}enu_MGPIO_pinValue_t;


/********************************************************************************/
/*                                   GPIO PIN OUT CURRENT                       */
/********************************************************************************/
typedef enum __MGPIO_pinOutCurrent
{
	PIN_CURRENT_2MA  = 0,
	PIN_CURRENT_4MA     ,
	PIN_CURRENT_8MA     ,
	INVALID_OUT_CURRENT
}enu_MGPIO_pinOutCurrent_t;

/********************************************************************************/
/*                                      GPIO PIN TYPE                           */
/********************************************************************************/
typedef enum __MGPIO_pinType
{
	MGPIO_PIN  		  = 0,
	ALTERNATIVE_PIN      ,
	INVALID_TYPE
}enu_MGPIO_pinType_t;

/********************************************************************************/
/*                           GPIO PIN INTERNAL ATTACH                           */
/********************************************************************************/
typedef enum __MGPIO_pinInternalType
{
	OPEN_DRAIN   = 0,
	PULL_UP         ,
	PULL_DOWN       ,
	INVALID_INTERNAL_TYPE
}enu_MGPIO_pinInternalType_t;

/********************************************************************************/
/*                       GPIO PIN TRIGGER INTERRUPTS                            */
/********************************************************************************/
typedef enum __MGPIO_pinEventTrigger
{
	TRIGGER_FALLING_EDGE                          = 0,
	TRIGGER_RISING_EDGE                              ,
	TRIGGER_BOTH_RISING_FALLING_EDGES                ,
	TRIGGER_PIN_LOW               				           ,
	TRIGGER_PIN_HIGH              				           ,
	INVALID_TRIGGER
}enu_MGPIO_pinEventTrigger_t;

/********************************************************************************/
/*                               GPIO ERROR STATUS                              */
/********************************************************************************/
typedef enum __MGPIO_errorStatus
{
	GPIO_OK                       =0,
	GPIO_NULL_POINTER               ,
	GPIO_PORT_ERROR                 ,
	GPIO_PIN_ERROR                  ,
	GPIO_DIRECTION_ERROR            ,
	GPIO_MODE_ERROR                 ,
	GPIO_PIN_TYPE_ERROR							,
	GPIO_OUT_CURRENT_ERROR          ,
	GPIO_INTERNAL_TYPE_ERROR        ,
	GPIO_VALUE_ERROR                ,
	GPIO_EVENT_TRIGGER_ERROR        ,
	GPIO_PORT_NOT_INITIALIZED       , 
	GPIO_NULL_CB_POINTER
}enu_MGPIO_errorStatus_t;


/********************************************************************************/
/*                       GPIO PIN TRIGGER INTERRUPTS                            */
/********************************************************************************/
typedef struct __MGPIO_configuration
{
	/*
  	options pin number:
	    -> 0 : 7
	*/
	enu_MGPIO_pinNumber_t           enu_pinNumber; 
	
	/*
  	options port number:
	    -> MGPIO_PIN
      -> ALTERNATIVE_PIN
	*/
	enu_MGPIO_portNumber_t          enu_portNumber;                       
	
	/*
  	options pin Dir :
	    -> INPUT_PIN_DIRECTION
      -> OUTPUT_PIN_DIRECTION
	*/
	enu_MGPIO_pinDirection_t        enu_pinDirection;                    

	/*
  	options pin mode:
	    -> DIGITAL_PIN_MODE
      -> ANALOG_PIN_MODE
	*/
	enu_MGPIO_pinMode_t             enu_pinMode;                     
	
	/*
  	options pin type:
	    -> DIGITAL_PIN_MODE
      -> ANALOG_PIN_MODE
	*/
	enu_MGPIO_pinType_t			        enu_pinType;			                      
	

	/*
	  for output direction if direction output 
	  options pin value:
	   -> PIN_LOW_VALUE
     -> PIN_HIGH_VALUE
	*/
	enu_MGPIO_pinValue_t         enu_pinValue;    

	/*
	  options pin out current:
	   -> PIN_CURRENT_2mA
	   -> PIN_CURRENT_4mA
	   -> PIN_CURRENT_8mA
	*/
	enu_MGPIO_pinOutCurrent_t    enu_pinOutCurrent;                         

	/*
	  for input direction if direction input 
	  options pin internal type:
	   -> OPEN_DRAIN
     -> PULL_UP
	   -> PULL_DOWN
	*/
	enu_MGPIO_pinInternalType_t enu_pinInternalType;      
}str_MGPIO_configuration_t;	


/********************************************************************************/
/*                                PROTOTYPES                                    */
/********************************************************************************/

/**
 * @brief      Initialize GPIO pin OUTPUT,INPUT,INTERRUPT.
 * @param      ptr_str_MGPIO_config Pointer to str_MGPIO_configuration_t refer to these options:
 *                    
 *            - enu_pinNumber      				 -> Select Pin Number 
 *            - enu_portNumber      			 -> Select Port Number
 *            - enu_pinDirection   				 -> Select Pin Direction
 *            - enu_pinMode         			 -> Select Pin Mode           		 
 *            - enu_pinValue        			 -> Select level
 *            - enu_pinOutCurrent   			 -> Select output current               		 
 *            - enu_pinInternalType 			 -> Select Internal type
 *            - bool_useInterrupt          -> Select interrupt or not
 *            - enu_GPIO_pinEventTrigger 	 -> Select sense trigger
 *            - ptr_GPIO_callback          -> Set callback 
 * 
 * @return     GPIO_OK                         -> success initialization
 *             GPIO_NULL_POINTER               -> Null pointer argument
 *             GPIO_PORT_ERROR                 -> Invalid port number
 *             GPIO_PIN_ERROR                  -> Invalid pin number
 *             GPIO_DIRECTION_ERROR            -> Invalid pin direction
 *             GPIO_MODE_ERROR                 -> Invalid mode selection
 *             GPIO_OUT_CURRENT_ERROR          -> Invalid output current
 *             GPIO_INTERNAL_TYPE_ERROR        -> Invalid internal type
 *             GPIO_LEVEL_ERROR                -> Invalid output level
 *             GPIO_EVENT_TRIGGER_ERROR        -> Invalid sense triggel
 *             GPIO_NULL_CB_POINTER            -> Null pointer to cbf
 */
 enu_MGPIO_errorStatus_t MGPIO_init (str_MGPIO_configuration_t *ptr_str_MGPIO_config);


/**
* @brief        Choose level for pin 
* @param        - enu_portNumber_t     -> Select Port Number 
								- enu_pinNumber_t      -> Select Pin Number
								- enu_pinValue_t       -> Select Output level
								
								
* @return  GPIO_OK                       -> success
			     GPIO_PORT_ERROR               -> Invalid port number
			     GPIO_PIN_ERROR                -> Invalid pin nimber
			     GPIO_LEVEL_ERROR              -> Invalid output level
			     GPIO_PORT_NOT_INITIALIZED     -> the port not initialized
*/
enu_MGPIO_errorStatus_t MGPIO_write(enu_MGPIO_portNumber_t enu_a_portNumber, enu_MGPIO_pinNumber_t enu_a_pinNumber, enu_MGPIO_pinValue_t enu_l_pinValue);


/**
*@brief       Read value from specific
*@param         - enu_portNumber         -> Select Port Number 
								- enu_pinNumber          -> Select Pin Number
                - ptr_a_pinValue         -> pointer to boolean to store value true , false
								
*@return  GPIO_OK                     -> success initialization
			    GPIO_NULL_POINTER           -> Null pointer argument
			    GPIO_PORT_ERROR             -> Invalid port number
			    GPIO_PIN_ERROR              -> Invalid pin nimber
				  GPIO_PORT_NOT_INITIALIZED    port is not initialized
*/
enu_MGPIO_errorStatus_t MGPIO_read(enu_MGPIO_portNumber_t enu_a_portNumber, enu_MGPIO_pinNumber_t enu_a_pinNumber, boolean *ptr_arg_pinValue);


/**
*@brief         Toggle  pin 
*@param         - enu_portNumber_t -> Select Port Number 
								- enu_pinNumber_t  -> Select Pin Number
								
*@return GPIO_OK                    -> success
			   GPIO_PORT_ERROR            -> Invalid port number
			   GPIO_PIN_ERROR             -> Invalid pin number
			   GPIO_PORT_NOT_INITIALIZED  -> the port not initialized
*/
enu_MGPIO_errorStatus_t MGPIO_toggle(enu_MGPIO_portNumber_t enu_a_portNumber, enu_MGPIO_pinNumber_t enu_a_pinNumber);



/**
*@brief        Enable interrupt for pin
*@param         - enu_portNumber_t  -> Select Port Number 
								- enu_pinNumber_t   -> Select Pin Number	
								
*@return GPIO_OK                     -> success 
			   GPIO_PORT_ERROR             -> Invalid port number
			   GPIO_PIN_ERROR              -> Invalid pin number
			   GPIO_PORT_NOT_INITIALIZED   -> the port not initialized
*/
enu_MGPIO_errorStatus_t  MGPIO_enableInterrupt(enu_MGPIO_portNumber_t enu_a_portNumber, enu_MGPIO_pinNumber_t enu_a_pinNumber);


/**
*@brief        Disable interrupt for pin
*@param         - enu_portNumber_t  -> Select Port Number 
								- enu_pinNumber_t   -> Select Pin Number	
								
*@return GPIO_OK                    -> success operation
			   GPIO_PORT_ERROR            -> Invalid port number
			   GPIO_PIN_ERROR             ->Invalid pin number
			   GPIO_PORT_NOT_INITIALIZED  -> portnot initialized
*/
enu_MGPIO_errorStatus_t MGPIO_disableInterrupt(enu_MGPIO_portNumber_t enu_a_portNumber, enu_MGPIO_pinNumber_t enu_a_pinNumber);


#endif