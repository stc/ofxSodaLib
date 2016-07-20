#pragma once

#include "ofMain.h"
#include "ofxSodaLib.h"
#include "DataStream.h"

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
    
        void audioReceived(float * input, int bufferSize, int nChannels);
        void audioRequested(float * output, int bufferSize, int nChannels);
    
        ofxSodaLib soda;
        DataStream noiseData;
        DataStream harmonicData;
        DataStream brownianData;
        DataStream gestureData;
        DataStream linearData;
    
        ofVec2f pPos;
        float speed;
    
        void listenToAll(int x, int y);
        void switchCursor();
};
