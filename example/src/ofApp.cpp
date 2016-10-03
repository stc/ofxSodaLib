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
    ofDrawLine(ofGetWidth()/2,ofGetHeight()/4,ofGetWidth()/2,ofGetHeight()-ofGetHeight()/4);
    if(mouseX<ofGetWidth()/2) {
        ofDrawBitmapString("NOISE TEXTURE", 100, ofGetHeight()/2);
    } else {
        ofDrawBitmapString("SYNTHESIS", ofGetWidth()/2+100, ofGetHeight()/2);
    }
    
    ofSetColor(245, 58, 135);
    ofDrawCircle(cPosition,cSize);
    if(cSize) cSize--;
}

void ofApp::keyPressed(int key){}
void ofApp::keyReleased(int key){}
void ofApp::mouseMoved(int x, int y ){}
void ofApp::mouseDragged(int x, int y, int button){
    if(mouseX>ofGetWidth()/2) {
        soda.set("mySynth")->pan(1)->volume(1)->depth(ofMap(mouseX,ofGetWidth()/2,ofGetWidth(),1,0))->shift(mouseY / float(ofGetHeight()))->play();
        soda.set("myTexture")->volume(0);
    } else {
        soda.set("myTexture")->pan(0)->volume(0.5)->depth(ofMap(mouseX,ofGetWidth()/2,0,1,0))->shift(mouseY / float(ofGetHeight()))->play();
        soda.set("mySynth")->volume(0);
    }
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

