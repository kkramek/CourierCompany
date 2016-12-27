#pragma once
#include <vector>
#include "Package.h"

using namespace std;

class PackageList
{
public:
	PackageList();
	~PackageList();

	vector < Package* > packageList;

	void AppendPackage(Package package);
};

