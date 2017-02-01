#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "VehicleLibrary.h"
#include "Vehicle.h"
#include "Library.h"
#include "Game.h"


// CTabGarage dialog

class CTabGarage : public CDialogEx
{
	DECLARE_DYNAMIC(CTabGarage)

public:
	CTabGarage(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTabGarage();

// Dialog Data
	enum { IDD = IDD_TAB_GARAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	void CompleteVehicleList();
	void AppendPlayerVehicleList(string vehicleName);
	CListCtrl vehicleListCtrl;
	afx_msg void BuyChangeClick();
	CListBox playerVehicleList;

	afx_msg void OnLbnSelchangeList3();
	CStatic MaxSpeedOfSel;
	CStatic MaxCombustionOfSel;
	CStatic FuelLevelOfSel;
	CStatic MaxCapacityOfSel;
	CStatic MaxPayloadOfSel;
	CStatic MaxFuelLevelOfSel;
};
