#include "Planet.h"
Planet::Planet() {
}
	void Planet::setup(){
		pos = ofVec2f(ofRandom(150, ofGetWidth() - 150), ofRandom(150, ofGetHeight() - 150));
			size = ofRandom(50, 100);
			mass = (size / 15)*(size / 15);
	}
	void Planet::reroll(){
		pos = ofVec2f(ofRandom(150, ofGetWidth() - 150), ofRandom(150, ofGetHeight() - 150));
		ofLog() << "rerolled";
	}
	void Planet::draw() {
		ofDrawCircle(pos.x, pos.y, size);
	}

	
	ofVec2f Planet::gravity(ofVec2f target) {
		float g;
		if (pos.distance(target)< 100) {
			g = mass *0.5 / pos.distance(target);
		}
		else if (pos.distance(target) > 500) {
			g = mass*0.0001 / pos.distance(target);
		}
		else {
			g = mass*0.2 / pos.distance(target);
		}
			ofVec2f Gravity = pos - target;
			Gravity.normalize();
			Gravity*g;
			Gravity.limit(1);
			return Gravity;
	}
	
