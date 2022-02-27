#include "ofApp.h"

#include <iostream>
#include <random>

void ofApp::setup()
{
    ofBackground(ofColor::white);
    ofSetBackgroundAuto(true);

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<float> distAngle(-TWO_PI, TWO_PI);
    std::uniform_real_distribution<float> distMass(8, 16);
    std::uniform_real_distribution<float> distLength(120, 180);

    // random initial conditions
    lengthOne = distLength(mt);
    lengthTwo = distLength(mt);
    thetaOne = distAngle(mt);
    thetaTwo = distAngle(mt);
    massOne = distMass(mt);;
    massTwo = distMass(mt);;
}

void ofApp::update()
{
    float num1 = -g * (2 * massOne + massTwo) * sin(thetaOne);
    float num2 = -massTwo * g * sin(thetaOne - 2 * thetaTwo);
    float num3 = -2 * sin(thetaOne - thetaTwo) * massTwo;
    float num4 = aVelocityTwo * aVelocityTwo * lengthOne + aVelocityOne * aVelocityOne * lengthOne * cos(thetaOne - thetaTwo);
    float den = lengthOne * (2 * massOne + massTwo - massTwo *cos (2 * thetaOne -2 * thetaTwo));
    aAcclOne = (num1 + num2 + num3 * num4) / den;
  
    num1 = 2 * sin(thetaOne - thetaTwo);
    num2 = (aVelocityOne * aVelocityOne * lengthOne * (massOne + massTwo));
    num3 = g * (massOne + massTwo) * cos(thetaOne);
    num4 = aVelocityTwo * aVelocityTwo * lengthTwo * massTwo * cos(thetaOne - thetaTwo);
    den = lengthTwo * (2 * massOne + massTwo - massTwo * cos(2 * thetaOne -2 * thetaTwo));
    aAcclTwo = (num1 * (num2 + num3 + num4)) / den;

    aVelocityOne += (aAcclOne * dt);
    aVelocityTwo += (aAcclTwo * dt);

    aVelocityOne *= damping;
    aVelocityTwo *= damping;

    thetaOne += (aVelocityOne * dt);
    thetaTwo += (aVelocityTwo * dt);
    
    x1 = lengthOne * sin(thetaOne);
    y1 = -lengthOne * cos(thetaOne);
    x2 = x1 + (lengthTwo * sin(thetaTwo));
    y2 = y1 - (lengthTwo * cos(thetaTwo));
}

void ofApp::draw()
{
    ofTranslate(500, 150);
    ofSetColor(0, 0, 0, 255);
    ofDrawLine(-500, 0, 500, 0);

    ofSetColor(255, 0, 0, 255);
    // The y1 is inverted because the positive y direction is downward in application, and upward in formulae and calculation.
    ofDrawLine(0, 0, x1, -y1);
    ofDrawCircle(x1, -y1, massTwo);

    ofSetColor(0, 0, 255, 255);
    ofDrawLine(x1, -y1, x2, -y2);
    ofDrawCircle(x2, -y2, massOne);

    trace.addVertex(x2, -y2, 0);

    trace.draw();

    // std::cout << "(x1, y1) = (" << x1 << ", " << y1 << ") ";
    // std::cout << "(x2, y2) = (" << x2 << ", " << y2 << ")\n";
}

void ofApp::keyPressed(int key)
{

}

void ofApp::keyReleased(int key)
{

}

void ofApp::mouseMoved(int x, int y )
{

}

void ofApp::mouseDragged(int x, int y, int button)
{

}

void ofApp::mousePressed(int x, int y, int button)
{

}

void ofApp::mouseReleased(int x, int y, int button)
{

}

void ofApp::mouseEntered(int x, int y)
{

}

void ofApp::mouseExited(int x, int y)
{

}

void ofApp::windowResized(int w, int h)
{

}

void ofApp::gotMessage(ofMessage msg)
{

}

void ofApp::dragEvent(ofDragInfo dragInfo)
{ 

}
