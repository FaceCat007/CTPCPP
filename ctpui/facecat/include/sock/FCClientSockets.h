/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCCLIENTSOCKETS_H__
#else                                                                            
#define __FCCLIENTSOCKETS_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
using namespace std;  

namespace FaceCat{ 
	typedef void (__stdcall *RecvMsg)(int socketID, int localSID, const char *str, int len);

	typedef void (__stdcall *WriteClientLog)(int socketID, int localSID, int state, const char *log);

	/*
	* 客户端套接字连接管理
	*/
	class __FCCLIENTSOCKETS_H__ FCClientSockets{
	public:
		/*
		* 消息回调
		*/
		static void __stdcall recvServerMsg(int socketID, int localSID, const char *str, int len);
		/*
		* 日志回调
		*/ 
		static void __stdcall writeLog(int socketID, int localSID, int state, const char *log);
	public:
		/*
		* 关闭连接
		*/
		static int close(int socketID);
		/*
		* 连接
		*/
		static int connect(int proxyType, const char *ip, int port, const char *proxyIp, int proxyPort, const char *proxyUserName, const char *proxyUserPwd, const char *proxyDomain, int timeout);
		/*
		* 注册日志回调
		*/
		static void registerLog(WriteClientLog writeLogCallBack);
		/*
		* 注册消息回调
		*/
		static void registerRecv(RecvMsg recvMsgCallBack);
		/*
		* 发送数据
		*/
		static int send(int socketID, const char *str, int len);
	};
}