
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "IPR.h"
#include "C_PVT_INPUT.h"
//#include "matlib.h"
//#include <GL/glut.h>

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_FILE_SAVE_AS, &CMainFrame::OnFileSaveAs)

	ON_COMMAND(ID_PLOT, &CMainFrame::OnPlot)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));
	
	SetWindowLong(m_hWnd,GWL_STYLE,WS_OVERLAPPEDWINDOW);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	cs.cx=1000;
	cs.cy=600;
	cs.style = WS_OVERLAPPED | FWS_ADDTOTITLE
		 | WS_THICKFRAME | WS_MINIMIZEBOX | WS_SYSMENU;	
	
	cs.style&=~FWS_ADDTOTITLE;
	//cs.lpszName="IPR";

	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序



void CMainFrame::OnFileSaveAs()
{
	// TODO: 在此添加命令处理程序代码

}


void CMainFrame::OnPlot()
{
	// TODO: 在此添加命令处理程序代码
//	 begin_scope
//    
//    initM(MATCOM_VERSION);
//
//  dMm(x); dMm(y); dMm(h_menu); dMm(h_submenu1); dMm(h_submenu2); dMm(handle); 
//  
//  #line 1 "d:/matcom/sin1111.m"
//  call_stack_begin;
//  #line 1 "d:/matcom/sin1111.m"
//_ x = colon(-pi,pi/10.0,pi);
//  #line 2 "d:/matcom/sin1111.m"
//_ y = tan(sin(x))-sin(tan(x));
//  #line 3 "d:/matcom/sin1111.m"
//_ display( figure((CL(1.0))) );
//  #line 3 "d:/matcom/sin1111.m"
//  // 创建一个图形窗
//  #line 4 "d:/matcom/sin1111.m"
//_ set(gcf(),(CL(TM("MenuBar")),TM("none")));
//  #line 5 "d:/matcom/sin1111.m"
////_ h_menu = uimenu((CL(gcf()),TM("label"),TM("Color")));
//  #line 5 "d:/matcom/sin1111.m"
//  // 制作用户顶层菜单项 Color <2>
//  #line 6 "d:/matcom/sin1111.m"
////_ h_submenu1 = uimenu((CL(h_menu),TM("label"),TM("Blue"),TM("callback"),TM("sin1111#0000")));
//  #line 7 "d:/matcom/sin1111.m"
//  //<4>
//  #line 8 "d:/matcom/sin1111.m"
////_ h_submenu2 = uimenu((CL(h_menu),TM("label"),TM("Red"),TM("callback"),TM("sin1111#0001")));
//  #line 9 "d:/matcom/sin1111.m"
//  // % 制作下拉菜单 Red <5> <6> 
//  
//  #line 11 "d:/matcom/sin1111.m"
//_ handle = plot((CL(x),y,TM("--rs"),TM("LineWidth"),3.0,TM("MarkerEdgeColor"),TM("k"),TM("MarkerFaceColor"),TM( \
//    "g"),TM("MarkerSize"),10.0));
//  
//  call_stack_end;
//
//  exitM();
//
//  end_scope

}
