/******************************************************************************
 *
 * Module: DC MOTOR
 *
 * File Name: motor.h
 *
 * Description: Header file for the DC MOTOR driver
 *
 * Author: Omar Elsehity
 *
 *******************************************************************************/

#ifndef MOTOR_H_
#define MOTOR_H_
#include "gpio.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define MOTOR_PORT PORTB_ID
#define MOTOR_PIN1 PIN0_ID
#define MOTOR_PIN2 PIN1_ID

/*enum for motor state*/
typedef enum{
	STOP,CW,ACW
}DcMotor_State;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the DC Motor driver.
 */
void DcMotor_Init(void);
/*
 * Description :
 * Function responsible for State the DC Motor driver.
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* MOTOR_H_ */
