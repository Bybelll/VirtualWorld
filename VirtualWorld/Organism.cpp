#include "Organism.h"
#include <iostream>



Organism::Organism(World* world, int strengh, int initiative, int x,int y, char symbol)
{
	this->world = world;
	this->strengh = strengh;
	this->initiative = initiative;
	this->x = x;
	this->y = y;
	this->symbol = symbol;
}


void Organism::draw()
{
	this->world->moveCursorTo(this->getX(), this->getY());
	std::cout << this->symbol;
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