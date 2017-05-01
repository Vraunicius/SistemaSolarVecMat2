#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofSetFrameRate(60);

	ofSetBackgroundColor(0, 0, 0);

	SunPosition.set(ofGetWidth() / 2, ofGetHeight() /2);
	PlanetPosition.set(140, 140);
	MoonPosition.set(40, 40);
	
	Bodys.push_back(new CorposCelestes(SunPosition, "sol1.png", 0, 332946.0487 / 100, 100));
	Bodys.push_back(new CorposCelestes(PlanetPosition, "terra1.png", 0.3f, 100, 4));
	Bodys.push_back(new CorposCelestes(MoonPosition, "lua1.png", 1.5, 0.0123000371, 1));
	


}

//--------------------------------------------------------------
void ofApp::update(){

	Bodys.at(1)->Update(Bodys.at(0));
	Bodys.at(2)->Update(Bodys.at(1));



	for (int i = 0; i < Asteroids.size(); i++) {
		for (int j = 0; j < Bodys.size(); j++) 
			Asteroids.at(i)->Update(Bodys.at(j));
		for (int j = 0; j < Asteroids.size(); j++) 
			if (i != j) 
				Asteroids.at(i)->Update(Asteroids.at(j));	
		}
	

}

//--------------------------------------------------------------
void ofApp::draw(){
	Bodys.at(0)->Draw();
	Bodys.at(1)->Draw();
	Bodys.at(2)->Draw();

	for (int i = 0; i < Asteroids.size(); i++) {
		Asteroids.at(i)->Draw();
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (67 || 99)
		Asteroids.clear();
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
	if (button == 0) 
		Asteroids.push_back(new Meteoro(x, y, (ofRandom(25) * 1 / 1000), ceil(1 / 10),
 (1 - ofRandom(3)) / 100, (1 - ofRandom(3)) / 100, "meteoro1.png"));
	
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
