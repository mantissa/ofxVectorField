#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofEnableAlphaBlending();
	
	puppy.loadImage("puppy.jpg");
	
	ofSetWindowShape(puppy.width, puppy.height);
	
	ofSetFrameRate(30);
	
	// allocate the vector field with the desired spacing
	vectorField.setup(puppy.width, puppy.height, 10);
	
	// create the vector field using perlin noise
	//vectorField.randomize();
	
	// create the vector field from an image
	vectorField.setFromImage(puppy);
	
	// adjust the vector field by normalizing, scaling, biasing & blurring (to make it look nice)
	vectorField.normalize();
	vectorField.scale(5);
	vectorField.bias(0, 0.5);
	vectorField.blur();
}

//--------------------------------------------------------------
void testApp::update(){

	if( ofGetFrameNum() % 10 == 0 && particles.size() < 300 ){
	
		ofxSimpleParticle newParticle;
		ofVec2f pos( ofGetWidth()/2 + ofRandom( -200, 200), ofGetHeight()/2 + ofRandom( -200, 200));
		newParticle.setup(pos);
		particles.push_back(newParticle);
	}
	
	for( int i=0; i<particles.size(); i++){
	
		particles[i].move(vectorField.getVectorInterpolated(particles[i].x, particles[i].y, ofGetWidth(), ofGetHeight()));
		particles[i].stayOnscreen();
	}
}

//--------------------------------------------------------------
void testApp::draw(){

	ofBackground(0, 0, 0);
	
	ofSetColor(255, 255, 255);
	puppy.draw(0, 0);
	
	vectorField.draw();
	
	for( int i=0; i<particles.size(); i++){
		particles[i].draw();
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}