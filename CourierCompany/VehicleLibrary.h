#pragma once
#include <vector>
#include "Vehicle.h"

using namespace std;

class VehicleLibrary
{
public:
	VehicleLibrary();
	~VehicleLibrary();
	vector < Vehicle* > GetVehicleList();

	Vehicle* createHuman();
	Vehicle* createBike();
	Vehicle* createHatchback();
	Vehicle* createSedan();
	Vehicle* createWagon();
	Vehicle* createVan();
	Vehicle* createMiniTruck();
};

