#pragma once
#include "Organism.h"
#include "OrganismList.h"
class Organism;
class OrganismList;

class World
{
private:
	int width;
	int height;
	OrganismList* organismList;
	

public:
	World(int width, int height);
	void doRound();
	void drawWorld();
	void moveCursorTo(int, int);
	void insertOrganism(Organism*);

};

