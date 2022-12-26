/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCWINDOWFRAME_H__
#else                                                                            
#define __FCWINDOWFRAME_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCWindow.h"

namespace FaceCat
{
	/*
	* 窗体边界
	*/
	class __FCWINDOWFRAME_H__ FCWindowFrame : public FCView{
	public:
	    /**
		 * 窗体视图边界
		 */
		FCWindowFrame();
		/*
		* 析构函数
		*/
		virtual ~FCWindowFrame();
	public:
		/**
		* 是否包含坐标
		* @param  point  坐标
		*/
		virtual bool containsPoint(const FCPoint& point);
		/**
		 * 获取视图类型
		 */
		virtual String getViewType();
		/**
		 * 重绘方法
		 */
		virtual void invalidate();
		/**
		* 绘制背景方法
		* @param  paint 绘图对象
		* @param  clipRect   裁剪区域
		*/
		virtual void onPaintBackground(FCPaint *paint, const FCRect& clipRect);
	};
}