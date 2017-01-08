// TabMap.cpp : implementation file
//

#include "stdafx.h"
#include "CourierCompany.h"
#include "TabMap.h"
#include "afxdialogex.h"


// CTabMap dialog

IMPLEMENT_DYNAMIC(CTabMap, CDialogEx)

CTabMap::CTabMap(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTabMap::IDD, pParent)
{

}

CTabMap::~CTabMap()
{
}

void CTabMap::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTabMap, CDialogEx)
END_MESSAGE_MAP()


// CTabMap message handlers
