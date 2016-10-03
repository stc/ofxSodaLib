#include "ofApp.h"

void ofApp::setup(){
    int ticksPerBuffer = 8; // 8 * 64 = buffer len of 512
    ofSoundStreamSetup(2, 2, this, 44100, ofxPd::blockSize()*ticksPerBuffer, 3);
    soda.init();
    soda.clear();
    soda.createSampler("mySampler","sounds/sound.wav",10);
    soda.createSynth("mySynth", "triwave", "C");
    soda.createTexture("myTexture", 10);
    soda.save();
}

void ofApp::update(){}

void ofApp::draw(){
    ofBackground(34);
    ofSetColor(100);
    ofDrawBitmapString("click & drag the mouse to interact",20,20);
    ofDrawBitmapString("----------------------------------",20,40);
    ofSetColor(255);
    ofDrawBitmapString("mySampler pan: " + ofToString(soda.get("mySampler")->mPan),20,60);
    ofDrawBitmapString("mySampler pitch-shift: " + ofToString(soda.get("mySampler")->mShift),20,80);
    ofDrawBitmapString("mySynth volume: " + ofToString(soda.get("mySynth")->mVolume),20,100);
    ofDrawBitmapString("mySynth pitch-shift: " + ofToString(soda.get("mySynth")->mShift),20,120);
    ofDrawBitmapString("myTexture volume: " + ofToString(soda.get("myTexture")->mVolume),20,140);
    ofDrawBitmapString("myTexture pitch-shift: " + ofToString(soda.get("myTexture")->mShift),20,160);
    
    ofSetColor(245, 58, 135);
    ofDrawCircle(cPosition,cSize);
    if(cSize) cSize--;
}

void ofApp::keyPressed(int key){}
void ofApp::keyReleased(int key){}
void ofApp::mouseMoved(int x, int y ){}
void ofApp::mouseDragged(int x, int y, int button){
    soda.set("mySynth")->volume(mouseX / float(ofGetWidth()))->shift(mouseY / float(ofGetHeight()))->play();
    soda.set("myTexture")->volume(1 - mouseX / float(ofGetWidth()))->shift(mouseY / float(ofGetHeight()))->play();
}

void ofApp::mousePressed(int x, int y, int button){
    cPosition = ofVec2f(x,y);
    cSize = 20;
    soda.set("mySampler")->pan(mouseX / float(ofGetWidth()))->shift(mouseY / float(ofGetHeight()))->play();
}

void ofApp::mouseReleased(int x, int y, int button){
    soda.set("mySynth")->volume(0);
    soda.set("myTexture")->volume(0);
}

void ofApp::mouseEntered(int x, int y){}
void ofApp::mouseExited(int x, int y){}
void ofApp::windowResized(int w, int h){}
void ofApp::gotMessage(ofMessage msg){}
void ofApp::dragEvent(ofDragInfo dragInfo){}

void ofApp::audioReceived(float * input, int bufferSize, int nChannels) {
    soda.audioReceived(input, bufferSize, nChannels);
}

void ofApp::audioRequested(float * output, int bufferSize, int nChannels) {
    soda.audioRequested(output, bufferSize, nChannels);
}

