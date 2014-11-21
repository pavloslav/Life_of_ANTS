#include "SDL_Setup.h"


SDL_Setup::SDL_Setup(bool *quit, int Screen_WIDTH, int Screen_HEIGHT)
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO);
	window = NULL;
	window = SDL_CreateWindow("Strategy", 100, 100, Screen_WIDTH, Screen_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	glcontext = SDL_GL_CreateContext(window);
	if (window == NULL)
	{
		std::cout << "Win Error" << std::endl;
		*quit = true;

	}

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glClearColor(0.f, 0.f, 0.f, 1.f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, Screen_WIDTH,0, Screen_HEIGHT);

	render = NULL;
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	mainEvent = new SDL_Event();
	glFlush();
	glutPostOverlayRedisplay();

}


SDL_Setup::~SDL_Setup()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(render);
	delete mainEvent;

}

SDL_Renderer* SDL_Setup::GetRenderer()
{
	return render;
}
SDL_Event* SDL_Setup::GetMainEvent()
{
	return  mainEvent;
}

void SDL_Setup::Begin()
{
	SDL_PollEvent(GetMainEvent());
	SDL_RenderClear(GetRenderer());

}
void SDL_Setup::End()
{
	SDL_RenderPresent(GetRenderer());

}