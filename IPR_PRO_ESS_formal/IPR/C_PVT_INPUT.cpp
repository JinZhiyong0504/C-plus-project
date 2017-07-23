// C_PVT_INPUT.cpp : 实现文件
//



// C_PVT_INPUT 消息处理程序


/*

void C_PVT_INPUT::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
	if(UpdateData(true)!=0)
	{
	//UpdateData(false);
	char Ct_string[10],N_string[20],INI_PRESSURE_string[20],N_stage_string[20],P_reasonable_ctring[20],Swc_ctring[20];
	//GetDlgItem(IDC_PRESS_INI)->GetWindowText(Ct_string,10);
	SendDlgItemMessage(IDC_PRESS_INI,WM_GETTEXT,20,(LPARAM)INI_PRESSURE_string);
	SendDlgItemMessage(IDC_RESERVE,WM_GETTEXT,20,(LPARAM)N_string);
	SendDlgItemMessage(IDC_Swc,WM_GETTEXT,20,(LPARAM)Swc_ctring);
	SendDlgItemMessage(IDC_STAGE,WM_GETTEXT,20,(LPARAM)N_stage_string);
	SendDlgItemMessage(IDC_COMPRESSIBLITY,WM_GETTEXT,20,(LPARAM)Ct_string);	
	SendDlgItemMessage(IDC_PRESSURE_REASON,WM_GETTEXT,20,(LPARAM)P_reasonable_ctring);	


	INI_PRESSURE_input=atof(INI_PRESSURE_string);
	N_input=atof(N_string);
	// 储量
	Swc_input=atof(Swc_ctring);
	// 合理地层压力
	P_reasonable_input=atof(P_reasonable_ctring);
	// 地层压缩系数
	Ct_input=atof(Ct_string);
	// 压缩系数
	N_stage_input=atoi(N_stage_string);
	// 阶段划分

	theApp.stage=N_stage_input;
	theApp.Compressibility=Ct_input;
	theApp.Conate_Water_Saturation=Swc_input;
	theApp.Ini_pressure=INI_PRESSURE_input;
	theApp.N_reserves=N_input;
	theApp.Pressure_reasonable=P_reasonable_input;	

	EndDialog(1);

	}
	else
	{
	}
}
*/