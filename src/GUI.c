#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Hubs,  S3, HTServo,  none,     none,     none)
#pragma config(Hubs,  S4, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     ,               sensorI2CMuxController)
#pragma config(Sensor, S4,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     rightWheel1,   tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     rightWheel2,   tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C1_1,     leftWheel1,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     leftWheel2,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C1_1,     h,             tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C1_2,     kjg,           tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S3_C1_1,    front,                tServoStandard)
#pragma config(Servo,  srvo_S3_C1_2,    back,                 tServoStandard)
#pragma config(Servo,  srvo_S3_C1_3,    lift1,                tServoStandard)
#pragma config(Servo,  srvo_S3_C1_4,    lift2,                tServoStandard)
#pragma config(Servo,  srvo_S3_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_6,    servo6,               tServoNone)

#define kExitButton 0
#define kRightButton 1
#define kLeftButton 2
#define kEnterButton 3
task main(){
	int startWait = 1;
	bool kickstand = true;
	int kickTime = 15;
	bool check = false;
	int spot = 4;
	while(check == false) {
		nxtDisplayCenteredTextLine(1, "-----LASA5998----");
		nxtDisplayCenteredTextLine(2, "-Pick Autonomous-");
		nxtDisplayCenteredTextLine(3, "--------------------");
		nxtDisplayTextLine(4, "> StartWait: %d  <", startWait);
		nxtDisplayTextLine(5, "> Kickstand: %d  <", kickstand);
		nxtDisplayTextLine(6, "> Kick Time:  %d <", kickTime);
		nxtDisplayTextLine(7, "_________________");
		nxtDisplayTextLine(8, "_________________");
		if (nNxtButtonPressed ==  kRightButton) { /* Right Button  */
			if (spot == 4 && startWait < 10) {
				startWait++;
			}
			if (spot == 5){
				kickstand = !kickstand;
			}
			if(spot == 6 && kickTime < 28){
				kickTime++;
			}
		}
		if( nNxtButtonPressed == kLeftButton) { /* Left Button  */
			if(spot == 4 && startWait > 1){
				startWait--;
			}
			if(spot == 5){
				kickstand = !kickstand;
			}
			if(spot == 6 && kickTime > 15){
				kickTime--;
			}
		}
		if( (nNxtButtonPressed == kEnterButton) && spot != 6 ) { // Middle Button
			spot++;
		}
		if( (nNxtButtonPressed == kEnterButton) && spot == 6) { // Middle Button
			check = true;
		}
		wait1Msec(20);
	}
	while(check == true){
		nxtDisplayTextLine(1, "-----LASA5998----");
		nxtDisplayTextLine(2, "-Pick Autonomous-");
		nxtDisplayTextLine(3, "_________________");
		nxtDisplayTextLine(4, "> StartWait: %d  <", startWait);
		nxtDisplayTextLine(5, "> Kickstand: %d  <", kickstand);
		nxtDisplayTextLine(6, "> Kick Time:  %d <", kickTime);
		nxtDisplayCenteredTextLine(7, " -- Press Orange --");
		nxtDisplayCenteredTextLine(8, " -- to Confirm -- ");
		while(nNxtButtonPressed == false){ /*Center Button*/
			wait1Msec(20);
		}
	}
}
