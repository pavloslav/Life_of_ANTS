#ifndef R_BASE_H
#define R_BASE_H

#include "base.h"

class R_base: public Base
{
public:
    R_base( );
    virtual void print() const;
    virtual void draw() const;
};

#endif // R_BASE_H
