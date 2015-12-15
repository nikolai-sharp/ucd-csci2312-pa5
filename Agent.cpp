//
//  Agent.cpp
//  ucd-csci2312-pa5
//
//  Created by Nikolai Sharp on 12/14/15.
//  Copyright © 2015 Nikolai Sharp. All rights reserved.
//

#include "Agent.h"

namespace Gaming
{
    const double Agent::AGENT_FATIGUE_RATE = 0.3;
    
    Agent::Agent(const Game &g, const Position &p, double energy): Piece::Piece(g,p), __energy(energy)
    {
        
    }
    
    Agent::~Agent()
    {
        
    }
    
    Piece &Agent::operator*(Piece &other)
    {
        
        return other;
    }
    
    Piece &Agent::interact(Agent *other)
    {
        
        return *this;//change later
    }
    
    Piece &Agent::interact(Resource *)
    {
        
        return *this;//change later
    }
}