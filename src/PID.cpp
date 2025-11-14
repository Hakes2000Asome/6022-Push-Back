
#include "api.h"
#include "PID.h"

using namespace pros;

float kP_drive = 20; //1st
float kI_drive = 0; //3rd
float kD_drive = 0; //2nd

float kP_angle = 1;
float kI_angle = 0;
float kD_angle = 0;

float previousTime_drive = 0;
float previousError_drive;
float deltaTime_drive;
float errorSum_drive = 0;


float previousTime_angle = 0;
float previousError_angle;
float deltaTime_angle;
float errorSum_angle = 0;


float drivePID(float error) {
    float currentTime_drive = millis();

    deltaTime_drive = currentTime_drive - previousTime_drive;

    errorSum_drive += 0.5*(error + previousError_drive)*deltaTime_drive;

    float P_drive = kP_drive * error;
    float I_drive = kI_drive * (errorSum_drive);
    float D_drive = kD_drive * (error - previousError_drive)/deltaTime_drive;

    previousError_drive = error;
    previousTime_drive = currentTime_drive;

    return (P_drive + I_drive + D_drive);
    
}


float anglePID(float error) {
    float currentTime_angle = millis();

    deltaTime_angle = currentTime_angle - previousTime_angle;

    errorSum_angle += 0.5*(error + previousError_angle)*deltaTime_angle;

    float P_angle = kP_angle * error;
    float I_angle = kI_angle * (errorSum_angle);
    float D_angle = kD_angle * (error - previousError_angle)/deltaTime_angle;

    previousError_angle = error;
    previousTime_angle = currentTime_angle;

    return (P_angle + I_angle + D_angle);
}

