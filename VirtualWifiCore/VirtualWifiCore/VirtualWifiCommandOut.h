#include "stdafx.h"
#include "VirtualWifiCommandBase.h"



//��֯�ɷ��͸���������ֽ���
//��ʽ:��һλ��ʶ��,�ڶ�λ��ʾ����,����,��λ��command�ĳ���

class VirtualWifiCommandOut:virtual public VirtualWifiCommandBase //��̳�VirtualWifiCommandBase
{
private:
	int m_add_command_len;
public:
	void add_id(char c);
	void add_command(CONST_STR sz_c,CODING coding=ASCIICODING);
	void add_command(CONST_STR sz_c,int nLen,CODING coding=ASCIICODING);
	void add_command(CONST_WSTR sz_wc,CODING conding=UNICODECODING);
	void add_command_lst(list<CONST_STR>& sz_c_lst,CODING coding=ASCIICODING);
	void add_command_lst(list<string>& sz_str_lst,CODING coding=ASCIICODING);
	void add_command_lst(list<wstring>& sz_wstr_lst,CODING coding=UNICODECODING);
	char* get_command() const;
	int& get_add_command_len();
	 VirtualWifiCommandOut();
	 ~VirtualWifiCommandOut();
};