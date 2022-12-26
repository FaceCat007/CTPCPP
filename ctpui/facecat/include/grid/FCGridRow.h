/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCGRIDROW_H__
#else                                                                            
#define __FCGRIDROW_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCAttribute.h"
#include "FCGridCell.h"
#include "FCGrid.h"
#include "FCGridColumn.h"

namespace FaceCat{
	class FCGridCell;
	class FCGrid;
	class FCGridColumn;

	/*
	* 表格行的央视
	*/
	class __FCGRIDROW_H__ FCGridRowStyle{
	public:
	    /**
		 * 表格行的样式
		 */
		Long m_backColor;
		/**
		 * 字体
		 */
		FCFont *m_font;
		/**
		 * 触摸悬停行的背景色
		 */
		Long m_hoveredBackColor;
		/**
		 * 触摸悬停行的前景色
		 */
		Long m_hoveredTextColor;
		/**
		 * 选中行的背景色
		 */
		Long m_selectedBackColor;
		/**
		 * 选中行的前景色
		 */
		Long m_selectedTextColor;
		/**
		 * 前景色
		 */
		Long m_textColor;
	public:
		/*
		* 构造函数
		*/
		FCGridRowStyle();
		/*
		* 析构函数
		*/
		virtual ~FCGridRowStyle();
		/*
		* 获取背景色
		*/
		virtual Long getBackColor();
		/*
		* 设置背景色
		*/
		virtual void setBackColor(Long value);
		/**
		 * 获取字体
		 */
		virtual FCFont* getFont();
		/**
		 * 设置字体
		 */
		virtual void setFont(FCFont *value);
		/**
		 * 获取前景色
		 */
		virtual Long getTextColor();
		/**
		 * 设置前景色
		 */
		virtual void setTextColor(Long value);
		/**
		 * 获取触摸悬停行的背景色
		 */
		virtual Long getHoveredBackColor();
		/**
		 * 设置触摸悬停行的背景色
		 */
		virtual void setHoveredBackColor(Long value);
		/**
		 * 获取触摸悬停行的前景色
		 */
		virtual Long getHoveredTextColor();
		/**
		 * 设置触摸悬停行的前景色
		 */
		virtual void setHoveredTextColor(Long value);
		/**
		 * 获取选中行的背景色
		 */
		virtual Long getSelectedBackColor();
		/**
		 * 设置选中行的背景色
		 */
		virtual void setSelectedBackColor(Long value);
		/**
		 * 获取选中行的前景色
		 */
		virtual Long getSelectedTextColor();
		/**
		 * 设置选中行的前景色
		 */
		virtual void setSelectedTextColor(Long value);
	public:
		/*
		* 拷贝对象
		*/
		void copy(FCGridRowStyle *style);
	};

	/*
	* 表格行
	*/
	class __FCGRIDROW_H__ FCGridRow : public FCAttribute{
	public:
	    /**
		 * 是否允许编辑
		 */
		bool m_allowEdit;
		/**
		 * 显示区域
		 */
		FCRect m_bounds;
		/**
		 * 编辑按钮
		 */
		FCView *m_editButton;
		/**
		 * 所在表格
		 */
		FCGrid *m_grid;
		int m_height;
		/**
		 * 横向滚动距离
		 */
		int m_horizontalOffset;
		/**
		 * 索引
		 */
		int m_index;
		/**
		 * TAG值
		 */
		Object m_tag;
		/**
		 * 是否可见
		 */
		bool m_visible;
		/**
		 * 可见索引
		 */
		int m_visibleIndex;
	public:
		/*
		* 单元格
		*/
		ArrayList<FCGridCell*> m_cells;
		/*
		* 编辑状态
		*/
		int m_editState;
		/*
		* 构造函数
		*/
		FCGridRow();
		/*
		* 析构函数
		*/
		virtual ~FCGridRow();
		/**
		 * 获取是否允许编辑
		 */
		virtual bool allowEdit();
		/**
		 * 设置是否允许编辑
		 */
		virtual void setAllowEdit(bool value);
		/**
		 * 获取显示区域
		 */
		virtual FCRect getBounds();
		/**
		 * 设置显示区域
		 */
		virtual void setBounds(FCRect value);
		/**
		 * 获取编辑按钮
		 */
		virtual FCView* getEditButton();
		/**
		 * 设置编辑按钮
		 */
		virtual void setEditButton(FCView *value);
		/**
		 * 获取所在表格
		 */
		virtual FCGrid* getGrid();
		/**
		 * 设置所在表格
		 */
		virtual void setGrid(FCGrid *value);
		/**
		 * 获取行高
		 */
		virtual int getHeight();
		/**
		 * 设置行高
		 */
		virtual void setHeight(int value);
		/**
		 * 获取横向滚动距离
		 */
		virtual int getHorizontalOffset();
		/**
		 * 设置横向滚动距离
		 */
		virtual void setHorizontalOffset(int value);
		/**
		 * 获取索引
		 */
		virtual int getIndex();
		/**
		 * 设置索引
		 */
		virtual void setIndex(int value);
		/**
		 * 获取TAG值
		 */
		virtual Object getTag();
		/**
		 * 设置TAG值
		 */
		virtual void setTag(Object value);
		/**
		 * 获取是否可见
		 */
		virtual bool isVisible();
		/**
		 * 设置是否可见
		 */
		virtual void setVisible(bool value);
		/**
		 * 获取可见索引
		 */
		virtual int getVisibleIndex();
		/**
		 * 设置可见索引
		 */
		virtual void setVisibleIndex(int value);
	public:
	    /**
		 * 添加单元格
		 */
		void addCell(FCGridColumn *column, FCGridCell *cell);
		/**
		 * 添加单元格
		 */
		void addCell(int columnIndex, FCGridCell *cell);
		/**
		 * 添加单元格
		 */
		void addCell(const String& columnName, FCGridCell *cell);
		/**
		 * 清除单元格
		 */
		void clearCells();
		/**
		 * 获取所有单元格
		 */
		ArrayList<FCGridCell*> getCells();
		/**
		 * 根据列的名称获取单元格
		 */
		FCGridCell* getCell(FCGridColumn *column);
		/**
		 * 根据列的索引获取单元格
		 */
		FCGridCell* getCell(int columnIndex);
		/**
		 * 根据列的名称获取单元格
		 */
		FCGridCell* getCell(const String& columnName);
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
		 * 添加行方法
		 */
		virtual void onAdd();
		/**
		 * 重绘方法
		 */
		virtual void onPaint(FCPaint *paint, const FCRect& clipRect, bool isAlternate);
		/**
		 * 重绘边线方法
		 */
		virtual void onPaintBorder(FCPaint *paint, const FCRect& clipRect, bool isAlternate);
		/**
		 * 移除行方法
		 */
		virtual void onRemove();
		/*
		* 处理缩放
		*/
		virtual void onScaling(double scaleFactorX, double scaleFactorY);
		/**
		 * 移除单元格
		 */
		void removeCell(FCGridColumn *column);
		/**
		 * 移除单元格
		 */
		void removeCell(int columnIndex);
		/**
		 * 移除单元格
		 */
		void removeCell(const String& columnName);
		/**
		* 设置属性
		* @param  name  属性名称
		* @param  value  属性值
		*/
		virtual void setAttribute(const String& name, const String& value);
	};
}
