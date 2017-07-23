#pragma once


// C_CDialog_Scale 对话框

class C_CDialog_Scale : public CDialogEx
{
	DECLARE_DYNAMIC(C_CDialog_Scale)

public:
	C_CDialog_Scale(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~C_CDialog_Scale();

// 对话框数据
	enum { IDD = IDD_SCAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// //初始含水饱和度
	float ID_Vari_Satu_Ini_W;
	// //束缚水
	float ID_Vari_Conate_W;
	float ID_Vari_Para_a;
	// //参数b
	float ID_Vari_Para_b;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
