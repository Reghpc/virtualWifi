#pragma once

class VirtualWifiDriver:virtual VirtualWifiExecuteCmd
{
private:
	static CONST_STR SZ_SUPPORT_WIFI;
private:
	static CONST_STR SZ_SHOW_DRIVER;
private:
	bool m_is_support_wifi; //�Ƿ�֧�ֳ�������
public:
	bool get_is_support_wifi();
	VirtualWifiDriver(void);
	~VirtualWifiDriver(void);
};

