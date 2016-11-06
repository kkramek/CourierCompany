// CourierCompanyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CourierCompany.h"
#include "CourierCompanyDlg.h"
#include "afxdialogex.h"
#include "Player.h"
#include "Game.h"
#include "StartWindowDlg.h"
#include "Library.h"
#include "afxwin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCDlg dialog



CCDlg::CCDlg(CWnd* pParent /*=NULL*/)
: CDialogEx(CCDlg::IDD, pParent)
, userDataNick(_T(""))
, userDataLvl(_T(""))
, userDataMoney(_T(""))
, userDataTime(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tabMenu);
	DDX_Text(pDX, ID_RECORD_NEXT, userDataNick);
	DDV_MaxChars(pDX, userDataNick, 50);
	DDX_Text(pDX, ID_WINDOW_NEW, userDataLvl);
	DDV_MaxChars(pDX, userDataLvl, 50);
	DDX_Text(pDX, ID_WINDOW_SPLIT, userDataMoney);
	DDV_MaxChars(pDX, userDataMoney, 100);
	DDX_Text(pDX, IDC_EDIT1, userDataTime);
	DDV_MaxChars(pDX, userDataTime, 50);

}

BEGIN_MESSAGE_MAP(CCDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CCDlg message handlers

BOOL CCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	this->StartGame();
	
	m_tabMenu.InsertItem(0, _T("Tab Warehouse"));
	m_tabMenu.InsertItem(1, _T("Tab Garage"));
	m_tabMenu.InsertItem(2, _T("Tab Map"));

	m_tabMenu.Init();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);



		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCDlg::StartGame()
{
	Game* game;
	INT_PTR nRet = -1;

	StartWindowDlg startWindow;
	startWindow.DoModal();
	string userName = startWindow.GetUserName();

	game = Game::getInstance();
	game->SetPlayer(userName);
}

void CCDlg::SetHeaderUserData()
{
	string playerName, playerLvl;
	float playerAccountBalance;
	CString pName, pLvl;

	Game* game;
	Player* player;
	game = Game::getInstance();
	player = game->GetPlayer();

	playerName = player->getName();
	playerLvl = player->getLevel();
	playerAccountBalance = player->getAccountBalance();

	pName = Library::ConvertStringToCString(playerName);

	playerDataName.SetWindowTextW(pName);
}







