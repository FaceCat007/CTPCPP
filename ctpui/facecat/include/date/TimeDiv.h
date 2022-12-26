/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __TIMEDIV_H__
#else                                                                            
#define __TIMEDIV_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCCalendar.h"
#include "..\\input\\FCSpin.h"

namespace FaceCat{
	class FCCalendar;

	/*
	* 时间层
	*/
	class __TIMEDIV_H__ TimeDiv : public FCEventCallBack{
	public:
	    /**
		 * 日历视图
		 */
		FCCalendar *m_calendar;
		/**
		 * 高度
		 */
		int m_height;
		/**
		 * 小时
		 */
		FCSpin *m_spinHour;
		/**
		 * 分钟
		 */
		FCSpin *m_spinMinute;
		/**
		 * 秒
		 */
		FCSpin *m_spinSecond;
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
		TimeDiv(FCCalendar *calendar);
		/*
		* 析构函数
		*/
		virtual ~TimeDiv();
		/**
		 * 获取日历视图
		 */
		virtual FCCalendar* getCalendar();
		/**
		 * 设置日历视图
		 */
		virtual void setCalendar(FCCalendar *value);
		/**
		 * 获取或设置高度
		 */
		virtual int getHeight();
		/**
		 * 获取或设置高度
		 */
		virtual void setHeight(int value);
		/**
		 * 获取或设置小时
		 */
		virtual int getHour();
		/**
		 * 获取或设置小时
		 */
		virtual void setHour(int value);
		/**
		 * 获取或设置分钟
		 */
		virtual int getMinute();
		/**
		 * 获取或设置分钟
		 */
		virtual void setMinute(int value);
		/**
		 *获取秒
		 */
		virtual int getSecond();
		/**
		 * 设置秒
		 */
		virtual void setSecond(int value);
	public:
		virtual void callEvent(String eventName, Object sender, Object invoke);
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
		 * 数值修改事件
		 */
		void onSelectedTimeChanged();
		/**
		 * 秒表触发方法
		 */
		void onTimer();
		/**
		 * 更新布局方法
		 */
		void update();
	};
}