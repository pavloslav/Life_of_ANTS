#ifndef BASE_H
#define BASE_H


class Colony;

class Base
{
public:

    Base( int x, int y);
	int PosX;
	int PosY;
    void print() const;
    void draw() const;
	int Score;
private:
    int size;

};

#endif // BASE_H


