
#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Hubs,  S2, HTServo,  none,     none,     none)
#pragma config(Hubs,  S3, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     lift1,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     rightWheel,    tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     motorF,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     motorH,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorI,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C1_1,     leftWheel,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C1_2,     motorK,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C2_1,     intake,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C2_2,     lift2,         tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C4_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    servo2,               tServoStandard)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_1,    claw,                 tServoStandard)
#pragma config(Servo,  srvo_S2_C1_2,    servo8,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_3,    servo9,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_4,    servo10,              tServoNone)
#pragma config(Servo,  srvo_S2_C1_5,    servo11,              tServoNone)
#pragma config(Servo,  srvo_S2_C1_6,    servo12,              tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
index of motor names:
leftWheel
rightWheel
intake
motorG
lift1
lift2
clawLeft
clawRight
servo3
servo4
servo5
servo6
*/

/************************************************************************\
| Index of Buttons and Uses																							 |
| 1: Claw Up																														 |
| 2: Intake Out																													 |
| 3: Claw Down																													 |
| 4: Intake In																													 |
| 5: Lift Up																														 |
| 6: modifier set to 5 (overrides Button 8)															 |
| 7: Lift Down																													 |
| 8: Modifier set to 10																									 |
| Joystick 1: Controls the Left Wheel																		 |
| Joystick 2: Controls the Right Wheel																	 |
\************************************************************************/

#define clawDown 250
#define clawUp 125
#define inSpeed 50
#define threshold 0

//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                           Tele-Operation Mode Code Template
//3
// This file contains a template for simplified creation of an tele-op program for an FTC
// competition.
//
// You need to customize two functions with code unique to your specific robot.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                    initializeRobot
//
// Prior to the start of tele-op mode, you may want to perform some initialization on your robot
// and the variables within your program.
//
// In most cases, you may not have to add any code to this function and it will remain "empty".
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void initializeRobot()
{
  // Place code here to sinitialize servos to starting positions.
  // Sensors are automatically configured and setup by ROBOTC. They may need a brief time to stabilize.

  return;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                         Main Task
//
// The following is the main code for the tele-op robot operation. Customize as appropriate for
// your specific robot.
//
// Game controller / joystick information is sent periodically (about every 50 milliseconds) from
// the FMS (Field Management System) to the robot. Most tele-op programs will follow the following
// logic:
//   1. Loop forever repeating the following actions:
//   2. Get the latest game controller / joystick settings that have been received from the PC.
//   3. Perform appropriate actions based on the joystick + buttons settings. This is usually a
//      simple action:
//      *  Joystick values are usually directly translated into power levels for a motor or
//         position of a servo.
//      *  Buttons are usually used to start/stop a motor or cause a servo to move to a specific
//         position.
//   4. Repeat the loop.
//
// Your program needs to continuously loop because you need to continuously respond to changes in
// the game controller settings.
//
// At the end of the tele-op period, the FMS will autonmatically abort (stop) execution of the program.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

task main()
{
  initializeRobot();

  //waitForStart();   // wait for start of tele-op phase

  while (true)
  { //it constantly runs whatever is in here

	getJoystickSettings(joystick); //gets joystick input
	 int modifier = 5;//set modifier variable
	if(joy1Btn(6))
	{ //This creates a modifier variable. When the assistant driver presses the upper right trigger,
		//the robot goes at a fifth of it's normal power
		modifier = 1;
	}
	else if(joy1Btn(8))
	{ //if button 8 is pressed, modifier is set to 10
		modifier = 20;
	}
	else
	{//if the buttons 6 and 8 aren't pressed, the robot goes back to driving at full power.
		modifier =5;
	}
	if( abs(joystick.joy1_y1) > 10){
		motor[leftWheel] = (joystick.joy1_y1 / modifier); //reads joystick values on joystick one.
	}
	else
	{
		motor[leftWheel] = 0;
	}
	if( abs(joystick.joy1_y2) > 10)
	{
		motor[rightWheel] = (joystick.joy1_y2 / modifier); //the 'y'(up and down) axis values set the power.
	}
	else
	{
		motor[rightWheel] = 0;
	}

	//the below code will swing the claw to the down position.
	if(joy1Btn(3))
	{
		servo[claw] = clawDown;
	}
	//the below code will swing the claw to the up position.
	else if(joy1Btn(1)) {
		servo[claw] = clawUp;
	}
	//this will move the rollers to pushing the balls into the robot's control.
	if(joy1Btn(4))
	{
		motor[intake]	= inSpeed;
	}
	else if(joy1Btn(2)) //this will spin backward in case it gets jammed.
	{
		motor[intake] = -inSpeed;
	}
	else
	{
	motor[intake] = 0;
	}

	//make sure that "0" is up and "90" is down.
	if( joy1Btn(5) )
	{
		motor[lift1] = 75;
		motor[lift2] = 75;
	}
	else if ( joy1Btn(7) )
	{
		motor[lift1] = -75;
		motor[lift2] = -75;
	}
	else
	{
		motor[lift1] = 0;
		motor[lift2] = 0;
	}
	//JOY 2 JOY 2 JOY 2 JOY 2 JOY 2 JOY 2 JOY 2 JOY 2 JOY 2 JOY 2 JOY 2 JOY 2 JOY 2 JOY 2 JOY 2 JOY 2 JOY 2 JOY 2 JOY 2 JOY 2 JOY 2 JOY 2 JOY 2 JOY 2 JOY 2 JOY 2 JOY 2 JOY 2 JOY 2 JOY 2 JOY 2 JOY 2 JOY 2
	//for the operator
	if(joy2Btn(1)){
		servo[claw] = clawUp;
		}
	else if(joy2Btn(3)){
		servo[claw]=clawDown;
	}
	if(joy2Btn(4)){
		PlaySound(soundBeepBeep);
		}
	if (joy2Btn(2)){
		PlaySound(soundBlip);
	}
	//6is expander up, 8 is down`
/*	if()
		while(true){
motor[]= random[12];
	}
}
*/

//this is to raise the scissor lift
	//motor[NAME]=100;
	//wait1Msec(100);
	//motor[NAME]=0;
	}
//}//is this the while loop?
//teh last 2 are well you know, off limits
	}
//}
