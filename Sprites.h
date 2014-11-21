#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <iostream>

class Sprites
{
private:
	SDL_Texture* image;
	SDL_Rect rect;
	SDL_Rect anim;
	SDL_Renderer* render;
	int img_width;
	int img_height;
	int CurentFrame;
	int animDelay;
	int A_Frame_X;
	int A_Frame_Y;

public:
	int GetX();
	int GetY();
	bool turn;
	int StartPosX;
	int StartPosY;
	Sprites(SDL_Renderer* pass_render, std::string FilePath, int x, int y, int w, int h);
	void Draw();
	void PlayAnimation(int BeginF, int EndF, int Row, float Speed);
	void setX(int x);
	void setY(int y);
	void setPosition(int x, int y);
	void setAnimation(int passed_A_X, int passed_A_Y);

	~Sprites();
};

