#include "stdafx.h"
#include "Game.h"
#include "StartWindowDlg.h"

Game* Game::instance = NULL;

Game::Game()
{ 
}


Game::~Game()
{
}

Game * Game::getInstance() {

	if (!instance) {
		instance = new Game();
		srand(time(NULL));
	};

	return instance;
};

void Game::SetPlayer(string playerName)
{
	this->player = new Player(playerName);
}

Player * Game::GetPlayer()
{
	return this->player;
}
