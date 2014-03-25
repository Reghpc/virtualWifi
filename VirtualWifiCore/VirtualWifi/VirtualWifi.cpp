// VirtualWifi.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


VirtualWifiEntry Entry;
int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	char strAppName[] ="OnlyOne";
	HANDLE hMutex = NULL;
	hMutex = CreateMutex(NULL, FALSE, strAppName);
     if(hMutex != NULL)  
	 {
		 if (GetLastError() == ERROR_ALREADY_EXISTS)//���г���������
         {
			 CloseHandle(hMutex);
			 return -1;
		 }
	 }
  Entry=(VirtualWifiEntry)GetProcAddress(LoadLibraryA("VirtualWifiCore.dll"),"VirtualWifiEntry");
  Entry(lpCmdLine);
    while (true)
   {
	   Sleep(300000);
   }
	return 0;
}
