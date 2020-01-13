#pragma once
#include "Organism.h"
class Organism;

class ListItem
{
private:
	Organism* organism;
	ListItem* next;
	ListItem* prev;

public:
	ListItem(Organism*);
	~ListItem();
	void setNext(ListItem*);
	void setPrev(ListItem*);
	ListItem* getNext();
	ListItem* getPrev();
	Organism* getOrganism();
};

