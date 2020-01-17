#include "Sheep.h"

Sheep::Sheep(World* world, int x, int y) : Animal(world, 4, 4, x, y, 'S')
{}

bool Sheep::reproduce()
{
	Sheep* offspring = new Sheep(this->getWorld(), this->getX(), this->getY());
	if (Animal::tryReproduce(offspring)) {
		return true;
	}
	else {
		delete offspring;
		return false;
	}
}
