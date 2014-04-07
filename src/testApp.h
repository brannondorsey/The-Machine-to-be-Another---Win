#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define HOST "localhost"
#define PORT 8015

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
							
		void clear();
		void output();
		
		ofxOscSender sender;
		ofVideoGrabber vidGrabberLeft, vidGrabberRight;		
		
		int camWidth, camHeight;
		int x_offset, y_offset;
		float pitch, yaw, roll;
		int layer_offset;
		bool symmetry;
};
