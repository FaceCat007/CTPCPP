/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCCALENDAR_H__
#else                                                                            
#define __FCCALENDAR_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "CDay.h"
#include "CYears.h"
#include "CMonth.h"
#include "ArrowButton.h"
#include "DateTitle.h"
#include "DayButton.h"
#include "DayDiv.h"
#include "HeadDiv.h"
#include "MonthButton.h"
#include "MonthDiv.h"
#include "TimeDiv.h"
#include "YearButton.h"
#include "YearDiv.h"

namespace FaceCat{
	class ArrowButton;
	class DateTitle;
	class DayButton;
	class DayDiv;
	class HeadDiv;
	class MonthButton;
	class MonthDiv;
	class TimeDiv;
	class YearButton;
	class YearDiv;

	/*
	* 日历模式
	*/
	enum __FCCALENDAR_H__ FCCalendarMode{
		FCCalendarMode_Day, //选择日
		FCCalendarMode_Month, //选择月
		FCCalendarMode_Year //选择年
	};

	/*
	* 日历视图
	*/
	class __FCCALENDAR_H__ FCCalendar : public FCView{
	private:
	    /**
		 * 秒表ID
		 */
		int m_timerID;;
	public:
	    /**
		 * 日期层
		 */
		DayDiv *m_dayDiv;
		/**
		 * 头部层
		 */
		HeadDiv *m_headDiv;
		/**
		 * 日历的模式
		 */
		FCCalendarMode m_mode;
		/**
		 * 当前的月份
		 */
		int m_month;
		/**
		 * 月份层
		 */
		MonthDiv *m_monthDiv;
		/**
		 * 选中日期
		 */
		CDay *m_selectedDay;
		/**
		 * 时间层
		 */
		TimeDiv *m_timeDiv;
		/**
		 * 是否使用动画
		 */
		bool m_useAnimation;
		/**
		 * 年份
		 */
		int m_year;
		/**
		 * 年份层
		 */
		YearDiv *m_yearDiv;
		/**
		 * 日历
		 */
		CYears *m_years;
	public:
		/*
		* 构造函数
		*/
		FCCalendar();
		/*
		* 析构函数
		*/
		virtual ~FCCalendar();
		/**
		 * 获取日期层
		 */
		virtual DayDiv* getDayDiv();
		/**
		 * 设置日期层
		 */
		virtual void setDayDiv(DayDiv *value);
		/**
		 * 获取头部层
		 */
		virtual HeadDiv* getHeadDiv();
		/**
		 * 设置头部层
		 */
		virtual void setHeadDiv(HeadDiv *value);
		/**
		 * 获取日历的模式
		 */
		virtual FCCalendarMode getMode();
		/**
		 * 设置日历的模式
		 */
		virtual void setMode(FCCalendarMode value);
		/**
		 * 获取月份
		 */
		virtual CMonth* getMonth();
		/**
		 * 设置月份
		 */
		virtual void setMonth(CMonth *value);
		/**
		 * 获取月份层
		 */
		virtual MonthDiv* getMonthDiv();
		/**
		 * 设置月份层
		 */
		virtual void setMonthDiv(MonthDiv *value);
		/**
		 * 获取选中日期
		 */
		virtual CDay* getSelectedDay();
		/**
		 * 设置选中日期
		 */
		virtual void setSelectedDay(CDay *value);
		/**
		 * 获取时间层
		 */
		virtual TimeDiv* getTimeDiv();
		/**
		 * 设置时间层
		 */
		virtual void setTimeDiv(TimeDiv *value);
		/**
		 * 获取是否使用动画
		 */
		virtual bool useAnimation();
		/**
		 * 设置是否使用动画
		 */
		virtual void setUseAnimation(bool value);
		/**
		 * 获取年份层
		 */
		virtual YearDiv* getYearDiv();
		/**
		 * 设置年份层
		 */
		virtual void setYearDiv(YearDiv *value);
		/**
		 * 获取日历
		 */
		virtual CYears* getYears();
		/**
		 * 设置日历
		 */
		virtual void setYears(CYears *value);
	public:
		/*
		* 获取星期
		*/
		static int dayOfWeek(int y, int m, int d);
		/**
		 * 获取视图类型
		 */
		virtual String getViewType();
		/**
		* 根据年月获取上个月
		* @param  year   年
		* @param  month   月
		*/
		CMonth* getLastMonth(int year, int month);
		/**
		* 获取下个月
		* @param  year   年
		* @param  month   月
		*/
		CMonth* getNextMonth(int year, int month);
		/**
		* 获取属性值
		* @param  name   属性名称
		* @param  value  属性值
		* @param  type   类型
		*/
		virtual void getAttribute(const String& name, String *value, String *type);
		/**
		 * 获取属性名称列表
		 */
		virtual ArrayList<String> getAttributeNames();
		/**
         * 获取方法列表
         */
        virtual ArrayList<String> getEventNames();
		/**
		 * 回到上个月
		 */
		void goLastMonth();
		/**
		 * 前往下个月
		 */
		void goNextMonth();
		/**
		* 触摸点击方法
		* @param  touchInfo   触摸信息
		*/
		virtual void onClick(FCTouchInfo touchInfo);
		/**
		 * 视图被添加事件
		 */
		virtual void onLoad();
		/**
		* 键盘方法
		* @param  key  按键
		*/
		virtual void onKeyDown(char key);
		/**
		* 重绘背景方法
		* @param  paint  绘图对象
		* @param  clipRect  裁剪区域
		*/
		virtual void onPaintBackground(FCPaint *paint, const FCRect& clipRect);
		/**
		 * 选中日期更改方法
		 */
		virtual void onSelectedTimeChanged();
		/**
		* 秒表事件
		* @param  timerID  秒表编号
		*/
		virtual void onTimer(int timerID);
		/**
		* 设置属性值
		* @param  name  属性名称
		* @param  value  属性值
		*/
		virtual void setAttribute(const String& name, const String& value);
		/**
		 * 重新布局
		 */
		virtual void update();
public:
		/*
		* 创建箭头按钮
		*/
		virtual ArrowButton* createArrowButton();
		/*
		* 创建标题
		*/
		virtual DateTitle* createDateTitle();
		/*
		* 创建日的按钮
		*/ 
		virtual DayButton* createDayButton();
		/*
		* 创建日期层
		*/
		virtual DayDiv* createDayDiv();
		/*
		* 创建头部层
		*/
		virtual HeadDiv* createHeadDiv();
		/*
		* 创建月的按钮
		*/
		virtual MonthButton* createMonthButton();
		/*
		* 创建月份层
		*/
		virtual MonthDiv* createMonthDiv();
		/*
		* 创建时间层
		*/
		virtual TimeDiv* createTimeDiv();
		/*
		* 创建年的按钮
		*/ 
		virtual YearButton* createYearButton();
		/*
		* 创建年的层
		*/
		virtual YearDiv* createYearDiv();
	};
}