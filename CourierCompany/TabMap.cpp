// TabMap.cpp : implementation file
//

#include "stdafx.h"
#include "CourierCompany.h"
#include "TabMap.h"
#include "afxdialogex.h"


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

	//CBitmap bmp;

	//bmp.LoadBitmap(GAMEMAP);

	//gameMapField.SetBitmap((HBITMAP)bmp);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTabMap::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTabMap, CDialogEx)
	//ON_WM_PAINT()
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

	X.MoveTo(100, 100);
	X.LineTo(200, 200);
}
