#ifndef Map_H
#define Map_H

#define NAME_MAX_LENGTH 50  /*size of name of the location*/

#define MAP_SIZE 16       /* num of locations*/


typedef struct {
    char name[NAME_MAX_LENGTH];
	
    float Latitude;
	
    float Longitude;
	
} location;



static const location MAP[MAP_SIZE] = {
    { "HALL_A ", 30.064094738671454f, 31.280115384904754f },
		
    { "HALL_B", 30.064094738671454f, 31.280115384904754f },
		
    { "HALL_C",30.06367902216664f, 31.280382108343176f },
		
		{ "HALL_D",30.06367902216664f, 31.280382108343176f },
		
		{ "Architecture Department Building",30.064140278390333f, 31.280684709663866f },
		
		{ "Engineering College Mosque",30.064649734347483f, 31.280397040815135f },
		
		{ "Playground",30.06376495176123f, 31.27954399074193f },
		
		{ "mechanical workshop",30.06406005290846f, 31.278882152802797f }, 
		
		{ "Luban Workshop",30.063415604696043f, 31.279609375152308f },
		
		{ "Credit building",30.06349676107864f, 31.27841452373108f },
		
		{ "College Library",30.065248963951802f, 31.28021914000281f },
		
		{ "Main Building",30.064968222358775f, 31.279018586832205f },
		
		{ "Student Affairs",30.065101262416096f, 31.27864449470614f },
		
		{ "Palestine Hall",30.06519417419859f, 31.278602358352384f },
		
		{ "kharasana building",30.06425265689325f, 31.277704235090642f },
		
		{ "EL_NAFORA",30.065585244427574f, 31.278404414635386f },
		
};

#endif 