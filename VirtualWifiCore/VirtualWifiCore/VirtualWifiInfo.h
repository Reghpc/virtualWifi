#include "stdafx.h"


#include <pcap.h>
#pragma comment(lib,"VirtualWifiInfo.lib")
#define VIPLEN 16


/* 4�ֽ�IP��ַ */
typedef struct ip_address{
	u_char byte1;
	u_char byte2;
	u_char byte3;
	u_char byte4;
}ip_address;

//Mac֡ͷ ռ14���ֽ�
typedef struct tag_mac_header
{
	u_char dadd[6];//6���ֽ� Ŀ���ַ
	u_char sadd[6];//6���ֽ� Դ��ַ
	u_short mac_type;//2���ֽ� ����
}mac_header;

typedef struct ip_header{
	u_char  ver_ihl;   	// 4 bit�İ汾��Ϣ + 4 bits��ͷ��
	u_char  tos;        	// ��������
	u_short tlen;        	// �ܳ���
	u_short identification; 	// ��ʶ����
	u_short flags_fo;      	// Flags (3 bits) + Fragment offset (13 bits)
	u_char  ttl;          	// ������
	u_char  proto;      	// Э��
	u_short crc;         	// У��ͷ
	ip_address  saddr; 	// Դ��ַ
	ip_address  daddr;   	// Ŀ���ַ
	u_int   op_pad;     	// Option + Padding
}ip_header;

typedef unsigned int u_int32_t;
//����TCPͷ
typedef struct tag_tcp_header
{
	u_short sport;//Դ�˿ڵ�ַ  16λ
	u_short dport;//Ŀ�Ķ˿ڵ�ַ 16λ
	u_int32_t sn;//���к� 32λ
	u_int32_t an;//ȷ�Ϻ� 32λ
	u_int16_t other;//16λ ���� ͷ����4λ������6λ��UPG1+ACK1+PSH1+RST1+SYN1+FIN1 
	u_int16_t window_size;//���ڴ�С 16λ
	u_int16_t check_sum;//У��� 16λ
	u_int16_t urgent_pointer;//����ָ�� 16λ
	u_int32_t option;//ѡ��0��32λ
}tcp_header;

//����UDPͷ
typedef struct tag_udp_header
{
	u_short sport;//Դ�˿�  16λ
	u_short dport;//Ŀ�Ķ˿� 16λ
	u_short len;//���ݱ����� 16λ
	u_short crc;//У��� 16λ

}udp_header;


enum IP_TYPE
{
	IP_TYPE_LOCAL_NETWORK,   //����
	IP_TYPE_EXTERNAL_NETWORK, //����
	IP_TYPE_INVALID_NETWORK,  /* ��ЧIP*/
	IP_TYPE_MULTICAST_NETWORK,/*�鲥��ַ*/
	IP_TYPE_UNKOWN
};

/************************************************************************/
/*  ����IP
    10.x.x.x
����172.16.x.x��172.31.x.x
    192.168.x.x   
/*  ��ЧIP
    169.254.x.x
/*  �鲥��ַ 
    224.0.0.0��239.255.255.255
/************************************************************************/
class __declspec(dllexport) VirtualWifiIp
{
private:
	static DWORD NETWORK_192_168;
	static DWORD NETWORK_10;
	static DWORD NETWORK_172;
	static DWORD NETWORK_169_254;
	static DWORD NETWORK_224;
	static DWORD NETWORK_239;
private:
	char m_ip[IPLEN];
	IP_TYPE m_ip_type;
public:
	IP_TYPE reset_ip_type();/*�ж�IP��ַ������*/

	void set_ip(CONST_STR sz_ip);
	void set_ip(ip_address& ia);
	CONST_STR get_ip();
	IP_TYPE get_ip_type();
	bool operator==(VirtualWifiIp& ip);
	VirtualWifiIp(ip_address& ia);
	VirtualWifiIp(CONST_STR sz_ip="0.0.0.0");
	~VirtualWifiIp(void);
};



#define GUIDLEN 64
class __declspec(dllimport) VirtualWifiAdapter
{
protected:
	char* m_sz_name;
	char* m_des;
	VirtualWifiIp* m_ip;
	char m_guid[GUIDLEN];
	bool m_is_init;
	UINT m_type;
	NETCON_STATUS m_status;
	u_int m_netmask;
public:
	VirtualWifiIp* get_v_ip();
	UINT get_type();
	NETCON_STATUS get_status();
	u_int get_netmask();
	CONST_STR get_des();
	CONST_STR get_guid();
	CONST_STR get_name();

	void set_adapter_info(PIP_ADAPTER_INFO adapter_info);
	void set_adapter_info(pcap_if_t* pcapinfo);
	void set_adapter_info(NETCON_PROPERTIES* netconinfo);
	void set_adapter_info(VirtualWifiAdapter* adapters,VirtualWifiAdapter* netconinfo);
	void set_adapter_info_(VirtualWifiAdapter* adapters,VirtualWifiAdapter* pcapadapter);
	void set_adapter_info(CONST_STR sz_name);

	void release();
	VirtualWifiAdapter();
	VirtualWifiAdapter(PIP_ADAPTER_INFO adapter_info);
	VirtualWifiAdapter(pcap_if_t* pcapinfo);
	VirtualWifiAdapter(NETCON_PROPERTIES* netconinfo);

	~VirtualWifiAdapter(void);
};


/************************************************************************/
/* ͨ��IPHlpApi��ȡ����NetShare��ȡ����ϣ�������������GUID��                                                                     */
/************************************************************************/
class __declspec(dllimport) VirtualWifiManageAdapterEx
{
protected:
	VirtualWifiAdapter* m_adapters;
	int m_adapter_total;
private:
	void release();
public:
	VirtualWifiManageAdapterEx();
	void reset_integrate_adapter();/*����2�ַ�����ȡ����������Ϣ����������*/
	VirtualWifiAdapter* get_adapters() const;
	VirtualWifiAdapter* get_external_ip_adapters() const;
	VirtualWifiAdapter* get_connected_ppp_adapters() const;
	VirtualWifiAdapter* get_local_ip_adapters() const;

	void reset_integrate_pcap_adapter();/*����pcap��iphlpApi������ȡ��Ϣ������*/

	VirtualWifiAdapter* get_virtual_adapter() const;
	int get_adapter_total() const;
};

#define TIMELEN  48

class __declspec(dllimport) VirtualWifiTime
{
private:
	char m_sz_time[TIMELEN];
protected:
	byte m_hour;
	byte m_min;
	byte m_sec;
	struct tm m_fmt;
protected:
	void set_time(byte m_hour=0,byte m_min=0,byte m_sec=0);
public:
	byte get_hour();
	byte get_min();
	byte get_sec();
public:
	static VirtualWifiTime get_now_time();
	CONST_STR string();
	VirtualWifiTime(byte m_hour=0,byte m_min=0,byte m_sec=0);
	int operator-(VirtualWifiTime& time);
	bool operator=(VirtualWifiTime& time);
	VirtualWifiTime(const time_t t);
	~VirtualWifiTime(void);
};



enum protocol
{
	TCP=6,
	UDP=17
};

#define NAMELEN 128
class _declspec(dllimport)  VirtualWifiCountFlowBase:virtual public VirtualWifiException
{
private:
	pcap_t * m_adhandle;
	string data_filter(CONST_STR sz_ip);
protected:
	int m_timeout;
	float m_timesec;/*��λΪ��*/
	float m_dtimeout;
protected:
	virtual void handle_data(struct pcap_pkthdr *header,const u_char *pkt_data)=0;
	virtual void handle_data_timeout(struct pcap_pkthdr *header)=0;
public:
	bool init_pcap(VirtualWifiAdapter* adapter,int n_timeout=900);
	int start_capture_flow();
	VirtualWifiCountFlowBase(void);
	~VirtualWifiCountFlowBase(void);
};
