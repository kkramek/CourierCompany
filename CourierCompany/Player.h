#pragma once
#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "stdafx.h"
#include "Vehicle.h"

using namespace std;

class Player
{

public:
	Player(string name);
	~Player();

	string getName();
	int getLevel();
	float getAccountBalance();

	void setName(string name);
	void setLevel(int level);
	void setAccountBalance(float accountBalance);

	void addToAccountBalance(float money);
	void takeFromAccountBalance(float money);

	void appendVehicle(Vehicle *vehicle);
	vector < Vehicle* > GetVehicleList();

private:
	string name;
	string courierType;
	int level;
	float accountBalance;
	vector < Vehicle* > vehicleList;


};

