#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofSetupOpenGL(1024,500,OF_WINDOW);			// <-------- setup the GL context
	ofRunApp(new ofApp());
}
