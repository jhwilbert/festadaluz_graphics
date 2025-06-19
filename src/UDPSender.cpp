#include "UDPSender.h"
#include "SharedData.h"
//--------------------------------------------------------------
void UDPSender::setup(int _numColumns, int _stripHeight, int _stripWidth){
    
    /* Display settings */
    stripHeight = _stripHeight;
    stripWidth = _stripWidth;
    previewScale = 4;
    numColumns = _numColumns;
    
    /* Preview */
    previewSpace = 70;
    
    
    /* UDP Settings */
    ofxUDPSettings settings1;
    settings1.sendTo("192.168.1.179", 8888);
    settings1.blocking = false;
    udpConnection1.Setup(settings1);
    udpConnection2.Connect("192.168.1.179",8888);
    
    /* UDP Settings */
    ofxUDPSettings settings2;
    settings2.sendTo("192.168.1.180", 8888);
    settings2.blocking = false;
    udpConnection2.Setup(settings2);
    udpConnection2.Connect("192.168.1.180",8888);
    
    fbo.allocate(numColumns, stripHeight, GL_RGB);
    rotatedFbo.allocate(stripHeight, numColumns, GL_RGB);
    
    previewColums.resize(numColumns);
    
}

void UDPSender::sendFbo(ofFbo fbo) {
    ofPixels pixels;
    fbo.readToPixels(pixels);
    
    ofPixels transformedPixels;
    transformedPixels.allocate(60, numColumns, OF_IMAGE_COLOR);
    
    ofPixels outPixels1;
    outPixels1.allocate(60, 8, OF_IMAGE_COLOR);
    
    ofPixels outPixels2;
    outPixels2.allocate(60, 8, OF_IMAGE_COLOR);
    
    // Transform 12x60 to 60x12
    for(int y = 0; y < numColumns; y++) {
        for(int x = 0; x < 60; x++) {
            transformedPixels.setColor(stripHeight - x - 1, y, pixels.getColor(y, x));
        }
    }
    
    // Split into 60x8 and 60x4, and complete the last 4 rows of outPixels2 with black
    for(int y = 0; y < numColumns; y++) {
        for(int x = 0; x < 60; x++) {
            if(y < 8) {
                outPixels1.setColor(x, y, transformedPixels.getColor(x, y));
            } else {
                outPixels2.setColor(x, y - 8, transformedPixels.getColor(x, y));
            }
        }
    }
    
    // Set the last 4 rows of outPixels2 to black
    for(int y = 4; y < 8; y++) {
        for(int x = 0; x < 60; x++) {
            outPixels2.setColor(x, y, ofColor(0, 0, 0));
        }
    }
    
    
    
    outImage1.setFromPixels(outPixels1);
    outImage2.setFromPixels(outPixels2);
    
   
    udpConnection1.Send((const char*)outPixels1.getData(), outPixels1.size());
    udpConnection2.Send((const char*)outPixels2.getData(), outPixels2.size());

    
    
    
}

void UDPSender::update(){

    for(int i = 0; i < numColumns; i++){
        ofImage temp;
        temp.grabScreen(i,0, stripWidth,stripHeight);
        temp.resize(stripWidth * previewScale, stripHeight * previewScale);
        previewColums[i] = temp;

    }
    
    
}

void UDPSender::draw(){
    outImage1.draw(20,0);
    outImage2.draw(20,8);
    
    
    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2 - (numColumns * previewSpace) / 2, ofGetHeight() / 2 - stripHeight / 2);

    int groupindex = 0; // Initialize groupindex at the beginning

    for (int i = 0; i < numColumns; i++) {
        previewColums[i].draw(i * previewSpace, 0);
        ofSetColor(255);

        if (i == numColumns / 2) {
            groupindex = 0; // Reset groupindex when starting the second half
        }

        if (i < numColumns / 2) {
            ofDrawBitmapString("A" + ofToString(groupindex + 1), i * previewSpace, -10);
        } else {
            ofDrawBitmapString("B" + ofToString(groupindex + 1), i * previewSpace, -10);
        }

        groupindex++;
    }

    ofPopMatrix();
}



void UDPSender::drawPreview() {
 
    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2 - (numColumns * previewSpace) / 2, ofGetHeight() / 2 - stripHeight / 2);

    int groupindex = 0; // Initialize groupindex at the beginning

    for (int i = 0; i < numColumns; i++) {
        previewColums[i].draw(i * previewSpace, 0);
        ofSetColor(255);

        if (i == numColumns / 2) {
            groupindex = 0; // Reset groupindex when starting the second half
        }

        if (i < numColumns / 2) {
            ofDrawBitmapString("A" + ofToString(groupindex + 1), i * previewSpace, -10);
        } else {
            ofDrawBitmapString("B" + ofToString(groupindex + 1), i * previewSpace, -10);
        }

        groupindex++;
    }

    ofPopMatrix();
}
