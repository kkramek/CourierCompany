#include "stdafx.h"
#include "Player.h"
#include <string>


Player::Player(string name)
{
	this->setName(name);
	this->setLevel(1);
	this->setAccountBalance(1000000);
}

Player::~Player()
{
}

void Player::appendVehicle(Vehicle *vehicle)
{
	this->vehicleList.push_back(vehicle);
}

vector < Vehicle* > Player::GetVehicleList()
{
	return this->vehicleList;
}

void Player::setName(string name) 
{
	this->name = name;
}

void Player::setLevel(int level) 
{
	this->level = level;
}

void Player::setAccountBalance(int accountBalance)
{
	this->accountBalance = accountBalance;
}

void Player::addToAccountBalance(int money)
{
	this->accountBalance = this->accountBalance + money;
}

void Player::takeFromAccountBalance(int money)
{
	this->accountBalance = this->accountBalance - money;
}

string Player::getName()
{
	return this->name;
}

int Player::getLevel()
{
	return this->level;
}

int Player::getAccountBalance()
{
	return this->accountBalance;
}

float Player::GetMAXICapacityofallcars()
{
	if (vehicleList.size() > 0)
	{
		float tempMAXI = vehicleList[0]->GetCapacity();
		for (unsigned int i = 0; i < vehicleList.size() - 1; i++)
		{
			if (vehicleList[i]->GetCapacity() < vehicleList[i + 1]->GetCapacity())
				tempMAXI = vehicleList[i + 1]->GetCapacity();
		}
		return tempMAXI;
	}
	else
		return 0.0;
}

float Player::GetMaxiPayloadofallcars()
{
	if (vehicleList.size() > 0)
	{
		float tempMAXI = vehicleList[0]->GetMaxiPayload();
		for (unsigned int i = 0; i < vehicleList.size() - 1; i++)
		{
			if (vehicleList[i]->GetMaxiPayload() < vehicleList[i + 1]->GetMaxiPayload())
				tempMAXI = vehicleList[i + 1]->GetMaxiPayload();
		}
		return tempMAXI;
	}
	else
		return 0.0;
}