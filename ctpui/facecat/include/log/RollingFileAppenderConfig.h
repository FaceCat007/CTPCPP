/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __ROLLINGFILEAPPENDERCONFIG_H__
#else                                                                            
#define __ROLLINGFILEAPPENDERCONFIG_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FileAppenderConfig.h"

namespace FaceCat{
    // 滚动文件输出型日志的配置文件
    class __ROLLINGFILEAPPENDERCONFIG_H__ RollingFileAppenderConfig : public FileAppenderConfig{
	public:
		// 构造函数
		RollingFileAppenderConfig();
		// 析构函数
		virtual ~RollingFileAppenderConfig();
	public:
		// 单个日志文件大小
        String m_wstrMaxFileSize;
        // log保留个数
        int m_maxSizeRollBackups;
    };
}