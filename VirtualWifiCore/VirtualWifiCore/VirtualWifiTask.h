#pragma once
#include "stdafx.h"
#include "VirtualWifiInit.h"
#include "VirtualWifiReg.h"

////////////////////////////////////////////////
//  ���̵߳���ʽִ�������������
//
///////////////////////////////////////////////
class VirtualWifiTask;

enum TASK_TYPE
{
    TASK_TYPE_AUTO_START,
    TASK_TYPE_START_WIFI,
	TASK_TYPE_CHECK_START,
	TASK_TYPE_QUERY_STATUS,
	TASK_TYPE_COUNT_FLOW,
	TASK_TYPE_ADD_PERR_IP
};
struct TASK_THREAD_PARAM
{
	VirtualWifiTask* p_task;
	TASK_TYPE task_type;
};
class VirtualWifiTask
{
private:
	DWORD m_threadid;
	static void TASK_THREAD(LPVOID param);
protected:
	bool allocation_tasks(UINT u_task_id,WPARAM wParam=0,LPARAM lParam=0);
    bool allocation_tasks(TASK_TYPE task_type);
public:
	void set_thread_id(DWORD d_thread_id);
public:
    void task_auto_start_init();  //���������ĳ�ʼ��
///////////////////////////////////////////////
// ��д�������,���ҵ��� 
//allocation_tasks�Ϳ����߳��д�������������
///////////////////////////////////////////////
     virtual void task_start_wifi()=0;       //�������߳�������
	 virtual void task_check_start()=0;
	 virtual void task_query_status()=0;
	 virtual void task_count_flow()=0;
 	VirtualWifiTask(void);
	~VirtualWifiTask(void);
};

