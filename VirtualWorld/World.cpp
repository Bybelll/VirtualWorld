#include "World.h"
#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;
void World::drawWorld() {

	this->moveCursorTo(0, 0);
	for (int i = 0; i < 20 + 2; i++) {
		cout << "-";
	}
	for (int i = 1; i < 20 + 1; i++) {
		cout << endl << "|";
		this->moveCursorTo(20 + 1, i);
		cout << "|";
	}
	cout << endl;
	for (int i = 0; i < 20 + 2; i++) {
		cout << "-";
	}
}

void World::moveCursorTo(int x, int y)
{
	COORD p = { x, y + 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}