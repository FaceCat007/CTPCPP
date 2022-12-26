/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __ARROWBUTTON_H__
#else                                                                            
#define __ARROWBUTTON_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\btn\\FCButton.h"
#include "FCCalendar.h"
#include "YearDiv.h"

namespace FaceCat{
	class FCCalendar;

	/*
	* 箭头按钮
	*/
	class __ARROWBUTTON_H__ ArrowButton:public FCButton{
	public:
	    /**
		 * 日历视图
		 */
		FCCalendar *m_calendar;
		/**
		 * 是否前往上个月
		 */
		bool m_toLast;
	public:
		/*
		* 构造函数
		*/
		ArrowButton(FCCalendar *calendar);
		/*
		* 析构函数
		*/
		virtual ~ArrowButton();
		/**
		 * 获取日历视图
		 */
		virtual FCCalendar* getCalendar();
		/**
		 * 设置日历视图
		 */
		virtual void setCalendar(FCCalendar *value);
		/**
		 * 获取是否前往上个月
		 */
		virtual bool isToLast();
		/**
		 * 设置是否前往上个月
		 */
		virtual void setToLast(bool value);
	public:
	    /**
		 * 获取视图类型
		 */
		virtual String getViewType();
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
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
	};
}