#pragma once
#include "ofxNetwork.h"
#include "ofxStateMachine.h"
#include "SharedData.h"
#include "ofxGui.h"
#include "States.h"
#include "UDPSender.h"
#include "midiController.h"
#include "ofMain.h"
#include "midiEvent.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
        void onMidiEvent(midiEvent & event);

        void nextTrack();
        void prevTrack();

    
    
        int guiXpos,guiYpos;
        bool eventLoaded;
    
        ofFbo fbo;
    
    
        int numStrips,stripHeight, stripWidth,numColumns;
        int bufferSize, sampleRate;
        
        vector<string> songs;
        int currentStateIndex,currentState;
        int previewScale;
        int maxWhite;
    
    
 
        midiController controller;
        UDPSender sender;
    
        ofTrueTypeFont font;
    

    private:
        itg::ofxStateMachine<SharedData> stateMachine;
    
    
    
};
