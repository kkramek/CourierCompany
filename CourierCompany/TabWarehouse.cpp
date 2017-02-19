// TabWarehouse.cpp : implementation file
//

#include "stdafx.h"
#include "CourierCompany.h"
#include "TabWarehouse.h"
#include "afxdialogex.h"
#include <cstdlib>
#include <ctime>
#include "PackageList.h"
#include "Library.h"


// CTabWarehouse dialog

IMPLEMENT_DYNAMIC(CTabWarehouse, CDialogEx)

CTabWarehouse::CTabWarehouse(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTabWarehouse::IDD, pParent)
	, Charge(0)
{

}

CTabWarehouse::~CTabWarehouse()
{
}

void CTabWarehouse::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PACKAGELISTTABLE, PackageListTable);

	PackageListTable.InsertColumn(0, _T("Package type"), LVCFMT_LEFT, 120);
	PackageListTable.InsertColumn(1, _T("Size"), LVCFMT_RIGHT, 80);
	PackageListTable.InsertColumn(2, _T("Prize"), LVCFMT_RIGHT, 80);
	PackageListTable.InsertColumn(3, _T("Delivery addres"), LVCFMT_RIGHT, 150);

	DDX_Control(pDX, IDC_VEHCHARLIST, VehCharList);

	VehCharList.InsertColumn(0, _T("Vehicle name"), LVCFMT_LEFT, 120);
	VehCharList.InsertColumn(1, _T("Capacity"), LVCFMT_RIGHT, 80);
	VehCharList.InsertColumn(2, _T("Payload"), LVCFMT_RIGHT, 80);
	VehCharList.InsertColumn(3, _T("Delivery addres"), LVCFMT_RIGHT, 150);
}


BEGIN_MESSAGE_MAP(CTabWarehouse, CDialogEx)
	ON_BN_CLICKED(IDC_CHARGE, &CTabWarehouse::OnBnClickedCharge)
END_MESSAGE_MAP()


// CTabWarehouse message handlers


void CTabWarehouse::OnBnClickedCharge()
{
	srand(time(NULL));

	int packagesamount = rand() % 7 + 8;  // from 8 to 14
	PackageList *packagelist = new PackageList;
	packagelist->GetNewPackages(packagesamount);

	for (unsigned int i = 0; i < packagelist->packageList.size(); i++)
	{
		int nIndex = PackageListTable.InsertItem(0, Library::StrToCStr(packagelist->packageList[i]->getType()));
		PackageListTable.SetItemText(nIndex, 1, Library::StrToCStr(to_string(packagelist->packageList[i]->getSize())));
		PackageListTable.SetItemText(nIndex, 2, Library::StrToCStr(to_string(packagelist->packageList[i]->getPrize())));
		PackageListTable.SetItemText(nIndex, 3, Library::StrToCStr(to_string(packagelist->packageList[i]->getHouseId())));
	}
}

