#pragma once
class CIPR_OPT
{
public:
	CIPR_OPT(void);
	~CIPR_OPT(void);
public:

	float Ini_pressure;
	float Pressure_reasonable;
	

	float Boi;
	float Bg;
	float Bw;
	float Gravity_o;
	float Visc_o;
	float Visc_w;
	float Compss_Ct;
	float P_satu;

	float Para_a;
	float Para_b;
	float S_w_ini;
	float S_o_residule;

	float Solut_GOR_INI;
	float Solut_GOR_PRENT;

	float Reserves;
	float Reserves_recov;


	int stage;

	float IPR[4];

	// //Calculate Opt IPR
	void IPR_CMP();


};

extern CIPR_OPT theIPR;

