#include "ofApp.h"

void ofApp::setup(){
    ofSetOrientation(OF_ORIENTATION_90_LEFT);
    
    //  avoid screenlock
    [[UIApplication sharedApplication] setIdleTimerDisabled:YES];
    
    int ticksPerBuffer = 32; // larger buffer used (earplug is heavy)
    ofSoundStreamSetup(2, 2, this, 44100, ofxPd::blockSize()*ticksPerBuffer, 3);
    
    //  Copy SodaLib from application bundle to application's documents directory.
    //  This is needed for dynamic patching & saving in libPd
    
    NSFileManager *fileManager = [NSFileManager defaultManager];
    NSError *error;
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *documentsDirectory = [paths objectAtIndex:0];
    NSString *documentDBFolderPath = [documentsDirectory stringByAppendingPathComponent:@"sodalib"];
    NSString *resourceDBFolderPath = [[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:@"sodalib"];
    
    if (![fileManager fileExistsAtPath:documentDBFolderPath]) {
        //Create Directory!
        [fileManager createDirectoryAtPath:documentDBFolderPath withIntermediateDirectories:NO attributes:nil error:&error];
    } else {
        // NSLog(@"Directory exists! %@", documentDBFolderPath);
    }
    
    NSArray *fileList = [fileManager contentsOfDirectoryAtPath:resourceDBFolderPath error:&error];
    for (NSString *s in fileList) {
        NSString *newFilePath = [documentDBFolderPath stringByAppendingPathComponent:s];
        NSString *oldFilePath = [resourceDBFolderPath stringByAppendingPathComponent:s];
        if (![fileManager fileExistsAtPath:newFilePath]) {
            //File does not exist, copy it
            [fileManager copyItemAtPath:oldFilePath toPath:newFilePath error:&error];
        } else {
            // NSLog(@"File exists: %@", newFilePath);
        }
    }
    
    documentPath = ofxiOSGetDocumentsDirectory();
    soda.init(documentPath + "sodalib/");
    soda.createSampler("sample-1","sounds/s1.wav",1);
    soda.createSampler("sample-2","sounds/s1.wav",1);
    
    camera.setupPerspective();
    camera.setVFlip(false);
    camera.setPosition(0, 0, 0);
    
    coreMotion.setupAttitude(CMAttitudeReferenceFrameXMagneticNorthZVertical);
    camera.setParent(mCamRig);
    
    soundA = SpatialSound();
    soundB = SpatialSound();
    soundA.mPosition = ofVec2f(0,250);
    soundB.mPosition = ofVec2f(0,-250);
}

void ofApp::update(){
    coreMotion.update();
    ofQuaternion quat = coreMotion.getQuaternion();
    landscapeFix = ofQuaternion(-quat.y(), quat.x(), quat.z(), quat.w());
    camera.setOrientation(landscapeFix);
    thirdEye.setOrientation(camera.getOrientationQuat() * mCamRig.getOrientationQuat());
    mUp = thirdEye.getUpDir();
    soundA.update();
    soundB.update();
}

void ofApp::draw(){
    ofBackground(30);
    camera.begin();
    
    ofNoFill();
    ofSetColor(255,50);
    ofDrawSphere(0,0,100);
    ofSetColor(255);
    ofDrawCircle(0,0,500);
    soundA.draw(camera);
    soundB.draw(camera);
    camera.end();
    
    pTouchPos = touchPos;
    
    if(ofGetFrameNum() % 100 == 0) {
        float tmpAzimuth = soundA.mAngle;
        float tmpDistance = 0.5;
        float mElevation = 0;
        
        soda.set("sample-1")->pan(tmpAzimuth, tmpDistance, mElevation)->play();
        soundA.mSoundTrigger = 255;
    }
    
    if(ofGetFrameNum() % 120 == 0) {
        float tmpAzimuth = soundB.mAngle;
        float tmpDistance = 0.5;
        float mElevation = 0;
        
        soda.set("sample-2")->shift(0.8)->pan(tmpAzimuth, tmpDistance, mElevation)->play();
        soundB.mSoundTrigger = 255;
    }
    
    cout << ofGetFrameRate() << endl;
}


void ofApp::exit(){}

void ofApp::touchDown(ofTouchEventArgs & touch){
    touchPos = ofVec2f(touch.x,touch.y);
}
void ofApp::touchMoved(ofTouchEventArgs & touch){
    touchPos = ofVec2f(touch.x,touch.y);
    pTouchPos = touchPos;
}
void ofApp::touchUp(ofTouchEventArgs & touch){
    touchPos = ofVec2f(touch.x,touch.y);
    pTouchPos = touchPos;
}
void ofApp::touchDoubleTap(ofTouchEventArgs & touch){}
void ofApp::touchCancelled(ofTouchEventArgs & touch){}
void ofApp::lostFocus(){}
void ofApp::gotFocus(){}
void ofApp::gotMemoryWarning(){}
void ofApp::deviceOrientationChanged(int newOrientation){}

void ofApp::audioReceived(float * input, int bufferSize, int nChannels) {
    soda.audioReceived(input, bufferSize, nChannels);
}

void ofApp::audioRequested(float * output, int bufferSize, int nChannels) {
    soda.audioRequested(output, bufferSize, nChannels);
}

