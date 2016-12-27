#include "stdafx.h"
#include "VehicleLibrary.h"
#include "Vehicle.h"


VehicleLibrary::VehicleLibrary()
{
}


VehicleLibrary::~VehicleLibrary()
{
}

vector < Vehicle* > VehicleLibrary::GetVehicleList()
{
	vector < Vehicle* > vehicleList;

	vehicleList.push_back(this->createHuman());
	vehicleList.push_back(this->createBike());
	vehicleList.push_back(this->createHatchback());
	vehicleList.push_back(this->createSedan());
	vehicleList.push_back(this->createWagon());
	vehicleList.push_back(this->createVan());
	vehicleList.push_back(this->createMiniTruck());

	return vehicleList;
}

Vehicle* VehicleLibrary::createHuman()
{
	string name = "Human";
	float speed = 5;
	float price = 0;
	float capacity = 10;
	float maxiPayload = 10;
	float combustion = 0;
	float fuelCapacity = 0;

	Vehicle* human = new Vehicle(name, speed, price, capacity, maxiPayload, combustion, fuelCapacity);

	return human;
}

Vehicle* VehicleLibrary::createBike()
{
	string name = "Bike";
	float speed = 10;
	float price = 500;
	float capacity = 20;
	float maxiPayload = 20;
	float combustion = 0;
	float fuelCapacity = 0;

	Vehicle* bike = new Vehicle(name, speed, price, capacity, maxiPayload, combustion, fuelCapacity);

	return bike;
}

Vehicle* VehicleLibrary::createHatchback()
{
	string name = "Hatchback";
	float speed = 90;
	float price = 3000;
	float capacity = 100;
	float maxiPayload = 100;
	float combustion = 50;
	float fuelCapacity = 40;

	Vehicle* hatchback = new Vehicle(name, speed, price, capacity, maxiPayload, combustion, fuelCapacity);

	return hatchback;
}

Vehicle* VehicleLibrary::createSedan()
{
	string name = "Sedan";
	float speed = 80;
	float price = 5000;
	float capacity = 200;
	float maxiPayload = 200;
	float combustion = 6;
	float fuelCapacity = 50;

	Vehicle* sedan = new Vehicle(name, speed, price, capacity, maxiPayload, combustion, fuelCapacity);

	return sedan;
}

Vehicle* VehicleLibrary::createWagon()
{
	string name = "Wagon";
	float speed = 70;
	float price = 10000;
	float capacity = 500;
	float maxiPayload = 500;
	float combustion = 7;
	float fuelCapacity = 70;

	Vehicle* sedan = new Vehicle(name, speed, price, capacity, maxiPayload, combustion, fuelCapacity);

	return sedan;
}

Vehicle* VehicleLibrary::createVan()
{
	string name = "Van";
	float speed = 60;
	float price = 20000;
	float capacity = 1500;
	float maxiPayload = 1500;
	float combustion = 10;
	float fuelCapacity = 70;

	Vehicle* van = new Vehicle(name, speed, price, capacity, maxiPayload, combustion, fuelCapacity);

	return van;
}

Vehicle* VehicleLibrary::createMiniTruck()
{
	string name = "MiniTruck";
	float speed = 50;
	float price = 50000;
	float capacity = 3000;
	float maxiPayload = 3000;
	float combustion = 12;
	float fuelCapacity = 70;

	Vehicle* van = new Vehicle(name, speed, price, capacity, maxiPayload, combustion, fuelCapacity);

	return van;
}