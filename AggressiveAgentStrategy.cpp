//
//  AggressiveAgentStrategy.cpp
//  ucd-csci2312-pa5
//
//  Created by Nikolai Sharp on 12/14/15.
//  Copyright © 2015 Nikolai Sharp. All rights reserved.
//

#include "AggressiveAgentStrategy.h"
#include "Game.h"

namespace Gaming
{
    const double AggressiveAgentStrategy::DEFAULT_AGGRESSION_THRESHOLD = Game::STARTING_AGENT_ENERGY * 0.75;
    const ActionType AggressiveAgentStrategy::surroundingToAction[9] = {NW, N, NE, W, STAY, E, SW, S, SE};
    
    
    AggressiveAgentStrategy::AggressiveAgentStrategy(double agentEnergy): __agentEnergy(agentEnergy)
    {
        
    }
    
    AggressiveAgentStrategy::~AggressiveAgentStrategy()
    {
        
    }
    
    ActionType AggressiveAgentStrategy::operator()(const Surroundings &s) const
    {
        if (__agentEnergy >= DEFAULT_AGGRESSION_THRESHOLD)
        {
            for (int i = 0; i < 9; i++)
            {
                if (s.array[i] == SIMPLE || s.array[i] == STRATEGIC)
                    return surroundingToAction[i];
            }
        }
        
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
            if (s.array[i] == EMPTY)
                return surroundingToAction[i];
        }
        return STAY;
        
    }
    
    
    
}