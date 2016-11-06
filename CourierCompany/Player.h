#pragma once
#pragma once
#include <string>
#include <iostream>

using namespace std;

class Player
{

public:
	Player(string name);
	~Player();
	void addToAccountBalance(float money);
	void takeFromAccountBalance(float money);
	string getName();
	int getLevel();
	float getAccountBalance();

private:
	string name;
	int level;
	float accountBalance;
	string courierType;

protected:
	void setName(string name);
	void setLevel(int level);
	void setAccountBalance(float accountBalance);

};

