#pragma once


// C_CDdialog_Reservoir 对话框

class C_CDdialog_Reservoir : public CDialogEx
{
	DECLARE_DYNAMIC(C_CDdialog_Reservoir)

public:
	C_CDdialog_Reservoir(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~C_CDdialog_Reservoir();

// 对话框数据
	enum { IDD = IDD_Reservior };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangePressIni();
	float ID_Vari_Pre_Ini;
	// //合理地层压力
	float ID_Vari_Pres_Opt;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	// //reserve varible
	float ID_Vari_Reserves;
	float ID_Vari_Reserve_rec;
};
