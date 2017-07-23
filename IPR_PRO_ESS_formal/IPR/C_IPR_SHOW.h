#pragma once
#include "resource.h"

// C_IPR_SHOW 对话框

class C_IPR_SHOW : public CDialogEx
{
	DECLARE_DYNAMIC(C_IPR_SHOW)

public:
	C_IPR_SHOW(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~C_IPR_SHOW();

	virtual void OnFinalRelease();

// 对话框数据
	enum { IDD = IDD_IPR_SHOW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	afx_msg void OnStnClickedIprRes();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedClose();
};
