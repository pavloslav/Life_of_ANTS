#ifndef COLONY_H
#define COLONY_H

#include <vector>
class Base;
class Ant;

class Colony
{
public:
    Colony( float r, float g, float b, int scoreX, int scoreY );
    Base* nearestBase( Ant *who );
    double score;
    float red, green, blue;//color of the colony
    int scorePosX, scorePosY;
    std::vector< Base * > bases;
    std::vector< Ant * > ants;
    virtual void draw();
};

#endif // COLONY_H
