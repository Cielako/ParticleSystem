#pragma once

#include "ofMain.h"
#include "Particle.h"
#include <vector>

class Generator
{
public:
	Generator();
	~Generator();
	void update();
	void draw();

	int maxParticles;
	std::vector<Particle> particles; // wektor zawierajacy kule
};

