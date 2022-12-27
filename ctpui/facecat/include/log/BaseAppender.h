/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __BASEAPPENDER_H__
#else                                                                            
#define __BASEAPPENDER_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"

namespace FaceCat{
	/*
	* 日志的基类
	*/
	class __BASEAPPENDER_H__ BaseAppender{
	public:
		/*
		* 构造函数
		*/
		BaseAppender();
		/*
		* 析构函数
		*/
		virtual ~BaseAppender();
	private:
		/*
		* Appender的ID
		*/
		int m_id;
		/*
		* Appender的名称
		*/
		String m_name;
	public:
		/*
		* 初始化标志
		*/
		bool m_initFinished;
		/*
		* 获取Appender的ID
		*/
		int getID(){ return m_id; }
		/*
		* 设置Appender的名称
		*/
		String getName(){ return m_name; }
		/*
		* 设置Appender的ID
		*/
		void setID(int value){  m_id = value; }
		/*
		* 设置Appender的名称
		*/
		void setName(const String &name){  m_name = name; }
	public:
		/*
		* 输出调试日志
		* @param  message  消息
		*/
		virtual void debug(const String &message) = 0;
		/*
		* 资源释放
		*/
		virtual void dispose() = 0;
		/*
		* 输出错误日志
		* @param  message  消息
		*/
		virtual void error(const String &message) = 0;
		/*
		* 输出致命错误日志
		* @param  message  消息
		*/
		virtual void fatal(const String &message) = 0;
		/*
		* 输出信息日志
		* @param  message  消息
		*/
		virtual void info(const String &message) = 0;
		/*
		* 输出日志
		* @param logType 日志类型
		* @param  message  消息
		*/
		virtual void log(int logType, const String &message) = 0;
		/*
		* 输出警告日志
		* @param  message  消息
		*/
		virtual void warn(const String &message) = 0;
	};
}
