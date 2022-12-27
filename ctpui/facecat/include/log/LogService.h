/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __LOGSERVICE_H__
#else                                                                            
#define __LOGSERVICE_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "BaseAppender.h"

namespace FaceCat
{
	/*
	* 日志记录的类型
	*/
    enum __LOGSERVICE_H__ LogType
    {
        // 调试
        LogType_Debug = 1,
        // 错误
        LogType_Error = 4,
        // 致命错误
        LogType_Fatal = 5,
        // 信息
        LogType_Info = 2,
        // 警告
        LogType_Warnning = 3,
    };

	/*
	* 多线程工作信息
	*/
	class __LOGSERVICE_H__ LogWorkDataInfo
	{
	public:
        /*
		* 日志appender
		*/
        BaseAppender *m_appender;
		/*
		* 键
		*/
        int m_id;
		/*
		* 日志的内容
		*/ 
        String m_logContent;
		/*
		* 日志的类型
		*/
        int m_logType;
		/*
		* 执行次数
		*/
        int m_pos;
		/*
		* 线程ID
		*/ 
        int m_threadID;
		/*
		* 请求ID
		*/
		int m_requestID;
		/*
		* 会话ID
		*/
		int m_sessionID;
	public:
		/*
		* 构造函数
		*/
		LogWorkDataInfo();
		/*
		* 析构函数
		*/
		virtual ~LogWorkDataInfo();
	};

	/*
	* 日志请求信息
	*/
    struct __LOGSERVICE_H__ LogReqDataInfo
    {
	public:
		/*
		* 构造函数
		*/
		LogReqDataInfo();
		/*
		* 析构函数
		*/
		virtual ~LogReqDataInfo();
		/*
		* 请求ID
		*/
		int m_requestID;
		/*
		* 会话ID
		*/
        int m_sessionID;
		/*
		* 相同判断
		*/
		bool operator == (const LogReqDataInfo& other) const
		{
			return m_requestID == other.m_requestID && m_sessionID == other.m_sessionID;
		}
		/* 
		* 排序判断
		*/
		bool operator < (const LogReqDataInfo& other) const
		{
			if(m_requestID * m_sessionID < other.m_requestID * other.m_sessionID)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
    };

	typedef LogWorkDataInfo* (*PushDataRecv)(LogWorkDataInfo *message, void *pInvoke);
	typedef void (*PushDataQuit)(LogWorkDataInfo *pushDataInfo, void *pInvoke);
	typedef int (*PushDataWork)(LogWorkDataInfo *pushDataInfo, void *pInvoke);

	/*
	* 日志服务
	*/
	class __LOGSERVICE_H__ LogService{
	private:
		/*
		* 所有的日志类型服务
		*/
        map<int, BaseAppender*> m_appenders;
		/*
		* 数据信息
		*/
		map<int, vector<LogWorkDataInfo*>*> m_dataInfos;
		/*
		* 锁
		*/
		FCLock m_lock;
		/*
		* 追加锁
		*/
		FCLock m_lockAppender;
		/*
		* 停止推送锁
		*/
		FCLock m_lockStopPushDatas;
		/*
		* 消息列表
		*/ 
		vector<LogWorkDataInfo*> m_messages;
		/*
		* 退出事件
		*/ 
		PushDataQuit m_quitEvent;
		/*
		* 退出事件调用
		*/
		void *m_quitEventInvoke;
		/*
		* 接收事件
		*/
		PushDataRecv m_recvEvent;
		/*
		* 接收事件调用
		*/
		void *m_recvEventInvoke;
		/*
		* 停止事件
		*/ 
		vector<LogReqDataInfo> m_stopPushDatas;
		/*
		* 计数器
		*/
		int m_tick;
		/*
		* 工作事件
		*/
		PushDataWork m_workEvent;
		/*
		* 工作事件调用
		*/
		void *m_workEventInvoke;
	private:
		/*
		* 工作中
		* @param dataInfo 数据信息
		*/
		int onWorking(LogWorkDataInfo *dataInfo);
		/*
		* 单条日记开始处理
		* @param dataInfo 数据信息
		*/
		void startWork(LogWorkDataInfo *dataInfo);
		/*
		* 多条日记开始处理
		* @param dataInfos 多条数据
		*/
		void startWork(vector<LogWorkDataInfo*> &dataInfos);
	public:
		/*
		* 构造函数
		*/
		LogService();
		/*
		* 析构函数
		*/
		virtual ~LogService();
	public:
		/*
		* 添加日志服务
		* @param appender 追加器
		*/
		void addAppender(BaseAppender *appender);
		/*
		* 添加滚动日志服务
		* @param filePath 文件路径
		*/
		void addRollingFileAppender(const String &filePath);
		/*
		* 添加分割日志服务
		* @param filePath 文件路径
		*/
		void addSeparateDirAppender(const String &filePath);
		/*
		* 获取当前的时间
		* @param datePattern 日期分割
		*/
		String getNowDate(const String &datePattern);
		/*
		* 输出日志
		* @param logType 日志类型
		* @param message 消息
		*/
		void log(LogType logType, const String &message);
		/*
		* 输出日志
		* @param logType 日志类型
		* @param str 短字符
		*/
		void log(LogType logType, const string &str);
		/*
		* 日志处理
		* @param id 编号
		*/
		void onWork(int id);
		/*
		* 退出处理
		* @param reqInfo 请求数据
		*/
		int quit(LogReqDataInfo *reqInfo);
		/*
		* 接收处理
		* @param message 消息
		*/
		void recv(LogWorkDataInfo *message);
		/*
		* 注册退出事件
		* @param quitEvent 退出事件
		* @param pInvoke 调用者
		*/
		void registerQuitEvent(PushDataQuit quitEvent, void *pInvoke);
		/*
		* 注册接收事件
		* @param recvEvent 接收事件
		* @param pInvoke 调用者
		*/
		void registerRecvEvent(PushDataRecv recvEvent, void *pInvoke);
		/*
		* 注册工作事件
		* @param recvEvent 工作事件
		* @param pInvoke 调用者
		*/
		void registerWorkEvent(PushDataWork workEvent, void *pInvoke);
		/*
		* Log服务启动
		*/
		void start();
	};
}