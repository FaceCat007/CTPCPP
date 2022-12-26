/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __SEPARATEDIRAPPENDER_H__
#else                                                                            
#define __SEPARATEDIRAPPENDER_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FileAppender.h"
#include "RollingFileAppenderConfig.h"

namespace FaceCat{
    // 根据日期分目录输出型日志
    class __SEPARATEDIRAPPENDER_H__ SeparateDirAppender : public FileAppender{
	public:
		// 构造函数
        SeparateDirAppender();
        // 构造函数
        SeparateDirAppender(RollingFileAppenderConfig *fileAppenderConfig);
        // 构造函数
        SeparateDirAppender(const String &configPath);
        // 析构函数
        virtual ~SeparateDirAppender();
	private:
        // 日志文件名称
        String m_baseLogFileName;
		// 配置文件
        RollingFileAppenderConfig *m_fileAppenderConfig;
	public:
        long m_maxFileSize;
	public:
        // 计算日志文件的大小
        virtual void calculateLogFileSize();
	private:
        // 获取当前日志文件的索引
        int getBackUpIndex(const String &curFileName);
		// 获取文件名
		String getFileNameFromFilePath(const String &filePath);
		// 从文件名里取得index
		bool getIndexFromFileName(const String &curFileName, const String &baseFileName, int *index);
	public:
		// 输出日志
        void log(int logType, const String &message);
	};
}