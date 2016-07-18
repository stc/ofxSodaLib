#pragma once
#include "ofMain.h"

class DataObject {
public:
    DataObject(ofVec2f p);
    void draw(ofColor c);
    ofVec2f mPos;
    float mSize;
    bool canPlay = true;
    float fade;
};