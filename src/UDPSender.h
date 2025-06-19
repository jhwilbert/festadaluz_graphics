//#ifndef UDPSENDER_H
//#define UDPSENDER_H
#include "ofxState.h"
#include "ofxNetwork.h"
#include "SharedData.h"
#include "ofxGui.h"

class UDPSender  {

	public:
		void setup(int _numColumns, int _stripHeight, int _stripWidth);
		void update();
		void draw();

		void rotateFbo(const ofFbo& srcFbo, ofFbo& dstFbo);
        void splitFbo(const ofFbo& srcFbo);
        
        void sendFbo(ofFbo fbo);
        void previewFbo();
    
        void drawDebug(ofPixels pixels, int x, int y);
    
        void drawPreview();

        vector<ofImage> previewColums;
        ofxUDPManager udpConnection1;
        ofxUDPManager udpConnection2;
        ofxUDPManager udpConnection;
        
    bool conn1, conn2;
    
        int stripHeight, stripWidth,numColumns;
        int previewScale, previewSpace;
        
        ofFbo fbo,rotatedFbo;
        ofPixels pixels,pixels1,pixels2;
        ofImage outImage1,outImage2;
    
        vector<string> states;
    

    
    
};
//#endif // MYCLASS_H
