// TabMenu.cpp : implementation file
//

#include "stdafx.h"
#include "CourierCompany.h"
#include "TabMenu.h"
#include "CourierCompanyDlg.h"

#include "TabGarage.h"
#include "TabWarehouse.h"
#include "TabMap.h"

// CTabMenu

IMPLEMENT_DYNAMIC(CTabMenu, CTabCtrl)

CTabMenu::CTabMenu()
{
	m_tabPages[0] = new CTabWarehouse;
	m_tabPages[1] = new CTabGarage;
	m_tabPages[2] = new CTabMap;
}

CTabMenu::~CTabMenu()
{
	for (int nCount = 0; nCount < m_nNumberOfPages; nCount++) {
		delete m_tabPages[nCount];
	}
}


BEGIN_MESSAGE_MAP(CTabMenu, CTabCtrl)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



// CTabMenu message handlers




void CTabMenu::Init()
{
	m_tabCurrent = 0;

	m_tabPages[0]->Create(IDD_TAB_WAREHOUSE, this);
	m_tabPages[1]->Create(IDD_TAB_GARAGE, this);
	m_tabPages[2]->Create(IDD_TAB_MAP, this);

	m_tabPages[0]->ShowWindow(SW_SHOW);
	m_tabPages[1]->ShowWindow(SW_HIDE);
	m_tabPages[2]->ShowWindow(SW_HIDE);

}

void CTabMenu::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CTabCtrl::OnLButtonDown(nFlags, point);

	if (m_tabCurrent != GetCurFocus()) {
		m_tabPages[m_tabCurrent]->ShowWindow(SW_HIDE);
		m_tabCurrent = GetCurFocus();
		m_tabPages[m_tabCurrent]->ShowWindow(SW_SHOW);
		m_tabPages[m_tabCurrent]->SetFocus();
	}
}
