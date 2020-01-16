#include "Kangaroo.h"


Kangaroo::Kangaroo(World* world, int x, int y) : Animal(world, 8, 8, x, y, 'K') 
{
}

void Kangaroo::action()
{
	Animal::action();
	Animal::action();
}
