// C_CDialog_Fluid_Property.cpp : 实现文件
//

#include "stdafx.h"
#include "IPR.h"
#include "C_CDialog_Fluid_Property.h"
#include "afxdialogex.h"
#include "IPR_OPT.h"


// C_CDialog_Fluid_Property 对话框

IMPLEMENT_DYNAMIC(C_CDialog_Fluid_Property, CDialogEx)

C_CDialog_Fluid_Property::C_CDialog_Fluid_Property(CWnd* pParent /*=NULL*/)
	: CDialogEx(C_CDialog_Fluid_Property::IDD, pParent)
	, ID_Vari_Visc_Oil(0)
	, ID_Vari_Visc_Wat(0)
	, ID_Vari_Den_o(0)
	, ID_Vari_Comp_o(0)
	, ID_Vari_Volume_Factor(0)
{

}

C_CDialog_Fluid_Property::~C_CDialog_Fluid_Property()
{
}

void C_CDialog_Fluid_Property::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Visc_Oil, ID_Vari_Visc_Oil);
	DDV_MinMaxFloat(pDX, ID_Vari_Visc_Oil, 0, 1000);
	DDX_Text(pDX, IDC_Visc_Wat, ID_Vari_Visc_Wat);
	DDV_MinMaxFloat(pDX, ID_Vari_Visc_Wat, 0, 1000);
	DDX_Text(pDX, IDC_Den_o, ID_Vari_Den_o);
	DDV_MinMaxFloat(pDX, ID_Vari_Den_o, 0, 1000);
	DDX_Text(pDX, IDC_COMPRESSIBLITY, ID_Vari_Comp_o);
	DDV_MinMaxFloat(pDX, ID_Vari_Comp_o, 0, 1);
	DDX_Text(pDX, IDC_Volume_factor_O, ID_Vari_Volume_Factor);
	DDV_MinMaxFloat(pDX, ID_Vari_Volume_Factor, 0, 5);
}


BEGIN_MESSAGE_MAP(C_CDialog_Fluid_Property, CDialogEx)

	ON_BN_CLICKED(IDOK, &C_CDialog_Fluid_Property::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK_P, &C_CDialog_Fluid_Property::OnBnClickedCheckP)
	ON_BN_SETFOCUS(IDC_CHECK_P, &C_CDialog_Fluid_Property::OnBnSetfocusCheckP)
	ON_BN_CLICKED(IDCANCEL, &C_CDialog_Fluid_Property::OnBnClickedCancel)
END_MESSAGE_MAP()


// C_CDialog_Fluid_Property 消息处理程序



void C_CDialog_Fluid_Property::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
	if(UpdateData(true)!=0)
	{
	//UpdateData(false);
	char Ct_string[20],Den_str[20],Visc_oil_str[20],Visc_Wat_str[20],Volume_Factor_str[20];	
	char Satu_P_str[20],Volume_Fact_W_str[20],Volume_Fact_G_str[20],Solut_GOR_INI_str[20],Solut_GOR_PRET_str[20];

	//GetDlgItem(IDC_PRESS_INI)->GetWindowText(Ct_string,10);
	//SendDlgItemMessage(IDC_COMPRESSIBLITY,WM_GETTEXT,20,(LPARAM)Ct_string);
	SendDlgItemMessage(IDC_COMPRESSIBLITY,WM_GETTEXT,20,(LPARAM)Ct_string);
	SendDlgItemMessage(IDC_Den_o,WM_GETTEXT,20,(LPARAM)Den_str);
	SendDlgItemMessage(IDC_Visc_Oil,WM_GETTEXT,20,(LPARAM)Visc_oil_str);
	SendDlgItemMessage(IDC_Visc_Wat,WM_GETTEXT,20,(LPARAM)Visc_Wat_str);
	SendDlgItemMessage(IDC_Volume_factor_O,WM_GETTEXT,20,(LPARAM)Volume_Factor_str);
	
	
	SendDlgItemMessage(IDC_Saturation_P,WM_GETTEXT,20,(LPARAM)Satu_P_str);
	SendDlgItemMessage(IDC_Volume_Factor_W,WM_GETTEXT,20,(LPARAM)Volume_Fact_W_str);
	SendDlgItemMessage(IDC_Volume_Factor_G,WM_GETTEXT,20,(LPARAM)Volume_Fact_G_str);
	SendDlgItemMessage(IDC_GOR_INI,WM_GETTEXT,20,(LPARAM)Solut_GOR_INI_str);
	
//	if(((CButton *)GetDlgItem(IDC_CHECK_P))->GetCheck()==1)
//	{
//		SendDlgItemMessage(IDC_GOR_PREST,WM_GETTEXT,20,(LPARAM)Solut_GOR_PRET_str);	
//		theIPR.Solut_GOR_PRENT=_wtof((wchar_t*)Solut_GOR_PRET_str);
//	}

	//ID_Vari_Comp_o=_wtof((wchar_t*)Ct_string);
	//ID_Vari_Den_o=_wtof((wchar_t*)Den_str);	
	//ID_Vari_Visc_Oil=_wtof((wchar_t*)Visc_oil_str);
	//ID_Vari_Visc_Wat=_wtof((wchar_t*)Visc_Wat_str);
	//ID_Vari_Volume_Factor=_wtof((wchar_t*)Volume_Factor_str);


	theIPR.Compss_Ct=ID_Vari_Comp_o;
	theIPR.Gravity_o=ID_Vari_Den_o;
	theIPR.Visc_o=ID_Vari_Visc_Oil;
	theIPR.Visc_w=ID_Vari_Visc_Wat;
	theIPR.Boi=ID_Vari_Volume_Factor;	

	theIPR.P_satu=_wtof((wchar_t*)Satu_P_str);
	theIPR.Bw=_wtof((wchar_t*)Volume_Fact_W_str);
	theIPR.Bg=_wtof((wchar_t*)Volume_Fact_G_str);
	theIPR.Solut_GOR_INI=_wtof((wchar_t*)Solut_GOR_INI_str);

	EndDialog(1);

	}
	else
	{
		EndDialog(1);

	}
	EndDialog(1);
}


void C_CDialog_Fluid_Property::OnBnClickedCheckP()
{
	// TODO: 在此添加控件通知处理程序代码
	// SendDlgItemMessage（IDC_GOR_INI,WM_ENABLE,false,0);
	// GetDlgItem(IDC_GOR_INI)->EnableActiveAccessibility();
	// GetDlgItem(IDC_GOR_INI)->EnableWindow(TRUE);
	GetDlgItem(IDC_GOR_PREST)->EnableWindow(TRUE);
}


void C_CDialog_Fluid_Property::OnBnSetfocusCheckP()
{
	// TODO: 在此添加控件通知处理程序代码
	// GetDlgItem(IDC_GOR_INI)->EnableWindow(TRUE);
	// GetDlgItem(IDC_GOR_PREST)->EnableWindow(TRUE);
}


void C_CDialog_Fluid_Property::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
