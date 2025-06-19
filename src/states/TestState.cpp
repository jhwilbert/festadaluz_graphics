
#include "TestState.h"

void TestState::setup() {

    
    numColumns = getSharedData().numColumns;
    stripHeight = getSharedData().stripHeight;
    stripWidth = getSharedData().stripWidth;
    
    colors.resize(numColumns);
    
    
    colors[0] = ofColor(255, 0, 0); // R
    colors[1] = ofColor(0,255, 0); // G
    colors[2] = ofColor(0, 0, 255); //B
    colors[3] = ofColor(255, 255, 0); // Y

    colors[4] = ofColor(255, 0, 0); // R
    colors[5] = ofColor(0,255, 0); // G
    colors[6] = ofColor(0, 0, 255); //B
    colors[7] = ofColor(255, 255, 0); // Y

    colors[8] = ofColor(255, 0, 0); // R
    colors[9] = ofColor(0,255, 0); // G
    colors[10] = ofColor(0, 0, 255); //B
    colors[11] = ofColor(255, 255, 0); // Y

    cnt = 0;

}
void TestState::update() {

    if(ofGetFrameNum() % 20 == 0) {
        if(cnt == numColumns-1) {
            cnt = 0;
        } else {
            cnt += 1;
        }
    }


}

void TestState::draw() {
    ofSetColor(0);
    ofFill();
    ofDrawRectangle(0, 0, numColumns, stripHeight);

    for(int i = 0; i < numColumns; i++) {
        ofSetColor(255);
        ofDrawRectangle(i, stripHeight-i-1, stripWidth, i+1);
    }


    ofSetColor(255, 0, 0);
    ofDrawRectangle(cnt,0, stripWidth, stripHeight);
}

string TestState::getName()
{
	return "TestState";
}
void TestState::keyPressed(int key) {
    
    
}

