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

	void SaveGame();
	void LoadGame();
	void LoadVehicleList();
};

