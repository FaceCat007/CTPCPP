/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FILEAPPENDER_H__
#else                                                                            
#define __FILEAPPENDER_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "BaseAppender.h"
#include "FileAppenderConfig.h"

namespace FaceCat{
	/*
	* 文件输出型日志
	*/
	class __FILEAPPENDER_H__ FileAppender : public BaseAppender{
	public:
		/*
		* 构造函数
		*/
		FileAppender();
		/*
		* 构造函数
		*/
		FileAppender(FileAppenderConfig* fileAppenderConfig);
		/*
		* 构造函数
		*/
		FileAppender(const String &configPath);
		/*
		* 析构函数
		*/
		virtual ~FileAppender();
	public:
		/*
		* 配置文件
		*/
		FileAppenderConfig* m_baseFileAppenderConfig;
	public:
		/*
		* 向文件中追加内容
		* @param logFile 日志文件
		* @param content 内容
		*/
		virtual bool append(const String &logFile, const String &content);
		/*
		* 判断日志目录
		* @param fileFullPath 文件路径
		*/
		virtual void checkDirectory(const String &fileFullPath);
		/*
		* 判断是否输出
		*/
		bool checkOut(int logType);
	public:
		/*
		* 输出调试日志
		* @param message 消息
		*/
		void debug(const String &message);
		/*
		* 资源释放
		*/
		void dispose();
		/*
		* 输出错误日志
		* @param message 消息
		*/
		void error(const String &message);
		/*
		* 输出致命错误日志
		* @param message 消息
		*/
		void fatal(const String &message);
		/*
		* 输出信息日志
		* @param message 消息
		*/
		void info(const String &message);
		/*
		* 输出日志
		* @param message 消息
		*/
		void log(int logType, const String &message);
		/*
		* 输出警告日志
		* @param message 消息
		*/
		void warn(const String &message);

	public: 
		/*
		* 获取当前的时间
		* @param datePattern 日期连接符号
		*/
		String getNowDate(const String &datePattern);
	};
}