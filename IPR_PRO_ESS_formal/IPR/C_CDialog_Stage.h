#pragma once


// C_CDialog_Stage 对话框

class C_CDialog_Stage : public CDialogEx
{
	DECLARE_DYNAMIC(C_CDialog_Stage)

public:
	C_CDialog_Stage(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~C_CDialog_Stage();

// 对话框数据
	enum { IDD = IDD_Stage };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
