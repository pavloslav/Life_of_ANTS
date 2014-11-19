#ifndef B_BASE_H
#define B_BASE_H

#include "base.h"

class B_base: public Base
{
public:
    B_base( );
    virtual void print() const;
    virtual void draw() const;
};

#endif // B_BASE_H
