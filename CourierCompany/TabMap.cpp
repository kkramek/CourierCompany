// TabMap.cpp : implementation file
//

#include "stdafx.h"
#include "CourierCompany.h"
#include "TabMap.h"
#include "afxdialogex.h"
#include "Game.h"


// CTabMap dialog

IMPLEMENT_DYNAMIC(CTabMap, CDialogEx)

CTabMap::CTabMap(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTabMap::IDD, pParent)
{

}

CTabMap::~CTabMap()
{
}

BOOL CTabMap::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	this->SetBackgroundImage(IDB_BITMAP2, BACKGR_TOPLEFT, TRUE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTabMap::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTabMap, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


void CTabMap::OnPaint()
{
	CPaintDC X(this);
	DrawMap(X);
}

void CTabMap::DrawMap(CPaintDC & X)
{
	CPen pen(PS_SOLID, 2, RGB(255, 0, 0));
	CPen* pOldPen = X.SelectObject(&pen);

	X.SelectStockObject(BLACK_BRUSH);
	X.Rectangle(0, 0, 10, 10);

	//X.MoveTo(100, 100);
	//X.LineTo(200, 200);
}
///////////////////////////////////
void CTabMap::LevelUP()
{
	Game *game = Game::getInstance();
	Player * player = game->GetPlayer();
	if ((player->getLevel()) < ((player->GetDeliveredPackages() / 100) + 1))
	{
		player->setLevel(player->getLevel() + 1);
		player->SetUpgradePoints(player->GetUpgradePoints() + 10);
		MessageBox(_T("You've reached the next level. Go to garage and use 10 points to upgrade your vehicles"), _T("LEVEL UP"),
			MB_ICONINFORMATION | MB_OK);
	}
}