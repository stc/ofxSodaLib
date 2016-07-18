#include "ofxSodaLib.h"

ofxPd ofxSodaLib::pd;

void ofxSodaLib::init() {
    if(!pd.init( 2, 2, 44100, 8)) {
        OF_EXIT_APP(1);
    }
    pdFolder = "lib/";
    pd.addReceiver(*this);
    pd.start();
    patch = pd.openPatch(pdFolder + "main.pd");
}

void ofxSodaLib::createCustomObject(string objectName) {
    List myList;
    myList.addSymbol("blocks/custom/customObjectGenerator");
    myList.addSymbol(objectName);
    pd.sendList("createCustomObject", myList);
    SodaObject* o = new SodaObject(objectName);
    objects.insert(make_pair(objectName,o));
}

void ofxSodaLib::createCustomObject(string objectName, string customPatchName) {
    List myList;
    myList.addSymbol("blocks/custom/" + customPatchName);
    myList.addSymbol(objectName);
    pd.sendList("createCustomObject", myList);
    SodaObject* o = new SodaObject(objectName);
    objects.insert(make_pair(objectName,o));
}

void ofxSodaLib::createSynth(string objectName, string type, string note) {
    List myList;
    myList.addSymbol("blocks/synthesis/synthGenerator");
    myList.addSymbol(objectName);
    myList.addSymbol(type);
    myList.addSymbol(note);
    myList.addSymbol(objectName + "-ch");
    pd.sendList("createSynth", myList);
    SodaObject* o = new SodaObject(objectName);
    objects.insert(make_pair(objectName,o));
}

void ofxSodaLib::createSampler(string objectName, string fileName, int numberOfPolyphony) {
    List myList;
    myList.addSymbol("blocks/sampling/samplerGenerator");
    myList.addSymbol(objectName);
    myList.addSymbol("../../" + fileName); // sound is in the "sounds" folder, relative to patch
    myList.addFloat(numberOfPolyphony);
    myList.addFloat(44100);
    pd.sendList("createSynth", myList);
    SodaObject* o = new SodaObject(objectName);
    objects.insert(make_pair(objectName,o));
}

void ofxSodaLib::createTexture(string objectName, float resonance) {
    List myList;
    myList.addSymbol("blocks/texture/textureGenerator");
    myList.addSymbol(objectName);
    myList.addFloat(resonance);
    pd.sendList("createTexture", myList);
    SodaObject* o = new SodaObject(objectName);
    objects.insert(make_pair(objectName,o));
}

void ofxSodaLib::clear() {
    objects.clear();
    List myList;
    pd.sendMessage("clearObjects", "clear", myList);
}

void ofxSodaLib::save() {
    List myList;
    pd.sendMessage("saveObjects", "menusave", myList);
    pd.closePatch(patch);
    patch = pd.openPatch(pdFolder + "main.pd");
}

void ofxSodaLib::computeAudio(string objectName, int onOff){
    List myList;
    myList.addSymbol(objectName);
    myList.addFloat(onOff);
    pd.sendList("computeAudio", myList);
}

SodaObject* ofxSodaLib::set(string objectName) {
    auto iter = objects.find(objectName);
    if (iter != objects.end() ) {
        SodaObject* o = objects.at(objectName);
        return o;
    } else {
        // handle if no object exists with name
        SodaObject* o = new SodaObject(objectName, true);
        return o;
    }
}

SodaObject* ofxSodaLib::get(string objectName) {
    auto iter = objects.find(objectName);
    if (iter != objects.end() ) {
        SodaObject* o = objects.at(objectName);
        return o;
    } else {
        // handle if no object exists with name
        SodaObject* o = new SodaObject(objectName, true);
        return o;
    }
}

void ofxSodaLib::audioReceived(float * input, int bufferSize, int nChannels) {
    pd.audioIn( input, bufferSize, nChannels );
}

void ofxSodaLib::audioRequested(float * output, int bufferSize, int nChannels) {
    pd.audioOut(output, bufferSize, nChannels);
}
 
void ofxSodaLib::print(const std::string& message) {
	cout << message << endl;
}

