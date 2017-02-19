#pragma once
#include <string>
#include <iostream>

using namespace std;

class Library
{
public:
	Library();
	~Library();
	static string ConvertCStringToString(CString cString);
	static CString ConvertStringToCString(string cString);
	static string CStrToStr(CString cString);
	static CString StrToCStr(string cString);

};

