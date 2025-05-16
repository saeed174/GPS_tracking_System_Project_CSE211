#ifndef Map_H
#define Map_H

#define NAME_MAX_LENGTH 16  /*size of name of the location*/

#define MAP_SIZE 7       /* num of locations*/


typedef struct {
    char name[NAME_MAX_LENGTH];
	
    float Latitude;
	
    float Longitude;
	
} location;



static const location MAP[MAP_SIZE] = {
    { "HALL_A & B", 3003.8576660156f, 3116.8222656250f },
		
    { "HALL_C & D", 3003.8286132813f, 3116.8378906250f },
		
		{ "Mosque", 3003.8867187500f, 3116.8051757813f },
		
		{ "College Library",3003.9128417969f, 3116.8105468750f },
		
		{ "Student Affairs",3003.9040527344f, 3116.7026367188f },
		
		{ "Kharasana",3003.8659667969f, 3116.6779785156f },
		
		{ "Credit building",3003.8168945313f, 3116.6950683594f },

};

void search(float currentLatitude, float currentLongitude , char name_nearest_location[50]);

#endif 