/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCCLIENTSOCKET_H__
#else                                                                            
#define __FCCLIENTSOCKET_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#pragma comment(lib, "ws2_32.lib")
#include "winsock2.h"
#include <time.h> 
#include <string>  
#include <vector>  
#include "CBase64.h"
#include "FCClientSockets.h"
using namespace std;  

namespace FaceCat{ 
	enum ConnectStatus{  
		SUCCESS,  
		CONNECT_PROXY_FAIL,  
		NOT_CONNECT_PROXY,  
		CONNECT_SERVER_FAIL  
	};

	struct TSock4req1{   
		char VN;   
		char CD;   
		unsigned short Port;   
		unsigned long IPAddr;   
		char other;   
	};   
  
	struct TSock4ans1{   
		char VN;   
		char CD;   
	};  
  
	struct TSock5req1{   
		char Ver;   
		char nMethods;   
		char Methods;   
	};   
  
	struct TSock5ans1{   
		char Ver;   
		char Method;   
	};   
  
	struct TSock5req2{   
		char Ver;   
		char Cmd;   
		char Rsv;   
		char Atyp;   
		char other;   
	};   
  
	struct TSock5ans2{   
		char Ver;   
		char Rep;   
		char Rsv;   
		char Atyp;   
		char other;   
	};   
  
	struct TAuthreq{   
		char Ver;   
		char Ulen;   
		char Name;   
		char PLen;   
		char Pass;   
	};   
  
	struct TAuthans{   
		char Ver;   
		char Status;   
	};   
  
	/*
	* 客户端套接字连接
	*/
	class __FCCLIENTSOCKET_H__ FCClientSocket{
		bool m_blnProxyServerOk;
		string m_ip;
		u_short m_port;
		string m_proxyDomain;
		int m_proxyType;  
		string m_proxyIp;  
		u_short m_proxyPort; 
		string m_proxyUserName;  
		string m_proxyUserPwd;
		int m_timeout;
	private:
		/*
		* 标准连接
		*/
		ConnectStatus connectStandard();
		/*
		* Http连接
		*/
		ConnectStatus connectByHttp();  
		/*
		* Sock4连接
		*/
		ConnectStatus connectBySock4();  
		/*
		* Sock5连接
		*/
		ConnectStatus connectBySock5(); 
		/*
		* 创建socket
		*/
		void createSocket();
	public:
		SOCKADDR_IN m_addr;
		SOCKET m_hSocket;
		RecvMsg m_recvEvent;
		WriteClientLog m_writeLogEvent;
	public:
		/*
		* 创建客户端socket
		*/
		FCClientSocket(int proxyType, const string &ip, u_short port, const string &proxyIp, u_short proxyPort, const string &proxyUserName, const string &proxyUserPwd, const string &proxyDomain, int timeout);
		/*
		* 销毁对象
		*/
		virtual ~FCClientSocket();
	public:
		/*
		* 关闭
		*/
		int close(int socketID);
		/*
		* 连接
		*/
		ConnectStatus connect(); 
		/*
		* 代理连接
		*/
		ConnectStatus connectProxyServer();
		/*
		* 获取主机IP
		*/
		static string getHostIP(const char* ip);
		/*
		* 发送消息
		*/
		static int send(int socketID, const char *str, int len);
		/*
		* 打印日志
		*/
		void writeLog(int socketID, int localSID, int state, const char *log);
	};  
}
