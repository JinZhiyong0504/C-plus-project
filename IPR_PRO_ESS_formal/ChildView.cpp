
// ChildView.cpp : CChildView 类的实现
//

#include "stdafx.h"
#include "IPR.h"
#include "ChildView.h"
#include <math.h>
#include "Pegrpapi.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

HWND hPE;


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_MB, &CChildView::OnMb)
END_MESSAGE_MAP()



// CChildView 消息处理程序

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 用于绘制的设备上下文
	
	// TODO: 在此处添加消息处理程序代码
	
	// 不要为绘制消息而调用 CWnd::OnPaint()
}



void CChildView::OnMb()
{
	// TODO: 在此添加命令处理程序代码
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	RECT r;
	int s, p;
	float f,fX,fY; 
	int nTypes[] = {PELT_MEDIUMSOLID, PELT_MEDIUMSOLID};  
	int nPTypes[] = { PEPT_DOTSOLID, PEPT_PLUS };  
	DWORD dwArray[2] = { PERGB(128, 198,0,0), PERGB(128, 0, 198, 0) };  
	double dmax=1000.0F;
	double dmin=0.0F;


	HWND hWnd;
	hWnd=::GetActiveWindow();
	 ::GetClientRect(hWnd, &r);
     hPE = PEcreate(PECONTROL_GRAPH, 0, &r, hWnd, 1001);
     //PEnset(hPE, PEP_bPREPAREIMAGES, TRUE);
     PEnset(hPE, PEP_nSUBSETS, 2);
     PEnset(hPE, PEP_nPOINTS, 10);
     for (s=0; s<2; s++)
     {
    //     for (p=0; p<10; p++)
    //     { 
    //        //f = (rand() % 10) + (rand() % 100) / 100.0F;
			 //f = rand();//(rand() % 10) + (rand() % 100) / 100.0F;
    //        PEvsetcellEx(hPE, PEP_faYDATA, s, p, &f); 
    //     }
		 
		 for( int p=0; p<=11; p++ )
           {										  
               fX = ((float) (p+1)) * 100.0F + ((float) rand()) / 50.0F;
               PEvsetcellEx (hPE, PEP_faXDATA, s, p, &fX);
               fY = ((float) (p+1) * 1.0F) + rand() + 700.0F - ((float) (s * 140.0F)) + ((float) rand()) / 250.0F;
               PEvsetcellEx (hPE, PEP_faYDATA, s, p, &fY);
           }
     }

	 //enable set min and max
	 PEnset(hPE, PEP_nMANUALSCALECONTROLY, PEMSC_MINMAX);
	
	 PEvset(hPE, PEP_fMANUALMINY, &dmin, 0);
	 PEvset(hPE, PEP_fMANUALMAXY, &dmax, 0);
	 PEvset(hPE, PEP_fMANUALMINY, &dmin, 1);
	 PEvset(hPE, PEP_fMANUALMAXY, &dmax, 1);

	 


	 // Set draw pattern (point plus line)
	 PEnset(hPE, PEP_nPLOTTINGMETHODII, PEGPM_POINTSPLUSLINE);
	 PEnset(hPE, PEP_nPLOTTINGMETHOD, PEGPM_POINTSPLUSLINE);  
	 
	 PEvset(hPE, PEP_naSUBSETLINETYPES, nTypes, 2);  //define line type
	 PEvset(hPE, PEP_naSUBSETPOINTTYPES, nTypes, 2); 
	 PEvset( hPE, PEP_dwaSUBSETCOLORS, dwArray, 2); //define line color

	 // set second subset on right y axis.
	 PEnset(hPE, PEP_nRYAXISCOMPARISONSUBSETS, 1);
	 //PEnset(hPE, PEP_nPLOTTINGMETHODII, PEGPM_LINE);
	 //PEnset(hPE, PEP_nRYAXISCOMPARISONSUBSETS, );

     PEszset(hPE, PEP_szMAINTITLE, TEXT("My Title"));
     PEszset(hPE, PEP_szSUBTITLE, TEXT(""));
     PEszset(hPE, PEP_szYAXISLABEL, TEXT("My Data"));
     PEszset(hPE, PEP_szXAXISLABEL, TEXT(""));

     PEvsetcell(hPE, PEP_szaSUBSETLABELS, 0, TEXT("Hello"));//define subtitle name;
     PEvsetcell(hPE, PEP_szaSUBSETLABELS, 1, TEXT("World"));//define subtitle name;

     //PEnset(hPE, PEP_bBITMAPGRADIENTMODE, TRUE);
     //PEnset(hPE, PEP_nQUICKSTYLE, PEQS_MEDIUM_NO_BORDER);
     //PEnset(hPE, PEP_bFIXEDFONTS, TRUE);
     //PEnset(hPE, PEP_nLEGENDSTYLE, PELS_1_LINE_INSIDE_AXIS);

     //PEreinitialize(hPE);
     PEresetimage(hPE, 0, 0);

}
