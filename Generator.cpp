#include "Generator.h"

Generator::Generator() {
	maxParticles = 1000;
    for (int i = 0; i < maxParticles; i++) {
        Particle newParticle;
        newParticle.setup();
        particles.push_back(newParticle);
    }
}

Generator::~Generator() {

}

void Generator::update()
{
    for (size_t i = 0; i < particles.size(); i++)
    {
        //particles[i].update();
    }
}

void Generator::draw() {
    for (size_t i = 0; i < particles.size(); i++)
    {
        //particles[i].draw();
    }
}
