//need to clean this fill up 
  //its getting disorganzied


#include "pitches.h"

int serialDebug=1; //enter 1 for on, 0 for off 

/*Declare L298N Dual H-Bridge Motor Controller directly since there is not a library to load.*/
//Define L298N Dual H-Bridge Motor Controller Pins
#define dir1PinL  2    //Motor direction
#define dir2PinL  4    //Motor direction
#define speedPinL 6    // Needs to be a PWM pin to be able to control motor speed

#define dir1PinR  7    //Motor direction
#define dir2PinR  8   //Motor direction
#define speedPinR 5    // Needs to be a PWM pin to be able to control motor speed

#define SERVO_PIN     9  //servo connect to D9

#define Echo_PIN    11 // Ultrasonic Echo pin connect to D11
#define Trig_PIN    12  // Ultrasonic Trig pin connect to D12

#define peizoPin     13

const int SPEED = 100;   //both sides of the motor speed
const int turnSpeed = 150;
#define BACK_SPEED1  135     //back speed
#define BACK_SPEED2  135     //back speed

int leftscanval, centerscanval, rightscanval, ldiagonalscanval, rdiagonalscanval;
const int distancelimit = 40; //distance limit for obstacles in front           
const int sidedistancelimit = 25; //minimum distance in cm to obstacles at both sides (the car will allow a shorter distance sideways to prioritize the front)
int distance;
int numcycles = 0;

const int backtime = 250; //Time the robot spends backing up (miliseconds)
const int servoTurnPause = 500;
int thereis;

// notes in the errorMelody
int errorMelody[]={NOTE_G4, NOTE_C4};
int greatingMelody[]={NOTE_G4, NOTE_D5, NOTE_A5};
int noteDurations[]={200, 300, 400};
int pauseBetweenNotes = 500;

int fullLeftLimitSwitchPin = A4;
int centerLimitSwitchPin = A2;
int fullRightLimitSwitchPin = 10;

int oneSecond = 1000;
unsigned long timeElapsed = 0;

int center = 90;
int Left = 112;
int Right = 68;

int degree;//given by user in function
float turnRatio=(7.8);//8 +(20/21)
