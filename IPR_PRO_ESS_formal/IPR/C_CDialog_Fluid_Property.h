#pragma once


// C_CDialog_Fluid_Property 对话框

class C_CDialog_Fluid_Property : public CDialogEx
{
	DECLARE_DYNAMIC(C_CDialog_Fluid_Property)

public:
	C_CDialog_Fluid_Property(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~C_CDialog_Fluid_Property();

// 对话框数据
	enum { IDD = IDD_Property_fluid };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:

	// //油粘度
	double ID_Vari_Visc_Oil;
	// //水粘度
	double ID_Vari_Visc_Wat;
	// //油密度
	double ID_Vari_Den_o;
	// //油压缩系数
	double ID_Vari_Comp_o;
	double ID_VolumFactor_G;
	double ID_Sat_P;
	double ID_VolumFactor_W;
	double ID_CompFactor_T;
	// //油体积系数
	double ID_Vari_Volume_Factor;
	double ID_SolutP_ini;
	double ID_SolutP_Prent;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCheckP();
	afx_msg void OnBnSetfocusCheckP();
	afx_msg void OnBnClickedCancel();
};
