#pragma once

#include "myshape.hpp"

class Point : public Shape
{
private:
    
public:
    Point(unsigned width, unsigned height);

    ~Point() {};

    virtual void move(float speed, unsigned width, unsigned height);
};
