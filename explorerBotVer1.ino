/*
 * This code borrows heavily from other code. 
 * 
 * 
 * TODO:
 * cite sources for code
 * 
 * update variable and function names
 * 
 * update look function to turn the bot 90 degrees then take a full 180 sweep of readings when the path forward is blocked
 *  repeat this to complete a 360 degree view of the surroundings
 *    will need to update binary intake of the surroundings to compensate for this
 *    
 * update bot turn functions to take in a variable that determines the amount of turn
 *  current function does not and requires a second function to determine how long you let the bot turn, thus dtermining the amount of turn
 *    new function will do the math for the user so you just input the degree of turn you desire
 *    
 * create an function that will turn on the serial printing for debugging   
 *  should be turned on or off by changing a vaiable from a 0 to 1, or true to false
 *    also need to add more debugging into the code
 */

#include <Servo.h>
#include "configuration.h"
#include "functions.h"

void setup() 
  { 
    playGreatingMelody();
  
    Serial.begin(9600);
    
    //setup limit switches
    pinMode(fullLeftLimitSwitchPin, INPUT);
    pinMode(centerLimitSwitchPin, INPUT);
    pinMode(fullRightLimitSwitchPin, INPUT);
    
    //setup L298N pin mode
    pinMode(dir1PinL, OUTPUT); 
    pinMode(dir2PinL, OUTPUT); 
    pinMode(speedPinL, OUTPUT);  
    pinMode(dir1PinR, OUTPUT);
    pinMode(dir2PinR, OUTPUT); 
    pinMode(speedPinR, OUTPUT); 
    
    
    //init HC-SR04
    pinMode(Trig_PIN, OUTPUT); 
    pinMode(Echo_PIN,INPUT); 
    digitalWrite(Trig_PIN,LOW);
    
    //init servo
    head.attach(SERVO_PIN); 
    testDance();
    fullScanSweep();
    playGreatingMelody();
  }

void loop() 
  {
  }
