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
	int getAccountBalance();
	float GetMAXICapacityofallcars();
	float GetMaxiPayloadofallcars();

	void setName(string name);
	void setLevel(int level);
	void setAccountBalance(int accountBalance);

	void addToAccountBalance(int money);
	void takeFromAccountBalance(int money);

	void appendVehicle(Vehicle *vehicle);
	void clearVehicleList();
	vector < Vehicle* > GetVehicleList();

private:
	string name;
	string courierType;
	int level;
	int accountBalance;
	vector < Vehicle* > vehicleList;


};

