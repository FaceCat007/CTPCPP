/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FILEAPPENDERCONFIG_H__
#else                                                                            
#define __FILEAPPENDERCONFIG_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "BaseAppenderConfig.h"

namespace FaceCat{
	/*
	* 文件输出型日志的配置文件
	*/
	class __FILEAPPENDERCONFIG_H__ FileAppenderConfig : public BaseAppenderConfig{
	public:
		/*
		* 构造函数
		*/
		FileAppenderConfig();
		/*
		* 析构函数
		*/
		virtual ~FileAppenderConfig();
	public:
		/*
		* 日志文件的名称
		*/
		String m_logFile;
		/*
		* 时间格式
		*/
		String m_datePattern;
		/*
		* 加载配置文件
		* @param configPath 配置文件
		*/
		bool loadConfig(const String &configPath);
	};
}
