/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __CROSSLINETIP_H__
#else                                                                            
#define __CROSSLINETIP_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCPaint.h"
#include "ChartDiv.h"

namespace FaceCat{
	class ChartDiv;

	/*
	* 十字线提示框
	*/
	class __CROSSLINETIP_H__ CrossLineTip : public FCAttribute{
	public:
	    /**
	     * 是否允许用户绘图
	     */
		bool m_allowUserPaint;
		/**
	     * X轴提示框背景色
	     */
		Long m_backColor;
		/**
	     * X轴提示框文字的字体
	     */
		FCFont *m_font;
		/**
	     * X轴提示框文字色
	     */
		Long m_textColor;
		/**
	     * 是否可见
	     */
		bool m_visible;
	public:
		/*
		* 创建提示框
		*/
		CrossLineTip();
		/*
		* 销毁提示框
		*/
		virtual ~CrossLineTip();
		/**
	     * 获取是否允许用户绘图
	     */
		virtual bool allowUserPaint();
		/**
	     * 设置是否允许用户绘图
	     */
		virtual void setAllowUserPaint(bool value);
		/**
	     * 获取X轴提示框背景色
	     */
		virtual Long getBackColor();
		/**
	     * 设置X轴提示框背景色
	     */
		virtual void setBackColor(Long value);
		/**
	     * 获取X轴提示框文字的字体
	     */
		virtual FCFont* getFont();
		/**
	     * 设置X轴提示框文字的字体
	     */
		virtual void setFont(FCFont *value);
		/**
	     * 获取X轴提示框文字色
	     */
		virtual Long getTextColor();
		/**
	     * 设置X轴提示框文字色
	     */
		virtual void setTextColor(Long value);
		/**
	     * 获取是否可见
	     */
		virtual bool isVisible();
		/**
	     * 设置是否可见
	     */
		virtual void setVisible(bool value);
	public:
	     /**
          * 获取属性值
          * @param name  属性名称
          * @param value 返回属性值
          * @param type  返回属性类型
         */
		virtual void onPaint(FCPaint *paint, ChartDiv *div, const FCRect& rect);
		/**
	     * 获取属性名称列表
	     */
		virtual void getAttribute(const String& name, String *value, String *type);
	    /**
         * 重绘方法
         * @param paint  绘图对象
         * @param div    图层
         * @param rect   区域
        */
		virtual ArrayList<String> getAttributeNames();
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