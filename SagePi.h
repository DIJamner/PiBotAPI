#ifndef SagePi
#define SagePi

const int speed = 150;
int wheelRTime = 0;
int wheelLTime = 0;

void start(){
    Timer1.initialize(100000);
    Timer1.attachInterrupt(updateRobot);
    
}

void updateRobot(){
    if(wheelRTime != 0){
        wheelRTTime -= 10;
    }
    if(wheelRTime != 0){
        wheelRTTime -= 10;
    }
}
    
#endif