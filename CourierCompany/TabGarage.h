#pragma once


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
};
