/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCBUTTON_H__
#else                                                                            
#define __FCBUTTON_H__ _declspec(dllexport) 
#endif

#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCTran.h"

namespace FaceCat{
	/**
     * 按钮视图
     */
	class __FCBUTTON_H__ FCButton : public FCView{
	public:
		/**
		* 不可用时的背景图片
		*/
		String m_disabledBackImage;
		/**
		* 触摸悬停时的背景图片
		*/
		String m_hoveredBackImage;
		/**
		* 触摸按下时的背景图片
		*/
		String m_pushedBackImage;
		/**
		* 文字排列方式
		*/
		FCContentAlignment m_textAlign;
	public:
	    /**
	     * 获取要绘制的背景色
	     */
		virtual Long getPaintingBackColor();
		/**
	     * 获取用于绘制的背景图片
	     */
		virtual String getPaintingBackImage();
	public:
		/*
		* 构造函数
		*/
		FCButton();
		/*
		* 析构函数
		*/
		virtual ~FCButton();
		/**
	     * 获取不可用时的背景图片
	     */
		virtual String getDisabledBackImage();
		/**
	     * 设置不可用时的背景图片
	     */
		virtual void setDisabledBackImage(const String& value);
		/**
	     * 获取触摸悬停时的背景图片
	     */
		virtual String getHoveredBackImage();
		/**
	     * 设置触摸悬停时的背景图片
	     */
		virtual void setHoveredBackImage(const String& value);
		/**
	     * 获取触摸按下时的背景图片
	     */
		virtual String getPushedBackImage();
		/**
	     * 设置触摸按下时的背景图片
	     */
		virtual void setPushedBackImage(const String& value);
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
         * 触摸按下方法
         * @param touchInfo 触摸信息
         */
		virtual void onTouchDown(FCTouchInfo touchInfo);
	    /**
         * 触摸进入方法
         * @param touchInfo 触摸信息
         */
		virtual void onTouchEnter(FCTouchInfo touchInfo);
	    /**
         * 触摸离开方法
         * @param touchInfo 触摸信息
         */
		virtual void onTouchLeave(FCTouchInfo touchInfo);
	    /**
         * 触摸抬起方法
         * @param touchInfo 触摸信息
         */
		virtual void onTouchUp(FCTouchInfo touchInfo);
	    /**
         * 重绘前景方法
         * @param paint    绘图对象
         * @param clipRect 裁剪区域
         */
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
	    /**
         * 设置属性
         * @param name  属性名称
         * @param value 属性值
         */
		virtual void setAttribute(const String& name, const String& value);
	};
}
