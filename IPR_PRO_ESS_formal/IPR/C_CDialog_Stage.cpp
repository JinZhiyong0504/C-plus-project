// C_CDialog_Stage.cpp : 实现文件
//

#include "stdafx.h"
#include "IPR.h"
#include "C_CDialog_Stage.h"
#include "afxdialogex.h"
#include "IPR_OPT.h"


// C_CDialog_Stage 对话框

IMPLEMENT_DYNAMIC(C_CDialog_Stage, CDialogEx)

C_CDialog_Stage::C_CDialog_Stage(CWnd* pParent /*=NULL*/)
	: CDialogEx(C_CDialog_Stage::IDD, pParent)
{

}

C_CDialog_Stage::~C_CDialog_Stage()
{
}

void C_CDialog_Stage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(C_CDialog_Stage, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO1, &C_CDialog_Stage::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &C_CDialog_Stage::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &C_CDialog_Stage::OnBnClickedRadio3)
	ON_BN_CLICKED(IDOK, &C_CDialog_Stage::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &C_CDialog_Stage::OnBnClickedCancel)
END_MESSAGE_MAP()


// C_CDialog_Stage 消息处理程序


void C_CDialog_Stage::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
	theIPR.stage=1;
}


void C_CDialog_Stage::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
	theIPR.stage=2;
}


void C_CDialog_Stage::OnBnClickedRadio3()
{
	// TODO: 在此添加控件通知处理程序代码
	theIPR.stage=3;
}


void C_CDialog_Stage::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void C_CDialog_Stage::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
