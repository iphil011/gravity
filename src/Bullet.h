#pragma once
#include "ofMain.h"
class Bullet
{
public:
	void setup(ofVec2f play, ofVec2f target, float _strength);
	void update(ofVec2f grav);
	void draw();
	bool collide(ofVec2f planet, float pSize);
	ofVec2f pos;
	ofVec2f vel;
	ofVec2f acc;
	float size;

	Bullet();
	~Bullet();
};

