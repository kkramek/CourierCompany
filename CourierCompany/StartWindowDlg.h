#pragma once
#include "afxwin.h"
#include "resource.h"
#include <string>
#include <iostream>

using namespace std;

// StartWindowDlg dialog

class StartWindowDlg : public CDialog
{
	DECLARE_DYNAMIC(StartWindowDlg)

public:
	StartWindowDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~StartWindowDlg();

// Dialog Data
	enum { IDD = IDD_STARTWINDOWDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString startDataNick;
	string GetUserName();
	void SetUserName(string playerName);

private:
	string playerName;
public:
	afx_msg void StartGameOnClickBtn();
	CEdit playerNick;
	CButton LoadGame;
	afx_msg void OnBnClickedLoad();
};
