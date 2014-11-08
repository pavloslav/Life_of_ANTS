#include "game.h"

game::game()
{

    delay = 100;
    scale = 1;
    WinScale = 5;
    WinPosX = 200;
    WinPosY = 100;
}


Base::Base()
{
    size = 1;
    Score = 0;
    StartPosX = 1;
    StartPosY = 1;
}

R_base::R_base()
{
    size = 1;
    Score = 0;
    StartPosX = 1;
    StartPosY = 1;
}
B_base::B_base()
{
    size = 1;
    Score = 0;
    StartPosX = 1;
    StartPosY = 1;
}


block::block()
{

    x = 1;
    y = 1;
}

food::food()
{
x = 1;
y = 1;
}





