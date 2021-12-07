#include "Emiter.h"

Params::Params() {
	//konstruktor
	eCenter = ofPoint(ofGetWidth() / 2, ofGetHeight() / 2);
	eRad = 50;
	velRad = 200;
	lifeTime = 1.0;
	rotate = 90;

	force = 1000;
	spinning = 1000;
	friction = 0.05;
}

Params::~Params() {
	//destruktor
}
void Params::setup() {
	
}