#include "SodaObject.h"
#include "ofxSodaLib.h"

SodaObject::SodaObject(string name) {
    mName = name;
    mShift = 1;
    mVolume = 1;
    mDepth = -1; // disabled by default to save cpu
    mPan = 0.5;
}

SodaObject::SodaObject(string name, bool objNotFoundError) {
    cout << "Error, could not find Soda Object with name: " + name << endl;
}

void SodaObject::debug() {
    cout << mName << " shift: " << mShift << " volume: " << mVolume << " pan: " << mPan << endl;
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

SodaObject * SodaObject::depth(float depth) {
    mDepth = ofClamp(depth,0,1);
    return this;
}

void SodaObject::play() {
    List myList;
    myList.addFloat(mShift);
    myList.addFloat(mVolume);
    myList.addFloat(mPan);
    myList.addFloat(mDepth);
    ofxSodaLib::pd.sendList(mName, myList);
}
 
SodaObject * SodaObject::pan(float pan) {
    mPan = ofClamp(pan,0,1);
    return this;
}

