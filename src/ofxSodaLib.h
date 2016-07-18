#pragma once
#include "ofMain.h"
#include "ofxPd.h"
#include "SodaObject.h"

using namespace pd;

class ofxSodaLib : public PdReceiver, public PdMidiReceiver {
public:
    void init();
    void clear();
    void save();
    void computeAudio(string objectName, int onOff);
    SodaObject* set(string objectName);
    SodaObject* get(string objectName);
    
    void createSynth(string objectName, string type, string note);
    void createSampler(string objectName, string fileName, int numberOfPolyphony);
    void createTexture(string objectName, float resonance);
    void createCustomObject(string objectName);
    void createCustomObject(string objectName, string customPatchName);
    
    void audioReceived(float * input, int bufferSize, int nChannels);
    void audioRequested(float * output, int bufferSize, int nChannels);
    void print(const std::string& message);
    
    static ofxPd pd;
    Patch patch;
    string pdFolder;
    map< string, SodaObject* > objects;
};