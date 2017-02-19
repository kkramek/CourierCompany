#include "Coordinates.h"


class House
{
public:
	House(int roadId, int houseNumber, int roadPointX, int roadPointY, int topLeftCornerX, int topLeftCornerY);
	~House();

private:
	int roadId;
	int houseNumber;
	Coordinates* roadPoint;
	Coordinates* topLeftCorner;
};

