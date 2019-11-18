//
//  particle.hpp
//  vectorField
//
//  Created by Caroline Record on 10/2/16.
//
//

#pragma once

#include "ofMain.h"

class Particle {
public:
    
    
    void setup(glm::vec2 startPos);
    void move(glm::vec2 dir);
    void draw();
    void stayOnScreen();
    bool isOffScreen();
    bool isDead();
    
    glm::vec2 pos;
    int duration;
    
};
