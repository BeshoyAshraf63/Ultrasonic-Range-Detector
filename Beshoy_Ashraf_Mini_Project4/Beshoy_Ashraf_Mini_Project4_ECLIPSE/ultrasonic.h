 /******************************************************************************
 *
 * Module: ULTRASONIC
 *
 * File Name: ultrasonic.h
 *
 * Description: header file for the ULTRASONIC driver
 *
 * Author: Beshoy Ashraf
 *
 *******************************************************************************/



#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "std_types.h"


/*******************************************************************************
 *                               Definitions                                   *
 *******************************************************************************/
#define ULTRASONIC_TRIGGER_PORT_ID    PORTB_ID
#define ULTRASONIC_TRIGGER_PIN_ID     PIN5_ID

#define ULTRASONIC_ECHO_PORT_ID       PORTD_ID
#define ULTRASONIC_ECHO_PIN_ID        PIN6_ID

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description : Function to initialize the Ultrasonic
 * 	1. Start ICU module:
 * 	 Set the required edge detection.
 * 	 Enable the Input Capture Interrupt.
 * 	 Initialize Timer1 Registers
 * 	2. Setup pins used for trigger and echo in MC.
 */
void Ultrasonic_init(void);

/*
 * Description :
 *  Function to send Trigger pulse to Ultra-sonic:
 *  by writing logic high- delay- logic low to the trigger pin.
 */
void Ultrasonic_Trigger(void);

/*
 * Description :
 *  Function to calculate distance of object away from Ultrasonic sensor:
 *  Uses Ultrasonic_Trigger() function to send signal.
 *  Uses g_high_time calculated by Ultrasonic_edgeProcessing() function.
 *  Then calculates the total distance by the eqn (g_high_time) / 58.8.
 */
uint16 Ultrasonic_readDistance(void);

/*
 * Description :
 *  Function to calculate high time (pulse) generated by Ultrasonic sensor:
 */
void Ultrasonic_edgeProcessing(void);


#endif /* ULTRASONIC_H_ */
