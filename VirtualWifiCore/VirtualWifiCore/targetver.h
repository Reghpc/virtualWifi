#pragma once

#ifndef WINVER                          // ָ��Ҫ������ƽ̨�� Windows Vista��  
//#define WINVER 0x0600           // ����ֵ����Ϊ��Ӧ��ֵ���������� Windows �������汾��  
#define WINVER 0x0501   
#endif  
#ifndef _WIN32_WINNT            // ָ��Ҫ������ƽ̨�� Windows Vista��  
//#define _WIN32_WINNT 0x0600     // ����ֵ����Ϊ��Ӧ��ֵ���������� Windows �������汾��  
#define WINVER 0x0501   
#endif 
#include <SDKDDKVer.h>