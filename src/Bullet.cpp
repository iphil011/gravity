#include "Bullet.h"

void Bullet::setup(ofVec2f play, ofVec2f target, float _strength ) {
	pos = play;
	vel = target- pos;
	vel.normalize();
	vel.scale(_strength);
	size = 10;
}

void Bullet::update(ofVec2f grav, int timer) {
	//ofLog() << vel.length();
	grav.limit(0.005);
	if (timer < 2390) {
		acc += grav;
	}
	vel += acc;
	acc.normalize();
	acc.limit(0.00001);
	vel.limit(2);
	pos += vel;
}


void Bullet::draw() {
	ofSetColor(255);
	ofFill();
	ofDrawCircle(pos.x, pos.y, size);
}

bool Bullet::collide(ofVec2f planet, float pSize){
	bool collided = false;
	if (planet.distance(pos)< pSize) {
		collided = true;
	}
	return collided;
}


Bullet::Bullet() {
}


Bullet::~Bullet()
{
}
