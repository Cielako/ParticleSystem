#pragma once
#include "ofMain.h"
class Params
{
public:
	Params();
	~Params();
	void setup();
	ofPoint eCenter;    //Emitter center
	float eRad;         //Emitter radius
	float velRad;       //Initial velocity limit
	float lifeTime;     //Lifetime in seconds

	float rotate;   //Direction rotation speed in angles per second

	float force;       //Attraction/repulsion force inside emitter
	float spinning;    //Spinning force inside emitter
	float friction;    //Friction, in the range [0, 1]
}; 



