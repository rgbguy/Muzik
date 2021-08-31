#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    music.load("audio.mp3");
    
    fftsmooth = new float[8129];
    for (int i = 0; i < 8129; i++) {
        fftsmooth[i] = i;
    }
    bands = 64;
    
    music.setVolume(0.6f);

    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSoundUpdate();
    float * value = ofSoundGetSpectrum(bands);
    for (int i = 0; i < bands; i++) {
        fftsmooth[i] *= 0.9f;
        if (fftsmooth[i] < value[i]) {
            fftsmooth[i] = value[i];
        }
    }
    
    if(ball) ball->Update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofNoFill();
    for (int i = 0; i < bands; i++) {
        //ofSetCircleResolution(ofGetElapsedTimef()/10);
        if((fftsmooth[i]*1500) > 150)
        {
            ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, (fftsmooth[i]*1500));
        }
    }
    if(ball) ofDrawCircle(ball->position.x, ball->position.y, 10.0f);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 32)
    {
        if(!music.isPlaying())
        {
            music.play();
        }
        else music.stop();
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    ball = new Ball(x, y);

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
