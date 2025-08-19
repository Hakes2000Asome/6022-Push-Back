#include Drive.h;
#include math.h;

float turn_p = 1;
float turn_i = 1;
float turning_threshold = 5;

void drive_cord(int x_cord, int y_cord, int heading){
    int angle = atan2(y_cord, x_cord)*36000/(2*pi);

}

void drive_distance(int distance){
    int feetTo = distance/(3.25*pi);
    while(distance -)

}

void turn(int angle){
    while(abs(angle-imu_sensor.get_heading())>turning_threshold){
        int delta_angle = reduce_negative_180_to_180(angle-imu_sensor.get_heading());
        if(delta_angle < 0){
            //right forward( -delta_angle*p)
            //left reverse( delta_angle*p)
        }
        if(delta_angle > 0){
            //right reverse( -delta_angle*p)
            //left forward( delta_angle*p)
        }
    }
}
