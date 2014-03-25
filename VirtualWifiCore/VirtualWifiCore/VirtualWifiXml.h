#include "stdafx.h"

class VirtualWifiConfig
{
protected:
	ConfigInfo* m_configinfo;
public:
	VirtualWifiConfig();
	void modify_config();
};

class VirtualWifiSoft
{
private:
	char* m_version_mainui_title;     //���а汾��Ϣ��
	char* m_version_title;
	void parse_title();
	void parse_mainui_title();
protected:
	SoftInfo* m_softinfo;
	CONST_STR m_warninginfo; //��������ʱ�ľ�����Ϣ
	void check_flowmonitor_pos(); /*���������������X,Y����*/
public:
	void get_title(char* sz_title,int& n_title_buffer_len);
	char* get_title() const;
	char* get_mainui_title() const;
	void modify_soft();
	VirtualWifiSoft();
	~VirtualWifiSoft();
};


class VirtualWifiNetInfo
{
protected:
	NetInfo* m_netinfoex;
public:
	void modify_netinfo();
	NetInfo* parse_netinfoex(CONST_STR sz_parse_c); //�����ַ�������NetInfo
	VirtualWifiNetInfo();
};
class VirtualPeerHis
{
protected:
	PeersInfo* m_peerHis;
public:
	VirtualPeerHis();
};
class VirtualWifiNotifyIconInfo
{
protected:
	NotifyIconInfo* m_notifyiconinfo;
public:
	
    VirtualWifiNotifyIconInfo();
};