/*
 * FaceCat框架(非开源)
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __UISCRIPT_H__
#else                                                                            
#define __UISCRIPT_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCUIEvent.h"
#include "FCUIScript.h"

namespace FaceCat{
	class FCUIEvent;
	class FCUIXml;

	/*
	* 脚本接口类
	*/
	class __UISCRIPT_H__ FCUIScript{
	private:
		/*
		* xml对象
		*/
		FCUIXml* m_xml;
	public:
		/*
		* 构造函数
		*/
		FCUIScript(FCUIXml *xml);
		/*
		* 析构函数
		*/
		virtual ~FCUIScript();
		/**
		 * 获取XML对象
		 */
		FCUIXml* getXml();
		/**
		 * 设置XML对象
		 */
		void setXml(FCUIXml *value);
	public:
	    /**
		 * 调用方法
		 */
		virtual String callFunction(const String& function);
		/**
		 * 设置脚本
		 */
		virtual void setText(const String& text);
	};
}