
//int turntime = degree*turnRatio; //Time the robot spends turning (miliseconds)

String obstacle_str;
String obstacle_sign;
int obstacle_status = B100000;

//this our pause function
void pause(int pauseTime)
 {
  timeElapsed = millis();
  while (millis() < timeElapsed + pauseTime){}
 }

void microPause(int pauseTime)
 {
  timeElapsed = micros();
  while (micros() < timeElapsed + pauseTime){}
 }

//initialize the Servo head and name it something
Servo head;

//===============
/*motor control*/
//==============

//set motor speed 
//this function allows you to specify an integer and then have that integer analog written to a predefined set of pins
void set_Motorspeed(int speed_L,int speed_R)
  {
    analogWrite(speedPinL,speed_L); 
    analogWrite(speedPinR,speed_R);   
  }

//Stop  
void stopStop()    
  {
    digitalWrite(dir1PinL, LOW);
    digitalWrite(dir2PinL,LOW);
    digitalWrite(dir1PinR,LOW);
    digitalWrite(dir2PinR,LOW);
  }

//go forward
void goForward(void)  
  {
    set_Motorspeed(SPEED,SPEED);
    digitalWrite(dir1PinL, HIGH);
    digitalWrite(dir2PinL,LOW);
    digitalWrite(dir1PinR,HIGH);
    digitalWrite(dir2PinR,LOW);
  }
  
//Turn left
void turnLeft(int degree)  
  {
    set_Motorspeed(turnSpeed, turnSpeed);
    digitalWrite(dir1PinL,HIGH);
    digitalWrite(dir2PinL,LOW);
    digitalWrite(dir1PinR,LOW);
    digitalWrite(dir2PinR,HIGH);
    pause(degree*turnRatio);
    stopStop();
  }

//Turn right
void turnRight(int degree)  
  {
    set_Motorspeed(turnSpeed, turnSpeed);
    digitalWrite(dir1PinL,LOW);
    digitalWrite(dir2PinL,HIGH);
    digitalWrite(dir1PinR,HIGH);
    digitalWrite(dir2PinR,LOW);
    pause(degree*turnRatio);
    stopStop();
  }

//Reverse  
//update this so it takes in a number that reflects distance
//code should do the math for the user and will determine the amount of time to pause and let the wheels spin to reach the desired disdtance
void goBack()  
  {
    set_Motorspeed(BACK_SPEED1,BACK_SPEED2);
    digitalWrite(dir1PinL, LOW);
    digitalWrite(dir2PinL,HIGH);
    digitalWrite(dir1PinR,LOW);
    digitalWrite(dir2PinR,HIGH);
    pause(backtime);
    stopStop();
  }

//these functions use for loops to cycle through the index of notes we created, thus playing a melody
//write new function called play() that takes in a string variable and plays the related melody
void playErrorMelody()  
  {
    // iterate over the notes of the errorMelody:
    for (int thisNote = 0; thisNote < 2; thisNote++) 
      {
        tone(peizoPin, errorMelody[thisNote], noteDurations);
        // to distinguish the notes, set a minimum time between them.
        pause(pauseBetweenNotes);
        // stop the tone playing
        noTone(peizoPin);
      }
  }

void playGreatingMelody()  
  {
    // iterate over the notes of the errorMelody:
    for (int thisNote = 0; thisNote < 3; thisNote++) 
      {
        tone(peizoPin, greatingMelody[thisNote], noteDurations);
        // to distinguish the notes, set a minimum time between them.
        pause(pauseBetweenNotes);
        // stop the tone playing
        noTone(peizoPin);
      }
  }

//Detection of ultrasonic distance
int watch()//we made need to take a closer look at this one to make sure its working as expected and desired
  {
    long echo_distance;
    digitalWrite(Trig_PIN,LOW);
    microPause(5);                                                                              
    digitalWrite(Trig_PIN,HIGH);
    microPause(15);
    digitalWrite(Trig_PIN,LOW);
    echo_distance = pulseIn(Echo_PIN,HIGH);
    echo_distance = echo_distance*0.01657; //how far away is the object in cm
    return round(echo_distance);
  }

void lookCenter()
  {
    head.write(center);//90 
    pause(servoTurnPause);//this gives the servo time to turn before trying to do anything else, can also slow the servo down so its not so spastic
  }
void lookLeft()
  {
    head.write(Left);//110
    pause(servoTurnPause); 
  }
void lookRight()
  {
    head.write(Right);//70
    pause(servoTurnPause);
  }

//we need to rewrite this an an array that takes in the scan distance of objects in a 360 degree scan sweep.
//  paralell array that associates each scan location to a degree location that will be used as reference to orient the car
//    towards the largest value, indicating the clearest route.
/*Meassures distances to the right, left, front, left diagonal, right diagonal and asign them in cm to the variables rightscanval, 
leftscanval, centerscanval, ldiagonalscanval and rdiagonalscanval (there are 5 points for distance testing)*/
String scanSweep()
  {
    lookCenter();
    watch();
    lookLeft();
    watch();
    lookRight();
    watch();
    lookCenter();
  }
String fullScanSweep()
  {  
    scanSweep();
    turnRight(45);
    scanSweep();
    turnRight(45);
    scanSweep();
    turnRight(45);
    scanSweep();
    turnRight(45);
    scanSweep();
    turnRight(45);
    scanSweep();
    turnRight(45);
    scanSweep();
    turnRight(45);
    scanSweep();
    turnRight(45);
  }

//need to fix this after the the collisionAvoidacne is updated  
//change this to collisionDetected  
void waitForSwitch()
  {
    if (digitalRead(fullRightLimitSwitchPin) == HIGH)
      {
        playErrorMelody();
      }
  }
  

void collisionAvoidance()
  {
  
  }

void testDance()
  {
    lookCenter();
    
    turnLeft(45);
    lookRight();
    pause(500);

    turnRight(80);
    lookLeft();
    pause(500);

    turnLeft(45);
    lookCenter();
  }
