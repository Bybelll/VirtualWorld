#include "Organism.h"
#include <iostream>



World* Organism::getWorld()
{
	return this->world;
}

char Organism::getSymbol()
{
	return this->symbol;
}

bool Organism::isToDelete()
{
	return toDelete;
}

void Organism::setCanMove(bool canMove)
{
	this->canMove = canMove;
}

bool Organism::getCanMove()
{
	return this->canMove;
}

Organism::Organism(World* world, int strengh, int initiative, int x,int y, char symbol,bool canMove)
{
	this->world = world;
	this->strengh = strengh;
	this->initiative = initiative;
	this->x = x;
	this->y = y;
	this->symbol = symbol;
	this->canMove = canMove;
}


void Organism::draw()
{
	this->world->moveCursorTo(this->getX(), this->getY());
	std::cout << this->symbol;
	
}

int Organism::getInitiative()
{
	return this->initiative;
}

void Organism::setX(int x)
{
	this->x = x;
}
void Organism::setY(int y)
{
	this->y = y;
}
int Organism::getX()
{
	return x;
}
int Organism::getY()
{
	return y;
}