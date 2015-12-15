//
//  Simple.cpp
//  ucd-csci2312-pa5
//
//  Created by Nikolai Sharp on 12/14/15.
//  Copyright © 2015 Nikolai Sharp. All rights reserved.
//

#include "Simple.h"


namespace Gaming
{
    const char Simple::SIMPLE_ID = 'S';
    
    Simple::Simple(const Game &g, const Position &p, double energy): Agent::Agent(g,p,energy)
    {
        
    }
    
    Simple::~Simple()
    {
        
    }
    
    void Simple::print(std::ostream &os) const
    {
        os << SIMPLE_ID << __id;
    }
    
    ActionType Simple::takeTurn(const Surroundings &s) const
    {
        ActionType action;
        
        return action;
    }
    
    
}