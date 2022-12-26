/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __CDAY_H__
#else                                                                            
#define __CDAY_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"

namespace FaceCat{
	/**
		* 创建日
		* @param  year   年
		* @param  month   月
		* @param  day   日
	*/
	class __CDAY_H__ CDay{
	public:
		int m_day;
		int m_month;
		int m_year;
	public:
		/*
		* 构造函数
		*/
		CDay(int year, int month, int day);
		/*
		* 析构函数
		*/
		virtual ~CDay();
		/**
		 * 获取日
		 */
		int getDay();
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