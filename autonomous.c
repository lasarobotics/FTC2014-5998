#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Hubs,  S3, HTServo,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     ,               sensorI2CMuxController)
#pragma config(Sensor, S4,     ir,             sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  mtr_S1_C1_1,     rightWheel1,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     rightWheel2,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     leftWheel1,    tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C1_2,     leftWheel2,    tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S3_C2_1,     Infeed,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C2_2,     Pulley,        tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Servo,  srvo_S3_C1_1,    front,                tServoStandard)
#pragma config(Servo,  srvo_S3_C1_2,    back,                 tServoStandard)
#pragma config(Servo,  srvo_S3_C1_3,    lift1,                tServoStandard)
#pragma config(Servo,  srvo_S3_C1_4,    lift2,                tServoStandard)
#pragma config(Servo,  srvo_S3_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/**********************************************************************************************\
| Functions:
|
| resetEncoders()
|     Resets the read encoder values.
|     This makes sure we don't mess up after turning or at the start of a match
| stopMotors()
|		 Makes it easier to monitor functions. Called Often
| forward(rotations, power)
|		 goes forward for a number of rotations.
|		 automatically aligns after left wheel has travelled far enough
| turnLeft(rotations, power)
|		 turns left for the specified number of rotations.
| turnRight(rotations, power)
|		 turns right for the specified number of rotations.
\**********************************************************************************************/
#define backDown 225
#define backUp 125
#define frontDown 225
#define frontUp 125
#define liftOneUp 250
#define liftTwoUp 0
#define liftOneDown 0
#define liftTwoDown 250
void showStatus(int rotations, int power){
		nxtDisplayTextLine(1, "Power: %d", power);
		nxtDisplayTextLine(2, "rotations: %d",rotations);
		nxtDisplayTextLine(3, "encoders: %d",nMotorEncoder[leftWheel1]);
		nxtDisplayTextLine(4, "encoders: %d",nMotorEncoder[leftWheel2]);
		nxtDisplayTextLine(5, "encoders: %d",nMotorEncoder[rightWheel1]);
		nxtDisplayTextLine(6, "encoders: %d",nMotorEncoder[rightWheel2]);
}
void armUp(){//this function sets the lift to the top postion
	servo[lift1] = liftOneUp;
	servo[lift2] = liftTwoUp;
}
void armDown(){//this function sets the lift to the down position
	servo[lift1] = liftOneDown;
	servo[lift2] = liftTwoDown;
}
void frontServoUp(){//this moves the front servo to the upright position
	servo[front] = frontUp;
}
void frontServoDown(){//this moves the front servo to the down position
	servo[front] = frontDown;
}
void backServoUp(){//this moves the down servo to the upright position
	servo[back] = backUp;
}
void backServoDown(){//this moves the back servo to the down position
	servo[back] = backDown;
}
void resetEncoders(){//clears all encoders
	nMotorEncoder[leftWheel1] = 0;
	nMotorEncoder[leftWheel2] = 0;
	nMotorEncoder[rightWheel1] = 0;
	nMotorEncoder[rightWheel2] = 0;
	nMotorEncoder[Pulley] = 0;
}//resets motor encoders
void stopMotors(){//this wait for it... stops the motors
	wait1Msec(100);
	motor[rightWheel1] = 0;
	motor[rightWheel2] = 0;
	motor[leftWheel1] = 0;
	motor[leftWheel2] = 0;
	resetEncoders();
}//stops drive

void forward( int rotations, int power ){//this drives forward the desired rotations at the desired power
	resetEncoders(); //Resets the motor encoder readings.
	while( (nMotorEncoder[leftWheel1] < rotations) && (nMotorEncoder[rightWheel1] < rotations) && (nMotorEncoder[leftWheel2]) < rotations && (nMotorEncoder[rightWheel2] < rotations)){
		showStatus(rotations, power);
		motor[leftWheel1] = power;
		motor[rightWheel1] = power;
		motor[leftWheel2] = power;
		motor[rightWheel2] = power;
	}//goes forward until one of the two sides has rotated enough
	stopMotors();

	if( ( nMotorEncoder[leftWheel1] + nMotorEncoder[leftWheel2] ) - ( nMotorEncoder[rightWheel1] + nMotorEncoder[rightWheel2] ) > 100){
		//if shifted to face left
		while( nMotorEncoder[leftWheel1] - nMotorEncoder[rightWheel1] > 0 ){
			motor[rightWheel1] = power / 5;//turns to be straight
		}
			stopMotors();
			resetEncoders();
			return;
	}
	if( ( nMotorEncoder[rightWheel1] + nMotorEncoder[rightWheel2] ) - ( nMotorEncoder[leftWheel1] + nMotorEncoder[leftWheel2] ) > 100 ){
		//if shifted to face right
		while( nMotorEncoder[rightWheel1] - nMotorEncoder[leftWheel1] > 0 ){
			motor[leftWheel1] = power/5;//turns to be straight
		}
	}

	stopMotors();
	resetEncoders();
}//forward function


void backwards(int rotations, int power){
	resetEncoders(); //Resets the motor encoder readings.
	while( (abs(nMotorEncoder[leftWheel1]) < rotations) || (abs(nMotorEncoder[rightWheel1]) < rotations) || (abs(nMotorEncoder[leftWheel2]) < rotations) || (abs(nMotorEncoder[rightWheel2]) < rotations)){
		showStatus(rotations, power);
		motor[leftWheel1] = -power;
		motor[rightWheel1] = -power;
		motor[leftWheel2] = -power;
		motor[rightWheel2] = -power;
	}//goes forward until one of the two sides has rotated enough
	stopMotors();

	if( abs(( nMotorEncoder[leftWheel1] + nMotorEncoder[leftWheel2] ) - ( nMotorEncoder[rightWheel1] + nMotorEncoder[rightWheel2] )) > 100){
		//if shifted to face left
		while( nMotorEncoder[leftWheel1] - nMotorEncoder[rightWheel1] > 0 ){
			motor[rightWheel1] = -power / 5;//turns to be straight
		}
			stopMotors();
			resetEncoders();
	}
	if( abs(( nMotorEncoder[rightWheel1] + nMotorEncoder[rightWheel2] ) - ( nMotorEncoder[leftWheel1] + nMotorEncoder[leftWheel2] )) > 100 ){
		//if shifted to face right
		while( nMotorEncoder[rightWheel1] - nMotorEncoder[leftWheel1] > 0 ){
			motor[leftWheel1] = -power/5;//turns to be straight
		}
	}
	stopMotors();
	resetEncoders();
}
void turnLeft(int rotations, int power){
	resetEncoders();//resets encoders
	while( (nMotorEncoder[rightWheel2] < rotations) && abs(nMotorEncoder[leftWheel2]) < rotations ){
		showStatus(rotations, power);
		motor[rightWheel2] = power;
		motor[rightWheel1] = power;
		motor[leftWheel2] = 0;
		motor[leftWheel1] = 0;
 	}
 	stopMotors();
 	return;
}//turns left

void turnRight(int rotations, int power){
	resetEncoders();//resets encoders
	while( (nMotorEncoder[leftWheel2] < rotations) && abs(nMotorEncoder[rightWheel2]) < rotations ){
		showStatus(rotations, power);
		motor[rightWheel2] = 0;
		motor[rightWheel1] = 0;
		motor[leftWheel2] = power;
		motor[leftWheel1] = power;
 	}
 	stopMotors();
 	return;
 }//turns right
void initializeRobot()
{
 	armUp();
 	frontServoUp();
	backServoUp();
	return;
}

//Start of Auto















task main()
{
	//waitForStart(); //waits for Start Command From FCS
		while(nMotorEncoder[Pulley] < 28200){
			motor[Pulley] = 90;
		}
		motor[Pulley] = 0;
	ClearTimer(T1);
	int zone;
  wait1Msec(500);
	nxtDisplayCenteredTextLine(3, "IR Value: %d", SensorValue[ir]);
 	wait10Msec(50);
 	if(SensorValue[ir] == 3 || SensorValue[ir] == 0){
 		zone = 1;
	}
	else if(SensorValue[ir] == 4){
		zone = 2;
	}
	else if(SensorValue[ir] == 5){
		zone = 3;
	}
	else{
		zone = 0;
	}
	initializeRobot();

	if( zone == 3){
		forward(500, 20);
		turnRight(350, 20);
		forward(2600, 20);
		turnLeft(350, 20);
		forward(20, 20);
		PlaySound(soundBeepBeep);
		wait1Msec(10000);
	}
	if( zone == 2){
		forward(250, 20);
		turnLeft(800, 20);
		forward(1050, 20);
		turnRight(1820, 20);
		forward(1700, 20);
		PlaySound(soundBeepBeep);
		wait1Msec(1000);
	}
	if( zone == 1 ){
		forward(250, 20);
		turnLeft(1200, 20);
		forward(900, 20);
		turnRight(1400, 20);
		forward(3000, 20);
		PlaySound(soundBeepBeep);
		wait1Msec(1000);
	}
	/*
		backwards(500, 20);
		turnRight(550, 20);
		if (zone != 1){
			forward(1500, 20);
		} else {
			forward(750, 20);
		}
		turnLeft(50, 20);
		forward(800, 20);
		PlaySound(soundBeepBeep);
		wait1Msec(1000);
	*/
}
