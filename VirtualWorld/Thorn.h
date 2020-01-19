#pragma once
#include "Plant.h"
//#include "World.h"

class Thorn : public Plant
{
public:
	Thorn(World*, int, int, bool);
	~Thorn();
	bool reproduce();
};
