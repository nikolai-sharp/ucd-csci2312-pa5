//
//  Advantage.cpp
//  ucd-csci2312-pa5
//
//  Created by Nikolai Sharp on 12/14/15.
//  Copyright © 2015 Nikolai Sharp. All rights reserved.
//

#include "Advantage.h"


namespace Gaming
{
    const char Advantage::ADVANTAGE_ID = 'D';
    const double Advantage::ADVANTAGE_MULT_FACTOR = 2.0;
    
    Advantage::Advantage(const Game &g, const Position &p, double capacity): Resource::Resource(g,p,capacity)
    {
        
    }
    
    Advantage::~Advantage()
    {
        
    }
    
    void Advantage::print(std::ostream &os) const
    {
        
    }
    
    double Advantage::consume()
    {
        
        return 0;//fill in
    }
    
    
}