#include "Sloth.h"

Sloth::Sloth(World* world, int x, int y) : Animal(world, 2, 1, x, y, 'L')
{ 
	this->canMove = true;
}