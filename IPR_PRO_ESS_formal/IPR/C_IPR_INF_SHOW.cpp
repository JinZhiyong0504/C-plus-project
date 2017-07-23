// C_IPR_INF_SHOW.cpp : 实现文件
//

#include "stdafx.h"
#include "IPR.h"
#include "C_IPR_INF_SHOW.h"
#include "afxdialogex.h"
#include "IPR_OPT.h"
extern CIPR_OPT theIPR;

// C_IPR_INF_SHOW 对话框

IMPLEMENT_DYNAMIC(C_IPR_INF_SHOW, CDialogEx)

C_IPR_INF_SHOW::C_IPR_INF_SHOW(CWnd* pParent /*=NULL*/)
	: CDialogEx(C_IPR_INF_SHOW::IDD, pParent)
	, P_PRENT(_T(""))
	, m_STR_P_INF(_T(""))
{

}

C_IPR_INF_SHOW::~C_IPR_INF_SHOW()
{
}

void C_IPR_INF_SHOW::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_P_PRET, P_PRENT);
	DDV_MaxChars(pDX, P_PRENT, 10);
	DDX_Text(pDX, IDC_P_INF, m_STR_P_INF);
	DDV_MaxChars(pDX, m_STR_P_INF, 10);
}


BEGIN_MESSAGE_MAP(C_IPR_INF_SHOW, CDialogEx)
	ON_BN_CLICKED(IDCALT, &C_IPR_INF_SHOW::OnBnClickedCalt)
END_MESSAGE_MAP()


// C_IPR_INF_SHOW 消息处理程序


void C_IPR_INF_SHOW::OnBnClickedCalt()
{
	// TODO: 在此添加控件通知处理程序代码

	if(UpdateData(true)!=0)
	{
	//UpdateData(false);
	char P_PRENT_Str[10];
	char CharCum_Oil_Str[10];
	char CharCum_Wat_Str[10];
	char CharCum_Gas_Str[10];
	char CharIPR[10];
	float P_prest,IPR_inf;
	float Cum_Oil,Cum_Gas,Cum_Wat;
	float IPR_INF;

	theIPR.Bg=1;
	theIPR.Boi=1.2;
	theIPR.Bw=1;
	theIPR.Compss_Ct=0.00123;
	theIPR.S_w_ini=0.2;

	//GetDlgItem(IDC_PRESS_INI)->GetWindowText(Ct_string,10);
	//SendDlgItemMessage(IDC_COMPRESSIBLITY,WM_GETTEXT,20,(LPARAM)Ct_string);
	SendDlgItemMessage(IDC_P_PRET,WM_GETTEXT,10,(LPARAM)P_PRENT_Str);
	SendDlgItemMessage(IDC_Cum_Oil,WM_GETTEXT,10,(LPARAM)CharCum_Oil_Str);
	SendDlgItemMessage(IDC_Cum_Wat,WM_GETTEXT,10,(LPARAM)CharCum_Wat_Str);
	SendDlgItemMessage(IDC_Cum_Gas,WM_GETTEXT,10,(LPARAM)CharCum_Gas_Str);

	P_prest=atof(P_PRENT_Str);
	Cum_Oil=atof(CharCum_Oil_Str);
	Cum_Wat=atof(CharCum_Wat_Str);
	Cum_Gas=atof(CharCum_Gas_Str);
	
	IPR_INF=(Cum_Oil*theIPR.Boi+Cum_Wat*theIPR.Bw-
		theIPR.Reserves*theIPR.Boi*theIPR.Compss_Ct*(theIPR.Ini_pressure-P_prest)/
		(1-theIPR.S_w_ini))/(Cum_Oil*theIPR.Boi+Cum_Wat*theIPR.Bw);

	SendDlgItemMessage(IDC_P_INF,WM_SETTEXT,10,(LPARAM)P_PRENT_Str);

	///*ID_Vari_Comp_o=_wtof((wchar_t*)Ct_string);
	//ID_Vari_Den_o=_wtof((wchar_t*)Den_str);	
	//ID_Vari_Visc_Oil=_wtof((wchar_t*)Visc_oil_str);
	//ID_Vari_Visc_Wat=_wtof((wchar_t*)Visc_Wat_str);
	//ID_Vari_Volume_Factor=_wtof((wchar_t*)Volume_Factor_str);*/


	}
	else
	{
		
	}





}
