/******************************************************************************
 *
 * Module: Main Program
 *
 * File Name: Fan_control.c
 *
 * Description: source file for the program code
 *
 * Author: Omar Elsehity
 *
 *******************************************************************************/

#include "adc.h"
#include "lcd.h"
#include "Lm35_sensor.h"
#include "motor.h"
#include "pwm.h"
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*variables to control the program flow*/
uint8 ON_state[] = "FAN IS ON ";
uint8 OFF_state[] = "FAN IS OFF";
uint8 Temp_state[] = "Temp=   C";

/*main Function that runs the code*/
int main(void)
{
	/*variable to store the temperature*/
	uint8 temp;
	/* initialize LCD */
	LCD_init();
	/* ADC configurations */
	ADC_ConfigType ADC_config = {INTERNAL_VOLTAGE, Fadc_8 };
	ADC_init(&ADC_config);
	/* PWM configurations */
	PWM_config PWM_Config = {NON_INVERTING,F_CPU_8};
	PWM_Timer0_init(&PWM_Config);
	/* initialize DC MOTOR driver */
	DcMotor_Init();
	while(1){
		temp=LM35_GetTemperature(); /*get the value from temperature sensor and store it in the temp variable*/
		/*if temperature is less than 30*/
		if(temp < 30){
			DcMotor_Rotate(STOP,0);/*stop the motor & pwm produce no signal*/
			LCD_moveCursor(1,3);/*move the cursor to print the next word in middle*/
			LCD_displayString(OFF_state);
			LCD_moveCursor(2,3);
			LCD_displayString(Temp_state);
			LCD_moveCursor(2,8);
			LCD_intgerToString(temp);/*display the temperature*/
		}
		/*if temperature more than or equal 30 and less than 60*/
		else if(temp>= 30 && temp < 60){
			DcMotor_Rotate(CW,64);/* turn the motor clock wise with speed equal 25% * PWM module (255) total signal*/
			LCD_moveCursor(1,3);
			LCD_displayString(ON_state);
			LCD_moveCursor(2,3);
			LCD_displayString(Temp_state);
			LCD_moveCursor(2,8);
			LCD_intgerToString(temp);
		}
		/*if temperature more than or equal 60 and less than 90*/
		else if(temp>= 60 && temp < 90){
			DcMotor_Rotate(CW,128);/* turn the motor clock wise with speed equal 50% * PWM module (255) total signal*/
			LCD_moveCursor(1,3);
			LCD_displayString(ON_state);
			LCD_moveCursor(2,3);
			LCD_displayString(Temp_state);
			LCD_moveCursor(2,8);
			LCD_intgerToString(temp);
		}
		/*if temperature more than or equal 90 and less than 120*/
		else if(temp>= 90 && temp < 120){
			DcMotor_Rotate(CW,191);/* turn the motor clock wise with speed equal 75% * PWM module (255) total signal*/
			LCD_moveCursor(1,3);
			LCD_displayString(ON_state);
			LCD_moveCursor(2,3);
			LCD_displayString(Temp_state);
			LCD_moveCursor(2,8);
			LCD_intgerToString(temp);
		}
		else {
			DcMotor_Rotate(CW,255);/* turn the motor clock wise with full speed*/
			LCD_moveCursor(1,3);
			LCD_displayString(ON_state);
			LCD_moveCursor(2,3);
			LCD_displayString(Temp_state);
			LCD_moveCursor(2,8);
			LCD_intgerToString(temp);
		}
	}

}
