#pragma once
#include "ofMain.h"

class DataStream {
public:
    void update();
    void drawNoiseData(int x, int y);
    void drawHarmonicData(int x, int y);
    void drawBrownData(int x, int y);
    void drawLinearData(int x, int y);
    void drawGestureData(int x, int y, float acc);
    bool mCursorOver = false;
    int mTick;
    float mValue;
    vector <float> valHistory;
};