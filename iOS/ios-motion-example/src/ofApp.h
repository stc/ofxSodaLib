#pragma once

#include "ofxiOS.h"
#include "ofxSodaLib.h"
#include "ofxCoreMotion.h"
#include "SpatialSound.h"

class ofApp : public ofxiOSApp {
	
    public:
        void setup();
        void update();
        void draw();
        void exit();
	
        void touchDown(ofTouchEventArgs & touch);
        void touchMoved(ofTouchEventArgs & touch);
        void touchUp(ofTouchEventArgs & touch);
        void touchDoubleTap(ofTouchEventArgs & touch);
        void touchCancelled(ofTouchEventArgs & touch);

        void lostFocus();
        void gotFocus();
        void gotMemoryWarning();
        void deviceOrientationChanged(int newOrientation);
    
        // audio
        ofxSodaLib soda;
        string documentPath;
        void audioReceived(float * input, int bufferSize, int nChannels);
        void audioRequested(float * output, int bufferSize, int nChannels);
    
        //  coremotion & 3D
        ofxCoreMotion coreMotion;
        ofCamera camera;
        ofNode mCamRig;
        ofNode thirdEye;
        ofVec3f mUp;
        ofQuaternion landscapeFix;
    
        ofVec2f touchPos;
        ofVec2f pTouchPos;
    
        SpatialSound soundA, soundB;
};


