#include "Plant.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

Plant::Plant(World* world, int strength, int x, int y, char symbol,bool canMove,int reproducingChance) : Organism(world, strength, 0, x, y, symbol,canMove)
{
	this->reproducingChance = reproducingChance;
}


Plant::~Plant()
{
}

void Plant::action() {
	if (!this->getCanMove()) {
		this->setCanMove(true);
		return;
	}
	cout << "Roslina " << this->getSymbol() << " probuje sie rozmnozyc";
	int randomNumber = rand() % 100;
	if (randomNumber > reproducingChance) {
		cout << " - nie udalo sie" << endl;
	}
	else {
		this->reproduce();
	}
	this->setCanMove(false);
}

bool Plant::tryReproduce(Organism* child) {
	cout << " na ";
	int direction = rand()%8 +1;
	int newX = this->getX();
	int newY = this->getY();
	switch (direction)
	{
	case 1:
		cout << " na polnocny zachod";
		if (this->getX() == 1) {
			newX = 2;
		}
		else {
			newX = newX-1;
		}
		if (this->getY() == 1) {
			newY = 2;
		}
		else {
			newY = newY  -1 ;
		}

		break;
	case 2:
		cout << " polnoc";
		if (this->getY() == 1) {
			newY = 2;
		}
		else {
			newY = newY - 1;
		}
		break;
	case 3:
		cout << " polnocny wschod";
		if (this->getX() == this->getWorld()->getWidth()) {
			newX = this->getWorld()->getWidth() - 1;
		}
		else {
			newX = newX + 1;
		}

		if (this->getY() == 1) {
			this->setY(2);
		}
		else {
			newY = newY - 1;
		}

		break;
	case 4:
		cout << " zachod";
		if (this->getX() == 1) {
			newX = 2;
		}
		else {
			newX = newX - 1;

		}
		break;
	case 5:
		cout << " wschod ";
		if (this->getX() == this->getWorld()->getWidth()) {
			newX = this->getWorld()->getWidth() - 1;
		}
		else {
			newX = newX + 1;
		}
		break;
	case 6:
		cout << " poludniowy zachod";
		if (this->getX() == 1) {
			this->setX(2);
		}
		else {
			newX = newX - 1;
		}
		if (this->getY() == this->getWorld()->getHeight()) {
			newY = this->getWorld()->getHeight() - 1;
		}
		else {
			newY = newY + 1;
		}
		break;
	case 7:
		cout << " poludnie";
		if (this->getY() == this->getWorld()->getHeight()) {
			newY = this->getWorld()->getHeight() - 1;
		}
		else {
			newY = newY + 1;
		}
		break;
	case 8:
		cout << " poludniowy wschod";
		if (this->getX() == this->getWorld()->getWidth()) {
			newX = this->getWorld()->getWidth() - 1;
		}
		else {
			newX = newX + 1;
		}
		if (this->getY() == this->getWorld()->getHeight()) {
			newY = this->getWorld()->getHeight() - 1;
		}
		else {
			newY = newY + 1;
		}
		break;
	default:

		break;
	}

	Organism* colliding = this->getWorld()->getOrganismFromPosition(newX, newY);
	if (colliding != nullptr) {
		cout << " ale to pole jest zajete" << endl;
		return false;
	}
	else {
		cout << ". Sukces" << endl;
		child->setX(newX);
		child->setY(newY);
		this->getWorld()->insertOrganism(child);
		return true;
	}
}

