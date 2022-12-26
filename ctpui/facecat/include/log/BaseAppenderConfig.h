/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __BASEAPPENDERCONFIG_H__
#else                                                                            
#define __BASEAPPENDERCONFIG_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"

namespace FaceCat{
	// 日志配置文件的基类
	class __BASEAPPENDERCONFIG_H__ BaseAppenderConfig{
	public:
		// 构造函数
		BaseAppenderConfig();
		// 析构函数
		virtual ~BaseAppenderConfig();

	public:
		// 日志的输入模式
		String m_logPatten;
		// 日志的级别
		// 1：调试模式
		// 2：信息模式
		// 3：警告模式
		// 4：错误模式
		// 5：致命错误
		int m_logType;
		// 日志配置的名称
		String m_name;
		// 日志配置的类型
		String m_type;
		// 加载配置文件
		virtual bool loadConfig(const String &configPath);
	};
}