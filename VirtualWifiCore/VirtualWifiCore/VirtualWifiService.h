#pragma once
#include "stdafx.h"

//��������Ҫ�ķ���
class VirtualWifiService
{
private:
	SC_HANDLE m_hSC;
public:
	DWORD CheckServiceStatus(CONST_STR pServiceName);
	DWORD StartService(CONST_STR pServiceName);
	DWORD StopService(CONST_STR pServiceName);
	void  PrintAllService();
	VirtualWifiService(void);
	~VirtualWifiService(void);
};

