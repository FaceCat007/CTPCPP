/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCNATIVE_H__
#else                                                                            
#define __FCNATIVE_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCView.h"
#include "FCTran.h"
#include "FCPaint.h"
#include "GdiPaint.h"
#include "GdiPlusPaint.h"
#include "FCHost.h"
#include "WinHost.h"

namespace FaceCat{
	enum _declspec(dllexport) SortType{
		SortType_None,
		SortType_Asc,
		SortType_Desc
	};

	class FCView;
	class FCHost;
	class WinHost;
	/*
	* 控制器
	*/
	class __FCNATIVE_H__ FCNative{
	public:
	    /**
		 * 是否允许使用缩放尺寸
		 */
		bool m_allowScaleSize;
		/*
		* 开始绘图的店
		*/
		FCPoint m_drawBeginPoint;
		/**
		 * 拖动开始时的区域
		 */
		FCRect m_dragBeginRect;
		/**
		 * 可以开始拖动的偏移坐标量
		 */
		FCPoint m_dragStartOffset;
		/*
		* 要导出图片的视图
		*/
		FCView *m_exportingView;
		/**
		 * 视图管理器
		 */
		FCHost *m_host;
		/*
		* 是否锁定更新
		*/
		bool m_lockUpdate;
		/*
		* 镜像宿主
		*/
		FCNative *m_mirrorHost;
		/*
		* 镜像模式
		*/
		FCMirrorMode m_mirrorMode;
		/**
		 * 透明度
		 */
		float m_opacity;
		/**
		 * 绘图类
		 */
		FCPaint *m_paint;
		/**
		 * 触摸按下时的坐标
		 */
		FCPoint m_touchDownPoint;
		/**
		 * 资源文件的路径
		 */
		String m_resourcePath;
		/**
		 * 旋转角度
		 */
		int m_rotateAngle;
		/**
		 * 使用缩放尺寸
		 */
		FCSize m_scaleSize;
		/**
		 * 显示区域
		 */
		FCSize m_size;
		/*
		* 秒表
		*/
		map<int, FCView*> m_timers;
	    /**
         * 根据触摸位置获取视图
         * @param mp    坐标
         * @param view 视图
         * @returns 视图对象
        */
		FCView* findView(const FCPoint& mp, ArrayList<FCView*> *views);
	    /**
         * 根据名称查找视图
         * @param name  名称
         * @param views  视图集合
         * @returns 视图
        */
		FCView* findView(const String& name, ArrayList<FCView*> *views);
	    /**
         * 根据视图查找预处理事件的视图
         * @param view   视图
         * @returns 视图
        */
		FCView* findPreviewsView(FCView *view);
	    /**
         * 根据视图查找窗体
         * @param view   视图
         * @returns 窗体
        */
		FCView* findWindow(FCView *view);
	    /**
         * 获取绘制的透明度
         * @param view   视图
         * @returns 透明度
        */
		float getPaintingOpacity(FCView *view);
	    /**
         * 获取排序后的视图集合
         * @param parent    父视图
         * @param sortedViews   排序后的视图
         * @returns 状态
        */
		bool getSortedViews(FCView *parent, ArrayList<FCView*> *sortedViews);
		/*
		* 获取允许Tab键的视图
		*/
		void getTabStopViews(FCView *view, ArrayList<FCView*> *tabStopViews);
	    /**
         * 判断是否绘制可用状态
         * @param view   视图
         * @returns 是否绘制可用状态
        */
		bool isPaintEnabled(FCView *view);
	    /**
         * 绘制视图
         * @param   rect 矩形
         * @param   views 视图集合
         * @param   opacity 透明度
        */
		void renderViews(const FCRect& rect, ArrayList<FCView*> *views, float opacity);
		 /**
         * 绘制视图
         * @param   rect 矩形
         * @param   views 视图集合
         * @param   opacity 透明度
        */
		void renderView(const FCRect& rect, FCView *views, float opacity);
		/*
		* 设置光标
		*/
		void setCursor(FCView *view);
	    /**
         * 设置绘图属性
         * @param offsetX  横向偏移
         * @param offsetY  纵向偏移
         * @param clipRect  裁剪区域
         * @param resourcePath  资源路径
         * @param opacity  透明度
        */
		void setPaint(int offsetX, int offsetY, const FCRect& clipRect, float opacity);
	public:
	    /**
		 * 正被拖动的视图
		 */
		FCView *m_draggingView;
		/*
		* 正被焦点的视图
		*/
		FCView *m_focusedView;
		/**
		 * 正被触摸按下的视图
		 */
		FCView *m_touchDownView;
		/**
		 * 触摸正在其上方移动的视图
		 */
		FCView *m_touchMoveView;
	public:
	    /**
		 * 视图
		 */
		ArrayList<FCView*> m_views;
		/*
		* 镜像
		*/
		vector<FCNative*> m_mirrors;
		/*
		* 构造函数
		*/
		FCNative();
		/*
		* 析构函数
		*/
		virtual ~FCNative();
		/**
		 * 获取是否允许使用缩放尺寸
		 */
		bool allowScaleSize();
		/**
		 * 设置是否允许使用缩放尺寸
		 */
		void setAllowScaleSize(bool value);
		/*
		* 获取鼠标的形状
		*/
		FCCursors getCursor();
		/*
		* 设置鼠标的形状
		*/
		void setCursor(FCCursors value);
		/**
		 * 获取选中的视图
		 */
		FCView* getFocusedView();
		/**
		 * 设置选中的视图
		 */
		void setFocusedView(FCView *value);
		/**
		 * 获取视图管理器
		 */
		FCHost* getHost();
		/**
		 * 设置视图管理器
		 */
		void setHost(FCHost *value);
		/**
		 * 获取触摸悬停的视图
		 */
		FCView* getHoveredView();
		/*
		* 获取镜像宿主
		*/
		FCNative* getMirrorHost();
		/*
		* 获取镜像模式
		*/
		FCMirrorMode getMirrorMode();
		/*
		* 设置镜像模式
		*/
		void setMirrorMode(FCMirrorMode value);
		/**
		 * 获取触摸的实际位置
		 */
		FCPoint getTouchPoint();
		/**
		 * 获取透明度
		 */
		float getOpacity();
		/**
		 * 设置透明度
		 */
		void setOpacity(float value);
		/**
		 * 获绘图类
		 */
		FCPaint* getPaint();
		/**
		 * 取绘图类
		 */
		void setPaint(FCPaint *value);
		/**
		 * 获取触摸按住的视图
		 */
		FCView* getPushedView();
		/**
		 * 获取资源文件的路径
		 */
		String getResourcePath();
		/**
		 * 设置资源文件的路径
		 */
		void setResourcePath(const String& value);
		/**
		 * 获取旋转角度
		 */
		int getRotateAngle();
		/**
		 * 设置旋转角度
		 */
		void setRotateAngle(int value);
		/**
		 * 获取使用缩放尺寸
		 */
		FCSize getScaleSize();
		/**
		 * 设置使用缩放尺寸
		 */
		void setScaleSize(FCSize value);
		/**
		 * 获取显示区域
		 */
		FCSize getSize();
		/**
		 * 设置显示区域
		 */
		void setSize(FCSize value);
	public:
	    /**
         * 添加视图
         * @param view 视图
        */
		void addView(FCView *view);
		/*
		* 添加镜像
		*/
		void addMirror(FCNative *mirrorHost, FCView *view);
	    /**
         * 将视图放到最前显示
         * @param view 视图
        */
		void bringToFront(FCView *view);
		/**
		 * 退出拖动
		 */
		void cancelDragging();
		/**
		 * 清除所有的视图
		 */
		void clearViews();
	    /**
         * 获取视图的绝对横坐标
         * @param view 视图
        */
		int clientX(FCView *view);
	    /**
         * 获取视图的绝对纵坐标
         * @param view 视图
         * @returns 坐标
        */
		int clientY(FCView *view);
		/*
         * 获取控件的绝对坐标
         */
        virtual FCPoint clientPoint(FCView *view);
	    /**
         * 是否包含视图
         * @param view 视图
         * @returns 是否包含
        */
		bool containsView(FCView *view);
		/*
		* 导出为图片
		*/
        void exportToImage(const String& exportPath);
		/*
		* 导出为图片
		*/
        void exportToImage(const String& exportPath, FCView *view);
        /**
         * 根据触摸位置获取视图
         * @param mp    坐标
        */
		FCView* findView(const FCPoint& mp);
	    /**
         * 根据坐标在视图中查找视图
         * @param mp    坐标
         * @param parent    父视图
         * @returns 视图
        */
		FCView* findView(const FCPoint& mp, FCView *parent);
	    /**
         * 根据名称查找视图
         * @param name  名称
         * @returns 视图
        */
		FCView* findView(const String& name);
		/**
		 * 获取视图集合的拷贝
		 */
		ArrayList<FCView*> getViews();
	    /**
         * 插入视图
         * @param index 索引
         * @param view   视图
         */
		void insertView(int index, FCView *view);
		/**
		 * 使用缓存绘制图象，不重新计算绘图结构
		 */
		void invalidate();
	    /**
         * 局部绘图
         * @param view   视图
         */
		void invalidate(FCView *view);
	    /**
         * 局部绘图
         * @param rect  区域
         */
		void invalidate(const FCRect& rect);
		/**
         * 文字输入
         */
		bool onChar(wchar_t key);
	    /**
         * 双击
         */
		void onDoubleClick(FCTouchInfo touchInfo);
		/**
         * 键盘按下
         */
		void onKeyDown(char key);
		/**
         * 键盘抬起
         */
		void onKeyUp(char key);
		/**
         * 触摸按下
         */
		void onTouchDown(FCTouchInfo touchInfo);
		/**
         * 触摸离开
         */
		void onTouchLeave(FCTouchInfo touchInfo);
	    /**
         * 触摸移动事件
         * @param   ouchInfo    触摸信息
        */
		void onTouchMove(FCTouchInfo touchInfo);
		/**
         * 触摸抬起
         */
		void onTouchUp(FCTouchInfo touchInfo);
		/**
         * 触摸滚动
         */
		void onTouchWheel(FCTouchInfo touchInfo);
	    /**
         * 绘图方法
         * @param clipRect  矩形区域
        */
		void onPaint(const FCRect& rect);
		/*
		* 按键预处理
		*/
		bool onPreviewsKeyEvent(String eventName, char key);
		/*
		* 触摸预处理
		*/
		bool onPreviewsTouchEvent(String eventName, FCView *view, FCTouchInfo touchInfo);
		/**
		 * 处理尺寸改变
		 */
		void onResize();
		/*
		* 处理缩放
		*/
		virtual void onScaling(double scaleFactorX, double scaleFactorY);
	    /**
         * 处理秒表
         * @param   timerID 秒表ID
        */
		void onTimer(int timerID);
		/**
		 * 移除视图
		 */
		void removeView(FCView *view);
		/*
		* 移除镜像
		*/
		void removeMirror(FCView *view);
		/**
		 * 将视图放到最下面显示
		 */
		void sendToBack(FCView *view);
		/**
		 * 设置排列
		 */
		void setAlign(ArrayList<FCView*> *views);
		/*
		* 设置锚定信息
		*/
		void setAnchor(ArrayList<FCView*> *views, FCSize oldSize);
		/*
		* 设置绑定边缘
		*/
		void setDock(ArrayList<FCView*> *views);
	    /**
         * 启动秒表
         * @param view  视图
         * @param timerID  秒表编号
         * @param interval 间隔
        */
		void startTimer(FCView *view, int timerID, int interval);
		/**
		 * 停止秒表
		 */
		void stopTimer(int timerID);
		/**
		 * 更新布局
		 */
		void update();
	public:
        static void addChangeID();
        static int getChangeID();

	};
}