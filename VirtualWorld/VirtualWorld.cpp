#include <iostream>
#include <list>
#include "World.h"
#include "Wolf.h"
#include "Sloth.h"
using namespace std;

int main()
{
	int x;
	int y;

	cout << "Podaj wymiary swiata (x, y): ";
	cin >> x;
	cin >> y;
	
	World *world = new World(x,y);


	Wolf *wolf = new Wolf(world, 10, 10);
	Sloth* sloth = new Sloth(world, 20, 20);

	world->insertOrganism(sloth);
	world->insertOrganism(wolf);



	world->drawWorld();
}

