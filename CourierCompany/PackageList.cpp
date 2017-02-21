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
	Package *package;
	for (int i = 0; i < packagesNumber; i++)
	{
		package = new Package(10);
		this->AppendPackage(package);
	}
		
}