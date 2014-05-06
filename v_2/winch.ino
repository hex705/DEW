
// get height is a winch activity
  
  int getHeight() {
    
    int h = winchDepth;
    
    // need the real method here
    
    return h;
  }
  
  
void moveWinch ( int wDirection, int howFar, int winchSpeed ) {
  
  String db = "movewinch " + wDIrection + " " + winchSpeed;
  if (DEBUG) Serial.print(db);
  // stop switch on pin 2
   winch->setSpeed(winchSpeed);  
   winch->run(wDirection);
    delay(howFar);
   winch->run(RELEASE);
}
    
  
void lowerWinch() {  
  lowerWinch ( 255 , 10 );
}

void lowerWinch(int howFar ) {
   moveWinch (BACKWARD, 150, howFar); 
}

void lowerWinch(  int howFar, int mSpeed ) {
   moveWinch(BACKWARD, howFar, mSpeed);
}


void raiseWinch() {  
  raiseWinch ( 255 , 10 );
}

void raiseWinch(int howFar, int mSpeed) {
  moveWinch(FORWARD, howFar, mSpeed);
}


void resetWinch(){
  
  int atTop = digitalRead( winchStopPin );
  
  while ( !atTop ){
    
    raiseWinch(10, 150);
    atTop = digitalRead( winchStopPin );
    
  }
  
  winch->run(RELEASE);
  lowerWinch(250);
  
  winchDepth = 0;
  
  
}
