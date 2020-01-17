#include "Animal.h"
#include<stdlib.h>
#include<time.h>
#include <iostream>
using namespace std;

Animal::Animal(World* world, int strengh, int initiative, int x,int y, char symbol,bool canMove) : Organism(world, strengh, initiative, x,y, symbol,canMove)
{
	srand(time(NULL));
}


void Animal::action() {
	if (!this->getCanMove()) {
		this->setCanMove(true);
		return;
	}
	int direction = rand() % 8 + 1;
	cout << "Zwierze " << this->getSymbol() << " idzie ";

	int newX = this->getX();
	int newY = this->getY();

	switch (direction)
	{
	case 1:
		cout << " na polnocny zachod ";
		if (newX == 1) {
			newX = 2;
		}
		else {
			newX = newX - 1;
		}
		if (newY == 1) {
			newY = 2;
		}
		else {
			newY = newY - 1;
		}
			break;
	case 2:
		cout << " na polnoc";
		if (newY == 1) {
			newY = 2;
		}
		else {
			newY = newY - 1;
		}
		break;
	case 3:
		cout << " na polnocny wschod";
		if (newX == this->getWorld()->getWidth()) {
			newX = this->getWorld()->getWidth() - 1;
		}
		else {
			newX = newX + 1;
		}

		if (newY == 1) {
			newY = 2;
		}
		else {
			newY = newY - 1;
		}

		break;
	case 4:
		cout << " na zachod";;
		if (newX == 1) {
			newX = 2;
		}
		else {
			newX = newX - 1;
		}
		break;
	case 5:
		cout << " na wschod";
		if (newX == this->getWorld()->getWidth()) {
			newX = this->getWorld()->getWidth() - 1;
		}
		else {
			newX = newX + 1;
		}
		break;
	case 6:
		cout << " na poludniowy zachod";
		if (newX == 1) {
			newX = 2;
		}
		else {
			newX = newX - 1;
		}
		if (newY == this->getWorld()->getHeight()) {
			newY = this->getWorld()->getHeight() - 1;
		}
		else {
			newY = newY + 1;
		}
		break;
	case 7:
		cout << " na poludnie";
		if (newY == this->getWorld()->getHeight()) {
			newY = this->getWorld()->getHeight() - 1;
		}
		else {
			newY = newY + 1;
		}
		break;
	case 8:
		cout << " na poludniowy wschod";
		if (newX == this->getWorld()->getWidth()) {
			newX = this->getWorld()->getWidth() - 1;
		}
		else {
			newX = newX + 1;
		}
		if (newY == this->getWorld()->getHeight()) {
			newY = this->getWorld()->getHeight() - 1;
		}
		else {
			newY = newY + 1;
		}
		break;
	default:
		cout << "cos poszlo nie tak przy poruszaniu sie";
		break;
	}
	cout << endl;
	Organism* colliding = this->getWorld()->getOrganismFromPosition(newX, newY);
	if (colliding != nullptr) {

		cout << "Kolizja zwierzecia: " << this->getSymbol() << " z " << colliding->getSymbol() << endl;
		if (colliding->collision(this)) {
			this->setX(newX);
			this->setY(newY);
		}
	}
	else {
		this->setX(newX);
		this->setY(newY);
	}
	this->setCanMove(false);
}

bool Animal::collision(Organism* colliding)
{
	if (colliding->getSymbol() == this->getSymbol()) {
		Animal* collidingSameAnimal = dynamic_cast<Animal*>(colliding);
		cout << "Proba rozmnozenia sie zwierzecia " << this->getSymbol() << "... ";
		bool tryMultiply = this->reproduce();
		if (!tryMultiply) {
			tryMultiply = collidingSameAnimal->reproduce();
		}
		if (tryMultiply) {
			cout << "Sukces!" << endl;
		}
		else {
			cout << "Brak miejsca!" << endl;
		}
		return false;
	}
	else {
		cout << "Walka! ";
		if (this->getStrength() > colliding->getStrength()) {
			cout << "Atakujace zwierze " << colliding->getSymbol() << " przegrywa i umiera!" << endl;
			colliding->setToDelete();
		}
		else {
			cout << "Atakujace zwierze " << colliding->getSymbol() << " wygrywa! Zwierze " << this->getSymbol() << " umiera" << endl;
			this->setToDelete();
		}
		return true;
	}
}

bool Animal::tryReproduce(Organism* child)
{
	int tmpX = this->getX();
	int tmpY = this->getY();

	Organism* occupied;
	for (int i = -1;i < 2;i++) {
		if (tmpX + i == 0 || tmpX+i==this->getWorld()->getWidth())
			continue;

		for (int j = -1;j < 2;j++) {
			if (tmpY + i == 0 || tmpY + i == this->getWorld()->getWidth())
				continue;

			occupied = this->getWorld()->getOrganismFromPosition(tmpX+i, tmpY+j);
			if (occupied == nullptr) {
				child->setX(tmpX + i);
				child->setY(tmpY + j);
				this->getWorld()->insertOrganism(child);
				return true;
			}

		}
	}
	
	return false;
}
