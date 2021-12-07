#pragma once

#include "ofMain.h"
#include "Emiter.h"
#include "Particle.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		vector<Particle> p;	  //Particles
		ofFbo fbo;            //Off-screen buffer for trails

		float history;        //Control parameter for trails
		float time0;          //Time value for computing dt

		float bornRate;       //Particles born rate per second
		float bornCount;      //Integrated number of particles to born

		ofEasyCam cam;
		ofLight light;
		Params param;
		

}; 

