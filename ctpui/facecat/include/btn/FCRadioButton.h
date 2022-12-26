/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCRADIOBUTTON_H__
#else                                                                            
#define __FCRADIOBUTTON_H__ _declspec(dllexport) 
#endif

#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCTran.h"
#include "FCCheckBox.h"

namespace FaceCat{
    /**
     * 复选框视图
     */
	class __FCRADIOBUTTON_H__ FCRadioButton:public FCCheckBox{
	public:
		/*
		* 组名称
		*/
		String m_groupName;
	public:
		/*
		* 构造函数
		*/
		FCRadioButton();
		/*
		* 析构函数
		*/
		virtual ~FCRadioButton();
		/**
	     * 获取组名
	     */
		virtual String getGroupName();
		/**
	     * 设置组名
	     */
		virtual void setGroupName(const String& value);
	public:
	    /**
	     * 获取视图类型
	     */
		virtual String getViewType();
	    /**
         * 获取属性值
         * @param name  属性名称
         * @param value 返回属性值
         * @param type  返回属性类型
        */
		virtual void getAttribute(const String& name, String *value, String *type);
		/**
	     * 获取属性名称列表
	     */
		virtual ArrayList<String> getAttributeNames();
		/**
	     * 点击方法
	     */
		virtual void onClick(FCTouchInfo touchInfo);
	    /**
         * 重绘选中按钮方法
         * @param paint    绘图对象
         * @param clipRect 裁剪区域
        */
		virtual void onPaintCheckButton(FCPaint *paint, const FCRect& clipRect);
	    /**
         * 设置属性
         * @param name    属性名称
         * @param value   属性值
        */
		virtual void setAttribute(const String& name, const String& value);
		/**
	     * 更新布局方法
	     */
		virtual void update();
	};
}

