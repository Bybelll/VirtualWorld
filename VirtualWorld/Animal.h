#pragma once
#include "Organism.h"
class Animal : public Organism
{


public:
	Animal(World* world, int strengh, int initiative,int x,int y, char symbol,bool canMove=true);
	void action();
	virtual bool collision(Organism* organism);
	virtual bool reproduce() = 0;
	virtual bool tryReproduce(Organism*);
};

