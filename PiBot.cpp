#include <Arduino.h>
#include <TimerOne.h>
#include "PiBot.h"

const int RIGHT = 0, LEFT = 1;


const int In1 = 3;      
const int In2 = 5;      
const int In3 = 6;      
const int In4 = 11;   

const int speed[10][2] = {
  {150,150},
  {150,150},
  {150,150},
  {150,150},
  {150,150},
  {150,150},
  {150,150},
  {150,150},
  {150,150},
  {150,150}
};
int robot = -1;
int wheelRTime = 0;
bool wheelRForward = true;
int wheelLTime = 0;
bool wheelLForward = true;


void start(int rbt){
    robot = rbt;
    Timer1.initialize(10000);//TODO: check timing
    Timer1.attachInterrupt(updateRobot);
    pinMode(In1, OUTPUT);
    pinMode(In2, OUTPUT);
    pinMode(In3, OUTPUT);
    pinMode(In4, OUTPUT);
    
}

void stopLeftWheel(){
    moveLeftWheel(0,true);
}

void stopRightWheel(){
    moveRightWheel(0,true);
}

void moveLeftWheel(int time, bool direction){
    wheelLTime = time;
    wheelLForward = direction;
}

void moveRightWheel(int time, bool direction){
    wheelRTime = time;
    wheelRForward = direction;
}

void updateRobot(){
    if(wheelRTime != 0){
        wheelRTime -= 10;
        if(wheelRForward){
                analogWrite(In4, 0); 
                analogWrite(In3, speed[robot][RIGHT]);
            }else{
                analogWrite(In4, speed[robot][RIGHT]); 
                analogWrite(In3, 0);
            }
    }else{
        analogWrite(In4, 0); 
        analogWrite(In3, 0);
    }
    if(wheelLTime != 0){
        wheelLTime -= 10;
        if(wheelLForward){
            analogWrite(In2, 0); 
            analogWrite(In1, speed[robot][LEFT]); 
        }else{
            analogWrite(In2, speed[robot][LEFT]); 
            analogWrite(In1, 0); 
        }
    }else{
            analogWrite(In2, 0);
            analogWrite(In1, 0);
        }
}