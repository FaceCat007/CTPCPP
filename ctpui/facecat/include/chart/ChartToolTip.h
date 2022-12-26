/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __CHARTTOOLTIP_H__
#else                                                                            
#define __CHARTTOOLTIP_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCPaint.h"
#include "ChartDiv.h"

namespace FaceCat{
	class ChartDiv;

	/*
	* 提示框
	*/
	class __CHARTTOOLTIP_H__ ChartToolTip : public FCAttribute{
	public:
	    /**
	     * 是否允许用户绘图
	     */
		bool m_allowUserPaint;
		/**
	     * 提示框的背景色
	     */
		Long m_backColor;
		/**
	     * 边线的颜色
	     */
		Long m_borderColor;
		/**
	     * 提示框的字体
	     */
		FCFont *m_font;
		/**
	     * 提示框的字体颜色
	     */
		Long m_textColor;
	public:
		ChartToolTip();
		/*
		* 析构函数
		*/
		virtual ~ChartToolTip();
		/**
	     * 获取是否允许用户绘图
	     */
		virtual bool allowUserPaint();
		/**
	     * 设置是否允许用户绘图
	     */
		virtual void setAllowUserPaint(bool value);
		/**
	     * 获取提示框的背景色
	     */
		virtual Long getBackColor();
		/**
	     * 设置提示框的背景色
	     */
		virtual void setBackColor(Long value);
		/**
	     * 获取边线的颜色
	     */
		virtual Long getBorderColor();
		/**
	     * 设置边线的颜色
	     */
		virtual void setBorderColor(Long value);
		/**
	     * 获取提示框的字体
	     */
		virtual FCFont* getFont();
		/**
	     * 设置提示框的字体
	     */
		virtual void setFont(FCFont *value);
		/**
	     * 获取提示框的字体颜色
	     */
		virtual Long getTextColor();
		/**
	     * 设置提示框的字体颜色
	     */
		virtual void setTextColor(Long value);
	public:
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
         * 重绘方法
         * @param paint  绘图对象
         * @param div    图层
         * @param rect   区域
        */
		virtual void onPaint(FCPaint *paint, ChartDiv *div, const FCRect& rect);
		/*
		* 处理缩放
		*/
		virtual void onScaling(double scaleFactorX, double scaleFactorY);
	    /**
         * 设置属性值
         * @param name  属性名称
         * @param value 属性值
        */
		virtual void setAttribute(const String& name, const String& value);
	};
}