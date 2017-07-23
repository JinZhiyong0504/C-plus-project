// C_CDialog_Scale.cpp : 实现文件
//

#include "stdafx.h"
#include "IPR.h"
#include "C_CDialog_Scale.h"
#include "afxdialogex.h"
#include "IPR_OPT.h"


// C_CDialog_Scale 对话框

IMPLEMENT_DYNAMIC(C_CDialog_Scale, CDialogEx)

C_CDialog_Scale::C_CDialog_Scale(CWnd* pParent /*=NULL*/)
	: CDialogEx(C_CDialog_Scale::IDD, pParent)
	, ID_Vari_Satu_Ini_W(0)
	, ID_Vari_Conate_W(0)
	, ID_Vari_Para_a(0)
	, ID_Vari_Para_b(0)
{

}

C_CDialog_Scale::~C_CDialog_Scale()
{
}

void C_CDialog_Scale::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Satu_INI_W, ID_Vari_Satu_Ini_W);
	DDV_MinMaxFloat(pDX, ID_Vari_Satu_Ini_W, 0, 1);
	DDX_Text(pDX, IDC_Sat_Res_O, ID_Vari_Conate_W);
	DDV_MinMaxFloat(pDX, ID_Vari_Conate_W, 0, 1);
	DDX_Text(pDX, IDC_Scale_Para_a, ID_Vari_Para_a);
	DDV_MinMaxFloat(pDX, ID_Vari_Para_a, 0, 10000000);
	DDX_Text(pDX, IDC_Scale_Para_b, ID_Vari_Para_b);
	DDV_MinMaxFloat(pDX, ID_Vari_Para_b, 0, 10000000);
}


BEGIN_MESSAGE_MAP(C_CDialog_Scale, CDialogEx)
	ON_BN_CLICKED(IDOK, &C_CDialog_Scale::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &C_CDialog_Scale::OnBnClickedCancel)
END_MESSAGE_MAP()


// C_CDialog_Scale 消息处理程序


void C_CDialog_Scale::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
	if(UpdateData(true)!=0)
	{
	//UpdateData(false);
	char Conate_Wat_str[10],Para_a_str[20],Para_b_str[20],Satu_Ini_w_str[20];
	//GetDlgItem(IDC_PRESS_INI)->GetWindowText(Ct_string,10);
	SendDlgItemMessage(IDC_Sat_Res_O,WM_GETTEXT,20,(LPARAM)Conate_Wat_str);
	SendDlgItemMessage(IDC_Scale_Para_a,WM_GETTEXT,20,(LPARAM)Para_a_str);
	SendDlgItemMessage(IDC_Scale_Para_b,WM_GETTEXT,20,(LPARAM)Para_b_str);
	SendDlgItemMessage(IDC_Satu_INI_W,WM_GETTEXT,20,(LPARAM)Satu_Ini_w_str);
	
	//ID_Vari_Conate_W=atof(Conate_Wat_str);
	//ID_Vari_Para_a=atof(Para_a_str); 
	//ID_Vari_Para_b=atof(Para_b_str); 
	//ID_Vari_Satu_Ini_W=atof(Satu_Ini_w_str);
	

	theIPR.S_o_residule=ID_Vari_Conate_W;
	theIPR.Para_a=ID_Vari_Para_a;
	theIPR.Para_b=ID_Vari_Para_b;
	theIPR.S_w_ini=ID_Vari_Satu_Ini_W;	

	EndDialog(1);

	}
	else
	{
	}
}


void C_CDialog_Scale::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
