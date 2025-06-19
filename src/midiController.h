
#pragma once

#include "ofMain.h"
#include "ofxMidi.h"
#include "SharedData.h"
#include "ofxState.h"
#include "midiEvent.h"

class midiController : public ofxMidiListener {
	
public:
	
	void setup();
	void update();
	void draw();
	void exit();
	

	/// direct message handling
	/// ofxMidiListener callback, called by ofxMidiIn instance if set as listener
	/// note: this is not needed if you use queued message passing
	void newMidiMessage(ofxMidiMessage &msg);
	
	ofxMidiIn midiIn;
	std::vector<ofxMidiMessage> midiMessages; ///< received messages
	std::size_t maxMessages = 10; ///< max number of messages to keep track of
    std::vector<float> controlValues;
};
