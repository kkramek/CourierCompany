#pragma once
#include <vector>
#include "Road.h"
#include "House.h"

using namespace std;

class MapLibrary
{
public:
	MapLibrary();
	~MapLibrary();

	static MapLibrary* GetInstance();

	void GetHouseList();
	void GetRoadList();

	int GetRandomHouse();

private:
	static MapLibrary *instance;
	vector < Road* > roadList;
	vector < House* > houseList;
};

