#pragma once
#include "stdafx.h"

//�������淢�͹������ַ������н���
class VirtualWifiParse
{
protected:
	NetInfo ParseNetInfo(CONST_STR sz_c);
public:
	VirtualWifiParse(void);
	~VirtualWifiParse(void);
};

