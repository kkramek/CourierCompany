#include "stdafx.h"
#include "PackageList.h"


PackageList::PackageList()
{
}


PackageList::~PackageList()
{
}

void PackageList::AppendPackage(Package *package)
{
	this->packageList.push_back(package);
}

void PackageList::GetNewPackages(int packagesNumber)
{
	for (int i = 0; i < packagesNumber; i++)
		this->AppendPackage(new Package(10));
}