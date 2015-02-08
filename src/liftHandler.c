#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Hubs,  S3, HTServo,  none,     none,     none)
#pragma config(Hubs,  S4, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     ,               sensorI2CMuxController)
#pragma config(Sensor, S4,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     rightWheel1,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     rightWheel2,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     leftWheel1,    tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C1_2,     leftWheel2,    tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S4_C1_1,     lift,             tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C1_2,     kjg,           tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S3_C1_1,    front,                tServoStandard)
#pragma config(Servo,  srvo_S3_C1_2,    back,                 tServoStandard)
#pragma config(Servo,  srvo_S3_C1_3,    lift1,                tServoStandard)
#pragma config(Servo,  srvo_S3_C1_4,    lift2,                tServoStandard)
#pragma config(Servo,  srvo_S3_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_6,    servo6,               tServoNone)
#include "JoystickDriver.c"

#define rpcm 11.25 //the number of rotations that it takes to move the lift 1 meter

int currentHeight;
void resetEncoders(){
	nMotorEncoder[lift] = 0;
}//resets motor encoders

void liftHandler (int heightTarget)//param is the desired height in cm
{
	int heightDif=0;
	if(currentHeight>heightTarget){
	heightDif=currentHeight-heightTarget;
	}
	if(currentHeight<heightTarget){
	heightDif= -(currentHeight-heightTarget);
	}
	bool runRest = true;
	if(currentHeight==heightTarget){
	//this means it is tryinng to go to where it already thinks it is, this is bad
	runRest  = false;
	}
	if (runRest) {
		int rotations=heightDif/rpcm;
		motor[lift]=100;
		nMotorEncoder[lift]=rotations;
		motor[lift]=0;
	}
}
task main(){
	liftHandler(60); // change to desired value after lift is built
}
