#include "Thorn.h"


using namespace std;

Thorn::Thorn(World* world, int x, int y,bool canMove) : Plant(world, 2, x, y, 'c',canMove,100)
{
}

Thorn::~Thorn() {

}


bool Thorn::reproduce() {
	Thorn* offspring = new Thorn(this->getWorld(), this->getX(), this->getY(), false);
	if (this->tryReproduce(offspring)) {
		return true;
	}
	else {
		delete offspring;
		return false;
	}
}