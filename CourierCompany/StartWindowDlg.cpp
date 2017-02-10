// StartWindowDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CourierCompany.h"
#include "StartWindowDlg.h"
#include "afxdialogex.h"
#include "Library.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


// StartWindowDlg dialog

IMPLEMENT_DYNAMIC(StartWindowDlg, CDialog)

StartWindowDlg::StartWindowDlg(CWnd* pParent /*=NULL*/)
	: CDialog(StartWindowDlg::IDD, pParent)
	, startDataNick(_T(""))
{

}

StartWindowDlg::~StartWindowDlg()
{
}

void StartWindowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, startDataNick);
	DDV_MaxChars(pDX, startDataNick, 50);
	DDX_Control(pDX, IDC_EDIT1, playerNick);
	DDX_Control(pDX, IDLOAD, LoadGame);
}


BEGIN_MESSAGE_MAP(StartWindowDlg, CDialog)
	ON_BN_CLICKED(IDOK, &StartWindowDlg::StartGameOnClickBtn)
	ON_BN_CLICKED(IDLOAD, &StartWindowDlg::OnBnClickedLoad)
END_MESSAGE_MAP()


// StartWindowDlg message handlers

string StartWindowDlg::GetUserName()
{
	return this->playerName;
}

void StartWindowDlg::SetUserName(string playerName)
{
	this->playerName = playerName;
}


void StartWindowDlg::StartGameOnClickBtn()
{
	CString nick;
	string nickString;

	playerNick.GetWindowTextW(nick);
	nickString = Library::ConvertCStringToString(nick);

	if (nickString[0] == '\0') {
		MessageBox(_T("Entered nick is wrong. Please try again"), _T("Error"),
			MB_ICONERROR | MB_OK);
	}
	else {
		this->SetUserName(nickString);
		CDialog::OnOK();
	}

}




void StartWindowDlg::OnBnClickedLoad()
{
	CFileDialog FileDialog(TRUE, _T("save"), _T("*.save"));

	if (FileDialog.DoModal() == IDOK)
	{
		CString PathName = FileDialog.GetPathName();
		ifstream loadfile;
		loadfile.open(Library::ConvertCStringToString(PathName), ios::binary);
		if (loadfile.is_open())
		{
			string name;
			int namelenght;
			int money;
			int lvl;
			char temp;
			loadfile >> namelenght;
			for (int i = 0; i < namelenght; i++)
			{
				loadfile >> temp;
				name += temp;
			}
			loadfile >> lvl >> money;


			loadfile.close();



			this->SetUserName(name);
			CDialog::OnOK();

		}
		else
		{
			MessageBox(_T("Access danied"), _T("Error"),
				MB_ICONERROR | MB_OK);
		}
		
	}
}
