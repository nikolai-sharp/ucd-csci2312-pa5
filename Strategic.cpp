//
//  Strategic.cpp
//  ucd-csci2312-pa5
//
//  Created by Nikolai Sharp on 12/14/15.
//  Copyright © 2015 Nikolai Sharp. All rights reserved.
//

#include "Strategic.h"


namespace Gaming
{
    const char Strategic::STRATEGIC_ID = 'T';
    
    Strategic::Strategic(const Game &g, const Position &p, double energy, Strategy *s): Agent::Agent(g, p, energy), __strategy(s)
    {
        
    }
    
    Strategic::~Strategic()
    {
        delete __strategy;
    }
    
    void Strategic::print(std::ostream &os) const
    {
        os << STRATEGIC_ID << __id;
    }
    
    ActionType Strategic::takeTurn(const Surroundings &s) const
    {
        ActionType action;
        
        return action;
        
    }
}