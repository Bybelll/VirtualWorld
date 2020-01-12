#pragma once
#include <list>
#include "Organism.h"
class Organism;

class World
{
private:



public:
	std::list <Organism*> organisms;
	void doRound();
	void drawWorld();
	void moveCursorTo(int, int);
};

