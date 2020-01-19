#include <iostream>
#include <conio.h>
#include <time.h>

#include "World.h"
//Animals
#include "Wolf.h"      //W
#include "Sloth.h"     //L
#include "Turtle.h"   //T
#include "Sheep.h"    //S
#include "Kangaroo.h" //K             //rusza siê dwa razy
//Plants
#include "Thorn.h"    //C
#include "Grass.h"   //G
#include "Guarana.h" //Z


using namespace std;

int main()
{
	int x;
	int y;
	char chase = 's';

	cout << "Podaj wymiary swiata x=(5,80), y=(5,40): ";
	cin >> x;
	cin >> y;
	
	World *world = new World(x,y);
	srand(time(NULL));

	//world->insertOrganism(new Sloth(world, 20, 20));
	//world->insertOrganism(new Kangaroo(world, 3, 2));
	//world->insertOrganism(new Turtle(world,4,5));
	//world->insertOrganism(new Sheep(world,1,1));

	//world->insertOrganism(new Thorn(world, 15, 15,true));
	//world->insertOrganism(new Grass(world, 2, 13,true));
	//world->insertOrganism(new Guarana(world, 1, 1, true));

	cout <<  "Dodaj organism" << endl;
	cout << "w wilk, l leniwiec, t zolw, s owca, k kangur, c ciern, g trawa, z guarana" << endl;
	cout << " q zeby wyjsc z dodawania" << endl;
	cout << endl;

	while (chase != 'q') {

		chase = _getch();

		int newX = rand() % world->getWidth() + 1;
		int newY = rand() % world->getHeight() + 1;

		switch (chase)
		{
		case 'w':
			if (world->getOrganismFromPosition(newX, newY) == nullptr) {
				world->insertOrganism(new Wolf(world, newX, newY));
				cout << "wilk pomyslnie dodany do swiata." << endl;
			}
			else {
				cout << " Nie uda³o siê dodac wilka. Pole (" << newX << "," << newY << ") jest zajete." << endl;
			}
			break;
		case 'l':
			if (world->getOrganismFromPosition(newX, newY) == nullptr) {
				world->insertOrganism(new Sloth(world, newX, newY));
				cout << "leniwiec pomyslnie dodany do swiata." << endl;
			}
			else {
				cout << " Nie uda³o siê dodac leniwca. Pole (" << newX << "," << newY << ") jest zajete."<<endl;
			}
			break;
		case 't':
			if (world->getOrganismFromPosition(newX, newY) == nullptr) {
				world->insertOrganism(new Turtle(world, newX, newY));
				cout << "zolw pomyslnie dodany do swiata." << endl;
			}
			else {
				cout << " Nie uda³o siê dodac zolwia. Pole (" << newX << "," << newY << ") jest zajete." << endl;
			}
			break;
		case 's':
			if (world->getOrganismFromPosition(newX, newY) == nullptr) {
				world->insertOrganism(new Sheep(world, newX, newY));
				cout << "owca pomyslnie dodany do swiata." << endl;
			}
			else {
				cout << " Nie uda³o siê dodac owcy. Pole (" << newX << "," << newY << ") jest zajete." << endl;
			}
			break;
		case 'k':
			if (world->getOrganismFromPosition(newX, newY) == nullptr) {
				world->insertOrganism(new Kangaroo(world, newX, newY));
				cout << "kangur pomyslnie dodany do swiata." << endl;
			}
			else {
				cout << " Nie uda³o siê dodac kangura. Pole (" << newX << "," << newY << ") jest zajete." << endl;
			}
			break;
		case 'c':
			if (world->getOrganismFromPosition(newX, newY) == nullptr) {
				world->insertOrganism(new Thorn(world, newX, newY,true));
				cout << "ciern pomyslnie dodany do swiata." << endl;
			}
			else {
				cout << " Nie uda³o siê dodac ciern. Pole (" << newX << "," << newY << ") jest zajete." << endl;
			}
			break;
		case 'g':
			if (world->getOrganismFromPosition(newX, newY) == nullptr) {
				world->insertOrganism(new Grass(world, newX, newY));
				cout << "trawa pomyslnie dodany do swiata." << endl;
			}
			else {
				cout << " Nie uda³o siê dodac trawy. Pole (" << newX << "," << newY << ") jest zajete." << endl;
			}
			break;
		case 'z':
			if (world->getOrganismFromPosition(newX, newY) == nullptr) {
				world->insertOrganism(new Guarana(world, newX, newY,true));
				cout << "guarana pomyslnie dodany do swiata." << endl;
			}
			else {
				cout << " Nie uda³o siê dodac guarany. Pole (" << newX << "," << newY << ") jest zajete." << endl;
			}
			break;
		default:
			cout << "Podales zly znak." << endl;
			break;
		}


	}






	system("cls");
	world->drawWorld();

	chase = 's';
	while (chase != 'q') {
		chase = _getch();
		world->doRound();

}

}

