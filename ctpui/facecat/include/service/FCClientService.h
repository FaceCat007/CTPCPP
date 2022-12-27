/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCCLIENTSERVICE_H__
#else                                                                            
#define __FCCLIENTSERVICE_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCBinary.h"
#include "FCServerService.h"
#include <string>
#include <map>
using namespace std;

#define  DOWNHELPER_AGENTNAME         "SECURITY"  
#define  LEN_OF_BUFFER_FOR_QUERYINFO  128  
#define  MAX_DOWNLOAD_REQUEST_TIME    10   

namespace FaceCat{
	/*
	* 客户端SOCKET服务
	*/
	class __FCCLIENTSERVICE_H__ FCClientService{
	private:
		/*
		* 锁
		*/
		FCLock m_lock;
		/**
		 * 压缩类型
		 */
		int m_compressType;
		/**
		 * 监听者集合
		 */
		map<int, FCMessageListener*> m_listeners;
		/**
		 * 服务的ID
		 */
		int m_serviceID;
		/**
		 * 等待消息队列
		 */
		map<int, FCMessage*> m_waitMessages;
	public:
		/**
		* 关闭
		* @param  socketID  连接ID
		*/
		static int closeClient(int socketID);
		/**
		* 连接
		* @param  proxyType  代理类型
		* @param  ip  地址
		* @param  port  端口
		* @param  proxyIp  代理地址
		* @param  proxyPort  代理端口
		* @param  proxyUserName  代理名称
		* @param  proxyUserPwd  代理密码
		* @param  proxyDomain  代理域
		* @param  timeout  超时
		*/
		static int connectToServer(int proxyType, const char *ip, int port, const char *proxyIp, int proxyPort, const char *proxyUserName, const char *proxyUserPwd, const char *proxyDomain, int timeout, char *token);
		/**
		 * 注册回调
		 */
		static void registerCallBack(MessageCallBack callBack);
		/**
		 * 注册日志
		 */
		static void registerLog(WriteLogCallBack callBack);
		/**
		* 发送消息
		* @param  socketID  连接ID
		* @param  str   数据
		* @param  len  长度
		*/
		static int sendByClient(int socketID, const char *str, int len);
	public:
		/*
		* 构造函数
		*/
		FCClientService();
		/*
		* 析构函数
		*/
		virtual ~FCClientService();
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
		static void addService(FCClientService *service);
		/**
		* 回调函数
		* @param  socketID  连接ID
		* @param  localSID  本地连接ID
		* @param  str  数据
		* @param  len  长度
		*/
		static void __stdcall callBack(int socketID, int localSID, const char *str, int len);
		/**
		 * 获取请求ID
		 */
		static int getRequestID();
		/**
		 * 获取所有的服务
		 */
		static void getServices(vector<FCClientService*> *services);
		/**
		 * 保持活跃
		 */
		int keepAlive(int socketID);
		/**
		 * 收到消息
		 */
		virtual void onCallBack(FCBinary *binary, int socketID, int localSID, int len);
		/**
		* 客户端断开方法
		*/
		virtual void onClientClose(int socketID, int localSID);
		/**
		* 客户端连接方法
		*/
		virtual void onClientConnect(int socketID, int localSID);
		/**
		 * 接收数据
		 */
		virtual void onReceive(FCMessage *message);
		/**
		 * 等待消息的处理
		 */
		virtual void onWaitMessageHandle(FCMessage *message);
		/**
		* 注册数据监听
		* @param  requestID 请求ID
		* @param  callBack  回调函数
		*/
		void addListener(int requestID, FCListenerMessageCallBack *callBack, Object pInvoke);
		/**
		 * 注册等待
		 */
		void addWait(int requestID, FCMessage *message);
		/**
		 * 发送消息
		 */
		virtual int send(FCMessage *message);
		/**
		 * 发送到监听者
		 */
		void sendToListener(FCMessage *message);
		/*
		* 移除回调
		*/
		static void removeDataCallBack(FCDataEventCallBack *dataCallBack);
		/**
		 * 取消注册数据监听
		 */
		void removeListener(int requestID);
		/**
		 * 取消注册监听
		 */
		void removeListener(int requestID, FCListenerMessageCallBack *callBack);
		/**
		 * 取消注册等待
		 */
		void removeWait(int requestID);
		/**
		 * 等待消息
		 */
		int waitMessage(int requestID, int timeout);
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