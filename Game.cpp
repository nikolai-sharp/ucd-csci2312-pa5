//
//  Game.cpp
//  ucd-csci2312-pa5
//
//  Created by Nikolai Sharp on 12/14/15.
//  Copyright © 2015 Nikolai Sharp. All rights reserved.
//

#include "Game.h"
#include "Exceptions.h"

namespace Gaming
{
    const unsigned int Game::NUM_INIT_AGENT_FACTOR = 4;
    const unsigned int Game::NUM_INIT_RESOURCE_FACTOR = 2;
    const unsigned Game::MIN_WIDTH = 3;
    const unsigned Game::MIN_HEIGHT = 3;
    const double Game::STARTING_AGENT_ENERGY = 20;
    const double Game::STARTING_RESOURCE_CAPACITY = 10;
    
    Game::Game(): __width(MIN_WIDTH), __height(MIN_HEIGHT), __grid(__width*__height, nullptr)
    {
        __round = 0;
    }
    
    Game::Game(unsigned width, unsigned height, bool manual): __grid(width*height, nullptr), __width(width), __height(height)
    {
        if (width < MIN_WIDTH || height < MIN_HEIGHT)
            throw InsufficientDimensionsEx(MIN_WIDTH, MIN_HEIGHT, width, height);
        __round = 0;
    }
    
    Game::Game(const Game &another): __grid(another.__grid), __height(another.__height), __width(another.__width), __round(another.__round), __status(another.__status)
    {
        __verbose = another.__verbose;
        
    }
    
    Game::~Game()
    {
//        for (auto it = __grid.begin(); it != __grid.end(); it++)
//        {
//            if (*it != nullptr)
//                
//        }
    }
    
    unsigned int Game::getNumPieces() const
    {
        unsigned int count = 0;
        auto it = __grid.begin();
        while (it != __grid.end())
        {
            if (*it != nullptr)
                count++;
            it++;
        }
        return count;
    }
    
    std::ostream &operator<<(std::ostream &os, const Game &game)
    {
        os << "Round " << game.__round;
        
//        auto it = game.__grid.begin();
        for (int i = 0; i < game.getHeight(); i++)
        {
            os << std::endl;
            for (int j = 0; j < game.getWidth(); j++)
            {
                os << "[     ]";
                
//                it++;
            }
        }
        os << std::endl << "Status:";
        
        return os;
    }
    
    
    
    
}