#include "Sloth.h"
#include<stdlib.h>

Sloth::Sloth(World* world, int x, int y) : Animal(world, 2, 1, x, y, 'L')
{ 
	this->canMove = true;
}

void Sloth::action()
{
	int chance = rand() % 3;
	if (canMove) {
		Animal::action();
		canMove = false;
	}
	else if (chance == 0){
		canMove = true;
	}
}

bool Sloth::reproduce()
{
	Sloth* offspring = new Sloth(this->getWorld(), this->getX(), this->getY());
	if (Animal::tryReproduce(offspring)) {
		return true;
	}
	else {
		delete offspring;
		return false;
	}
}
