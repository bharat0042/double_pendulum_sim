#ifndef __OFAPP_H__
#define __OFAPP_H__

#include "ofMain.h"

class ofApp : public ofBaseApp
{
public:
    float g = 1.0f;
    float damping = 0.9999f;
    float dt = 1.0f;

    float thetaOne = 0;
    float thetaTwo = 0;
    
    float aVelocityOne = 0;
    float aVelocityTwo = 0;

    float aAcclOne = 0;
    float aAcclTwo = 0;

    float lengthOne = 0;
    float lengthTwo = 0;

    float massOne = 0;
    float massTwo = 0;

    float x1 = 0, y1 = 0, x2 = 0, y2 = 0;

    ofPolyline trace;
    
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);    
};

#endif