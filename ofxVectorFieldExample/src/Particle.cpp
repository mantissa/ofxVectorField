//
//  particle.cpp
//  vectorField
//
//  Created by Caroline Record on 10/2/16.
//
//

#include "Particle.h"

void Particle::setup(ofVec2f startPos){
    pos = startPos;
    duration = 0;
}

void Particle::move(ofVec2f dir){
    pos += dir;
}

void Particle::draw(){
    ofSetColor(255, 255, 255);
    ofDrawCircle(pos.x, pos.y, 5);
    duration ++;
}

void Particle::stayOnScreen(){
    if( pos.x < 0 ) pos.x += ofGetWidth();
    if( pos.x >= ofGetWidth() ) pos.x -= ofGetWidth();
    if( pos.y < 0 ) pos.y += ofGetHeight();
    if( pos.y >= ofGetHeight() ) pos.y -= ofGetHeight();
}

bool Particle::isOffScreen(){
    if( pos.x < 0 || pos.x >= ofGetWidth() || pos.y < 0 || pos.y >= ofGetHeight() ){
        
        return true;
    }
    
    return false;
}

bool Particle::isDead(){
    return duration >= 10000;
}
