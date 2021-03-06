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

	DDX_Control(pDX, ID_RECORD_NEXT, headerDataNick);
	DDX_Control(pDX, IDC_BUTTON1, SaveGame);
}

BEGIN_MESSAGE_MAP(CCDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CCDlg::saveAction)
	ON_BN_CLICKED(IDC_BUTTON2, &CCDlg::loadAction)
	ON_STN_CLICKED(ID_WINDOW_SPLIT, &CCDlg::OnStnClickedWindowSplit)
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

	AfxBeginThread(SetHeaderUserData, (LPVOID)this);
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
	if (!startWindow.wasLoaded())
	{
		string userName = startWindow.GetUserName();

		game = Game::getInstance();
		game->SetPlayer(userName);
	}
}


UINT CCDlg::SetHeaderUserData(LPVOID pParam)
{
	CCDlg *dlg = (CCDlg*)pParam;
	string playerName;
	int playerLvl;
	int playerAccountBalance;
	CString pName, pLvl, pAccountBalance;

	Game* game;
	Player* player;
	game = Game::getInstance();
	player = game->GetPlayer();
	
	playerName = player->getName();
	playerLvl = player->getLevel();
	playerAccountBalance = player->getAccountBalance();

	pName = Library::ConvertStringToCString("Nick: " + playerName);
	pLvl = Library::ConvertStringToCString("Level: " + to_string(playerLvl));
	pAccountBalance = Library::ConvertStringToCString("Account balance: " + to_string(playerAccountBalance));

	dlg->GetDlgItem(ID_RECORD_NEXT)->SetWindowText(pName);
	dlg->GetDlgItem(ID_WINDOW_NEW)->SetWindowText(pLvl);
	dlg->GetDlgItem(ID_WINDOW_SPLIT)->SetWindowText(pAccountBalance);
	
	return 0;
}

void CCDlg::UpdateHeaderData(string playerName, int playerLvl, int playerAccountBalance)
{
	CString pName, pLvl, pAccountBalance;

	pName = Library::ConvertStringToCString("Nick: " + playerName);
	pLvl = Library::ConvertStringToCString("Level: " + to_string(playerLvl));
	pAccountBalance = Library::ConvertStringToCString("Account balance: " + to_string(playerAccountBalance));

	playerDataName.SetWindowText(pName);
	playerDataMoney.SetWindowText(pLvl);
	playerDataMoney.SetWindowText(pAccountBalance);
}





void CCDlg::saveAction()
{
	FileManager* fileManager = new FileManager();
	fileManager->SaveGame();
}


void CCDlg::loadAction()
{
	FileManager* fileManager = new FileManager();
	fileManager->LoadGame();
}


void CCDlg::OnStnClickedWindowSplit()
{
	// TODO: Add your control notification handler code here
}
