//
//  Game.cpp
//  ucd-csci2312-pa5
//
//  Created by Nikolai Sharp on 12/14/15.
//  Copyright © 2015 Nikolai Sharp. All rights reserved.
//

#include "Game.h"
#include "Exceptions.h"
#include "Simple.h"
#include "Strategic.h"
#include "Food.h"
#include "Advantage.h"

namespace Gaming
{
    const unsigned int Game::NUM_INIT_AGENT_FACTOR = 4;
    const unsigned int Game::NUM_INIT_RESOURCE_FACTOR = 2;
    const unsigned Game::MIN_WIDTH = 3;
    const unsigned Game::MIN_HEIGHT = 3;
    const double Game::STARTING_AGENT_ENERGY = 20;//////
    const double Game::STARTING_RESOURCE_CAPACITY = 10;
    const unsigned int Game::actionToSurrounding[9] = {1, 2, 0, 5, 3, 8, 6, 7, 4};
    
    Game::Game(): __width(MIN_WIDTH), __height(MIN_HEIGHT), __grid(__width*__height, nullptr)
    {
        __round = 0;
        
    }
    
    Game::Game(unsigned width, unsigned height, bool manual): __grid(width*height, nullptr), __width(width), __height(height)
    {
        if (width < MIN_WIDTH || height < MIN_HEIGHT)
            throw InsufficientDimensionsEx(MIN_WIDTH, MIN_HEIGHT, width, height);
        __round = 0;
//        std::cout << "\nw:" << __width << "h:" << __height << *this;
        if (!manual)
        {
            populate();
        }
    }
    
    Game::Game(const Game &another): __grid(another.__grid), __height(another.__height), __width(another.__width), __round(another.__round), __status(another.__status)
    {
        __verbose = another.__verbose;
        
    }
    
    Game::~Game()
    {
        for (int i = 0; i < __grid.size(); i++)
        {
            if (__grid[i] != nullptr)
            {
                delete __grid[i];
            }
        }
    }
    
    unsigned int Game::getNumPieces() const
    {
        unsigned int count = 0;
        auto it = __grid.begin();
        while (it != __grid.end())
        {
//            std::cout << 1;
            if (*it != nullptr)
            {
                count++;
//                std::cout << 2;
            }
            it++;
        }
        return count;
    }
    
    unsigned int Game::getNumSimple() const {
        unsigned int numAgents = 0;
        
        for (auto it = __grid.begin(); it != __grid.end(); ++it) {
            Agent *agent = dynamic_cast<Simple*>(*it);
            if (agent) numAgents ++;
        }
        
        return numAgents;
    }
    
    unsigned int Game::getNumStrategic() const
    {
        unsigned int numAgents = 0;
        
        for (auto it = __grid.begin(); it != __grid.end(); ++it) {
            Agent *agent = dynamic_cast<Strategic*>(*it);
            if (agent) numAgents ++;
        }
        
        return numAgents;
    }
    
    unsigned int Game::getNumAgents() const {
        unsigned int numAgents = 0;
        
        for (auto it = __grid.begin(); it != __grid.end(); ++it) {
            Agent *agent = dynamic_cast<Agent*>(*it);
            if (agent) numAgents ++;
        }
        
        return numAgents;
    }
    
    unsigned int Game::getNumResources() const {
        unsigned int numResources = 0;
        
        for (auto it = __grid.begin(); it != __grid.end(); ++it) {
            Resource *resource = dynamic_cast<Resource*>(*it);
            if (resource) numResources ++;
        }
        
        return numResources;
    }
    
    
    std::ostream &operator<<(std::ostream &os, const Game &game)
    {
        os << "Round " << game.__round;
        
        auto it = game.__grid.begin();
        for (int i = 0; i < game.getHeight(); i++)
        {
            os << std::endl;
            for (int j = 0; j < game.getWidth(); j++)
            {
                if (*it == nullptr)
                    os << "[     ]";
                else
                {
                    os << "[" << (*it)->getTypeId() << (*it)->getId() << "]";
                }
                it++;
            }
        }
        os << std::endl << "Status:";
//        os << std::endl << "w:" << game.__width << "h:" << game.__height;
        
        return os;
    }
    
    const unsigned int Game::positionToGrid(const Position &p) const
    {
        unsigned int grid;
        grid = p.x*__width;
        grid += p.y;
        
        return grid;
    }
    
    const unsigned int Game::positionToGrid(const unsigned int x, const unsigned int y) const
    {
        unsigned int grid;
        grid = x*__width;
        grid += y;
//        std::cout << "\nx:" << x << "y:" << y << "grid:" << grid;
        return grid;
    }
    
    bool Game::addSimple(const Position &position)
    {
        int it = positionToGrid(position);
        if (position.x >= __height || position.y >= __width)
            throw OutOfBoundsEx(__height,__width, position.x, position.y);
        else if (__grid[it] == nullptr)
        {
            __grid[it] = new Simple(*this,position,STARTING_AGENT_ENERGY);
//            std::cout << *it;
            return true;
        }
        else
            return false;
    }
    
    bool Game::addSimple(unsigned x, unsigned y)
    {
        int it = positionToGrid(x,y);
        if (x >= __height || y >= __width)
            throw OutOfBoundsEx(__height,__width,x,y);
        else if (__grid[it] == nullptr)
        {
            Position p(x,y);
            __grid[it] = new Simple(*this,p,STARTING_AGENT_ENERGY);
//            std::cout << __grid[positionToGrid(x,y)];
            return true;
        }
        else
            return false;
        
    }
    
    bool Game::addStrategic(const Position &position, Strategy *s)
    {
        int it = positionToGrid(position);
        
        if (position.x >= __height || position.y >= __width)
            throw OutOfBoundsEx(__height,__width, position.x, position.y);
        else if (__grid[it] == nullptr)
        {
            __grid[it] = new Strategic(*this,position,STARTING_AGENT_ENERGY,s);
            return true;
        }
        else
            return false;
        
    }
    
    bool Game::addStrategic(unsigned x, unsigned y, Strategy *s)
    {
        int it = positionToGrid(x,y);
//        std::cout << it;
        if (x >= __height || y >= __width)
            throw OutOfBoundsEx(__height,__width,x,y);
        else if (__grid[it] == nullptr)
        {
            Position p(x,y);
            __grid[it] = new Strategic(*this,p,STARTING_AGENT_ENERGY,s);
            return true;
        }
        else
            return false;
    }
    
    bool Game::addFood(const Position &position)
    {
        int it = positionToGrid(position);
        
        if (position.x >= __height || position.y >= __width)
            throw OutOfBoundsEx(__height,__width, position.x, position.y);
        else if (__grid[it] == nullptr)
        {
            __grid[it] = new Food(*this,position,STARTING_RESOURCE_CAPACITY);
            return true;
        }
        else
            return false;
    }
    
    
    bool Game::addFood(unsigned x, unsigned y)
    {
        int it = positionToGrid(x,y);
//        std::cout << it;
        if (x >= __height || y >= __width)
            throw OutOfBoundsEx(__height,__width,x,y);
        else if (__grid[it] == nullptr)
        {
            Position p(x,y);
            __grid[it] = new Food(*this,p,STARTING_RESOURCE_CAPACITY);
            return true;
        }
        else
            return false;
    }
    
    bool Game::addAdvantage(const Position &position)
    {
        int it = positionToGrid(position);
        
        if (position.x >= __height || position.y >= __width)
            throw OutOfBoundsEx(__height,__width, position.x, position.y);
        else if (__grid[it] == nullptr)
        {
            __grid[it] = new Advantage(*this,position,STARTING_RESOURCE_CAPACITY);
            return true;
        }
        else
            return false;
    }
    
    bool Game::addAdvantage(unsigned x, unsigned y)
    {
        int it = positionToGrid(x,y);
        if (x >= __height || y >= __width)
            throw OutOfBoundsEx(__height,__width,x,y);
        else if (__grid[it] == nullptr)
        {
            Position p(x,y);
            __grid[it] = new Advantage(*this,p,STARTING_RESOURCE_CAPACITY);
            return true;
        }
        else
            return false;
    }
    
    void Game::populate()
    {
        __numInitAgents = (__width * __height) / NUM_INIT_AGENT_FACTOR;
        __numInitResources = (__width * __height) / NUM_INIT_RESOURCE_FACTOR;
        
        unsigned int numStrategic = __numInitAgents / 2;
        unsigned int numSimple = __numInitAgents - numStrategic;
        unsigned int numAdvantages = __numInitResources / 4;
        unsigned int numFoods = __numInitResources - numAdvantages;
        
        std::default_random_engine gen;
        std::uniform_int_distribution<int> d(0, __width * __height);
        
        // populate Strategic agents
        while (numStrategic > 0) {
            int i = d(gen); // random index in the grid vector
            if (__grid[i] == nullptr) { // is position empty
                Position pos(i / __width, i % __width);
                __grid[i] = new Strategic(*this, pos, Game::STARTING_AGENT_ENERGY);
                numStrategic --;
            }
        }
        
        while (numSimple > 0) {
            int i = d(gen); // random index in the grid vector
            if (__grid[i] == nullptr) { // is position empty
                Position pos(i / __width, i % __width);
                __grid[i] = new Simple(*this, pos, Game::STARTING_AGENT_ENERGY);
                numSimple --;
            }
        }
        
        while (numAdvantages > 0) {
            int i = d(gen); // random index in the grid vector
            if (__grid[i] == nullptr) { // is position empty
                Position pos(i / __width, i % __width);
                __grid[i] = new Advantage(*this, pos, Game::STARTING_RESOURCE_CAPACITY);
                numAdvantages --;
            }
        }
        
        while (numFoods > 0) {
            int i = d(gen); // random index in the grid vector
            if (__grid[i] == nullptr) { // is position empty
                Position pos(i / __width, i % __width);
                __grid[i] = new Food(*this, pos, Game::STARTING_RESOURCE_CAPACITY);
                numFoods --;
            }
        }
    }
    
    const Surroundings Game::getSurroundings(const Position &pos) const
    {
        Surroundings s;
        int i = 0, x = pos.x, y = pos.y;
        for (int x1 = -1; x1 <= 1; x1++)
        {
            for (int y1 = -1; y1 <= 1; y1++)
            {
                if (x + x1 >= __height || x + x1 < 0 || y + y1 >= __width || y + y1 < 0)
                    s.array[i] = PieceType::INACCESSIBLE;
                else if (x1 == 0 && y1 == 0)
                    s.array[i] = PieceType::SELF;
                else if (__grid[positionToGrid(x + x1, y+y1)] != nullptr)
                    s.array[i] = (*__grid[positionToGrid(x + x1, y+y1)]).getType();
                else
                    s.array[i] = PieceType::EMPTY;
                    
                i++;
            }
        }
        
        return s;
    }
    
    bool Game::isLegal(const ActionType &ac, const Position &pos) const
    {
        Surroundings s = getSurroundings(pos);
        int i = actionToSurrounding[ac];
        
        if (s.array[i] == PieceType::INACCESSIBLE)
            return false;
        else
            return true;
        
    }
    
//    const Position Game::gridToPosition(const std::vector<Piece *>::iterator it) const
//    {
//        
//    }
    
    const Position Game::gridToPosition(const unsigned int grid) const
    {
        Position s;
        
        s.x = grid / __width;
//        std::cout << s.x;
        s.y = grid % __width;
        
        return s;
    }
    
    const Position Game::actionToPosition(ActionType ac, Position s) const
    {//{ N=0, NE, NW, E, W, SE, SW, S, STAY };
        switch (ac) {
            case NW: s.x--; s.y--; break;
            case N: s.x--; break;
            case NE: s.x--; s.y++; break;
            case W: s.y--; break;
            case E: s.y++; break;
            case SW: s.x++; s.y--; break;
            case S: s.x++; break;
            case SE: s.x++; s.y++; break;
            case STAY:break;
        }
        return s;
    }
    
    const Position Game::move(const Position &pos, const ActionType &ac) const
    {
//        Surroundings s = getSurroundings(pos);
        Position pos1 = actionToPosition(ac,pos);
        int from = positionToGrid(pos); int to = positionToGrid(pos1);
        auto itf = __grid[from]; auto itt = __grid[to];
        if (isLegal(ac, pos))
        {
            __grid[from]->setPosition(pos1);
            if (__grid[to] == nullptr)
                itt = itf;
            itf = nullptr;
            
            return pos1;
        }
        else
            return pos;
    }
    
    const ActionType Game::reachSurroundings(const Position &from, const Position &to)
    {
        ActionType ac;
        int xdiff = from.x - to.x, ydiff = from.y - to.y;
        if (abs(xdiff) > 1 || abs(ydiff) > 1)
        {
            ac = STAY; //throw exception??
        }
        else
        {
            if (xdiff == 1 && ydiff == 1)
                ac = NW;
            else if (xdiff == 1 && ydiff == 0)
                ac = N;
            else if (xdiff == 1 && ydiff == -1)
                ac = NE;
            else if (xdiff == 0 && ydiff == 1)
                ac = W;
            else if (xdiff == 0 && ydiff == 0)
                ac = STAY;
            else if (xdiff == 0 && ydiff == -1)
                ac = E;
            else if (xdiff == -1 && ydiff == 1)
                ac = SW;
            else if (xdiff == -1 && ydiff == 0)
                ac = S;
            else if (xdiff == -1 && ydiff == -1)
                ac = SE;
            else //should never get here...
                ac = STAY;
        }
        
        
        return ac;
    }
    
    void Game::play(bool verbose)
    {
        //first, add pieces to set
        for (int i = 8; i >= 0; i--)
        {
            if (__grid[i] != nullptr)
            {
                __pieces.push_front(__grid[i]);
            }
        }
        
        int i = 10;
        while (getNumResources() > 0)
//        while (i >= 0)
        {
            round();
            __round++;
            
            if (getNumResources() == 0)
            {
                std::cout << std::endl << *this;
                std::cout << "Over!\n";
            }
            else if (verbose)
            {
                std::cout << std::endl << *this;
                std::cout << "Playing...";
            }
            i--;
        }
    }
    
    void Game::round()
    {
//        std::cout << *this;
        for (auto it = __pieces.begin(); it != __pieces.end(); it++)
        {
//            std::cout << *this;
//            std::cout << "\nviable:" << (*it)->isViable();
            if (!(*it)->getTurned() && (*it)->isViable())
            {
//                std::cout << *(*it);
                Position p = (*it)->getPosition();
                int oldG = positionToGrid(p);
                Surroundings s = getSurroundings((*it)->getPosition());
                ActionType ac = (*it)->takeTurn(s);
                if (isLegal(ac, p) && ac != STAY)
                {
                    Position np = actionToPosition(ac, p);
                    int newG = positionToGrid(np);
                    (*it)->setPosition(np);
                    
                    if ( __grid[newG] != nullptr)
                    {
                        Piece *pi = &((*(*it)) * (*(__grid[newG])));//this is the strangest thing I've ever created.
                        char id = (__grid[newG])->getTypeId();
                        if (id == 'F' || id == 'D')
                            (__grid[newG])->finnish();
                        __grid[newG] = pi;
                    }
                    else
                    {
                        __grid[newG] = __grid[oldG];
                    }
                    __grid[oldG] = nullptr;
                    
                }
            }
            (*it)->age();
            (*it)->setTurned(true);
            
        }
        
        for (int i = 0; i < __grid.size(); i++)
        {
            
            if (__grid[i] != nullptr && !(__grid[i])->isViable())
            {
                __grid[i] = nullptr;
            }
            else if (__grid[i] != nullptr && (__grid[i]->isViable()))
            {
                (__grid[i])->setTurned(false);
            }
        }
        
        auto it1 = __pieces.before_begin();
        auto it2 = __pieces.begin();
        while (it2 != __pieces.end())
        {
            if (!(*it2)->isViable())
            {
                it2 = __pieces.erase_after(it1);
            }
            else
            {
                it2++;
                it1++;
            }
        }
//        std::cout << "\t\tvecSize:" << __pieces.size();
        
//        std::cout << *this;
        
    }
    
    
}






