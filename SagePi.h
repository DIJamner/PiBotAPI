#ifndef SagePi
#define SagePi

const int speed = 150;

void start(){
    Timer1.initialize(100000);
    Timer1.attachInterrupt(updateRobot);
    
}

void updateRobot(){
    
}
    
#endif