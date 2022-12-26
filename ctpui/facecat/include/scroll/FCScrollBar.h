/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCSCROLLBAR_H__
#else                                                                            
#define __FCSCROLLBAR_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\btn\\FCButton.h"

namespace FaceCat{
	/*
	* 滚动条
	*/
	class __FCSCROLLBAR_H__ FCScrollBar:public FCView, public FCEventCallBack, public FCTouchEventCallBack{
	private:
        /**
		 * 秒表ID
		 */
		int m_timerID;
		/**
		 * 秒表计数
		 */
		int m_tick;
	public:
		FCButton *m_addButton;
		/**
		 * 当前的加速度
		 */
		int m_addSpeed;
		/**
		 * 滚动背景按钮
		 */
		FCButton *m_backButton;
		/**
		 * 内容尺寸
		 */
		int m_contentSize;
		/**
		 * 是否正在增量
		 */
		bool m_isAdding;
		/**
		 * 是否正在减量
		 */
		bool m_isReducing;
		/**
		 * 滚动的行尺寸
		 */
		int m_lineSize;
		/**
		 * 页的尺寸
		 */
		int m_pageSize;
		/**
		 * 滚动距离
		 */
		int m_pos;
		/**
		 * 减量按钮
		 */
		FCButton *m_reduceButton;
		/**
		 * 滚动按钮
		 */
		FCButton *m_scrollButton;
	public:
		/*
		* 构造函数
		*/
		FCScrollBar();
		/*
		* 析构函数
		*/
		virtual ~FCScrollBar();
		/**
		 * 增量按钮
		 */
		virtual FCButton* getAddButton();
		/**
		 * 获取当前的加速度
		 */
		virtual int getAddSpeed();
		/**
		 * 设置当前的加速度
		 */
		virtual void setAddSpeed(int value);
		/**
		 * 获取滚动背景按钮
		 */
		virtual FCButton* getBackButton();
		/**
		 * 获取内容尺寸
		 */
		virtual int getContentSize();
		/**
		 * 设置内容尺寸
		 */
		virtual void setContentSize(int value);
		/**
		 * 获取是否正在增量
		 */
		virtual bool isAdding();
		/**
		 * 设置是否正在增量
		 */
		virtual void setIsAdding(bool value);
		/**
		 * 获取是否正在减量
		 */
		virtual bool isReducing();
		/**
		 * 设置是否正在减量
		 */
		virtual void setIsReducing(bool value);
		/**
		 * 获取每次滚动的行尺寸
		 */
		virtual int getLineSize();
		/*
		* 设置每次滚动的行尺寸
		*/
		virtual void setLineSize(int value);
		/**
		 * 获取页的尺寸
		 */
		virtual int getPageSize();
		/**
		 * 设置页的尺寸
		 */
		virtual void setPageSize(int value);
		/**
		 * 获取滚动距离
		 */
		virtual int getPos();
		/**
		 * 设置滚动距离
		 */
		virtual void setPos(int value);
		/**
		 * 减量按钮
		 */
		virtual FCButton* getReduceButton();
		/**
		 * 获取滚动按钮
		 */
		virtual FCButton* getScrollButton();
	public:
		/*
		* 触发事件
		*/
		virtual void callEvent(String eventName, Object sender, Object invoke);
		/*
		* 调用键盘事件
		*/
		virtual void callTouchEvent(String eventName, Object sender, FCTouchInfo touchInfo, Object invoke);
		/**
         * 获取方法列表
         */
        virtual ArrayList<String> getEventNames();
	    /**
		 * 获取视图类型
		 */
		virtual String getViewType();
		/**
		 * 行变大方法
		 */
		virtual void lineAdd();
		/**
		 * 行变小方法
		 */
		virtual void lineReduce();
		/**
		* 增量滚动按钮按下事件方法
		* @params touchInfo  触摸信息
		*/
		virtual void onAddButtonTouchDown(FCTouchInfo touchInfo);
		/**
		 * 增量滚动按钮抬起事件方法
		 */
		virtual void onAddButtonTouchUp(FCTouchInfo touchInfo);
		/**
		 * 加速滚动结束
		 */
		virtual void onAddSpeedScrollEnd();
		/**
		 * 自动加速滚动开始
		 */
		virtual void onAddSpeedScrollStart(DWORD startTime, DWORD nowTime, int start, int end);
		/**
		 * 自动加速滚动中
		 */
		virtual int onAddSpeedScrolling();
		/**
		 * 拖动滚动方法
		 */
		virtual void onDragScroll();
		/**
		 * 视图添加方法
		 */
		virtual void onLoad();
		/**
		 * 减量滚动按钮按下事件方法
		 */
		virtual void onReduceButtonTouchDown(FCTouchInfo touchInfo);
		/**
		 * 减量滚动按钮抬起事件回调方法
		 */
		virtual void onReduceButtonTouchUp(FCTouchInfo touchInfo);
		/**
		 * 滚动方法
		 */
		virtual void onScrolled();
		/**
		 * 可见状态改变方法
		 */
		virtual void onVisibleChanged();
		/**
		 * 页变大方法
		 */
		virtual void pageAdd();
		/**
		 * 页变小方法
		 */
		virtual void pageReduce();
		/**
		 * 滚动到开始
		 */
		virtual void scrollToBegin();
		/**
		 * 滚动到结束
		 */
		virtual void scrollToEnd();
		/**
		 * 秒表回调方法
		 */
		virtual void onTimer(int timerID);
	};
}
