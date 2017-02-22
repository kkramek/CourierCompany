#pragma once
#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "stdafx.h"
#include "Vehicle.h"
#include "PackageList.h"

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
	int GetDeliveredPackages();
	int GetUpgradePoints();

	void setName(string name);
	void setLevel(int level);
	void SetUpgradePoints(int upgradepoints);
	void setAccountBalance(int accountBalance);
	void SetDeliveredPackages(int deliveredpackages);

	void addToAccountBalance(int money);
	void takeFromAccountBalance(int money);

	void appendVehicle(Vehicle *vehicle);
	void clearVehicleList();
	vector < Vehicle* > GetVehicleList();
	PackageList packagelist;

private:
	string name;
	string courierType;
	int level;
	int accountBalance;
	int deliveredPackages;
	vector < Vehicle* > vehicleList;
	int UpgradePoints;


};

