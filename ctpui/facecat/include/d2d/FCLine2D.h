/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCLINE2D_H__
#else                                                                            
#define __FCLINE2D_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCTran.h"

namespace FaceCat{
	/**
     * 线视图
     */
	class __FCLINE2D_H__ FCLine2D : public FCView{
	public:
		/*
		* 是否关闭
		*/
		bool m_close;
		/**
	     * 线的宽度
	     */
		float m_lineWidth;
		/**
	     * 获取或设置点
	     */
		String m_points;
	public:
		/*
		* 构造函数
		*/
		FCLine2D();
		/*
		* 析构函数
		*/
		virtual ~FCLine2D();
		/*
		* 获取是否关闭
		*/
        virtual bool isClose();
		/*
		* 设置是否关闭
		*/
        virtual void setClose(bool value);
		/*
		* 获取线的宽度
		*/
        virtual float getLineWidth();
        /*
		* 设置线的宽度
		*/
        virtual void setLineWidth(float value);
		/*
		* 获取点
		*/
        virtual String getPoints();
		/*
		* 设置点
		*/
        virtual void setPoints(String value);
	public:
	    /**
	     * 获取视图类型
	     */
		virtual String getViewType();
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
         * 重绘背景方法
         * @param paint    绘图对象
         * @param clipRect 裁剪区域
         */
		virtual void onPaint(FCPaint *paint, const FCRect& clipRect);
	    /**
         * 重绘边线方法
         * @param paint    绘图对象
         * @param clipRect 裁剪区域
         */
		virtual void onPaintBorder(FCPaint *paint, const FCRect& clipRect);
	    /**
         * 设置属性
         * @param name    属性名称
         * @param value   属性值
        */
		virtual void setAttribute(const String& name, const String& value);
	};
}
