/********************************************************************************/
/*                              HEADER GUARD                                    */
/********************************************************************************/
#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_


/********************************************************************************/
/*                              GPIO base address                               */
/********************************************************************************/
/*First Select BUS*/
#define GPIO_APB
#ifdef  GPIO_APB
#define GPIO_OFFSET(x)         (x < 4 ? ((0x40004000) + ((x) * 0x1000)) : ((0x40024000) + ((x - 4) * 0x1000)))

/*Second Select Bus*/
#elif GPIO_AHB
#error  "Not Supported"
#else
#error  "Please Choose Bus for GPIOs"
#endif

/********************************************************************************/
/*                                 GPIO Register                                */
/********************************************************************************/

/* 
   GPIO Data Register
	 Description :  Used to read and write the data on pins for a port choose
*/
#define GPIODATA(x)            ( *(volatile uint32_t*) (GPIO_OFFSET(x) + (0x3FC)) )

/*
   GPIO Direction Register
   Description : Setdirection of pins I/O for a port choose
*/
#define GPIODIR(x)             ( *(volatile uint32_t*) (GPIO_OFFSET(x) + (0x400)) )

/*
   GPIO Interrupt Sense Register
   Description : Configuration the interrupt detection level
*/
#define GPIOIS(x)              ( *(volatile uint32_t*) (GPIO_OFFSET(x) + (0x404)) )

/*
		GPIO Interrupt Both Edges Register 
		Description : Enable interrupt trigger
*/
#define GPIOIBE(x)             ( *(volatile uint32_t*) (GPIO_OFFSET(x) + (0x408)) )

/*
		GPIO Interrupt Event Register
    Description : Configuration interrupt trigger rising or falling edge.
*/
#define GPIOIEV(x)             ( *(volatile uint32_t*) (GPIO_OFFSET(x) + (0x40C)) )

/*
		GPIO Interrupt Mask Register
	  Description : Enables interrupt
*/
#define GPIOIM(x)              ( *(volatile uint32_t*) (GPIO_OFFSET(x) + (0x410)) )


/*
		GPIO Raw Interrupt Status Register
		Description : Shows the raw interrupt status 
*/
#define GPIORIS(x)             ( *(volatile uint32_t*) (GPIO_OFFSET(x) + (0x414)) )

/*
		GPIO Masked Interrupt Status Register
		Description : Shows the masked interrupt status 
*/
#define GPIOMIS(x)             ( *(volatile uint32_t*) (GPIO_OFFSET(x) + (0x418)) )

/*
		GPIO Interrupt Clear Register
		Description : Clears interrupt flags 
*/
#define GPIOICR(x)             ( *(volatile uint32_t*) (GPIO_OFFSET(x) + (0x41C)) )

/*
		GPIO Alternate Function Select Register
		Description : Selects alternate function
*/
#define GPIOAFSEL(x)           ( *(volatile uint32_t*) (GPIO_OFFSET(x) + (0x420)) )

/*
		GPIO 2-mA Drive Select Register
		Description : Configures 2-mA drive strength 
*/
#define GPIODR2R(x)            ( *(volatile uint32_t*) (GPIO_OFFSET(x) + (0x500)) )

/*
		GPIO 4-mA Drive Select Register
		Description : Configures 4-mA drive strength 
*/
#define GPIODR4R(x)            ( *(volatile uint32_t*) (GPIO_OFFSET(x) + (0x504)) )

/*
		GPIO 8-mA Drive Select Register
		Description : Configures 8-mA drive strength 
*/
#define GPIODR8R(x)            ( *(volatile uint32_t*) (GPIO_OFFSET(x) + (0x508)) )

/*
		GPIO Open Drain Select Register
		Description : Configures open-drain mode
*/
#define GPIOODR(x)             ( *(volatile uint32_t*) (GPIO_OFFSET(x) + (0x50C)) )

/*
		GPIO Pull-Up Select Register
		Description : Enables pull-up resistors
*/
#define GPIOPUR(x)             ( *(volatile uint32_t*) (GPIO_OFFSET(x) + (0x510)) )

/*
		GPIO Pull-Down Select Register
		Description : Enables pull-down resistors
*/
#define GPIOPDR(x)             ( *(volatile uint32_t*) (GPIO_OFFSET(x) + (0x514)) )

/*
		GPIO Slew Rate Control Select Register
		Description : Configures the slew rate 
*/
#define GPIOSLR(x)             ( *(volatile uint32_t*) (GPIO_OFFSET(x) + (0x518)) )

/*
		GPIO Digital Enable Register
		Description : Enables digital functionality 
*/
#define GPIODEN(x)             ( *(volatile uint32_t*) (GPIO_OFFSET(x) + (0x51C)) )

/*
		GPIO Lock Register
		Description : Locks the configuration of GPIO pins 
*/
#define GPIOLOCK(x)            ( *(volatile uint32_t*) (GPIO_OFFSET(x) + (0x520)) )

/*
		GPIO Commit Register
		Description : Commits the configuration changes to GPIO pins 
*/
#define GPIOCR(x)              ( *(volatile uint32_t*) (GPIO_OFFSET(x) + (0x524)) )

/*
		GPIO Analog Mode Select Register
		Description: Configures GPIO pins for analog mode
*/
#define GPIOAMSEL(x)           ( *(volatile uint32_t*) (GPIO_OFFSET(x) + (0x528)) )


/* 
		GPIO RUN MODE GATING CONTROL REGISTER
		Description : Used to control the clock gating for the GPIO
*/ 
#define RCGCGPIO_REG               ( *(volatile uint32_t*) (0x400FE608) )

#endif