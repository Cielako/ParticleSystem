#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){

	//ofDisableAlphaBlending();
	ofEnableDepthTest();
	ofDisableArbTex();

	light.enable();
	light.setPosition(100, 100, 200);
	light.lookAt(ofVec3f(0, 0, 0));
	cam.setPosition(ofPoint(ofGetWidth() / 2, ofGetHeight() / 2));

	//Set up parameters
	history = 0.995;
	bornRate = 1000;
	bornCount = 0;
	time0 = ofGetElapsedTimef();
}

//--------------------------------------------------------------
void ofApp::update(){
	//Compute dt
	float time = ofGetElapsedTimef();
	float dt = ofClamp(time - time0, 0, 0.1);
	time0 = time;

	//Delete inactive particles
	int i = 0;
	while (i < p.size()) {
		if (!p[i].live) {
			p.erase(p.begin() + i);
		}
		else {
			i++;
		}
	}

	//Born new particles
	bornCount += dt * bornRate;      //Update bornCount value
	if (bornCount >= 1) {          //It's time to born particle(s)
		int bornN = int(bornCount);//How many born
		bornCount -= bornN;          //Correct bornCount value
		for (int i = 0; i < bornN; i++) {
			Particle newP;
			newP.setup();            //Start a new particle
			p.push_back(newP);     //Add this particle to array
		}
	}

	//Update the particles
	for (int i = 0; i < p.size(); i++) {
		p[i].update(dt);
	}
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	//Draw semi-transparent white rectangle
	//to slightly clearing a buffer (depends on history value)

	//ofEnableAlphaBlending();         //Enable transparency

	float alpha = (1 - history) * 255;
	//ofSetColor(255, 255, 255, alpha);
	//ofFill();
	//ofRect(0, 0, ofGetWidth(), ofGetHeight());
	cam.begin();
	//ofDisableAlphaBlending();        //Disable transparency

	//Draw the particles
	//ofFill();
	for (int i = 0; i < p.size(); i++) {
		p[i].draw();
	}
	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
