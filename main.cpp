<<<<<<< HEAD
#include "CMain.h"
=======
#include <ctime>
#include <cstdlib>
#include <GL/glut.h>
>>>>>>> origin/master

int main (int argc, char *argv[])
{
	//SDL_Init(SDL_INIT_VIDEO);

	srand(time(NULL));
	CMain* cmain = new CMain(300,150);
	cmain->GameLoop();
	

	delete cmain;
	system("pause");
	return 0;
}



