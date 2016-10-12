#include "ofApp.h"

void ofApp::setup(){
    int ticksPerBuffer = 8; // 8 * 64 = buffer len of 512
    ofSoundStreamSetup(2, 2, this, 44100, ofxPd::blockSize()*ticksPerBuffer, 3);
    soda.init();
    
    // populate cells of the display
    rows = 10;
    cols = 5;
    int index = 0;
    
    for(int i=0; i<rows; i++) {
        vector< Cell *> c;
        for(int j=0; j<cols; j++) {
            c.push_back( new Cell(j * ofGetWidth() / float(cols), i * ofGetHeight() / float(rows),
                        ofGetWidth() / float(cols), ofGetHeight() / float(rows)) );
            
            // create filtered noise soda object with q-frequency 40
            soda.createTexture("soda-" + ofToString(index), 40 );
            
            // setup shift for this object, based on its row index
            soda.set("soda-" + ofToString(index))->shift(ofMap(i/float(rows),0,1,0.6,0.2));
            
            // setup pan for the soda object based on its col index
            soda.set("soda-" + ofToString(index))->pan(j/float(cols));
            
            index++;
        }
        cells.push_back(c);
    }
}

void ofApp::update(){}

void ofApp::draw(){
    ofBackground(0);
    int index = 0;
    for (auto cellRow : cells) {
        for(auto cell : cellRow) {
            cell->display(ofVec2f(mouseX,mouseY));
            soda.set("soda-" + ofToString(index))->volume(cell->brightness)->play();
            index++;
        }
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

