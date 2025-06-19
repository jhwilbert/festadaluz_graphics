#pragma once

#include "ofMain.h"
#include "ofxNetwork.h"
#include "ofxStateMachine.h"
#include "SharedData.h"
#include "ofxGui.h"
#include "States.h"
#include "UDPSender.h"

// Detect if we should have a display
#ifdef TARGET_OSX
#define HAS_DISPLAY 1
#else
#define HAS_DISPLAY 0
#endif

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);


    int guiXpos, guiYpos;
    bool eventLoaded;

#if HAS_DISPLAY
    ofFbo fbo;
    ofTrueTypeFont font;
#endif

    int numStrips, stripHeight, stripWidth, numColumns;
    int bufferSize, sampleRate;
    vector<string> songs;
    int currentStateIndex, currentState;
    int previewScale;
    int maxWhite;

    UDPSender sender;

private:
    itg::ofxStateMachine<SharedData> stateMachine;
};
