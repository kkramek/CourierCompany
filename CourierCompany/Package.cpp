#include "stdafx.h"
#include "Package.h"
#include "Game.h"
#include "MapLibrary.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Konstruktor bêdzie ju¿ sam w sobie losowa³ paczkê
Package::Package(int type = 10)
{
	switch (type)
	{
		case TYPE_MAIL:
			this->preparePackage(TYPE_MAIL, 5, 1, 10, 0);
			break;
		case TYPE_SMALL_PACK:
			this->preparePackage(TYPE_SMALL_PACK, 10, 5, 20, 0);
			break;
		case TYPE_MEDIUM_PACK:
			this->preparePackage(TYPE_MEDIUM_PACK, 20, 10, 40, 0);
			break;
		case TYPE_LARGE_PACK:
			this->preparePackage(TYPE_LARGE_PACK, 40, 20, 80, 0);
			break;
		default:
			this->prepareRandomPackage();
			break;

	}
}

Package::~Package()
{
}

void Package::preparePackage(int typeId, float size, float weight, int prize, int houseId)
{
	this->setTypeId(typeId);
	this->setHouseId(houseId);
	this->setPrize(prize);
	this->setSize(size);
	this->setWeight(weight);
}

void Package::prepareRandomPackage()
{
	srand(time(NULL));

	Game *game = Game::getInstance();;
	Player *player = game->GetPlayer();
	MapLibrary *maplibrary = MapLibrary::GetInstance();

	float maxsize = player->GetMAXICapacityofallcars();
	float maxweight = player->GetMaxiPayloadofallcars();
	float maxcapacity = maxsize;
	if (maxsize > maxweight)
		maxcapacity = maxweight;
	int packagefactor; // depends on player's vehile_library
	if (maxcapacity <= 10.0)
		packagefactor = 1;
	else
	{
		if (maxcapacity <= 200.0)
			packagefactor = 2;
		else
		{
			if (maxcapacity <= 1500.0)
				packagefactor = 3;
			else
				packagefactor = 4;
		}
	}
	int typeId = (rand() % packagefactor + 1);
	float size;
	float weight;
	int prize;
	int houseId = maplibrary->GetRandomHouse();
	float luckfactor = float(rand() % int(100) + 60) / 100;  

	switch (typeId)
	{
	case TYPE_MAIL:
		size = float(rand() % int(991) + 10) / 100; // from 0.10 to 10.00
		weight = float(rand() % int(100) + 1) / 100; // from 0.01 to 1.00
		break;
	case TYPE_SMALL_PACK:
		size = float(rand() % int(4501) + 500) / 100; // from 5.00 to 50.00
		weight = float(rand() % int(500) + 1) / 100; // from 0.01 to 5.00
		break;
	case TYPE_MEDIUM_PACK:
		size = float(rand() % int(26001) + 4000) / 100; // from 40.00 to 300.00
		weight = float(rand() % int(3000) + 1) / 100; // from 0.01 to 30.00
		break;
	case TYPE_LARGE_PACK:
		size = float(rand() % int(130001) + 20000) / 100; // from 200.00 to 1500.00
		weight = float(rand() % int(50000) + 1) / 100; // from 0.01 to 500.00
		break;
	}
	prize = int((size + weight) * luckfactor); // trzeba to poprawiæ, bo za ma³e paczki nagroda bêdzie równa 0


	this->preparePackage(typeId, size, weight, prize, houseId);
}

void Package::setTypeId(int typeId)
{
	this->typeId = typeId;
}

void Package::setSize(float size)
{
	this->size = size;
}

void Package::setWeight(float weight)
{
	this->weight = weight;
}

void Package::setPrize(int prize)
{
	this->prize = prize;
}

void Package::setDeliveryDate(int deliveryDate)
{
	this->deliveryDate = deliveryDate;
}

void Package::setHouseId(int houseId)
{
	this->houseId = houseId;
}

void Package::setDelivered(bool delivered)
{
	this->delivered = delivered;
}

float Package::getSize()
{
	return size;
}
float Package::getWeight()
{
	return weight;
}
int Package::getPrize()
{
	return prize;
}
int Package::getDeliveryDate()
{
	return deliveryDate;
}
int Package::getHouseId()
{
	return houseId;
}
bool Package::getDelivered()
{
	return delivered;
}
string Package::getType()
{
	if (typeId == 1)
		return string("Mail");
	else
	{
		if (typeId == 2)
			return string("Small Packet");
		else
		{
			if (typeId == 3)
				return string("Medium Packet");
			else
			{
				if (typeId == 4)
					return string("Large Packet");
			}
		}
	}
}