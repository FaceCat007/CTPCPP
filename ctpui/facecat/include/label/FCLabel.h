/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCLABEL_H__
#else                                                                            
#define __FCLABEL_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"

namespace FaceCat{
	/*
	* 标签
	*/
	class __FCLABEL_H__ FCLabel : public FCView{
	public:
		FCContentAlignment m_textAlign;
	public:
		/*
		* 构造函数
		*/ 
		FCLabel();
		/*
		* 析构函数
		*/
		virtual ~FCLabel();
		/**
		 * 获取文字的布局方式
		 */
		virtual FCContentAlignment getTextAlign();
		/**
		 * 设置文字的布局方式
		 */
		virtual void setTextAlign(FCContentAlignment value);
	public:
	    /**
		 * 获取视图类型
		 */
		virtual String getViewType();
		/**
		* 获取属性值
		* @param  name  属性名称
		* @param  value  返回属性值
		* @param  type  返回属性类型
		*/
		virtual void getAttribute(const String& name, String *value, String *type);
		/**
		 * 获取属性名称列表
		 */
		virtual ArrayList<String> getAttributeNames();
		/**
		 * 重绘前景方法
		 */
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
		/*
		* 预绘图方法
		*/
		virtual bool onPrePaint(FCPaint *paint, const FCRect& clipRect);
		/**
		* 设置属性
		* @param  name  属性名称
		* @param  value  属性值
		*/
		virtual void setAttribute(const String& name, const String& value);
	};
}