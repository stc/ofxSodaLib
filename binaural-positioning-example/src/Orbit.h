#pragma once
#include "ofMain.h"

class Orbit {
public:
    ofVec2f cPos;
    ofVec2f mPos;
    float mVel;
    float mCount;
    float mRad;
    Orbit(ofVec2f centerPos, float rad, float vel);
    void draw();
};
