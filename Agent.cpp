//
//  Agent.cpp
//  ucd-csci2312-pa5
//
//  Created by Nikolai Sharp on 12/14/15.
//  Copyright © 2015 Nikolai Sharp. All rights reserved.
//

#include "Agent.h"
#include "Resource.h"

namespace Gaming
{
    const double Agent::AGENT_FATIGUE_RATE = 0.3;
    const ActionType Agent::surroundingToAction[9] = {NW, N, NE, W, STAY, E, SW, S, SE};
    
    Agent::Agent(const Game &g, const Position &p, double energy): Piece::Piece(g,p), __energy(energy)
    {
        
    }
    
    Agent::~Agent()
    {
        
    }
    
    Piece &Agent::operator*(Piece &other)
    {
        Piece *ot = &other;
        PieceType p = other.getType();
        if (p == ADVANTAGE || p == FOOD)
        {
            Resource *res = dynamic_cast<Resource*>(ot);
            
            return interact(res);
        }
        else if (p == SIMPLE || p == STRATEGIC)
        {
            Agent *ag = dynamic_cast<Agent*>(ot);
            
            return interact(ag);
        }
        return *this;//shouldn't get here..
    }
    
    Piece &Agent::interact(Agent *other)
    {
        
        if (other->isViable() && isViable())
        {
            if (other->__energy == __energy)
            {
                finish();
                other->finish();
                return *this; //gotta return something..
            }
            else if (other->__energy > __energy)
            {
                other->__energy -= __energy;
                finish();
                return *other;
            }
            else if (other->__energy < __energy)
            {
                __energy -= other->__energy;
                other->finish();
                return *this;
            }
            
            
        }
        else if (other->isViable() && !isViable())
        {
            return *other;
        }
        else //if (!other->isViable() && isViable()) //commented out because this should be the last case anyway
        {
            return *this;
        }
        return *this;

    }
    
    Piece &Agent::interact(Resource *other)
    {
        __energy += other->getCapacity();
        other->consume();
        return *this;
    }
}





