#include "stdafx.h"
#include "Package.h"
#include <string>
#include <iostream>

using namespace std;

Package::Package(int type)
{
	switch (type)
	{
		case TYPE_MAIL:
			this->preparePackage(TYPE_MAIL, 5, 1, 10);
			break;
		case TYPE_SMALL_PACK:
			this->preparePackage(TYPE_SMALL_PACK, 10, 5, 20);
			break;
		case TYPE_MEDIUM_PACK:
			this->preparePackage(TYPE_MEDIUM_PACK, 20, 10, 40);
			break;
		case TYPE_LARGE_PACK:
			this->preparePackage(TYPE_LARGE_PACK, 40, 20, 80);
			break;
		default:
			this->prepareRandomPackage();
			break;

	}
}

Package::~Package()
{
}

void Package::preparePackage(int typeId, float size, float weight, float prize)
{
	this->setTypeId(typeId);
	//this->setHouseId(houseId);
	this->setPrize(prize);
	this->setSize(size);
	this->setWeight(weight);
}

void Package::prepareRandomPackage()
{

}

void Package::setTypeId(int typeId)
{
	this->typeId = typeId;
}

void Package::setSize(float size)
{
	this->size = size;
}

void Package::setWeight(float weight)
{
	this->weight = weight;
}

void Package::setPrize(float prize)
{
	this->prize = prize;
}

void Package::setDeliveryDate(int deliveryDate)
{
	this->deliveryDate = deliveryDate;
}

void Package::setHouseId(int houseId)
{
	this->houseId = houseId;
}

void Package::setDelivered(bool delivered)
{
	this->delivered = delivered;
}
