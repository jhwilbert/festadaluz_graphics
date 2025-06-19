#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundColor(30);
    ofSetFrameRate(60);
    ofDisableAntiAliasing();
    ofDisableAlphaBlending();
    ofSetLogLevel(OF_LOG_ERROR);
    
    // Display settings
    stripHeight = 60;
    stripWidth = 1;
    previewScale = 4;
    numColumns = 12;
    
    // Preview
    guiXpos = ofGetWidth()-250;
    guiYpos = 40;
    
    font.load("verdana.ttf",30);
    
    stateMachine.getSharedData().stripHeight = stripHeight;
    stateMachine.getSharedData().stripWidth = stripWidth;
    stateMachine.getSharedData().numColumns = numColumns;
    stateMachine.getSharedData().guiXpos = guiXpos;
    stateMachine.getSharedData().guiYpos = guiYpos;
    
    stateMachine.getSharedData().maxWhite = 255;
    stateMachine.getSharedData().midWhite = 127;
    

    stateMachine.addState<TestState>();
    currentState = 0;

    // Setup State Machine
    stateMachine.changeState("TestState");
    
    // Setup UDP Sender
    sender.setup(numColumns,stripHeight,stripWidth);
    
    
    // FBO Settings
    fbo.allocate(numColumns,stripHeight,GL_RGB);
    

}


void ofApp::update(){
  
    
    // Draw FBO
    
    fbo.begin();
    ofClear(0,0,0);
    
    stateMachine.draw();
    fbo.end();

    // Send Fbo as UDP
    sender.sendFbo(fbo);
    
    // Update Preview
    sender.update();
    

    
}

void ofApp::draw(){
    
    ofSetColor(255);
    
    // Draw State Text
    ofSetColor(255);

    
    // Draw Sender
    sender.draw();


}

//--------------------------------------------------------------

void ofApp::keyPressed(int key){
    if(key == 'f') {
        ofToggleFullscreen();
    }
}

