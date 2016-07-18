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

void SodaObject::shift(float shift) {
    mShift = shift;
    List myList;
    myList.addFloat(mShift);
    myList.addFloat(mVolume);
    myList.addFloat(mPan);
    ofxSodaLib::pd.sendList(mName, myList);
}

void SodaObject::shift(float shift, bool trigger) {
    mShift = shift;
    if(trigger) {
        List myList;
        myList.addFloat(mShift);
        myList.addFloat(mVolume);
        myList.addFloat(mPan);
        ofxSodaLib::pd.sendList(mName, myList);
    }
}

void SodaObject::volume(float volume) {
    mVolume = volume;
    List myList;
    myList.addFloat(mShift);
    myList.addFloat(mVolume);
    myList.addFloat(mPan);
    ofxSodaLib::pd.sendList(mName, myList);
 }
 
void SodaObject::volume(float volume, bool trigger) {
    mVolume = volume;
    if(trigger) {
        List myList;
        myList.addFloat(mShift);
        myList.addFloat(mVolume);
        myList.addFloat(mPan);
        ofxSodaLib::pd.sendList(mName, myList);
    }
}
 
void SodaObject::pan(float pan) {
    mPan = pan;
    List myList;
    myList.addFloat(mShift);
    myList.addFloat(mVolume);
    myList.addFloat(mPan);
    ofxSodaLib::pd.sendList(mName, myList);
}

void SodaObject::pan(float pan, bool trigger) {
    mPan = pan;
    if(trigger) {
        List myList;
        myList.addFloat(mShift);
        myList.addFloat(mVolume);
        myList.addFloat(mPan);
        ofxSodaLib::pd.sendList(mName, myList);
    }
}

