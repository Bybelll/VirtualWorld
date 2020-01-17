#include "Grass.h"

Grass::Grass(World* world, int x, int y, bool canMove) : Plant(world, 0, x, y, 'G', canMove, 20)
{
}

Grass::~Grass() {

}

bool Grass::reproduce() {
	Grass* offspring = new Grass(this->getWorld(), this->getX(), this->getY(), false);
	if (this->tryReproduce(offspring)) {
		return true;
	}
	else {
		delete offspring;
		return false;
	}
}