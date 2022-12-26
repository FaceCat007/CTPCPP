/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __WINHOST_H__
#else                                                                            
#define __WINHOST_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCView.h"
#include "FCTran.h"
#include "FCPaint.h"
#include "GdiPaint.h"
#include "GdiPlusPaint.h"
#include "FCNative.h"
#include "FCHost.h"

namespace FaceCat{
	class FCView;
	class FCNative;

	/*
	* Windows设备类
	*/
	class __WINHOST_H__ WinHost : public FCHost{
	public:
		CRITICAL_SECTION _csLock;
		/**
		 * 是否可以操作
		 */
		bool m_allowOperate;
		/**
		 * 是否支持局部绘图
		 */
		bool m_allowPartialPaint;
		/*
		* 输入法句柄
		*/
		HIMC m_hImc;
		/**
		 * 图形视图
		 */
		HWND m_hWnd;
		/**
		 * 调用视图线程方法的流水号
		 */
		int m_invokeSerialID;
		/**
		 * 调用视图线程方法的参数
		 */
		map<int, Object> m_invokeArgs;
		/**
		 * 调用视图线程方法的视图
		 */
		map<int, FCView*> m_invokeViews;
		/**
		 * 方法库
		 */
		FCNative *m_native;
		/**
		 * 调用线程方法的消息ID
		 */
		int m_pInvokeMsgID;
		/**
		 * 提示框
		 */
		FCView *m_toolTip;
		/*
		* 触摸位置
		*/
		FCPoint m_touchPoint;
	public:
	    /**
		 * 获取客户端的大小
		 */
		FCSize getClientSize();
	public:
	    /**
		 * 窗体视图管理
		 */
		WinHost();
		virtual ~WinHost();
		/**
		 * 获取窗体视图管理
		 */
		HWND getHWnd();
		/**
		 * 设置窗体视图管理
		 */
		void setHWnd(HWND hWnd);
		/*
		* 获取控制器
		*/
		virtual FCNative* getNative();
		/*
		* 设置控制器
		*/
		virtual void setNative(FCNative *value);
		/*
		* 获取Invoke的消息号
		*/
		int getPInvokeMsgID();
		/*
		* 设置Invoke的消息号
		*/
		void setPInvokeMsgID(int value);
		/*
		* 获取提示框
		*/
		FCView* getToolTip();
		/*
		* 设置提示框
		*/
		void setToolTip(FCView *value);
	public:
	    /**
		 * 激活镜像
		 */
		virtual void activeMirror();
		/**
		 * 获取或设置是否允许操作
		 */
		virtual bool allowOperate();
		/**
		 * 获取或设置是否允许局部绘图
		 */
		virtual bool allowPartialPaint();
		/**
		*在视图的线程中调用方法
		* @param view 视图
		* @param args 参数
		*/
		virtual void beginInvoke(FCView *view, Object args);
		/**
		 * 复制文本
		 */
		virtual void copy(string text);
		/**
		*创建内部视图
		* @param parent 父视图
		* @param clsid 类型ID
		*/
		virtual FCView* createInternalView(FCView *parent, const String& clsid);
		/**
		 * 获取程序的路径
		 */
		static string getAppPath();
		/**
		 * 取光标获
		 */
		virtual FCCursors getCursor();
		/**
		*获取矩形相交区
		* @param lpDestRect 相交矩形
		* @param lpSrc1Rect 矩形1
		* @param lpSrc2Rect 矩形2
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
		/**
		*获取矩形并集区
		* @param lpDestRect 并集矩形
		* @param lpSrc1Rect 矩形1
		* @param lpSrc2Rect 矩形2
		*/
		virtual int getUnionRect(LPRECT lpDestRect, const FCRect *lpSrc1Rect, const FCRect *lpSrc2Rect);
		/*
		* 锁
		*/
		void lock();
		/**
		 * 刷新绘图
		 */
		virtual void invalidate();
		/**
		* 刷新绘图
		* @param rect  区域
		*/
        virtual void invalidate(const FCRect& rect);
		/**
		* 在视图的线程中调用方法
		* @param view   视图
		* @param args      参数
		*/
		virtual void invoke(FCView *view, Object args);
		/**
		* 获取按键的状态
		* @param key   按键
		*/
		virtual bool isKeyPress(char key);
		/**
		* 调用视图线程的方法
		* @param invokeSerialID   消息ID
		*/
		void onInvoke(int invokeSerialID);
		/**
		* 消息处理
		* @param m  消息
		*/
		int onMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
		/**
		* 重绘方法
		* @param clipRect  裁剪区域
		*/
		void onPaint(HDC hDC, const FCRect& rect);
		/**
		 * 获取粘贴文本
		 */
		virtual string paste();
		/*
		* 设置是否允许操作
		*/
		virtual void setAllowOperate(bool allowOperate);
		/*
		* 设置是否允许局部绘图
		*/
		virtual void setAllowPartialPaint(bool allowPartialPaint);
		/**
		* 设置光标
		* @param cursor  光标
		*/
        virtual void setCursor(FCCursors cursor);
		/**
		* 显示提示框
		* @param text  文字
		* @param mp  位置
		*/
		virtual void showToolTip(const String& text, const FCPoint& mp);
		/*
		* 设置触摸位置
		*/
		virtual void setTouchPoint(const POINT& point);
		/**
		* 开启秒表
		* @param timerID  秒表ID
		* @param interval  间隔
		*/
        virtual void startTimer(int timerID, int interval);
		/**
		* 停止秒表
		* @param timerID  秒表ID
		*/
        virtual void stopTimer(int timerID);
		/*
		* 解锁
		*/
		void unLock();
	};
}