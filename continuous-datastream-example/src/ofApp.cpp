#include "ofApp.h"

void ofApp::setup(){
    int ticksPerBuffer = 8; // 8 * 64 = buffer len of 512
    ofSoundStreamSetup(2, 2, this, 44100, ofxPd::blockSize()*ticksPerBuffer, 3);
    
    // create SodaLib. please refer to the underlying concepts,
    // creation arguments & function details in the readme file
    
    soda.init();
    soda.clear();
    soda.createSynth("noise","triwave","C");
    soda.createSynth("harmonic","triwave","Eb");
    soda.createSynth("brownian","triwave","F");
    soda.createSynth("gesture","triwave","G");
    soda.createSynth("linear","triwave","A");
    soda.save();
}

void ofApp::update(){
    noiseData.update();
    harmonicData.update();
    brownianData.update();
    gestureData.update();
    linearData.update();
    switchCursor();
    
    // handle synths based on the data stream values.
    // would be much more effective with for loops & vectors
    // this example stands here for clarity
    
    if(noiseData.mCursorOver) {
        soda.set("noise")->volume(0.8, false);
        soda.set("noise")->shift(noiseData.mValue * 0.8);
    } else {
        soda.set("noise")->volume(0);
    }
    if(harmonicData.mCursorOver) {
        soda.set("harmonic")->volume(0.8, false);
        soda.set("harmonic")->shift(harmonicData.mValue * 0.8);
    } else {
        soda.set("harmonic")->volume(0);
    }
    if(brownianData.mCursorOver) {
        soda.set("brownian")->volume(0.8, false);
        soda.set("brownian")->shift(brownianData.mValue * 0.8);
    } else {
        soda.set("brownian")->volume(0);
    }
    if(gestureData.mCursorOver) {
        soda.set("gesture")->volume(0.8, false);
        soda.set("gesture")->shift(gestureData.mValue * 0.8);
    } else {
        soda.set("gesture")->volume(0);
    }
    if(linearData.mCursorOver) {
        soda.set("linear")->volume(0.8, false);
        soda.set("linear")->shift(linearData.mValue * 0.8);
    } else {
        soda.set("linear")->volume(0);
    }
}

void ofApp::draw(){
    ofBackground(34);
    listenToAll(100,200);
    
    noiseData.drawNoiseData(500,200);
    harmonicData.drawHarmonicData(500,300);
    brownianData.drawBrownData(100,300);
    gestureData.drawGestureData(100,400, speed / 10);
    linearData.drawLinearData(500,400);
    
    speed = ofVec2f(mouseX,mouseY).distance(pPos);
    
    pPos.x = mouseX;
    pPos.y = mouseY;
}

void ofApp::listenToAll(int x, int y) {
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(x, y, 0);
    
    ofSetColor(225);
    ofDrawBitmapString("Hover here to listen to all data at once", 4, 18);
    ofNoFill();
    ofDrawRectangle(0, 0, 400, 100);
    ofPopMatrix();
    ofPopStyle();
}

void ofApp::switchCursor() {
    if((mouseX>100 && mouseX < 500)&&(mouseY>200&&mouseY<300)) {
        noiseData.mCursorOver = true;
        harmonicData.mCursorOver = true;
        brownianData.mCursorOver = true;
        gestureData.mCursorOver = true;
        linearData.mCursorOver = true;
    }
    if((mouseX>500 && mouseX < 900)&&(mouseY>200&&mouseY<300)) {
        noiseData.mCursorOver = true;
        harmonicData.mCursorOver = false;
        brownianData.mCursorOver = false;
        gestureData.mCursorOver = false;
        linearData.mCursorOver = false;
    }
    if((mouseX>500 && mouseX < 900)&&(mouseY>300&&mouseY<400)) {
        noiseData.mCursorOver = false;
        harmonicData.mCursorOver = true;
        brownianData.mCursorOver = false;
        gestureData.mCursorOver = false;
        linearData.mCursorOver = false;
    }
    if((mouseX>100 && mouseX < 500)&&(mouseY>300&&mouseY<400)) {
        noiseData.mCursorOver = false;
        harmonicData.mCursorOver = false;
        brownianData.mCursorOver = true;
        gestureData.mCursorOver = false;
        linearData.mCursorOver = false;
    }
    if((mouseX>100 && mouseX < 500)&&(mouseY>400&&mouseY<500)) {
        noiseData.mCursorOver = false;
        harmonicData.mCursorOver = false;
        brownianData.mCursorOver = false;
        gestureData.mCursorOver = true;
        linearData.mCursorOver = false;
    }
    if((mouseX>500 && mouseX < 900)&&(mouseY>400&&mouseY<500)) {
        noiseData.mCursorOver = false;
        harmonicData.mCursorOver = false;
        brownianData.mCursorOver = false;
        gestureData.mCursorOver = false;
        linearData.mCursorOver = true;
    }
}

void ofApp::keyPressed(int key){}
void ofApp::keyReleased(int key){}
void ofApp::mouseMoved(int x, int y ){}
void ofApp::mouseDragged(int x, int y, int button){}
void ofApp::mousePressed(int x, int y, int button){}
void ofApp::mouseReleased(int x, int y, int button){}
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
