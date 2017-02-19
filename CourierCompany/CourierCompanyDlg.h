
// CourierCompanyDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "TabMenu.h"
#include "StartWindowDlg.h"
#include "FileManager.h"
#include <string>
#include <iostream>


// CCDlg dialog
class CCDlg : public CDialogEx
{
// Construction
public:
	CCDlg(CWnd* pParent = NULL);	// standard constructor
	CTabMenu m_tabMenu;

// Dialog Data
	enum { IDD = IDD_COURIERCOMPANY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEdit1();
	CEdit playerDataName;
	CEdit playerDataLevel;
	CEdit playerDataMoney;
	CEdit inputPlayerName;
	afx_msg void OnBnClickedButton1();
	CTabCtrl menu;
	CString userDataNick;
	CString userDataLvl;
	CString userDataMoney;
	CString userDataTime;
	void StartGame();
	static UINT SetHeaderUserData(LPVOID pParam);
	void UpdateHeaderData(string playerName, int playerLvl, int playerAccountBalance);
	CStatic headerDataNick;
	afx_msg void saveAction();
	afx_msg void loadAction();
	afx_msg void OnStnClickedWindowSplit();
	afx_msg void OnStnClickedEdit1();
};
