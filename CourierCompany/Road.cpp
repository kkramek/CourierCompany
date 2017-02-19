#include "stdafx.h"
#include "Road.h"


Road::Road(int id, string name, int startPointX, int startPointY, int endPointX, int endPointY)
{
	this->id = id;
	this->name = name;
	this->startPoint = new Coordinates(startPointX, startPointY);
	this->endPoint = new Coordinates(endPointX, endPointY);

}


Road::~Road()
{
}
