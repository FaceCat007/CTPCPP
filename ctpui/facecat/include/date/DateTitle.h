/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __DATETITLE_H__
#else                                                                            
#define __DATETITLE_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\btn\\FCButton.h"
#include "FCCalendar.h"

namespace FaceCat{
	class FCCalendar;

	/*
	* 日历标题栏
	*/
	class __DATETITLE_H__ DateTitle : public FCButton{
	public:
		FCCalendar *m_calendar;
	public:
		/**
		 * 日期标题
		 */
		DateTitle(FCCalendar *calendar);
		/*
		* 析构函数
		*/
		virtual ~DateTitle();
		/**
		 * 获取日历
		 */
		virtual FCCalendar* getCalendar();
		/**
		 * 设置日历
		 */
		virtual void setCalendar(FCCalendar *value);
	public:
	    /**
		 * 获取视图类型
		 */
		virtual String getViewType();
		/**
		* 触摸点击方法
		* @param  mp   坐标
		* @param  button   触摸按钮
		* @param  clicks   点击次数
		* @param  delta   滚轮值
		*/
		virtual void onClick(FCTouchInfo touchInfo);
		/**
		* 重绘前景方法
		* @param  paint 绘图对象
		* @param  clipRect  	裁剪区域
		*/
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
	};
}