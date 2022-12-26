/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __CFUNCTIONEX_H__
#else                                                                            
#define __CFUNCTIONEX_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCHttpMonitor.h"

namespace FaceCat{
	/*
	* HTTP的库
	*/
	class __CFUNCTIONEX_H__ CFunctionEx : public CFunction{
	private:
	    /**
		 * 指标
		 */
		FCScript *m_script;
		/**
		 * XML对象
		 */
		FCNative *m_native;
	public:
		/**
		* 创建方法
		* @param  script  指标
		* @param  id  ID
		* @param  name  名称
		* @param  native  XML对象
		*/
		CFunctionEx(FCScript *script, int cid, const String& name, FCNative *native);
		/*
		* 析构函数
		*/
		virtual ~CFunctionEx();
	public:
		/*
		* 创建脚本
		*/
		static FCScript* createScript(const String& text, FCNative *native, FCHttpMonitor *monitor);
		/**
		* 计算
		* @param  var  变量
		*/
		virtual double onCalculate(CVariable *var);
	};
}

