#pragma once


// CTabWarehouse dialog

class CTabWarehouse : public CDialogEx
{
	DECLARE_DYNAMIC(CTabWarehouse)

public:
	CTabWarehouse(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTabWarehouse();

// Dialog Data
	enum { IDD = IDD_TAB_WAREHOUSE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
