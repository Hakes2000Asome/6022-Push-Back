float kP_drive = 1;
float kI_drive = 1;
float kD_drive = 1;

float kP_angle = 1;
float kI_angle = 1;
float kD_angle = 1;

float previousTime = millis();
float previousError;
float deltaTime;

float errorSum = 0;

float drivePID(float error) {
    float currentTime = millis();

    deltaTime = currentTime - previousTime;

    errorSum += (error - previousError)*deltaTime;

    float P_drive = kP_drive * error;
    float I_drive = kI_drive * (errorSum);
    float D_drive = kD_drive * (error - previousError)/deltaTime;

    previousError = error;
    previousTime = currentTime;

    return (P_drive + I_drive + D_drive);
    
}


float anglePID() {

}

