#include "stdafx.h"

#define MAX_COMMAND_LEN 512

class VirtualWifiExecuteCmd //ִ��cmd����
{
private:
	static const char* SZ_PREFIX;
	static const int N_PREFIX_LEN;
private:
	void AddCommand(char* szcommand);
protected:
	bool   m_isaddcommand;
	char  m_szcommand[MAX_COMMAND_LEN];
	string m_reslut;
public:
	VirtualWifiExecuteCmd(char* szcommand=EMPTYSTRING);
	virtual bool Execute(char* szcommand=EMPTYSTRING);  //ִ������
	const char* GetReslut();    //��ȡ����ִ��������
};