#pragma once
#include "ofMain.h"
#include <math/ofVec3f.h>
#include<of3dGraphics.h>
#include "Emiter.h"

#pragma once
class Particle
{
public:
	Particle();
	~Particle();
	void setup();
	void update(float dt);
	void draw();

	double radius;
	double weight;
	float time;
	float lifeTime;
	bool live;

	ofColor color;
	//ofVec3f acceleration;
	ofPoint position;//Position
	ofPoint velocity;//Velocity
	ofVec3f force;

	Params param; //Declaration of a global variable
};

