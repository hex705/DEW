
// get height is a winch activity
  
  int getHeight() {
    
    int h = winchDepth;
    
    // need the real method here
    
    return h;
  }
  
  
void moveWinch ( int wDirection, int howFar, int winchSpeed ) {
  

  if (DEBUG) Serial.print("winch move");
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
   moveWinch (BACKWARD, howFar, 150); 
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
  Serial.println("start reset");
  int atTop = digitalRead( winchStopPin );
  
  while ( !atTop ){
    Serial.println("looping");
    raiseWinch(10, 150);
    atTop = digitalRead( winchStopPin );
    
  }
  Serial.println("done");
  winch->run(RELEASE);
  lowerWinch(150,100);
  Serial.println("lowered");
  
  winchDepth = 0;
  
  
}
