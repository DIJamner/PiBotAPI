#ifndef SagePi
#define SagePi

const int In1 = 3;      
const int In2 = 5;      
const int In3 = 6;      
const int In4 = 11;   

const int speed = 150;
int wheelRTime = 0;
bool wheelRForward = true;
int wheelLTime = 0;
bool wheelLForward = true;


void start(){
    Timer1.initialize(100000);
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
    }else if(wheelRForward){
        analogWrite(In4, 0); 
        analogWrite(In3, speed);
    }else{
        analogWrite(In4, speed); 
        analogWrite(In3, 0);
    }
    if(wheelLTime != 0){
        wheelLTime -= 10;
    }else if(wheelLForward){
        analogWrite(In2, 0); 
        analogWrite(In1, speed); 
    }else{
        analogWrite(In2, speed); 
        analogWrite(In1, 0); 
    }
}


    
#endif