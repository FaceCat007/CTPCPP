/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __CYEAR_H__
#else                                                                            
#define __CYEAR_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "CMonth.h"

namespace FaceCat{
	/**
		* 创建年
		* @param  year   年份
	*/
	class __CYEAR_H__ CYear{
	public:
	    /**
		 * 年份
		 */
		int m_year;
		void createMonths();
	public:
	    /**
		 * 获取年份
		 */
		CYear(int year);
		/*
		* 析构函数
		*/
		virtual ~CYear();
		/**
		 * 获取或设置月的集合
		 */
		HashMap<Integer,CMonth*> Months;
	};
}
