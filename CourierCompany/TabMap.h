#pragma once


// CTabMap dialog

class CTabMap : public CDialogEx
{
	DECLARE_DYNAMIC(CTabMap)

public:
	CTabMap(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTabMap();

// Dialog Data
	enum { IDD = IDD_TAB_MAP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	void DrawMap(CPaintDC & X);

	DECLARE_MESSAGE_MAP()
};
