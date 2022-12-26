/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCTABLELAYOUTDIV_H__
#else                                                                            
#define __FCTABLELAYOUTDIV_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCDiv.h"

namespace FaceCat{
    /**
	 * 调整大小的类型
	 */
	enum __FCTABLELAYOUTDIV_H__ FCSizeType{
	    /**
		 * 绝对大小
		 */
		FCSizeType_AbsoluteSize,
		/**
		 * 自动填充
		 */
		FCSizeType_AutoFill,
		/**
		 * 百分比大小
		 */
		FCSizeType_PercentSize
	};

	/*
	* 列的样式
	*/
	class __FCTABLELAYOUTDIV_H__ FCColumnStyle : public FCAttribute{
	public:
	    /**
		 * 调整大小的类型
		 */
		FCSizeType m_sizeType;
		/**
		 * 宽度
		 */
		float m_width;
	public:
		/*
		* 构造函数
		*/
		FCColumnStyle();
		/*
		* 构造函数
		*/
		FCColumnStyle(FCSizeType sizeType, float width);
		/*
		* 析构函数
		*/
		virtual ~FCColumnStyle();
		/**
		 * 获取调整大小的类型
		 */
		virtual FCSizeType getSizeType();
		/**
		 * 设置调整大小的类型
		 */
		virtual void setSizeTypeA(FCSizeType value);
		/**
		 * 获取宽度
		 */
		virtual float getWidth();
		/**
		 * 设置宽度
		 */
		virtual void setWidth(float value);
	public:
		/**
		* 获取属性值
		* @param  name   属性名称
		* @param  value   返回属性值
		* @param  type   返回属性类型
		*/
		virtual void getAttribute(const String& name, String *value, String *type);
		/**
		 * 获取属性名称列表
		 */
		virtual ArrayList<String> getAttributeNames();
		/**
		* 设置属性值
		* @param  name   属性名称
		* @param  value   属性值
		*/
		virtual void setAttribute(const String& name, const String& value);
	};

	/*
	* 行的样式
	*/
	class __FCTABLELAYOUTDIV_H__ FCRowStyle : public FCAttribute{
	public:
	    /**
		 * 宽度
		 */
		float m_height;
		/**
		 * 调整大小的类型
		 */
		FCSizeType m_sizeType;
	public:
		/*
		* 构造函数
		*/
		FCRowStyle();
		/*
		* 构造函数
		*/
		FCRowStyle(FCSizeType sizeType, float height);
		/*
		* 析构函数
		*/
		virtual ~FCRowStyle();
		/**
		 * 获取宽度
		 */
		virtual float getHeight();
		/**
		 * 设置宽度
		 */
		virtual void setHeight(float value);
		/**
		 * 获取调整大小的类型
		 */
		virtual FCSizeType getSizeType();
		/**
		 * 设置调整大小的类型
		 */
		virtual void setSizeTypeA(FCSizeType value);
	public:
		/**
		* 获取属性值
		* @param  name   属性名称
		* @param  value   返回属性值
		* @param  type   返回属性类型
		*/
		virtual void getAttribute(const String& name, String *value, String *type);
		/**
		 * 获取属性名称列表
		 */
		virtual ArrayList<String> getAttributeNames();
		/**
		* 设置属性值
		* @param  name   属性名称
		* @param  value   属性值
		*/
		virtual void setAttribute(const String& name, const String& value);
	};

	/*
	* 表格层
	*/
	class __FCTABLELAYOUTDIV_H__ FCTableLayoutDiv : public FCDiv{
	public:
	    /**
		 * 列的集合
		 */
		ArrayList<Integer> m_columns;
		/**
		 * 列的数量
		 */
		int m_columnsCount;
		/**
		 * 行的集合
		 */
		ArrayList<Integer> m_rows;
		/**
		 * 行的数量
		 */
		int m_rowsCount;
		/**
		 * 表格视图
		 */
		ArrayList<FCView*> m_tableViews;
	public:
	    /**
		 * 列的样式
		 */
		ArrayList<FCColumnStyle> m_columnStyles;
		/**
		 * 行的样式
		 */
		ArrayList<FCRowStyle> m_rowStyles;
		/*
		* 构造函数
		*/
		FCTableLayoutDiv();
		/*
		* 析构函数
		*/
		virtual ~FCTableLayoutDiv();
		/**
		 * 获取列的数量
		 */
		virtual int getColumnsCount();
		/**
		 * 设置列的数量
		 */
		virtual void setColumnsCount(int value);
		/**
		 * 获取行的数量
		 */
		virtual int getRowsCount();
		/**
		 * 设置行的数量
		 */
		virtual void setRowsCount(int value);
	public:
		/**
		* 添加视图
		* @param  view   视图
		*/
		virtual void addView(FCView *view);
		/**
		* 添加视图
		* @param  view   视图
		* @param  column   列
		* @param  row   行
		*/
		virtual void addView(FCView *view, int column, int row);
		/**
		 * 获取视图类型
		 */
		virtual String getViewType();
		/**
		* 获取属性值
		* @param  name   属性名称
		* @param  value   返回属性值
		* @param  type   返回属性类型
		*/
		virtual void getAttribute(const String& name, String *value, String *type);
		/**
		 * 获取属性名称列表
		 */
		virtual ArrayList<String> getAttributeNames();
		/**
		 * 重置布局
		 */
		virtual bool onResetLayout();
		/**
		* 移除视图
		* @param  view   视图
		*/
		virtual void removeView(FCView *view);
		/**
		* 设置属性值
		* @param  name   属性名称
		* @param  value   属性值
		*/
		virtual void setAttribute(const String& name, const String& value);
		/**
		 * 布局更新方法
		 */
		virtual void update();
	};
}
