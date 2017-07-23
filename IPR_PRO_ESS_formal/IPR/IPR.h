
// IPR.h : IPR 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CIPRApp:
// 有关此类的实现，请参阅 IPR.cpp
//

class CIPRApp : public CWinApp
{
public:
	CIPRApp();

public:


//	float Ini_pressure;
	/*float Pressure_reasonable;
	

	float Boi;
	float Gravity_o;
	float Visc_o;
	float Visc_w;
	float Compss_Ct;

	float Para_a;
	float Para_b;
	float S_w_ini;
	float S_w_conate;

	int stage;*/

// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现	
	DECLARE_MESSAGE_MAP()
	afx_msg void OnCumlqdvswct();
	afx_msg void OnResidWat();
};

extern CIPRApp theApp;
