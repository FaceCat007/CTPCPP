/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCGRIDCELL_H__
#else                                                                            
#define __FCGRIDCELL_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCAttribute.h"
#include "FCGridColumn.h"
#include "FCGridRow.h"
#include "FCGrid.h"

namespace FaceCat{
	class FCGridColumn;
	class FCGridRow;
	class FCGrid;

	/*
	* 单元格样式
	*/
	class __FCGRIDCELL_H__ FCGridCellStyle{
	public:
		FCHorizontalAlign m_align;
		/**
		 * 是否在文字超出范围时在结尾显示省略号
		 */
		bool m_autoEllipsis;
		/**
		 * 获取
		 */
		Long m_backColor;
		/**
		 * 字体
		 */
		FCFont *m_font;
		/**
		 * 前景色
		 */
		Long m_textColor;
	public:
		/*
		* 构造函数
		*/
		FCGridCellStyle();
		/*
		* 析构函数
		*/
		virtual ~FCGridCellStyle();
		/**
		 * 获取内容的横向排列样式
		 */
		virtual FCHorizontalAlign getAlign();
		/**
		 * 设置内容的横向排列样式
		 */
		virtual void setAlign(FCHorizontalAlign value);
		/**
		 * 获取是否在文字超出范围时在结尾显示省略号
		 */
		virtual bool autoEllipsis();
		/**
		 * 设置是否在文字超出范围时在结尾显示省略号
		 */
		virtual void setAutoEllipsis(bool value);
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
	public:
		/*
		* 拷贝
		*/
		void copy(FCGridCellStyle *style);
	};

	/*
	* 单元格
	*/
	class __FCGRIDCELL_H__ FCGridCell : public FCAttribute{
	public:
	    /**
		 * 是否可编辑
		 */
		bool m_allowEdit;
		/*
		* 列的跨度
		*/
		int m_colSpan;
		/**
		 * 所在列
		 */
		FCGridColumn *m_column;
		/**
		 * 表格
		 */
		FCGrid *m_grid;
		/**
		 * 名称
		 */
		String m_name;
		/**
		 * 所在行
		 */
		FCGridRow *m_row;
		/*
		* 行的跨度
		*/
		int m_rowSpan;
		/**
		 * 样式
		 */
		FCGridCellStyle *m_style;
		/**
		 * TAG值
		 */
		Object m_tag;
	public:
		/*
		* 构造函数
		*/
		FCGridCell();
		/*
		* 析构函数
		*/
		virtual ~FCGridCell();
		/**
		 * 获取是否可编辑
		 */
		virtual bool allowEdit();
		/**
		 * 设置是否可编辑
		 */
		virtual void setAllowEdit(bool value);
		/**
		 * 获取跨越的列数
		 */
		virtual int getColSpan();
		/**
		 *设置跨越的列数
		 */
		virtual void setColSpan(int value);
		/**
		 * 获取所在列
		 */
		virtual FCGridColumn* getColumn();
		/**
		 * 设置所在列
		 */
		virtual void setColumn(FCGridColumn *value);
		/**
		 * 获取表格
		 */
		virtual FCGrid* getGrid();
		/**
		 * 设置表格
		 */
		virtual void setGrid(FCGrid *value);
		/**
		 * 获取名称
		 */
		virtual String getName();
		/**
		 * 设置名称
		 */
		virtual void setName(const String& value);
		/**
		 * 获取所在行
		 */
		virtual FCGridRow* getRow();
		/**
		 * 设置所在行
		 */
		virtual void setRow(FCGridRow *value);
		/**
		 * 获取跨越的行数
		 */
		virtual int getRowSpan();
		/**
		 * 设置跨越的行数
		 */
		virtual void setRowSpan(int value);
		/**
		 * 获取样式
		 */
		virtual FCGridCellStyle* getStyle();
		/**
		 * 设置样式
		 */
		virtual void setStyle(FCGridCellStyle *value);
		/**
		 * 获取TAG值
		 */
		virtual Object getTag();
		/**
		 * 设置TAG值
		 */
		virtual void setTag(Object value);
		/**
		 * 获取文字
		 */
		virtual String getText();
		/**
		 * 设置文字
		 */
		virtual void setText(const String& value);
	public:
	    /**
		 * 单元格大小比较，用于排序
		 */
		virtual int compareTo(FCGridCell *cell);
		/**
		 * 获取布尔型数值
		 */
		virtual bool getBool();
		/**
		 * 获取双精度浮点值
		 */
		virtual double getDouble();
		/**
		 * 获取单精度浮点值
		 */
		virtual float getFloat();
		/**
		 * 获取整型数值
		 */
		virtual int getInt();
		/**
		 * 获取长整型数值
		 */
		virtual Long getLong();
		/**
		 * 获取要绘制的文字
		 */
		virtual String getPaintText();
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
		 * 获取字符型数值
		 */
		virtual String getString();
		/**
		 * 添加单元格方法
		 */
		virtual void onAdd();
		/**
		* 重绘方法
		* @param  paint  绘图对象
		* @param  rect  矩形
		* @param  clipRect  裁剪矩形
		* @param  isAlternate  是否交替行
		*/
		virtual void onPaint(FCPaint *paint, const FCRect& rect, const FCRect& clipRect, bool isAlternate);
		/**
		 * 移除单元格方法
		 */
		virtual void onRemove();
		/*
		* 处理缩放
		*/
		virtual void onScaling(double scaleFactorX, double scaleFactorY);
		/**
		 * 设置布尔型数值
		 */
        virtual void setBool(bool value);
        /**
		 * 设置双精度浮点值
		 */
        virtual void setDouble(double value);
        /**
		 * 设置单精度浮点值
		 */
        virtual void setFloat(float value);
        /**
		 * 设置整型数值
		 */
        virtual void setInt(int value);
        /**
		 * 设置长整型数值
		 */
        virtual void setLong(Long value);
		/**
		* 设置属性
		* @param  name  属性名称
		* @param  value  属性值
		*/
		virtual void setAttribute(const String& name, const String& value);
		/**
		 * 设置字符型数值
		 */
        virtual void setString(const String& value);
	};

	/*
	* 视图型单元格
	*/
	class __FCGRIDCELL_H__ FCGridViewCell : public FCGridCell, public FCTouchEventCallBack{
	public:
		FCView *m_view;
	public:
		/*
		* 构造函数
		*/
		FCGridViewCell();
		/*
		* 析构函数
		*/
		virtual ~FCGridViewCell();
		/**
		 * 获取视图
		 */
		FCView* getView();
		/**
		 * 设置视图
		 */
		void setView(FCView *value);
		/**
		 * 获取字符型数值
		 */
		virtual String getString();
		/**
		 * 获取要绘制的文字
		 */
		virtual String getPaintText();
	public:
		/*
		* 触摸事件
		*/
		virtual void callTouchEvent(String eventName, Object sender, FCTouchInfo touchInfo, Object invoke);
		/**
		 * 添加单元格方法
		 */
		virtual void onAdd();
		/**
		 * 视图触摸按下方法
		 */
		virtual void onViewTouchDown(FCTouchInfo touchInfo);
		/**
		 * 视图触摸移动事件
		 */
		virtual void onViewTouchMove(FCTouchInfo touchInfo);
		/**
		 * 视图触摸抬起事件
		 */
		virtual void onViewTouchUp(FCTouchInfo touchInfo);
		/**
		 * 视图触摸滚轮滚动事件
		 */
		virtual void onViewTouchWheel(FCTouchInfo touchInfo);
		/**
		 * 重绘方法
		 */
		virtual void onPaint(FCPaint *paint, const FCRect& rect, const FCRect& clipRect, bool isAlternate);
		/*
		* 重绘视图
		*/
		virtual void onPaintView(FCPaint *paint, const FCRect& rect, const FCRect& clipRect);
		/**
		 * 移除单元格方法
		 */
		virtual void onRemove();
		/**
		 * 设置字符型数值s
		 */
		virtual void setString(const String& value);
	};
}