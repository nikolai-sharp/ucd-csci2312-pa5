//
//  Exceptions.cpp
//  ucd-csci2312-pa5
//
//  Created by Nikolai Sharp on 12/14/15.
//  Copyright © 2015 Nikolai Sharp. All rights reserved.
//

#include "Exceptions.h"


namespace Gaming
{
    std::ostream &operator<<(std::ostream &os, const GamingException &ex) //we don't actually want this to do anything.. do we
    {
        
        os << ex.__name;
//        __print_args(os);
        return os;
    }
    
    
    DimensionEx::DimensionEx(unsigned expWidth, unsigned expHeight, unsigned width, unsigned height):
            __exp_height(expHeight), __exp_width(expWidth), __height(height), __width(width)
    {
        
    }
    
    InsufficientDimensionsEx::InsufficientDimensionsEx(unsigned minWidth, unsigned minHeight, unsigned width, unsigned height):
        DimensionEx::DimensionEx(minWidth, minHeight, width, height)
    {
        __name = "InsufficientDimensionsEx";
    }
    
    void InsufficientDimensionsEx::__print_args(std::ostream &os) const
    {
        
    }
    
    OutOfBoundsEx::OutOfBoundsEx(unsigned minWidth, unsigned minHeight, unsigned width, unsigned height):
        DimensionEx::DimensionEx(minWidth, minHeight, width, height)
    {
        __name = "OutOfBoundsEx";
    }
    
    void OutOfBoundsEx::__print_args(std::ostream &os) const
    {
        
    }
    
    
}