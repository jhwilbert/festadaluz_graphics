#include "ofMain.h"
#include "ofApp.h"
#include "ofAppNoWindow.h"

int main() {
#ifdef TARGET_OSX
    ofSetupOpenGL(1024, 768, OF_WINDOW);
#else
    ofAppNoWindow window;
    ofSetupOpenGL(&window, 0, 0, OF_WINDOW);
#endif
    ofRunApp(new ofApp());
}
