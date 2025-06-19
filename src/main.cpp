#include "ofMain.h"
#include "ofApp.h"
#include "ofAppNoWindow.h"  

int main() {
#ifdef TARGET_OSX
    // macOS: Create a normal visible window
    ofSetupOpenGL(1024, 768, OF_WINDOW);
#else
    // Other platforms (e.g. Raspberry Pi): Run headless
    ofAppNoWindow window;
    ofSetupOpenGL(&window, 0, 0, OF_WINDOW);
#endif

    ofRunApp(new ofApp());
}
