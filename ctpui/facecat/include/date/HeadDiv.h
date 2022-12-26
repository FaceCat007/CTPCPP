/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __HEADDIV_H__
#else                                                                            
#define __HEADDIV_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "CDay.h"
#include "FCCalendar.h"
#include "DateTitle.h"

namespace FaceCat{
	class ArrowButton;
	class DateTitle;

	/*
	* 头部层
	*/
	class __HEADDIV_H__ HeadDiv:public FCView{
	public:
	    /**
		 * 日历
		 */
		FCCalendar *m_calendar;
		/**
		 * 日期标题
		 */
		DateTitle *m_dateTitle;
		/**
		 * 上个周期的按钮
		 */
		ArrowButton *m_lastBtn;
		/**
		 * 下个周期的按钮
		 */
		ArrowButton *m_nextBtn;
		/*
		* 日期名称
		*/
		String m_weekStrings[7];
	public:
		/*
		* 构造函数
		*/
		HeadDiv(FCCalendar *calendar);
		/*
		* 析构函数
		*/
		virtual ~HeadDiv();
		/**
		 * 获取日历
		 */
		virtual FCCalendar* getCalendar();
		/**
		 * 设置日历
		 */
		virtual void setCalendar(FCCalendar *value);
		/**
		 * 获取日期标题
		 */
		virtual DateTitle* getDateTitle();
		/**
		 * 设置日期标题
		 */
		virtual void setDateTitle(DateTitle *value);
		/**
		 * 获取到上个周期的按钮
		 */
		virtual ArrowButton* getLastBtn();
		/**
		 * 设置到上个周期的按钮
		 */
		virtual void setLastBtn(ArrowButton *value);
		/**
		 * 获取到下个周期的按钮
		 */
		virtual ArrowButton* getNextBtn();
		/**
		 * 设置到下个周期的按钮
		 */
		virtual void setNextBtn(ArrowButton *value);
	public:
	    /**
		 * 获取视图类型
		 */
		virtual String getViewType();
		/**
		 * 添加视图方法
		 */
		virtual void onLoad();
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
		/**
		 * 布局更新方法
		 */
		virtual void update();
	};
}
