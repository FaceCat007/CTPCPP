/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __YEARDIV_H__
#else                                                                            
#define __YEARDIV_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "YearButton.h"
#include "HeadDiv.h"
#include "TimeDiv.h"

namespace FaceCat{
	class FCCalendar;
	class HeadDiv;
	class YearButton;
	class TimeDiv;

	/*
	* 年的层
	*/
	class __YEARDIV_H__ YearDiv{
	public:
	    /**
		 * 动画的方向
		 */
		int m_am_Direction;
		/**
		 * 动画当前帧数
		 */
		int m_am_Tick;
		/**
		 * 动画总帧数
		 */
		int m_am_TotalTick;
		/**
		 * 日历视图
		 */
		FCCalendar *m_calendar;
		/**
		 * 开始年份
		 */
		int m_startYear;
	public:
	    /**
		 * 月的按钮
		 */
		ArrayList<YearButton*> m_yearButtons;
		/**
		 * 月的动画按钮
		 */
		ArrayList<YearButton*> m_yearButtons_am;
	public:
		/*
		* 构造函数
		*/
		YearDiv(FCCalendar *calendar);
		/*
		* 析构函数
		*/
		virtual ~YearDiv();
		/**
		 * 获取日历视图
		 */
		virtual FCCalendar* getCalendar();
		/**
		 * 设置日历视图
		 */
		virtual void setCalendar(FCCalendar *value);
		/**
		 * 获取开始年份
		 */
		virtual int getStartYear();
	public:
	    /**
		 * 隐藏
		 */
		void hide();
		/**
		* 触摸点击方法
		* @param  mp   坐标
		* @param  button   按钮
		* @param  clicks   点击次数
		* @param  delta   滚轮数
		*/
		void onClick(FCTouchInfo touchInfo);
		/**
		 * 添加视图方法
		 */
		void onLoad();
		/**
		* 重绘方法
		* @param  paint   绘图对象
		* @param  clipRect   裁剪区域
		*/
		void onPaint(FCPaint *paint, const FCRect& clipRect);
		/**
		* 重置日期图层
		* @param  state  状态
		*/
		void onResetDiv(int state);
		/**
		 * 秒表触发方法
		 */
		void onTimer();
		/**
		* 选择开始年份
		* @param  startYear  开始年份
		*/
		void selectStartYear(int startYear);
		/**
		 * 显示
		 */
		void show();
		/**
		 * 更新布局方法
		 */
		void update();
	};
}