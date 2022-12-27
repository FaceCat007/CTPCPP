/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCSERVERSOCKET_H__
#else                                                                            
#define __FCSERVERSOCKET_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#pragma comment(lib, "ws2_32.lib")
#include "winsock2.h"
#include "FCServerSockets.h"
#include "..\\core\\FCLock.h"
#pragma comment (lib,"winmm")

namespace FaceCat{
	typedef enum  {
		RECV_POSTED
	}OPERATION_TYPE;

	typedef struct 
	{
		WSAOVERLAPPED  overlap;
		WSABUF         Buffer;
		char           szMessage[1024];
		DWORD          NumberOfBytesRecvd;
		DWORD          Flags;
		OPERATION_TYPE OperationType;
	}PER_IO_OPERATION_DATA, *LPPER_IO_OPERATION_DATA;

	class __FCSERVERSOCKET_H__ SOCKDATA{
	public:
		SOCKDATA();
		~SOCKDATA();
		char *m_buffer;
		int m_bufferRemain;
		bool m_get;
		int m_head;
		int m_headSize;
		char m_headStr[4];
		int m_index;
		int m_len;
		int m_pos;
		SOCKET m_socket;
		char *m_str;
		int m_strRemain;
		bool m_submit;
		int m_readHead;
	};

	/*
	* 服务端套接字连接
	*/
	class __FCSERVERSOCKET_H__ FCServerSocket{
	public:
		SOCKADDR_IN m_addr;
		HANDLE m_completionPort;
		vector<SOCKDATA*> m_datas;
		SOCKET m_hSocket;
		int m_port;
		RecvMsg m_recvEvent;
		WriteServerLog m_writeLogEvent;
		char m_token[4];
	public:
		/*
		* 创建服务端socket
		*/
		FCServerSocket();
		/*
		* 销毁对象
		*/
		virtual ~FCServerSocket();
		/*
		* 关闭服务端
		*/
		int close(int socketID);
		/*
		* 关闭客户端
		*/
		int closeClient(int socketID);
		/*
		* 接收数据
		*/
		int recv(SOCKDATA *data);
		/*
		* 发送数据
		*/
		static int send(int socketID, const char *str, int len);
		/*
		* 启动TCP
		*/
		int startTCP(int port);
		/*
		* 写日志
		*/
		void writeLog(int socketID, int localSID, int state, const char *log);
	public:
		/*
		* 启动Socket
		*/
		static void wSStart();
		/*
		* 停止Socket
		*/
		static void wSStop();
	public:
        /*
         * 清除缓存的间隔
         */
        int m_clearInterval;
        /*
         * 记录IP的缓存
         */
        map<string, int> m_ipCaches;
        /*
         * 记录缓存的锁
         */
        FCLock m_ipCachesLock;
        /*
         * 上次清理缓存的时间
         */
        double m_lastClearTime;
        /*
         * 限制连接IP的次数
         */
        int m_limitTimes;
		/*
         * IP黑名单
         */
        map<string, int> m_blackIPs;
        /*
         * 黑名单的锁
         */
        FCLock m_blackIPsLock;
        /*
         * 添加IP黑名单
         */
        void addBlackIP(string ip);
        /*
         * 移除IP黑名单
         */
        void removeBlackIP(string ip);
	};
}