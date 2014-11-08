#include "ant.h"

Ant::Ant()
{
    size = 1;
    StartSize = 1;
    StartPosX = (int)(WIDTH/6);
    StartPosY = (int)(HEIGHT/6);

}

void Ant::set_speed(double sp)
{
    Speed=sp;
}
double Ant::get_speed()
{
    return Speed;
}

void Ant::set_live(double lv)
{
    Live = lv;
}

double Ant::get_live()
{
    return Live;
}

void Ant::set_speedatack(double spa)
{
    SpeedAtack = spa;
}

double Ant::get_speedatack()
{
    return SpeedAtack;
}








