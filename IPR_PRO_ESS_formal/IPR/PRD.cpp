#include "StdAfx.h"
#include "PRD.h"
#include "stdio.h"
#include  <afxwin.h> 
#include <io.h>
//matcom include file
//#include "matlib.h"


CPRD::CPRD(void)
	: DataLength(0)
	, Verify_Data(false)
	, Reserve_Oil(0)
{
	Winjt=NULL; 
	Winjt_indc=false; //indicate Winjt is available or notOil_P=NULL;

	Wat_P=NULL;
	Wat_P_indc=false; //indicate Wat_P is available or not;

	Wcut=NULL;
	Wcut_indc=false; //indicate Wcut is available or not;
	
	Rpre=NULL;
	Rpre_indc=false; //indicate Rpre is avilable or not

	Cum_oil==NULL;
	Cum_oil_Indc=false;   //indicate Cum_oil is available or not;

	Cum_Wt_P=NULL;
	Cum_Wt_P_Indc=false; //indicate Cum_Wt_P is available or not;

	Cum_Wt_I=NULL;
	Cum_Wt_I_Indc=false; //indicate Cum_Wt_I is available or not;

	Date=NULL;
	Data_Indc=false; //indicate Cum_Wt_I is available or not;
	
	CharWinjt_unit==NULL;
	CharOil_P_unit=NULL;
	CharWat_P_unit=NULL;
	CharWcut_unit=NULL;
	Rpr_unit=NULL;
	CharCum_Wt_I_unit=NULL;
	CharCum_oil_unit=NULL;
	CharCum_Wt_P_unit=NULL;
}


CPRD::~CPRD(void)
{
	
	if(Date_indc!=0)
	{
		free(Date);
	}	
	
	if(Winjt_indc!=0)
	{
		free(Winjt);
		free(CharWinjt_unit);
	}

	if(Oil_P_indc!=0)
	{
		free(Oil_P);
		free(CharOil_P_unit);
	}
	if(Wat_P_indc!=0)
	{
		free(Wat_P);
		free(CharWat_P_unit);
	}

	if(Wcut_indc!=0)
	{
		free(Wcut);
	}

	if(Rpre_indc!=0)
	{
		free(Rpre);
		free(Rpr_unit);
	}
	if(Cum_oil_Indc!=0)
	{	
		free(Cum_oil);	
		free(CharCum_oil_unit);
	}
	if(Cum_Wt_P!=0)
	{
		free(Cum_Wt_P);
		free(CharCum_Wt_P_unit);
	}
	if(Cum_Wt_I_Indc!=0)
	{
		free(Cum_Wt_I);
		free(CharCum_Wt_I_unit);
	}	
}


// //初始化参数
void CPRD::Initialization(CString Ipfile)
{
	if(Verify_Data==true)
	{
		if(MessageBox(NULL,_T("数据已经存在，是否替换"),_T(" "),MB_OKCANCEL)==IDOK)
		{
			Verify_Data=false;
			dump();
		}
	}

	if (Verify_Data==false)
	{
	    char *pBuf;
		CFile file(Ipfile,CFile::modeRead);		
		ULONGLONG dwFileLen;
		dwFileLen=file.GetLength();
		pBuf=new char[dwFileLen+1];
		pBuf[dwFileLen]=0;
		file.Read(pBuf,dwFileLen);
		file.Close();		

		//MessageBox(LPCTSTR(*pBuf));		
		//sscanf(buf,"x=%d,y=%d",&u1,&v1);  
		//str.format("u1=%d,v1=%d",u1,v1);  
		//AfxMessageBox("str");  
		//解析头文件 时间；注水量；产油量；产水量；含水；累注水量；累产油量；累产水量；
		//count lines in buf;
		int i=0;
		int line_num;
		line_num=1;

		for(i=0;i<dwFileLen;i++)
		{
			if(pBuf[i]=='\n')
			{
				line_num++;
			}
		}
		thePrd.DataLength=line_num-3;
		free(pBuf);

		//thePrd.Date=new (line_num-1)*char[10];		

		char CharDate[thePrd.CharLength];
		char CharWinjt[thePrd.CharLength];
		char CharOil_P[thePrd.CharLength];
		char CharWat_P[thePrd.CharLength];
		char CharGas_P[thePrd.CharLength];
		char CharWcut[thePrd.CharLength];

		char CharCum_Wt_I[thePrd.CharLength];
		char CharCum_oil[thePrd.CharLength];
		char CharCum_Wt_P[thePrd.CharLength];	
		char CharCum_Gas_P[thePrd.CharLength];

		char CharReserve[thePrd.CharLength];
		char CharRec_Rev[thePrd.CharLength];



		FILE *Fdata=NULL;
		
		wchar_t *Ipfile_str=Ipfile.GetBuffer(Ipfile.GetLength());
		//strncpy(Ipfile_str,(LPCTSTR)Ipfile,Ipfile.GetLength());
		//Ipfile_str=(char)Ipfile.GetBuffer(Ipfile.GetLength());

		//Fdata=fopen((char*)Ipfile_str,"r");
		//charpoint=strtest.GetBuffer(strtest.GetLength());
		char s[50];
		//wchar_t to char*
		WideCharToMultiByte( CP_ACP, 0,Ipfile_str,-1,s,50, NULL, NULL);
		//open file;
		Fdata=fopen(s,"r");		
		if(Fdata!=NULL)
		{
			thePrd.Date=new int[thePrd.DataLength];		
			thePrd.Winjt=new float[thePrd.DataLength];
			thePrd.Oil_P=new float[thePrd.DataLength];
			thePrd.Wat_P=new float[thePrd.DataLength];
			thePrd.GAS_P=new float[thePrd.DataLength];
			thePrd.Wcut=new float[thePrd.DataLength];		
			thePrd.Cum_Wt_I=new float[thePrd.DataLength];
			thePrd.Cum_oil=new float[thePrd.DataLength];		
			thePrd.Cum_Wt_P=new float[thePrd.DataLength];
			thePrd.Cum_GAS_P=new float[thePrd.DataLength];
			
			thePrd.CharWinjt_unit=new char[thePrd.CharLength];
			thePrd.CharOil_P_unit=new char[thePrd.CharLength];
			thePrd.CharWat_P_unit=new char[thePrd.CharLength];
			thePrd.CharGas_P_unit=new char[thePrd.CharLength];
			thePrd.CharCum_Wt_I_unit=new char[thePrd.CharLength];
			thePrd.CharCum_oil_unit=new char[thePrd.CharLength];
			thePrd.CharCum_Wt_P_unit=new char[thePrd.CharLength];
			thePrd.CharCum_Gas_P_unit=new char[thePrd.CharLength];

			thePrd.Data_Indc=true;     //indicate Cum_Wt_I is available;
			thePrd.Oil_P_indc=true;    //indicate oil_P is available;
			thePrd.Wat_P_indc=true;    //indicate Wat_P is available;	
			thePrd.GAS_indc=true;      //indicate gas production is available;
			thePrd.Wcut_indc=true;     //indicate Wcut is available;	
			thePrd.Winjt_indc=true;    //indicate Winjt is available;			
			thePrd.Cum_oil_Indc=true;  //indicate Cum_oil is available;	
			thePrd.Cum_Wt_P_Indc=true; //indicate Cum_Wt_P is available;	
			thePrd.Cum_Wt_I_Indc=true; //indicate Cum_Wt_I is available;	
			thePrd.Cum_Gas_P_Indc=true;//indicate cummulative gas production is available;

			

			fscanf(Fdata,"地质储量:%s 可采储量:%s\n",CharReserve,CharRec_Rev);
			thePrd.Reserve_Oil=atoi(CharReserve);
			thePrd.Rcoverable_Rev=atoi(CharRec_Rev);
			

			fscanf(Fdata,"注水:%s 产油:%s  产水:%s  产气:%s  累积注水:%s  累积产油:%s 累积产水:%s  累积产气:%s\n",
				thePrd.CharWinjt_unit,thePrd.CharOil_P_unit,
				thePrd.CharWat_P_unit,thePrd.CharGas_P_unit,thePrd.CharCum_Wt_I_unit,
				thePrd.CharCum_oil_unit,thePrd.CharCum_Wt_P_unit,thePrd.CharCum_Gas_P_unit);  
     
    		fscanf(Fdata,"%s %s %s %s %s %s %s %s %s %s\n",
				CharDate,CharWinjt,CharOil_P,CharWat_P,CharGas_P,CharWcut,
				CharCum_Wt_I,CharCum_oil,CharCum_Wt_P,CharCum_Gas_P);  
			
			int index=0;
			
			while(!feof(Fdata))
			{
				fscanf(Fdata,"%s %s %s %s %s %s %s %s %s %s\n",
				CharDate,CharWinjt,CharOil_P,CharWat_P,CharGas_P,CharWcut,
				CharCum_Wt_I,CharCum_oil,CharCum_Wt_P,CharCum_Gas_P);  

				thePrd.Date[index]=atoi(CharDate);
				thePrd.Winjt[index]=atof(CharWinjt);
				thePrd.Oil_P[index]=atof(CharOil_P);
				thePrd.Wat_P[index]=atof(CharWat_P);
				thePrd.GAS_P[index]=atof(CharGas_P);
				thePrd.Wcut[index]=atof(CharWcut);		
				thePrd.Cum_Wt_I[index]=atof(CharCum_Wt_I);
				thePrd.Cum_oil[index]=atof(CharCum_oil);
				thePrd.Cum_Wt_P[index]=atof(CharCum_Wt_P);
				Cum_GAS_P[index]=atof(CharCum_Gas_P);
				
				index++;
			}			
		}
		else
		{
			//MessageBox("这是一个最简单的消息框！");
			MessageBox(NULL,(LPCWSTR)"错误",(LPCWSTR)"错误",NULL);
			//::AfxMessageBox("Are you sure?",MB_YESNO|MB_ICONQUESTION);
			//AfxMessageBox("Are you sure?");
			//::MessageBoxA(this,"A");
		}
		fclose(Fdata);
		Verify_Data=true;
	}
}


// //refresh object memory
void CPRD::dump(void)
{
	if(Date_indc!=false)
	{
		free(Date);
		Date=NULL;
	}	
	
	if(Winjt_indc!=false)
	{
		free(Winjt);
		Winjt=NULL;
		free(CharWinjt_unit);
		CharWinjt_unit=NULL;
	}

	if(Oil_P_indc!=false)
	{
		free(Oil_P);
		Oil_P=NULL;
		free(CharOil_P_unit);
		CharOil_P_unit=NULL;
	}
	if(Wat_P_indc!=false)
	{
		free(Wat_P);
		Wat_P=NULL;
		free(CharWat_P_unit);
		CharWat_P_unit=NULL;
	}

	if(Wcut_indc!=false)
	{
		free(Wcut);
		Wcut=NULL;
	}

	if(Rpre_indc!=false)
	{
		free(Rpre);
		Rpre=NULL;
		free(Rpr_unit);
		Rpr_unit=NULL;
	}
	if(Cum_oil_Indc!=false)
	{	
		free(Cum_oil);	
		Cum_oil=NULL;
		free(CharCum_oil_unit);
		CharCum_oil_unit=NULL;
	}
	if(Cum_Wt_P!=false)
	{
		free(Cum_Wt_P);
		Cum_Wt_P=NULL;
		free(CharCum_Wt_P_unit);
		CharCum_Wt_P_unit=NULL;
	}
	if(Cum_Wt_I_Indc!=false)
	{
		free(Cum_Wt_I);
		Cum_Wt_I=NULL;
		free(CharCum_Wt_I_unit);
		CharCum_Wt_I_unit=NULL;
	}	

}


// //draw picture of data vs date
void CPRD::Draw_Date(int index)
{
	 //  initM(MATCOM_VERSION);

		//  Mm x,s,c;
		//  Mm m_hPlot;//figure handle
		//  Mm m_hAxis;//坐标轴句柄
		//  Mm m_axispos;//坐标轴范围
		//  Mm m_hXlabel,m_hYlabel,m_hTitle;//x轴，y轴和标题句柄


		//  Mm x,y;
		//  int year,month;
		//  float p;
		//  int i;
		//  int date_gap;//1:1-jan-2000;

		//  x=zeros(1,thePrd.DataLength);
	 //     y=zeros(1,thePrd.DataLength);
		//  
		//  for(i=0;i<thePrd.DataLength;i++)
		//  {
		//	  year=round(thePrd.Date[i]/100);			  			  
		//	  month=mod(thePrd.Date[i],100);
		//	  x(i+1)=datenum(year-1900,month,1);
		//	  y.r(i+1)=thePrd.Oil_P[i];
		//	  p=y.r(i+1);
		//	  
		//  }
		// /* memcpy(x.addr(),thePrd.Date,sizeof(thePrd.DataLength*sizeof(int)));
	 //     memcpy(y.addr(),thePrd.Date,sizeof(thePrd.DataLength*sizeof(float)));*/
		//
		//  convert to date format
	
		//  set(gcf(),TM("MenuAbout"),TM("off"));
		// 
		//m_hPlot=plot((CL(x),y,TM("LineWidth"),4));	
		//datetick('x',TM("yyyy/mm"));
		//m_hAxis = gca();
		//set(m_hAxis,TM("color"),TM("White"));
		//set(m_hPlot,(CL(TM("COLOR")),TM("red")));
		//set(m_hAxis,TM("MenuAbout"),TM("off"));

		//xlabel((CL(TM("Date"))));
		//ylabel((CL(TM("Oil Production Rate"))));
		//
		//drawnow();
		//exitM();


}
