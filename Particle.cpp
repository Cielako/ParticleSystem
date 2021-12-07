#include "Particle.h"


Particle::Particle() {
	//konstruktor
    live = false;
   
}

Particle::~Particle() {
	//destruktor
}

ofPoint randomPointInCircle(float maxRad) {
    ofPoint pnt;
    float rad = ofRandom(0, maxRad);
    float angle = ofRandom(0, M_TWO_PI);
    pnt.x = cos(angle) * rad;
    pnt.y = sin(angle) * rad;
    pnt.z = tan(angle) * rad; // tan fajny efekt
    return pnt;
}

void Particle::setup()
{
    radius = ofRandom(1, 4);
    position = param.eCenter + randomPointInCircle(param.eRad);
    velocity = randomPointInCircle(param.velRad);
    time = 0;
    lifeTime = param.lifeTime;
    live = true;
    //color.set(ofRandom(255), ofRandom(255), ofRandom(255));
    //weight = ofRandom(1, 4);
    
}

void Particle::update(float dt)
{   
    if (live) {
        //Rotate vel
        velocity.rotate(0, 0, param.rotate * dt);


        ofPoint acc;         //Acceleration
        ofPoint delta = position - param.eCenter;
        float len = delta.length();
        if (ofInRange(len, 0, param.eRad)) {
            delta.normalize();

            //Attraction/repulsion force 
            acc += delta * param.force;

            //Spinning force
            acc.x += -delta.y * param.spinning;
            acc.y += delta.x * param.spinning;
            acc.z += -delta.z * param.spinning;
        }

        velocity += acc * dt;            //Euler method
        velocity *= (1 - param.friction);  //Friction

        //Update pos
        position += velocity * dt;    //Euler method

        ////Update pos
        //position += velocity * dt;    //Euler method

        //Update time and check if particle should die
        time += dt;
        if (time >= lifeTime) {
            live = false;   //Particle is now considered as died
        }
    }
    
}

void Particle::draw()
{	

    if (live) {
        //Compute size
        float size = ofMap(
            fabs(time - lifeTime / 2), 0, lifeTime / 2, 3, 1);

        //Compute color
        color = ofColor::blue;
        float hue = ofMap(time, 0, lifeTime, 0, 128);
        color.setHue(hue);
        ofSetColor(color);
        ofDrawSphere(position, radius);
    }
}

