/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCBANDEDGRIDCOLUMN_H__
#else                                                                            
#define __FCBANDEDGRIDCOLUMN_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCGridEnums.h"
#include "FCBandedGrid.h"
#include "FCGridColumn.h"
#include "FCGridBand.h"

namespace FaceCat{
	class FCBandedGrid;
	class FCGridColumn;
	class FCGridBand;

	/*
	* 多列头表格列
	*/
	class __FCBANDEDGRIDCOLUMN_H__ FCBandedGridColumn : public FCGridColumn{
	public:
	    /**
		 * 表格带
		 */
		FCGridBand *m_band;
	public:
		/*
		* 构造函数
		*/
		FCBandedGridColumn();
		/*
		* 析构函数
		*/
		virtual ~FCBandedGridColumn();
		/**
		 * 获取表格带
		 */
		virtual FCGridBand* getBand();
		/**
		 * 设置表格带
		 */
		virtual void setBand(FCGridBand *value);
	public:
	    /**
		 * 获取视图类型
		 */
		virtual String getViewType();
		/**
		 * 拖动开始方法
		 */
		virtual bool onDragBegin();
		/**
		* 触摸按下方法
         * @param  touchInfo   触摸信息
		*/
		virtual void onTouchDown(FCTouchInfo touchInfo);
		/**
		* 触摸移动方法
         * @param  touchInfo   触摸信息
		*/
		virtual void onTouchMove(FCTouchInfo touchInfo);
	};
}
