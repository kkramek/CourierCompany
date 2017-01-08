#include "stdafx.h"
#include "Vehicle.h"
#include <string>


Vehicle::Vehicle(string name, float speed, int price, float capacity, float maxiPayload, float combustion, float fuelcapacity)
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

int Vehicle::GetPrice()
{
	return this->price;
}

float Vehicle::GetSpeed()
{
	return this->speed;
}

float Vehicle::GetCapacity()
{
	return this->capacity;
}

float Vehicle::GetMaxiPayload()
{
	return this->maxiPayload;
}

float Vehicle::GetFuelCapacity()
{
	return this->fuelCapacity;
}

float Vehicle::GetFuelLevel()
{
	return this->fuelLevel;
}

float Vehicle::GetCombustion()
{
	return this->combustion;
}

void Vehicle::SetName(string name)
{
	this->name = name;
}

void Vehicle::SetSpeed(float speed)
{
	this->speed = speed;
}

void Vehicle::SetPrice(int price)
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
