/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCHTTPHARDSERVICE_H__
#else                                                                            
#define __FCHTTPHARDSERVICE_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include <string>
#include <map>
#include "FCServerService.h"
#include "FCHttpMonitor.h"

#define SERVICEID_HTTPHARD 20
#define FUNCTIONID_HTTPHARD_TEST 0

namespace FaceCat{
    /**
	 * HTTP服务
	 */
	class __FCHTTPHARDSERVICE_H__ FCHttpHardService:public FCServerService{
	private:
		/*
		* 监听器
		*/
		FCHttpMonitor *m_monitor;
	public:
	    /**
		 * 创建HTTP服务
		 */
		FCHttpHardService();
		/*
		* 析构函数
		*/
		virtual ~FCHttpHardService();
		/*
		* 获取监听器
		*/
		virtual FCHttpMonitor* getMonitor();
		/*
		* 设置监听器
		*/
		virtual void setMonitor(FCHttpMonitor *value);
	public:
		/**
		* 接收数据
		* @param  message  消息
		*/
		virtual void onReceive(FCMessage *message);
		/**
		* 发送消息
		* @param  message  消息
		*/
		virtual int send(FCMessage *message);
	};
}
