#ifndef GPS_H
#define GPS_H
#include <stdint.h>
#include "math.h"
#include "tm4c123gh6pm.h"
#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371000 // in meters

// update to repo
float ToDegrees(float angle);
float ToRadians(float angle);
float GPS_GET_DISTANCE(float Current_Latitude , float Current_Longitude , float Destination_Latitude , float Destination_Longitude);
void GPS_read_latitude_longitude(float *latitude , float *longitude);

#endif