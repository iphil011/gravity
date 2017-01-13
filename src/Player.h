#ifndef _PLAYER
#define _PLAYER
#include "ofMain.h"
class Player
{
public:
	void setup(int play, ofVec2f planet, float dist);
	void update();
	void draw();
	void indi();
	bool collide(ofVec2f bullet);
	void keyPressed(int key);
	ofVec2f getPos();
	ofVec2f pos;
	ofVec2f planet;
	ofVec2f indic;
	int player;
	float speed;
	float size;
    float theta;
	bool hit;
	float angle;
	float dist;
	float del;

	Player();
	~Player();
};
#endif 
