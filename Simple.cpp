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
    
    Simple::Simple(const Game &g, const Position &p, double energy): Agent::Agent(g,p,energy), __bias(false) ////
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
//        ActionType action;
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
        
        if ((numFood + numAdv) > 0)
        {
            std::vector<int> vec(numFood + numAdv);
            int j = 0;
            for (int i = 0; i < 9; i++)
            {
                if (s.array[i] == FOOD || s.array[i] == ADVANTAGE)
                {
                    vec[j] = i;
                    j++;
                }
            }
            int k = rand() % (numAdv + numFood);
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
//            rand(); rand(); rand(); rand();
            int k = rand() % numEm;
            
            return (surroundingToAction[vec[k]]);
        }
        else
            return STAY;
        
        
        
        
//        return action;
    }
    
    
}