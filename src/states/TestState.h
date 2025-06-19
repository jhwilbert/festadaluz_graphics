
#pragma once

#include "ofxState.h"
#include "SharedData.h"

class TestState : public itg::ofxState<SharedData>
{
public:
	void update();
	void draw();
    void setup();
	string getName();
    void keyPressed(int key);
    
    float noiseScale, offsetX, offsetY;
    int numColumns, stripHeight, stripWidth;
    vector<ofColor> colors;
    int cnt;
    
};
