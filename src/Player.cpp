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
	del = 0;

}

void Player::update() {
	float d = 0.1;
	if (del>5) {
		d = -d;
		del = 5;
	}
	if (del < -5) {
		d = -d;
		del = -5;
	}
	ofVec2f angle = ofVec2f(0, 0);
	ofVec2f indicA = ofVec2f(0,0);
	angle.x = (size + dist)*cos(theta);
	angle.y = (size + dist)*sin(theta);
	indicA.x = (2.5*size + dist +del)*cos(theta);
	indicA.y = (2.5*size + dist + del)*sin(theta);
	pos = planet + angle;
	indic = planet + indicA;
}

void Player::draw() {
	
	switch (player) {
	default: ofSetColor(255);
		break;
	case 0: ofSetColor(255);
		break;
	case 1: ofSetColor(255, 0, 0);
		break;
	case 2: ofSetColor(0, 255, 0);
		break;
	case 3: ofSetColor(0, 0, 255);
		break;
	case 4: ofSetColor(255,255,0);
		break;
	}
	if (hit == false) {
		ofFill();
		ofDrawCircle(pos.x, pos.y, size);
		
	}
}

void Player::indi(){
	ofSetColor(255);
	ofDrawCircle(indic.x, indic.y, size / 5);

}

bool Player::collide(ofVec2f bullet){
	bool collided = false;
	if (bullet.distance(pos)< size) {
		collided = true;
	}
	return collided;
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
