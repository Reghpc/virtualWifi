#pragma once
#include "stdafx.h"

class VirtualWifiInitBase
{
protected:
  struct  VirtualWifiInitStruct
	{
		CONST_STR sz_c;
		USHORT s_sz_c_len;
	};
private:
	list<VirtualWifiInitStruct> m_lstinitstruct;
	list<VirtualWifiInitStruct>::iterator m_it_lstinitstruct;
	bool m_bcheck_begin;
public:
	bool add_init_command(CONST_STR sz_c,int& ncommandlen); //���ݵ��ֽ���,�Լ������ڴ�
	bool add_init_command(VirtualWifiInitStruct& virtualwifistruct);
	void remove_all_init_command();

	//��ȡ���ݵ���������
	bool has_next();  //�Ƿ�����һ������
	void reset_data(); //����Ϊlist�����
	VirtualWifiInitStruct& current_data(); //��ȡ��ǰָ�������

	VirtualWifiInitBase();
	~VirtualWifiInitBase();
};

