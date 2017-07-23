#pragma once
class CPRD
{
public:
	CPRD(void);
	~CPRD(void);
public:
	int* Date;        //date;
	float* Winjt;     //water injection;
	float* Oil_P;     // oil prodcution;
	float* Wat_P;     //water production
	float* GAS_P;     //gas production
	float* Wcut;	     //water cut
	float* Rpre;         //reservoir pressure
	float* Cum_oil;      //cummulative oil production;
	float* Cum_Wt_P;     //cummulative water production
	float* Cum_Wt_I;     //cummulative water injection
	float* Cum_GAS_P;    //commulative gas production;
	float Reserve_Oil;   //geological reserves
	float Rcoverable_Rev;
	
	bool Date_indc;     //indicate Date is available or not;
	bool Winjt_indc;    //indicate Water injection is available or not;	
	bool Oil_P_indc;    //indicate oil production is available or not;
	bool Wat_P_indc;    //indicate Wat production is available or not;	
	bool Wcut_indc;     //indicate Water cut is available or not;
	bool GAS_indc;      //indicate GAS production data is available or not;
	bool Rpre_indc;     //indicate Reservoir pressure is available or not;


	bool  Cum_oil_Indc; //indicate Cum_oil is available or not;	
	bool  Cum_Wt_P_Indc;//indicate Cum_Wt_P is available or not;	
	bool  Cum_Wt_I_Indc;//indicate Cum_Wt_I is available or not;	
	bool  Cum_Gas_P_Indc;//indicate cummulative gas is available or not;
	bool  Data_Indc;    //indicate Cum_Wt_I is available or not;
	
	//unit string
	char *CharWinjt_unit;
	char *CharOil_P_unit;
	char *CharWat_P_unit;
	char *CharGas_P_unit;
	char *CharWcut_unit;
	char *Rpr_unit;
	char *CharCum_Wt_I_unit;
	char *CharCum_oil_unit;
	char *CharCum_Wt_P_unit;
	char *CharCum_Gas_P_unit;

	//name of every vector;

	char* Str_Name_Winjt;
	char* Str_Name_Oil_P;
	char* Str_Name_Wat_P;
	char* Str_Name_Gas_P;
	char* Str_Name_Wcut;	
	char* Str_Name_Rpre;    
	char* Str_Name_Cum_oil;
	char* Str_Name_Cum_Wt_P;
	char* Str_Name_Cum_Wt_I;
	char* Str_Name_Cum_Gas_P;
	

	// //初始化参数
	void Initialization(CString Ipfile);
	// //max length of characters
	static const int CharLength=20;
	// //number of unit record
	int DataLength;	
	// //verify data present or not,true:data already present,false:No data;
	bool Verify_Data;
	// //refresh object memory
	void dump(void);
	// //draw picture of data vs date
	void Draw_Date(int);
	// //储量
	
};
extern CPRD thePrd;