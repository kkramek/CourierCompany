#include "stdafx.h"
#include "FileManager.h"
#include "afxdialogex.h"
#include "CourierCompany.h"
#include "StartWindowDlg.h"
#include "Library.h"
#include <fstream>
#include <iostream>


FileManager::FileManager()
{
}


FileManager::~FileManager()
{
}

//TODO: Stworzyæ funkcje zapisuj¹c¹ stan gry do pliku
bool FileManager::SaveGame()
{
	CFileDialog FileDialog(FALSE, _T("save"), _T("*.save"));

	if (FileDialog.DoModal() == IDOK)
	{
		ofstream savefile;
		savefile.open(Library::ConvertCStringToString(FileDialog.GetPathName()), std::ios::binary);
		if (savefile.is_open())
		{
			string playerName;
			int playernamelenght;
			int playerLvl;
			int playerAccountBalance;
			vector < Vehicle* > vehicleList;

			Game* game;
			Player* player;
			game = Game::getInstance();
			player = game->GetPlayer();

			playerName = player->getName();
			playerLvl = player->getLevel();
			playerAccountBalance = player->getAccountBalance();
			vehicleList = player->GetVehicleList();
			playernamelenght = playerName.length();


			savefile << playernamelenght;
			for (int i = 0; i < playernamelenght; i++)
				savefile << playerName[i];
			savefile << playerLvl << '$' << playerAccountBalance << '$' << vehicleList.size() << '$';

			for (unsigned int i = 0; i < vehicleList.size(); i++)
			{
				playerName = vehicleList[i]->GetName();
				playernamelenght = vehicleList[i]->GetName().size();
				savefile << playernamelenght;
				for (int j = 0; j < playernamelenght; j++)
					savefile << playerName[j];
				savefile << vehicleList[i]->GetPrice() << '$'
					<< vehicleList[i]->GetSpeed() << '$'
					<< vehicleList[i]->GetCapacity() << '$'
					<< vehicleList[i]->GetMaxiPayload() << '$'
					<< vehicleList[i]->GetFuelCapacity() << '$'
					<< vehicleList[i]->GetFuelLevel() << '$'
					<< vehicleList[i]->GetCombustion() << '$';
			}

			savefile.close();
			return TRUE;
		}
	}
	return FALSE;
}

//TODO: Stworzyæ funkcje wczytuj¹c¹ stan gry
bool FileManager::LoadGame()
{
	CFileDialog FileDialog(TRUE, _T("save"), _T("*.save"));

	if (FileDialog.DoModal() == IDOK)
	{
		CString PathName = FileDialog.GetPathName();
		ifstream loadfile;
		loadfile.open(Library::ConvertCStringToString(PathName), ios::binary);
		if (loadfile.is_open())
		{
			string name;
			int namelenght;
			int money;
			int lvl;
			char temp;
			char dollar;
			loadfile >> namelenght;
			for (int i = 0; i < namelenght; i++)
			{
				loadfile >> temp;
				name += temp;
			}
			loadfile >> lvl >> dollar >> money >> dollar;

			Game* game = Game::getInstance();

			game->SetPlayer(name);

			Player* player = game->GetPlayer();


			player->setLevel(lvl);
			player->setAccountBalance(money);

			string vehiclename;
			int vehiclenamelenght;
			float vehiclespeed;
			int vehicleprice;
			float vehiclecapacity;
			float vehiclemaxiPayload;
			float vehiclefuelLevel;
			float vehiclecombustion;
			float vehiclefuelCapacity;

			int vehicleamount;
			loadfile >> vehicleamount >> dollar;

			player->clearVehicleList();
			Vehicle *vehicle;

			for (int j = 0; j < vehicleamount; j++)
			{
				vehiclename.erase();
				loadfile >> vehiclenamelenght;
				for (int i = 0; i < vehiclenamelenght; i++)
				{
					loadfile >> temp;
					vehiclename += temp;
				}
				loadfile >> vehicleprice >> dollar
					>> vehiclespeed >> dollar
					>> vehiclecapacity >> dollar
					>> vehiclemaxiPayload >> dollar
					>> vehiclefuelCapacity >> dollar
					>> vehiclefuelLevel >> dollar
					>> vehiclecombustion >> dollar;

				
				vehicle = new Vehicle(vehiclename, vehiclespeed, vehicleprice, vehiclecapacity, vehiclemaxiPayload, vehiclecombustion, vehiclefuelCapacity);
				player->appendVehicle(vehicle);
				/*	MessageBox(Library::ConvertStringToCString(vehiclename), _T("TEST"),
				MB_ICONERROR | MB_OK);*/

			}
			loadfile.close();

			return TRUE;
		}
	}
	return FALSE;
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