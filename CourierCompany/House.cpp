#include "stdafx.h"
#include "House.h"


House::House(int roadId, int houseNumber, int roadPointX, int roadPointY, int topLeftCornerX, int topLeftCornerY)
{
	this->roadId = roadId;
	this->houseNumber = houseNumber;
	this->roadPoint = new Coordinates(roadPointX, roadPointY);
	this->topLeftCorner = new Coordinates(topLeftCornerX, topLeftCornerY);
}


House::~House()
{
}
