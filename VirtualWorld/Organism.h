#pragma once
#include "World.h"
class World; //forward deklaration (deklaracja przekazania)


class Organism
{

	int strength;
	int initiative;
	int x;
	int y;
	char symbol;
	World* world;
	bool canMove;
	bool toDelete = false;


public:
	Organism(World* world, int strengh, int initiative, int x,int y, char symbol,bool CanMove);
	virtual void action() = 0;
	virtual bool collision(Organism* organism) = 0;
	virtual bool reproduce() = 0;
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
	int getStrength();
	void setToDelete();
	bool getToDelete();
	void setStrength(int);
};

