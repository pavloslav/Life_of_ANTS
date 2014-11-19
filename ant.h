#ifndef ANT_H
#define ANT_H

class Scene;


#define WIDTH 300
#define HEIGHT 150
#define BARR 50

class Ant
{
private:
    double Speed;
    double Live;
    double SpeedAtack;


public:
    static Scene *mainScene;
    int size;
    bool turn;
    bool Invent;
    int StartPosX;
    int StartPosY;
    int StartSize;
    Ant( );
    void set_speed(double);
    double get_speed();
    void set_live(double);
    double get_live();
    void set_speedatack(double);
    double get_speedatack();
    int direction;
    void go_home(int i);
    void init();
    void DrawAnt(int i);
    void search(int j);
    void navig(double* targ, int *ptr , int i);
    void move();
    void go();
    void eject(int i);
    virtual void eat(int i);
    void chek(int i);

};
#endif // ANT_H
