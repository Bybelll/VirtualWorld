#include "Kangaroo.h"


Kangaroo::Kangaroo(World* world, int x, int y) : Animal(world, 8, 8, x, y, 'K') 
{
}

void Kangaroo::action()
{
	Animal::action();
	Animal::action();
}

bool Kangaroo::reproduce()
{
	Kangaroo* offspring = new Kangaroo(this->getWorld(), this->getX(), this->getY());
	if (Animal::tryReproduce(offspring)) {
		return true;
	}
	else {
		delete offspring;
		return false;
	}
}
