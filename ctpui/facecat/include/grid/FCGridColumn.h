/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCGRIDCOLUMN_H__
#else                                                                            
#define __FCGRIDCOLUMN_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCGridEnums.h"
#include "FCGrid.h"
#include "..\\btn\\FCButton.h"

namespace FaceCat{
	class FCGrid;

	/*
	* 表格列
	*/
	class __FCGRIDCOLUMN_H__ FCGridColumn : public FCButton{
	public:
		/**
		 * 是否可以拖动行
		 */
		bool m_allowDragRow;
	    /**
		 * 是否可以排序
		 */
		bool m_allowSort;
		/**
		 * 是否可以调整大小
		 */
		bool m_allowResize;
		/**
		 * 内容的横向排列样式
		 */
		FCHorizontalAlign m_cellAlign;
		/**
		 * 列的类型
		 */
		String m_columnType;
		/**
		 * 是否冻结
		 */
		bool m_frozen;
		/**
		 * 表格
		 */
		FCGrid *m_grid;
		/**
		 * 头部的矩形
		 */
		FCRect m_headerRect;
		/**
		 * 索引
		 */
		int m_index;
		/**
		 * 排序状态
		 */
		FCGridColumnSortMode m_sortMode;
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
		 * 调整大小状态
		 */
		int m_resizeState;
	public:
		/*
		* 构造函数
		*/
		FCGridColumn();
		/*
		* 构造函数
		*/
		FCGridColumn(const String& text);
		/*
		* 析构函数
		*/
		virtual ~FCGridColumn();
		/*
		* 获取是否可以拖动行
		*/
		virtual bool allowDragRow();
		/*
		* 设置是否可以拖动行
		*/ 
		virtual void setAllowDragRow(bool value);
		/**
		 * 获取是否可以调整大小
		 */
		virtual bool allowResize();
		/**
		 * 获设置是否可以调整大小
		 */
		virtual void setAllowResize(bool value);
		/**
		 * 获取是否可以排序
		 */
		virtual bool allowSort();
		/**
		 * 设置是否可以排序
		 */
		virtual void setAllowSort(bool value);
		/**
		 * 获取内容的横向排列样式
		 */
		virtual FCHorizontalAlign getCellAlign();
		/**
		 * 设置内容的横向排列样式
		 */
		virtual void setCellAlign(FCHorizontalAlign value);
		/**
		 * 获取列的类型
		 */
		virtual String getColumnType();
		/**
		 * 设置列的类型
		 */
		virtual void setColumnType(String value);
		/**
		 * 获取是否冻结
		 */
		virtual bool isFrozen();
		/**
		 * 设置是否冻结
		 */
		virtual void setFrozen(bool value);
		/**
		 * 获取表格
		 */
		virtual FCGrid* getGrid();
		/**
		 * 设置表格
		 */
		virtual void setGrid(FCGrid *value);
		/**
		 * 获取头部的矩形
		 */
		virtual FCRect getHeaderRect();
		/**
		 * 设置头部的矩形
		 */
		virtual void setHeaderRect(FCRect value);
		/**
		 * 获取索引
		 */
		virtual int getIndex();
		/**
		 * 设置索引
		 */
		virtual void setIndex(int value);
		/**
		 * 获取排序状态，0:不排序 1:升序 2:降序
		 */
		virtual FCGridColumnSortMode getSortMode();
		/**
		 * 设置排序状态，0:不排序 1:升序 2:降序
		 */
		virtual void setSortMode(FCGridColumnSortMode value);
	public:
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
		 * 点击方法
		 */
		virtual void onClick(FCTouchInfo touchInfo);
		/**
		 * 拖动开始方法
		 */
		virtual bool onDragBegin();
		/**
		 * 拖动中方法
		 */
		virtual void onDragging();
		/**
		 * 触摸按下方法
		 */
		virtual void onTouchDown(FCTouchInfo touchInfo);
		/**
		 * 触摸移动方法
		 */
		virtual void onTouchMove(FCTouchInfo touchInfo);
		/**
		 * 触摸抬起方法
		 */
		virtual void onTouchUp(FCTouchInfo touchInfo);
		/**
		 * 重绘前景方法
		 */
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
		/**
		* 设置属性
		* @param  name  属性名称
		* @param  value  属性值
		*/
		virtual void setAttribute(const String& name, const String& value);
	};
}