#include "ListItem.h"

ListItem::ListItem(Organism* organism) {
	this->organism = organism;
	this->next = nullptr;
	this->prev = nullptr;
}
ListItem::~ListItem() {
	delete this->organism;
}
void ListItem::setNext(ListItem* newNext) {
	this->next = newNext;
}
void ListItem::setPrev(ListItem* newPrev) {
	this->prev = newPrev;
}
ListItem* ListItem::getNext() {
	return this->next;
}
ListItem* ListItem::getPrev() {
	return this->prev;
}
Organism* ListItem::getOrganism() {
	return this->organism;
}
