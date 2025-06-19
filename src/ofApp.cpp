#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
#if HAS_DISPLAY
    ofSetBackgroundColor(30);
    ofSetFrameRate(60);
    ofDisableAntiAliasing();
    ofDisableAlphaBlending();
#endif

    ofSetLogLevel(OF_LOG_ERROR);

    stripHeight = 60;
    stripWidth = 1;
    previewScale = 4;
    numColumns = 12;

    guiXpos = ofGetWidth() - 250;
    guiYpos = 40;

#if HAS_DISPLAY
    font.load("verdana.ttf", 30);
    fbo.allocate(numColumns, stripHeight, GL_RGB);
#endif

    stateMachine.getSharedData().stripHeight = stripHeight;
    stateMachine.getSharedData().stripWidth = stripWidth;
    stateMachine.getSharedData().numColumns = numColumns;
    stateMachine.getSharedData().guiXpos = guiXpos;
    stateMachine.getSharedData().guiYpos = guiYpos;
    stateMachine.getSharedData().maxWhite = 255;
    stateMachine.getSharedData().midWhite = 127;

    stateMachine.addState<TestState>();  // Adjust to your actual state names
    currentState = 0;
    stateMachine.changeState("TestState");

    sender.setup(numColumns, stripHeight, stripWidth);
}

//--------------------------------------------------------------
void ofApp::update() {
#if HAS_DISPLAY
    fbo.begin();
    ofClear(0, 0, 0);
    stateMachine.draw();
    fbo.end();

    sender.sendFbo(fbo);
    sender.update();
#endif
}

//--------------------------------------------------------------
void ofApp::draw() {
#if HAS_DISPLAY
    ofSetColor(255);
    sender.draw();
#endif
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
#if HAS_DISPLAY
    if (key == 'f') {
        ofToggleFullscreen();
    }
#endif
}

