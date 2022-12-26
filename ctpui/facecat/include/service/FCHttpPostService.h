/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCHTTPPOSTSERVICE_H__
#else                                                                            
#define __FCHTTPPOSTSERVICE_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCClientService.h"

namespace FaceCat{
	/*
	* Post服务
	*/
	class __FCHTTPPOSTSERVICE_H__ FCHttpPostService : public FCClientService{
	private:
	    /**
		 * 是否同步发送
		 */
		bool m_isSyncSend;
		/*
		* 锁
		*/
        FCLock m_lock;
        /**
		 * 地址
		 */
		string m_url;
		/**
		 * Timeout时间
		 */
		int m_timeout;
	public:
		/*
		* 消息
		*/
		ArrayList<FCMessage*> m_messages;
		/**
		 * 创建HTTP服务
		 */
		FCHttpPostService();
		/*
		* 析构函数
		*/
		virtual ~FCHttpPostService();
		/**
		 * 获取是否同步发送
		 */
		bool isSyncSend();
		/**
		 * 设置是否同步发送
		 */
        void setIsSyncSend(bool value);
		/*
		* 获取锁
		*/
        FCLock getLock();
        /**
		 * 获取Timeout时间
		 */
		int getTimeout();
		/**
		 * 设置Timeout时间
		 */
		void setTimeout(int value);
		/**
		 * 获取地址
		 */
		string getUrl();
		/**
		 * 设置地址
		 */
		void setUrl(string value);
	public:
	    /**
		 * 异步发送数据
		 */
		static DWORD WINAPI asynSend(LPVOID lpParam);
	public:
		/**
		* 接收数据
		* @param  message  消息
		*/
		virtual void onReceive(FCMessage *message);
		/**
		* 发送POST数据
		* @param  url  地址
		* @param  data  数据
		*/
		String post(const String& url);
		/*
		* 发送POST数据
		*/
		string post(const String& url, char *sendDatas, int sendSize);
		/*
		* 发送POST数据
		*/
		String post(const String& url, const String &data);
		/*
		* 发送数据
		*/
		int send(FCMessage *message);
		/**
		* 发送POST数据
		* @param  message  消息
		*/
		int sendRequest(FCMessage *message);
	};
}