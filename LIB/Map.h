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
		
		//{ "Architecture", 3003.8525390625f, 3116.8178710938f },
		
		{ "Mosque", 3003.8867187500f, 3116.8051757813f },
		
		//{ "Playground",3006.376495176123f, 3127.954399074193f }, //Not updated
		
		//{ "meca workshop",30064.06005290846f, 3127.8882152802797f }, //Not updated
		
		//{ "Luban Workshop",3006.3415604696043f, 3127.9609375152308f }, //Not updated
		
		{ "Credit building",3003.8168945313f, 3116.6950683594f },
		
		{ "College Library",3003.9128417969f, 3116.8105468750f },
		
		//{ "Main Building",3006.4968222358775f, 3127.9018586832205f }, //Not updated
		
		{ "Student Affairs",3003.9040527344f, 3116.7026367188f },
		
		//{ "Palestine Hall",3006.519417419859f, 3127.8602358352384f }, //Not updated
		
		{ "Kharasana",3003.8659667969f, 3116.6779785156f },
		
		//{ "EL_NAFORA",3006.5585244427574f, 3127.8404414635386f }, //Not updated
		
};

void search(float currentLatitude, float currentLongitude , char name_nearest_location[50]);

#endif 