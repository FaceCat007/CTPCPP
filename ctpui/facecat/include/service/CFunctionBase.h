/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __NFUNCTIONBASE_H__
#else                                                                            
#define __NFUNCTIONBASE_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"

namespace FaceCat{
	/*
	* 基础方法库
	*/
	class __NFUNCTIONBASE_H__ NFunctionBase : public CFunction{
	private:
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
		NFunctionBase(FCScript *script, int cid, const String& name);
		/*
		* 析构函数
		*/
		virtual ~NFunctionBase();
	public:
		/**
		* 添加方法
		* @param  script  方法库
		*/
		static void addFunctions(FCScript *script);
		/**
		* 计算
		* @param  var  变量
		*/
		virtual double onCalculate(CVariable *var);
	public:
		/**
		* 输入函数
		* @param  var  变量
		*/
		double INPUT(CVariable *var);
		/**
		* 输出函数
		* @param  var  变量
		*/
		double OUTPUT(CVariable *var);
		/**
		* 睡眠
		* @param  var  变量
		*/
		double SLEEP(CVariable *var);
	};
}


