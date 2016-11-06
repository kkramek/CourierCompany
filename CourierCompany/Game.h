#pragma once
#include "Player.h"
#include "Courier.h"
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
	Courier	courier;

};



