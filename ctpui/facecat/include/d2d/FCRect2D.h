/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCRECT2D_H__
#else                                                                            
#define __FCRECT2D_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCTran.h"

namespace FaceCat{
    /**
     * 矩形视图
     */
	class __FCRECT2D_H__ FCRect2D : public FCView{
	public:
		/*
		* 构造函数
		*/
		FCRect2D();
		/*
		* 析构函数
		*/
		virtual ~FCRect2D();
	public:	    
		/**
	     * 获取视图类型
	     */
		virtual String getViewType();
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
	};
}