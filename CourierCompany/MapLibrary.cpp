#include "stdafx.h"
#include "MapLibrary.h"
#include <cstdlib>
#include <ctime>

MapLibrary* MapLibrary::instance = NULL;

MapLibrary::MapLibrary()
{
	this->GetRoadList();
	this->GetHouseList();
}


MapLibrary::~MapLibrary()
{
}

MapLibrary * MapLibrary::GetInstance() {

	if (!instance) {
		instance = new MapLibrary();
	};

	return instance;
};

int MapLibrary::GetRandomHouse()
{
	srand(time(NULL));
	return (std::rand() % houseList.size());
}

void MapLibrary::GetHouseList()
{
	this->houseList.push_back(new House(1,1,299,152,291,148));
}

void MapLibrary::GetRoadList()
{
	this->roadList.push_back(new Road(1, "Krakowska", 300, 139, 300, 255));
}