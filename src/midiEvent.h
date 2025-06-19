#ifndef MIDI_EVENT_H
#define MIDI_EVENT_H

#include "ofMain.h"

class midiEvent : public ofEventArgs {
public:
    int control;
    int value;

    // You can add more data members if needed

    midiEvent(int control, int value) : control(control), value(value) {}

    static ofEvent<midiEvent> events;
};

#endif // CUSTOM_EVENT_H
