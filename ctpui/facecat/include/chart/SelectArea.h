/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */


#ifdef __SELECTAREA_H__
#else                                                                            
#define __SELECTAREA_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "ChartDiv.h"

namespace FaceCat{
	class ChartDiv;

    /**
     * 选中区域
     */
	class __SELECTAREA_H__ SelectArea : public FCAttribute{
	public:
	    /**
	     * 是否允许用户绘图
	     */
		bool m_allowUserPaint;
		/**
	     * 背景色
	     */
		Long m_backColor;
		/**
	     * 选中框的区域
	     */
		FCRect m_bounds;
		/**
	     * 是否可以改变选中框的大小
	     */
		bool m_canResize;
		/**
	     * 是否可以出现选中框
	     */
		bool m_enabled;
		/**
	     * 选中框的颜色
	     */
		Long m_lineColor;
		/**
	     * 是否显示选中框
	     */
		bool m_visible;
	public:
		/*
		* 构造函数
		*/
		SelectArea();
		/*
		* 析构函数
		*/
		virtual ~SelectArea();
		/**
	     * 获取是否允许用户绘图
	     */
		virtual bool allowUserPaint();
		/**
	     * 设置是否允许用户绘图
	     */
		virtual void setAllowUserPaint(bool value);
		/**
	     * 获取背景色
	     */
		virtual Long getBackColor();
		/**
	     * 设置背景色
	     */
		virtual void setBackColor(Long value);
		/**
	     * 获取选中框的区域
	     */
		virtual FCRect getBounds();
		/**
	     * 设置选中框的区域
	     */
		virtual void setBounds(FCRect value);
		/**
	     * 获取是否可以改变选中框的大小
	     */
		virtual bool canResize();
		/**
	     * 设置是否可以改变选中框的大小
	     */
		virtual void setCanResize(bool value);
		/**
	     * 获取是否可以出现选中框
	     */
		virtual bool isEnabled();
		/**
	     * 设置是否可以出现选中框
	     */
		virtual void setEnabled(bool value);
		/**
	     * 获取选中框的颜色
	     */
		virtual Long getLineColor();
		/**
	     * 设置选中框的颜色
	     */
		virtual void setLineColor(Long value);
		/**
	     * 获取是否显示选中框
	     */
		virtual bool isVisible();
		/**
	     * 设置是否显示选中框
	     */
		virtual void setVisible(bool value);
	public:
	    /**
	     * 关闭
	     */
		void close();
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