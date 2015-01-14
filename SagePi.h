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


void start(){
    Timer1.initialize(100000);
    Timer1.attachInterrupt(updateRobot);
    pinMode(In1, OUTPUT);
    pinMode(In2, OUTPUT);
    pinMode(In3, OUTPUT);
    pinMode(In4, OUTPUT);
    
}

void updateRobot(){
    if(wheelRTime != 0){
        wheelRTime -= 10;
    }else if(wheelRForward){
        
    }else{
        
    }
    if(wheelLTime != 0){
        wheelLTime -= 10;
    }
    
}
    
#endif