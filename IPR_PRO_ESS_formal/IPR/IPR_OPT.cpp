#include "StdAfx.h"
#include "IPR_OPT.h"
#include <math.h>


CIPR_OPT::CIPR_OPT(void)
{

	Ini_pressure=0;
	Pressure_reasonable=0;	

	Boi=0;
	Gravity_o=0;
	Visc_o=0;
	Visc_w=0;
	Compss_Ct=0;
	
	Para_a=0;
	Para_b=0;
	S_w_ini=0;
	S_o_residule=0;
	stage=0;	
}


CIPR_OPT::~CIPR_OPT(void)
{
	
}


//Calculate Opt IPR
void CIPR_OPT::IPR_CMP()
{
	int i;
	float Lp_Cum;

	//theIPR.Ini_pressure=60;
	//theIPR.Pressure_reasonable=40;	

	//theIPR.Boi=1.2;
	//theIPR.Gravity_o=0.8;
	//theIPR.Visc_o=2;
	//theIPR.Visc_w=0.5;
	//theIPR.Compss_Ct=0.00123;
	//
	//theIPR.Para_a=854267;
	//theIPR.Para_b=26.8;
	//theIPR.S_w_ini=0.4;
	//theIPR.S_o_residule=0.2;
	//theIPR.stage=2;

	float A_p,C_p;
	A_p=2/(3*theIPR.Para_b*(1-theIPR.S_w_ini));
	C_p=A_p*(theIPR.Para_b/2*(3*theIPR.S_w_ini+theIPR.S_o_residule-1)-log(theIPR.Para_a)+log(theIPR.Visc_o*theIPR.Boi/(theIPR.Visc_w*theIPR.Gravity_o)));

	//theIPR.stage=3;
	switch(theIPR.stage)
	{

	case 1:
		Lp_Cum=A_p*(0.6/(1-0.6)+log(0.6/(1-0.6)))-C_p;
		IPR[0]=0.83*(theIPR.Pressure_reasonable-theIPR.Ini_pressure)*theIPR.Boi*theIPR.Compss_Ct/Lp_Cum+1;
		Lp_Cum=A_p*(0.9/(1-0.9)+log(0.9/(1-0.9)))-C_p-Lp_Cum;
		IPR[1]=0.17*(theIPR.Pressure_reasonable-theIPR.Ini_pressure)*theIPR.Boi*theIPR.Compss_Ct/Lp_Cum+1;
		IPR[2]=1;
		break;
	
	case 2:				
		Lp_Cum=A_p*(0.3/(1-0.3)+log(0.3/(1-0.3)))-C_p;
	    IPR[0]=0.34*(theIPR.Pressure_reasonable-theIPR.Ini_pressure)*theIPR.Boi*theIPR.Compss_Ct/Lp_Cum+1;
		Lp_Cum=A_p*(0.6/(1-0.6)+log(0.6/(1-0.6)))-C_p-Lp_Cum;
		IPR[1]=0.47*(theIPR.Pressure_reasonable-theIPR.Ini_pressure)*theIPR.Boi*theIPR.Compss_Ct/Lp_Cum+1;
		Lp_Cum=A_p*(0.9/(1-0.9)+log(0.9/(1-0.9)))-C_p-Lp_Cum;
		IPR[2]=0.17*(theIPR.Pressure_reasonable-theIPR.Ini_pressure)*theIPR.Boi*theIPR.Compss_Ct/Lp_Cum+1;
		IPR[3]=1;
		break;
	
	case 3:	
		Lp_Cum=A_p*(0.6/(1-0.6)+log(0.6/(1-0.6)))-C_p;
	    IPR[0]=0.346*(theIPR.Pressure_reasonable-theIPR.Ini_pressure)*theIPR.Boi*theIPR.Compss_Ct/Lp_Cum+1;
		Lp_Cum=A_p*(0.9/(1-0.9)+log(0.9/(1-0.9)))-C_p-Lp_Cum;
		IPR[1]=0.474*(theIPR.Pressure_reasonable-theIPR.Ini_pressure)*theIPR.Boi*theIPR.Compss_Ct/Lp_Cum+1;
		Lp_Cum=A_p*(0.95/(1-0.95)+log(0.95/(1-0.95)))-C_p-Lp_Cum;
		IPR[2]=0.18*(theIPR.Pressure_reasonable-theIPR.Ini_pressure)*theIPR.Boi*theIPR.Compss_Ct/Lp_Cum+1;
		IPR[3]=1;
		break;
	
	default:
		for(i=0;i<3;i++)
		{
			IPR[i]=0;
		}		
	}

}
