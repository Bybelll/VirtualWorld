#include "World.h"
#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

World::World(int width, int height) {

	this->organismList = new OrganismList();

	if (height > 40) {
		this->height = 40;
	}
	else if(height<5)
	{
		this->height = 5;
	}
	else {
		this->height = height;
	}

	if (width > 80) {
		this->width = 80;
	}
	else if (width < 5)
	{
		this->width = 5;
	}
	else {
		this->width = width;
	}
}

void World::doRound()
{
	system("cls");
	cout << "Michal Reclaw 150529" << endl;
	this->moveCursorTo(0, this->getHeight() + 2);
	this->organismList->action();
	this->drawWorld();
	this->organismList->refreshMove();
}

void World::drawWorld() {

	this->moveCursorTo(0, 0);
	for (int i = 0; i < width + 2; i++) {
		cout << "-";
	}
	for (int i = 1; i < height+ 1; i++) {
		cout << endl << "|";
		this->moveCursorTo(width + 1, i);
		cout << "|";
	}
	cout << endl;
	for (int i = 0; i < width + 2; i++) {
		cout << "-";
	}

	this->organismList->drawOrganisms();


	this->moveCursorTo(0, height + 3);
}

void World::moveCursorTo(int x, int y)
{
	COORD p = { x, y + 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void World::insertOrganism(Organism* organism)
{
	this->organismList->insert(organism);
}

int World::getWidth()
{
	return this->width;
}

int World::getHeight()
{
	return this->height;
}

Organism* World::getOrganismFromPosition(int x, int y) {
	ListItem* iter = this->organismList->search(x, y);
	if (iter != nullptr) {
		return iter->getOrganism();
	}
	else {
		return nullptr;
	}
}







