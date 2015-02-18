#pragma config(Hubs,  S3, HTServo,  HTMotor,  none,     none)
#pragma config(Sensor, S3,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S3_C2_1,     motorD,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C2_2,     Pulley,        tmotorTetrix, openLoop, encoder)
#pragma config(Servo,  srvo_S3_C1_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	int pos = 15 * 1000;
	while(true){
		eraseDisplay();
		nxtDisplayCenteredTextLine(3, "Pos:%d",pos);//shows power and encoder value (rotations)
		nxtDisplayCenteredTextLine(7, "+50 || +200 || +500");
		wait1Msec(200);
		//allows the user to move the lift based on button pushes
		if(nNxtButtonPressed == 1){ pos += 200; }
		if(nNxtButtonPressed == 2){ pos += 500; }
		if(nNxtButtonPressed == 3){ pos += 1000; }

		if( nMotorEncoder[Pulley] < pos){
			motor[Pulley] = 50;
			} else {
			motor[Pulley] = 0;
		}
	}



}