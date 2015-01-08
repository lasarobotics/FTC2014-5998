int leftWheel1;
int leftWheel2;

int rightWheel1;
int rightWheel2;

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

//Need to fix variables. Free trial doesn't allow tool use.
void resetEncoders(){
	nMotorEncoder[leftWheel1] = 0;
	nMotorEncoder[leftWheel2] = 0;
	nMotorEncoder[rightWheel1] = 0;
	nMotorEncoder[rightWheel2] = 0;
}//resets motor encoders

void stopMotors(){
	wait1Msec(100);
	motor[rightWheel1] = 0;
	motor[rightWheel2] = 0;
	motor[leftWheel1] = 0;
	motor[leftWheel2] = 0;
	resetEncoders();
}//stops drive

void forward( int rotations, int power ){
	resetEncoders();
	//Resets the motor encoder readings.
	while( nMotorEncoder[leftWheel1] != rotations ){
		motor[leftWheel1] = power;
		motor[rightWheel1] = power;
	}//goes forward until one of the two sides has rotated enough
	if( ( nMotorEncoder[leftWheel1] + nMotorEncoder[leftWheel2] ) - ( nMotorEncoder[rightWheel1] + nMotorEncoder[rightWheel2] ) > 10){
		//if shifted to face left
		while( nMotorEncoder[leftWheel1] + nMotorEncoder[leftWheel2] != nMotorEncoder[rightWheel1] + nMotorEncoder[rightWheel2] ){
			motor[rightWheel1] = power / 5;//turns to be straight
		}
			stopMotors();
			return;
	}
	if( ( nMotorEncoder[rightWheel1] + nMotorEncoder[rightWheel2] ) - ( nMotorEncoder[leftWheel1] + nMotorEncoder[leftWheel2] ) > 10 ){
		//if shifted to face right
		while( nMotorEncoder[rightWheel1] != nMotorEncoder[leftWheel1] ){
			motor[leftWheel1] = 20;//turns to be straight
		}
			stopMotors();
			return;
	}
}//forward function

void turnLeft(int rotations, int power){
	resetEncoders();//resets encoders
	while(nMotorEncoder[rightWheel1] != rotations){
		motor[rightWheel1] = power;
		motor[leftWheel1] = -power;
 	}
 	stopMotors();
 	return;
}//turns left

void turnRight(int rotations, int power){
	resetEncoders();//resets encoders
	while(nMotorEncoder[leftWheel1] != rotations){
		motor[leftWheel1] = power;
		motor[rightWheel1] = -power;
 	}
 	stopMotors();
 	return;
}//turns right

//Start of Auto
task main()
{
	forward(2500, 100);
	turnLeft(50, 20);
	turnRight(50, 20);
	stopMotors();
}