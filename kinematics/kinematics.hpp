#include "servo2040.hpp"
#include "pico/stdlib.h"

class kinematics
{
private:
    float L1 = 24.8f;
    float L2 = 37.0f;
    float L3 = 65.0f;
    float r1;
    float r2;
    float r3;
    float phi2;
    float phi3;
    float theta1;
    float theta2;
    float theta3;

public:
    kinematics() {};
    void endpoint(int x, int y, int z);
    ~kinematics() {};
};