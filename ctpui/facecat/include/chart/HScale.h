/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __HSCALE_H__
#else                                                                            
#define __HSCALE_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCPaint.h"
#include "Enums.h"
#include "CrossLineTip.h"
#include "ChartDiv.h"

namespace FaceCat{
	class ChartDiv;
	class CrossLineTip;

	/*
	* 横轴
	*/
	class __HSCALE_H__ HScale : public FCAttribute{
	public:
	    /**
	     * 是否允许用户绘图
	     */
		bool m_allowUserPaint;
		/**
	     * 十字线标签
	     */
		CrossLineTip *m_crossLineTip;
		/**
	     * 日期文字的颜色
	     */
		HashMap<Integer, Long> m_dateColors;
		/**
	     * X轴文字的字体
	     */
		FCFont *m_font;
		/**
	     * X轴的高度
	     */
		int m_height;
		/**
	     * 横轴的数据类型
	     */
		HScaleType m_hScaleType;
		/**
	     * 日期文字间隔
	     */
		int m_interval;
		/**
	     * X轴的线条颜色
	     */
		Long m_scaleColor;
		/**
	     * 刻度点
	     */
		ArrayList<Double> m_scaleSteps;
		/**
	     * 文本颜色
	     */
		Long m_textColor;
		/*
		* 标题
		*/
		String m_title;
		/**
	     * 标题的字体
	     */
		FCFont *m_titleFont;
		/**
	     * 显示X轴
	     */
		bool m_visible;
	public:
		/*
		* 创建X轴
		*/
		HScale();
		/*
		* 销毁X轴
		*/
		virtual ~HScale();
		/**
	     * 获取是否允许用户绘图
	     */
		virtual bool allowUserPaint();
		/**
	     * 设置是否允许用户绘图
	     */
		virtual void setAllowUserPaint(bool value);
		/**
	     * 获取十字线标签
	     */
		virtual CrossLineTip* getCrossLineTip();
		/**
	     *  获取日期文字的颜色
	     */
		virtual Long getDateColor(DateType dateType);
		/**
	     * 设置日期文字的颜色
	     */
		virtual void setDateColor(DateType dateType, Long color);
		/**
	     * 获取X轴文字的字体
	     */
		virtual FCFont* getFont();
		/**
	     * 设置X轴文字的字体
	     */
		virtual void setFont(FCFont *value);
		/**
	     * 获取X轴的高度
	     */
		virtual int getHeight();
		/**
	     * 设置X轴的高度
	     */
		virtual void setHeight(int value);
		/**
	     * 获取横轴的数据类型
	     */
		virtual HScaleType getHScaleType();
		/**
	     * 设置横轴的数据类型
	     */
		virtual void setHScaleType(HScaleType value);
		/**
	     * 获取日期文字间隔
	     */
		virtual int getInterval();
		/**
	     * 设置日期文字间隔
	     */
		virtual void setInterval(int value);
		/**
	     * 获取X轴的线条颜色
	     */
		virtual Long getScaleColor();
		/**
	     * 设置X轴的线条颜色
	     */
		virtual void setScaleColor(Long value);
		/**
	     * 获取文本颜色
	     */
		virtual Long getTextColor();
		/**
	     * 设置文本颜色
	     */
		virtual void setTextColor(Long value);
		/*
		* 获取标题
		*/
		virtual String getTitle();
		/*
		* 设置标题
		*/
		virtual void setTitle(String value);
		/**
	     * 获取标题的字体
	     */
		virtual FCFont* getTitleFont();
		/**
	     * 设置标题的字体
	     */
		virtual void setTitleFont(FCFont *value);
		/**
	     * 获取显示X轴
	     */
		virtual bool isVisible();
		/**
	     * 设置显示X轴
	     */
		virtual void setVisible(bool value);
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
	     * 获取刻度点
	     */
		ArrayList<Double> getScaleSteps();
		/**
	     * 重绘方法
	     */
		virtual void onPaint(FCPaint *paint, ChartDiv *div, const FCRect& rect);
		/**
	     * 重绘前方法
	     */
		virtual void onPaintBefore(FCPaint *paint, ChartDiv *div, const FCRect& rect);
		/*
		* 处理缩放
		*/
		virtual void onScaling(double scaleFactorX, double scaleFactorY);
		/**
	     * 设置属性
	     */
		virtual void setAttribute(const String& name, const String& value);
		/**
	     * 设置刻度点
	     */
		void setScaleSteps(ArrayList<Double> scaleSteps);
	};
}