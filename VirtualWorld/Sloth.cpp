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
