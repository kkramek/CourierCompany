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

void Player::setAccountBalance(float accountBalance)
{
	this->accountBalance = accountBalance;
}

void Player::addToAccountBalance(float money)
{
	this->accountBalance = this->accountBalance + money;
}

void Player::takeFromAccountBalance(float money)
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

float Player::getAccountBalance()
{
	return this->accountBalance;
}