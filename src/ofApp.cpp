#include "ofApp.h"
vector<Planet> planets;
vector<Player> players;
vector<Bullet> bullets;
int turn;
int bulletTimer;
float strength;
/*
to do:
fix reroll function
implement player collision
menu screen?
*/


//--------------------------------------------------------------
void ofApp::setup() {
	//ofSetWindowShape(1000, 1000);
	
	//creates 4 planets and puts a player on each one
	for (int i = 0; i < 4; i++) {
		planets.push_back(Planet());
		players.push_back(Player());
		planets[i].setup();
		players[i].setup(i, planets[i].pos, planets[i].size);
		//checks if the planets are overlapping (WIP)
		distanceCheck();
	}
	bulletTimer = 0;

}

//--------------------------------------------------------------
void ofApp::update() {
	if (players[turn].hit) {
		turn++;
		if (turn >= players.size()) {
			turn = 0;
		}
	}
	for (auto & play : players) {
		play.update();
	}
	//finds closest planet to the bullet and applies its gravity;
	for (auto & bull : bullets) {
		bull.update(closest(bull.pos, planets).gravity(bull.pos));
		for (int i = 0; i < players.size(); i++) {
			if (players[i].collide(bull.pos) && bulletTimer<2200) {
				players[i].hit = true;
				break;
			}
		}
	}
	for (auto & plan : planets) {
		if (bullets.size() > 0) {
			if (bullets[0].collide(plan.pos, plan.size)) {
				bullets.clear();
				bulletTimer = 0;
			}// iterator deletion (breaks when bullet hits start planet)
		}
	}
	
	
	//times out bullet
	if (bulletTimer > 0) {
		bulletTimer--;
		//ofLog() << bulletTimer;
	}
	if (bulletTimer == 0) {
		bullets.clear();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(0);
	for (auto plan : planets) {
		plan.draw();

	}
	for (auto play : players) {
		//if (play.hit == false) {
			play.draw();
		//}
	}
	for (auto bull : bullets) {
		bull.draw();
	}
	players[turn].indi();
	//ofLog() << players[turn].getPos() << ' ' << turn;
	if (players.size() == 1) {
		ofBackground(0);
		ofSetRectMode(OF_RECTMODE_CENTER);
		ofSetColor(255);
		ofFill();
		ofDrawRectangle(ofGetWidth()/2,ofGetHeight()/2,200,100);
		for (auto play : players) {
			if (!play.hit) {
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	players[turn].keyPressed(key);

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	if (strength < 5);
	strength ++;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	//spawns bullet at the player's who turn it is and cycles turn to next player
	if (bulletTimer == 0) {
		Bullet tempBull;
		tempBull.setup(players[turn].getPos(), ofVec2f(x, y), strength);
		//tempBull.setup(ofVec2f(x,y), ofVec2f(x, y), strength);
		bullets.push_back(tempBull);
		turn++;
		if (turn >= players.size()) {
			turn = 0;
		}
		bulletTimer = 2400;
	}
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

void ofApp::distanceCheck() {
	//checks to see if planets overlap
	bool rerolled;
	rerolled = false;
	for (int i = 0; i < planets.size(); i++) {
		for (int j = 0; j < planets.size(); j++) {
			if (i != j) {
				Planet plan1 = planets[i];
				Planet plan2 = planets[j];
				while (plan1.pos.distance(plan2.pos) <= plan2.size + plan1.size + 30) {
					plan2.reroll();
					if (plan2.pos.distance(plan1.pos) <= plan2.size + plan1.size + 30) {
						rerolled = true;
					}
				}
			}
		}
	}
	if (rerolled) {
		distanceCheck();
	}
}

Planet ofApp::closest(ofVec2f bullet, vector<Planet> p) {
	float dis = 1000;
	int a = 0;
	for (int i = 0; i < p.size(); i++) {
		if (dis > p[i].pos.distance(bullet)) {
			dis = p[i].pos.distance(bullet);
			a = i;
		}
	}
	return p[a];
}



