#pragma once
#include "Animal.h"


class Sloth : public Animal
{
private:
	bool canMove;
public:
	Sloth(World* world, int x, int y);
	void action();
	bool reproduce();
};

