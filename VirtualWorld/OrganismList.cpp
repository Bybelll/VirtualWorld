#include "OrganismList.h"

OrganismList::OrganismList() {
	this->head = nullptr;
}

OrganismList::~OrganismList() {
	if (head == nullptr) {
		return;
	}
	ListItem* current = head;
	while (current->getNext() != nullptr) {
		current = current->getNext();
		delete current->getPrev();
	}
	delete current;
}

void OrganismList::insert(Organism* organism)
{
	ListItem* newItem = new ListItem(organism);
	if (this->head == nullptr) {
		this->head = newItem;
	}
	else {
		ListItem* tmp=head;
		while (tmp->getOrganism()->getInitiative() >= newItem->getOrganism()->getInitiative()) {
			if (tmp->getNext() == nullptr) {
				tmp->setNext(newItem);
				newItem->setPrev(tmp);
				
			}
			else if (tmp->getNext()->getOrganism()->getInitiative() < newItem->getOrganism()->getInitiative()) {
				newItem->setNext(tmp->getNext());
				newItem->setPrev(tmp);
				tmp->setNext(newItem);
				newItem->getNext()->setPrev(newItem);
			}
			else {
				tmp = tmp->getNext();
			}

		}


	}
}
