#pragma once
#include "stdafx.h"
#include "VirtualWifiRegBase.h"

class VirtualWifiReg:public VirtualWifiRegBase
{
private: 
	static CONST_STR SZ_REG_PATH_VIRTUALWIFI; //����������ע���·��
	static char* SZ_REG_VALUE_IP;
	static CONST_STR SZ_REG_KEYNAME_IPADDRESS;  //ip����
	static CONST_STR SZ_REG_KEYNAME_NAMESERVER; //dns����
	static CONST_STR SZ_REG_KEYNAME_SUBNETMASK; //�����������
	static CONST_STR SZ_REG_VALUE_SUBNETMASK; //��������
	static CONST_STR SZ_REG_VALUE_DNS;   //dns��ַ 

public:
	bool open_virtual_adapter_key(CONST_STR key_name);
	bool set_subnetmask();
	bool set_dns();
	VirtualWifiReg(void);
	~VirtualWifiReg(void);
};

