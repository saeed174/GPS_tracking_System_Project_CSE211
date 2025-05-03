#include "GPS.h"
#include <stdint.h>
#include "UART.h"
#include "tm4c123gh6pm.h"
#include "microconfig.h"

char GPS [100];
char GPS_GPGGA_VALUES[12][20];
uint8_t GPS_Received_Flag = 0;

float ToDegrees(float angle)
{
    uint32_t degree = (uint32_t)angle / 100;
    float minutes = angle - degree*100;
    return degree + (minutes / 60.0);
}

float ToRadians(float angle)
{
    return (angle * PI) / 180.0;
}

float GPS_GET_DISTANCE(float Current_Latitude , float Current_Longitude , float Destination_Latitude , float Destination_Longitude)
{
    // Get Radius of Angles
    float Current_Latitude_Radians = ToRadians(ToDegrees(Current_Latitude));
    float Current_Longitude_Radians = ToRadians(ToDegrees(Current_Longitude));
    float Destination_Latitude_Radians = ToRadians(ToDegrees(Destination_Latitude));
    float Destination_Longitude_Radians = ToRadians(ToDegrees(Destination_Longitude));


    // Get difference
    float diff_Latitude = Destination_Latitude_Radians - Current_Latitude_Radians;
    float diff_Longitude = Destination_Longitude_Radians - Current_Longitude_Radians;

    float a = pow(sin(diff_Latitude / 2), 2) + cos(Current_Latitude_Radians) * cos(Destination_Latitude_Radians) * pow(sin(diff_Longitude / 2), 2);
    float c = 2 * atan2(sqrt(a), sqrt(1 - a));
    float distance = EARTH_RADIUS * c; // in meters
    return distance;
}

void GPS_read_latitude_longitude(float *latitude , float *longitude)
{
	while(GPS_Received_Flag == 0)
	{
    char *token;
    int i = 0;
    char c0 = UART5_ReceiveChar();
    if(c0 == '$')
    {
        char c1 = UART5_ReceiveChar();
        if(c1 == 'G')
        {
            char c2 = UART5_ReceiveChar();
            if(c2 == 'P')
            {
                char c3 = UART5_ReceiveChar();
                if(c3 == 'G')
                {
                    char c4 = UART5_ReceiveChar();
                    if(c4 == 'G')
                    {
                        char c5 = UART5_ReceiveChar();
                        if(c5 == 'A')
                        {
                            char c6 = UART5_ReceiveChar();
                            if(c6 == ',')
                            {
                                char c7 = UART5_ReceiveChar();
                                while (c7 !='*')
                                {
                                    GPS[i] = c7;
                                    i++;
                                    c7 = UART5_ReceiveChar();
                                }
                                i = 0;
                                token=strtok(GPS,",");
                                
                                do
                                {
                                    strcpy(GPS_GPGGA_VALUES[i],token);
                                    token=strtok(NULL,",");
                                    i++;
                                }while(token!=NULL);

                                if( strcmp(GPS_GPGGA_VALUES[5], "1") == 0){
                                    *latitude = atof(GPS_GPGGA_VALUES[1]); 
                                    *longitude = atof(GPS_GPGGA_VALUES[3]);
                                    GPS_Received_Flag = 1; // use it main function to ensure that the GPS data is received
                                }
                            }
                        }
                    }
                }
            }
        }
    }
	}
	GPS_Received_Flag = 0;
}