#pragma config(Hubs,  S4, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S4,     Infrared,       sensorNone)
#pragma config(Motor,  mtr_S4_C1_1,     right,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C1_2,     left,          tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S4_C2_1,    arm1,                 tServoStandard)
#pragma config(Servo,  srvo_S4_C2_2,    arm2,                 tServoStandard)
#pragma config(Servo,  srvo_S4_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S4_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S4_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S4_C2_6,    servo6,               tServoNone)

#define power 100


//Distances to remember:
//72 inches from parking zone to kickstand in zone 1
//61 inches from parking zone to kickstand in zone 2
//60 inches from parking zone to kickstand in zone 3
/*
allows us to change the amount of time that we wait before autonomous starts
*/
void initializeRobot()
{
	//mandatory stuff

	return;
}
//this code allows the user to set how long the robot waits to start to drive.
// because of this, we can make sure that we don't run into our partner robot
void setWaitTime()
{
	int waitTime = 0;
	while ( nNxtButtonPressed == 3 ){//stop the loop when the orange button is pressed.
		nxtDisplayCenteredBigTextLine(2, "The robot will wait for:" );//displays the amount of time the robot will wait before starting
		nxtDisplayCenteredBigTextLine(3,"%d" ,waitTime*500);//
		nxtDisplayCenteredBigTextLine(4, "Milliseconds");
		if((nNxtButtonPressed == 1) && (waitTime < 51)) //if the left button is pressed, increment up by 1
		{
			waitTime++;
		}
		if( (nNxtButtonPressed == 2) && (waitTime > 0) ) //if the right button is pressed, increment down by 1
		{
			waitTime--;
		}
	}
}

void stopMotors() //stops motor drive
{
	motor[right]=0;
	motor[left]=0;
}
void driveMotors(int n1,int time)//drives forward for a power of 'N1' for time of 'time'
{
	motor[right] =	n1;
	motor[left] = n1;
	wait1Msec(time);
	stopMotors();
}
void turnMotors(int rightpower, int leftpower, int time) //turn the robot, by spinning motors for 'time' at varying power
{
	motor[right] = rightpower;
	motor[left] = leftpower;
	wait1Msec(time);
	stopMotors(); //stops drive
}
task main()
{
	int arthursadvice = 720;
	//initalizeRobot();
	driveMotors(100,arthursadvice); //drive forward at full power for .72 seconds
	stopMotors(); //stops drivng
	turnMotors (0, 100, 500); //turns left
	driveMotors(100, arthursadvice); //goes forward
	while(true) { //forever
		turnMotors (100, 0, 500); //turns right
		driveMotors(100,250); //goes forward
	} //repeats

}
