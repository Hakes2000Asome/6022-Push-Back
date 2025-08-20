#include "funtions.h"
#include "math.h"

float reduce_negative_180_to_180(float angle) {
  while(!(angle >= -180 && angle < 180)) {
    if(angle < -180) {
        angle += 360; 
    }
    if(angle >= 180) {
        angle -= 360; 
    }
  }
  return(angle);
}