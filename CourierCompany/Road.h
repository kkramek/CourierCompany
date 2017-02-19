#include <string>
#include <iostream>
#include "stdafx.h"
#include "Coordinates.h"

using namespace std;

class Road
{
public:
	Road(int id, string name, int startPointX, int startPointY, int endPointX, int endPointY);
	~Road();

private:
	int id;
	string name;
	Coordinates* startPoint;
	Coordinates* endPoint;

};

