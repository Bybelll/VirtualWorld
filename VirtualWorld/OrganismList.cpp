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
				break;
				
			}
			else if (tmp->getNext()->getOrganism()->getInitiative() < newItem->getOrganism()->getInitiative()) {
				newItem->setNext(tmp->getNext());
				newItem->setPrev(tmp);
				tmp->setNext(newItem);
				newItem->getNext()->setPrev(newItem);
				break;
			}
			else {
				tmp = tmp->getNext();
			}

		}
		if (head->getOrganism()->getInitiative() < newItem->getOrganism()->getInitiative()) {
			head->setPrev(newItem);
			newItem->setNext(head);
			head = newItem;
		}

	}
}

void OrganismList::drawOrganisms()
{
	ListItem* iter = head;
	while (iter != nullptr) {

			iter->getOrganism()->draw();
			iter = iter->getNext();
	}
}

void OrganismList::action()
{
	ListItem* iter = head;
	while (iter != nullptr) {
		iter->getOrganism()->action();
		iter = iter->getNext();
	}
}

ListItem* OrganismList::search(int x, int y) {
	ListItem* iter = head;
	while (iter != nullptr) {
		Organism* searchOrganism = iter->getOrganism();
		if (searchOrganism->isToDelete()) {
			ListItem* toRemove = iter;
			iter = iter->getNext();
			this->remove(toRemove);
		}
		else {
			if (searchOrganism->getX() == x && searchOrganism->getY() == y) {
				return iter;
			}
			else {
				iter = iter->getNext();
			}
		}
	}
	return nullptr;
}

void OrganismList::remove(ListItem* toRemove) {
	ListItem* tmpPrev = toRemove->getPrev();
	ListItem* tmpNext = toRemove->getNext();
	if (tmpNext == nullptr && tmpPrev == nullptr) {
		head = nullptr;
	}
	else {
		if (tmpPrev != nullptr) {
			tmpPrev->setNext(tmpNext);
		}
		if (tmpNext != nullptr) {
			tmpNext->setPrev(tmpPrev);
			if (head == toRemove) {
				head = tmpNext;
			}
		}
	}
	delete toRemove;
}

void OrganismList::refreshMove()
{
	ListItem* iter = head;
	while (iter != nullptr) {
		iter->getOrganism()->setCanMove(true);
		iter = iter->getNext();
	}
}
