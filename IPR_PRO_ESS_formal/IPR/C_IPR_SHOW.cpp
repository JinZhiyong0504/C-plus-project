// C_IPR_SHOW.cpp : 实现文件
//

#include "stdafx.h"
#include "IPR.h"
#include "C_IPR_SHOW.h"
#include "afxdialogex.h"
#include "IPR_OPT.h"
#include <string>
#include <fontsub.h>
#include <afxwin.h> 
extern CIPR_OPT theIPR;


// C_IPR_SHOW 对话框

IMPLEMENT_DYNAMIC(C_IPR_SHOW, CDialogEx)

C_IPR_SHOW::C_IPR_SHOW(CWnd* pParent /*=NULL*/)
	: CDialogEx(C_IPR_SHOW::IDD, pParent)
{

	EnableAutomation();

}

C_IPR_SHOW::~C_IPR_SHOW()
{
}

void C_IPR_SHOW::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CDialogEx::OnFinalRelease();
}

void C_IPR_SHOW::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(C_IPR_SHOW, CDialogEx)
	//ON_STN_CLICKED(IDC_IPR_RES, &C_IPR_SHOW::OnStnClickedIprRes)
	ON_BN_CLICKED(IDCANCEL, &C_IPR_SHOW::OnBnClickedClose)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(C_IPR_SHOW, CDialogEx)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_I_IPR_SHOW 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {045CE6A1-D128-4527-ADEF-DCB517BC6C4B}
static const IID IID_I_IPR_SHOW =
{ 0x45CE6A1, 0xD128, 0x4527, { 0xAD, 0xEF, 0xDC, 0xB5, 0x17, 0xBC, 0x6C, 0x4B } };

BEGIN_INTERFACE_MAP(C_IPR_SHOW, CDialogEx)
	INTERFACE_PART(C_IPR_SHOW, IID_I_IPR_SHOW, Dispatch)
END_INTERFACE_MAP()


// C_IPR_SHOW 消息处理程序


void C_IPR_SHOW::OnStnClickedIprRes()
{
	// TODO: 在此添加控件通知处理程序代码
}


BOOL C_IPR_SHOW::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  在此添加额外的初始化
	TCHAR Head[]=_T("不同含水阶段注采比计算结果：\r\n\r\n");
	TCHAR  T1[100];
	//("最优的IPR：\r\n");
	//static TCHAR  IPR_STR[10];
	TCHAR IPR_STR[10];
	//gcvt(theIPR.IPR[0],5,IPR_STR);		
	//GetDlgItem(IDC_IPR_TEXT)->
	CFont font;

	VERIFY(font.CreateFont(
   25,                        // nHeight
   25,                         // nWidth
   0,                         // nEscapement
   0,                         // nOrientation
   FW_SEMIBOLD,                 // nWeight
   FALSE,                     // bItalic
   FALSE,                     // bUnderline
   0,                         // cStrikeOut
   GB2312_CHARSET,              // nCharSet
   OUT_DEFAULT_PRECIS,        // nOutPrecision
   CLIP_DEFAULT_PRECIS,       // nClipPrecision
   DEFAULT_QUALITY,           // nQuality
   DEFAULT_PITCH | FF_SWISS, // nPitchAndFamily
   L"宋体"));                 // lpszFacename
	
	CWnd *cWnd = GetDlgItem(IDC_IPR_TEXT);
	cWnd->SetFont(&font);
	cWnd->GetDC()->SetTextColor(RGB(0,255,200));

	theIPR.IPR_CMP();

	switch(theIPR.stage)
	{
	case 1:
		wcscpy(T1,Head);
		wcscat(T1,_T("含水0-60%注采比："));
		_stprintf(IPR_STR,_T("%.2f"),theIPR.IPR[0]);
		wcscat(T1,IPR_STR);
		
		wcscat(T1,_T("\r\n\r\n"));
		wcscat(T1,_T("含水60-90%注采比："));
		_stprintf(IPR_STR,_T("%.2f"),theIPR.IPR[1]);
		wcscat(T1,IPR_STR);
		GetDlgItem(IDC_IPR_TEXT)->SetWindowText(T1);
		
		wcscat(T1,_T("\r\n\r\n"));
		wcscat(T1,_T("含水>90%注采比："));
		wcscat(T1,_T("1"));
		GetDlgItem(IDC_IPR_TEXT)->SetWindowText(T1);	

		break;
	case 2:
		wcscpy(T1,Head);
		wcscat(T1,_T("含水0-30%注采比："));
		_stprintf(IPR_STR,_T("%.2f"),theIPR.IPR[0]);
		wcscat(T1,IPR_STR);
		
		wcscat(T1,_T("\r\n\r\n"));
		wcscat(T1,_T("含水30%-60%注采比："));
		_stprintf(IPR_STR,_T("%.2f"),theIPR.IPR[1]);
		wcscat(T1,IPR_STR);
		GetDlgItem(IDC_IPR_TEXT)->SetWindowText(T1);
		
		wcscat(T1,_T("\r\n\r\n"));
		wcscat(T1,_T("含水60%-90%注采比："));
		_stprintf(IPR_STR,_T("%.2f"),theIPR.IPR[2]);
		wcscat(T1,IPR_STR);
		GetDlgItem(IDC_IPR_TEXT)->SetWindowText(T1);

		wcscat(T1,_T("\r\n\r\n"));
		wcscat(T1,_T("含水>90%注采比："));
		wcscat(T1,_T("1"));
		GetDlgItem(IDC_IPR_TEXT)->SetWindowText(T1);	
		break;
	case 3:
		wcscpy(T1,Head);
		wcscat(T1,_T("含水0-60%注采比："));
		_stprintf(IPR_STR,_T("%.2f"),theIPR.IPR[0]);
		wcscat(T1,IPR_STR);
		
		wcscat(T1,_T("\r\n\r\n"));
		wcscat(T1,_T("含水60%-90%注采比："));
		_stprintf(IPR_STR,_T("%.2f"),theIPR.IPR[1]);
		wcscat(T1,IPR_STR);
		GetDlgItem(IDC_IPR_TEXT)->SetWindowText(T1);
		
		wcscat(T1,_T("\r\n\r\n"));
		wcscat(T1,_T("含水90%-95%注采比："));
		_stprintf(IPR_STR,_T("%.2f"),theIPR.IPR[2]);
		wcscat(T1,IPR_STR);
		GetDlgItem(IDC_IPR_TEXT)->SetWindowText(T1);

		wcscat(T1,_T("\r\n\r\n"));
		wcscat(T1,_T("含水>95%注采比："));
		wcscat(T1,_T("1"));
		GetDlgItem(IDC_IPR_TEXT)->SetWindowText(T1);		
		break;
	default:
		;
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void C_IPR_SHOW::OnBnClickedClose()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
