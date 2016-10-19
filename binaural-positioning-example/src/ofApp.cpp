#include "ofApp.h"


void ofApp::setup(){
    int ticksPerBuffer = 8; // 8 * 64 = buffer len of 512
    ofSoundStreamSetup(2, 2, this, 44100, ofxPd::blockSize()*ticksPerBuffer, 3);
    soda.init();
    soda.createSynth("s", "triwave", "D");
    ofBackground(60);
}

void ofApp::update(){}

void ofApp::draw(){
    // distance to fade out
    float mMaxDistance = 300;
    float elevation = 70; // degrees
    
    // sound location
    ofVec2f mSoundHorizontalLocation = ofVec3f(mouseX,mouseY);
    // stage center (head) location
    ofVec3f mCenter = ofVec3f(ofGetWidth()/2, ofGetHeight()/2, 0);
    // angle (mapped to 0 - 1 from 0 - 360 )
    float mAzimuth = getAngleFromPoint2D(mCenter, mSoundHorizontalLocation);
    // distance ( mapped to 0 - 1 from 0 - maximum distance to fade out)
    float mDistance = ofClamp((mMaxDistance - mSoundHorizontalLocation.distance(mCenter))/mMaxDistance,0,1);
    // elevation ( mapped to 0 - 1 from -40 90 )
    float mElevation = ofMap(elevation,-40,90,0,1);
    
    ofFill();
    ofSetCircleResolution(120);
    ofSetColor(255);
    ofDrawCircle(mCenter,20);
    ofSetColor(60);
    ofDrawCircle(mCenter,5);
    
    ofNoFill();
    ofSetColor(255,100);
    ofDrawCircle(mCenter,300);
    
    ofFill();
    ofSetColor(77,192,255,mDistance * 255);
    ofDrawCircle(mSoundHorizontalLocation,10);
    ofDrawLine(mCenter, mSoundHorizontalLocation);
    
    soda.set("s")->pan(mAzimuth,mDistance,mElevation)->play();
    
    for(int i=0; i< orbits.size(); i++) {
        orbits[i].draw();
        float tmpAzimuth = getAngleFromPoint2D(mCenter, orbits[i].mPos);
        float tmpDistance = ofClamp((mMaxDistance - orbits[i].mPos.distance(mCenter))/mMaxDistance,0,1);
        soda.set("s-" + ofToString(i))->pan(tmpAzimuth, tmpDistance, mElevation)->play();
    }
}

float ofApp::getAngleFromPoint2D(ofVec2f center, ofVec2f pos) {
    float azimuth = atan2(pos.y - center.y, pos.x - center.x);
    float mappedAzimuth;
    if(azimuth<0) {
        mappedAzimuth = ofRadToDeg(azimuth) + 360;
    } else {
        mappedAzimuth = ofRadToDeg(azimuth);
    }
    float remappedAzimuth;
    if(mappedAzimuth>=90) {
        remappedAzimuth = mappedAzimuth-90;
    } else {
        remappedAzimuth = mappedAzimuth + 270;
    }
    float destAzimuth = remappedAzimuth;
    return destAzimuth/360;
}

void ofApp::keyPressed(int key){
    if(key == ' ') {
        ofVec2f v = ofVec2f(ofRandom(ofGetWidth()/2) + ofGetWidth()/4,ofRandom(ofGetHeight()));
        orbits.push_back(Orbit(v, ofRandom(100) + 50,(ofRandom(2)-1)/20));
        soda.createSynth("s-"+ofToString(index), "triwave", notes[int(ofRandom(7))]);
        soda.set("s-"+ofToString(index))->shift(ofRandom(0.5) + 0.2);
        index++;
    }
}
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

