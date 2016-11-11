#pragma once
#include "Player.h"
#include "Vehicle.h"
#include <string>
#include <iostream>


class Game
{

public:
	Game();
	~Game();
	
	void SetPlayer(string playerName);
	static Game* getInstance();
	Player* GetPlayer();

private:
	static Game *instance;
	Player* player;
	//Vehicle	vehicle;

};



