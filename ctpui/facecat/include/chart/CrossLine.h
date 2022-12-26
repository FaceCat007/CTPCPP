/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __CROSSLINE_H__
#else                                                                            
#define __CROSSLINE_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "Enums.h"
#include "ChartDiv.h"

namespace FaceCat{
	class ChartDiv;
	/**
     * 十字线
     */
	class __CROSSLINE_H__ CrossLine : public FCAttribute{
	public:
	    /**
	     * 是否允许用户绘图
	     */
		bool m_allowUserPaint;
		/**
	     * 是否允许双击操作
	     */
		bool m_allowDoubleClick;
		/**
	     * 依附于左轴还是右轴
	     */
		AttachVScale m_attachVScale;
		/**
	     * 十字线的颜色
	     */
		Long m_lineColor;
	public:
		/*
		* 构造函数
		*/
		CrossLine();
		/*
		* 析构函数
		*/
		virtual ~CrossLine();
		/**
	     * 获取是否允许双击操作
	     */
		virtual bool allowDoubleClick();
		/**
	     * 设置是否允许双击操作
	     */
		virtual void setAllowDoubleClick(bool value);
		/**
	     * 获取是否允许用户绘图
	     */
		virtual bool allowUserPaint();
		/**
	     * 设置是否允许用户绘图
	     */
		virtual void setAllowUserPaint(bool value);
		/**
	     * 获取依附于左轴还是右轴
	     */
		virtual AttachVScale getAttachVScale();
		/**
	     * 设置依附于左轴还是右轴
	     */
		virtual void setAttachVScale(AttachVScale value);
		/**
	     * 获取十字线的颜色
	     */
		virtual Long getLineColor();
		/**
	     * 设置十字线的颜色
	     */
		virtual void setLineColor(Long value);
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