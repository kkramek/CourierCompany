// TabGarage.cpp : implementation file
//

#include "stdafx.h"
#include "CourierCompany.h"
#include "CourierCompanyDlg.h"
#include "TabGarage.h"
#include "afxdialogex.h"
#include <sstream>


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

	vehicleListCtrl.InsertColumn(0, _T("Name"), LVCFMT_LEFT, 70);
	vehicleListCtrl.InsertColumn(1, _T("Price"), LVCFMT_RIGHT, 50);
	vehicleListCtrl.InsertColumn(2, _T("Speed"), LVCFMT_RIGHT, 95);
	vehicleListCtrl.InsertColumn(3, _T("Capacity"), LVCFMT_RIGHT, 95);
	vehicleListCtrl.InsertColumn(4, _T("Max Payload"), LVCFMT_RIGHT, 95);
	vehicleListCtrl.InsertColumn(5, _T("Combustion"), LVCFMT_RIGHT, 95);
	vehicleListCtrl.InsertColumn(6, _T("Fuel Capacity"), LVCFMT_RIGHT, 95);

	this->CompleteVehicleList();


	DDX_Control(pDX, IDC_LIST3, playerVehicleList);


	this->CompletePlayerVehicleList();


	DDX_Control(pDX, ID_MAXSPEED, MaxSpeedOfSel);
	DDX_Control(pDX, IDC_MAXCOMBUSTION, MaxCombustionOfSel);
	DDX_Control(pDX, ID_FUELLEVEL, FuelLevelOfSel);
	DDX_Control(pDX, ID_MAXCAPACITY, MaxCapacityOfSel);
	DDX_Control(pDX, ID_MAXPAYLOAD, MaxPayloadOfSel);
	DDX_Control(pDX, ID_MAXFUELLEVEL, MaxFuelLevelOfSel);
	DDX_Control(pDX, IDC_GETFUEL, GetFuel);
	DDX_Control(pDX, IDC_PLUS1SPEED, PlusOneSpeed);
	DDX_Control(pDX, IDC_PLUS1CAPACITY, PlusOneCapacity);
	DDX_Control(pDX, IDC_PLUS1PAYLOAD, PlusOnePayload);
	DDX_Control(pDX, IDC_PLUS1FUEL, PlusOneFuel);
}


BEGIN_MESSAGE_MAP(CTabGarage, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CTabGarage::BuyChangeClick)
	ON_LBN_SELCHANGE(IDC_LIST3, &CTabGarage::OnLbnSelchangeList3)
	ON_BN_CLICKED(IDC_GETFUEL, &CTabGarage::OnBnClickedGetfuel)
	ON_BN_CLICKED(IDC_PLUS1SPEED, &CTabGarage::OnBnClickedPlus1speed)
	ON_BN_CLICKED(IDC_PLUS1CAPACITY, &CTabGarage::OnBnClickedPlus1capacity)
	ON_BN_CLICKED(IDC_PLUS1PAYLOAD, &CTabGarage::OnBnClickedPlus1payload)
	ON_BN_CLICKED(IDC_PLUS1FUEL, &CTabGarage::OnBnClickedPlus1fuel)
END_MESSAGE_MAP()


// CTabGarage message handlers

void CTabGarage::CompleteVehicleList()
{
	vector < Vehicle* > vehicleList;
	vector < Vehicle* >::iterator iter, end;
	string vehicleListRow;

	VehicleLibrary* vehicleLibrary = new VehicleLibrary();
	vehicleList = vehicleLibrary->GetVehicleList();
	reverse(vehicleList.begin(), vehicleList.end());

	for (iter = vehicleList.begin(), end = vehicleList.end(); iter != end; ++iter) {

		int nIndex = vehicleListCtrl.InsertItem(0, Library::StrToCStr((*iter)->GetName()));
		vehicleListCtrl.SetItemText(nIndex, 1, Library::StrToCStr(to_string((*iter)->GetPrice())));
		vehicleListCtrl.SetItemText(nIndex, 2, Library::StrToCStr(to_string((*iter)->GetSpeed())));
		vehicleListCtrl.SetItemText(nIndex, 3, Library::StrToCStr(to_string((*iter)->GetCapacity())));
		vehicleListCtrl.SetItemText(nIndex, 4, Library::StrToCStr(to_string((*iter)->GetMaxiPayload())));
		vehicleListCtrl.SetItemText(nIndex, 5, Library::StrToCStr(to_string((*iter)->GetCombustion())));
		vehicleListCtrl.SetItemText(nIndex, 6, Library::StrToCStr(to_string((*iter)->GetFuelCapacity())));


	}

}


void CTabGarage::CompletePlayerVehicleList()
{
	Game *game = Game::getInstance();
	Player *player = game->GetPlayer();
	vector < Vehicle* > vehiclelist = player->GetVehicleList();

	for (int i = 0; i < vehiclelist.size(); i++)
	{
		this->AppendPlayerVehicleList(vehiclelist[i]->GetName());
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


void CTabGarage::OnLbnSelchangeList3()
{
	UINT uiSelection = playerVehicleList.GetCurSel();
	Game *game;
	Player *player;
	vector < Vehicle* > vehicleList;
	Vehicle* vehicle;

	game = Game::getInstance();
	player = game->GetPlayer();
	vehicleList = player->GetVehicleList();
	vehicle = vehicleList[uiSelection];

	MaxSpeedOfSel.SetWindowText(Library::ConvertStringToCString(to_string(vehicle->GetSpeed())));
	MaxCombustionOfSel.SetWindowText(Library::ConvertStringToCString(to_string(vehicle->GetCombustion())));
	FuelLevelOfSel.SetWindowText(Library::ConvertStringToCString(to_string(vehicle->GetFuelLevel())));
	MaxCapacityOfSel.SetWindowText(Library::ConvertStringToCString(to_string(vehicle->GetCapacity())));
	MaxPayloadOfSel.SetWindowText(Library::ConvertStringToCString(to_string(vehicle->GetMaxiPayload())));
	MaxFuelLevelOfSel.SetWindowText(Library::ConvertStringToCString(to_string(vehicle->GetFuelCapacity())));
}


void CTabGarage::OnBnClickedGetfuel()
{
	float fuelprice = 4.0;
	UINT uiSelection = playerVehicleList.GetCurSel();
	if (uiSelection != -1) 
	{
		Game *game;
		Player *player;
		vector < Vehicle* > vehicleList;
		Vehicle* vehicle;

		game = Game::getInstance();
		player = game->GetPlayer();
		vehicleList = player->GetVehicleList();
		vehicle = vehicleList[uiSelection];

		int fuelcost = int(((vehicle->GetFuelCapacity()) - (vehicle->GetFuelLevel()))*fuelprice);

		if (fuelcost < player->getAccountBalance())
		{
			player->takeFromAccountBalance(fuelcost);
			vehicle->SetFuelLevel(vehicle->GetFuelCapacity());
			FuelLevelOfSel.SetWindowText(Library::ConvertStringToCString(to_string(vehicle->GetFuelLevel())));
		}
	}
}


void CTabGarage::OnBnClickedPlus1speed()
{
	UINT uiSelection = playerVehicleList.GetCurSel();
	if (uiSelection != -1)
	{
		Game *game;
		Player *player;
		vector < Vehicle* > vehicleList;
		Vehicle* vehicle;

		game = Game::getInstance();
		player = game->GetPlayer();
		vehicleList = player->GetVehicleList();
		vehicle = vehicleList[uiSelection];

		if (player->GetUpgradePoints()>0)
		{
			if(!(vehicle->GetSpeed()==0.0))
				player->SetUpgradePoints(player->GetUpgradePoints() - 1);
			vehicle->SetSpeed(vehicle->GetSpeed()*1.1);
			MaxSpeedOfSel.SetWindowText(Library::ConvertStringToCString(to_string(vehicle->GetSpeed())));
		}
		else
		{
			MessageBox(_T("You don't have upgrade points."), _T("Error"),
				MB_ICONERROR | MB_OK);
		}
	}
}


void CTabGarage::OnBnClickedPlus1capacity()
{
	UINT uiSelection = playerVehicleList.GetCurSel();
	if (uiSelection != -1)
	{
		Game *game;
		Player *player;
		vector < Vehicle* > vehicleList;
		Vehicle* vehicle;

		game = Game::getInstance();
		player = game->GetPlayer();
		vehicleList = player->GetVehicleList();
		vehicle = vehicleList[uiSelection];

		if (player->GetUpgradePoints()>0)
		{
			if (!(vehicle->GetCapacity() == 0.0))
				player->SetUpgradePoints(player->GetUpgradePoints() - 1);
			vehicle->SetCapacity(vehicle->GetCapacity()*1.1);
			MaxCapacityOfSel.SetWindowText(Library::ConvertStringToCString(to_string(vehicle->GetCapacity())));
		}
		else
		{
			MessageBox(_T("You don't have upgrade points."), _T("Error"),
				MB_ICONERROR | MB_OK);
		}
	}
}


void CTabGarage::OnBnClickedPlus1payload()
{
	UINT uiSelection = playerVehicleList.GetCurSel();
	if (uiSelection != -1)
	{
		Game *game;
		Player *player;
		vector < Vehicle* > vehicleList;
		Vehicle* vehicle;

		game = Game::getInstance();
		player = game->GetPlayer();
		vehicleList = player->GetVehicleList();
		vehicle = vehicleList[uiSelection];

		if (player->GetUpgradePoints()>0)
		{
			if (!(vehicle->GetMaxiPayload() == 0.0))
				player->SetUpgradePoints(player->GetUpgradePoints() - 1);
			vehicle->SetMaxiPayload(vehicle->GetMaxiPayload()*1.1);
			MaxPayloadOfSel.SetWindowText(Library::ConvertStringToCString(to_string(vehicle->GetMaxiPayload())));
		}
		else
		{
			MessageBox(_T("You don't have upgrade points."), _T("Error"),
				MB_ICONERROR | MB_OK);
		}
	}
}


void CTabGarage::OnBnClickedPlus1fuel()
{
	UINT uiSelection = playerVehicleList.GetCurSel();
	if (uiSelection != -1)
	{
		Game *game;
		Player *player;
		vector < Vehicle* > vehicleList;
		Vehicle* vehicle;

		game = Game::getInstance();
		player = game->GetPlayer();
		vehicleList = player->GetVehicleList();
		vehicle = vehicleList[uiSelection];

		if (player->GetUpgradePoints()>0)
		{
			if (!(vehicle->GetFuelCapacity() == 0.0))
				player->SetUpgradePoints(player->GetUpgradePoints() - 1);
			vehicle->SetFuelCapacity(vehicle->GetFuelCapacity()*1.1);
			MaxFuelLevelOfSel.SetWindowText(Library::ConvertStringToCString(to_string(vehicle->GetFuelCapacity())));
		}
		else
		{
			MessageBox(_T("You don't have upgrade points."), _T("Error"),
				MB_ICONERROR | MB_OK);
		}
	}
}
