#include "SodaObject.h"
#include "ofxSodaLib.h"

SodaObject::SodaObject(string name) {
    mName = name;
    mShift = 1;
    mVolume = 1;
    mDepth = -1; // disabled by default to save cpu
    mPan.push_back(0.5);
    // disable binaural panning by default to save cpu
    mPan.push_back(-1);
    mPan.push_back(-1);
}

SodaObject::SodaObject(string name, bool objNotFoundError) {
    cout << "Error, could not find Soda Object with name: " + name << endl;
}

SodaObject * SodaObject::shift(float shift) {
    mShift = ofClamp(shift,0,1);
    return this;
}

SodaObject * SodaObject::volume(float volume) {
    mVolume = ofClamp(volume,0,1);
    if(volume == 0) {
        play();
    }
    return this;
}

SodaObject * SodaObject::pan(float pan) {
    mPan[0] = ofClamp(pan,0,1);
    mPan[1] = -1;
    mPan[2] = -1;
    return this;
}

SodaObject * SodaObject::pan(float azimuth, float distance, float elevation) {
    mPan[0] = ofClamp(azimuth,0,1);
    mPan[1] = ofClamp(distance,0,1);
    mPan[2] = ofClamp(elevation,0,1);
    return this;
}

SodaObject * SodaObject::depth(float depth) {
    mDepth = ofClamp(depth,0,1);
    return this;
}

void SodaObject::play() {
    ofxSodaLib::pd.sendFloat(mName + "-depth", mDepth);
    List mList;
    for( auto e : mPan) mList.addFloat(e);
    ofxSodaLib::pd.sendList(mName + "-pan", mList);
    ofxSodaLib::pd.sendFloat(mName + "-vol", mVolume);
    ofxSodaLib::pd.sendFloat(mName + "-shift", mShift);
}
 

