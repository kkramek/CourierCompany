#include "stdafx.h"
#include "FileManager.h"


FileManager::FileManager()
{
}


FileManager::~FileManager()
{
}

//TODO: Stworzy� funkcje zapisuj�c� stan gry do pliku
void FileManager::SaveGame()
{
	/*
		Og�lnie masz za zadanie pobiera� wszystkie elementy gry i zapisywa� je do pliku .bin
		Strukture pliku musisz sobie tak przemy�le� �eby� potem nie mia� problemu ze zrobieniem 
		funkcji odczytu stanu gry. Narazie skup si� na tych danych kt�re Ci wy�ej wymieni�em. 
		Jak ju� b�dzie dzia�a� to b�d� Ci podsy�a� kolejne elementy o kt�re masz rozbudowa� t� klas�.
	*/

	//Tak si� pobiera nadrz�dy obiekt Game. Ta klasa ma wszystkie potrzebe Ci dane
	Game* game = Game::getInstance();

	//Jak chcesz pobra� gracza to wyci�gasz go z obiektu Game w ten spos�b:
	Player* player = game->GetPlayer();

	//Jak chcesz pobra� kolejne atrybuty gracza robisz tak:
	string playerName = player->getName();
	int playerLvl = player->getLevel();
	int playerAccountBalance = player->getAccountBalance();

	//Jak chcesz pobra� list� pojazd�w robisz tak:
	vector < Vehicle* > vehicleList = player->GetVehicleList();
}

//TODO: Stworzy� funkcje wczytuj�c� stan gry
void FileManager::LoadGame()
{
	/*
		Wczytujesz ten sw�j plik .bin i uzupe�niasz kolejno dane w odpowiednich klasach
	*/

	//Znowu pobierasz obiekt Game (W przypadku braku obiektu getInstance go sobie utworzy)
	Game* game = Game::getInstance();

	//Tworzysz gracza
	game->SetPlayer("Podajesz jako parmetr nick gracza");

	//Pobierasz utworzonego gracza �eby mie� dost�p do jego metod
	Player* player = game->GetPlayer();

	//I jak chcesz mu uzupe�ni� dane to robisz to w ten spos�b:
	player->setLevel(1);
	player->setAccountBalance(100);

	//Jak chcsz doda� pojzd to analogicznie tylko musisz utworzy� obiekt  
	//player->appendVehicle(Vehicle);

}

void FileManager::LoadVehicleList()
{

}

void FileManager::LoadRoadList()
{

}

void FileManager::LoadHouseList()
{

}