/********************************************************************************/
/*                                   INCLUDES                                   */
/********************************************************************************/
#include "gpio_private.h"
#include "gpio_interface.h"


/********************************************************************************/
/*                                   Global Arrays                              */
/********************************************************************************/

/*store states of GPIO Ports initial values*/
static boolean bool_gs_portInitialized [INVALID_PORT] = {FALSE};


/*store states of GPIO Ports interrupts initial values*/
static boolean bool_gs_interruptEnable [INVALID_PORT] = {FALSE};

/* store the enable states of global interrupt initial values */
static boolean bool_gs_IRQEnable  = FALSE;


/********************************************************************************/
/*                                   Implementation                             */
/********************************************************************************/
enu_MGPIO_errorStatus_t MGPIO_init (str_MGPIO_configuration_t *ptr_str_MGPIO_config)
{
	  /* make variable to store error state*/
    enu_MGPIO_errorStatus_t enu_l_errorState = GPIO_OK;
    /* check if the pointer to struct is null pointer*/
		if(ptr_str_MGPIO_config == NULL)
		{
			enu_l_errorState = GPIO_NULL_POINTER;
		}
    else
    {
			/*check port number*/
			if((ptr_str_MGPIO_config->enu_portNumber) < INVALID_PORT)
			{
				
				if( bool_gs_portInitialized[ptr_str_MGPIO_config->enu_portNumber] == FALSE)
				{
						/*set the clock*/
						SET_BIT(RCGCGPIO_REG , ptr_str_MGPIO_config->enu_portNumber);
						/*set port state  INITIALIZED*/
						bool_gs_portInitialized[ptr_str_MGPIO_config->enu_portNumber] = TRUE;
				}
				
				/*check pin number*/
				if((ptr_str_MGPIO_config->enu_pinNumber) < INVALID_PIN)
				{
					/*set the direction then value*/
					switch(ptr_str_MGPIO_config->enu_pinDirection)
					{
							case OUTPUT_PIN_DIRECTION :
							SET_BIT(GPIODIR(ptr_str_MGPIO_config->enu_portNumber) , ptr_str_MGPIO_config->enu_pinNumber);
								switch (ptr_str_MGPIO_config->enu_pinValue)
								{
										case PIN_HIGH_VALUE:
										SET_BIT(GPIODATA(ptr_str_MGPIO_config->enu_portNumber) , ptr_str_MGPIO_config->enu_pinNumber);
										break;

										case PIN_LOW_VALUE:
										CLEAR_BIT(GPIODATA(ptr_str_MGPIO_config->enu_portNumber) , ptr_str_MGPIO_config->enu_pinNumber);
										break;

										default:
									  enu_l_errorState = GPIO_VALUE_ERROR ;
								}

								/*set the output current*/
								switch(ptr_str_MGPIO_config->enu_pinOutCurrent)
								{
										case PIN_CURRENT_2MA:
										SET_BIT(GPIODR2R(ptr_str_MGPIO_config->enu_portNumber) , ptr_str_MGPIO_config->enu_pinNumber);
										break;

										case PIN_CURRENT_4MA:
										SET_BIT(GPIODR4R(ptr_str_MGPIO_config->enu_portNumber) , ptr_str_MGPIO_config->enu_pinNumber);
										break;			

										case PIN_CURRENT_8MA:
										SET_BIT(GPIODR8R(ptr_str_MGPIO_config->enu_portNumber) , ptr_str_MGPIO_config->enu_pinNumber);
										break;

										default:
										enu_l_errorState = GPIO_OUT_CURRENT_ERROR;				
								}
						 break;

						case INPUT_PIN_DIRECTION:
							CLEAR_BIT(GPIODIR(ptr_str_MGPIO_config->enu_portNumber) , ptr_str_MGPIO_config->enu_pinNumber);
								/*set the pin Internal Type*/	
								switch(ptr_str_MGPIO_config->enu_pinInternalType)
								{
										case PULL_UP:
										CLEAR_BIT(GPIOODR(ptr_str_MGPIO_config->enu_portNumber), ptr_str_MGPIO_config->enu_pinNumber);
										CLEAR_BIT(GPIOPDR(ptr_str_MGPIO_config->enu_portNumber), ptr_str_MGPIO_config->enu_pinNumber);
										SET_BIT(GPIOPUR(ptr_str_MGPIO_config->enu_portNumber) , ptr_str_MGPIO_config->enu_pinNumber);
										break;

										case PULL_DOWN:
										CLEAR_BIT(GPIOODR(ptr_str_MGPIO_config->enu_portNumber), ptr_str_MGPIO_config->enu_pinNumber);
										CLEAR_BIT(GPIOPUR(ptr_str_MGPIO_config->enu_portNumber), ptr_str_MGPIO_config->enu_pinNumber);
										SET_BIT(GPIOPDR(ptr_str_MGPIO_config->enu_portNumber), ptr_str_MGPIO_config->enu_pinNumber);
										break;	

										case OPEN_DRAIN:
										CLEAR_BIT(GPIOPDR(ptr_str_MGPIO_config->enu_portNumber), ptr_str_MGPIO_config->enu_pinNumber);
										CLEAR_BIT(GPIOPUR(ptr_str_MGPIO_config->enu_portNumber), ptr_str_MGPIO_config->enu_pinNumber);
										SET_BIT(GPIOODR(ptr_str_MGPIO_config->enu_portNumber), ptr_str_MGPIO_config->enu_pinNumber);
										break;

										default:
										enu_l_errorState  = GPIO_INTERNAL_TYPE_ERROR;					
								}
						  break;

						default:
							enu_l_errorState = GPIO_DIRECTION_ERROR ;
					}

					/*set the pin type*/
					switch (ptr_str_MGPIO_config->enu_pinType)
					{
						case MGPIO_PIN:
							CLEAR_BIT(GPIOAFSEL(ptr_str_MGPIO_config->enu_portNumber) , ptr_str_MGPIO_config->enu_pinNumber);
						break;

						case ALTERNATIVE_PIN:
							SET_BIT(GPIOAFSEL(ptr_str_MGPIO_config->enu_portNumber) , ptr_str_MGPIO_config->enu_pinNumber);
							 /*TODO: alternative settings*/
						break;

						default:
						enu_l_errorState = GPIO_PIN_TYPE_ERROR;	
					}

					/*set the pin mode*/	
					switch(ptr_str_MGPIO_config->enu_pinMode)
					{
						case DIGITAL_PIN_MODE:
						CLEAR_BIT(GPIOAMSEL(ptr_str_MGPIO_config->enu_portNumber),ptr_str_MGPIO_config->enu_pinNumber);
						SET_BIT(GPIODEN(ptr_str_MGPIO_config->enu_portNumber),ptr_str_MGPIO_config->enu_pinNumber);
						break;

						case ANALOG_PIN_MODE:
						CLEAR_BIT(GPIODEN(ptr_str_MGPIO_config->enu_portNumber) , ptr_str_MGPIO_config->enu_pinNumber);
						SET_BIT(GPIOAMSEL(ptr_str_MGPIO_config->enu_portNumber) , ptr_str_MGPIO_config->enu_pinNumber);
						break;		

						default:
						enu_l_errorState = GPIO_MODE_ERROR;					
					}
				}
				else
				{
					 enu_l_errorState = GPIO_PIN_ERROR;
				}
		  }
			else
			{
					enu_l_errorState=   GPIO_PORT_ERROR;
			}
   }
   return enu_l_errorState;
}

/**************************************************************************************************************/

enu_MGPIO_errorStatus_t MGPIO_write(enu_MGPIO_portNumber_t enu_a_portNumber, enu_MGPIO_pinNumber_t enu_a_pinNumber, enu_MGPIO_pinValue_t enu_l_pinValue)
{
	/* make variable to store error state*/
   enu_MGPIO_errorStatus_t enu_l_errorState = GPIO_OK;
	/*check the port number*/
	if(enu_a_portNumber < INVALID_PORT)
	{
		if( bool_gs_portInitialized[enu_a_portNumber] == TRUE )
		{
			if(enu_a_pinNumber < INVALID_PIN)
			{
				if(enu_l_pinValue == PIN_HIGH_VALUE)
				{
					SET_BIT(GPIODATA(enu_a_portNumber),enu_a_pinNumber);
				}
				else if (enu_l_pinValue == PIN_LOW_VALUE)
				{
						CLEAR_BIT(GPIODATA(enu_a_portNumber),enu_a_pinNumber);
				}
				else
				{
						enu_l_errorState = GPIO_VALUE_ERROR ;
				}
			}
			else
			{
					enu_l_errorState = GPIO_PIN_ERROR;
			}
		}
		else
		{
				enu_l_errorState = GPIO_PORT_NOT_INITIALIZED ;
		}
	}
	else
	{
		enu_l_errorState = GPIO_PORT_ERROR;
	}
	
	return enu_l_errorState;
}

/**************************************************************************************************************/

enu_MGPIO_errorStatus_t MGPIO_read(enu_MGPIO_portNumber_t enu_a_portNumber, enu_MGPIO_pinNumber_t enu_a_pinNumber, boolean *ptr_arg_pinValue)
{
	/* make variable to store error state*/
  enu_MGPIO_errorStatus_t enu_l_errorState = GPIO_OK;
	/*check the port number*/
	if(enu_a_portNumber < INVALID_PORT)
	{
     if(bool_gs_portInitialized[enu_a_portNumber] == TRUE )
       {
					if(enu_a_pinNumber< INVALID_PIN)
					{  
							if(ptr_arg_pinValue != NULL)
							{
								*ptr_arg_pinValue = GET_BIT(GPIODATA(enu_a_portNumber),enu_a_pinNumber);
							}
							else
							{
								enu_l_errorState = GPIO_NULL_POINTER ;
							}
					 }
					 else
					 {
							enu_l_errorState = GPIO_PIN_ERROR;
					 }
        }
				else
				{
					enu_l_errorState = GPIO_PORT_NOT_INITIALIZED ;
				}
    }
    else
    {
        enu_l_errorState = GPIO_PORT_ERROR;
    } 
	return enu_l_errorState;
}

/**************************************************************************************************************/

enu_MGPIO_errorStatus_t MGPIO_toggle(enu_MGPIO_portNumber_t enu_a_portNumber , enu_MGPIO_pinNumber_t enu_a_pinNumber)
{
	 /* make variable to store error state*/
   enu_MGPIO_errorStatus_t enu_l_errorState = GPIO_OK;
	 /*check the port number*/ 
   if(enu_a_portNumber < INVALID_PORT)
	  {
       if( bool_gs_portInitialized[enu_a_portNumber] == TRUE )
        {
					if(enu_a_pinNumber < INVALID_PIN)
					{
							TOGGLE_BIT(GPIODATA(enu_a_portNumber),enu_a_pinNumber);
					}
					else
					{
							enu_l_errorState = GPIO_PIN_ERROR;
					}
        }
				else
				{
						enu_l_errorState = GPIO_PORT_NOT_INITIALIZED ;
				}
    }
    else
    {
        enu_l_errorState = GPIO_PORT_ERROR;
    } 
    return enu_l_errorState;
}


/**************************************************************************************************************/


