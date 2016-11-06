#include "stdafx.h"
#include "Library.h"
#include <string>
#include <iostream>

using namespace std;

Library::Library()
{
}


Library::~Library()
{
}

string Library::ConvertCStringToString(CString cString)
{
	CT2CA pszConvertedAnsiString(cString);
	string strStd(pszConvertedAnsiString);

	return strStd;
}

CString Library::ConvertStringToCString(string string)
{
	CString cstring(string.c_str());

	return cstring;
}
