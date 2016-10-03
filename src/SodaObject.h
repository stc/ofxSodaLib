#pragma once
#include "ofMain.h"

class SodaObject {
public:
    SodaObject(string name);
    SodaObject(string name, bool objNotFoundError);
    
    string mName;
    float mShift;
    float mVolume;
    float mPan;
    float mDepth;
    
    SodaObject * shift(float shift);
    SodaObject * pan(float pan);
    SodaObject * volume(float volume);
    SodaObject * depth(float depth);
    
    void play();
    void debug();
};
