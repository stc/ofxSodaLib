#include "Orbit.h"

Orbit::Orbit(ofVec2f centerPos, float rad, float vel) {
    cPos = centerPos;
    mVel = vel;
    mRad = rad;
}

void Orbit::draw() {
    ofSetColor(255,200);
    mPos = ofVec2f(cPos.x + sin(mCount) * mRad, cPos.y + cos(mCount) * mRad);
    ofFill();
    ofDrawCircle(mPos, 5);
    mCount += mVel;
    
    ofNoFill();
    ofSetColor(255,50);
    ofDrawCircle(cPos,mRad);
    ofDrawLine(cPos,mPos);
}
