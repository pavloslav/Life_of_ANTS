#ifndef BASE_H
#define BASE_H

class Base
{
public:
    int size;
    int StartPosX;
    int StartPosY;
    double Score;

    Base();
    void Print();
    void draw();
    void init();
};

#endif // BASE_H
