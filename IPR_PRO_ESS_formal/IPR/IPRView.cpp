
// IPRView.cpp : CIPRView 类的实现
//

#include "stdafx.h"
//#include "matlib.h"//matcom 包含头文件 与matlab的动态链接库冲突
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#include "stdafx.h"

#ifndef SHARED_HANDLERS
#include "IPR.h"
#endif

#include "IPRDoc.h"
#include "IPRView.h"
#include "C_CDdialog_Reservoir.h"
#include "C_CDialog_Fluid_Property.h"
#include "C_CDialog_Scale.h"
#include "C_CDialog_Stage.h"
#include <string.h>
#include "PRD.h"
#include "IPR_OPT.h"
#include "Pegrpapi.h"
#include <math.h>
#include "C_IPR_SHOW.h"
#include "resource.h"
#include "C_IPR_INF_SHOW.h"

//#include "mclmcr.h"
//#include "matrix.h"
//#include "mclcppclass.h"
//#include "libDrw_Prdu_Date.h"  
//
//#pragma comment( lib, "mclmcrrt.lib" )
//#pragma comment( lib, "libmx.lib" )
//#pragma comment( lib, "libmat.lib" )
//#pragma comment( lib, "mclmcr.lib" )
//#pragma comment (lib,"libDrw_Prdu_Date.lib") 

#include <stdio.h>
#include <iostream>
using namespace std;
extern CPRD thePrd;
extern CIPR_OPT theIPR;
HWND hPE;



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CIPRView

IMPLEMENT_DYNCREATE(CIPRView, CView)

BEGIN_MESSAGE_MAP(CIPRView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_Res, &CIPRView::OnRes)
	ON_COMMAND(ID_SCAL, &CIPRView::OnScal)
	ON_COMMAND(ID_Property_fluid, &CIPRView::OnPropertyfluid)
	ON_COMMAND(ID_Stage, &CIPRView::OnStage)
	ON_COMMAND(ID_FILE_SAVE_AS, &CIPRView::OnFileSaveAs)
	ON_COMMAND(ID_FILE_SAVE, &CIPRView::OnFileSave)
	ON_COMMAND(ID_FILE_OPEN, &CIPRView::OnFileOpen)
	ON_COMMAND(ID_Input_Data, &CIPRView::OnInputData)
	ON_COMMAND(ID_Plot_Fig, &CIPRView::OnPlotFig)
	ON_COMMAND(IDWCTVSRECV, &CIPRView::OnWctvsrecv)
	ON_COMMAND(IDCUMLQDVSWCT, &CIPRView::OnCumlqdvswct)
	ON_COMMAND(IDWATINDX, &CIPRView::OnWatindx)
	ON_COMMAND(IDWCTRECRATIO, &CIPRView::OnWctRecRatio)
	ON_COMMAND(IDRESIDWAT, &CIPRView::OnResidwat)
	ON_WM_PAINT()
	ON_COMMAND(ID_WCT_FIG, &CIPRView::OnWctFig)
	ON_COMMAND(ID_TSH_MODEL, &CIPRView::OnTshModel)
	ON_COMMAND(ID_TSH_MODEL_M, &CIPRView::OnTshModelM)
	ON_COMMAND(ID_SWPT_EFF, &CIPRView::OnSwptEff)
	ON_COMMAND(ID_IPR_OPT, &CIPRView::OnIprOpt)
	ON_COMMAND(ID_IPR_INF, &CIPRView::OnIprInf)
END_MESSAGE_MAP()

// CIPRView 构造/析构

CIPRView::CIPRView()

	: FIG_TYPE(0)
{
	// TODO: 在此处添加构造代码

}

CIPRView::~CIPRView()
{
}

BOOL CIPRView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CIPRView 绘制

void CIPRView::OnDraw(CDC* /*pDC*/)
{
	CIPRDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CIPRView 打印

BOOL CIPRView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CIPRView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CIPRView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CIPRView 诊断

#ifdef _DEBUG
void CIPRView::AssertValid() const
{
	CView::AssertValid();
}

void CIPRView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CIPRDoc* CIPRView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CIPRDoc)));
	return (CIPRDoc*)m_pDocument;
}
#endif //_DEBUG



void CIPRView::OnRes()
{
	// TODO: 在此添加命令处理程序代码
	
	C_CDdialog_Reservoir *pDlg_Res=new C_CDdialog_Reservoir();
	pDlg_Res->DoModal();
}


void CIPRView::OnScal()
{
	// TODO: 在此添加命令处理程序代码
	C_CDialog_Scale *pDlg_Scale=new C_CDialog_Scale();
	pDlg_Scale->DoModal();
}


void CIPRView::OnPropertyfluid()
{
	// TODO: 在此添加命令处理程序代码
	
	C_CDialog_Fluid_Property *pDlg_Fluid=new C_CDialog_Fluid_Property();
	pDlg_Fluid->DoModal();

}


void CIPRView::OnStage()
{
	// TODO: 在此添加命令处理程序代码
	C_CDialog_Stage *pDlg_Stage=new C_CDialog_Stage();
	pDlg_Stage->DoModal();
}


void CIPRView::OnFileSaveAs()
{
	// TODO: 在此添加命令处理程序代码
	
	CFileDialog fileDlg(FALSE);
	fileDlg.m_ofn.lpstrTitle=LPCTSTR(_T("Save as"));
	fileDlg.m_ofn.lpstrFilter=LPCTSTR(_T("*.IPR"));
	fileDlg.m_ofn.lpstrDefExt=LPCTSTR(_T("IPR"));
	if(IDOK==fileDlg.DoModal())
	{
		CFile file(fileDlg.GetFileName(),CFile::modeCreate | CFile::modeWrite);
		file.Write("http://www.sunxin.org",strlen("http://www.sunxin.org"));//add new data;
		file.Close();
	}
	
}


void CIPRView::OnFileSave()
{
	// TODO: 在此添加命令处理程序代码



}


void CIPRView::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
		
	CFileDialog fileDlg(TRUE);
	fileDlg.m_ofn.lpstrTitle=LPCTSTR(_T("Open"));
	fileDlg.m_ofn.lpstrFilter=LPCTSTR(_T("*.IPR"));
	
	if(IDOK==fileDlg.DoModal())
	{
		CFile file(fileDlg.GetFileName(),CFile::modeRead);
		char *pBuf;
		DWORD dwFileLen;
		dwFileLen=file.GetLength();
		pBuf=new char[dwFileLen+1];
		pBuf[dwFileLen]=0;
		file.Read(pBuf,dwFileLen);
		file.Close();
		//MessageBox(LPCTSTR(*pBuf));
		
	}
}

void CIPRView::OnInputData()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog fileDlg(TRUE);
	fileDlg.m_ofn.lpstrTitle=LPCTSTR(_T("输入生产数据"));
	fileDlg.m_ofn.lpstrFilter=LPCTSTR(_T("*.*"));
	
	if(IDOK==fileDlg.DoModal())
	{
		
		//CString fullpath(fileDlg.GetFolderPath());
		//fileDlg.GetPathName();	
			//+fileDlg.GetFileName();
		//fullpath.SetString(fileDlg.GetFolderPath()&&fileDlg.GetFileName());
		thePrd.Initialization(fileDlg.GetFileName());
		//thePrd.Initialization(fileDlg.GetPathName());	

	}

}

void CIPRView::OnPlotFig()
{
	//// TODO: 在此添加命令处理程序代码

	FIG_TYPE=1;
	OnPaint();
	

	////mclInitializeApplication(NULL,0);

	////if(!libDrw_Prdu_DateInitialize())
	////{   
	////	std::cout << "Could not initialize Drw_Prdu_Date!" << std::endl;   				 
	////}
	////
	////// 为变量分配内存空间，可以查帮助mwArray   

	////{
	////	//mwSize i=(mwSize)thePrd.DataLength;
	////	
	////	//mwArray mwA(i,1,mxDOUBLE_CLASS); // 1，1表示矩阵的大小（所有maltab只有一种变量，就是矩阵，为了和Cpp变量接轨，设置成1*1的矩阵，mxDOUBLE_CLASS表示变量的精度）   
	////	//mwArray mwB(1,1,mxDOUBLE_CLASS);   

	////	// set data，不用我解释了吧，很简单的，调用类里面的SetData函数给类赋值   
	////	//mwA.SetData(&a, 1);   
	////	//mwB.SetData(&b, 1);   
	////	// using my add，掉我自己写的函数   
	////	//MyAdd(1, mwC, mwA, mwB);   
	////	Drw_Prdu_Date();
	////	
	////	// get data，不用我解释了吧，很简单的，调用类里面的Get函数获取取函数返回值   
	/////*	int c = mwC.Get(1, 1);   */
	////	//printf("c is %f\n", c);   
	////	// 后面是一些终止调用的程序   
	////	 //terminate the lib   
	////}
	////	libDrw_Prdu_DateTerminate();   
	////	// terminate MCR   
	////	mclTerminateApplication();   

	////参数传递
	//
	//  //Mm x=zeros(1,thePrd.DataLength+1);
	//  //Mm y=zeros(1,thePrd.DataLength+1);
	//  //double x[2000];
	//  //memcpy(x.addr(),thePrd.Date,sizeof(thePrd.DataLength*sizeof(int)));
	//  //memcpy(x.addr(),thePrd.Date,sizeof(thePrd.DataLength*sizeof(int)));
	//  //initM(MATCOM_VERSION);
	//  //
	//  //set(gcf(),TM("MenuAbout"),TM("off"));
	//  //exitM();	
	////subplot(2,1,1);
	////thePrd.Draw_Date(1);
	////subplot(2,1,2);
	////thePrd.Draw_Date(1);

	//    subplot(2,1,1);

	//    initM(MATCOM_VERSION);

	//	 // Mm x,s,c;
	//	  Mm m_hPlot;//figure handle
	//	  Mm m_hAxis;//坐标轴句柄
	//	  Mm m_axispos;//坐标轴范围
	//	  Mm m_hXlabel,m_hYlabel,m_hTitle;//x轴，y轴和标题句柄


	//	  Mm date,Oil_P,Wat_P,Wcut;
	//	  int year,month;
	//	  float p;
	//	  int i;
	//	  int date_gap;//1:1-jan-2000;

	//	  date=zeros(1,thePrd.DataLength);
	//      Oil_P=zeros(1,thePrd.DataLength);
	//	  Wat_P=zeros(1,thePrd.DataLength);
	//	  Wcut=zeros(1,thePrd.DataLength);		  
	//	  
	//	  for(i=0;i<thePrd.DataLength;i++)
	//	  {
	//		  year=round(thePrd.Date[i]/100);			  			  
	//		  month=mod(thePrd.Date[i],100);
	//		  date(i+1)=datenum(year-1900,month,1);
	//		  Oil_P.r(i+1)=thePrd.Oil_P[i];
	//		  Wat_P.r(i+1)=thePrd.Wat_P[i];
	//		  
	//	  }
	//	 /* memcpy(x.addr(),thePrd.Date,sizeof(thePrd.DataLength*sizeof(int)));
	//      memcpy(y.addr(),thePrd.Date,sizeof(thePrd.DataLength*sizeof(float)));*/
	//	
	//	  //convert to date format
	//
	//	  //set(gcf(),TM("MenuAbout"),TM("off"));
	//	set(m_hAxis,TM("MenuAbout"),TM("off")); 

	//	m_hPlot=plot((CL(date),Oil_P,TM("LineWidth"),4,TM("COLOR"),TM("red")));	
	//	datetick('x',TM("yyyy/mm"));		
	//	hold();
	//	m_hPlot=plot((CL(date),Wat_P,TM("LineWidth"),4,TM("COLOR"),TM("blue")));	
	//	m_hAxis = gca();
	//	//set(m_hPlot,(CL(TM("COLOR")),TM("red")));
	//	//set(gcf(),TM("IconFile"),TM("IPR.ico"));

	//	set(m_hAxis,TM("color"),TM("White"));
	//	xlabel((CL(TM("Date"))));
	//	ylabel((CL(TM("Oil Production Rate/Water Production Rate"))));	


	//	subplot(2,1,2);

	//	 for(i=0;i<thePrd.DataLength;i++)
	//	  {
	//		  year=round(thePrd.Date[i]/100);			  			  
	//		  month=mod(thePrd.Date[i],100);
	//		  //date(i+1)=datenum(year-1900,month,1);
	//		  Wcut.r(i+1)=thePrd.Wcut[i];			 			  
	//	  }
	//	 /* memcpy(x.addr(),thePrd.Date,sizeof(thePrd.DataLength*sizeof(int)));
	//      memcpy(y.addr(),thePrd.Date,sizeof(thePrd.DataLength*sizeof(float)));*/
	//	
	//	  //convert to date format
	//
	//	  //set(gcf(),TM("MenuAbout"),TM("off"));
	//	 
	//	m_hPlot=plot((CL(date),Wcut,TM("LineWidth"),4));	
	//	m_hAxis = gca();
	//	datetick('x',TM("yyyy/mm"));		
	//	set(m_hAxis,TM("color"),TM("White"));
	//	set(m_hPlot,(CL(TM("COLOR")),TM("green")));
	//	//set(m_hAxis,TM("MenuAbout"),TM("off"));

	//	xlabel((CL(TM("Date"))));
	//	ylabel((CL(TM("Water Cut"))));	
	//	//axis([date(1),date(thePrd.DataLength),0,1]);
	//	m_hAxis = gca();
	//	//set(m_hAxis,(CL(TM("Y")),(BR(0.0),1.0)));
	//	set(m_hAxis,(CL(TM("Ylim")),(BR(0.0),1.0)));
	//	//axis(TM("Manual"));
	//	//display(m_hAxis,(CL(TM("Ytick")),(BR(colon(0.0,0.2,1.0))))) );
	//	
	//	//set(m_hAxis,(CL(TM("Ytick")),(BR(colon(0.0,0.2,1.0)))));	
	//	//display( set(gca(),(CL(TM("Ytick")),colon(0.0,0.1,1.0))) );
	//	//drawnow();
	//	exitM();

	////	begin_scope
 ////   
	////	initM(MATCOM_VERSION);

	////	dMm(x); dMm(y); dMm(h_menu); dMm(h_submenu1); dMm(h_submenu2); dMm(handle); 
 //// 
	////	#line 1 "d:/matcom/sin1111.m"
	////	call_stack_begin;
	////	#line 1 "d:/matcom/sin1111.m"
	////_ x = colon(-pi,pi/10.0,pi);
	////	#line 2 "d:/matcom/sin1111.m"
	////_ y = tan(sin(x))-sin(tan(x));
	////	#line 3 "d:/matcom/sin1111.m"
	////_ display( figure((CL(1.0))) );
	////	#line 3 "d:/matcom/sin1111.m"
	////	// 创建一个图形窗
	////	#line 4 "d:/matcom/sin1111.m"
	////_ set(gcf(),(CL(TM("MenuBar")),TM("none")));
	////	#line 5 "d:/matcom/sin1111.m"
	//////_ h_menu = uimenu((CL(gcf()),TM("label"),TM("Color")));
	////	#line 5 "d:/matcom/sin1111.m"
	////	// 制作用户顶层菜单项 Color <2>
	////	#line 6 "d:/matcom/sin1111.m"
	//////_ h_submenu1 = uimenu((CL(h_menu),TM("label"),TM("Blue"),TM("callback"),TM("sin1111#0000")));
	////	#line 7 "d:/matcom/sin1111.m"
	////	//<4>
	////	#line 8 "d:/matcom/sin1111.m"
	//////_ h_submenu2 = uimenu((CL(h_menu),TM("label"),TM("Red"),TM("callback"),TM("sin1111#0001")));
	////	#line 9 "d:/matcom/sin1111.m"
	////	// % 制作下拉菜单 Red <5> <6> 

	////
 //// 
	////	#line 11 "d:/matcom/sin1111.m"
	////_ handle = plot((CL(x),y,TM("--rs"),TM("LineWidth"),3.0,TM("MarkerEdgeColor"),TM("k"),TM("MarkerFaceColor"),TM( \
	////	"g"),TM("MarkerSize"),10.0));

	////
 //// 
	////	call_stack_end;

	////	exitM();

	////	end_scope



	//	//CIPRDoc* pDoc = GetDocument();
	//	//ASSERT_VALID(pDoc);
	//	//// TODO: add draw code for native data here
	//	//if (!INIT) 
	//	//{
	//	// initM(MATCOM_VERSION);
	//	// Mm h = winaxes(m_hWnd);
	//	// axesposition(10,10,300,180);
	//	// plot((CL(magic(20+40*rand()))));
	//	// title((CL(TM("Random plot"))));
	//	// xlabel((CL(TM("This is the x axis"))));
	//	// ylabel((CL(TM("This is the y axis"))));
	//	// set(h,(CL(TM("Color")),TM("white")));
	//	// set(h,(CL(TM("Box")),TM("on")));
	//	// init=true;
	//	// }
	//	// drawnow();


}


void CIPRView::OnWctvsrecv()
{
	// TODO: 在此添加命令处理程序代码
	
	FIG_TYPE=3;
	OnPaint();

	
	 //   initM(MATCOM_VERSION);

		// // Mm x,s,c;
		//  Mm m_hPlot;//figure handle
		//  Mm m_hAxis;//坐标轴句柄
		//  Mm m_axispos;//坐标轴范围
		//  Mm m_hXlabel,m_hYlabel,m_hTitle;//x轴，y轴和标题句柄


		//  Mm Cum_Oil_P,Wcut;


		//  int i;


	 //     Cum_Oil_P=zeros(1,thePrd.DataLength);		 
		//  Wcut=zeros(1,thePrd.DataLength);		  
		//  
		//  for(i=0;i<thePrd.DataLength;i++)
		//  {
		//	  Wcut.r(i+1)=thePrd.Wcut[i];
		//	  Cum_Oil_P.r(i+1)=thePrd.Cum_oil[i]/thePrd.Reserve_Oil;	  
		//	  
		//  }
		// /* memcpy(x.addr(),thePrd.Date,sizeof(thePrd.DataLength*sizeof(int)));
	 //     memcpy(y.addr(),thePrd.Date,sizeof(thePrd.DataLength*sizeof(float)));*/
		//
		//  //convert to date format
	
		//  //set(gcf(),TM("MenuAbout"),TM("off"));
		//set(m_hAxis,TM("MenuAbout"),TM("off")); 

		//m_hPlot=plot((CL(Cum_Oil_P),Wcut,TM("LineWidth"),4,TM("COLOR"),TM("red")));	
		//
		////datetick('x',TM("yyyy/mm"));	
		//m_hAxis = gca();
		////set(m_hPlot,(CL(TM("COLOR")),TM("red")));
		////set(gcf(),TM("IconFile"),TM("IPR.ico"));

		//set(m_hAxis,TM("color"),TM("White"));
		//m_hAxis = gca();

		////set(m_hAxis,(CL(TM("Y")),(BR(0.0),1.0)));
		//set(m_hAxis,(CL(TM("Ylim")),(BR(0.0),1.0)));
		//set(m_hAxis,(CL(TM("Xlim")),(BR(0.0),1.0)));

		//ylabel((CL(TM("Wcut"))));
		//xlabel((CL(TM("Cumulative Oil Production"))));	

		//exitM();


}


void CIPRView::OnCumlqdvswct()
{
	// TODO: 在此添加命令处理程序代码
	
	FIG_TYPE=4;
	OnPaint();

	 //   initM(MATCOM_VERSION);

		// // Mm x,s,c;
		//  Mm m_hPlot;//figure handle
		//  Mm m_hAxis;//坐标轴句柄
		//  Mm m_axispos;//坐标轴范围
		//  Mm m_hXlabel,m_hYlabel,m_hTitle;//x轴，y轴和标题句柄


		//  Mm Cum_LQD_P,Wcut;


		//  int i;


	 //     Cum_LQD_P=zeros(1,thePrd.DataLength);		 
		//  Wcut=zeros(1,thePrd.DataLength);		  
		//  
		//  for(i=0;i<thePrd.DataLength;i++)
		//  {
		//	  Wcut.r(i+1)=thePrd.Wcut[i];
		//	  Cum_LQD_P.r(i+1)=thePrd.Cum_oil[i]/thePrd.Reserve_Oil+thePrd.Cum_Wt_P[i]/thePrd.Reserve_Oil;	  
		//	  
		//  }
		// /* memcpy(x.addr(),thePrd.Date,sizeof(thePrd.DataLength*sizeof(int)));
	 //     memcpy(y.addr(),thePrd.Date,sizeof(thePrd.DataLength*sizeof(float)));*/
		//
		//  //convert to date format
	
		//  //set(gcf(),TM("MenuAbout"),TM("off"));
		//set(m_hAxis,TM("MenuAbout"),TM("off")); 

		//m_hPlot=plot((CL(Cum_LQD_P),Wcut,TM("LineWidth"),4,TM("COLOR"),TM("red")));	
		//
		////datetick('x',TM("yyyy/mm"));	
		//m_hAxis = gca();
		////set(m_hPlot,(CL(TM("COLOR")),TM("red")));
		////set(gcf(),TM("IconFile"),TM("IPR.ico"));

		//set(m_hAxis,TM("color"),TM("White"));
		//m_hAxis = gca();

		////set(m_hAxis,(CL(TM("Y")),(BR(0.0),1.0)));
		//set(m_hAxis,(CL(TM("Ylim")),(BR(0.0),1.0)));
		////set(m_hAxis,(CL(TM("Ylim")),(BR(0.0),1.0)));

		//ylabel((CL(TM("Wcut"))));
		//xlabel((CL(TM("Cumulative liquid Production"))));	

		//exitM();
}


void CIPRView::OnWatindx()
{
	// TODO: 在此添加命令处理程序代码
	//
	
	FIG_TYPE=6;
	OnPaint();
	//initM(MATCOM_VERSION);

	//	 // Mm x,s,c;
	//	  Mm m_hPlot;//figure handle
	//	  Mm m_hAxis;//坐标轴句柄
	//	  Mm m_axispos;//坐标轴范围
	//	  Mm m_hXlabel,m_hYlabel,m_hTitle;//x轴，y轴和标题句柄


	//	  Mm Watindx,date;
	//	  Mm maxindx;
	//	  int i,year,month;

	//      Watindx=zeros(1,thePrd.DataLength);	 

	//	 for(i=0;i<thePrd.DataLength;i++)
	//	  {
	//		  year=round(thePrd.Date[i]/100);			  			  
	//		  month=mod(thePrd.Date[i],100);
	//		  date(i+1)=datenum(year-1900,month,1);
	//		  Watindx.r(i+1)=(thePrd.Cum_Wt_I[i]-thePrd.Cum_Wt_P[i])/thePrd.Reserve_Oil;			 			  
	//	  }
	//	 /* memcpy(x.addr(),thePrd.Date,sizeof(thePrd.DataLength*sizeof(int)));
	//      memcpy(y.addr(),thePrd.Date,sizeof(thePrd.DataLength*sizeof(float)));*/
	//	
	//	  //convert to date format
	//
	//	  //set(gcf(),TM("MenuAbout"),TM("off"));
	//	 
	//	m_hPlot=plot((CL(date),Watindx,TM("LineWidth"),4));	
	//	m_hAxis = gca();
	//	datetick('x',TM("yyyy/mm"));		
	//	set(m_hAxis,TM("color"),TM("White"));
	//	set(m_hPlot,(CL(TM("COLOR")),TM("blue")));
	//	//set(m_hAxis,TM("MenuAbout"),TM("off"));

	//	xlabel((CL(TM("Date"))));
	//	ylabel((CL(TM("Water Flooding Index"))));	
	//	maxindx=max(Watindx);
	//	m_hAxis = gca();
	//	set(m_hAxis,(CL(TM("Ylim")),(BR(0.0),(int)maxindx.r(1)+0.5)));
	//	//axis([date(1),date(thePrd.DataLength),0,1]);

	//	drawnow();
	//	exitM();

}


void CIPRView::OnWctRecRatio()
{
	// TODO: 在此添加命令处理程序代码

	
	FIG_TYPE=7;
	OnPaint();

	 //   initM(MATCOM_VERSION);

		// // Mm x,s,c;
		//  Mm m_hPlot;//figure handle
		//  Mm m_hAxis;//坐标轴句柄
		//  Mm m_axispos;//坐标轴范围
		//  Mm m_hXlabel,m_hYlabel,m_hTitle;//x轴，y轴和标题句柄


		//  Mm date,Wct_Cum,Wcut;
		//  int year,month;
		//  float p;
		//  int i;

		//  date=zeros(1,thePrd.DataLength);	     
		//  Wct_Cum=zeros(1,thePrd.DataLength);
		//  Wcut=zeros(1,thePrd.DataLength);	

		//  i=0;
		//  year=round(thePrd.Date[i]/100);			  			  
		//  month=mod(thePrd.Date[i],100);
		//  date(i+1)=datenum(year-1900,month,1);
		//  Wct_Cum.r(i+1)=0;
		//  Wcut.r(i+1)=0;		  
		//  for(i=1;i<thePrd.DataLength;i++)
		//  {
		//	  year=round(thePrd.Date[i]/100);			  			  
		//	  month=mod(thePrd.Date[i],100);
		//	  date(i+1)=datenum(year-1900,month,1);
		//	  Wct_Cum.r(i+1)=thePrd.Cum_Wt_P[i]/(thePrd.Cum_oil[i]+thePrd.Cum_Wt_P[i])/(thePrd.Cum_oil[i]/thePrd.Reserve_Oil);
		//	  Wcut.r(i+1)=thePrd.Wcut[i]/(thePrd.Cum_oil[i]/thePrd.Reserve_Oil);
		//	  
		//  }
		// /* memcpy(x.addr(),thePrd.Date,sizeof(thePrd.DataLength*sizeof(int)));
	 //     memcpy(y.addr(),thePrd.Date,sizeof(thePrd.DataLength*sizeof(float)));*/
		//
		//  //convert to date format
	
		//  //set(gcf(),TM("MenuAbout"),TM("off"));
		//set(m_hAxis,TM("MenuAbout"),TM("off")); 

		//m_hPlot=plot((CL(date),Wct_Cum,TM("LineWidth"),4,TM("COLOR"),TM("green")));	
		//datetick('x',TM("yyyy/mm"));		
		//hold();
		//m_hPlot=plot((CL(date),Wcut,TM("LineWidth"),4,TM("COLOR"),TM("blue")));	
		//m_hAxis = gca();
		////set(m_hPlot,(CL(TM("COLOR")),TM("red")));
		////set(gcf(),TM("IconFile"),TM("IPR.ico"));

		//set(m_hAxis,TM("color"),TM("White"));
		//xlabel((CL(TM("Date"))));
		//ylabel((CL(TM(" "))));	
		//		
		//drawnow();
		//exitM();

}


void CIPRView::OnResidwat()
{
	// TODO: 在此添加命令处理程序代码
	
	FIG_TYPE=5;
	OnPaint();

	//	  initM(MATCOM_VERSION);

	//	 // Mm x,s,c;
	//	  Mm m_hPlot;//figure handle
	//	  Mm m_hAxis;//坐标轴句柄
	//	  Mm m_axispos;//坐标轴范围
	//	  Mm m_hXlabel,m_hYlabel,m_hTitle;//x轴，y轴和标题句柄


	//	  Mm date,Wat_Resi;
	//	  int year,month;
	//	  float p;
	//	  int i;

	//	  date=zeros(1,thePrd.DataLength);	     
	//	  Wat_Resi=zeros(1,thePrd.DataLength);
	//

	//	  i=0;
	//	  year=round(thePrd.Date[i]/100);			  			  
	//	  month=mod(thePrd.Date[i],100);
	//	  date(i+1)=datenum(year-1900,month,1);
	//	  Wat_Resi.r(i+1)=0;
	//	  		  
	//	  for(i=1;i<thePrd.DataLength;i++)
	//	  {
	//		  year=round(thePrd.Date[i]/100);			  			  
	//		  month=mod(thePrd.Date[i],100);
	//		  date(i+1)=datenum(year-1900,month,1);
	//		  Wat_Resi.r(i+1)=(thePrd.Cum_Wt_I[i]-thePrd.Cum_Wt_P[i])/thePrd.Cum_Wt_I[i];			  
	//	  }
	//	  Wat_Resi.r(1)=Wat_Resi.r(2);

	//	 /* memcpy(x.addr(),thePrd.Date,sizeof(thePrd.DataLength*sizeof(int)));
	//      memcpy(y.addr(),thePrd.Date,sizeof(thePrd.DataLength*sizeof(float)));*/
	//	
	//	  //convert to date format
	//
	//	  //set(gcf(),TM("MenuAbout"),TM("off"));
	//	m_hPlot=plot((CL(date),Wat_Resi,TM("LineWidth"),4,TM("COLOR"),TM("green")));	
	//	m_hAxis = gca();
	//	set(m_hAxis,TM("MenuAbout"),TM("off")); 
	//	set(m_hAxis,(CL(TM("Ylim")),(BR(0.0),1)));
	//	//set(m_hAxis,(CL(TM("YTick")),colon(0.0,0.25,1.0)));
	//	//set(m_hAxis,(CL(TM("YTickLabel")),(CL(TM("0")),TM("0.25"),TM("0.5"),TM("0.75"),TM("1"))));

	//	set(m_hAxis,(CL(TM("Xlim")),(BR(date(1)),date(thePrd.DataLength))));


	//	datetick('x',TM("yyyy/mm"));
	//	//set(gcf(),(CL(TM("MenuBar")),TM("none")));
	//	

	//	m_hAxis = gca();
	//	set(m_hAxis,TM("color"),TM("White"));
	//	xlabel((CL(TM("Date"))));
	//	ylabel((CL(TM("Residual Water"))));	

	//	set(m_hAxis,(CL(TM("Xgrid")),TM("on")));
	//	set(m_hAxis,(CL(TM("Ygrid")),TM("on")));
	//	

	///*	set(m_hAxis,(CL(TM("Ystick")),(BR(0.0),0.25,0.5,0.75,1)));
	//	set(m_hAxis,(CL(TM("Ylabel")),(BR(0.0),0.25,0.5,0.75,1)));*/

	//	//print();
	//	//hgexport(figure_handle,'-clipboard');



	//	drawnow();
	//	exitM();

}


void CIPRView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CView::OnPaint()
			int wmId, wmEvent;
			PAINTSTRUCT ps;
			HDC hdc;
			RECT r;
			int s, p;
			int date_x;
			float f,fX,fY; 
			int nTypes[] = {PELT_MEDIUMSOLID, PELT_MEDIUMSOLID};  
			int nPTypes[] = { PEPT_DOTSOLID, PEPT_PLUS };  
			DWORD dwArray[2] = { PERGB(128, 198,0,0), PERGB(128, 0, 198, 0) };  
			DWORD COLOR_WCUT={PERGB(0,0,255,0)};
			DWORD COLOR_WCUT1={PERGB(0,191,255,0)};
			DWORD COLOR_RESIWAT={PERGB(127,255,212,0)};




			//童氏模板图标属性
			int nTypes_T[]={PELT_MEDIUMSOLID, PELT_MEDIUMSOLID,PELT_MEDIUMSOLID,PELT_MEDIUMSOLID,PELT_MEDIUMSOLID,PELT_MEDIUMSOLID,PELT_MEDIUMSOLID,
			PELT_MEDIUMSOLID,PELT_MEDIUMSOLID,PELT_THICKDOT};			
			int nPTypes_T[] = { PEPT_DOTSOLID, PEPT_DOTSOLID, PEPT_DOTSOLID, PEPT_DOTSOLID, PEPT_DOTSOLID, PEPT_DOTSOLID, PEPT_DOTSOLID, PEPT_DOTSOLID
			, PEPT_DOTSOLID, PEPT_SQUARE};  
			DWORD dwArray_T[] = { PERGB(128, 198,0,0), PERGB(128, 198,0,0), PERGB(128, 198,0,0),PERGB(128, 198,0,0),PERGB(128, 198,0,0),PERGB(128, 198,0,0),
			PERGB(128, 198,0,0),PERGB(128, 198,0,0),PERGB(128, 198,0,0),PERGB(128, 198,0,0)};  
			//最大值和最小值设定
			double dmax_x=0,dmax_y=0;
			double dmin_x=0.0F;
			double dmin_y=0;
			
			int nArray[8];
			TCHAR buff_Date[10];

			HWND hWnd;		


	switch(FIG_TYPE)
	{
		case 1:						

			hWnd=::GetActiveWindow();
			::GetClientRect(hWnd, &r);
			hPE = PEcreate(PECONTROL_GRAPH, 0, &r, hWnd, 1001);
			
			/*PEreinitialize(hPE);*/

			//// Version 4.0 Features //
		 //  PEnset(hPE, PEP_bFIXEDFONTS, TRUE);
		 //  PEnset(hPE, PEP_bSIMPLEPOINTLEGEND, TRUE);
		 //  PEnset(hPE, PEP_bSIMPLELINELEGEND, TRUE);
		 //  PEnset(hPE, PEP_nLEGENDSTYLE, PELS_1_LINE);
		 //  PEnset(hPE, PEP_nMULTIAXISSTYLE, PEMAS_SEPARATE_AXES);



			PEnset(hPE, PEP_bPREPAREIMAGES, TRUE);
			PEnset(hPE, PEP_nSUBSETS, 2);
			PEnset(hPE, PEP_nPOINTS, thePrd.DataLength);

			//FIG_TYPE=1;

			//enable set min and max
			//PEnset(hPE, PEP_nMANUALSCALECONTROLY, PEMSC_MINMAX);
			//
			//PEvset(hPE, PEP_fMANUALMINY, &dmin, 0);
			//PEvset(hPE, PEP_fMANUALMAXY, &dmax, 0);
			//PEvset(hPE, PEP_fMANUALMINY, &dmin, 1);
			//PEvset(hPE, PEP_fMANUALMAXY, &dmax, 1); 
			// Set draw pattern (point plus line)
			PEnset(hPE, PEP_nPLOTTINGMETHODII, PEGPM_POINTSPLUSLINE);
			PEnset(hPE, PEP_nPLOTTINGMETHOD, PEGPM_POINTSPLUSLINE);  
			
			PEvset(hPE, PEP_naSUBSETLINETYPES, nTypes, 2);  //define line type
			PEvset(hPE, PEP_naSUBSETPOINTTYPES, nTypes, 2); 
			PEvset( hPE, PEP_dwaSUBSETCOLORS, dwArray, 2); //define line color

			// set second subset on right y axis.
			//PEnset(hPE, PEP_nRYAXISCOMPARISONSUBSETS, 1);
			//PEnset(hPE, PEP_nPLOTTINGMETHODII, PEGPM_LINE);
			//PEnset(hPE, PEP_nRYAXISCOMPARISONSUBSETS, );

			PEszset(hPE, PEP_szMAINTITLE, TEXT("产油量与产水量曲线"));
			PEszset(hPE, PEP_szSUBTITLE, TEXT(""));
			PEszset(hPE, PEP_szYAXISLABEL, TEXT("产量（104）"));
			PEszset(hPE, PEP_szXAXISLABEL, TEXT(""));

			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 0, TEXT("产油量"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 1, TEXT("产水量"));//define subtitle name;

			PEnset(hPE, PEP_bBITMAPGRADIENTMODE, TRUE);
			//PEnset(hPE, PEP_nQUICKSTYLE, PEQS_MEDIUM_NO_BORDER);
			PEnset(hPE, PEP_nQUICKSTYLE, PEQS_LIGHT_SHADOW);

			PEnset(hPE, PEP_bFIXEDFONTS, TRUE);
			PEnset(hPE, PEP_nLEGENDSTYLE, PELS_1_LINE_INSIDE_AXIS);
		

			for (s=0; s<2; s++)
			{
				if(s==0)
				{
					for( int p=0; p<thePrd.DataLength; p++ )
					{										  
						////fX = ((float) (p+1)) * 100.0F + ((float) rand()) / 50.0F;
						//date_x= thePrd.Date[p];
						//PEvsetcellEx (hPE, PEP_faXDATA, s, p, &thePrd.Date[p]);
						////fY = ((float) (p+1) * 1.0F) + rand() + 700.0F - ((float) (s * 140.0F)) + ((float) rand()) / 250.0F;
						fY=thePrd.Oil_P[p];
						PEvsetcellEx (hPE, PEP_faYDATA, s, p, &fY);
					}
				}
				else
				{
					for( int p=0; p<thePrd.DataLength; p++ )
					{										  
						//fX = ((float) (p+1)) * 100.0F + ((float) rand()) / 50.0F;
						//fX= thePrd.Date[p];
						//PEvsetcellEx (hPE, PEP_faXDATA, s, p, &thePrd.Date[p]);
						////fY = ((float) (p+1) * 1.0F) + rand() + 700.0F - ((float) (s * 140.0F)) + ((float) rand()) / 250.0F;
						fY=thePrd.Wat_P[p];
						PEvsetcellEx (hPE, PEP_faYDATA, s, p, &fY);
					}

				}
			}



			//设置曲线的类型
			//PEnset(hPE, PEP_nPLOTTINGMETHOD, PEGPM_BAR);						


			// Improves metafile export //
			PEnset(hPE, PEP_nDPIX, 600);
			PEnset(hPE, PEP_nDPIY, 600);
		/*	for( int p=0; p<thePrd.DataLength; p++ )
			
			{
				if(p%(int(thePrd.DataLength/10))==0)
					PEvsetcell(hPE, PEP_szaPOINTLABELS, 0, TEXT("1"));
			}
*/

			
			//for( int p=0; p<thePrd.DataLength; p++ )
			//
			//{
			//	itoa(thePrd.Date[p],buff_Date,10);				
			//	PEvsetcell(hPE, PEP_szaPOINTLABELS, p, buff_Date);
			//}

		
			
			for( int p=0; p<thePrd.DataLength; p++ )
			
			{
				//itoa(thePrd.Date[p],buff_Date,10);	
				_itow_s(thePrd.Date[p],buff_Date,10);
				//PEvsetcell(hPE, PEP_szaPOINTLABELS, p, (TCHAR*)buff_Date);
				PEvsetcell(hPE, PEP_szaPOINTLABELS, p, buff_Date);
			}

			nArray[0] = 1;
			nArray[1] = thePrd.DataLength/10;
			nArray[2] = thePrd.DataLength/10*2;
			nArray[3] = thePrd.DataLength/10*3;
			nArray[4] = thePrd.DataLength/10*4;
			nArray[5] = thePrd.DataLength/10*5;
			nArray[6] = thePrd.DataLength/10*6;
			nArray[7] = thePrd.DataLength/10*7;

			PEvset (hPE, PEP_naALTFREQUENCIES, nArray, 8);


			       
			//// Enable Plotting style gradient and bevel features //
			//PEnset(hPE, PEP_nAREAGRADIENTSTYLE,  PEPGS_RADIAL_BOTTOM_RIGHT);
			//PEnset(hPE, PEP_nAREABEVELSTYLE, PEBS_MEDIUM_SMOOTH);
			//PEnset(hPE, PEP_nSPLINEGRADIENTSTYLE,  PEPGS_RADIAL_BOTTOM_RIGHT);
			//PEnset(hPE, PEP_nSPLINEBEVELSTYLE, PESBS_MEDIUM_SMOOTH);

			PEresetimage(hPE, 0, 0);

			break;
		case 2: //含水曲线

									
			hWnd=::GetActiveWindow();
			::GetClientRect(hWnd, &r);
			hPE = PEcreate(PECONTROL_GRAPH, 0, &r, hWnd, 1001);
			
			/*PEreinitialize(hPE);*/

			//// Version 4.0 Features //
		 //  PEnset(hPE, PEP_bFIXEDFONTS, TRUE);
		 //  PEnset(hPE, PEP_bSIMPLEPOINTLEGEND, TRUE);
		 //  PEnset(hPE, PEP_bSIMPLELINELEGEND, TRUE);
		 //  PEnset(hPE, PEP_nLEGENDSTYLE, PELS_1_LINE);
		 //  PEnset(hPE, PEP_nMULTIAXISSTYLE, PEMAS_SEPARATE_AXES);



			PEnset(hPE, PEP_bPREPAREIMAGES, TRUE);
			PEnset(hPE, PEP_nSUBSETS, 1);
			PEnset(hPE, PEP_nPOINTS, thePrd.DataLength);

			//FIG_TYPE=1;

			//enable set min and max
			//PEnset(hPE, PEP_nMANUALSCALECONTROLY, PEMSC_MINMAX);
			//
			//PEvset(hPE, PEP_fMANUALMINY, &dmin, 0);
			//PEvset(hPE, PEP_fMANUALMAXY, &dmax, 0);
			//PEvset(hPE, PEP_fMANUALMINY, &dmin, 1);
			//PEvset(hPE, PEP_fMANUALMAXY, &dmax, 1); 
			// Set draw pattern (point plus line)
			PEnset(hPE, PEP_nPLOTTINGMETHODII, PEGPM_POINTSPLUSLINE);
			PEnset(hPE, PEP_nPLOTTINGMETHOD, PEGPM_POINTSPLUSLINE);  
			
			PEvset(hPE, PEP_naSUBSETLINETYPES, nTypes, 1);  //define line type
			PEvset(hPE, PEP_naSUBSETPOINTTYPES, nTypes, 1); 
			PEvset( hPE, PEP_dwaSUBSETCOLORS, &COLOR_WCUT ,1); //define line color

			// set second subset on right y axis.
			//PEnset(hPE, PEP_nRYAXISCOMPARISONSUBSETS, 1);
			//PEnset(hPE, PEP_nPLOTTINGMETHODII, PEGPM_LINE);
			//PEnset(hPE, PEP_nRYAXISCOMPARISONSUBSETS, );

			PEszset(hPE, PEP_szMAINTITLE, TEXT("含水变化曲线"));
			PEszset(hPE, PEP_szSUBTITLE, TEXT(""));
			PEszset(hPE, PEP_szYAXISLABEL, TEXT("含水"));
			PEszset(hPE, PEP_szXAXISLABEL, TEXT(""));

			//PEvsetcell(hPE, PEP_szaSUBSETLABELS, 0, TEXT("产油量"));//define subtitle name;
			//PEvsetcell(hPE, PEP_szaSUBSETLABELS, 1, TEXT("产水量"));//define subtitle name;

			PEnset(hPE, PEP_bBITMAPGRADIENTMODE, TRUE);
			//PEnset(hPE, PEP_nQUICKSTYLE, PEQS_MEDIUM_NO_BORDER);
			PEnset(hPE, PEP_nQUICKSTYLE, PEQS_LIGHT_SHADOW);

			PEnset(hPE, PEP_bFIXEDFONTS, TRUE);
			PEnset(hPE, PEP_nLEGENDSTYLE, PELS_1_LINE_INSIDE_AXIS);


			//set max range of y and x;
			PEnset(hPE, PEP_nMANUALSCALECONTROLY, PEMSC_MINMAX);				
			dmax_x=1;
			dmin_x=0;
			PEvset(hPE, PEP_fMANUALMINY, &dmin_x, 0);
			PEvset(hPE, PEP_fMANUALMAXY, &dmax_x, 0); 
			//PEvset(hPE, PEP_fMANUALMINX, &dmin, 0);
			//PEvset(hPE, PEP_fMANUALMAXX, &dmax, 0); 

			
			for( int p=0; p<thePrd.DataLength; p++ )
			{										  
				////fX = ((float) (p+1)) * 100.0F + ((float) rand()) / 50.0F;
				//date_x= thePrd.Date[p];
				//PEvsetcellEx (hPE, PEP_faXDATA, s, p, &thePrd.Date[p]);
				////fY = ((float) (p+1) * 1.0F) + rand() + 700.0F - ((float) (s * 140.0F)) + ((float) rand()) / 250.0F;
				fY=thePrd.Wcut[p];
				PEvsetcellEx (hPE, PEP_faYDATA, 0,p, &fY);
			}

			//设置曲线的类型
			//PEnset(hPE, PEP_nPLOTTINGMETHOD, PEGPM_BAR);						


			// Improves metafile export //
			PEnset(hPE, PEP_nDPIX, 600);
			PEnset(hPE, PEP_nDPIY, 600);
		/*	for( int p=0; p<thePrd.DataLength; p++ )
			
			{
				if(p%(int(thePrd.DataLength/10))==0)
					PEvsetcell(hPE, PEP_szaPOINTLABELS, 0, TEXT("1"));
			}
*/

			
			//for( int p=0; p<thePrd.DataLength; p++ )
			//
			//{
			//	itoa(thePrd.Date[p],buff_Date,10);				
			//	PEvsetcell(hPE, PEP_szaPOINTLABELS, p, buff_Date);
			//}

		
			
			for( int p=0; p<thePrd.DataLength; p++ )
			
			{
				//itoa(thePrd.Date[p],buff_Date,10);	
				_itow_s(thePrd.Date[p],buff_Date,10);
				//PEvsetcell(hPE, PEP_szaPOINTLABELS, p, (TCHAR*)buff_Date);
				PEvsetcell(hPE, PEP_szaPOINTLABELS, p, buff_Date);
			}

			nArray[0] = 1;
			nArray[1] = thePrd.DataLength/10;
			nArray[2] = thePrd.DataLength/10*2;
			nArray[3] = thePrd.DataLength/10*3;
			nArray[4] = thePrd.DataLength/10*4;
			nArray[5] = thePrd.DataLength/10*5;
			nArray[6] = thePrd.DataLength/10*6;
			nArray[7] = thePrd.DataLength/10*7;

			PEvset (hPE, PEP_naALTFREQUENCIES, nArray, 8);


			       
			//// Enable Plotting style gradient and bevel features //
			//PEnset(hPE, PEP_nAREAGRADIENTSTYLE,  PEPGS_RADIAL_BOTTOM_RIGHT);
			//PEnset(hPE, PEP_nAREABEVELSTYLE, PEBS_MEDIUM_SMOOTH);
			//PEnset(hPE, PEP_nSPLINEGRADIENTSTYLE,  PEPGS_RADIAL_BOTTOM_RIGHT);
			//PEnset(hPE, PEP_nSPLINEBEVELSTYLE, PESBS_MEDIUM_SMOOTH);

			PEresetimage(hPE, 0, 0);
			break;


		case 3:

			hWnd=::GetActiveWindow();
			::GetClientRect(hWnd, &r);
			hPE = PEcreate(PECONTROL_SGRAPH, 0, &r, hWnd, 1001);		


			PEnset(hPE, PEP_bPREPAREIMAGES, TRUE);
			PEnset(hPE, PEP_nSUBSETS, 1);
			PEnset(hPE, PEP_nPOINTS, thePrd.DataLength);

			//FIG_TYPE=1;

			//enable set min and max
			//PEnset(hPE, PEP_nMANUALSCALECONTROLY, PEMSC_MINMAX);
			//
			//PEvset(hPE, PEP_fMANUALMINY, &dmin, 0);
			//PEvset(hPE, PEP_fMANUALMAXY, &dmax, 0);
			//PEvset(hPE, PEP_fMANUALMINY, &dmin, 1);
			//PEvset(hPE, PEP_fMANUALMAXY, &dmax, 1); 
			// Set draw pattern (point plus line)
			PEnset(hPE, PEP_nPLOTTINGMETHODII, PEGPM_POINTSPLUSLINE);
			PEnset(hPE, PEP_nPLOTTINGMETHOD, PEGPM_POINTSPLUSLINE);  
			
			PEvset(hPE, PEP_naSUBSETLINETYPES, nTypes, 1);  //define line type
			PEvset(hPE, PEP_naSUBSETPOINTTYPES, nTypes, 1); 
			PEvset( hPE, PEP_dwaSUBSETCOLORS, &COLOR_WCUT1, 1); //define line color


			// set second subset on right y axis.
			//PEnset(hPE, PEP_nRYAXISCOMPARISONSUBSETS, 1);
			//PEnset(hPE, PEP_nPLOTTINGMETHODII, PEGPM_LINE);
			//PEnset(hPE, PEP_nRYAXISCOMPARISONSUBSETS, );

			PEszset(hPE, PEP_szMAINTITLE, TEXT("含水VS采出程度"));
			PEszset(hPE, PEP_szSUBTITLE, TEXT(""));
			PEszset(hPE, PEP_szYAXISLABEL, TEXT("含水"));
			PEszset(hPE, PEP_szXAXISLABEL, TEXT("采出程度"));

			//PEvsetcell(hPE, PEP_szaSUBSETLABELS, 0, TEXT("产油量"));//define subtitle name;
			//PEvsetcell(hPE, PEP_szaSUBSETLABELS, 1, TEXT("产水量"));//define subtitle name;

			PEnset(hPE, PEP_bBITMAPGRADIENTMODE, TRUE);
			//PEnset(hPE, PEP_nQUICKSTYLE, PEQS_MEDIUM_NO_BORDER);
			PEnset(hPE, PEP_nQUICKSTYLE, PEQS_LIGHT_SHADOW);

			PEnset(hPE, PEP_bFIXEDFONTS, TRUE);
			PEnset(hPE, PEP_nLEGENDSTYLE, PELS_1_LINE_INSIDE_AXIS);
						
			//set max range of y and x;
			PEnset(hPE, PEP_nMANUALSCALECONTROLY, PEMSC_MINMAX);		
			PEnset(hPE, PEP_nMANUALSCALECONTROLX, PEMSC_MINMAX);	
			dmin_x=0;
			dmax_x=1;
			dmin_y=0;
			dmax_y=1;
			PEvset(hPE, PEP_fMANUALMINX, &dmin_x, 0);
			PEvset(hPE, PEP_fMANUALMAXX, &dmax_x, 0); 
			PEvset(hPE, PEP_fMANUALMINY, &dmin_y, 0);
			PEvset(hPE, PEP_fMANUALMAXY, &dmax_y, 0); 


			
			for( int p=0; p<thePrd.DataLength; p++ )
			{										  
				////fX = ((float) (p+1)) * 100.0F + ((float) rand()) / 50.0F;
				//date_x= thePrd.Date[p];
				//PEvsetcellEx (hPE, PEP_faXDATA, s, p, &thePrd.Date[p]);
				////fY = ((float) (p+1) * 1.0F) + rand() + 700.0F - ((float) (s * 140.0F)) + ((float) rand()) / 250.0F;
				
				fX=thePrd.Cum_oil[p]/thePrd.Reserve_Oil;
				PEvsetcellEx (hPE, PEP_faXDATA, 0,p, &fX);
				fY=thePrd.Wcut[p];
				PEvsetcellEx (hPE, PEP_faYDATA, 0,p, &fY);
			}

			//设置曲线的类型
			//PEnset(hPE, PEP_nPLOTTINGMETHOD, PEGPM_BAR);						


			// Improves metafile export //
			PEnset(hPE, PEP_nDPIX, 600);
			PEnset(hPE, PEP_nDPIY, 600);
		/*	for( int p=0; p<thePrd.DataLength; p++ )
			
			{
				if(p%(int(thePrd.DataLength/10))==0)
					PEvsetcell(hPE, PEP_szaPOINTLABELS, 0, TEXT("1"));
			}
*/

			
			//for( int p=0; p<thePrd.DataLength; p++ )
			//
			//{
			//	itoa(thePrd.Date[p],buff_Date,10);				
			//	PEvsetcell(hPE, PEP_szaPOINTLABELS, p, buff_Date);
			//}

		
			
			//for( int p=0; p<thePrd.DataLength; p++ )
			//
			//{
			//	//itoa(thePrd.Date[p],buff_Date,10);	
			//	_itow_s(thePrd.Date[p],buff_Date,10);
			//	//PEvsetcell(hPE, PEP_szaPOINTLABELS, p, (TCHAR*)buff_Date);
			//	PEvsetcell(hPE, PEP_szaPOINTLABELS, p, buff_Date);
			//}

			//nArray[0] = 1;
			//nArray[1] = thePrd.DataLength/10;
			//nArray[2] = thePrd.DataLength/10*2;
			//nArray[3] = thePrd.DataLength/10*3;
			//nArray[4] = thePrd.DataLength/10*4;
			//nArray[5] = thePrd.DataLength/10*5;
			//nArray[6] = thePrd.DataLength/10*6;
			//nArray[7] = thePrd.DataLength/10*7;

			//PEvset (hPE, PEP_naALTFREQUENCIES, nArray, 8);


			       
			//// Enable Plotting style gradient and bevel features //
			//PEnset(hPE, PEP_nAREAGRADIENTSTYLE,  PEPGS_RADIAL_BOTTOM_RIGHT);
			//PEnset(hPE, PEP_nAREABEVELSTYLE, PEBS_MEDIUM_SMOOTH);
			//PEnset(hPE, PEP_nSPLINEGRADIENTSTYLE,  PEPGS_RADIAL_BOTTOM_RIGHT);
			//PEnset(hPE, PEP_nSPLINEBEVELSTYLE, PESBS_MEDIUM_SMOOTH);

			PEresetimage(hPE, 0, 0);

			break;

		case 4:
				
			hWnd=::GetActiveWindow();
			::GetClientRect(hWnd, &r);
			hPE = PEcreate(PECONTROL_SGRAPH, 0, &r, hWnd, 1001);		


			PEnset(hPE, PEP_bPREPAREIMAGES, TRUE);
			PEnset(hPE, PEP_nSUBSETS, 1);
			PEnset(hPE, PEP_nPOINTS, thePrd.DataLength);

			//FIG_TYPE=1;

			//enable set min and max
			//PEnset(hPE, PEP_nMANUALSCALECONTROLY, PEMSC_MINMAX);
			//
			//PEvset(hPE, PEP_fMANUALMINY, &dmin, 0);
			//PEvset(hPE, PEP_fMANUALMAXY, &dmax, 0);
			//PEvset(hPE, PEP_fMANUALMINY, &dmin, 1);
			//PEvset(hPE, PEP_fMANUALMAXY, &dmax, 1); 
			// Set draw pattern (point plus line)
			PEnset(hPE, PEP_nPLOTTINGMETHODII, PEGPM_POINTSPLUSLINE);
			PEnset(hPE, PEP_nPLOTTINGMETHOD, PEGPM_POINTSPLUSLINE);  
			
			PEvset(hPE, PEP_naSUBSETLINETYPES, nTypes, 1);  //define line type
			PEvset(hPE, PEP_naSUBSETPOINTTYPES, nTypes, 1); 
			PEvset( hPE, PEP_dwaSUBSETCOLORS, &COLOR_WCUT, 1); //define line color


			// set second subset on right y axis.
			//PEnset(hPE, PEP_nRYAXISCOMPARISONSUBSETS, 1);
			//PEnset(hPE, PEP_nPLOTTINGMETHODII, PEGPM_LINE);
			//PEnset(hPE, PEP_nRYAXISCOMPARISONSUBSETS, );

			PEszset(hPE, PEP_szMAINTITLE, TEXT("含水VS累产液"));
			PEszset(hPE, PEP_szSUBTITLE, TEXT(""));
			PEszset(hPE, PEP_szYAXISLABEL, TEXT("含水"));
			PEszset(hPE, PEP_szXAXISLABEL, TEXT("累产液"));

			//PEvsetcell(hPE, PEP_szaSUBSETLABELS, 0, TEXT("产油量"));//define subtitle name;
			//PEvsetcell(hPE, PEP_szaSUBSETLABELS, 1, TEXT("产水量"));//define subtitle name;

			PEnset(hPE, PEP_bBITMAPGRADIENTMODE, TRUE);
			//PEnset(hPE, PEP_nQUICKSTYLE, PEQS_MEDIUM_NO_BORDER);
			PEnset(hPE, PEP_nQUICKSTYLE, PEQS_LIGHT_SHADOW);

			PEnset(hPE, PEP_bFIXEDFONTS, TRUE);
			PEnset(hPE, PEP_nLEGENDSTYLE, PELS_1_LINE_INSIDE_AXIS);
						
			//set max range of y and x;
			//PEnset(hPE, PEP_nMANUALSCALECONTROLY, PEMSC_MINMAX);		
			//PEnset(hPE, PEP_nMANUALSCALECONTROLX, PEMSC_MINMAX);	
			//dmin_y=0;
			//dmax_y=1;
			//dmin_x=0;
			//dmin_x=(thePrd.Cum_oil[thePrd.DataLength-1]+thePrd.Cum_Wt_P[thePrd.DataLength-1])/thePrd.Reserve_Oil+1;

			//PEvset(hPE, PEP_fMANUALMINX, &dmin_x, 0);
			//PEvset(hPE, PEP_fMANUALMAXX, &dmax_x, 0); 
			//PEvset(hPE, PEP_fMANUALMINY, &dmin_y, 0);
			//PEvset(hPE, PEP_fMANUALMAXY, &dmax_y, 0); 
			
			for( int p=0; p<thePrd.DataLength; p++ )
			{										  
				////fX = ((float) (p+1)) * 100.0F + ((float) rand()) / 50.0F;
				//date_x= thePrd.Date[p];
				//PEvsetcellEx (hPE, PEP_faXDATA, s, p, &thePrd.Date[p]);
				////fY = ((float) (p+1) * 1.0F) + rand() + 700.0F - ((float) (s * 140.0F)) + ((float) rand()) / 250.0F;
				
				fX=(thePrd.Cum_oil[p]+thePrd.Cum_Wt_P[p])/thePrd.Reserve_Oil;
				PEvsetcellEx (hPE, PEP_faXDATA, 0,p, &fX);
				fY=thePrd.Wcut[p];
				PEvsetcellEx (hPE, PEP_faYDATA, 0,p, &fY);
			}

			//设置曲线的类型
			//PEnset(hPE, PEP_nPLOTTINGMETHOD, PEGPM_BAR);						


			// Improves metafile export //
			PEnset(hPE, PEP_nDPIX, 600);
			PEnset(hPE, PEP_nDPIY, 600);
		/*	for( int p=0; p<thePrd.DataLength; p++ )
			
			{
				if(p%(int(thePrd.DataLength/10))==0)
					PEvsetcell(hPE, PEP_szaPOINTLABELS, 0, TEXT("1"));
			}
*/

			
			//for( int p=0; p<thePrd.DataLength; p++ )
			//
			//{
			//	itoa(thePrd.Date[p],buff_Date,10);				
			//	PEvsetcell(hPE, PEP_szaPOINTLABELS, p, buff_Date);
			//}

		
			
			//for( int p=0; p<thePrd.DataLength; p++ )
			//
			//{
			//	//itoa(thePrd.Date[p],buff_Date,10);	
			//	_itow_s(thePrd.Date[p],buff_Date,10);
			//	//PEvsetcell(hPE, PEP_szaPOINTLABELS, p, (TCHAR*)buff_Date);
			//	PEvsetcell(hPE, PEP_szaPOINTLABELS, p, buff_Date);
			//}

			//nArray[0] = 1;
			//nArray[1] = thePrd.DataLength/10;
			//nArray[2] = thePrd.DataLength/10*2;
			//nArray[3] = thePrd.DataLength/10*3;
			//nArray[4] = thePrd.DataLength/10*4;
			//nArray[5] = thePrd.DataLength/10*5;
			//nArray[6] = thePrd.DataLength/10*6;
			//nArray[7] = thePrd.DataLength/10*7;

			//PEvset (hPE, PEP_naALTFREQUENCIES, nArray, 8);


			       
			//// Enable Plotting style gradient and bevel features //
			//PEnset(hPE, PEP_nAREAGRADIENTSTYLE,  PEPGS_RADIAL_BOTTOM_RIGHT);
			//PEnset(hPE, PEP_nAREABEVELSTYLE, PEBS_MEDIUM_SMOOTH);
			//PEnset(hPE, PEP_nSPLINEGRADIENTSTYLE,  PEPGS_RADIAL_BOTTOM_RIGHT);
			//PEnset(hPE, PEP_nSPLINEBEVELSTYLE, PESBS_MEDIUM_SMOOTH);

			PEresetimage(hPE, 0, 0);
			break;

		case 5:

			
			hWnd=::GetActiveWindow();
			::GetClientRect(hWnd, &r);
			hPE = PEcreate(PECONTROL_GRAPH, 0, &r, hWnd, 1001);
			
			/*PEreinitialize(hPE);*/

			//// Version 4.0 Features //
		 //  PEnset(hPE, PEP_bFIXEDFONTS, TRUE);
		 //  PEnset(hPE, PEP_bSIMPLEPOINTLEGEND, TRUE);
		 //  PEnset(hPE, PEP_bSIMPLELINELEGEND, TRUE);
		 //  PEnset(hPE, PEP_nLEGENDSTYLE, PELS_1_LINE);
		 //  PEnset(hPE, PEP_nMULTIAXISSTYLE, PEMAS_SEPARATE_AXES);



			PEnset(hPE, PEP_bPREPAREIMAGES, TRUE);
			PEnset(hPE, PEP_nSUBSETS, 1);
			PEnset(hPE, PEP_nPOINTS, thePrd.DataLength);

			//FIG_TYPE=1;

			//enable set min and max
			//PEnset(hPE, PEP_nMANUALSCALECONTROLY, PEMSC_MINMAX);
			//
			//PEvset(hPE, PEP_fMANUALMINY, &dmin, 0);
			//PEvset(hPE, PEP_fMANUALMAXY, &dmax, 0);
			//PEvset(hPE, PEP_fMANUALMINY, &dmin, 1);
			//PEvset(hPE, PEP_fMANUALMAXY, &dmax, 1); 
			// Set draw pattern (point plus line)
			PEnset(hPE, PEP_nPLOTTINGMETHODII, PEGPM_POINTSPLUSLINE);
			PEnset(hPE, PEP_nPLOTTINGMETHOD, PEGPM_POINTSPLUSLINE);  
			
			PEvset(hPE, PEP_naSUBSETLINETYPES, nTypes, 1);  //define line type
			PEvset(hPE, PEP_naSUBSETPOINTTYPES, nTypes, 1); 
			PEvset( hPE, PEP_dwaSUBSETCOLORS, &COLOR_RESIWAT, 1); //define line color

			// set second subset on right y axis.
			//PEnset(hPE, PEP_nRYAXISCOMPARISONSUBSETS, 1);
			//PEnset(hPE, PEP_nPLOTTINGMETHODII, PEGPM_LINE);
			//PEnset(hPE, PEP_nRYAXISCOMPARISONSUBSETS, );

			PEszset(hPE, PEP_szMAINTITLE, TEXT("存水率曲线"));
			PEszset(hPE, PEP_szSUBTITLE, TEXT(""));
			PEszset(hPE, PEP_szYAXISLABEL, TEXT("存水率"));
			PEszset(hPE, PEP_szXAXISLABEL, TEXT(""));

			//PEvsetcell(hPE, PEP_szaSUBSETLABELS, 0, TEXT("产油量"));//define subtitle name;
			//PEvsetcell(hPE, PEP_szaSUBSETLABELS, 1, TEXT("产水量"));//define subtitle name;

			PEnset(hPE, PEP_bBITMAPGRADIENTMODE, TRUE);
			//PEnset(hPE, PEP_nQUICKSTYLE, PEQS_MEDIUM_NO_BORDER);
			PEnset(hPE, PEP_nQUICKSTYLE, PEQS_LIGHT_SHADOW);

			PEnset(hPE, PEP_bFIXEDFONTS, TRUE);
			PEnset(hPE, PEP_nLEGENDSTYLE, PELS_1_LINE_INSIDE_AXIS);


			//set max range of y and x;
			PEnset(hPE, PEP_nMANUALSCALECONTROLY, PEMSC_MINMAX);				
			dmax_y=1;
			dmin_y=0;
			PEvset(hPE, PEP_fMANUALMINY, &dmin_y, 0);
			PEvset(hPE, PEP_fMANUALMAXY, &dmax_y, 0); 
			//PEvset(hPE, PEP_fMANUALMINX, &dmin, 0);
			//PEvset(hPE, PEP_fMANUALMAXX, &dmax, 0); 

			
			for( int p=0; p<thePrd.DataLength; p++ )
			{										  
				////fX = ((float) (p+1)) * 100.0F + ((float) rand()) / 50.0F;
				//date_x= thePrd.Date[p];
				//PEvsetcellEx (hPE, PEP_faXDATA, s, p, &thePrd.Date[p]);
				////fY = ((float) (p+1) * 1.0F) + rand() + 700.0F - ((float) (s * 140.0F)) + ((float) rand()) / 250.0F;
				fY=(thePrd.Cum_Wt_I[p]-thePrd.Cum_Wt_P[p])/thePrd.Cum_Wt_I[p];
				PEvsetcellEx (hPE, PEP_faYDATA, 0,p, &fY);
			}

			//设置曲线的类型
			//PEnset(hPE, PEP_nPLOTTINGMETHOD, PEGPM_BAR);						


			// Improves metafile export //
			PEnset(hPE, PEP_nDPIX, 600);
			PEnset(hPE, PEP_nDPIY, 600);
		/*	for( int p=0; p<thePrd.DataLength; p++ )
			
			{
				if(p%(int(thePrd.DataLength/10))==0)
					PEvsetcell(hPE, PEP_szaPOINTLABELS, 0, TEXT("1"));
			}
*/

			
			//for( int p=0; p<thePrd.DataLength; p++ )
			//
			//{
			//	itoa(thePrd.Date[p],buff_Date,10);				
			//	PEvsetcell(hPE, PEP_szaPOINTLABELS, p, buff_Date);
			//}

		
			
			for( int p=0; p<thePrd.DataLength; p++ )
			
			{
				//itoa(thePrd.Date[p],buff_Date,10);	
				_itow_s(thePrd.Date[p],buff_Date,10);
				//PEvsetcell(hPE, PEP_szaPOINTLABELS, p, (TCHAR*)buff_Date);
				PEvsetcell(hPE, PEP_szaPOINTLABELS, p, buff_Date);
			}

			nArray[0] = 1;
			nArray[1] = thePrd.DataLength/10;
			nArray[2] = thePrd.DataLength/10*2;
			nArray[3] = thePrd.DataLength/10*3;
			nArray[4] = thePrd.DataLength/10*4;
			nArray[5] = thePrd.DataLength/10*5;
			nArray[6] = thePrd.DataLength/10*6;
			nArray[7] = thePrd.DataLength/10*7;

			PEvset (hPE, PEP_naALTFREQUENCIES, nArray, 8);


			       
			//// Enable Plotting style gradient and bevel features //
			//PEnset(hPE, PEP_nAREAGRADIENTSTYLE,  PEPGS_RADIAL_BOTTOM_RIGHT);
			//PEnset(hPE, PEP_nAREABEVELSTYLE, PEBS_MEDIUM_SMOOTH);
			//PEnset(hPE, PEP_nSPLINEGRADIENTSTYLE,  PEPGS_RADIAL_BOTTOM_RIGHT);
			//PEnset(hPE, PEP_nSPLINEBEVELSTYLE, PESBS_MEDIUM_SMOOTH);

			PEresetimage(hPE, 0, 0);
			break;

		case 6:

					
			hWnd=::GetActiveWindow();
			::GetClientRect(hWnd, &r);
			hPE = PEcreate(PECONTROL_GRAPH, 0, &r, hWnd, 1001);
			
			/*PEreinitialize(hPE);*/

			//// Version 4.0 Features //
		 //  PEnset(hPE, PEP_bFIXEDFONTS, TRUE);
		 //  PEnset(hPE, PEP_bSIMPLEPOINTLEGEND, TRUE);
		 //  PEnset(hPE, PEP_bSIMPLELINELEGEND, TRUE);
		 //  PEnset(hPE, PEP_nLEGENDSTYLE, PELS_1_LINE);
		 //  PEnset(hPE, PEP_nMULTIAXISSTYLE, PEMAS_SEPARATE_AXES);



			PEnset(hPE, PEP_bPREPAREIMAGES, TRUE);
			PEnset(hPE, PEP_nSUBSETS, 1);
			PEnset(hPE, PEP_nPOINTS, thePrd.DataLength);

			//FIG_TYPE=1;

			//enable set min and max
			//PEnset(hPE, PEP_nMANUALSCALECONTROLY, PEMSC_MINMAX);
			//
			//PEvset(hPE, PEP_fMANUALMINY, &dmin, 0);
			//PEvset(hPE, PEP_fMANUALMAXY, &dmax, 0);
			//PEvset(hPE, PEP_fMANUALMINY, &dmin, 1);
			//PEvset(hPE, PEP_fMANUALMAXY, &dmax, 1); 
			// Set draw pattern (point plus line)
			PEnset(hPE, PEP_nPLOTTINGMETHODII, PEGPM_POINTSPLUSLINE);
			PEnset(hPE, PEP_nPLOTTINGMETHOD, PEGPM_POINTSPLUSLINE);  
			
			PEvset(hPE, PEP_naSUBSETLINETYPES, nTypes, 1);  //define line type
			PEvset(hPE, PEP_naSUBSETPOINTTYPES, nTypes, 1); 
			PEvset( hPE, PEP_dwaSUBSETCOLORS, dwArray, 1); //define line color

			// set second subset on right y axis.
			//PEnset(hPE, PEP_nRYAXISCOMPARISONSUBSETS, 1);
			//PEnset(hPE, PEP_nPLOTTINGMETHODII, PEGPM_LINE);
			//PEnset(hPE, PEP_nRYAXISCOMPARISONSUBSETS, );

			PEszset(hPE, PEP_szMAINTITLE, TEXT("水驱指数曲线"));
			PEszset(hPE, PEP_szSUBTITLE, TEXT(""));
			PEszset(hPE, PEP_szYAXISLABEL, TEXT("水驱指数"));
			PEszset(hPE, PEP_szXAXISLABEL, TEXT(""));

			//PEvsetcell(hPE, PEP_szaSUBSETLABELS, 0, TEXT("产油量"));//define subtitle name;
			//PEvsetcell(hPE, PEP_szaSUBSETLABELS, 1, TEXT("产水量"));//define subtitle name;

			PEnset(hPE, PEP_bBITMAPGRADIENTMODE, TRUE);
			//PEnset(hPE, PEP_nQUICKSTYLE, PEQS_MEDIUM_NO_BORDER);
			PEnset(hPE, PEP_nQUICKSTYLE, PEQS_LIGHT_SHADOW);

			PEnset(hPE, PEP_bFIXEDFONTS, TRUE);
			PEnset(hPE, PEP_nLEGENDSTYLE, PELS_1_LINE_INSIDE_AXIS);




			
			for( int p=0; p<thePrd.DataLength; p++ )
			{										  
				////fX = ((float) (p+1)) * 100.0F + ((float) rand()) / 50.0F;
				//date_x= thePrd.Date[p];
				//PEvsetcellEx (hPE, PEP_faXDATA, s, p, &thePrd.Date[p]);
				////fY = ((float) (p+1) * 1.0F) + rand() + 700.0F - ((float) (s * 140.0F)) + ((float) rand()) / 250.0F;
				if(thePrd.Cum_oil[p]!=0)
					fY=(thePrd.Cum_Wt_I[p]-thePrd.Cum_Wt_P[p])/thePrd.Cum_oil[p];
				else
					fY=1;

				if(fY>dmax_y)
					dmax_y=fY;

				
				PEvsetcellEx (hPE, PEP_faYDATA, 0,p, &fY);
			}
			
			//set max range of y and x;
			PEnset(hPE, PEP_nMANUALSCALECONTROLY, PEMSC_MINMAX);				
			dmax_y=(int)(dmax_y+1);
			//dmin_y=0;
			PEvset(hPE, PEP_fMANUALMINY, &dmin_y, 0);
			PEvset(hPE, PEP_fMANUALMAXY, &dmax_y, 0); 
			////PEvset(hPE, PEP_fMANUALMINX, &dmin, 0);
			////PEvset(hPE, PEP_fMANUALMAXX, &dmax, 0); 

			//设置曲线的类型
			//PEnset(hPE, PEP_nPLOTTINGMETHOD, PEGPM_BAR);						


			// Improves metafile export //
			PEnset(hPE, PEP_nDPIX, 600);
			PEnset(hPE, PEP_nDPIY, 600);
		/*	for( int p=0; p<thePrd.DataLength; p++ )
			
			{
				if(p%(int(thePrd.DataLength/10))==0)
					PEvsetcell(hPE, PEP_szaPOINTLABELS, 0, TEXT("1"));
			}
*/

			
			//for( int p=0; p<thePrd.DataLength; p++ )
			//
			//{
			//	itoa(thePrd.Date[p],buff_Date,10);				
			//	PEvsetcell(hPE, PEP_szaPOINTLABELS, p, buff_Date);
			//}

		
			
			for( int p=0; p<thePrd.DataLength; p++ )
			
			{
				//itoa(thePrd.Date[p],buff_Date,10);	
				_itow_s(thePrd.Date[p],buff_Date,10);
				//PEvsetcell(hPE, PEP_szaPOINTLABELS, p, (TCHAR*)buff_Date);
				PEvsetcell(hPE, PEP_szaPOINTLABELS, p, buff_Date);
			}

			nArray[0] = 1;
			nArray[1] = thePrd.DataLength/10;
			nArray[2] = thePrd.DataLength/10*2;
			nArray[3] = thePrd.DataLength/10*3;
			nArray[4] = thePrd.DataLength/10*4;
			nArray[5] = thePrd.DataLength/10*5;
			nArray[6] = thePrd.DataLength/10*6;
			nArray[7] = thePrd.DataLength/10*7;

			PEvset (hPE, PEP_naALTFREQUENCIES, nArray, 8);


			       
			//// Enable Plotting style gradient and bevel features //
			//PEnset(hPE, PEP_nAREAGRADIENTSTYLE,  PEPGS_RADIAL_BOTTOM_RIGHT);
			//PEnset(hPE, PEP_nAREABEVELSTYLE, PEBS_MEDIUM_SMOOTH);
			//PEnset(hPE, PEP_nSPLINEGRADIENTSTYLE,  PEPGS_RADIAL_BOTTOM_RIGHT);
			//PEnset(hPE, PEP_nSPLINEBEVELSTYLE, PESBS_MEDIUM_SMOOTH);

			PEresetimage(hPE, 0, 0);
			break;

		case 7:
			
			hWnd=::GetActiveWindow();
			::GetClientRect(hWnd, &r);
			hPE = PEcreate(PECONTROL_GRAPH, 0, &r, hWnd, 1001);
			
			/*PEreinitialize(hPE);*/

			//// Version 4.0 Features //
		 //  PEnset(hPE, PEP_bFIXEDFONTS, TRUE);
		 //  PEnset(hPE, PEP_bSIMPLEPOINTLEGEND, TRUE);
		 //  PEnset(hPE, PEP_bSIMPLELINELEGEND, TRUE);
		 //  PEnset(hPE, PEP_nLEGENDSTYLE, PELS_1_LINE);
		 //  PEnset(hPE, PEP_nMULTIAXISSTYLE, PEMAS_SEPARATE_AXES);



			PEnset(hPE, PEP_bPREPAREIMAGES, TRUE);
			PEnset(hPE, PEP_nSUBSETS, 2);
			PEnset(hPE, PEP_nPOINTS, thePrd.DataLength);

			//FIG_TYPE=1;

			//enable set min and max
			//PEnset(hPE, PEP_nMANUALSCALECONTROLY, PEMSC_MINMAX);
			//
			//PEvset(hPE, PEP_fMANUALMINY, &dmin, 0);
			//PEvset(hPE, PEP_fMANUALMAXY, &dmax, 0);
			//PEvset(hPE, PEP_fMANUALMINY, &dmin, 1);
			//PEvset(hPE, PEP_fMANUALMAXY, &dmax, 1); 
			// Set draw pattern (point plus line)
			PEnset(hPE, PEP_nPLOTTINGMETHODII, PEGPM_POINTSPLUSLINE);
			PEnset(hPE, PEP_nPLOTTINGMETHOD, PEGPM_POINTSPLUSLINE);  
			
			PEvset(hPE, PEP_naSUBSETLINETYPES, nTypes, 2);  //define line type
			PEvset(hPE, PEP_naSUBSETPOINTTYPES, nTypes, 2); 
			PEvset( hPE, PEP_dwaSUBSETCOLORS, dwArray, 2); //define line color

			// set second subset on right y axis.
			//PEnset(hPE, PEP_nRYAXISCOMPARISONSUBSETS, 1);
			//PEnset(hPE, PEP_nPLOTTINGMETHODII, PEGPM_LINE);
			//PEnset(hPE, PEP_nRYAXISCOMPARISONSUBSETS, );

			PEszset(hPE, PEP_szMAINTITLE, TEXT("含水可采比/含水采出比"));
			PEszset(hPE, PEP_szSUBTITLE, TEXT(""));
			PEszset(hPE, PEP_szYAXISLABEL, TEXT("含水可采比/含水采出比"));
			PEszset(hPE, PEP_szXAXISLABEL, TEXT(""));

			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 0, TEXT("含水可采比"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 1, TEXT("含水采出比"));//define subtitle name;

			PEnset(hPE, PEP_bBITMAPGRADIENTMODE, TRUE);
			//PEnset(hPE, PEP_nQUICKSTYLE, PEQS_MEDIUM_NO_BORDER);
			PEnset(hPE, PEP_nQUICKSTYLE, PEQS_LIGHT_SHADOW);

			PEnset(hPE, PEP_bFIXEDFONTS, TRUE);
			PEnset(hPE, PEP_nLEGENDSTYLE, PELS_1_LINE_INSIDE_AXIS);




			
			for( int p=0; p<thePrd.DataLength; p++ )
			{										  
				////fX = ((float) (p+1)) * 100.0F + ((float) rand()) / 50.0F;
				//date_x= thePrd.Date[p];
				//PEvsetcellEx (hPE, PEP_faXDATA, s, p, &thePrd.Date[p]);
				////fY = ((float) (p+1) * 1.0F) + rand() + 700.0F - ((float) (s * 140.0F)) + ((float) rand()) / 250.0F;
				if(thePrd.Cum_oil[p]!=0)									
				{
					fY=thePrd.Wcut[p]/(thePrd.Cum_oil[p]/thePrd.Rcoverable_Rev);				
					PEvsetcellEx (hPE, PEP_faYDATA, 0,p, &fY);

					if(fY>dmax_y)
						dmax_y=fY;
				
					fY=thePrd.Wcut[p]/(thePrd.Cum_oil[p]/thePrd.Reserve_Oil);			
					PEvsetcellEx (hPE, PEP_faYDATA, 1,p, &fY);
					
					if(fY>dmax_y)
						dmax_y=fY;
				}
				else
				{
					fY=0;
					PEvsetcellEx (hPE, PEP_faYDATA, 0,p, &fY);
					PEvsetcellEx (hPE, PEP_faYDATA, 1,p, &fY);
				}

				

			}
			
			//set max range of y and x;
			PEnset(hPE, PEP_nMANUALSCALECONTROLY, PEMSC_MINMAX);				
			dmax_y=(int)(dmax_y+1);
			//dmin_y=0;
			PEvset(hPE, PEP_fMANUALMINY, &dmin_y, 0);
			PEvset(hPE, PEP_fMANUALMAXY, &dmax_y, 0); 
			////PEvset(hPE, PEP_fMANUALMINX, &dmin, 0);
			////PEvset(hPE, PEP_fMANUALMAXX, &dmax, 0); 

			//设置曲线的类型
			//PEnset(hPE, PEP_nPLOTTINGMETHOD, PEGPM_BAR);						


			// Improves metafile export //
			PEnset(hPE, PEP_nDPIX, 600);
			PEnset(hPE, PEP_nDPIY, 600);
		/*	for( int p=0; p<thePrd.DataLength; p++ )
			
			{
				if(p%(int(thePrd.DataLength/10))==0)
					PEvsetcell(hPE, PEP_szaPOINTLABELS, 0, TEXT("1"));
			}
*/

			
			//for( int p=0; p<thePrd.DataLength; p++ )
			//
			//{
			//	itoa(thePrd.Date[p],buff_Date,10);				
			//	PEvsetcell(hPE, PEP_szaPOINTLABELS, p, buff_Date);
			//}

		
			
			for( int p=0; p<thePrd.DataLength; p++ )
			
			{
				//itoa(thePrd.Date[p],buff_Date,10);	
				_itow_s(thePrd.Date[p],buff_Date,10);
				//PEvsetcell(hPE, PEP_szaPOINTLABELS, p, (TCHAR*)buff_Date);
				PEvsetcell(hPE, PEP_szaPOINTLABELS, p, buff_Date);
			}

			nArray[0] = 1;
			nArray[1] = thePrd.DataLength/10;
			nArray[2] = thePrd.DataLength/10*2;
			nArray[3] = thePrd.DataLength/10*3;
			nArray[4] = thePrd.DataLength/10*4;
			nArray[5] = thePrd.DataLength/10*5;
			nArray[6] = thePrd.DataLength/10*6;
			nArray[7] = thePrd.DataLength/10*7;

			PEvset (hPE, PEP_naALTFREQUENCIES, nArray, 8);


			       
			//// Enable Plotting style gradient and bevel features //
			//PEnset(hPE, PEP_nAREAGRADIENTSTYLE,  PEPGS_RADIAL_BOTTOM_RIGHT);
			//PEnset(hPE, PEP_nAREABEVELSTYLE, PEBS_MEDIUM_SMOOTH);
			//PEnset(hPE, PEP_nSPLINEGRADIENTSTYLE,  PEPGS_RADIAL_BOTTOM_RIGHT);
			//PEnset(hPE, PEP_nSPLINEBEVELSTYLE, PESBS_MEDIUM_SMOOTH);

			PEresetimage(hPE, 0, 0);
			break;


		case 8: //童氏模板


			hWnd=::GetActiveWindow();
			::GetClientRect(hWnd, &r);
			hPE = PEcreate(PECONTROL_SGRAPH, 0, &r, hWnd, 1001);
			
			/*PEreinitialize(hPE);*/

			//// Version 4.0 Features //
		 //  PEnset(hPE, PEP_bFIXEDFONTS, TRUE);
		 //  PEnset(hPE, PEP_bSIMPLEPOINTLEGEND, TRUE);
		 //  PEnset(hPE, PEP_bSIMPLELINELEGEND, TRUE);
		 //  PEnset(hPE, PEP_nLEGENDSTYLE, PELS_1_LINE);
		 //  PEnset(hPE, PEP_nMULTIAXISSTYLE, PEMAS_SEPARATE_AXES);



			PEnset(hPE, PEP_bPREPAREIMAGES, TRUE);
			PEnset(hPE, PEP_nSUBSETS, 10);
			PEnset(hPE, PEP_nPOINTS, thePrd.DataLength);
			//PEnset(hPE, PEP_nPOINTS, 20);

			//FIG_TYPE=1;

			//enable set min and max
			//PEnset(hPE, PEP_nMANUALSCALECONTROLY, PEMSC_MINMAX);
			//
			//PEvset(hPE, PEP_fMANUALMINY, &dmin, 0);
			//PEvset(hPE, PEP_fMANUALMAXY, &dmax, 0);
			//PEvset(hPE, PEP_fMANUALMINY, &dmin, 1);
			//PEvset(hPE, PEP_fMANUALMAXY, &dmax, 1); 
			// Set draw pattern (point plus line)
			PEnset(hPE, PEP_nPLOTTINGMETHODII, PEGPM_POINTSPLUSLINE);
			PEnset(hPE, PEP_nPLOTTINGMETHOD, PEGPM_LINE);  
			
			PEvset(hPE, PEP_naSUBSETLINETYPES, nTypes_T, 10);  //define line type
			PEvset(hPE, PEP_naSUBSETPOINTTYPES, nTypes_T, 10); 
			//PEvset( hPE, PEP_dwaSUBSETCOLORS, dwArray_T, 10); //define line color

			// set second subset on right y axis.
			//PEnset(hPE, PEP_nRYAXISCOMPARISONSUBSETS, 1);
			//PEnset(hPE, PEP_nPLOTTINGMETHODII, PEGPM_LINE);
			//PEnset(hPE, PEP_nRYAXISCOMPARISONSUBSETS, );

			PEszset(hPE, PEP_szMAINTITLE, TEXT("童氏模板"));
			PEszset(hPE, PEP_szSUBTITLE, TEXT(""));
			PEszset(hPE, PEP_szYAXISLABEL, TEXT("含水"));
			PEszset(hPE, PEP_szXAXISLABEL, TEXT("采出程度"));

			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 0, TEXT("20%"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 1, TEXT("25%"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 2, TEXT("30%"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 3, TEXT("35%"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 4, TEXT("40%"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 5, TEXT("45%"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 6, TEXT("50%"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 7, TEXT("55%"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 8, TEXT("60%"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 9, TEXT("观测数据"));//define subtitle name;

			PEnset(hPE, PEP_bBITMAPGRADIENTMODE, TRUE);
			//PEnset(hPE, PEP_nQUICKSTYLE, PEQS_MEDIUM_NO_BORDER);
			PEnset(hPE, PEP_nQUICKSTYLE, PEQS_LIGHT_SHADOW);

			PEnset(hPE, PEP_bFIXEDFONTS, TRUE);
			PEnset(hPE, PEP_nLEGENDSTYLE, PELS_1_LINE_INSIDE_AXIS);
		

			for (s=0; s<9; s++)
			{
				
				for( int p=0; p<thePrd.DataLength; p++ )
					{										  
						////fX = ((float) (p+1)) * 100.0F + ((float) rand()) / 50.0F;
						//date_x= thePrd.Date[p];
						//PEvsetcellEx (hPE, PEP_faXDATA, s, p, &thePrd.Date[p]);
						////fY = ((float) (p+1) * 1.0F) + rand() + 700.0F - ((float) (s * 140.0F)) + ((float) rand()) / 250.0F;						
						
						fY=0.05+p*(0.98-0.05)/thePrd.DataLength;
						PEvsetcellEx (hPE, PEP_faYDATA, s, p, &fY);
						fX=(log10(fY/(1-fY))-1.69)/7.5+(0.2+s*0.05);
						PEvsetcellEx (hPE, PEP_faXDATA, s, p, &fX);
					}				
				//fY=0.98;
				//PEvsetcellEx (hPE, PEP_faYDATA, s, 19, &fY);
				//fX=(log10(fY/(1-fY))-1.69+7.5*(0.2+s*0.05))/7.5;
				//PEvsetcellEx (hPE, PEP_faXDATA, s, 19, &fX);


			}

			for( int p=0; p<thePrd.DataLength; p++ )
			{
				fY=thePrd.Wcut[p];
				PEvsetcellEx (hPE, PEP_faYDATA, s, p, &fY);
				fX=thePrd.Cum_oil[p]/thePrd.Reserve_Oil;
				PEvsetcellEx (hPE, PEP_faXDATA, s, p, &fX);

			}



			//设置曲线的类型
			//PEnset(hPE, PEP_nPLOTTINGMETHOD, PEGPM_BAR);		
			//设置坐标范围
			PEnset(hPE, PEP_nMANUALSCALECONTROLY, PEMSC_MINMAX);
			PEnset(hPE, PEP_nMANUALSCALECONTROLX, PEMSC_MINMAX);	
			dmax_y=(int)(dmax_y+1);
			dmin_y=0;
			dmin_x=0;
			dmax_x=1;
			//dmin_y=0;
			PEvset(hPE, PEP_fMANUALMINY, &dmin_y, 0);
			PEvset(hPE, PEP_fMANUALMAXY, &dmax_y, 0); 
			PEvset(hPE, PEP_fMANUALMINX, &dmin_x, 0);
			PEvset(hPE, PEP_fMANUALMAXX, &dmax_x, 0); 

			// Improves metafile export //
			PEnset(hPE, PEP_nDPIX, 600);
			PEnset(hPE, PEP_nDPIY, 600);
		/*	for( int p=0; p<thePrd.DataLength; p++ )
			
			{
				if(p%(int(thePrd.DataLength/10))==0)
					PEvsetcell(hPE, PEP_szaPOINTLABELS, 0, TEXT("1"));
			}
*/

			
			//for( int p=0; p<thePrd.DataLength; p++ )
			//
			//{
			//	itoa(thePrd.Date[p],buff_Date,10);				
			//	PEvsetcell(hPE, PEP_szaPOINTLABELS, p, buff_Date);
			//}		

			       
			//// Enable Plotting style gradient and bevel features //
			//PEnset(hPE, PEP_nAREAGRADIENTSTYLE,  PEPGS_RADIAL_BOTTOM_RIGHT);
			//PEnset(hPE, PEP_nAREABEVELSTYLE, PEBS_MEDIUM_SMOOTH);
			//PEnset(hPE, PEP_nSPLINEGRADIENTSTYLE,  PEPGS_RADIAL_BOTTOM_RIGHT);
			//PEnset(hPE, PEP_nSPLINEBEVELSTYLE, PESBS_MEDIUM_SMOOTH);

			PEresetimage(hPE, 0, 0);	
			break;		


			case 9: //校正童氏模板曲线
			
		    hWnd=::GetActiveWindow();
			::GetClientRect(hWnd, &r);
			hPE = PEcreate(PECONTROL_SGRAPH, 0, &r, hWnd, 1001);
			
			/*PEreinitialize(hPE);*/

			//// Version 4.0 Features //
		 //  PEnset(hPE, PEP_bFIXEDFONTS, TRUE);
		 //  PEnset(hPE, PEP_bSIMPLEPOINTLEGEND, TRUE);
		 //  PEnset(hPE, PEP_bSIMPLELINELEGEND, TRUE);
		 //  PEnset(hPE, PEP_nLEGENDSTYLE, PELS_1_LINE);
		 //  PEnset(hPE, PEP_nMULTIAXISSTYLE, PEMAS_SEPARATE_AXES);



			PEnset(hPE, PEP_bPREPAREIMAGES, TRUE);
			PEnset(hPE, PEP_nSUBSETS, 10);
			PEnset(hPE, PEP_nPOINTS, thePrd.DataLength);
			//PEnset(hPE, PEP_nPOINTS, 20);

			//FIG_TYPE=1;

			//enable set min and max
			//PEnset(hPE, PEP_nMANUALSCALECONTROLY, PEMSC_MINMAX);
			//
			//PEvset(hPE, PEP_fMANUALMINY, &dmin, 0);
			//PEvset(hPE, PEP_fMANUALMAXY, &dmax, 0);
			//PEvset(hPE, PEP_fMANUALMINY, &dmin, 1);
			//PEvset(hPE, PEP_fMANUALMAXY, &dmax, 1); 
			// Set draw pattern (point plus line)
			PEnset(hPE, PEP_nPLOTTINGMETHODII, PEGPM_POINTSPLUSLINE);
			PEnset(hPE, PEP_nPLOTTINGMETHOD, PEGPM_LINE);  
			
			PEvset(hPE, PEP_naSUBSETLINETYPES, nTypes_T, 10);  //define line type
			PEvset(hPE, PEP_naSUBSETPOINTTYPES, nTypes_T, 10); 
			//PEvset( hPE, PEP_dwaSUBSETCOLORS, dwArray_T, 10); //define line color

			// set second subset on right y axis.
			//PEnset(hPE, PEP_nRYAXISCOMPARISONSUBSETS, 1);
			//PEnset(hPE, PEP_nPLOTTINGMETHODII, PEGPM_LINE);
			//PEnset(hPE, PEP_nRYAXISCOMPARISONSUBSETS, );

			PEszset(hPE, PEP_szMAINTITLE, TEXT("童氏模板"));
			PEszset(hPE, PEP_szSUBTITLE, TEXT(""));
			PEszset(hPE, PEP_szYAXISLABEL, TEXT("含水"));
			PEszset(hPE, PEP_szXAXISLABEL, TEXT("采出程度"));

			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 0, TEXT("20%"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 1, TEXT("25%"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 2, TEXT("30%"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 3, TEXT("35%"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 4, TEXT("40%"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 5, TEXT("45%"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 6, TEXT("50%"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 7, TEXT("55%"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 8, TEXT("60%"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 9, TEXT("观测数据"));//define subtitle name;

			PEnset(hPE, PEP_bBITMAPGRADIENTMODE, TRUE);
			//PEnset(hPE, PEP_nQUICKSTYLE, PEQS_MEDIUM_NO_BORDER);
			PEnset(hPE, PEP_nQUICKSTYLE, PEQS_LIGHT_SHADOW);

			PEnset(hPE, PEP_bFIXEDFONTS, TRUE);
			PEnset(hPE, PEP_nLEGENDSTYLE, PELS_1_LINE_INSIDE_AXIS);
		

			for (s=0; s<9; s++)
			{
				
				for( int p=0; p<thePrd.DataLength; p++ )
					{		
						fY=0.05+p*(0.98-0.05)/thePrd.DataLength;
						PEvsetcellEx (hPE, PEP_faYDATA, s, p, &fY);

						fX=(log10(fY/(1-fY)+49/(pow(10,7.5*(0.2+s*0.05))-1))-log10(49/(pow(10,7.5*(0.2+s*0.05))-1)))/7.5;
						PEvsetcellEx (hPE, PEP_faXDATA, s, p, &fX);
					}				
			}

			for( int p=0; p<thePrd.DataLength; p++ )
			{
				fY=thePrd.Wcut[p];
				PEvsetcellEx (hPE, PEP_faYDATA, s, p, &fY);
				fX=thePrd.Cum_oil[p]/thePrd.Reserve_Oil;
				PEvsetcellEx (hPE, PEP_faXDATA, s, p, &fX);

			}



			//设置曲线的类型
			//PEnset(hPE, PEP_nPLOTTINGMETHOD, PEGPM_BAR);		
			//设置坐标范围
			PEnset(hPE, PEP_nMANUALSCALECONTROLY, PEMSC_MINMAX);
			PEnset(hPE, PEP_nMANUALSCALECONTROLX, PEMSC_MINMAX);	
			dmax_y=(int)(dmax_y+1);
			dmin_y=0;
			dmin_x=0;
			dmax_x=1;
			//dmin_y=0;
			PEvset(hPE, PEP_fMANUALMINY, &dmin_y, 0);
			PEvset(hPE, PEP_fMANUALMAXY, &dmax_y, 0); 
			PEvset(hPE, PEP_fMANUALMINX, &dmin_x, 0);
			PEvset(hPE, PEP_fMANUALMAXX, &dmax_x, 0); 

			// Improves metafile export //
			PEnset(hPE, PEP_nDPIX, 600);
			PEnset(hPE, PEP_nDPIY, 600);
		/*	for( int p=0; p<thePrd.DataLength; p++ )
			
			{
				if(p%(int(thePrd.DataLength/10))==0)
					PEvsetcell(hPE, PEP_szaPOINTLABELS, 0, TEXT("1"));
			}
*/

			
			//for( int p=0; p<thePrd.DataLength; p++ )
			//
			//{
			//	itoa(thePrd.Date[p],buff_Date,10);				
			//	PEvsetcell(hPE, PEP_szaPOINTLABELS, p, buff_Date);
			//}		

			       
			//// Enable Plotting style gradient and bevel features //
			//PEnset(hPE, PEP_nAREAGRADIENTSTYLE,  PEPGS_RADIAL_BOTTOM_RIGHT);
			//PEnset(hPE, PEP_nAREABEVELSTYLE, PEBS_MEDIUM_SMOOTH);
			//PEnset(hPE, PEP_nSPLINEGRADIENTSTYLE,  PEPGS_RADIAL_BOTTOM_RIGHT);
			//PEnset(hPE, PEP_nSPLINEBEVELSTYLE, PESBS_MEDIUM_SMOOTH);

			PEresetimage(hPE, 0, 0);	
			break;	


		case 10:  //水驱波及系数曲线

			//data needed：viscosity of oil and water; parameters of relative permeability include a and b.initial water saturation;


						
			hWnd=::GetActiveWindow();
			::GetClientRect(hWnd, &r);
			hPE = PEcreate(PECONTROL_SGRAPH, 0, &r, hWnd, 1001);
			
			/*PEreinitialize(hPE);*/

			//// Version 4.0 Features //
		 //  PEnset(hPE, PEP_bFIXEDFONTS, TRUE);
		 //  PEnset(hPE, PEP_bSIMPLEPOINTLEGEND, TRUE);
		 //  PEnset(hPE, PEP_bSIMPLELINELEGEND, TRUE);
		 //  PEnset(hPE, PEP_nLEGENDSTYLE, PELS_1_LINE);
		 //  PEnset(hPE, PEP_nMULTIAXISSTYLE, PEMAS_SEPARATE_AXES);



			PEnset(hPE, PEP_bPREPAREIMAGES, TRUE);
			PEnset(hPE, PEP_nSUBSETS, 10);
			PEnset(hPE, PEP_nPOINTS, thePrd.DataLength);
			//PEnset(hPE, PEP_nPOINTS, 20);

			//FIG_TYPE=1;

			//enable set min and max
			//PEnset(hPE, PEP_nMANUALSCALECONTROLY, PEMSC_MINMAX);
			//
			//PEvset(hPE, PEP_fMANUALMINY, &dmin, 0);
			//PEvset(hPE, PEP_fMANUALMAXY, &dmax, 0);
			//PEvset(hPE, PEP_fMANUALMINY, &dmin, 1);
			//PEvset(hPE, PEP_fMANUALMAXY, &dmax, 1); 
			// Set draw pattern (point plus line)
			PEnset(hPE, PEP_nPLOTTINGMETHODII, PEGPM_POINTSPLUSLINE);
			PEnset(hPE, PEP_nPLOTTINGMETHOD, PEGPM_LINE);  
			
			PEvset(hPE, PEP_naSUBSETLINETYPES, nTypes_T, 10);  //define line type
			PEvset(hPE, PEP_naSUBSETPOINTTYPES, nTypes_T, 10); 
			//PEvset( hPE, PEP_dwaSUBSETCOLORS, dwArray_T, 10); //define line color

			// set second subset on right y axis.
			//PEnset(hPE, PEP_nRYAXISCOMPARISONSUBSETS, 1);
			//PEnset(hPE, PEP_nPLOTTINGMETHODII, PEGPM_LINE);
			//PEnset(hPE, PEP_nRYAXISCOMPARISONSUBSETS, );

			PEszset(hPE, PEP_szMAINTITLE, TEXT("水驱波及系数解释图版"));
			PEszset(hPE, PEP_szSUBTITLE, TEXT(""));
			PEszset(hPE, PEP_szYAXISLABEL, TEXT("含水"));
			PEszset(hPE, PEP_szXAXISLABEL, TEXT("采出程度"));

			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 0, TEXT("EV=0.5"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 1, TEXT("EV=0.55"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 2, TEXT("EV=0.6"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 3, TEXT("EV=0.65"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 4, TEXT("EV=0.7"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 5, TEXT("EV=0.75"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 6, TEXT("EV=0.8"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 7, TEXT("EV=0.85"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 8, TEXT("EV=0.9"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 9, TEXT("观测数据"));//define subtitle name;

			PEnset(hPE, PEP_bBITMAPGRADIENTMODE, TRUE);
			//PEnset(hPE, PEP_nQUICKSTYLE, PEQS_MEDIUM_NO_BORDER);
			PEnset(hPE, PEP_nQUICKSTYLE, PEQS_LIGHT_SHADOW);

			PEnset(hPE, PEP_bFIXEDFONTS, TRUE);
			PEnset(hPE, PEP_nLEGENDSTYLE, PELS_1_LINE_INSIDE_AXIS);
		
			theIPR.Para_a=721436;
			theIPR.Para_b=23.692;
			theIPR.Visc_o=2.17;
			theIPR.Visc_w=0.45;
			theIPR.S_w_ini=0.314;



			for (s=0; s<9; s++)
			{				
				for( int p=0; p<thePrd.DataLength; p++ )
					{										  
						////fX = ((float) (p+1)) * 100.0F + ((float) rand()) / 50.0F;
						//date_x= thePrd.Date[p];
						//PEvsetcellEx (hPE, PEP_faXDATA, s, p, &thePrd.Date[p]);
						////fY = ((float) (p+1) * 1.0F) + rand() + 700.0F - ((float) (s * 140.0F)) + ((float) rand()) / 250.0F;						
						
						fY=0.05+p*(0.98-0.05)/thePrd.DataLength;
						PEvsetcellEx (hPE, PEP_faYDATA, s, p, &fY);
						//fX=(log10(fY/(1-fY))-1.69+7.5*(0.2+s*0.05))/7.5;
						fX=((log(theIPR.Para_a*theIPR.Visc_w/theIPR.Visc_o)-log(1/fY-1)-theIPR.Para_b*theIPR.S_w_ini)/(theIPR.Para_b*(1-theIPR.S_w_ini)))*(0.5+s*0.05);
						PEvsetcellEx (hPE, PEP_faXDATA, s, p, &fX);
					}				
				//fY=0.98;
				//PEvsetcellEx (hPE, PEP_faYDATA, s, 19, &fY);
				//fX=(log10(fY/(1-fY))-1.69+7.5*(0.2+s*0.05))/7.5;
				//PEvsetcellEx (hPE, PEP_faXDATA, s, 19, &fX);
			}

			for( int p=0; p<thePrd.DataLength; p++ )
			{
				fY=thePrd.Wcut[p];
				PEvsetcellEx (hPE, PEP_faYDATA, s, p, &fY);
				fX=thePrd.Cum_oil[p]/thePrd.Reserve_Oil;
				PEvsetcellEx (hPE, PEP_faXDATA, s, p, &fX);

			}



			//设置曲线的类型
			//PEnset(hPE, PEP_nPLOTTINGMETHOD, PEGPM_BAR);		
			//设置坐标范围
			PEnset(hPE, PEP_nMANUALSCALECONTROLY, PEMSC_MINMAX);
			PEnset(hPE, PEP_nMANUALSCALECONTROLX, PEMSC_MINMAX);	
			dmax_y=(int)(dmax_y+1);
			dmin_y=0;
			dmin_x=0;
			dmax_x=1;
			//dmin_y=0;
			PEvset(hPE, PEP_fMANUALMINY, &dmin_y, 0);
			PEvset(hPE, PEP_fMANUALMAXY, &dmax_y, 0); 
			PEvset(hPE, PEP_fMANUALMINX, &dmin_x, 0);
			PEvset(hPE, PEP_fMANUALMAXX, &dmax_x, 0); 

			// Improves metafile export //
			PEnset(hPE, PEP_nDPIX, 600);
			PEnset(hPE, PEP_nDPIY, 600);
		/*	for( int p=0; p<thePrd.DataLength; p++ )
			
			{
				if(p%(int(thePrd.DataLength/10))==0)
					PEvsetcell(hPE, PEP_szaPOINTLABELS, 0, TEXT("1"));
			}
*/

			
			//for( int p=0; p<thePrd.DataLength; p++ )
			//
			//{
			//	itoa(thePrd.Date[p],buff_Date,10);				
			//	PEvsetcell(hPE, PEP_szaPOINTLABELS, p, buff_Date);
			//}		

			       
			//// Enable Plotting style gradient and bevel features //
			//PEnset(hPE, PEP_nAREAGRADIENTSTYLE,  PEPGS_RADIAL_BOTTOM_RIGHT);
			//PEnset(hPE, PEP_nAREABEVELSTYLE, PEBS_MEDIUM_SMOOTH);
			//PEnset(hPE, PEP_nSPLINEGRADIENTSTYLE,  PEPGS_RADIAL_BOTTOM_RIGHT);
			//PEnset(hPE, PEP_nSPLINEBEVELSTYLE, PESBS_MEDIUM_SMOOTH);

			PEresetimage(hPE, 0, 0);	
			break;		


			case 11: //校正童氏模板曲线
			
		    hWnd=::GetActiveWindow();
			::GetClientRect(hWnd, &r);
			hPE = PEcreate(PECONTROL_SGRAPH, 0, &r, hWnd, 1001);
			
			/*PEreinitialize(hPE);*/

			//// Version 4.0 Features //
		 //  PEnset(hPE, PEP_bFIXEDFONTS, TRUE);
		 //  PEnset(hPE, PEP_bSIMPLEPOINTLEGEND, TRUE);
		 //  PEnset(hPE, PEP_bSIMPLELINELEGEND, TRUE);
		 //  PEnset(hPE, PEP_nLEGENDSTYLE, PELS_1_LINE);
		 //  PEnset(hPE, PEP_nMULTIAXISSTYLE, PEMAS_SEPARATE_AXES);



			PEnset(hPE, PEP_bPREPAREIMAGES, TRUE);
			PEnset(hPE, PEP_nSUBSETS, 10);
			PEnset(hPE, PEP_nPOINTS, thePrd.DataLength);
			//PEnset(hPE, PEP_nPOINTS, 20);

			//FIG_TYPE=1;

			//enable set min and max
			//PEnset(hPE, PEP_nMANUALSCALECONTROLY, PEMSC_MINMAX);
			//
			//PEvset(hPE, PEP_fMANUALMINY, &dmin, 0);
			//PEvset(hPE, PEP_fMANUALMAXY, &dmax, 0);
			//PEvset(hPE, PEP_fMANUALMINY, &dmin, 1);
			//PEvset(hPE, PEP_fMANUALMAXY, &dmax, 1); 
			// Set draw pattern (point plus line)
			PEnset(hPE, PEP_nPLOTTINGMETHODII, PEGPM_POINTSPLUSLINE);
			PEnset(hPE, PEP_nPLOTTINGMETHOD, PEGPM_LINE);  
			
			PEvset(hPE, PEP_naSUBSETLINETYPES, nTypes_T, 10);  //define line type
			PEvset(hPE, PEP_naSUBSETPOINTTYPES, nTypes_T, 10); 
			//PEvset( hPE, PEP_dwaSUBSETCOLORS, dwArray_T, 10); //define line color

			// set second subset on right y axis.
			//PEnset(hPE, PEP_nRYAXISCOMPARISONSUBSETS, 1);
			//PEnset(hPE, PEP_nPLOTTINGMETHODII, PEGPM_LINE);
			//PEnset(hPE, PEP_nRYAXISCOMPARISONSUBSETS, );

			PEszset(hPE, PEP_szMAINTITLE, TEXT("童氏模板"));
			PEszset(hPE, PEP_szSUBTITLE, TEXT(""));
			PEszset(hPE, PEP_szYAXISLABEL, TEXT("含水"));
			PEszset(hPE, PEP_szXAXISLABEL, TEXT("采出程度"));

			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 0, TEXT("20%"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 1, TEXT("25%"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 2, TEXT("30%"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 3, TEXT("35%"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 4, TEXT("40%"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 5, TEXT("45%"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 6, TEXT("50%"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 7, TEXT("55%"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 8, TEXT("60%"));//define subtitle name;
			PEvsetcell(hPE, PEP_szaSUBSETLABELS, 9, TEXT("观测数据"));//define subtitle name;

			PEnset(hPE, PEP_bBITMAPGRADIENTMODE, TRUE);
			//PEnset(hPE, PEP_nQUICKSTYLE, PEQS_MEDIUM_NO_BORDER);
			PEnset(hPE, PEP_nQUICKSTYLE, PEQS_LIGHT_SHADOW);

			PEnset(hPE, PEP_bFIXEDFONTS, TRUE);
			PEnset(hPE, PEP_nLEGENDSTYLE, PELS_1_LINE_INSIDE_AXIS);
		

			for (s=0; s<9; s++)
			{
				
				for( int p=0; p<thePrd.DataLength; p++ )
					{		
						fY=0.05+p*(0.98-0.05)/thePrd.DataLength;
						PEvsetcellEx (hPE, PEP_faYDATA, s, p, &fY);

						fX=(log10(fY/(1-fY)+49/(pow(10,7.5*(0.2+s*0.05))-1))-log10(49/(pow(10,7.5*(0.2+s*0.05))-1)))/7.5;
						PEvsetcellEx (hPE, PEP_faXDATA, s, p, &fX);
					}				
			}

			for( int p=0; p<thePrd.DataLength; p++ )
			{
				fY=thePrd.Wcut[p];
				PEvsetcellEx (hPE, PEP_faYDATA, s, p, &fY);
				fX=thePrd.Cum_oil[p]/thePrd.Reserve_Oil;
				PEvsetcellEx (hPE, PEP_faXDATA, s, p, &fX);

			}

			//设置曲线的类型
			//PEnset(hPE, PEP_nPLOTTINGMETHOD, PEGPM_BAR);		
			//设置坐标范围
			PEnset(hPE, PEP_nMANUALSCALECONTROLY, PEMSC_MINMAX);
			PEnset(hPE, PEP_nMANUALSCALECONTROLX, PEMSC_MINMAX);	
			dmax_y=(int)(dmax_y+1);
			dmin_y=0;
			dmin_x=0;
			dmax_x=1;
			//dmin_y=0;
			PEvset(hPE, PEP_fMANUALMINY, &dmin_y, 0);
			PEvset(hPE, PEP_fMANUALMAXY, &dmax_y, 0); 
			PEvset(hPE, PEP_fMANUALMINX, &dmin_x, 0);
			PEvset(hPE, PEP_fMANUALMAXX, &dmax_x, 0); 

			// Improves metafile export //
			PEnset(hPE, PEP_nDPIX, 600);
			PEnset(hPE, PEP_nDPIY, 600);
		/*	for( int p=0; p<thePrd.DataLength; p++ )
			
			{
				if(p%(int(thePrd.DataLength/10))==0)
					PEvsetcell(hPE, PEP_szaPOINTLABELS, 0, TEXT("1"));
			}
*/
			
			//for( int p=0; p<thePrd.DataLength; p++ )
			//
			//{
			//	itoa(thePrd.Date[p],buff_Date,10);				
			//	PEvsetcell(hPE, PEP_szaPOINTLABELS, p, buff_Date);
			//}		

			       
			//// Enable Plotting style gradient and bevel features //
			//PEnset(hPE, PEP_nAREAGRADIENTSTYLE,  PEPGS_RADIAL_BOTTOM_RIGHT);
			//PEnset(hPE, PEP_nAREABEVELSTYLE, PEBS_MEDIUM_SMOOTH);
			//PEnset(hPE, PEP_nSPLINEGRADIENTSTYLE,  PEPGS_RADIAL_BOTTOM_RIGHT);
			//PEnset(hPE, PEP_nSPLINEBEVELSTYLE, PESBS_MEDIUM_SMOOTH);

			PEresetimage(hPE, 0, 0);	
			break;				
	 
		default:	
			CWnd::OnPaint();			

	}


}

void CIPRView::OnWctFig()
{
	// TODO: 在此添加命令处理程序代码
	
	FIG_TYPE=2;
	OnPaint();
}


void CIPRView::OnTshModel()
{
	// TODO: 在此添加命令处理程序代码

	FIG_TYPE=8;
	OnPaint();

}


void CIPRView::OnTshModelM()
{
	// TODO: 在此添加命令处理程序代码
	
	FIG_TYPE=9;
	OnPaint();
}


void CIPRView::OnSwptEff()
{
	// TODO: 在此添加命令处理程序代码
	
	FIG_TYPE=10;
	OnPaint();

}


void CIPRView::OnIprOpt()
{
	// TODO: 在此添加命令处理程序代码
	
	//C_IPR_SHOW *pDlg_IPR=new C_IPR_SHOW;	 	
	//static TCHAR  szTop[]=TEXT("最优的IPR：");
	//::SetDlgItemText(pDlg_IPR->m_hWnd,IDC_IPR_SHOW,szTop);
	//pDlg_IPR->DoModal();
	////::SetDlgItemText(IDC_IPR_SHOW,szTop);
	////CDC *pDC = GetDlgItem(IDC_IPR_SHOW)->GetDC();
	//CDC *pDC=GetDC();

	//CDC *pDC = pDlg_IPR->GetDlgItem(IDC_IPR_SHOW)->GetDC();	
	//TextOut(pDC->DrawText,0,0,szTop,lstrlen(szTop));
	//SendDlgItemMessage(IDC_IPR_SHOW,WM_SETTEXT,0,(LPARAM)szTop);

	 //TextOut(pDC->m_hDC,0,0,(LPCTSTR)szTop,lstrlen(szTop));
	 //pDlg_IPR->GetDlgItem(IDC_IPR_SHOW)->SetWindowTextW(_T(""));
	 ////pDlg_IPR->GetDlgItem(IDC_IPR_SHOW)->SetWindowText(_T("消息"));
	 //pDlg_IPR->GetDlgItem(IDC_IPR_SHOW)->UpdateData(1);
	 //pDlg_IPR->GetDlgItem(IDC_IPR_SHOW)->RedrawWindow();
	 //CWnd* pWnd = pDlg_IPR->GetDlgItem(IDC_IPR_SHOW); 
	 //pWnd->SetWindowText(_T("Hockey is best!"));  
	 ////////SetDlgItemText(IDC_IPR_SHOW, szTop);
	 //UpdateData(false);

	 //C_IPR_SHOW*   pDlg_IPR = new C_IPR_SHOW();
	 //pDlg_IPR->Create(pParent,DLG_ID);
	 //pDlg_IPR->Create();
	 //pDlg_IPR->SetDlgItemText( IDC_IPR_SHOW, szTop);
	 //pDlg_IPR->ShowWindow(SW_SHOW);

	//FIG_TYPE=0;
	//OnPaint();
	//HDC hdc;
	//hdc = ::GetDC(m_hWnd);	
	//::TextOut(hdc,20,20,szTop,lstrlen(szTop));
	//::ReleaseDC(m_hWnd, hdc);
	
	//HDC hdc;

	theIPR.IPR_CMP();

	C_IPR_SHOW pDlg_IPR;

	//::SetDlgItemText(IDC_IPR_RES,szTop);
	//pDlg_IPR.SetDlgItemText(IDC_IPR_TEXT,szTop);
	
	//::SetDlgItemText(pDlg_IPR,IDC_IPR_TEXT,szTop);
	//hdc = ::GetDC(pDlg_IPR->m_hWnd);
	//::TextOut(hdc,1,1,szTop,lstrlen(szTop));
	//GetDlgItem(IDC_IPR_TEXT)->SetWindowText(szTop);


	pDlg_IPR.DoModal();

	

}


void CIPRView::OnIprInf()
{
	// TODO: 在此添加命令处理程序代码
	C_IPR_INF_SHOW pDlg;
	pDlg.DoModal();


}
