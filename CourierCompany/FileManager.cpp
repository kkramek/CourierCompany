#include "stdafx.h"
#include "FileManager.h"


FileManager::FileManager()
{
}


FileManager::~FileManager()
{
}

//TODO: Stworzyæ funkcje zapisuj¹c¹ stan gry do pliku
void FileManager::SaveGame()
{
	/*
		Ogólnie masz za zadanie pobieraæ wszystkie elementy gry i zapisywaæ je do pliku .bin
		Strukture pliku musisz sobie tak przemyœleæ ¿ebyœ potem nie mia³ problemu ze zrobieniem 
		funkcji odczytu stanu gry. Narazie skup siê na tych danych które Ci wy¿ej wymieni³em. 
		Jak ju¿ bêdzie dzia³aæ to bêdê Ci podsy³a³ kolejne elementy o które masz rozbudowaæ t¹ klasê.
	*/

	//Tak siê pobiera nadrzêdy obiekt Game. Ta klasa ma wszystkie potrzebe Ci dane
	Game* game = Game::getInstance();

	//Jak chcesz pobraæ gracza to wyci¹gasz go z obiektu Game w ten sposób:
	Player* player = game->GetPlayer();

	//Jak chcesz pobraæ kolejne atrybuty gracza robisz tak:
	string playerName = player->getName();
	int playerLvl = player->getLevel();
	int playerAccountBalance = player->getAccountBalance();

	//Jak chcesz pobraæ listê pojazdów robisz tak:
	vector < Vehicle* > vehicleList = player->GetVehicleList();
}

//TODO: Stworzyæ funkcje wczytuj¹c¹ stan gry
void FileManager::LoadGame()
{
	/*
		Wczytujesz ten swój plik .bin i uzupe³niasz kolejno dane w odpowiednich klasach
	*/

	//Znowu pobierasz obiekt Game (W przypadku braku obiektu getInstance go sobie utworzy)
	Game* game = Game::getInstance();

	//Tworzysz gracza
	game->SetPlayer("Podajesz jako parmetr nick gracza");

	//Pobierasz utworzonego gracza ¿eby mieæ dostêp do jego metod
	Player* player = game->GetPlayer();

	//I jak chcesz mu uzupe³niæ dane to robisz to w ten sposób:
	player->setLevel(1);
	player->setAccountBalance(100);

	//Jak chcsz dodaæ pojzd to analogicznie tylko musisz utworzyæ obiekt  
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