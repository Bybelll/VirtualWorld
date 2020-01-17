#include <iostream>
#include <conio.h>
#include "World.h"
#include "Wolf.h"      //W
#include "Sloth.h"     //L
#include "Turtle.h"   //T
#include "Sheep.h"    //S
#include "Kangaroo.h" //K             //rusza siê dwa razy
#include "Thorn.h"    //C
#include "Grass.h"   //G
#include "Guarana.h" //Z


using namespace std;

int main()
{
	int x;
	int y;

	cout << "Podaj wymiary swiata (x, y): ";
	cin >> x;
	cin >> y;
	
	World *world = new World(x,y);

	world->insertOrganism(new Wolf(world, 10, 10));
	world->insertOrganism(new Sloth(world, 20, 20));
	world->insertOrganism(new Kangaroo(world, 3, 2));
	world->insertOrganism(new Turtle(world,4,5));
	world->insertOrganism(new Sheep(world,1,1));

	world->insertOrganism(new Thorn(world, 15, 15,true));
	world->insertOrganism(new Grass(world, 2, 13,true));
	world->insertOrganism(new Guarana(world, 5, 10, true));

	
	world->drawWorld();

	char chase = 's';
	while (chase != 'q') {
		chase = _getch();
		world->doRound();

}

}

