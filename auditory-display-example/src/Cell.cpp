#include "Cell.h"

Cell::Cell(int x, int y, int w, int h) {
    mX = x;
    mY = y;
    mW = w;
    mH = h;
    brightness = 0;
}

void Cell::display(ofVec2f mPos) {
    ofNoFill();
    ofSetColor(255,50);
    ofDrawRectangle(mX, mY, mW, mH);
    ofFill();
    ofSetColor(255,brightness*255);
    ofDrawRectangle(mX,mY,mW,mH);
    if((mPos.x>mX && mPos.x<mX+mW) && (mPos.y>mY&&mPos.y<mY+mH)) {
        brightness = 1;
    }else {
        if(brightness>0) brightness -= 0.005;
    }
}