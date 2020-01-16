#pragma once
#include "World.h"
class World; //forward deklaration (deklaracja przekazania)


class Organism
{

	int strengh;
	int initiative;
	int x;
	int y;
	char symbol;
	World* world;
	bool toDelete = false;
	bool canMove;



public:
	Organism(World* world, int strengh, int initiative, int x,int y, char symbol,bool CanMove);
	virtual void action() = 0;
	void collision();
	void draw();
	int getInitiative();
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
	World* getWorld();
	char getSymbol();
	bool isToDelete();
	void setCanMove(bool canMove);
	bool getCanMove();
};

