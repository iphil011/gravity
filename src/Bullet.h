#pragma once
#include "ofMain.h"
class Bullet
{
public:
	void setup(ofVec2f play, ofVec2f target);
	void update(ofVec2f grav);
	void draw();
	ofVec2f pos;
	ofVec2f vel;
	ofVec2f acc;
	float size;

	Bullet();
	~Bullet();
};

