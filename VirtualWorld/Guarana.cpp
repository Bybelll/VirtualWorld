#include "Guarana.h"

Guarana::Guarana(World* world, int x, int y, bool canMove) : Plant(world, 0, x, y, 'Z', true, 20) {

}

Guarana::~Guarana()
{
}

bool Guarana::reproduce() {
	Guarana* offspring = new Guarana(this->getWorld(), this->getX(), this->getY(), false);
	if (this->tryReproduce(offspring)) {
		return true;
	}
	else {
		delete offspring;
		return false;
	}
}

bool Guarana::collision()
{
	return false;
}
