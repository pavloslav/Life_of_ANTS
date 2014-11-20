#include "b_ant.h"
#include <GL/glut.h>
#include "scene.h"

B_ant::B_ant( int x, int y, Base *base ) : Ant( x, y, base )
{
}


void B_ant::drawSnake()
{
    glColor3f(0.0, 0.0, 0.0);
    glRectf(getX() * 1, getY() * 1, (getX() + 0.9) * 1, (getY() + 0.9) * 1);
}

void B_ant::move(){
    for(int j = 1; j > 0; j--){
        mainScene->bant[j]->setX( mainScene->bant[j-1]->getX() );
        mainScene->bant[j]->setY( mainScene->bant[j-1]->getY() );
    }
    step(direction);
}

<<<<<<< HEAD
=======
            }


    }
}


void B_ant::eject(int i)
{

    if((mainScene->bant[i]->invent)&&((mainScene->bant[i]->getX() == mainScene->base[1].getX())&&(mainScene->bant[i]->getY() == mainScene->base[1].getY())))
    {
       mainScene->bant[i]->invent=false;
        mainScene->b_base.score++;

}

void B_ant::eat(int j){
	for (int i = 0; i<20; ++i)
	{
		if ((mainScene->b_ant[j].x == mainScene->m[i]->x) && (mainScene->b_ant[j].y == mainScene->m[i]->y)){
			mainScene->bant[j]->invent = true;

			mainScene->m[i]->spawn();
		}
	}
}

}
void B_ant::move(int i){
        for(int j = 1; j > 0; j--){
                mainScene->bant[j]->setX( mainScene->bant[j-1]->getX() );
                mainScene->bant[j]->setY( mainScene->bant[j-1]->getY() );
        }
            switch (direction){
            case GLUT_KEY_UP :
                    mainScene->bant[i]->getY()++;
                    break;
            case GLUT_KEY_DOWN :
                    mainScene->bant[i]->getY()--;
                    break;
            case GLUT_KEY_LEFT :
                mainScene->bant[i]->getX()--;
                    break;
            case GLUT_KEY_RIGHT :
                   mainScene->bant[i]->getX()++;
                    break;
            case GLUT_KEY_END :
                    break;

        }

        if(mainScene->bant[i]->getX() < 0)mainScene->bant[i]->getX() += WIDTH;
        if(mainScene->bant[i]->getX() >= WIDTH)mainScene->bant[i]->getX() -= WIDTH;
        if(mainScene->bant[i]->getY() < 0)mainScene->bant[i]->getY() += HEIGHT;
        if(mainScene->bant[i]->getY() >= HEIGHT)mainScene->bant[i]->getY() -= HEIGHT;
}
void B_ant::search(int j)
{
        double size = 20;
        double targ[20];

        int n=0;
        for (int i=0;i<size;++i){     //перераховує масив food[i]
            targ[i] = mainScene->bant[j]->distance(*mainScene->food[i]);
            if(targ[i]<=targ[n]){
                n=i;
            }
        }
        navig(targ,&n,j );
}
>>>>>>> origin/master
