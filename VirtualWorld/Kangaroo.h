#pragma once
#include "Animal.h"
class Kangaroo :
	public Animal
{

public:
	Kangaroo(World* world, int x, int y);
	void action();
};

