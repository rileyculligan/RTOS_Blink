/******************************************************************************
 * @file     Main.c
 * @brief    Uses a system timer to toggle the  ports P0.0, P0.1, P0.6,  P0.7,  P0.8 and P0.9 with
 * 			 a frequency depending on the analog value of P2.5.
 *			 LEDs that are connected to these ports will toggle respectively.
 * 			 In addition it uses the UART of USIC Channel 1 to send a message every 2s to a terminal
 *		     emulator. The communication settings are 57.6kbps/8N1
 *			 P1.3 is configured as input (RXD) and P1.2 is configured as output(TXD)
 *			 This project runs without modifications on the XMC1300 boot kit
 * @version  V1.0
 * @date     20 February 2015
 * @note
 * Copyright (C) 2015 Infineon Technologies AG. All rights reserved.
 ******************************************************************************
 * @par
 * Infineon Technologies AG (Infineon) is supplying this software for use with
 * Infineon�s microcontrollers.
 * This file can be freely distributed within development tools that are
 * supporting such microcontrollers.
 * @par
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *****************************************************************************/

/*****************************************************************************
 *          Includes and Defines
 */
/*      Includes    */
#include <string.h>
#include "XMC1300.h"
// FreeRTOS Includes
#include "FreeRTOS.h"
#include "task.h"
#include "portmacro.h"
#include "semphr.h"
//#include "queue.h"
//#include "StackMacros.h"
//#include "port.c"
//#include "list.h"
//#include "mpu_wrappers.h"
//#include "heap_1.c"

/*      Defines     */
#define LED1 P0_0
#define LED1_OFFSET 0
#define GPIO_PUSHPULL 0b10000
/*****************************************************************************
 * 			Function Prototypes
 */
//Tasks
void LEDTask(void * pvParameters);

/*****************************************************************************
 * 			Function Definitions
 */
/****************** LEDTask()
 * Description:		Initializes LEDs and blinks them at 2 Hz
 * Parameters:		none
 * Return:			none
 * Date Created:	10/6/2017 - Riley Culligan
 */
void LEDTask( void * pvParameters )
{
    /* Initialise P0.0 as an output pin */
    //XMC_GPIO_Init(LED1, &gpio_output_config);
    PORT0->OMR = 1 << LED1_OFFSET;			//Sets LED1 off at first
	PORT0->IOCR0 |= GPIO_PUSHPULL << 3;		//Inits LED1 as pushpull

	while(1)
	{
	    PORT0->OMR = (0b1 << LED1_OFFSET) + (0b1 << (LED1_OFFSET + 16));
	    vTaskDelay(250);
	}
}

/*****************************************************************************
 * 			Main
 */
int main(void)
{
	xTaskCreate(LEDTask, "LED", 128, NULL, 1, NULL);

	vTaskStartScheduler();
	//Never reach this point
	while(1);
}


