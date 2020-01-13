#pragma once
#include "World.h"
class World; //forward deklaration (deklaracja przekazania)


class Organism
{
	int strengh;
	int initiative;
	int x;
	int y;
	World* world;


public:
	Organism(World* world, int strengh, int initiative, int x,int y, char symbol);
	void action();
	void collision();
	void draw();
	int getInitiative();
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();


	char symbol;
};

