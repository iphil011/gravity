#include "Player.h"



Player::Player()
{
}
void Player::setup(int play, ofVec2f _planet, float _dist) {
	hit = false;
	//pos = ofVec2f(0,0);
	speed = 2;
	size = 30;
	theta = ofRandom(0, 360);
	player = play + 1;
	planet = _planet;
	dist = _dist;

}

void Player::update() {
	ofVec2f angle = ofVec2f(0, 0);
	angle.x = (size + dist)*cos(theta);
	angle.y = (size + dist)*sin(theta);
	pos = planet + angle;
}

void Player::draw() {
	
	//ofLog() << pos;

	ofDrawCircle(pos.x, pos.y, size);
	
}

ofVec2f Player::getPos() {
	ofLog() << pos;
	ofVec2f p = pos;
	return p;

}

void Player::keyPressed(int key) {
	if (key == OF_KEY_LEFT) {
		theta += 0.05;
	}
	if (key == OF_KEY_RIGHT) {
		theta -= 0.05;

	}
}

Player::~Player()
{
}
