#pragma once
class Coordinates
{
public:
	Coordinates(int x, int y);
	~Coordinates();
	Coordinates* getCoordinates();

private:
	int x, y;

};

