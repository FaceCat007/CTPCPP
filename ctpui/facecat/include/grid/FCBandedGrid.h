/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCBANDEDGRID_H__
#else                                                                            
#define __FCBANDEDGRID_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCGridEnums.h"
#include "FCBandedGridColumn.h"
#include "FCGridBand.h"
#include "FCGrid.h"

namespace FaceCat{
	class FCBandedGridColumn;
	class FCGridBand;

	/*
	* 带状表格
	*/
	class __FCBANDEDGRID_H__ FCBandedGrid : public FCGrid{
	public:
	    /**
		 * 获取所有可见带的宽度
		 */
		int getAllVisibleBandsWidth();
	public:
	    /**
		 * 表格带
		 */
		ArrayList<FCGridBand*> m_bands;
		/*
		* 构造函数
		*/
		FCBandedGrid();
		/*
		* 析构函数
		*/
		virtual ~FCBandedGrid();
	public:
		/**
		* 添加表格带
		* @param  band  表格带
		*/
		void addBand(FCGridBand *band);
		/**
		* 添加列
		* @param  column  列
		*/
		virtual void addColumn(FCGridColumn *column);
		/**
		 * 清除表格带
		 */
		void clearBands();
		/**
		 * 清除所有的列
		 */
		virtual void clearColumns();
        /**
		 * 获取表格带列表
		 */
		ArrayList<FCGridBand*> getBands();
		/**
		 * 获取内容的宽度
		 */
		virtual int getContentWidth();
		/**
		 * 获取视图类型
		 */
		virtual String getViewType();
		/**
		* 插入表格带
		* @param  index  索引
		* @param  band  表格带
		*/
		void insertBand(int index, FCGridBand *band);
		/**
		 * 设置视图不可见方法
		 */
		virtual void onSetEmptyClipRegion();
		/**
		* 移除表格带
		* @param  band  表格带
		*/
		void removeBand(FCGridBand *band);
		/**
		* 移除列头
		* @param  column  列头
		*/
		virtual void removeColumn(FCGridColumn *column);
		/**
		 * 重置列头布局
		 */
		virtual void resetHeaderLayout();
		/**
		 * 重新布局
		 */
		virtual void update();
	};
}
