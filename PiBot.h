#ifndef PiBot
#define PiBot
#define WHEEL_FORWARD true
#define WHEEL_BACKWARD false

    void start(int rbt);

    void stopLeftWheel();

    void stopRightWheel();

    void moveLeftWheel(int time, bool direction);

    void moveRightWheel(int time, bool direction);

    void updateRobot();
    
#endif