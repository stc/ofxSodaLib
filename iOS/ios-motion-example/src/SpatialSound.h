#pragma once
#include "ofMain.h"

class SpatialSound {
public:
    ofVec2f mPosition;
    float mSoundTrigger = 0;
    float mAngle = 0;
    
    //SpatialSound(ofVec2f position) {
    //    mPosition = position;
    //}
    
    void update() {
        if(mSoundTrigger>0) mSoundTrigger-=4;
    }
    
    void draw(ofCamera & camera) {
        ofSetColor(255,mSoundTrigger);
        ofDrawSphere(mPosition,10);
        mAngle = getAngleFromTwoVectors(mPosition, camera.getLookAtDir());
    }
    
    float getAngleFromTwoVectors(ofVec3f lookat, ofVec2f position) {
        float azimuth = position.angleRad(lookat);
        
        float mappedAzimuth;
        if(azimuth>=0 && azimuth <= PI) {
            mappedAzimuth = azimuth;
        } else if(azimuth< 0){
            mappedAzimuth = azimuth + TWO_PI;
        }
        return mappedAzimuth / TWO_PI;
    }
};
