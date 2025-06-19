#include "midiController.h"

//--------------------------------------------------------------
void midiController::setup() {
	//ofSetLogLevel(OF_LOG_VERBOSE);

	// print input ports to console
	midiIn.listInPorts();

	midiIn.openPort(0);
	midiIn.ignoreTypes(false, false, false);
    midiIn.addListener(this);
    midiIn.setVerbose(true);
    
    controlValues.resize(24, 0.0f);
}

//--------------------------------------------------------------
void midiController::update() {

	/// queued message handling
	if(midiIn.hasWaitingMessages()) {
		ofxMidiMessage message;

		// add the latest message to the message queue
		while(midiIn.getNextMessage(message)) {
			midiMessages.push_back(message);
		}

		// remove any old messages if we have too many
		while(midiMessages.size() > maxMessages) {
			midiMessages.erase(midiMessages.begin());
		}
	}
}

//--------------------------------------------------------------
void midiController::draw() {

    

}

//--------------------------------------------------------------
void midiController::exit() {

	midiIn.closePort();
	midiIn.removeListener(this);
}

//--------------------------------------------------------------
void midiController::newMidiMessage(ofxMidiMessage &msg) {
    midiEvent midiEvent(msg.control, msg.value);
    ofNotifyEvent(midiEvent::events, midiEvent);
   
}


