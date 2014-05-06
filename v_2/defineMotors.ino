void defineMotors () {
  
  // Set the speed to start, from 0 (off) to 255 (max speed)
  paper1->setSpeed(150);
  paper1->run(FORWARD);
  // turn on motor
  paper1->run(RELEASE);
  
    // Set the speed to start, from 0 (off) to 255 (max speed)
  paper2->setSpeed(150);
  paper2->run(FORWARD);
  // turn on motor
  paper2->run(RELEASE);
  
      // Set the speed to start, from 0 (off) to 255 (max speed)
      

  winch->setSpeed(150);
  winch->run(FORWARD);
  // turn on motor
  winch ->run(RELEASE);
  
}
