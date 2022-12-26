/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCDIV_H__
#else                                                                            
#define __FCDIV_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCView.h"
#include "..\\scroll\\FCScrollBar.h"
#include "..\\scroll\\FCHScrollBar.h"
#include "..\\scroll\\FCVScrollBar.h"

namespace FaceCat{
	class FCHScrollBar;
	class FCVScrollBar;

	/*
	* 图层
	*/
	class __FCDIV_H__ FCDiv : public FCView, public FCEventCallBack, public FCKeyEventCallBack, public FCTouchEventCallBack{
	public:
	    /**
		 * 是否允许拖动滚动
		 */
		bool m_allowDragScroll;
		/**
		 * 横向滚动条
		 */
		FCHScrollBar *m_hScrollBar;
		/**
		 * 是否正在被拖动
		 */
		bool m_isDragScrolling;
		/**
		 * 是否正在滚动2
		 */
		bool m_isDragScrolling2;
		/*
		* 是否必须更新
		*/
		bool m_mustUpdate;
		/**
		 * 是否准备拖动滚动
		 */
		bool m_readyToDragScroll;
		/**
		 * 是否显示横向滚动条
		 */
		bool m_showHScrollBar;
		/**
		 * 是否显示纵向滚动条
		 */
		bool m_showVScrollBar;
		/**
		 * 开始移动的位置
		 */
		FCPoint m_startMovePoint;
		/**
		 * 开始移动的横向位置
		 */
		int m_startMovePosX;
		/**
		 * 开始移动的纵向位置
		 */
		int m_startMovePosY;
		/**
		 * 开始移动时间
		 */
		DWORD m_startMoveTime;
		/**
		 * 纵向滚动条
		 */
		FCVScrollBar *m_vScrollBar;
	public:
		/*
		* 构造函数
		*/
		FCDiv();
		/*
		* 析构函数
		*/
		virtual ~FCDiv();
		/**
		 * 获取是否允许拖动滚动
		 */
		virtual bool allowDragScroll();
		/**
		 * 设置是否允许拖动滚动
		 */
		virtual void setAllowDragScroll(bool value);
		/**
		 * 获取横向滚动条
		 */
		FCHScrollBar* getHScrollBar();
		/**
		 * 获取是否显示横向滚动条
		 */
		virtual bool showHScrollBar();
		/**
		 * 设置是否显示横向滚动条
		 */
		virtual void setShowHScrollBar(bool value);
		/**
		 * 获取是否正在被拖动
		 */
		virtual bool isDragScrolling();
		/**
		 * 获取是否显示纵向滚动条
		 */
		virtual bool showVScrollBar();
		/**
		 * 设置是否显示纵向滚动条
		 */
		virtual void setShowVScrollBar(bool value);
		/**
		 * 获取纵向滚动条
		 */
		virtual FCVScrollBar* getVScrollBar();
	public:
		/*
		* 触发事件
		*/
		virtual void callEvent(String eventName, Object sender, Object invoke);
		/*
		* 滚动按钮键盘按下事件
		*/
		virtual void callKeyEvent(String eventName, Object sender, char key, Object invoke);
		/*
		* 滚动按钮触摸滚动事件
		*/
		virtual void callTouchEvent(String eventName, Object sender, FCTouchInfo touchInfo, Object invoke);
		/**
		 * 清除所有视图
		 */
		virtual void clearChildViews();
	    /**
		 * 获取内容的高度
		 */
		virtual int getContentHeight();
		/**
		 * 获取内容的宽度
		 */
		virtual int getContentWidth();
		/**
		 * 获取视图类型
		 */
		virtual String getViewType();
		/**
		 * 获取显示偏移坐标
		 */
		virtual FCPoint getDisplayOffset();
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
		 * 向下滚动一行
		 */
		virtual void lineDown();
		/**
		 * 向左滚动一行
		 */
		virtual void lineLeft();
		/**
		 * 向右滚动一行
		 */
		virtual void lineRight();
		/**
		 * 向上滚动一行
		 */
		virtual void lineUp();
		/**
		* 拖动准备方法
		* @param  startOffset  可以拖动的偏移坐标量
		*/
		virtual void onDragReady(FCPoint *startOffset);
		/**
		 * 拖动滚动结束
		 */
		virtual void onDragScrollEnd();
		/**
		 * 拖动滚动中
		 */
		virtual void onDragScrolling();
		/**
		 * 拖动滚动许可检查
		 */
		virtual bool onDragScrollPermit();
		/**
		 * 拖动滚动开始
		 */
		virtual void onDragScrollStart();
		/**
		* 键盘按下方法
		* @param  key  按键
		*/
		virtual void onKeyDown(char key);
		/**
		* 触摸点击方法
		* @param  touchInfo   触摸信息
		*/
		virtual void onTouchDown(FCTouchInfo touchInfo);
		/**
		* 触摸移动方法
		* @param  touchInfo   触摸信息
		*/
		virtual void onTouchMove(FCTouchInfo touchInfo);
		/**
		* 触摸抬起方法
		* @param  touchInfo   触摸信息
		*/
		virtual void onTouchUp(FCTouchInfo touchInfo);
		/**
		* 触摸滚动方法
		* @param  touchInfo   触摸信息
		*/
		virtual void onTouchWheel(FCTouchInfo touchInfo);
		/**
		* 预处理触摸事件
		* @param  eventName   事件ID
		* @param  touchInfo   触摸信息
		*/
		virtual bool onPreviewsTouchEvent(String eventName, FCTouchInfo touchInfo);
		/**
		 * 向下翻一页
		 */
		virtual void pageDown();
		/**
		 * 向左翻一页
		 */
		virtual void pageLeft();
		/**
		 * 向右翻一页
		 */
		virtual void pageRight();
		/**
		 * 向上翻一页
		 */
		virtual void pageUp();
		/**
		* 设置属性值
		* @param  name   属性名称
		* @param  value   属性值
		*/
		virtual void setAttribute(const String& name, const String& value);
		/**
		 * 更新布局方法
		 */
		virtual void update();
		/**
		 * 更新滚动条的布局
		 */
		virtual void updateScrollBar();
	};
}
