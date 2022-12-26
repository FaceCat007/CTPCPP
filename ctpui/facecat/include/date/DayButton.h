/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __DAYBUTTON_H__
#else                                                                            
#define __DAYBUTTON_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "CDay.h"
#include "FCCalendar.h"

namespace FaceCat{
	class FCCalendar;

    /**
	* 日期按钮
	*/
	class __DAYBUTTON_H__ DayButton{
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
		 * 保存的日期
		 */
		CDay *m_day;
		/**
		 * 是否在本月
		 */
		bool m_inThisMonth;
		/**
		 * 是否被选中
		 */
		bool m_selected;
		/**
		 * 是否可见
		 */
		bool m_visible;
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
		DayButton(FCCalendar *calendar);
		/*
		* 析构函数
		*/
		virtual ~DayButton();
		/**
		 * 获取显示区域
		 */
		virtual FCRect getBounds();
		/**
		 * 设置显示区域
		 */
		virtual void setBounds(const FCRect& value);
		/**
		 * 获取日历视图
		 */
		virtual FCCalendar* getCalendar();
		/**
		 * 设置日历视图
		 */
		virtual void setCalendar(FCCalendar *value);
		/**
		 * 获取保存的日期
		 */
		virtual CDay* getDay();
		/**
		 * 设置保存的日期
		 */
		virtual void setDay(CDay *value);
		/**
		 * 获取是否在本月
		 */
		virtual bool inThisMonth();
		/**
		 * 设置是否在本月
		 */
		virtual void setThisMonth(bool value);
		/**
		 * 获取是否被选中
		 */
		virtual bool isSelected();
		/**
		 * 设置是否被选中
		 */
		virtual void setSelected(bool value);
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
		* 触摸点击事件
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