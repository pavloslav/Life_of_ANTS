#pragma once
#include "Sprites.h"
#include "SDL_opengl.h"
#include "freeglut.h"

class SDL_Setup
{
public:
	SDL_Setup(bool *quit, int Screen_WIDTH, int Screen_HEIGHT);
	SDL_Renderer* GetRenderer();
	SDL_Event* GetMainEvent();
	void Begin();
	void End();
	void DrawField(int Screen_WIDTH, int Screen_HEIGHT, int scale);
	~SDL_Setup();

private:
	SDL_Window* window;
	SDL_Renderer* render;
	SDL_Event* mainEvent;
	Sprites* grass;
	SDL_GLContext glcontext;
};

