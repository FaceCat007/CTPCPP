/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __CMONTH_H__
#else                                                                            
#define __CMONTH_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "CDay.h"

namespace FaceCat{
	/*
	* 月
	*/
	class __CMONTH_H__ CMonth{
	public:
	    /**
		 * 创建月
		 */
		int m_month;
		/**
		 * 创建年
		 */
		int m_year;
		/*
		* 创建日期
		*/
		void createDays();
	public:
		/**
		* 创建月
		* @param  year   年
		* @param  month  月
		*/
		CMonth(int year, int month);
		/*
		* 析构函数
		*/
		virtual ~CMonth();
		/*
		* 日的集合
		*/
		HashMap<int, CDay*> m_days;
		/**
		 * 获取月的日数
		 */
		int getDaysInMonth();
		/**
		 * 获取该月的第一日
		 */
		CDay* getFirstDay();
		/**
		 * 获取该月的最后一日
		 */
		CDay* getLastDay();
		/**
		 * 获取月
		 */
		int getMonth();
		/**
		 * 获取年
		 */
		int getYear();
	};
}