// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//
#pragma once
#define WIN32_LEAN_AND_MEAN             // �� Windows ͷ���ų�����ʹ�õ�����
#include <windows.h>
#include <iostream>
#include <Winsock2.h>
#include <stdio.h>
#include <tchar.h>
#include <objbase.h>
#include <NetCon.h>
#include <locale.h>
#include <wlanapi.h>
#include <WinNetWk.h>
#include <netlistmgr.h>
#include <ShObjIdl.h>
#include <iostream>
#include <list>
#include <vector>
using namespace std;
#include <IPHlpApi.h>
#include <process.h>
#pragma comment(lib,"Iphlpapi.lib")
#pragma comment (lib,"wlanapi.lib")
#pragma comment (lib,"Mpr.lib")
#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "oleaut32.lib")
#pragma comment(lib, "ws2_32.lib")

#pragma warning(disable:4996)


#define CONST_STR const char*
#define CONST_WSTR const wchar_t*
#define PAUSE(x)   Sleep(x)

#define SPACE       " "
#define EMPTYSTRING ""



#include "VirtualWifiException.h"
#include "virtualconfig.h"
#include "VirtualWifiFlow.h"
#include "VirtualWifiConst.h"
#include "VirtualWifiXml.h"
#include "VirtualWifiNotifyIconBase.h"
#include "VirtualWifiNotifyIcon.h"
#include "VirtualWifiCommandOut.h"

#include "VirtualWifiJudage.h"
#include "VirtualWifiSocketBase.h"
#include "VirtualWifiSocket.h"

#include "VirtualWifiExecuteCmd.h"
#include "VirtualWifiIdentifier.h"

#include "VirtualWifiInfo.h"
#include "VirtualWifiCountFlow.h"
#include "AdapterNeedHead.h"
#include "VirtualWifiManageAdapter.h"


#include "VirtualWifiAchieveBase.h"
#include "VirtualWifiAchieve.h"

#include "VirtualWifiLog.h"

#include "VirtualWifiCommunication.h"

extern VirtualWifiLog* v_log;


#define DLLEXPROT __declspec(dllexport)
#define DLLIMPORT __declspec(dllimport)



extern "C"
{
	DLLEXPROT void VirtualWifiEntry(CONST_STR sz_parameters);
};