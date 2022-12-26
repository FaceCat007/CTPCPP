/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCWINDOW_H__
#else                                                                            
#define __FCWINDOW_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\btn\\FCButton.h"
#include "FCWindowFrame.h"

namespace FaceCat{
	class FCWindowFrame;

	/*
	* 关闭窗体事件
	*/
    class __FCWINDOW_H__ FCWindowClosingEventCallBack
    {
	public:
		FCWindowClosingEventCallBack(){}
		virtual ~FCWindowClosingEventCallBack(){}
		virtual void callWindowClosingEvent(String eventName, Object sender, bool *cancel, Object invoke){}
    };

	/*
	* 窗体
	*/
	class __FCWINDOW_H__ FCWindow : public FCView{
	public:
		int m_borderWidth;
		/**
		 * 是否可以调整尺寸
		 */
		bool m_canResize;
		/**
		 * 标题栏的高度
		 */
		int m_captionHeight;
		/**
		 * 窗体的
		 */
		FCWindowFrame *m_frame;
		/**
		 * 是否会话窗口
		 */
		bool m_isDialog;
		/**
         * 上次坐标
         */
        FCPoint m_oldLocation;
		/**
		 * 调整尺寸的点
		 */
		int m_resizePoint;
		/**
		 * 阴影的颜色
		 */
		Long m_shadowColor;
		/**
		 * 阴影的大小
		 */
		int m_shadowSize;
		/**
		 * 移动开始点
		 */
		FCPoint m_startTouchPoint;
		/**
		 * 移动开始时的视图矩形
		 */
		FCRect m_startRect;
		/**
		 * 是否使用框架
		 */
		bool m_useFrame;
	public:
		/**
		* 调用事件
		* @param  eventName  事件ID
		* @param  cancel   是否退出
		*/
		void callWindowClosingEvents(String eventName, bool *cancel);
		/**
		* 获取触摸状态
		* @param  state  状态值
		*/
		FCCursors getResizeCursor(int state);
		/**
		 * 获取调整尺寸的点
		 */
		ArrayList<FCRect> getResizePoints();
		/**
		 * 获取调整尺寸的状态
		 */
		int getResizeState();
	public:
		FCWindow();
		virtual ~FCWindow();
		/**
		 * 获取边框的宽度
		 */
		virtual int getBorderWidth();
		/**
		 * 设置边框的宽度
		 */
		virtual void setBorderWidth(int value);
		/**
		 * 获取标题栏的高度
		 */
		virtual int getCaptionHeight();
		/**
		 * 设置标题栏的高度
		 */
		virtual void setCaptionHeight(int value);
		/**
		 * 获取是否可以调整尺寸
		 */
		virtual bool canResize();
		/**
		 * 设置是否可以调整尺寸
		 */
		virtual void setCanResize(bool value);
		/**
		 * 获取窗体的
		 */
		virtual FCWindowFrame* getFrame();
		/**
		 * 设置窗体的
		 */
		virtual void setFrame(FCWindowFrame *value);
		/**
		 * 获取是否会话窗口
		 */
		virtual bool isDialog();
		/**
         * 设置控件的位置
         */
        virtual void setLocation(const FCPoint& value);
		/**
		 * 获取阴影的颜色
		 */
		virtual Long getShadowColor();
		/**
		 * 设置阴影的颜色
		 */
		virtual void setShadowColor(Long value);
		/**
		 * 获取阴影的大小
		 */
		virtual int getShadowSize();
		/**
		 * 设置阴影的大小
		 */
		virtual void setShadowSize(int value);
		/**
		 * 是否使用框架
		 */
		virtual bool useFrame();
		/**
		 * 是否使用框架
		 */
		virtual void setUseFrame(bool value);
	public:
	    /**
		 * 将视图放到最前显示
		 */
		virtual void bringToFront();
		/**
		 * 关闭窗体
		 */
		virtual void close();
		/**
		 * 获取视图类型
		 */
		virtual String getViewType();
		/**
		 * 获取动态绘图区域
		 */
		FCRect getDynamicPaintRect();
		/**
		* 获取属性值
		* @param  name   属性名称
		* @param  value   返回属性值
		* @param  type   返回属性类型
		*/
		virtual void getAttribute(const String& name, String *value, String *type);
		/**
		 * 获取属性列表
		 */
		virtual ArrayList<String> getAttributeNames();
		/**
         * 获取方法列表
         */
        virtual ArrayList<String> getEventNames();
		/**
		 * 滚动开始方法
		 */
		virtual bool onDragBegin();
		/**
		* 拖动准备方法
		* @param  startOffset  可以拖动的偏移坐标量
		*/
		virtual void onDragReady(FCPoint *startOffset);
		/**
		* 触摸按下方法
         * @param  touchInfo  触摸信息
		*/
		virtual void onTouchDown(FCTouchInfo touchInfo);
		/**
		* 触摸移动方法
         * @param  touchInfo  触摸信息
		*/
		virtual void onTouchMove(FCTouchInfo touchInfo);
		/**
		* 触摸抬起方法
         * @param  touchInfo  触摸信息
		*/
		virtual void onTouchUp(FCTouchInfo touchInfo);
		/**
		* 绘制前景方法
		* @param  paint   绘图对象
		* @param  clipRect  裁剪区域
		*/
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
		/**
		 * 可见状态改变方法
		 */
		virtual void onVisibleChanged();
		/**
		* 窗体正在关闭方法
		* @param  cancel  是否退出
		*/
		virtual void onWindowClosing(bool *cancel);
		/**
		 * 窗体关闭方法
		 */
		virtual void onWindowClosed();
		/**
		 * 将视图放到最下面显示
		 */
		virtual void sendToBack();
		/**
		* 设置属性值
		* @param  name   属性名称
		* @param  value   属性值
		*/
		virtual void setAttribute(const String& name, const String& value);
		/**
		 * 以会话方式显示
		 */
		virtual void showDialog();
		/*
         * 更新布局方法
         */
        virtual void update();
	};
}