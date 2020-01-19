#include "Guarana.h"
#include <iostream>
using namespace std;

Guarana::Guarana(World* world, int x, int y, bool canMove) : Plant(world, 0, x, y, 'Z', true, 20) {

}

Guarana::~Guarana()
{
}

bool Guarana::reproduce() {
	Guarana* offspring = new Guarana(this->getWorld(), this->getX(), this->getY(), false);
	if (this->tryReproduce(offspring)) {
		return true;
	}
	else {
		delete offspring;
		return false;
	}
}

bool Guarana::collision(Organism* org)
{ 
	if (this->Plant::collision(org) && this->getToDelete()) {
		// If we got here, it means that colliding organism ate Wolfberry => it dies
		cout << "Roslina " << this->getSymbol() << " dodaje si³y! Zwierze " << org->getSymbol() << " zyskuje +3 do sily" << endl;
		org->setStrength(org->getStrength()+3);
		return true;
	}
	return false;
}
