/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __CFUNCTIONHTTP_H__
#else                                                                            
#define __CFUNCTIONHTTP_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCHttpMonitor.h"
#include "FCHttpEasyService.h"

namespace FaceCat{
	/*
	* HTTP库
	*/
	class __CFUNCTIONHTTP_H__ CFunctionHttp : public CFunction{
	private:
	    /**
		 * HTTP对象
		 */
		FCHttpData *m_data;
		/*
		* 监听器
		*/
		FCHttpMonitor *m_monitor;
		/**
		 * 指标
		 */
		FCScript *m_script;
	public:
		/**
		* 创建方法
		* @param  script  指标
		* @param  id  ID
		* @param  name  名称
		*/
		CFunctionHttp(FCScript *script, int cid, const String& name, FCHttpMonitor *monitor);
		/*
		* 析构函数
		*/
		virtual ~CFunctionHttp();
		/**
		 * 获取HTTP对象
		 */
		FCHttpData* getHttpData();
		/**
		 * 设置HTTP对象
		 */
		void setHttpData(FCHttpData *data);
	public:
		/**
		* 添加方法
		* @param  script  方法库
		*/
		static void addFunctions(FCScript *script, FCHttpMonitor *monitor);
		/**
		* 计算
		* @param  var  变量
		*/
		virtual double onCalculate(CVariable *var);
	public:
	    /**
		 * 添加前缀
		 */
		double HTTP_ADDPORT(CVariable *var);
		/**
		 * 检查脚本
		 */
		double HTTP_CHECKSCRIPT(CVariable *var);
		/**
		 * HTTP关闭
		 */
		double HTTP_CLOSE(CVariable *var);
		/**
		 * 接受GET请求
		 */
		double HTTP_EASYREQUEST(CVariable *var);
		/**
		 * 获取内容类型方法
		 */
		double HTTP_GETCONTENTTYPE(CVariable *var);
		/**
		 * 获取IP
		 */
		double HTTP_GETREMOTEIP(CVariable *var);
		/**
		 * 获取Port
		 */
		double HTTP_GETREMOTEPORT(CVariable *var);
		/**
		 * 获取请求方法
		 */
		double HTTP_GETREQUESTMETHOD(CVariable *var);
		/**
		 * 获取请求URL
		 */
		double HTTP_GETREQUESTURL(CVariable *var);
		/**
		 * 获取服务名称
		 */
		double HTTP_GETSERVICENAME(CVariable *var);
		/**
		 * 接受流数据
		 */
		double HTTP_HARDREQUEST(CVariable *var);
		/**
		 * 接受流数据
		 */
		double HTTP_POSTREQUEST(CVariable *var);
		/**
		 * HTTP获取POST请求的参数
		 */
		double HTTP_POSTSTRING(CVariable *var);
		/**
		 * HTTP获取GET请求的参数
		 */
		double HTTP_QUERYSTRING(CVariable *var);
		/**
		 * 设置响应状态码
		 */
		double HTTP_SETSTATUSCODE(CVariable *var);
		/**
		 * HTTP响应写流
		 */
		double HTTP_WRITE(CVariable *var);
	};
}

