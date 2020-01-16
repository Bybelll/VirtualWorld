#include "Animal.h"
#include<stdlib.h>
#include<time.h>


Animal::Animal(World* world, int strengh, int initiative, int x,int y, char symbol,bool canMove) : Organism(world, strengh, initiative, x,y, symbol,canMove)
{
	srand(time(NULL));
}


void Animal::action() {
	
	int direction = rand() % 8 + 1;
	
	switch (direction)
	{
	case 1:
		if (this->getX() == 1) {
			this->setX(2);
		}
		else {
			this->setX(this->getX() - 1);
		}
		if (this->getY() == 1) {
			this->setY(2);
		}
		else {
			this->setY(this->getY() - 1);
		}
		
			break;
	case 2:
		if (this->getY() == 1) {
			this->setY(2);
		}
		else {
			this->setY(this->getY() - 1);
		}
		break;
	case 3:
		if (this->getX() == this->getWorld()->getWidth()) {
			this->setX(this->getWorld()->getWidth() - 1);
		}
		else {
			this->setX(this->getX() + 1);
		}

		if (this->getY() == 1) {
			this->setY(2);
		}
		else {
			this->setY(this->getY() - 1);
		}

		break;
	case 4:
		if (this->getX() == 1) {
			this->setX(2);
		}
		else {
			this->setX(this->getX() - 1);
		}
		break;
	case 5:
		if (this->getX() == this->getWorld()->getWidth()) {
			this->setX(this->getWorld()->getWidth() - 1);
		}
		else {
			this->setX(this->getX() + 1);
		}
		break;
	case 6:
		if (this->getX() == 1) {
			this->setX(2);
		}
		else {
			this->setX(this->getX() - 1);
		}
		if (this->getY() == this->getWorld()->getHeight()) {
			this->setY(this->getWorld()->getHeight() - 1);
		}
		else {
			this->setY(this->getY() + 1);
		}
		break;
	case 7:
		if (this->getY() == this->getWorld()->getHeight()) {
			this->setY(this->getWorld()->getHeight() - 1);
		}
		else {
			this->setY(this->getY() + 1);
		}
		break;
	case 8:
		if (this->getX() == this->getWorld()->getWidth()) {
			this->setX(this->getWorld()->getWidth() - 1);
		}
		else {
			this->setX(this->getX() + 1);
		}
		if (this->getY() == this->getWorld()->getHeight()) {
			this->setY(this->getWorld()->getHeight() - 1);
		}
		else {
			this->setY(this->getY() + 1);
		}
		break;
	default:

		break;
	}
}