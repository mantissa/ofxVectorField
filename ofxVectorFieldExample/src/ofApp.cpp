#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableAlphaBlending();
    
    puppy.load("puppy3.jpg");
    
    ofSetWindowShape(puppy.getWidth(), puppy.getHeight());
    
    ofSetFrameRate(30);
    
    // allocate the vector field with the desired spacing
    vectorField.setup(puppy.getWidth(), puppy.getHeight(), 10);
    
    // create the vector field using perlin noise
    //vectorField.randomize();
    
    // create the vector field from an image
    vectorField.setFromImage(puppy);
    
    // adjust the vector field by normalizing, scaling, biasing & blurring (to make it look nice)
    vectorField.normalize();
    vectorField.scale(7);
    vectorField.bias(1, 0);
    vectorField.blur();
}

//--------------------------------------------------------------
void ofApp::update(){
    if( ofGetFrameNum() % 10 == 0 && particles.size() < 300 ){
        
        Particle newParticle;
        ofVec2f pos( ofGetWidth()/2 + ofRandom( -200, 200), ofGetHeight()/2 + ofRandom( -200, 200));
        newParticle.setup(pos);
        particles.push_back(newParticle);
    }
    
    for( int i=0; i<particles.size(); i++){
        
        particles[i].move(vectorField.getVectorInterpolated(particles[i].pos.x, particles[i].pos.y, ofGetWidth(), ofGetHeight()));
        particles[i].stayOnScreen();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 0, 0);
    
    ofSetColor(255, 255, 255);
    puppy.draw(0, 0);
    
    vectorField.draw();
    
    for( int i=0; i<particles.size(); i++){
        particles[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
