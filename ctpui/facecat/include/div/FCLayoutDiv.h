/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCLAYOUTDIV_H__
#else                                                                            
#define __FCLAYOUTDIV_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\btn\\FCButton.h"
#include "FCDiv.h"

namespace FaceCat{
	/**
	 * 布局视图
	 */
	class __FCLAYOUTDIV_H__ FCLayoutDiv : public FCDiv{
	public:
	    /**
		 * 是否自动换行
		 */
		bool m_autoWrap;
		/**
		 * 排列模式
		 */
		FCLayoutStyle m_layoutStyle;
	public:
		/*
		* 构造函数
		*/
		FCLayoutDiv();
		/*
		* 析构函数
		*/
		virtual ~FCLayoutDiv();
		/**
		 * 获取是否自动换行
		 */
		virtual bool autoWrap();
		/**
		 * 设置是否自动换行
		 */
		virtual void setAutoWrap(bool value);
		/**
		 * 获取排列模式
		 */
		virtual FCLayoutStyle getLayoutStyle();
		/**
		 * 设置排列模式
		 */
		virtual void setLayoutStyle(FCLayoutStyle value);
	public:
	    /**
		 * 获取视图类型
		 */
		virtual String getViewType();
		/**
		* 获取属性值
		* @param  name   属性名称
		* @param  value   返回属性值
		* @param  type   返回属性类型
		*/
		virtual void getAttribute(const String& name, String *value, String *type);
		/**
		 * 获取属性名称列表
		 */
		virtual ArrayList<String> getAttributeNames();
		/**
		 * 重置布局
		 */
		virtual bool onResetLayout();
		/**
		* 设置属性
		* @param  name   属性名称
		* @param  value   返回属性值
		*/
		virtual void setAttribute(const String& name, const String& value);
		/**
		 * 布局更新方法
		 */
		virtual void update();
	};
}
