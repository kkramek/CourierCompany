#include "stdafx.h"
#include "Coordinates.h"


Coordinates::Coordinates(int x, int y)
{
	this->x = x;
	this->y = y;
}


Coordinates::~Coordinates()
{
}

Coordinates * Coordinates::getCoordinates()
{
	return this;
}
