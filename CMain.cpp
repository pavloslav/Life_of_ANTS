#include "CMain.h"


CMain::CMain(int S_WIDTH, int S_HEIGHT)
{
	WIDTH = S_WIDTH;
	HEIGHT = S_HEIGHT;
	scale = 1;
	WinScale = 5;
	bool quit = false;
	tic = 0;
	sdl_setup = new SDL_Setup(&quit, WIDTH*WinScale, HEIGHT*WinScale);
	grass = new Sprites(sdl_setup->GetRenderer(), "DATA/Fon.JPG", 0, 0, WIDTH*WinScale, HEIGHT*WinScale);
	
	Base_Sprite = new Sprites(sdl_setup->GetRenderer(), "DATA/Ork_Castle.png", 200, 500, 180, 180);
	Base_Sprite->setAnimation(5, 5);

	
	colony = new Base(200,500);


	for (int i = 0; i < 30; ++i){
		Ant_Body[i] = new Ant(200 + (i * 10), 500 + (i * 10));
		Ork_Sprite[i] = new Sprites(sdl_setup->GetRenderer(), "DATA/MY_Ork.png", 200 + (i * 10), 500 + (i * 10), 60, 60);
		Ork_Sprite[i]->setAnimation(5, 5);

	}
	for (int i = 0; i < 30; ++i){
		food[i] = new Food;
		food[i]->spawn(WIDTH*WinScale, HEIGHT*WinScale);
		food_Sprite[i] = new Sprites(sdl_setup->GetRenderer(), "DATA/test.png", food[i]->x, food[i]->y, 10, 10);

	}	

	MoveRight = false;
	MoveLeft = false;
	MuveUp = false;
	MoveDown = false;

	timeChekc = SDL_GetTicks();
	
}



CMain::~CMain()
{
	delete sdl_setup;
	delete grass;
	delete Ork_Sprite[30];
	delete Ant_Body[30];

}


void CMain::GameLoop()
{
	tic++;
	if (tic < 2){
		for (int i = 0; i < 30; ++i){
			food[i]->spawn(WIDTH, HEIGHT);
			food_Sprite[i]->setPosition(food[i]->x, food[i]->y);
		}
	}
	while (!quit && sdl_setup->GetMainEvent()->type != SDL_QUIT)
	{
		

		sdl_setup->Begin();
		grass->Draw();
		
		for (int i = 0; i < 30; ++i){
			food_Sprite[i]->Draw();
			Ork_Sprite[i]->Draw();
		}


		Base_Sprite->Draw();


		for (int* i = new int(0); *i < 30; ++*i)
		{
			Chek(i);
		}

		switch (sdl_setup->GetMainEvent()->type)
		{
		case SDL_KEYDOWN:
			switch (sdl_setup->GetMainEvent()->key.keysym.sym)
			{
			case SDLK_a:
				MoveLeft = true;
				break;
			case SDLK_w:
				MuveUp = true;
				break;
			case SDLK_d:
				MoveRight = true;
				break;
			case SDLK_s:
				MoveDown = true;
				break;
			}

			break;

		case SDL_KEYUP:
			switch (sdl_setup->GetMainEvent()->key.keysym.sym)
			{
			case SDLK_a:
				MoveLeft = false;
				break;
			case SDLK_w:
				MuveUp = false;
				break;
			case SDLK_d:
				MoveRight = false;
				break;
			case SDLK_s:
				MoveDown = false;
				break;
			}
			break;
		default:
			break;

		}
		system("cls");
		cout <<colony->Score<< endl;
		for (int i = 0; i < 30; ++i){
			cout <<"Ork "<<i+1<<' '<< Ant_Body[i]->x << ' ';
			cout << Ant_Body[i]->y << ' ';
			cout << Ork_Sprite[i]->GetX() << ' ';
			cout << Ork_Sprite[i]->GetY() << endl;
		}
		sdl_setup->End();

	}

}
void CMain::Chek(int* i)
{
	int j = *i;
	if (Ant_Body[j]->Invent == true){

			Go_ToBase(j);
		}
	if (Ant_Body[j]->Invent == false)
		{
			Search(j);
		}
		Cath(j);
		Eject(j);
}



void CMain::Search(int j)
{
	double size = 30;
	double targ[30];
	double bufer = 0;

	double delta = 0;
	int deltaX;
	int deltaY;

	int n = 0;
	for (int i = 0; i < size; ++i)
	{
		deltaX = Ant_Body[j]->x - food[i]->x;
		deltaY = Ant_Body[j]->y - food[i]->y;
		delta = ((deltaX*deltaX) + (deltaY*deltaY));
		targ[i] = sqrt(delta);
		if (targ[i] <= targ[n])
		{
			n = i;
		}
	}
	Move(n, j);
}

void CMain::Move(int n,int j)
{
	Base_Sprite->PlayAnimation(0, 0, 0, 200);
	Ant_Body[j]->turn = true;
	if (timeChekc + 60 < SDL_GetTicks())
	{
		if (Ant_Body[j]->x < food[n]->x && Ant_Body[j]->turn)
		{
			Ork_Sprite[j]->PlayAnimation(0, 4, 0, 200);
			Ork_Sprite[j]->setX(Ork_Sprite[j]->GetX() + 1);
			Ant_Body[j]->x++;
			Ant_Body[j]->turn = false;
		}
		/*
		if (Ork_Body->x > Food[i]->x && Ork_Body->y > Food[i]->y)
		{
			Ork[0]->PlayAnimation(0, 4, 3, 200);
			Ork[0]->setX(Ork[0]->GetX() + 1);
			Ork[0]->setX(Ork[0]->GetY() + 1);
			Ork_Body->x += 1;
			Ork_Body->y += 1;
		}
		*/

		if (Ant_Body[j]->x > food[n]->x && Ant_Body[j]->turn)
		{
			Ork_Sprite[j]->PlayAnimation(0, 4, 4, 200);
			Ork_Sprite[j]->setX(Ork_Sprite[j]->GetX() - 1);
			Ant_Body[j]->x--;
			Ant_Body[j]->turn = false;
		}
		/*
		if (Ork_Body->x > Food[i]->x && Ork_Body->y < Food[i]->y)
		{
			Ork[0]->PlayAnimation(0, 4, 1, 200);
			Ork[0]->setX(Ork[0]->GetX() - 1);
			Ork[0]->setX(Ork[0]->GetY() + 1);
			Ork_Body->x -= 1;
			Ork_Body->y += 1;
		}
		*/

		if (Ant_Body[j]->y > food[n]->y && Ant_Body[j]->turn)
		{
			Ork_Sprite[j]->PlayAnimation(0, 4, 2, 200);
			Ork_Sprite[j]->setY(Ork_Sprite[j]->GetY() - 1);
			Ant_Body[j]->y--;
			Ant_Body[j]->turn = false;
		}

		if (Ant_Body[j]->y < food[n]->y && Ant_Body[j]->turn)
		{
			Ork_Sprite[j]->PlayAnimation(0, 2, 2, 200);
			Ork_Sprite[j]->setY(Ork_Sprite[j]->GetY() + 1);
			Ant_Body[j]->y++;
			Ant_Body[j]->turn = false;
		}

		timeChekc = SDL_GetTicks();
	}

}

void CMain::Go_ToBase(int j)
{
	Base_Sprite->PlayAnimation(0, 0, 0, 200);
	if (timeChekc + 60 < SDL_GetTicks())
	{
		if (Ant_Body[j]->x < colony->PosX)
		{
			Ork_Sprite[j]->PlayAnimation(0, 4, 0, 200);
			Ork_Sprite[j]->setX(Ork_Sprite[j]->GetX() + 1);
			Ant_Body[j]->x++;

		}


		if (Ant_Body[j]->x > colony->PosX)
		{
			Ork_Sprite[j]->PlayAnimation(0, 4, 4, 200);
			Ork_Sprite[j]->setX(Ork_Sprite[j]->GetX() - 1);
			Ant_Body[j]->x--;
		}


		if (Ant_Body[j]->y > colony->PosY)
		{
			Ork_Sprite[j]->PlayAnimation(0, 4, 2, 200);
			Ork_Sprite[j]->setY(Ork_Sprite[j]->GetY() - 1);
			Ant_Body[j]->y--;
		}

		if (Ant_Body[j]->y < colony->PosY)
		{
			Ork_Sprite[j]->PlayAnimation(0, 2, 2, 200);
			Ork_Sprite[j]->setY(Ork_Sprite[j]->GetY() + 1);
			Ant_Body[j]->y++;
		}

		timeChekc = SDL_GetTicks();
	}

}



void CMain::Cath(int j){
		for (int i = 0; i<30; ++i)
		{
			if ((Ant_Body[j]->x == food[i]->x) && (Ant_Body[j]->y == food[i]->y)){
				Ant_Body[j]->Invent = true;
				food[i]->spawn(WIDTH*WinScale, HEIGHT*WinScale);
				delete food_Sprite[i];
				food_Sprite[i] = new Sprites(sdl_setup->GetRenderer(), "DATA/test.png", food[i]->x, food[i]->y, 10, 10);
			}
		}
	}

void CMain::Eject(int j)
	{
	if ((Ant_Body[j]->Invent) && ((Ant_Body[j]->x == colony->PosX) && (Ant_Body[j]->y == colony->PosY)))
		{
		Ant_Body[j]->Invent = false;
			colony->Score+=1;

		}
	}






