#include "DataStream.h"

void DataStream::update() {
    mTick++;
    valHistory.push_back( mValue );
    if( valHistory.size() >= 400 ){
        valHistory.erase(valHistory.begin(), valHistory.begin()+1);
    }
}

void DataStream::drawNoiseData(int x, int y) {
    mValue = ofRandom(1);
    
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(x, y, 0);
    
    ofSetColor(225);
    ofDrawBitmapString("Noisy data", 4, 18);
    ofNoFill();
    ofDrawRectangle(0, 0, 400, 100);
    
    if(mCursorOver) {
        ofSetColor(245);
    }else {
        ofSetColor(100);
    }
    ofFill();
    ofBeginShape();
    for (unsigned int i = 0; i < valHistory.size(); i++){
        if( i == 0 ) ofVertex(i, 100);
        ofVertex(i, 100 - valHistory[i] * 70);
        if( i == valHistory.size() -1 ) ofVertex(i, 100);
    }
    ofEndShape(false);
    
    ofPopMatrix();
    ofPopStyle();
}

void DataStream::drawHarmonicData(int x, int y) {
    mValue = (sin(mTick * 0.1) + 1) / 2;
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(x, y, 0);
    
    ofSetColor(225);
    ofDrawBitmapString("Harmonic data", 4, 18);
    ofNoFill();
    ofDrawRectangle(0, 0, 400, 100);
    
    if(mCursorOver) {
        ofSetColor(245);
    }else {
        ofSetColor(100);
    }
    ofFill();
    ofBeginShape();
    for (unsigned int i = 0; i < valHistory.size(); i++){
        if( i == 0 ) ofVertex(i, 100);
        ofVertex(i, 100 - valHistory[i] * 70);
        if( i == valHistory.size() -1 ) ofVertex(i, 100);
    }
    ofEndShape(false);
    
    ofPopMatrix();
    ofPopStyle();

}

void DataStream::drawBrownData(int x, int y) {
    if(mTick%10==0) mValue = ofClamp((sin(mTick * 0.005) + 1) / 2 + ofRandom(0.5),0,1);
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(x, y, 0);
    
    ofSetColor(225);
    ofDrawBitmapString("Brownian data", 4, 18);
    ofNoFill();
    ofDrawRectangle(0, 0, 400, 100);
    
    if(mCursorOver) {
        ofSetColor(245);
    }else {
        ofSetColor(100);
    }
    ofFill();
    ofBeginShape();
    for (unsigned int i = 0; i < valHistory.size(); i++){
        if( i == 0 ) ofVertex(i, 100);
        ofVertex(i, 100 - valHistory[i] * 70);
        if( i == valHistory.size() -1 ) ofVertex(i, 100);
    }
    ofEndShape(false);
    
    ofPopMatrix();
    ofPopStyle();
}

void DataStream::drawGestureData(int x, int y, float acc) {
    mValue = ofClamp(acc,0,1);
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(x, y, 0);
    
    ofSetColor(225);
    ofDrawBitmapString("Gesture data", 4, 18);
    ofNoFill();
    ofDrawRectangle(0, 0, 400, 100);
    
    if(mCursorOver) {
        ofSetColor(245);
    }else {
        ofSetColor(100);
    }
    ofFill();
    ofBeginShape();
    for (unsigned int i = 0; i < valHistory.size(); i++){
        if( i == 0 ) ofVertex(i, 100);
        ofVertex(i, 100 - valHistory[i] * 70);
        if( i == valHistory.size() -1 ) ofVertex(i, 100);
    }
    ofEndShape(false);
    
    ofPopMatrix();
    ofPopStyle();
}

void DataStream::drawLinearData(int x, int y) {
    mValue = (mTick%100) / 100.;
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(x, y, 0);
    
    ofSetColor(225);
    ofDrawBitmapString("Linear data", 4, 18);
    ofNoFill();
    ofDrawRectangle(0, 0, 400, 100);
    
    if(mCursorOver) {
        ofSetColor(245);
    }else {
        ofSetColor(100);
    }
    ofFill();
    ofBeginShape();
    for (unsigned int i = 0; i < valHistory.size(); i++){
        if( i == 0 ) ofVertex(i, 100);
        ofVertex(i, 100 - valHistory[i] * 70);
        if( i == valHistory.size() -1 ) ofVertex(i, 100);
    }
    ofEndShape(false);
    
    ofPopMatrix();
    ofPopStyle();

}