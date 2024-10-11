#include "kinematics.hpp"
#include "pico/stdlib.h"
#include "servo2040.hpp"
#include <stdio.h>

void kinematics::endpoint(int x, int y, int z){
    r1 = sqrt(pow(x,2) + pow(y,2));
    r2 = r1 - L1;
    r3 = sqrt(pow(r1,2) + pow(z,2));
    phi2 = acos((pow(r3,2) + pow(L2,2) - pow(L3,2))/ (2 * r3 * L2));
    phi3 = atan2(r2, z);
    theta1 = atan2(y, x);
    theta2 = phi2 + phi3;
    theta3 = 3.14f - acos((pow(L2,2) + pow(L3,2) - pow(r3,2))/ (2 * L3 * L2));

    printf("r1: %f, r2: %f, r3, %f\n", r1, r2, r3);
    printf("phi2: %f, phi3: %f\n", phi2, phi3);
    printf("theta1: %f, theta2: %f, theta3: %f\n", theta1, theta2, theta3);
}