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
        
        int numFood = 0, numAdv = 0, numStr = 0, numSim = 0, numEm = 0;
        for (int i = 0; i < 9; i++)
        {
            if (s.array[i] == FOOD)
                numFood++;
            else if (s.array[i] == ADVANTAGE)
                numAdv++;
            else if (s.array[i] == STRATEGIC)
                numStr++;
            else if (s.array[i] == SIMPLE)
                numSim++;
            else if (s.array[i] == EMPTY)
                numEm++;
        }
        
        if (numAdv > 0)
        {
            std::vector<int> vec(numAdv);
            int j = 0;
            for (int i = 0; i < 9; i++)
            {
                if (s.array[i] == ADVANTAGE)
                {
                    vec[j] = i;
                    j++;
                }
            }
            int k = rand() % (numAdv);
            return (surroundingToAction[vec[k]]);
        }
        else if (numFood > 0)
        {
            std::vector<int> vec(numFood);
            int j = 0;
            for (int i = 0; i < 9; i++)
            {
                if (s.array[i] == FOOD)
                {
                    vec[j] = i;
                    j++;
                }
            }
            int k = rand() % (numFood);
            return (surroundingToAction[vec[k]]);
        }
        else if (numSim > 0)
        {
            std::vector<int> vec(numSim);
            int j = 0;
            for (int i = 0; i < 9; i++)
            {
                if (s.array[i] == SIMPLE)
                {
                    vec[j] = i;
                    j++;
                }
            }
            int k = rand() % (numSim);
            return (surroundingToAction[vec[k]]);
        }
        else if (numEm > 0)
        {
            std::vector<int> vec(numEm);
            int j = 0;
            for (int i = 0; i < 9; i++)
            {
                if (s.array[i] == EMPTY)
                {
                    vec[j] = i;
                    j++;
                }
            }
            int k = rand() % (numEm);
            return (surroundingToAction[vec[k]]);
        }
        else
            return STAY;
    }
    
    
    
}