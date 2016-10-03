#include "SodaObject.h"
#include "ofxSodaLib.h"

SodaObject::SodaObject(string name) {
    mName = name;
    mShift = 1;
    mVolume = 1;
    mPan = 0.5;
}

SodaObject::SodaObject(string name, bool objNotFoundError) {
    cout << "Error, could not find Soda Object with name: " + name << endl;
}

void SodaObject::debug() {
    cout << mName << " shift: " << mShift << " volume: " << mVolume << " pan: " << mPan << endl;
}

SodaObject * SodaObject::shift(float shift) {
    mShift = shift;
    return this;
}

SodaObject * SodaObject::volume(float volume) {
    mVolume = volume;
    if(volume == 0) play();
    return this;
}

void SodaObject::play() {
    List myList;
    myList.addFloat(mShift);
    myList.addFloat(mVolume);
    myList.addFloat(mPan);
    ofxSodaLib::pd.sendList(mName, myList);
}
 
SodaObject * SodaObject::pan(float pan) {
    mPan = pan;
    return this;
}

