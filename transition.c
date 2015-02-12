
void speedTransition(int currentSpeed, int newSpeed, int motorPow) {
    //Declares variables used in the process
    int diff;
    int diffProg;
    //Checks if speed is increasing, transitions speed upwards if true
    if (newSpeed > currentSpeed) {
      //Sets increment variable values
      diff = newSpeed - currentSpeed;
      diffProg = 0;
      while (diffProg < diff) {
        //Progresses the speed variables
        currentSpeed+=1;
        diffProg+=1;
        //Applies speed increment to motor
        motorPow=currentSpeed;
        //Waits to up speed after time increment
        wait1Msec(10); // .01 seconds
      }
    }

    //Checks if speed is decreasing, transitions speed downwards if true
    else if (newSpeed < currentSpeed) {
      //Sets increment variable values
        diff = currentSpeed - newSpeed;
        diffProg = diff;
        while (diffProg > 0) {
          //Progesses the speed variables
          currentSpeed-=1;
          diffProg-=1;
          //Applies new speed increment to motor
          motorPow = currentSpeed;
          //Waits to down speed after time increment
          wait1Msec(10); // .01 Seconds
        }
    }
}




/*
    Tester Code
*/

task main() {
  //Takes robot from stopped to 60% power in ~0.6 seconds
  //Currently works only in a  stright line, all-wheel drive
  speedTransition( 0, 60 );
}
