
#pragma once

#include "ofMain.h"

class ofxSimpleParticle : public ofVec2f {
	
public:
	
	ofxSimpleParticle(){
		
		duration = 0;
	}
	
	void setup(ofVec2f pos){
	
		this->set( pos );
	}

	void move(ofVec2f dir){
	
		*this += dir;
	}
	
	void draw(){
	
		ofSetColor(255, 255, 255);
		ofCircle(x, y, 5);
	}
	
	void stayOnscreen(){
		
		if( x < 0 ) x += ofGetWidth(); 
		if( x >= ofGetWidth() ) x -= ofGetWidth();
		if( y < 0 ) y += ofGetHeight();
		if( y >= ofGetHeight() ) y -= ofGetHeight();
	}
	
	bool isOffscreen(){
	
		if( x < 0 || x >= ofGetWidth() || y < 0 || y >= ofGetHeight() ){
		
			return true;
		}
		
		return false;
	}
	
	bool isDead(){
	
		return duration >= 10000;
	}
	
	int duration;
};