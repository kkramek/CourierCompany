#pragma once


// CTabMenu

class CTabMenu : public CTabCtrl
{
	DECLARE_DYNAMIC(CTabMenu)

public:
	CTabMenu();
	virtual ~CTabMenu();
	CDialog *m_tabPages[3];
	int m_tabCurrent;
	int m_nNumberOfPages;

protected:
	DECLARE_MESSAGE_MAP()
public:
	void Init();
	void SetRectengle(void);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};


