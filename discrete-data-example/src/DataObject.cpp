#include "DataObject.h"

DataObject::DataObject(ofVec2f p) {
    mPos = p;
    mSize = 5;
    fade = 0;
}

void DataObject::draw(ofColor c) {
    ofSetColor(c);
    ofMesh meshUp;
    meshUp.addVertex(ofVec2f(mPos.x-mSize,mPos.y));
    meshUp.addVertex(ofVec2f(mPos.x,mPos.y-mSize));
    meshUp.addVertex(ofVec2f(mPos.x+mSize,mPos.y));
    meshUp.draw();
    
    ofSetColor(c,100);
    ofMesh meshDown;
    meshDown.addVertex(ofVec2f(mPos.x-mSize,mPos.y));
    meshDown.addVertex(ofVec2f(mPos.x,mPos.y+mSize));
    meshDown.addVertex(ofVec2f(mPos.x+mSize,mPos.y));
    meshDown.draw();
    
    ofSetColor(c, fade);
    ofDrawCircle(mPos,mSize*2);
    fade-=10;
}