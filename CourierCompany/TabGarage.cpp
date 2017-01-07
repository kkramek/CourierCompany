// TabGarage.cpp : implementation file
//

#include "stdafx.h"
#include "CourierCompany.h"
#include "TabGarage.h"
#include "afxdialogex.h"


// CTabGarage dialog

IMPLEMENT_DYNAMIC(CTabGarage, CDialogEx)

CTabGarage::CTabGarage(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTabGarage::IDD, pParent)
{
}

CTabGarage::~CTabGarage()
{
}

void CTabGarage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, vehicleListCtrl);

	vehicleListCtrl.InsertColumn(0, _T("Car Name"), LVCFMT_LEFT, 105);
	vehicleListCtrl.InsertColumn(1, _T("Price"), LVCFMT_RIGHT, 95);

	this->CompleteVehicleList();

	DDX_Control(pDX, IDC_LIST3, playerVehicleList);
}


BEGIN_MESSAGE_MAP(CTabGarage, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CTabGarage::BuyChangeClick)
END_MESSAGE_MAP()


// CTabGarage message handlers

void CTabGarage::CompleteVehicleList()
{
	vector < Vehicle* > vehicleList;
	vector < Vehicle* >::iterator iter, end;
	string vehicleListRow;

	VehicleLibrary* vehicleLibrary = new VehicleLibrary();
	vehicleList = vehicleLibrary->GetVehicleList();

	for (iter = vehicleList.begin(), end = vehicleList.end(); iter != end; ++iter) {

		int nIndex = vehicleListCtrl.InsertItem(0, Library::ConvertStringToCString((*iter)->GetName()));
		vehicleListCtrl.SetItemText(nIndex, 1, Library::ConvertStringToCString(to_string((*iter)->GetPrice())));

	}

}


void CTabGarage::BuyChangeClick()
{
	Game *game;
	Player *player;
	Vehicle* vehicle;
	vector < Vehicle* > vehicleList;
	VehicleLibrary* vehicleLibrary = new VehicleLibrary();
	vehicleList = vehicleLibrary->GetVehicleList();

	int nSelectedItem = vehicleListCtrl.GetNextItem(-1, LVNI_SELECTED);

	if (nSelectedItem != -1) {

		vehicle = vehicleList[nSelectedItem];

		game = Game::getInstance();
		player = game->GetPlayer();

		if (vehicle->GetPrice() < player->getAccountBalance()) {
			
			player->takeFromAccountBalance(vehicle->GetPrice());
			player->appendVehicle(vehicle);
			this->AppendPlayerVehicleList(vehicle->GetName());
		
		}
		else {
			MessageBox(_T("You don't have enough money."), _T("Error"),
				MB_ICONERROR | MB_OK);
		}

		
	}
}

void CTabGarage::AppendPlayerVehicleList(string vehicleName)
{
	playerVehicleList.AddString(Library::ConvertStringToCString(vehicleName));
}
