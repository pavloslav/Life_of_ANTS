#ifndef FOOD_H
#define FOOD_H
#include <time.h>
#include <stdlib.h>

class Food 
{
public:
	int x;
	int y;
        Food();
		void spawn(int WIDTH, int HEIGHT);
};

#endif // FOOD_H