#pragma once
#include "ListItem.h"
#include "Organism.h"
class ListItem;
class Organism;

class OrganismList
{
private:
	ListItem* head;

public:
	OrganismList();
	~OrganismList();
	void insert(Organism* organism);
	void drawOrganisms();
	void action();
	ListItem* search(int x, int y);
	void remove(ListItem*);
	void refreshMove();
};

