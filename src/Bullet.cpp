#include "Bullet.h"

void Bullet::setup(ofVec2f play, ofVec2f target ) {
	pos = play;
	vel = target- pos;
	vel.normalize();
	vel* 0.001;
	//acc = ofVec2f(1, 1);
	size = 10;
}

void Bullet::update(ofVec2f grav) {
	grav.limit(0.005);
	acc += grav;
	vel += acc;
	acc.normalize();
	acc.limit(0.00001);
	vel.limit(1.5);
	pos += vel;
}


void Bullet::draw() {
	ofDrawCircle(pos.x, pos.y, size);
}

bool Bullet::collide(ofVec2f planet, float pSize){
	bool collided = false;
	if (planet.distance(pos)< pSize/2) {
		collided = true;
	}
	return collided;
}


Bullet::Bullet() {
}


Bullet::~Bullet()
{
}
