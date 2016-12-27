#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Vehicle
{

public:
	Vehicle(string Name, float Speed, float Price, float Capacity, float MaxiPayload, float Combustion, float Fuelcapacity);
	~Vehicle();

	string GetName();
	float GetPrice();

	void SetName(string name);
	void SetSpeed(float speed);
	void SetPrice(float price);
	void SetCapacity(float capacity);
	void SetMaxiPayload(float maxiPayload);
	void SetFuelLevel(float fuelLevel);
	void SetCombustion(float combustion);
	void SetFuelCapacity(float fuelCapacity);

private:
	int id;
	string name;
	float speed;
	float price;
	float capacity;
	float maxiPayload;
	float fuelLevel;
	float combustion;
	float fuelCapacity;

};




