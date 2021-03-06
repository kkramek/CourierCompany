#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Game.h"

using namespace std;

class FileManager
{
public:
	FileManager();
	~FileManager();

	bool SaveGame();
	bool LoadGame();
	void LoadVehicleList();
	void LoadRoadList();
	void LoadHouseList();
};

