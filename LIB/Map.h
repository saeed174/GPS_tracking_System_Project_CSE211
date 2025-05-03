#ifndef Map_H
#define Map_H

#define NAME_MAX_LENGTH 50  /*size of name of the location*/

#define MAP_SIZE 14       /* num of locations*/


typedef struct {
    char name[NAME_MAX_LENGTH];
	
    float Latitude;
	
    float Longitude;
	
} location;



static const location MAP[MAP_SIZE] = {
    { "HALL_A & B", 3006.4094738671454f, 3128.0115384904754f },
		
    { "HALL_C & D",3006.367902216664f, 3128.0382108343176f },
		
		{ "Architecture Department Building",3006.4140278390333f, 3128.0684709663866f },
		
		{ "Engineering College Mosque",3006.4649734347483f, 3128.0397040815135f },
		
		{ "Playground",3006.376495176123f, 3127.954399074193f },
		
		{ "mechanical workshop",30064.06005290846f, 3127.8882152802797f }, 
		
		{ "Luban Workshop",3006.3415604696043f, 3127.9609375152308f },
		
		{ "Credit building",3006.349676107864f, 3127.841452373108f },
		
		{ "College Library",3006.5248963951802f, 3128.021914000281f },
		
		{ "Main Building",3006.4968222358775f, 3127.9018586832205f },
		
		{ "Student Affairs",3006.5101262416096f, 3127.864449470614f },
		
		{ "Palestine Hall",3006.519417419859f, 3127.8602358352384f },
		
		{ "kharasana building",3006.425265689325f, 3127.7704235090642f },
		
		{ "EL_NAFORA",3006.5585244427574f, 3127.8404414635386f },
		
};

void search(float currentLatitude, float currentLongitude , char name_nearest_location[50]);

#endif 