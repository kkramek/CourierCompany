#pragma once
#include "afxcmn.h"


// CTabWarehouse dialog

class CTabWarehouse : public CDialogEx
{
	DECLARE_DYNAMIC(CTabWarehouse)

public:
	CTabWarehouse(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTabWarehouse();
	void CompletePlayerVehicleList();
// Dialog Data
	enum { IDD = IDD_TAB_WAREHOUSE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int Charge;
	afx_msg void OnBnClickedCharge();
	CListCtrl PackageListTable;
	CListCtrl VehicleChsrgeList;
	CListCtrl VehicleChargeList;
	afx_msg void OnLvnItemchangedVehiclechargelist(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl VehCharList;
	afx_msg void OnBnClickedChargebutton();
};
