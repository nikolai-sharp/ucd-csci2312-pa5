//
//  Food.cpp
//  ucd-csci2312-pa5
//
//  Created by Nikolai Sharp on 12/14/15.
//  Copyright © 2015 Nikolai Sharp. All rights reserved.
//

#include "Food.h"


namespace Gaming
{
    const char Food::FOOD_ID = 'F';
    
    Food::Food(const Game &g, const Position &p, double capacity): Resource::Resource(g,p,capacity)
    {
        
    }
    
    Food::~Food()
    {
        
    }
    
    void Food::print(std::ostream &os) const
    {
        os << FOOD_ID << __id;
        
    }
    
    
}