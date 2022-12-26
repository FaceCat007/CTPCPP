/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCHTTPMONITOR_H__
#else                                                                            
#define __FCHTTPMONITOR_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCBinary.h"
#include <string>
#include <map>
#pragma comment(lib, "ws2_32.lib")
#include "winsock2.h"
#include "FCHttpEasyService.h"
using namespace std;

namespace FaceCat
{
	class FCHttpEasyService;

    /**
	 * Http数据
	 */
	class __FCHTTPMONITOR_H__ FCHttpData
	{
	public:
	    /**
		 * 文件Http服务
		 */
		FCHttpData();
		/*
		* 析构函数
		*/
		~FCHttpData();
		SOCKADDR_IN m_addr;
		char *m_body;
        bool m_close;
		int m_contentLength;
        String m_contentType;
        String m_method;
		map<String, String> m_parameters;
		String m_remoteIP;
        int m_remotePort;
		char* m_resBytes;
		int m_resBytesLength;
		String m_resStr;
		SOCKET m_socket;
		int m_statusCode;	
        String m_url;
		void *m_tag;
	};

	/*
	* HTTP监听
	*/
	class __FCHTTPMONITOR_H__ FCHttpMonitor
	{
	public:
		SOCKADDR_IN m_addr;
		/**
		 * 文件名称
		 */
		string m_fileName;
		/*
		* 套接字
		*/
		SOCKET m_hSocket;
		/**
		 * 数据集合
		 */
		map<int, FCHttpData*> m_httpDatas;
		/**
		 * 脚本集合
		 */
		stack<FCScript*> m_scripts;
		/**
		 * 主脚本
		 */
		FCScript *m_script;
		/*
		* 全局锁
		*/
		FCLock m_lock;
		/*
		* HTTP锁
		*/
		FCLock m_lockHttpData;
		/**
		 * XML对象
		 */
		FCNative *m_native;
		/**
		 * 端口
		 */
		int m_port;
		/**
		 * 脚本
		 */
		String m_text;
		/**
		 * 使用脚本
		 */
		bool m_useScript;
	public:
		/*
		* 构造函数
		*/
		FCHttpMonitor(string fileName);
		/*
		* 析构函数
		*/
		virtual ~FCHttpMonitor();
		/*
		* 添加简单服务
		*/
		static void addEasyService(const String& name, FCHttpEasyService *easyService);
		/*
		* 获取简单服务
		*/
		static FCHttpEasyService* getEasyService(const String& name);
		/**
		 * 获取主脚本
		 */
		FCScript* getScript();
		/**
		 * 获取XML对象
		 */
		FCNative* getNative();
		/**
		 * 获取端口
		 */
		int getPort();
		/**
		 * 设置端口
		 */
		void setPort(int value);
		/**
		 * 获取脚本
		 */
		String getText();
		/**
		 * 设置脚本
		 */
		void setText(String value);
		/*
		* 获取套接字
		*/
		SOCKET getSocket();
		/**
		 * 是否使用脚本
		 */
		bool getUseScript();
		/*
		* 设置HTTP数据
		*/
		void setHttpData(int socketID, FCHttpData *data);
		/*
		* 弹出指标
		*/
		FCScript* popScript();
	public:
		/*
		* 关闭服务
		*/
		int close(int socketID);
		/**
		 * 启动监听
		 */
		int start();
	};
}