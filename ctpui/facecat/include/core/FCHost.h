/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCHOST_H__
#else                                                                            
#define __FCHOST_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCView.h"
#include "FCTran.h"
#include "FCPaint.h"
#include "GdiPaint.h"
#include "GdiPlusPaint.h"
#include "FCNative.h"

namespace FaceCat{
	class FCView;
	class FCNative;

    /**
     * 视图管理
     */
	class __FCHOST_H__ FCHost{
	public:
		/*
		* 构造函数
		*/
		FCHost();
		/*
		* 析构函数
		*/
		virtual ~FCHost();
		/**
		 * 获取方法库
		 */
		virtual FCNative* getNative();
		/**
		 * 设置方法库
		 */
		virtual void setNative(FCNative *value);
	public:
		/*
		* 激活镜像
		*/
		virtual void activeMirror();
		/**
		 * 是否允许操作
		 */
		virtual bool allowOperate();
		/**
		 * 是否允许局部绘图
		 */
		virtual bool allowPartialPaint();
		/**
		 * 在视图的线程中调用方法
		 */
		virtual void beginInvoke(FCView *view, Object args);
		/**
		 * 复制文本
		 */
		virtual void copy(string text);
		/**
		 * 创建内部视图
		 */
		virtual FCView* createInternalView(FCView *parent, const String& clsid);
		/*
		* 获取光标形状
		*/
        virtual FCCursors getCursor();
        /**
         * 获取矩形相交区
         *
         * @param lpDestRect    相交矩形
         * @param lpSrc1Rect    矩形1
         * @param lpSrc2Rect    矩形2
         * @returns 是否相交
         */
		virtual int getIntersectRect(LPRECT lpDestRect, const FCRect *lpSrc1Rect, const FCRect *lpSrc2Rect);
        /**
		 * 获取触摸位置
		 */
        virtual FCPoint getTouchPoint();
        /**
		 * 获取尺寸
		 */
        virtual FCSize getSize();
		/*
		* 获取矩形联合区
		*/
		virtual int getUnionRect(LPRECT lpDestRect, const FCRect *lpSrc1Rect, const FCRect *lpSrc2Rect);
		/**
		 * 刷新绘图
		 */
		virtual void invalidate();
	    /**
         *  刷新绘图
         * @param rect 区域
         */
        virtual void invalidate(const FCRect& rect);
        /**
         *  在视图的线程中调用方法
         * @param view 视图
         * @param args  参数
         */
		virtual void invoke(FCView *view, Object args);
		/*
		* 键盘是否被按下
		*/
		virtual bool isKeyPress(char key);
		/**
		 * 获取粘贴文本
		 */
		virtual string paste();
		/**
		 * 设置是否允许操作
		 */
		virtual void setAllowOperate(bool allowOperate);
		/**
		 * 设置是否允许局部绘图
		 */
		virtual void setAllowPartialPaint(bool allowPartialPaint);
		/*
		* 设置鼠标形状
		*/
        virtual void setCursor(FCCursors cursor);
        /**
         *  显示提示框
         * @param text  文字
         * @param mp    位置
         */
		virtual void showToolTip(const String& text, const FCPoint& mp);
		/*
		* 设置触摸位置
		*/
		virtual void setTouchPoint(const POINT& point);
	    /**
         *  开启秒表
         * @param timerID   秒表ID
         * @param interval  间隔
         */
        virtual void startTimer(int timerID, int interval);
        /**
         *  停止秒表
         * @param timerID   秒表ID
         */
        virtual void stopTimer(int timerID);
	};
}