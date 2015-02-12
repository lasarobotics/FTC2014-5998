int startWait = 1;
int selection = 4;
int kickTime = 15;
bool kickstand = true;
bool cont = false;


task main(){
	while(selection != 7){
		eraseDisplay();
		nxtDisplayCenteredTextLine(0, "+--------------+");
		nxtDisplayCenteredTextLine(1, "|  LASA 5998   |");
		nxtDisplayCenteredTextLine(2, "|PickAutonomous|");
		nxtDisplayCenteredTextLine(3, "+--------------+");
		if(selection == 4){
			nxtDisplayCenteredTextLine(4, "->StartWait: %d  ", startWait);
		} else {
			nxtDisplayCenteredTextLine(4, "StartWait: %d  ", startWait);
		}
		if(selection == 5){
			if(kickstand == true){
				nxtDisplayCenteredTextLine(5, "->Kickstand: Yes");
			}else{
				nxtDisplayCenteredTextLine(5, "->Kickstand: No");
			}
		} else {
			if(kickstand == true){
				nxtDisplayCenteredTextLine(5, "Kickstand: Yes");
			}else{
				nxtDisplayCenteredTextLine(5, "Kickstand: No");
			}
		}
		if(selection == 6){
			nxtDisplayCenteredTextLine(6, "->KickTime:%d ", kickTime);
		} else {
			nxtDisplayCenteredTextLine(6, "Kick Time:%d ", kickTime);
		}
		nxtDisplayCenteredTextLine(7, "-----------------------", selection);

		cont = false;
		while(cont == false){
			wait1Msec(200);
			if (nNxtButtonPressed == 2){
				if( (selection == 4) && (startWait > 1) ){
					startWait--;
					cont = true;
				}
				if(selection == 5){
					kickstand = !kickstand;
					cont = true;
				}
				if( (selection == 6) && (kickTime > 15)){
					kickTime--;
					cont = true;
				}
			}
			if(nNxtButtonPressed == 1){
				if( (selection == 4) && (startWait < 10) ){
					cont = true;
					startWait++;
				}
				if(selection == 5){
					kickstand = !kickstand;
					cont = true;
				}
				if( (selection == 6) && (kickTime < 27)){
					kickTime++;
					cont = true;				
				}
			}
			if(nNxtButtonPressed == 3){
				selection++;
				cont = true;
			}
		}
	}
}
