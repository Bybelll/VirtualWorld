#include "Animal.h"
#include<stdlib.h>
#include<time.h>


Animal::Animal(World* world, int strengh, int initiative, int x,int y, char symbol) : Organism(world, strengh, initiative, x,y, symbol)
{}


void Animal::action() {
	srand(time(NULL));
	int direction = rand() % 8 + 1;
	
	switch (direction)
	{
	case 1:
		this->setX(this->getX() - 1);
		this->setY(this->getY() - 1);
			break;
	case 2:
		this->setY(this->getY() - 1);
		break;
	case 3:
		this->setX(this->getX() + 1);
		this->setY(this->getY() - 1);
		break;
	case 4:
		this->setX(this->getX() - 1);
		break;
	case 5:
		this->setX(this->getX() + 1);
		break;
	case 6:
		this->setX(this->getX() - 1);
		this->setY(this->getY() + 1);
		break;
	case 7:
		this->setY(this->getY() + 1);
		break;
	case 8:
		this->setX(this->getX() + 1);
		this->setY(this->getY() + 1);
		break;
	default:

		break;
	}
}