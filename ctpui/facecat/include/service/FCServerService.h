/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCSERVERSERVICE_H__
#else                                                                            
#define __FCSERVERSERVICE_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCBinary.h"
#include <string>
#include <map>
using namespace std;

#define  COMPRESSTYPE_NONE			  0
#define  COMPRESSTYPE_GZIP			  1

static int m_requestID = 10000;

namespace FaceCat{	
	/**
	 * 消息结构
	 */
	struct __FCSERVERSERVICE_H__ FCMessage{
	public:
	    /**
		 * 创建消息
		 */
		FCMessage();
		/**
		* 创建消息
		* @param  serviceID  服务ID
		* @param  functionID  功能ID
		* @param  requestID  请求ID
		* @param  socketID  连接ID
		* @param  state  状态
		* @param  compressType  压缩类型
		* @param  bodyLength  包体长度
		* @param  body  包体
		*/
		FCMessage(int serviceID, int functionID, int requestID, int socketID, int state, int compressType, int bodyLength, char *body); 
		int m_serviceID;   
		int m_functionID;   
		int m_requestID;   
		int m_socketID; 
		int m_state;
		int m_compressType;
		int m_bodyLength;  
		char *m_body;
		int m_signal;
		/**
		 * 复制数据
		 */
		void copy(FCMessage *message)
		{
			m_serviceID = message->m_serviceID;
			m_functionID = message->m_functionID;
			m_requestID= message->m_requestID;
			m_socketID = message->m_socketID;
			m_state = message->m_state;
			m_compressType = message->m_compressType;
			m_bodyLength = message->m_bodyLength;
			m_body = message->m_body;
		}
	};

	typedef void (__stdcall *MessageCallBack)(int socketID, int localSID, const char *str, int len);

	typedef void (__stdcall *WriteLogCallBack)(int socketID, int localSID, int state, const char *log);

	/*
	* 监听消息
	*/
    class __FCSERVERSERVICE_H__ FCListenerMessageCallBack {
	public:
		virtual void callListenerMessageEvent(Object sender, FCMessage *message, Object invoke){}
    };

	/*
	* 消息监听
	*/
	class __FCSERVERSERVICE_H__ FCMessageListener{
	private:
	    /**
		 * 监听回调列表
		 */
		vector<FCListenerMessageCallBack*> m_callBacks;
		vector<Object> m_callBackInvokes;
	public:
	    /**
		 * 创建消息监听
		 */
		FCMessageListener();
		/*
		* 销毁对象
		*/
		virtual ~FCMessageListener();
	public:
	    /**
		 * 添加回调
		 */
		void add(FCListenerMessageCallBack *callBack, Object pInvoke);
		/**
		 * 回调方法
		 */
		void callBack(FCMessage *message);
		/**
		 * 清除监听
		 */
		void clear();
		/**
		 * 移除回调
		 */
		void remove(FCListenerMessageCallBack *callBack);
	};

	/*
	* 数据回调
	*/
	class __FCSERVERSERVICE_H__ FCDataEventCallBack{
	public:
		/*
		* 回调方法
		*/
		virtual bool callDataEvent(int socketID, int localSID, const char *str, int len){return false;}
	};

	/*
	* 套接字组
	*/
	class __FCSERVERSERVICE_H__ FCSocketArray{
	private:
	    /**
		 * 套接字ID组
		 */
		vector<int> m_sockets;
	public:
		/*
		* 创建对象
		*/
		FCSocketArray();
		/*
		* 销毁对象
		*/
		virtual ~FCSocketArray();
	public:
	    /**
		 * 添加套接字ID
		 */
		void addSocket(int socketID);
		/**
		* 获取套接字列表
		* @param  socketList  套接字列表
		*/
		void getSocketList(vector<int> *socketList);
		/**
		 * 移除套接字ID
		 */
		void removeSocket(int socketID);
	};

	/*
	* 服务端SOCKET服务
	*/
	class __FCSERVERSERVICE_H__ FCServerService{
	public:
		/*
		* 压缩类型
		*/
		int m_compressType;
		/**
		 * 压缩类型集合
		 */
		map<int, int> m_compressTypes;
		/**
		 * 监听者集合
		 */
		map<int, FCMessageListener*> m_listeners;
		/**
		 * 服务的ID
		 */
		int m_serviceID;
		/**
		* 套接字ID
		*/
		int m_socketID;
		/**
		 * 等待消息队列
		 */
		map<int, FCMessage*> m_waitMessages;
	public:
		/*
		* 锁
		*/
		FCLock m_lock;
	public:
		/**
		* 关闭
		* @param  socketID  连接ID
		*/
		static int closeServer(int socketID);
		/**
		* 注册回调
		* @param  callBack  回调函数
		*/
		static void registerCallBack(MessageCallBack callBack);
		/**
		* 注册日志
		* @param  callBack  回调函数
		*/
		static void registerLog(WriteLogCallBack callBack);
		/**
		* 发送消息
		* @param  socketID  连接ID
		* @param  str  数据
		* @param  len  长度
		*/
		static int sendByServer(int socketID, const char *str, int len);
		/**
		* 启动
		* @param  port  端口
		*/
		static int startServer(int port);
	public:
		/*
		* 构造函数
		*/
		FCServerService();
		/*
		* 析构函数
		*/
		virtual ~FCServerService();
		/**
		 * 获取压缩类型
		 */
		int getCompressType();
		/**
		 * 设置压缩类型
		 */
		void setCompressType(int value);
		/**
		 * 获取下载流量
		 */
		static Long getDownFlow();
		/**
		 * 设置下载流量
		 */
		static void setDownFlow(Long value);
		/**
		 * 获取服务的ID
		 */
		int getServiceID();
		/**
		 * 设置服务的ID
		 */
		void setServiceID(int value);
		/*
		* 获取套接字ID
		*/
		int getSocketID();
		/*
		* 设置套接字ID
		*/
		void setSocketID(int value);
		/**
		 * 获取上传流量
		 */
		static Long getUpFlow();
		/**
		 * 设置上传流量
		 */
		static void setUpFlow(Long value);
	public:
		/*
		* 添加回调
		*/
		static void addDataCallBack(FCDataEventCallBack *dataCallBack);
		/**
		* 添加服务
		* @param  service  服务
		*/
		static void addService(FCServerService *service);
		/*
		* 数据回调
		*/
		static void __stdcall callBack(int socketID, int localSID, const char *str, int len);
		/**
		 * 获取请求ID
		 */
		static int getRequestID();
		/**
		* 获取所有的服务
		* @param  service  服务
		*/
		static void getServices(vector<FCServerService*> *services);
		/**
		* 保持活跃
		* @param  socketID  套接字ID
		*/
		virtual int keepAlive(int socketID);
		/**
		* 收到消息
		* @param  br  流
		* @param  socketID  套接字ID
		* @param  localSID  本地套接字ID
		* @param  len  长度
		*/
		virtual void onCallBack(FCBinary *binary, int socketID, int localSID, int len);
		/**
		* 客户端关闭方法
		* @param  socketID  连接ID
		* @param  localSID  本地连接ID
		*/
		virtual void onClientClose(int socketID, int localSID);
		/*
		* 客户端连接方法
		*/
		virtual void onClientConnect(int socketID, int localSID, String ip);
		/*
		* 接收数据
		* @param  message  消息
		*/
		virtual void onReceive(FCMessage *message);
		/**
		 * 等待消息的处理
		 */
		virtual void onWaitMessageHandle(FCMessage *message);
		/**
		 * 注册数据监听
		 */
		virtual void addListener(int requestID, FCListenerMessageCallBack *callBack, Object pInvoke);
		/**
		 * 注册等待
		 */
		virtual void addWait(int requestID, FCMessage *message);
		/**
		 * 发送消息
		 */
		virtual int send(FCMessage *message);
		/**
		 * 发送到监听者
		 */
		virtual void sendToListener(FCMessage *message);
		/*
		* 移除回调
		*/
		static void removeDataCallBack(FCDataEventCallBack *dataCallBack);
		/**
		 * 取消注册数据监听
		 */
		virtual void removeListener(int requestID);
		/**
		 * 取消注册监听
		 */
		virtual void removeListener(int requestID, FCListenerMessageCallBack *callBack);
		/**
		 * 取消注册等待
		 */
		virtual void removeWait(int requestID);
		/**
		 * 等待消息
		 */
		virtual int waitMessage(int requestID, int timeout);
		/**
		* 写日志
		* @param  socketID  连接ID
		* @param  localSID  本地连接ID
		* @param  state  状态
		* @param  log  日志
		*/
		static void __stdcall writeServerLog(int socketID, int localSID, int state, const char *log);
	};
}