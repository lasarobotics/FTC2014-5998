#pragma config(Hubs,  S3, HTServo,  HTMotor,  none,     none)
#pragma config(Sensor, S3,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S3_C2_1,     JesusPull,   tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S3_C2_2,  		JesusPulley,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S3_C1_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


task main()
{
	int power = 0;
	nMotorEncoder[JesusPulley] = 0;

	while(nMotorEncoder[JesusPulley] < 28200 ){ motor[JesusPulley] = 50; }
}
