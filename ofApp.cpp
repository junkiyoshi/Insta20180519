#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(39);
	ofSetWindowTitle("Insta");

	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}


//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(270);
	ofRotate(ofGetFrameNum() * 0.5);

	ofColor body_color;
	for (int i = 0; i < 500; i++) {

		body_color.setHsb(ofRandom(255), 239, 239);
		ofSetColor(body_color);

		ofPoint point = ofPoint(ofRandom(-ofGetWidth() / 2, ofGetWidth() / 2), ofRandom(-ofGetHeight() / 2, ofGetHeight() / 2), ofRandom(-360, 360));
		point.z = ((int)point.z + ofGetFrameNum() * (int)ofRandom(5)) % 720;
		point.z -= 360;
		point = point.normalized() * 300;

		ofDrawSphere(point, 10);
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}