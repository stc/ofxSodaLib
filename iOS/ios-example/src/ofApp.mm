#include "ofApp.h"

void ofApp::setup(){
    //  avoid screenlock
    [[UIApplication sharedApplication] setIdleTimerDisabled:YES];
    
    int ticksPerBuffer = 8; // 8 * 64 = buffer len of 512
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
    
    /*
    NSString *documentDeprecatedFolderPath = [documentsDirectory stringByAppendingPathComponent:@"sodalib"];
    [[NSFileManager defaultManager] removeItemAtPath:documentDeprecatedFolderPath error:nil];
    */
    
    documentPath = ofxiOSGetDocumentsDirectory();
    soda.init(documentPath + "sodalib/");
    
    // soda.createSampler("sample","sounds/s1.wav",10);
    
    soda.createFreezer("freeze", "sounds/flute_d.wav");
}

void ofApp::update(){}

void ofApp::draw(){
	
}

void ofApp::exit(){}

void ofApp::touchDown(ofTouchEventArgs & touch){
    //soda.set("sample")->shift(touch.y / float(ofGetHeight()))->play();
    
}
void ofApp::touchMoved(ofTouchEventArgs & touch){
    soda.set("freeze")->shift(touch.y / float(ofGetHeight()))->volume(1)->depth(0.2)->play();
}
void ofApp::touchUp(ofTouchEventArgs & touch){
    soda.set("freeze")->volume(0);
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

