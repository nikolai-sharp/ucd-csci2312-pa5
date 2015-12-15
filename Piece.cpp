//
//  Piece.cpp
//  ucd-csci2312-pa5
//
//  Created by Nikolai Sharp on 12/14/15.
//  Copyright © 2015 Nikolai Sharp. All rights reserved.
//

#include "Piece.h"


namespace Gaming
{
    unsigned int Piece::__idGen = 1000;
    
    Piece::Piece(const Game &g, const Position &p): __game(g), __position(p)
    {
        __finished = 0;
        __turned = 0;
        __id = __idGen++;
    }
    
    Piece::~Piece()
    {
        
    }
    
    std::ostream &operator<<(std::ostream &os, const Piece &piece)
    {
//        char type = piece.getType();
//        switch (char)
//        {
//            case '0': type = 'S'; break;
//                case '1': type = 'T'
//        }
        
        os << piece.getTypeId() << piece.__id;
        return os;
    }
    
    
    
    
}