#pragma once
#include "ofMain.h"

class Cell {
public:
    Cell(int x, int y, int w, int h);
    void display(ofVec2f mPos);
    int mX;
    int mY;
    int mW;
    int mH;
    
    float brightness;
};