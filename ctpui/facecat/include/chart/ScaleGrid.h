/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __SCALEGRID_H__
#else                                                                            
#define __SCALEGRID_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "ChartDiv.h"

namespace FaceCat{
	class ChartDiv;

    /**
     * 网格线
     */
	class __SCALEGRID_H__ ScaleGrid : public FCAttribute{
	public:
	    /**
	     * 是否允许用户绘图
	     */
		bool m_allowUserPaint;
		/**
	     * 距离
	     */
		int m_distance;
		/**
	     * 网格线的颜色
	     */
		Long m_gridColor;
		/**
	     * 获取或设置横向网格线的样式
	     */
		int m_lineStyle;
		/**
	     * 是否可见
	     */
		bool m_visible;
	public:
		/*
		* 构造函数
		*/
		ScaleGrid();
		/*
		* 析构函数
		*/
		virtual ~ScaleGrid();
		/**
	     * 获取是否允许用户绘图
	     */
		virtual bool allowUserPaint();
		/**
	     * 设置是否允许用户绘图
	     */
		virtual void setAllowUserPaint(bool value);
		/**
	     * 获取距离
	     */
		virtual int getDistance();
		/**
	     * 设置距离
	     */
		virtual void setDistance(int value);
		/**
	     * 获取网格线的颜色
	     */
		virtual Long getGridColor();
		/**
	     * 设置网格线的颜色
	     */
		virtual void setGridColor(Long value);
		/**
	     * 获取横向网格线的样式
	     */
		virtual int getLineStyle();
		/**
	     * 设置横向网格线的样式
	     */
		virtual void setLineStyle(int value);
		/**
	     * 获取是否可见
	     */
		virtual bool isVisible();
		/**
	     * 设置是否可见
	     */
		virtual void setVisible(bool value);
	public:
	     /**
          * 获取属性值
          * @param name  属性名称
          * @param value 返回属性值
          * @param type  返回属性类型
         */
		virtual void getAttribute(const String& name, String *value, String *type);
		/**
	     * 获取属性名称列表
	     */
		virtual ArrayList<String> getAttributeNames();
	    /**
         * 重绘方法
         * @param paint  绘图对象
         * @param div    图层
         * @param rect   区域
        */
		virtual void onPaint(FCPaint *paint, ChartDiv *div, const FCRect& rect);
	    /**
         * 设置属性值
         * @param name  属性名称
         * @param value 属性值
        */
		virtual void setAttribute(const String& name, const String& value);
	};
}