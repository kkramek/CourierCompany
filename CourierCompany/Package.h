#pragma once
#include <string>
#include <iostream>

using namespace std;

class Package
{

public:
	Package(int type);
	~Package();

	//Setters
	void setTypeId(int typeId);
	void setSize(float size);
	void setWeight(float weight);
	void setPrize(float prize);
	void setDeliveryDate(int deliveryDate);
	void setDeliveryAdress(string deliveryAdress);
	void setDelivered(bool delivered);

	//Getters
	float getSize();
	float getWeight();
	float getPrize();
	int getDeliveryDate();
	string getDeliveryAdress();
	bool getDelivered();

	//Constants values of package type
	static const int TYPE_MAIL = 1;
	static const int TYPE_SMALL_PACK = 2;
	static const int TYPE_MEDIUM_PACK = 3;
	static const int TYPE_LARGE_PACK = 4;
	static const int TYPE_RANDOM = 5;


private:
	int typeId;

	float size;
	float weight;
	float prize;
	int deliveryDate;
	string deliveryAdress;
	bool delivered;

	void preparePackage(int typeId, float size, float weight, float prize);
	void prepareRandomPackage();
};
