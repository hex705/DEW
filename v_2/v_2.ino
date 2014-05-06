// motor test VEX

// the motors are basic motors with no feedback.
//so if the run in parallel or at same time all ok.
//steppers would be better.


// using lady ada motor shield for these tests.



/* 
This is a test sketch for the Adafruit assembled Motor Shield for Arduino v2
It won't work with v1.x motor shields! Only for the v2's with built in PWM
control

For use with the Adafruit Motor Shield v2 
---->	http://www.adafruit.com/products/1438
*/

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *winch = AFMS.getMotor(3);
Adafruit_DCMotor *paper1 = AFMS.getMotor(4);
// You can also make another motor on port M2
Adafruit_DCMotor *paper2 = AFMS.getMotor(1);


#define winchStopPin 2
boolean DEBUG = true;

int winchDepth = 0;


void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
  defineMotors();
  pinMode ( winchStopPin, INPUT);
  
  
}

void loop() {
  uint8_t i;
  
  resetWinch();
  
  
  Serial.print("tick");

  currentHeight = getHeight();
  advancePaper();
  

  paper1->run(FORWARD);
  paper2->run(FORWARD);
  
  
  for (i=0; i<255; i++) {
    paper1->setSpeed(i);  
    paper2->setSpeed(i); 
    delay(10);
  }
  for (i=255; i!=0; i--) {
    paper1->setSpeed(i);
    paper2->setSpeed(i);   
    delay(10);
  }
  
  Serial.print("tock");

  paper1->run(BACKWARD);
  paper2->run(BACKWARD); 
  for (i=0; i<255; i++) {
    paper1->setSpeed(i); 
    paper2->setSpeed(i);  
    delay(10);
  }
  for (i=255; i!=0; i--) {
    paper1->setSpeed(i); 
    paper2->setSpeed(i);  
    delay(10);
  }

  Serial.println("tech");
  paper1->run(RELEASE);
  paper2->setSpeed(i); 
  delay(1000);
}
