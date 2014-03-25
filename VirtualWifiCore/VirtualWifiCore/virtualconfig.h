
#include <windows.h>


enum VIRTUALWIFICONFIGERROR
{
	V_OK=0,              //��ȷ
	V_WRONG,  
	V_NOTFINDFILE,     //û���ҵ��ļ�
	V_NOTFINDNODE      //û���ҵ��ڵ�
};
struct VirtualWifiConfigError
{
	VIRTUALWIFICONFIGERROR V_ERROR;
};

struct ConfigInfo:public VirtualWifiConfigError
{
	char* StartPath;   //�������ڵ�·��
	bool AutoRun;
	char* AutoRunPath;
	bool AutoStartWifi;
	bool FlowMonitor; 
	bool ProvinceMemory;
	bool AutoUpdate;
	bool EventBalloonTip;
	bool HasNewClientBalloonTip;
	char* SoundPath;
};

#define GENERALLEN  256
#define IPLEN 24
#define VERSIONLEN 12
struct SoftInfo:public VirtualWifiConfigError
{
	char szTitle[GENERALLEN];
	char szBack[GENERALLEN];
	char szCursor[GENERALLEN];
	char szAddr[IPLEN];
	short sPort;
	char szVersion[VERSIONLEN];
	char szFlowMonitorUi[GENERALLEN];
	char szMainUi[GENERALLEN];
	int nflowmonitor_x;
	int nflowmonitor_y;
};


struct NotifyIconInfo:public VirtualWifiConfigError
{
	char NoStartPath[GENERALLEN];
	char StartPath[GENERALLEN];
	char** DynamicShow;
	int  DynamicNums;
};

#define NETINFOLEN 32
struct NetInfo:public VirtualWifiConfigError
{
	char szSsid[NETINFOLEN];
	char szKey[NETINFOLEN];
	char szAdapter[NETINFOLEN];
};

//�ڵ���Ϣ��ص�
#define  MACLEN 18

struct PeersInfo :public VirtualWifiConfigError
{
	char szMac[MACLEN];
	SHORT sCount;
	char* szRemark;
	PeersInfo* Next;
};


#define CONFIG_DLL_NAME "VirtualWifiConfig.dll"

#define PARSECONFIGFUNNAME "ParseConfigInfo"
#define PARSESOFTFUNNAME "ParseSoftInfo"
#define PARSENETINFOFUNNAME "ParseNetInfo"
#define PARSENOTIFYICONFUNNAME "ParseNotifyIconPath"
#define MODIFYCONFIGFUNNAME "ModifyConfigInfo"
#define MODIFYSOFTFUNNAME "ModifySoftInfo"
#define MODIFYNETINFOFUNNAME "ModifyNetInfo"
#define PARSEPEERHIS "ParsePeerHis"

typedef ConfigInfo*(*pParseConfig)();
typedef SoftInfo*(*pParseSoft)();
typedef NetInfo*(*pParseNetInfo)();
typedef NotifyIconInfo*(*pParseNotify)();
typedef PeersInfo*(*pParsePeerHis)();
typedef bool(*pModifyConfig)(ConfigInfo& config);
typedef bool(*pModifySoft)(SoftInfo& softinfo);
typedef bool(*pModifyNetInfo)(NetInfo& netinfo);


extern pParseConfig ParseConfig;
extern pParseSoft   ParseSoft;
extern pParseNetInfo ParseNetInfo;
extern pParseNotify ParseNotifyIcon;
extern pModifyConfig ModifyConfig;
extern pModifySoft ModifySoft;
extern pModifyNetInfo ModifyNetInfo;
extern pParsePeerHis ParsePeerHis;

bool VirtualWifiConfig_Load();
void VirtualWifiConfig_Release();