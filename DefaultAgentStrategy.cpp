//
//  DefaultAgentStrategy.cpp
//  ucd-csci2312-pa5
//
//  Created by Nikolai Sharp on 12/14/15.
//  Copyright © 2015 Nikolai Sharp. All rights reserved.
//

#include "DefaultAgentStrategy.h"


namespace Gaming
{
    const ActionType DefaultAgentStrategy::surroundingToAction[9] = {NW, N, NE, W, STAY, E, SW, S, SE};
    
    DefaultAgentStrategy::DefaultAgentStrategy()
    {
        
    }
    
    DefaultAgentStrategy::~DefaultAgentStrategy()
    {
        
    }
    
    ActionType DefaultAgentStrategy::operator()(const Surroundings &s) const
    {
        
        for (int i = 0; i < 9; i++)
        {
            if (s.array[i] == ADVANTAGE)
                return surroundingToAction[i];
        }
        
        for (int i = 0; i < 9; i++)
        {
            if (s.array[i] == FOOD)
                return surroundingToAction[i];
        }
        
        for (int i = 0; i < 9; i++)
        {
            if (s.array[i] == SIMPLE)
                return surroundingToAction[i];
        }
        
        for (int i = 0; i < 9; i++)
        {
            if (s.array[i] == EMPTY)
                return surroundingToAction[i];
        }
        return STAY;
    }
    
    
    
}