#pragma once
#include "stdafx.h"
#include "VirtualWifiRegBase.h"

///////////////////////////////////////////////////////////////
//   �ж��Ƿ�֧�ֳ�������
//   ����ע���,�ж��Ƿ�Ϊ��һ������,��������ϵͳ
//   �����һ������,��������������GUID,��д��ע��� 
//   д���ע���λ��Ϊ HKEY_CURRENT_USER\Software
///////////////////////////////////////////////////////////////

class VirtualWifiInit:virtual public VirtualWifiAchieve
	,virtual public VirtualWifiErrorMes
	,virtual public VirtualWifiSoft
	,virtual public VirtualWifiExecuteCmd
{
protected:
	char* m_virtualwifiadapter_guid;
protected:
    virtual void init_wifi()=0; //���������һ������,��Ҫ���͵���Ϣ
	virtual void init_wifi_account()=0;   //��ȡ��ǰ���ʺ�
	virtual void init_wifi_adapter()=0;
	virtual void init_wifi_selected_adapter()=0;
	virtual void init_wifi_soft()=0;    //���������Ϣ
	virtual void init_wifi_config()=0;

	//����ʱ���
	virtual bool start_check()=0;
protected:
	static CONST_STR SZ_WRITE_PATH;
	static CONST_STR SZ_VIRTUALWIFIADAPTERGUID;
protected:
	VirtualWifiRegBase m_reg;
	VirtualWifiAchieveBase m_achieve;
	CONST_STR m_key_name;
	virtual bool get_reg_info();
	virtual bool create_new_reg();
public:
	VirtualWifiInit();  
	virtual bool init_check();
	~VirtualWifiInit(void);
};

