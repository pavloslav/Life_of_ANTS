#ifndef ANT_H
#define ANT_H
#include "SDL.h"
#include <time.h>
#include <stdlib.h>

class Colony;
class Base;
class Food;

class Ant
{
private:
	char Name;
	double speed;
	double live;
	double speedAtack;
public:
<<<<<<< HEAD
	Ant(int s_x, int s_y);
	int x;
	int y;
	int StartSize;
	bool turn;
	bool Invent;
	void set_speed(double);
	double get_speed();
	void set_live(double);
	double get_live();
	void set_speedatack(double);
	double get_speedatack();
	void navig(double* targ, int *ptr, int i);
	void goHome();
	void search();
	void eject();
	void eat();
	void chek();
	//virtual void goTo( Block *target );

	//virtual void deside();
	void action();


	//~Ant(void);
=======
    Ant( int x, int y, Colony* col );
    void setSpeed(double);
    double getSpeed() const;
    void setLive(double);
    double getLive() const;
    void setSpeedatack(double);
    double getSpeedatack() const;
    virtual void goHome();
    virtual void draw();
    virtual void search();
    virtual void navig(double value, Food *target );
    virtual void eject();
    virtual void eat();
    virtual void chek();
    virtual void goTo( Block *target );
    virtual void action();
    enum State {idle, goingToFood, goingHome, fighting};

private:
    double speed;
    double live;
    double speedAtack;
    int size;
    bool turn;
    bool isCarringFood;
    int startPosX;
    int startPosY;
    int startSize;
    Block::Direction direction;
    State state;
    Block *target;
>>>>>>> origin/master
};

#endif // ANT_H
