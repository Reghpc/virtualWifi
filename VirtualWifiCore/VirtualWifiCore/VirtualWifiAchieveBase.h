#pragma once
#include "stdafx.h"
#include "VirtualWifiErrorMes.h"
#include "VirtualWifiBase.h"

class VirtualWifiAchieveBase:virtual public VirtualWifiConfig
	,virtual public VirtualWifiBase
	 ,virtual public VirtualWifiConst
	 ,public VirtualWifiManageAdapter
{
private:
	static CONST_STR SET_SUCCESS;
	static CONST_STR SET_SUCCESS_I;
	static CONST_STR START_SUCCESS;
	static CONST_STR STOP_SUCCESS;
	static CONST_STR DISALLOW_SUCCESS;
private:
	static const DWORD CLIENTVERSION_WIN7;
	static char* SZ_SET_SSID_KEY_CMD;
	static CONST_STR SZ_DISALLOW_WIFI;
	static CONST_STR SZ_ALLOW_WIFI;
	static CONST_STR SZ_START_WIFI; //�������߳�����������
	static CONST_STR SZ_STOP_WIFI;
private:
	void analysis_fail_reason();
public:
	bool start_wifi_cmd();  //��cmd�����
	bool StartWifi();  //��api��������
	bool stop_wifi_cmd();
    bool StopWifi();
    bool SetSsidAndKey(char* szSsid,char* szKey);
	bool AutoRun(CONST_STR start_name);  //���ÿ�������
	bool UnAutoRun(CONST_STR start_name);                    //ɾ������������
	bool disallow_wifi_cmd();                       //ɾ����������
	bool allow_wifi_cmd();
	bool set_adapter_info();   //����ip.dns
	VirtualWifiAchieveBase();
	~VirtualWifiAchieveBase();
};

