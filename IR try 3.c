int Maximum(tIntArray &array)             // This function returns the index of the maximum value in the inner-sensor array.
{
  int maxValue;
  int maxIndex;
  int i;

  maxIndex = 0;                                 // Set 'maxIndex' to 0.
  maxValue = array.arr[maxIndex];               // Set 'maxValue' to be the first sensor of the IR Seeker.

  for(i=1; i<5; i++)                            /* This for-loop cycles between the numbers 1 trough 4 [inclusive].          */
  {                                             /* Those numbers correspond to the internal sensors within the IR Seeker.    */
    if(array.arr[i] > maxValue)                 /* This loop compares each sensor to find the one with the strongest signal. */
    {
      maxValue = array.arr[i];
      maxIndex = i;
    }
  }
  return maxIndex;                              /* Return the index containing the maximum value.           */
}                                               /* (Returns which internal sensor has the highest reading.) */

task main()
{
	tIntArray sensorValue;
	int max=2;
	while(1){
		max= Maximum(sensirValue);
	}
//http://www.education.rec.ri.cmu.edu/downloads/lego/resources/robotc/IR%20Ball%20Chaser.c     from this place
}
