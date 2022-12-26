/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __VSCALE_H__
#else                                                                            
#define __VSCALE_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCPaint.h"
#include "Enums.h"
#include "FCDataTable.h"
#include "CrossLineTip.h"
#include "ChartDiv.h"

namespace FaceCat{
	class ChartDiv;
	class CrossLineTip;

	/*
	* 扩展数据
	*/
	class __VSCALE_H__ FCExValue
    {
	public:
        /*
		* 标题
		*/
        String m_title;

        /*
		* 数据
		*/
        ArrayList<double> m_values;
	public:
		/*
		* 构造函数
		*/
		FCExValue(){
		}
		/*
		* 析构函数
		*/
		virtual ~FCExValue(){
			m_values.clear();
		}
    };


    /**
     * Y轴
     */
	class __VSCALE_H__ VScale : public FCAttribute{
	public:
		/*
		* 扩展颜色字段
		*/
		ArrayList<Long> m_extendColors;
		/*
		* 扩展字段
		*/
		ArrayList<FCExValue> m_extendValues;
	public:
	    /**
	     * 是否允许用户绘图
	     */
		bool m_allowUserPaint;
		/**
	     * 最大值和最小值是否自动计算
	     */
		bool m_autoMaxMin;
		/**
	     * 基础字段
	     */
		int m_baseField;
		/**
	     * 十字线标签
	     */
		CrossLineTip *m_crossLineTip;
		/**
	     * 面板显示数值保留小数的位数
	     */
		int m_digit;
		/*
		* 下跌的颜色
		*/
		Long m_downColor;
		/**
	     * 左侧Y轴文字的字体
	     */
		FCFont *m_font;
		/*
		* 上次收盘价
		*/
		double m_lastClose;
		/**
		* 分时线最大值
		*/
		double m_minuteLineMaxValue;
		/*
		* 分时线最小值
		*/
		double m_minuteLineMinValue;
		/**
	     * 量级
	     */
		int m_magnitude;
		/**
	     * 区别涨贴的中间值
	     */
		double m_midValue;
		/**
	     * 数字类型
	     */
		NumberStyle m_numberStyle;
		/**
	     * 最小值上方的间隙比例
	     */
		int m_paddingBottom;
		/**
	     * 最大值上方的间隙比例
	     */
		int m_paddingTop;
		/**
	     * 是否反转
	     */
		bool m_reverse;
		/**
	     * 坐标轴的画笔
	     */
		Long m_scaleColor;
		/*
		* 坐标刻度
		*/
		ArrayList<Double> m_scaleSteps;
		/*
		* 是否显示分时线
		*/
		bool m_showMinuteLine;
		/**
	     * 坐标系的类型
	     */
		VScaleSystem m_system;
		/**
	     * Y轴文字的颜色
	     */
	    Long m_textColor;
		/**
	     * Y轴文字的颜色2
	     */
		Long m_textColor2;
		/*
		* 标题
		*/
		String m_title;
		/**
	     * 标题的字体
	     */
		FCFont *m_titleFont;

		/**
	     * 坐标轴的类型
	     */
		VScaleType m_type;
		/*
		* 上涨的颜色
		*/
		Long m_upColor;
		/**
	     * 坐标值可见部分的最大值
	     */
		double m_visibleMax;
		/**
	     * 坐标值可见部分的最小值
	     */
		double m_visibleMin;
	public:
		/*
		* 构造函数
		*/
		VScale();
		/*
		* 析构函数
		*/
		virtual ~VScale();
		/**
	     * 获取是否允许用户绘图
	     */
		virtual bool allowUserPaint();
		/**
	     * 设置是否允许用户绘图
	     */
		virtual void setAllowUserPaint(bool value);
		/**
	     * 获取最大值和最小值是否自动计算
	     */
		virtual bool autoMaxMin();
		/**
	     * 设置最大值和最小值是否自动计算
	     */
		virtual void setAutoMaxMin(bool value);
		/**
	     * 获取基础字段
	     */
		virtual int getBaseField();
		/**
	     * 设置基础字段
	     */
		virtual void setBaseField(int value);
		/**
	     * 获取十字线标签
	     */
		virtual CrossLineTip* getCrossLineTip();
		/**
	     * 获取面板显示数值保留小数的位数
	     */
		virtual int getDigit();
		/**
	     * 设置面板显示数值保留小数的位数
	     */
		virtual void setDigit(int value);
		/*
		* 获取下跌的颜色
		*/
		virtual Long getDownColor();
		/*
		* 设置下跌的颜色
		*/
		virtual void setDownColor(Long value);
		/**
	     * 获取左侧Y轴文字的字体
	     */
		virtual FCFont* getFont();
		/**
	     * 获取左侧Y轴文字的字体
	     */
		virtual void setFont(FCFont *value);
		/*
		* 获取上次收盘价
		*/
		virtual double getLastClose();
		/*
		* 设置上次收盘价
		*/
		virtual void setLastClose(double value);
		/*
		* 获取分时线最大值
		*/
		virtual double getMinuteLineMaxValue();
		/*
		* 设置分时线最大值
		*/
		virtual void setMinuteLineMaxValue(double value);
		/*
		* 获取分时线最小值
		*/
		virtual double getMinuteLineMinValue();
		/*
		* 设置分时线最小值
		*/
		virtual void setMinuteLineMinValue(double value);
		/**
	     * 获取量级
	     */
		virtual int getMagnitude();
		/**
	     * 设置量级
	     */
		virtual void setMagnitude(int value);
		/**
	     * 获取区别涨贴的中间值
	     */
		virtual double getMidValue();
		/**
	     * 设置区别涨贴的中间值
	     */
		virtual void setMidValue(double value);
		/**
	     * 获取数字类型
	     */
		virtual NumberStyle getNumberStyle();
		/**
	     * 设置数字类型
	     */
		virtual void setNumberStyle(NumberStyle value);
		/**
	     * 获取最小值上方的间隙比例
	     */
		virtual int getPaddingBottom();
		/**
	     * 设置最小值上方的间隙比例
	     */
		virtual void setPaddingBottom(int value);
		/**
	     * 获取最大值上方的间隙比例
	     */
		virtual int getPaddingTop();
		/**
	     * 设置最大值上方的间隙比例
	     */
		virtual void setPaddingTop(int value);
		/**
	     * 获取是否反转
	     */
		virtual bool isReverse();
		/**
	     * 设置是否反转
	     */
		virtual void setReverse(bool value);
		/**
	     * 获取坐标轴的画笔
	     */
		virtual Long getScaleColor();
		/**
	     * 设置坐标轴的画笔
	     */
		virtual void setScaleColor(Long value);
		/*
		* 获取是否显示分时线
		*/
		bool showMinuteLine();
		/*
		* 设置是否显示分时线
		*/
		void setShowMinuteLine(bool value);
		/**
	     * 获取坐标系的类型
	     */
		virtual VScaleSystem getSystem();
		/**
	     * 设置坐标系的类型
	     */
		virtual void setSystem(VScaleSystem value);
		/**
	     * 获取Y轴文字的颜色
	     */
	    virtual Long getTextColor();
	    /**
	     * 设置Y轴文字的颜色
	     */
		virtual void setTextColor(Long value);
		/**
	     * 获取Y轴文字的颜色2
	     */
		virtual Long getTextColor2();
		/**
	     * 设置Y轴文字的颜色2
	     */
		virtual void setTextColor2(Long value);
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
	     * 获取坐标轴的类型
	     */
		virtual VScaleType getType();
		/**
	     * 设置坐标轴的类型
	     */
		virtual void setType(VScaleType value);
		/*
		* 获取上涨的颜色
		*/
		virtual Long getUpColor();
		/*
		* 设置上涨的颜色
		*/
		virtual void setUpColor(Long value);
		/**
	     * 获取坐标值可见部分的最大值
	     */
		virtual double getVisibleMax();
		/**
	     * 设置坐标值可见部分的最大值
	     */
		virtual void setVisibleMax(double value);
		/**
	     * 获取坐标值可见部分的最小值
	     */
		virtual double getVisibleMin();
		/**
	     * 设置坐标值可见部分的最小值
	     */
		virtual void setVisibleMin(double value);
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
	     * 获取属性名称列表
	     */
		ArrayList<Double> getScaleSteps();
	    /**
         * 重绘方法
         * @param paint  绘图对象
         * @param div    图层
         * @param rect   区域
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
         * 设置属性值
         * @param name  属性名称
         * @param value 属性值
        */
		virtual void setAttribute(const String& name, const String& value);
		/**
	     * 设置刻度点
	     */
		void setScaleSteps(ArrayList<Double> scaleSteps);
	};
}