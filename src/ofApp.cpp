#include "ofApp.h"
vector<Planet> planets;
vector<Player> players;
vector<Bullet> bullets;
int turn;
int bulletTimer;

//--------------------------------------------------------------
void ofApp::setup(){
	//ofSetWindowShape(1000, 1000);
	ofBackground(0);
	for (int i = 0; i < 4; i++) {
		planets.push_back(Planet());
		players.push_back(Player());
		planets[i].setup();
		players[i].setup(i, planets[i].pos, planets[i].size);
		distanceCheck();
	}
	bulletTimer = 0;
	
}

//--------------------------------------------------------------
void ofApp::update(){
	for (auto play : players) {
		play.update();
		
	}
	for (auto & plan : planets) {
		for (auto & bull : bullets) {
			bull.update(plan.gravity(bull.pos));
		}
	}
	
	if (bulletTimer > 0) {
		bulletTimer--;
		//ofLog() << bulletTimer;
	}
	if (bulletTimer == 0) {
		bullets.clear();
	}
	if (bullets.size() == 1) {
		//ofLog() << bullets[0].pos;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (auto plan: planets) {
		plan.draw();
		
	}
	for (auto play : players) {
		play.draw();
	}
	for (auto bull : bullets) {
		bull.draw();
	}
	//ofLog() << players[turn].getPos() << ' ' << turn;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	players[turn].keyPressed(key);
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if(bulletTimer == 0){
		Bullet tempBull;
		tempBull.setup(players[turn].getPos(), ofVec2f(x, y));
		//tempBull.setup(ofVec2f(x,y), ofVec2f(x, y));
		//ofLog() << players[turn].pos << ' ' << turn;
	bullets.push_back(tempBull);
	turn++;
	if (turn >= players.size()) {
		turn = 0;
	}
	bulletTimer = 300;
	}
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::distanceCheck() {
	bool rerolled;
	rerolled = false;
	for (int i = 0; i < planets.size(); i++) {
		for (int j = 0; j < planets.size(); j++) {
			if (i != j) {
				Planet plan1 = planets[i];
				Planet plan2 = planets[j];
				if (plan1.pos.distance(plan2.pos) <= plan2.size+plan1.size+30) {
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


