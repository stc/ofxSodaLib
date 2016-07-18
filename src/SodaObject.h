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
    
    void shift(float shift);
    void shift(float shift, bool trigger);
    void volume(float volume);
    void volume(float volume, bool trigger);
    void pan(float pan);
    void pan(float pan, bool trigger);
    void debug();
};