#include "Wolf.h"

Wolf::Wolf(World* world,int x,int y) : Animal(world, 9, 5,x,y,'W')
{

}

Wolf::~Wolf()
{
}

bool Wolf::reproduce()
{
	Wolf* offspring = new Wolf(this->getWorld(), this->getX(), this->getY());
	if (Animal::tryReproduce(offspring)) {
		return true;
	}
	else {
		delete offspring;
		return false;
	}
}
