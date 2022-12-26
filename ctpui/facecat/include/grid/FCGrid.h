/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCGRID_H__
#else                                                                            
#define __FCGRID_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCGridColumn.h"
#include "FCGridRow.h"
#include "FCGridCell.h"
#include "..\\scroll\\FCHScrollBar.h"
#include "..\\scroll\\FCVScrollBar.h"
#include "..\\div\\FCDiv.h"
#include "..\\input\\FCTextBox.h"

namespace FaceCat{
	class FCGridCell;
	class FCGridColumn;
	class FCGridRow;
	class FCGridRowStyle;

	/*
	* 单元格事件
	*/
    class __FCGRID_H__ FCGridCellEventCallBack {
	public:
		FCGridCellEventCallBack(){}
		virtual ~FCGridCellEventCallBack(){}
		virtual void callGridCellEvent(String eventName, Object sender, FCGridCell *cell, Object invoke){}
    };

    /*
	* 单元格触摸事件委托
	*/
    class __FCGRID_H__ FCGridCellTouchEventCallBack {
	public:
		FCGridCellTouchEventCallBack(){}
		virtual ~FCGridCellTouchEventCallBack(){}
		virtual void callGridCellTouchEvent(String eventName, Object sender, FCGridCell *cell, FCTouchInfo touchInfo, Object invoke){}
    };

	/*
	* 行对比
	*/
	class __FCGRID_H__ GridRowCompare{
	public:
	    /**
		 * 列索引
		 */
		int m_columnIndex;
		/**
		 * 类型
		 */
		int m_type;
	public:
		/*
		* 构造函数
		*/
		GridRowCompare();
		/*
		* 析构函数
		*/
		virtual ~GridRowCompare();
		/*
		* 对比
		*/
		bool operator()(FCGridRow *x, FCGridRow *y);
	};

	class FCGrid;

	/*
	* 排序
	*/
	class __FCGRID_H__ FCGridSort{
	public:
		/*
		* 构造函数
		*/
		FCGridSort();
		/*
		* 析构函数
		*/
		virtual ~FCGridSort();
	public:
		/**
		* 排序
		* @param  grid   表格
		* @param  column   列
		* @param  sortMode  排序方式
		*/
		virtual void sortColumn(FCGrid *grid, FCGridColumn *column, FCGridColumnSortMode sortMode);
	};

	/*
	* 表格
	*/
	class __FCGRID_H__ FCGrid:public FCDiv{
	private:
	    /**
		 * 秒表ID
		 */
		int m_timerID;
	public:
	    /**
		 * 是否允许拖动行
		 */
		bool m_allowDragRow;
		/**
		 * 是否允许悬停行
		 */
		bool m_allowHoveredRow;
		/**
		 * 交替行的样式
		 */
		FCGridRowStyle *m_alternateRowStyle;
		/**
		 * 单元格编辑模式
		 */
		FCGridCellEditMode m_cellEditMode;
		/**
		 * 正在编辑的单元格
		 */
		FCGridCell *m_editingCell;
		/**
		 * 编辑文本框丢失焦点事件
		 */
		FCTextBox *m_editTextBox;
		/**
		 * 网格线的颜色
		 */
		Long m_gridLineColor;
		/**
		 * 是否包含不可见行
		 */
		bool m_hasUnVisibleRow;
		/**
		 * 标题头是否可见
		 */
		bool m_headerVisible;
		/**
		 * 标题头的高度
		 */
		int m_headerHeight;
		/**
		 * 横向滚动距离
		 */
		int m_horizontalOffset;
		/**
		 * 触摸悬停的单元格
		 */
		FCGridCell *m_hoveredCell;
		/**
		 * 悬停的行
		 */
		FCGridRow *m_hoveredRow;
		/**
		 * 触摸按下时的位置
		 */
		FCPoint m_touchDownPoint;
		/**
		 * 是否多选
		 */
		bool m_multiSelect;
		/**
		 * 行的样式
		 */
		FCGridRowStyle *m_rowStyle;
		/**
		 * 选中模式
		 */
		FCGridSelectionMode m_selectionMode;
		/**
		 * 排序处理类
		 */
		FCGridSort *m_sort;
		/**
		 * 是否使用动画
		 */
		bool m_useAnimation;
		/**
		 * 纵向滚动距离
		 */
		int m_verticalOffset;
		/**
		* 调用单元格事件
		* @param  eventName  事件ID
		* @param  cell   单元格
		*/
		virtual void callCellEvents(String eventName, FCGridCell *cell);
		/**
		* 调用单元格触摸事件
		* @param  eventName  事件ID
		* @param  cell   单元格
		* @param  touchInfo   触摸信息
		*/
		virtual void callCellTouchEvents(String eventName, FCGridCell *cell, FCTouchInfo touchInfo);
		/**
		* 触摸事件
		* @param  touchInfo  触摸信息
		*/
		virtual void touchEvent(FCTouchInfo touchInfo, int state);
	public:
	    /**
		 * 是否锁定界面更新
		 */
		bool m_lockUpdate;
		/**
		 * 选中的单元格
		 */
		ArrayList<FCGridCell*> m_selectedCells;
		/**
		 * 选中的列
		 */
		ArrayList<FCGridColumn*> m_selectedColumns;
		/**
		 * 选中行
		 */
		ArrayList<FCGridRow*> m_selectedRows;
		/*
		* 获取可见列的宽度 
		*/
		int getAllVisibleColumnsWidth();
		/*
		* 获取可见列的高度
		*/
		int getAllVisibleRowsHeight();
	public:
	    /**
		 * 动画添加的行
		 */
		ArrayList<FCGridRow*> m_animateAddRows;
		/**
		 * 动画移除的行
		 */
		ArrayList<FCGridRow*> m_animateRemoveRows;
		/**
		 * 列的集合
		 */
		ArrayList<FCGridColumn*> m_columns;
		/**
		 * 正在编辑的行
		 */
		FCGridRow *m_editingRow;
		/**
		 * 行的集合
		 */
		ArrayList<FCGridRow*> m_rows;
		/*
		* 构造函数
		*/
		FCGrid();
		/*
		* 析构函数
		*/
		virtual ~FCGrid();
		/**
		 * 获取是否允许拖动行
		 */
		virtual bool allowDragRow();
		/**
		 * 设置是否允许拖动行
		 */
		virtual void setAllowDragRow(bool value);
		/**
		 * 获取是否允许悬停行
		 */
		virtual bool allowHoveredRow();
		/**
		 * 设置是否允许悬停行
		 */
		virtual void setAllowHoveredRow(bool value);
		/**
		 * 获取交替行的样式
		 */
		virtual FCGridRowStyle* getAlternateRowStyle();
		/**
		 * 设置交替行的样式
		 */
		virtual void setAlternateRowStyle(FCGridRowStyle *value);
		/**
		 * 获取单元格编辑模式
		 */
		virtual FCGridCellEditMode getCellEditMode();
		/**
		 * 设置单元格编辑模式
		 */
		virtual void setCellEditMode(FCGridCellEditMode value);
		/**
		 * 获取文本框
		 */
		virtual FCTextBox* getEditTextBox();
		/**
		 * 编辑文本框
		 */
		virtual Long getGridLineColor();
		/**
		 * 获取网格线的颜色
		 */
		virtual void setGridLineColor(Long value);
		/**
		 * 设置网格线的颜色
		 */
		virtual bool isHeaderVisible();
		/**
		 * 获取标题头是否可见
		 */
		virtual void setHeaderVisible(bool value);
		/**
		 * 设置标题头是否可见
		 */
		virtual int getHeaderHeight();
		/**
		 * 获取标题头的高度
		 */
		virtual void setHeaderHeight(int value);
		/**
		 * 设置标题头的高度
		 */
		virtual int getHorizontalOffset();
		/**
		 * 获取横向滚动距离
		 */
		virtual void setHorizontalOffset(int value);
		/**
		 * 设置横向滚动距离
		 */
		virtual FCGridCell* getHoveredCell();
		/**
		 * 获取触摸悬停的行
		 */
		virtual FCGridRow* getHoveredRow();
		/**
		 * 获取是否多选
		 */
		virtual bool isMultiSelect();
		/**
		 * 设置是否多选
		 */
		virtual void setMultiSelect(bool value);
		/**
		 * 获取行的样式
		 */
		virtual FCGridRowStyle* getRowStyle();
		/**
		 * 设置行的样式
		 */
		virtual void setRowStyle(FCGridRowStyle *value);
		/**
		 * 获取选中的单元格
		 */
		virtual ArrayList<FCGridCell*> getSelectedCells();
		/**
		 * 设置选中的单元格
		 */
		virtual void setSelectedCells(ArrayList<FCGridCell*> value);
		/**
		 * 获取选中的列
		 */
		virtual ArrayList<FCGridColumn*> getSelectedColumns();
		/**
		 * 设置选中的列
		 */
		virtual void setSelectedColumns(ArrayList<FCGridColumn*> value);
		/**
		 * 获取选中行
		 */
		virtual ArrayList<FCGridRow*> getSelectedRows();
		/**
		 * 设置选中行
		 */
		virtual void setSelectedRows(ArrayList<FCGridRow*> value);
		/**
		 * 选中模式
		 */
		virtual FCGridSelectionMode getSelectionMode();
		/*
		* 设置选中模式
		*/
		virtual void setSelectionMode(FCGridSelectionMode value);
		/**
		 * 获取排序处理类
		 */
		virtual FCGridSort* getSort();
		/**
		 * 设置排序处理类
		 */
		virtual void setSort(FCGridSort *value);
		/**
		 * 获取是否使用动画
		 */
		virtual bool useAnimation();
		/**
		 * 设置是否使用动画
		 */
		virtual void setUseAnimation(bool value);
		/**
		 * 获取纵向滚动距离
		 */
		virtual int getVerticalOffset();
		/**
		 * 设置纵向滚动距离
		 */
		virtual void setVerticalOffset(int value);
	public:
		/**
		* 添加列
		* @param  column  列
		*/
		virtual void addColumn(FCGridColumn *column);
		/**
		* 添加行
		* @param  row  行
		*/
		virtual void addRow(FCGridRow *row);
		/**
		* 动画添加行
		* @param  row  行
		*/
		virtual void animateAddRow(FCGridRow *row);
		/**
		* 动画移除行
		* @param  row  行
		*/
		virtual void animateRemoveRow(FCGridRow *row);
		/**
		 * 开始更新
		 */
		virtual void beginUpdate();
		/*
		* 调用事件
		*/
		virtual void callEvent(String eventName, Object sender, Object invoke);
		/*
		* 调用键盘事件
		*/
		virtual void callKeyEvent(String eventName, Object sender, char key, Object invoke);
		/**
		 * 请除数据
		 */
		virtual void clear();
		/**
		 * 清除所有列
		 */
		virtual void clearColumns();
		/**
		 * 清除所有行
		 */
		virtual void clearRows();
		/**
		 * 结束更新
		 */
		virtual void endUpdate();
		/**
		* 获取表格列
		* @param  columnIndex  列的索引
		*/
		FCGridColumn* getColumn(int columnIndex);
		/**
		* 获取表格列
		* @param  columnName  列名
		*/
		FCGridColumn* getColumn(const String& columnName);
		/**
		 * 获取所有的列
		 */
		ArrayList<FCGridColumn*> getColumns();
		/**
		 * 获取内容的高度
		 */
		virtual int getContentHeight();
		/**
		 * 获取内容的宽度
		 */
		virtual int getContentWidth();
		/**
		 * 获取视图类型
		 */
		virtual String getViewType();
		/**
		 * 获取显示偏移坐标
		 */
		virtual FCPoint getDisplayOffset();
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
         * 获取方法列表
         */
        virtual ArrayList<String> getEventNames();
		/**
		* 根据坐标获取行
		* @param  mp   坐标
		*/
		FCGridRow* getRow(const FCPoint& mp);
		/**
		* 获取表格行
		* @param  rowIndex   行的索引
		*/
		FCGridRow* getRow(int rowIndex);
		/**
		 * 获取所有的行
		 */
		ArrayList<FCGridRow*> getRows();
		/**
		* 获取可见的行索引
		* @param  visiblePercent   可见百分比
		* @param  firstVisibleRowIndex  首先可见的行索引
		* @param  lastVisibleRowIndex  最后可见的行索引
		*/
		void getVisibleRowsIndex(double visiblePercent, int *firstVisibleRowIndex, int *lastVisibleRowIndex);
		/**
		* 插入行
		* @param  index  索引
		* @param  row  行
		*/
		void insertRow(int index, FCGridRow *row);
		/**
		* 判断行是否可见
		* @param  row  行
		* @param  visiblePercent  可见百分比
		*/
		bool isRowVisible(FCRect *bounds, int rowHeight, int scrollV, double visiblePercent, int cell, int floor);
		/*
		* 判断行是否可见
		*/
		bool isRowVisible(FCGridRow *row, double visiblePercent);
		/**
		* 移动行
		* @param  oldIndex  旧行
		* @param  newIndex  新行
		*/
		void moveRow(int oldIndex, int newIndex);
		/**
		* 单元格触摸点击方法
		* @param  cell    单元格
		* @param  touchInfo  触摸信息
		*/
		virtual void onCellClick(FCGridCell *cell, FCTouchInfo touchInfo);
		/**
		* 单元格编辑开始
		* @param  cell    单元格
		*/
		virtual void onCellEditBegin(FCGridCell *cell);
		/**
		* 单元格编辑结束
		* @param  cell    单元格
		*/
		virtual void onCellEditEnd(FCGridCell *cell);
		/**
		* 单元格触摸按下方法
		* @param  cell    单元格
		* @param  touchInfo  触摸信息
		*/
		virtual void onCellTouchDown(FCGridCell *cell, FCTouchInfo touchInfo);
		/**
		* 单元格触摸进入方法
		* @param  cell    单元格
		* @param  touchInfo  触摸信息
		*/
		virtual void onCellTouchEnter(FCGridCell *cell, FCTouchInfo touchInfo);
		/**
		* 单元格触摸移出方法
		* @param  cell    单元格
		* @param  touchInfo  触摸信息
		*/
		virtual void onCellTouchLeave(FCGridCell *cell, FCTouchInfo touchInfo);
		/**
		* 单元格触摸移动方法
		* @param  cell    单元格
		* @param  touchInfo  触摸信息
		*/
		virtual void onCellTouchMove(FCGridCell *cell, FCTouchInfo touchInfo);
		/**
		* 单元格触摸抬起方法
		* @param  cell    单元格
		* @param  touchInfo  触摸信息
		*/
		virtual void onCellTouchUp(FCGridCell *cell, FCTouchInfo touchInfo);
		/**
		 * 复制文字
		 */
		virtual void onCopy();
		/**
		 * 拖动滚动许可检查
		 */
		virtual bool onDragScrollPermit();
		/*
		* 行拖动结束事件
		*/
		virtual void onRowDraged();
		/**
		* 键盘方法
		* @param  key  键盘参数
		*/
		virtual void onKeyDown(char key);
		/**
		 * 视图添加方法
		 */
		virtual void onLoad();
		/**
		 * 丢失焦点方法
		 */
		virtual void onLostFocus();
		/**
		* 触摸按下方法
		* @param  touchInfo  触摸信息
		*/
		virtual void onTouchDown(FCTouchInfo touchInfo);
		/**
		* 触摸离开方法
		* @param  touchInfo  触摸信息
		*/
		virtual void onTouchLeave(FCTouchInfo touchInfo);
		/**
		* 触摸移动方法
		* @param  touchInfo  触摸信息
		*/
		virtual void onTouchMove(FCTouchInfo touchInfo);
		/**
		* 触摸抬起方法
		* @param  touchInfo  触摸信息
		*/
		virtual void onTouchUp(FCTouchInfo touchInfo);
		/**
		* 重绘前景方法
		* @param  paint  绘图对象
		* @param  clipRect  裁剪区域
		*/
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
		/**
		* 绘制编辑文本框
		* @param  cell  单元格
		* @param  paint  绘图对象
		* @param  rect  区域
		* @param  clipRect  裁剪区域
		*/
		virtual void onPaintEditTextBox(FCGridCell *cell, FCPaint *paint, const FCRect& rect, const FCRect& clipRect);
		/**
		* 行编辑开始
		* @param  row  行
		*/
		virtual void onRowEditBegin(FCGridRow *row);
		/**
		 * 行编辑结束
		 */
		virtual void onRowEditEnd();
		/*
		* 处理缩放
		*/
		virtual void onScaling(double scaleFactorX, double scaleFactorY);
		/**
		 * 选中单元格改变方法
		 */
		virtual void onSelectedCellsChanged();
		/**
		 * 选中列改变方法
		 */
		virtual void onSelectedColumnsChanged();
		/**
		 * 选中行改变方法
		 */
		virtual void onSelectedRowsChanged();
		/**
		 * 设置视图不可见方法
		 */
		virtual void onSetEmptyClipRegion();
		/**
		* 秒表方法
		* @param  timerID  秒表ID
		*/
		virtual void onTimer(int timerID);
		/**
		 * 可见状态改变方法
		 */
		virtual void onVisibleChanged();
		/**
		* 移除列
		* @param  column  列
		*/
		virtual void removeColumn(FCGridColumn *column);
		/**
		* 移除行
		* @param  row  行
		*/
		void removeRow(FCGridRow *row);
		/**
		 * 调整列的布局
		 */
		virtual void resetHeaderLayout();
		/**
		 * 选中上一行
		 */
		FCGridRow* selectFrontRow();
		/*
		* 选中第一行
		*/
		FCGridRow* selectFirstRow();
		/*
		* 选中第一行
		*/
		FCGridRow* selectLastRow();
		/**
		 * 选中下一行
		 */
		FCGridRow* selectNextRow();
		/**
		* 设置属性
		* @param  name  属性名称
		* @param  value  属性值
		*/
		virtual void setAttribute(const String& name, const String& value);
		/**
		* 排序
		* @param  grid  表格
		* @param  column  列
		* @param  sortMode  排序方式
		*/
		virtual void sortColumn(FCGrid *grid, FCGridColumn *column, FCGridColumnSortMode sortMode);
		/**
		 * 重新布局
		 */
		virtual void update();
		/**
		 * 更新列排序
		 */
		void updateSortColumn();
	};
}
