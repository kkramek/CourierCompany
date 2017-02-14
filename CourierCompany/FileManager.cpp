#include "stdafx.h"
#include "FileManager.h"


FileManager::FileManager()
{
}


FileManager::~FileManager()
{
}

//TODO: Stworzyć funkcje zapisującą stan gry do pliku
void FileManager::SaveGame()
{
	
	/*
	TEST PROBA NOWA
		Ogólnie masz za zadanie pobierać wszystkie elementy gry i zapisywać je do pliku .bin
		Strukture pliku musisz sobie tak przemyśleć żebyś potem nie miał problemu ze zrobieniem 
		funkcji odczytu stanu gry. Narazie skup się na tych danych które Ci wyżej wymieniłem. 
		Jak już będzie działać to będę Ci podsyłał kolejne elementy o które masz rozbudować tą klasę.
	*/

	//Tak się pobiera nadrzędy obiekt Game. Ta klasa ma wszystkie potrzebe Ci dane
	Game* game = Game::getInstance();

	//Jak chcesz pobrać gracza to wyciągasz go z obiektu Game w ten sposób:
	Player* player = game->GetPlayer();

	//Jak chcesz pobrać kolejne atrybuty gracza robisz tak:
	string playerName = player->getName();
	int playerLvl = player->getLevel();
	int playerAccountBalance = player->getAccountBalance();

	//Jak chcesz pobrać listę pojazdów robisz tak:
	vector < Vehicle* > vehicleList = player->GetVehicleList();
}

//TODO: Stworzyć funkcje wczytującą stan gry
void FileManager::LoadGame()
{
	/*
		Wczytujesz ten swój plik .bin i uzupełniasz kolejno dane w odpowiednich klasach
	*/

	//Znowu pobierasz obiekt Game (W przypadku braku obiektu getInstance go sobie utworzy)
	Game* game = Game::getInstance();

	//Tworzysz gracza
	game->SetPlayer("Podajesz jako parmetr nick gracza");

	//Pobierasz utworzonego gracza żeby mieć dostęp do jego metod
	Player* player = game->GetPlayer();

	//I jak chcesz mu uzupełnić dane to robisz to w ten sposób:
	player->setLevel(1);
	player->setAccountBalance(100);

	//Jak chcsz dodać pojzd to analogicznie tylko musisz utworzyć obiekt  
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
