#ifndef _PLANET
#define _PLANET

#include "ofMain.h"

class Planet
{

private:

protected:

public:
	//methods
	void setup();
	void reroll();
	void draw();
	ofVec2f gravity(ofVec2f target);
	//variables
	ofVec2f pos;
	float size;
	float mass;
	

	Planet();
	
};
#endif


