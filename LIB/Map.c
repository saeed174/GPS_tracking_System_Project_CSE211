#include "Map.h" 
#include "GPS.h"
#include <stdio.h>
#include <string.h>

// Buffer to store the name of the nearest location
/*char name_nearest_location[50]; */    

//========================[ Search Function ]========================
// Purpose: Finds the nearest location from MAP[] to the current GPS 
//          coordinates and stores its name in name_nearest_location.
//===================================================================

int search(float currentLatitude, float currentLongitude) {
    
    int nearestIndex = 0;                       // Index of the nearest location
    float minDistance = 1e10;                   // Initialize with a large number
    float distance = 0;                         // Distance from current to a map point

    // Loop through all locations in the map to find the nearest one
    for (int i = 0; i < MAP_SIZE; i++) {
        
        distance = GPS_GET_DISTANCE(
            currentLatitude, 
            currentLongitude, 
            MAP[i].Latitude, 
            MAP[i].Longitude
        );

        if (distance <= minDistance) {
            minDistance = distance;
            nearestIndex = i;
        }
    }
       
		    return nearestIndex;                   // return the index to main
   /* // Copy the name of the nearest location to the output buffer
    for (int i = 0; i < NAME_MAX_LENGTH; i++) {
        name_nearest_location[i] = MAP[nearestIndex].name[i];
    }*/
}



