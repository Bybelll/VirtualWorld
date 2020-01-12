#include <iostream>
#include <list>
#include "World.h"
#include "Wolf.h"
using namespace std;

int main()
{
	World *world = new World();
	Wolf* wolf = new Wolf(world, 10, 10);

	world->drawWorld();
}

