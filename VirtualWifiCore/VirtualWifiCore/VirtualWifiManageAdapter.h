#include "stdafx.h"
#include "VirtualWifiErrorMes.h"


class VirtualWifiManageAdapter:virtual public VirtualWifiException
	,virtual public VirtualWifiErrorMes
{
protected:
	INetSharingManager* pNSM;
	IEnumVARIANT* pAdapterList;
	HRESULT InitAdapterList();
	void  ReleaseNetSharingManger();
	HRESULT InitNetSharingManger();;
private:
	static CONST_STR VIRTUALADAPTERNAME;
	void error_deal(HRESULT hr);
	void free_adapterinfo();
protected:
	IP_ADAPTER_INFO* m_adapterinfo;
	void GetAllAdapterInfo();   //��iphlpApi��ȡ����������Ϣ
public:
	IEnumVARIANT* get_adapterlist();
	VirtualWifiManageAdapter();
	~VirtualWifiManageAdapter();
	string ptchar_to_string(const wchar_t* sz_w);
	string GetVirtualAdapterGuid();
	string wsTos(wstring& ws);
	bool CheckAdapterIsConnected(CONST_STR sz_adapter_name);

	//���ù���
	ADAPTERRET SetSharingAdapter(CONST_STR sz_adapter_name,const char* strVirtualAdpater=VIRTUALADAPTERNAME);
	//ȡ������
	ADAPTERRET UnSharingAdapter(CONST_STR sz_adapter_name); 
};