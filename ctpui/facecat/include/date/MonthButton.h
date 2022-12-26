/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __MONTHBUTTON_H__
#else                                                                            
#define __MONTHBUTTON_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\btn\\FCButton.h"
#include "FCCalendar.h"

namespace FaceCat{
	class FCCalendar;

	/*
	* 月的按钮
	*/
	class __MONTHBUTTON_H__ MonthButton:public FCButton{
	public:
	    /**
		 * 显示区域
		 */
		FCRect m_bounds;
		/**
		 * 日历视图
		 */
		FCCalendar *m_calendar;
		/**
		 * 月
		 */
		int m_month;
		/**
		 * 是否可见
		 */
		bool m_visible;
		/**
		 * 年
		 */
		int m_year;
	public:
	    /**
		 * 获取绘制的背景色
		 */
		virtual Long getPaintingBackColor();
		/**
		 * 获取绘制的边线颜色
		 */
		virtual Long getPaintingBorderColor();
		/**
		 * 获取要绘制的前景色
		 */
		virtual Long getPaintingTextColor();
	public:
		/*
		* 构造函数
		*/
		MonthButton(FCCalendar *calendar);
		/*
		* 析构函数
		*/
		virtual ~MonthButton();
		/**
		 * 获取日历视图
		 */
		virtual FCCalendar* getCalendar();
		/**
		 * 设置日历视图
		 */
		virtual void setCalendar(FCCalendar *value);
		/**
		 * 获取显示区域
		 */
		virtual FCRect getBounds();
		/**
		 * 设置显示区域
		 */
		virtual void setBounds(const FCRect& value);
		/**
		 * 获取月
		 */
		virtual int getMonth();
		/**
		 * 设置月
		 */
		virtual void setMonth(int value);
		/**
		 * 获取是否可见
		 */
		virtual bool isVisible();
		/**
		 * 设置是否可见
		 */
		virtual void setVisible(bool value);
		/**
		 * 获取年
		 */
		virtual int getYear();
		/**
		 * 设置年
		 */
		virtual void setYear(int value);
	public:
	    /**
		 * 获取月的文字
		 */
		virtual String getMonthStr();
		/**
		* 触摸点击方法
		* @param  touchInfo   触摸信息
		*/
		virtual void onClick(FCTouchInfo touchInfo);
		/**
		* 重绘背景方法
		* @param  paint   绘图对象
		* @param  clipRect   裁剪区域
		*/
		virtual void onPaintBackground(FCPaint *paint, const FCRect& clipRect);
		/**
		* 重绘边线方法
		* @param  paint   绘图对象
		* @param  clipRect   裁剪区域
		*/
		virtual void onPaintBorder(FCPaint *paint, const FCRect& clipRect);
		/**
		* 重绘前景方法
		* @param  paint   绘图对象
		* @param  clipRect   裁剪区域
		*/
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
	};
}