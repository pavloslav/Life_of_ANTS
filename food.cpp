#include "food.h"

Food::Food()
{
	x = 1;
	y = 1;
}


void Food::spawn(int WIDTH, int HEIGHT)
{
<<<<<<< HEAD
=======
    glColor3f(0.0,0.0,1.0);
    glRectf(getX()*mainScene->scale,getY()*mainScene->scale,(getX()+1)*mainScene->scale,(getY()+1)*mainScene->scale);
}
>>>>>>> origin/master

	x = (rand() % WIDTH);
	y = (rand() % HEIGHT);
}

