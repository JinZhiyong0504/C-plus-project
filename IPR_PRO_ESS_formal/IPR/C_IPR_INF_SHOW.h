#pragma once
#include "resource.h"

// C_IPR_INF_SHOW 对话框

class C_IPR_INF_SHOW : public CDialogEx
{
	DECLARE_DYNAMIC(C_IPR_INF_SHOW)

public:
	C_IPR_INF_SHOW(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~C_IPR_INF_SHOW();

// 对话框数据
	enum { IDD = IDD_IPR_INF_SHOW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString P_PRENT;
	CString m_STR_P_INF;
	afx_msg void OnBnClickedCalt();
};
