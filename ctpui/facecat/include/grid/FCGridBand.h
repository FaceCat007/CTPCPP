/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCGRIDBAND_H__
#else                                                                            
#define __FCGRIDBAND_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCGridEnums.h"
#include "FCBandedGrid.h"
#include "FCBandedGridColumn.h"
#include "..\\btn\\FCButton.h"

namespace FaceCat{
	class FCBandedGrid;
	class FCBandedGridColumn;

	/*
	* 表格带
	*/
	class __FCGRIDBAND_H__ FCGridBand : public FCButton{
	public:
	    /**
		 * 是否可以调整大小
		 */
		bool m_allowResize;
		/**
		 * 表格
		 */
		FCBandedGrid *m_grid;
		/**
		 * 索引
		 */
		int m_index;
		/**
		 * 父表格带
		 */
		FCGridBand *m_parentBand;
	public:
	    /**
		 * 起始宽度
		 */
		int m_beginWidth;
		/**
		 * 触摸按下时的坐标
		 */
        FCPoint m_touchDownPoint;
        /**
		 * 调整大小状态，1:左侧 2:右侧
		 */
		int m_resizeState;
	public:
	    /**
		 * 子表格带
		 */
		ArrayList<FCGridBand*> m_bands;
		/**
		 * 子表格列
		 */
		ArrayList<FCBandedGridColumn*> m_columns;
		/*
		* 构造函数
		*/
		FCGridBand();
		/*
		* 析构函数
		*/
		virtual ~FCGridBand();
		/**
		 * 获取是否可以调整大小
		 */
		virtual bool allowResize();
		/**
		 * 设置是否可以调整大小
		 */
		virtual void setAllowResize(bool value);
		/**
		 * 获取表格
		 */
		virtual FCBandedGrid* getGrid();
		/**
		 * 设置表格
		 */
		virtual void setGrid(FCBandedGrid *value);
		/**
		 * 获取索引
		 */
		virtual int getIndex();
		/**
		 * 设置索引
		 */
		virtual void setIndex(int value);
		/**
		 * 获取父表格带
		 */
		virtual FCGridBand* getParentBand();
		/**
		 * 设置父表格带
		 */
		virtual void setParentBand(FCGridBand *value);
	public:
	    /**
		 * 添加表格带
		 */
		void addBand(FCGridBand *band);
		/**
		 * 添加表格列
		 */
		void addColumn(FCBandedGridColumn *column);
		/**
		 * 清除表格带
		 */
		void clearBands();
		/**
		 * 清除列
		 */
		void clearColumns();
		/**
		 * 获取所有的子表格列
		 */
		ArrayList<FCBandedGridColumn*> getAllChildColumns();
		/**
		 * 获取表格带列表
		 */
		ArrayList<FCGridBand*> getBands();
		/**
		 * 获取列头
		 */
		ArrayList<FCBandedGridColumn*> getColumns();
		/**
		 * 获取视图类型
		 */
		virtual String getViewType();
		/**
		* 获取属性值
		* @param  name  属性名称
		* @param  value  返回属性值
		* @param  type  返回属性类型
		*/
		virtual void getAttribute(const String& name, String *value, String *type);
		/**
		 * 获取属性名称列表
		 */
		virtual ArrayList<String> getAttributeNames();
		/**
		* 插入表格带
		* @param  index   索引
		* @param  band   表格带
		*/
		void insertBand(int index, FCGridBand *band);
		/**
		* 插入表格列
		* @param  index   索引
		* @param  band   表格带
		*/
		void insertColumn(int index, FCBandedGridColumn *column);
		/**
		* 触摸按下方法
         * @param  touchInfo    触摸信息
		*/
		virtual void onTouchDown(FCTouchInfo touchInfo);
		/**
		* 触摸移动方法
         * @param  touchInfo    触摸信息
		*/
		virtual void onTouchMove(FCTouchInfo touchInfo);
		/**
		* 触摸抬起方法
         * @param  touchInfo    触摸信息
		*/
		virtual void onTouchUp(FCTouchInfo touchInfo);
		/**
		 * 移除表格带
		 */
		void removeBand(FCGridBand *band);
		/**
		 * 移除表格列
		 */
		void removeColumn(FCBandedGridColumn *column);
		/**
		 * 重置列头布局
		 */
		virtual void resetHeaderLayout();
		/**
		* 设置属性
		* @param  name  属性名称
		* @param  value  属性值
		*/
		virtual void setAttribute(const String& name, const String& value);
	};
}