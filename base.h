#ifndef BASE_H
#define BASE_H

class Scene;

class Base
{
public:
    static Scene *mainScene;
    int size;
    int StartPosX;
    int StartPosY;
    double Score;


    Base( );
    void Print();
    void draw();
    void init();
};

#endif // BASE_H
