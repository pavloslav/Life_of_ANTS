#include "Sprites.h"


Sprites::Sprites(SDL_Renderer* pass_render, std::string FilePath, int x, int y, int w, int h)
{
	render = pass_render;
	image = NULL;
	image = IMG_LoadTexture(render, FilePath.c_str());
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	SDL_QueryTexture(image, NULL, NULL, &img_width, &img_height);
		
	anim.x = 0;
	anim.y = 0;
	anim.w = img_width;
	anim.h = img_height;

	CurentFrame = 0;

	A_Frame_X = 0;
	A_Frame_Y = 0;

	if (image == NULL)
	{
		std::cout << "Couldn't load" << FilePath.c_str()<< std::endl;
	}

}

void Sprites::setAnimation(int passed_A_X, int passed_A_Y)
{
	A_Frame_X = passed_A_X;
	A_Frame_Y = passed_A_Y;
	 
}
 
void Sprites::Draw()
{
	SDL_RenderCopy(render, image, &anim, &rect);
}


void Sprites::PlayAnimation(int BeginF, int EndF, int Row, float Speed)
{
	if (animDelay + Speed < SDL_GetTicks())
	{

		if (EndF <= CurentFrame)

			CurentFrame = BeginF;
		else
			CurentFrame++;

		anim.x = CurentFrame * (img_width / A_Frame_X);
		anim.y = Row * (img_height / A_Frame_Y);
		anim.w = img_width / A_Frame_X;
		anim.h = img_height / A_Frame_Y;

		animDelay = SDL_GetTicks();
	}
}

Sprites::~Sprites()
{
	SDL_DestroyTexture(image);

}
void Sprites::setX(int x)
{
	rect.x = x;
	
}
void Sprites::setY(int y)
{
	rect.y = y;
}

void Sprites::setPosition(int x, int y)
{
	rect.x = x;
	rect.y = y;
}
int Sprites::GetX()
{
	return rect.x;
}
int Sprites::GetY()
{
	return rect.y;
}