//
//  Resource.cpp
//  ucd-csci2312-pa5
//
//  Created by Nikolai Sharp on 12/14/15.
//  Copyright © 2015 Nikolai Sharp. All rights reserved.
//

#include "Resource.h"


namespace Gaming
{
    const double Resource::RESOURCE_SPOIL_FACTOR = 1.2;
    
    Resource::Resource(const Game &g, const Position &p, double __capacity): Piece(g,p), __capacity(__capacity)
    {
        
    }
    
    Resource::~Resource()
    {
        
    }
    
    
    ActionType Resource::takeTurn(const Surroundings &s) const
    {
        return STAY;
    }
    
    Piece &Resource::operator*(Piece &other)
    {
        
        return other;
    }
    
    Piece &Resource::interact(Agent *other)
    {
        
        return *this;//change later
    }
    
    Piece &Resource::interact(Resource *)
    {
        
        return *this;//change later
    }
    
    
    
}