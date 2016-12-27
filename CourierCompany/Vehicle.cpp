#include "stdafx.h"
#include "Vehicle.h"
#include <string>


Vehicle::Vehicle(string name, float speed, float price, float capacity, float maxiPayload, float combustion, float fuelcapacity)
{
	this->SetName(name);
	this->SetSpeed(speed);
	this->SetPrice(price);
	this->SetCapacity(capacity);
	this->SetMaxiPayload(maxiPayload);
	this->SetFuelLevel(fuelLevel);
	this->SetCombustion(combustion);
	this->SetFuelCapacity(fuelCapacity);
}


Vehicle::~Vehicle()
{
}

string Vehicle::GetName()
{
	return this->name;
}

float Vehicle::GetPrice()
{
	return this->price;
}


void Vehicle::SetName(string name)
{
	this->name = name;
}

void Vehicle::SetSpeed(float speed)
{
	this->speed = speed;
}

void Vehicle::SetPrice(float price)
{
	this->price = price;
}

void Vehicle::SetCapacity(float capacity)
{
	this->capacity = capacity;
}

void Vehicle::SetMaxiPayload(float maxiPayload)
{
	this->maxiPayload = maxiPayload;
}

void Vehicle::SetFuelLevel(float fuelLevel)
{
	this->fuelLevel = fuelLevel;
}

void Vehicle::SetCombustion(float combustion)
{
	this->combustion = combustion;
}

void Vehicle::SetFuelCapacity(float fuelCapacity)
{
	this->fuelCapacity = fuelCapacity;
}
