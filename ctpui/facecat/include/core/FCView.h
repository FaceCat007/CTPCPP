/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */
#ifdef __FCVIEW_H__
#else                                                                            
#define __FCVIEW_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCNative.h"
#include "FCPaint.h"
#include "FCTran.h"
#include "FCAttribute.h"
#include "FCHost.h"

namespace FaceCat{
	static int timerID = 0;
	class FCNative;
	class FCView;

	/*
	* 视图事件
	*/
    class __FCVIEW_H__ FCEventCallBack{
	public:
		FCEventCallBack(){}
		virtual ~FCEventCallBack(){}
		virtual void callEvent(String eventName, Object sender, Object invoke){}
    };

    /*
	* 在线程中调用方法事件
	*/
    class __FCVIEW_H__ FCInvokeEventCallBack {
	public:
		FCInvokeEventCallBack(){}
		virtual ~FCInvokeEventCallBack(){}
        virtual void callInvokeEvent(String eventName, Object sender, Object args, Object invoke){}
    };

    /*
	* 键盘事件
	*/
    class __FCVIEW_H__ FCKeyEventCallBack {
	public:
		FCKeyEventCallBack(){}
		virtual ~FCKeyEventCallBack(){}
        virtual void callKeyEvent(String eventName, Object sender, char key, Object invoke){}
    };
    
    /*
	* 预键盘事件
	*/
    class __FCVIEW_H__ FCPreviewsKeyEventCallBack {
	public:
		FCPreviewsKeyEventCallBack(){}
		virtual ~FCPreviewsKeyEventCallBack(){}
        virtual bool callPreviewsKeyEvent(String eventName, String tEventID, Object sender, char key, Object invoke){return false;}
    };

    /*
	* 视图触摸事件
	*/
    class __FCVIEW_H__ FCTouchEventCallBack {
	public:
		FCTouchEventCallBack(){}
		virtual ~FCTouchEventCallBack(){}
        virtual void callTouchEvent(String eventName, Object sender, FCTouchInfo touchInfo, Object invoke){}
    };

    /*
	* 视图预触摸事件
	*/ 
    class __FCVIEW_H__ FCPreviewsTouchEventCallBack {
	public:
		FCPreviewsTouchEventCallBack(){}
		virtual ~FCPreviewsTouchEventCallBack(){}
        virtual bool callPreviewsTouchEvent(String eventName, String tEventID, Object sender, FCTouchInfo touchInfo, Object invoke){return false;}
    };

    /*
	* 视图重绘事件
	*/
    class __FCVIEW_H__ FCPaintEventCallBack {
	public:
		FCPaintEventCallBack(){}
		virtual ~FCPaintEventCallBack(){}
        virtual bool callPaintEvent(String eventName, Object sender, FCPaint *paint, const FCRect& clipRect, Object invoke){return false;}
    };

	/*
	* 秒表事件
	*/
	class __FCVIEW_H__ FCTimerEventCallBack{
	public:
		FCTimerEventCallBack(){}
		virtual ~FCTimerEventCallBack(){}
		virtual void callTimerEvent(String eventName, Object sender, int timerID, Object invoke){}
	};

	#define FCEventID_Add L"onadd";
    #define FCEventID_AutoSizeChanged L"onautosizechanged"
    #define FCEventID_BackColorChanged L"onbackcolorchanged" 
    #define FCEventID_BackImageChanged L"onbackimagechanged" 
    #define FCEventID_Char L"onchar" 
    #define FCEventID_Click L"onclick" 
    #define FCEventID_Copy L"oncopy" 
    #define FCEventID_Cut L"oncut" 
    #define FCEventID_DockChanged L"ondockchanged" 
    #define FCEventID_DoubleClick L"ondoubleclick" 
    #define FCEventID_DragBegin L"ondragbegin" 
    #define FCEventID_DragEnd L"ondragend" 
    #define FCEventID_Dragging L"ondragging" 
    #define FCEventID_EnableChanged L"onenablechanged" 
    #define FCEventID_FontChanged L"onfontchanged" 
    #define FCEventID_TextColorChanged L"ontextcolorchanged" 
    #define FCEventID_GotFocus L"ongotfocus" 
    #define FCEventID_Invoke L"oninvoke" 
    #define FCEventID_KeyDown L"onkeydown" 
    #define FCEventID_KeyUp L"onkeyup" 
    #define FCEventID_Load L"onload" 
    #define FCEventID_LocationChanged L"onlocationchanged" 
    #define FCEventID_LostFocus L"onlostfocus" 
    #define FCEventID_MarginChanged L"onmarginchanged" 
    #define FCEventID_TouchDown L"ontouchdown" 
    #define FCEventID_TouchEnter L"ontouchenter" 
    #define FCEventID_TouchLeave L"ontouchleave" 
    #define FCEventID_TouchMove L"ontouchmove" 
    #define FCEventID_TouchUp L"ontouchup" 
    #define FCEventID_TouchWheel L"ontouchwheel" 
    #define FCEventID_PaddingChanged L"onpaddingchanged" 
    #define FCEventID_ParentChanged L"onparentchanged" 
    #define FCEventID_Paint L"onpaint" 
    #define FCEventID_PaintBorder L"onpaintborder" 
    #define FCEventID_Paste L"onpaste" 
    #define FCEventID_RegionChanged L"onregionchanged" 
    #define FCEventID_Remove L"onremove" 
    #define FCEventID_SizeChanged L"onsizechanged" 
    #define FCEventID_TabStop L"ontabstop" 
    #define FCEventID_TabStopChanged L"ontabstopchanged" 
    #define FCEventID_TextChanged L"ontextchanged" 
    #define FCEventID_Timer L"ontimer" 
    #define FCEventID_VisibleChanged L"onvisiblechanged" 
    #define FCEventID_CheckedChanged L"oncheckedchanged" 
    #define FCEventID_SelectedTimeChanged L"onselectedtimechanged" 
    #define FCEventID_GridCellClick L"ongridcellclick" 
    #define FCEventID_GridCellEditBegin L"ongridcelleditbegin" 
    #define FCEventID_GridCellEditEnd L"ongridcelleditend" 
    #define FCEventID_GridCellTouchDown L"ongridcelltouchdown" 
    #define FCEventID_GridCellTouchEnter L"ongridcelltouchenter" 
    #define FCEventID_GridCellTouchLeave L"ongridcelltouchleave" 
    #define FCEventID_GridCellTouchMove L"ongridcelltouchmove" 
    #define FCEventID_GridCellTouchUp L"ongridcelltouchup" 
	#define FCEventID_GridRowDraged L"ongridrowdraged"
    #define FCEventID_GridSelectedCellsChanged L"ongridselectedcellschanged" 
    #define FCEventID_GridSelectedColumnsChanged L"ongridselectedcolumnschanged" 
    #define FCEventID_GridSelectedRowsChanged L"ongridselectedrowschanged" 
    #define FCEventID_MenuItemClick L"onmenuitemclick" 
    #define FCEventID_SelectedIndexChanged L"onselectedindexchanged" 
    #define FCEventID_SelectedTabPageChanged L"onselectedtabpagechanged" 
    #define FCEventID_Scrolled L"onscrolled" 
    #define FCEventID_ValueChanged L"onvaluechanged" 
    #define FCEventID_WindowClosed L"onwindowclosed" 
    #define FCEventID_WindowClosing L"onwindowclosing" 
    #define FCEventID_PreviewsKeyEvent L"onpreviewskeyevent" 
    #define FCEventID_PreviewsTouchEvent L"onpreviewstouchevent" 

	class __FCVIEW_H__ FCAtrEx{
    public:
        FCAtrEx();
        virtual ~FCAtrEx();
    public:
        /**
         * 锚定信息
         */
        FCAnchor m_anchor;
        /**
         * 外边距
         */
        FCPadding m_margin;
        /**
         * 控件的最大尺寸
         */
        FCSize m_maximumSize;
        /**
         * 控件的最小尺寸
         */
        FCSize m_minimumSize;
        /**
         * 百分比位置
         */
        FCPointF *m_percentLocation;
        /**
         * 百分比尺寸
         */
        FCSizeF *m_percentSize;
        /*
         * 区域
         */
        FCRect m_region;
        /**
         * 是否设置裁剪
         */
        bool m_useRegion;
        /**
         * 事件集合
         */
        map<String, vector<Object>*> m_events;
        /*
         * 调用者集合
         */
        map<String, vector<Object>*> m_invokes;
        /**
         * 内边距
         */
        FCPadding m_padding;
		 /**
         * 是否可以拖动位置
         */
        bool m_allowDrag;
        /**
         * 是否允许预处理事件
         */
        bool m_allowPreviewsEvent;
        /**
         * 是否在文字超出范围时在结尾显示省略号
         */
        bool m_autoEllipsis;
        /**
         * 是否自动调整尺寸
         */
        bool m_autoSize;
        /**
         * 圆角角度
         */
        int m_cornerRadius;
        /*
         * 鼠标形状
         */
        FCCursors m_cursor;
        /**
         * 是否允许偏移显示
         */
        bool m_displayOffset;
        /**
         * 或设置是否正被拖动
         */
        bool m_isDragging;
        /**
         * 是否为窗体
         */
        bool m_isWindow;
        /*
         * Tab索引
         */
        int m_tabIndex;
        /*
         * 是否支持Tab
         */
        bool m_tabStop;
        /**
         * TAG值
         */
        Object m_tag;
        /**
         * 背景图片
         */
        String m_backImage;
        /**
         * 绑定边缘类型
         */
        FCDockStyle m_dock;
		/*
         * 是否允许获得焦点
         */
        bool m_canFocus;
    };

	/*
	* 视图的基类
	*/
	class __FCVIEW_H__ FCView : public FCAttribute{
	public:
		FCAtrEx *m_atrEx;
	    /**
		 * 横向排列方式
		 */
		FCHorizontalAlign m_align;
		/**
		 * 背景色
		 */
		Long m_backColor;
		/**
		 * 边线的颜色
		 */
		Long m_borderColor;
		/**
		 * 视图是否可用
		 */
		bool m_enabled;
		/**
		 * 字体
		 */
		FCFont *m_font;
		/**
		 * 视图的位置
		 */
		FCPoint m_location;
		/**
		 * 视图的唯一标识名称
		 */
		String m_name;
		/**
		 * 按钮所在的图形接口
		 */
		FCNative *m_native;
		/**
		 * 上次尺寸
		 */
		FCSize m_oldSize;
		/**
		 * 透明度
		 */
		float m_opacity;
		/**
		 * 父视图
		 */
		FCView *m_parent;
		/**
		 * 尺寸
		 */
		FCSize m_size;
		/**
		 * 文字
		 */
		String m_text;
		/**
		 * 前景色
		 */
		Long m_textColor;
		/**
		 * 是否置顶显示
		 */
		bool m_topMost;
		/**
		 * 纵向排列方式
		 */
		FCVerticalAlign m_verticalAlign;
		/**
		 * 视图是否可见
		 */
		bool m_visible;
	public:
	    /**
         * 调用事件
         * @param eventName  事件ID
        */
		void callEvents(String eventName);
	    /**
         * 调用视图线程方法事件
         * @param eventName  事件ID
         * @param args     参数
        */
		void callInvokeEvents(String eventName, Object args);
		void callKeyEvents(String eventName, char key);
	    /**
         * 调用键盘事件
         * @param eventName  事件ID
         * @param key      按键
        */
		void callTouchEvents(String eventName, FCTouchInfo touchInfo);
	    /**
         * 调用重绘事件
         * @param eventName  事件ID
         * @param paint    绘图对象
         * @param clipRect 裁剪区域
        */
		bool callPaintEvents(String eventName, FCPaint *paint, const FCRect& clipRect);
		/*
		* 调用预键盘事件
		*/
		bool callPreviewsKeyEvent(String eventName, String tEventID, char key);
	    /**
         * 调用重绘事件
         * @param eventName  事件ID
         * @param tEventID 事件ID2
         * @param touchInfo   触摸信息
        */
		bool callPreviewsTouchEvent(String eventName, String tEventID, FCTouchInfo touchInfo);
	    /**
         * 调用秒表事件
         * @param eventName  事件ID
         * @param timerID  秒表编号
        */
		void callTimerEvents(String eventName, int timerID);
	    /**
         * 获取或设置的背景色
         * @returns 背景色
        */
        virtual Long getPaintingBackColor();
        /**
         * 获取要绘制的背景图片
         * @returns 背景图片
        */
        virtual String getPaintingBackImage();
        /**
         * 获取要绘制的边线颜色
         * @returns 边线颜色
        */
        virtual Long getPaintingBorderColor();
        /**
         * 获取要绘制的前景色
         * @returns 前景色
        */
        virtual Long getPaintingTextColor();
	public:
		/*
		* 所有视图
		*/
		ArrayList<FCView*> m_views;
		/*
		* 构造函数
		*/
		FCView();
		/*
		* 析构函数
		*/
		virtual ~FCView();
		/**
		 * 获取横向排列方式
		 */
		virtual FCHorizontalAlign getAlign();
		/**
		 * 设置横向排列方式
		 */
		virtual void setAlign(FCHorizontalAlign value);
		/**
		 * 获取是否可以拖动位置
		 */
		virtual bool allowDrag();
		/**
		 * 设置是否可以拖动位置
		 */
		virtual void setAllowDrag(bool value);
		/**
		 * 获取是否允许预处理事件
		 */
		virtual bool allowPreviewsEvent();
		/**
		 * 设置是否允许预处理事件
		 */
		virtual void setAllowPreviewsEvent(bool value);
		/**
		 * 获取锚定信息
		 */
		virtual FCAnchor getAnchor();
		/**
		 * 设置锚定信息
		 */
		virtual void setAnchor(const FCAnchor& value);
		/**
		 * 获取是否在文字超出范围时在结尾显示省略号
		 */
		virtual bool autoEllipsis();
		/**
		 * 设置是否在文字超出范围时在结尾显示省略号
		 */
		virtual void setAutoEllipsis(bool value);
		/**
		 * 获取是否自动调整尺寸
		 */
		virtual bool autoSize();
		/**
		 * 设置是否自动调整尺寸
		 */
		virtual void setAutoSize(bool value);
		/**
		 * 获取背景色
		 */
		virtual Long getBackColor();
		/**
		 * 设置背景色
		 */
		virtual void setBackColor(Long value);
		/**
		 * 获取背景图片
		 */
		virtual String getBackImage();
		/**
		 * 设置背景图片
		 */
		virtual void setBackImage(const String& value);
		/**
		 * 获取边线的颜色
		 */
		virtual Long getBorderColor();
		/**
		 * 设置边线的颜色
		 */
		virtual void setBorderColor(Long value);
		/**
		 * 获取距离下侧的位置
		 */
		virtual int getBottom();
		/**
		 * 获取视图的区域属性
		 */
		virtual FCRect getBounds();
		/**
		 * 设置视图的区域属性
		 */
		virtual void setBounds(const FCRect& value);
		/**
         * 设置控件的区域属性
         */
        virtual void setBounds2(const FCRect& value);
		/*
         * 获取是否获得焦点
         */
        virtual bool canFocus();
        /*
         * 设置是否允许获得焦点
         */
        virtual void setCanFocus(bool value);
		/**
		 * 获取是否被触摸捕获
		 */
		virtual bool isCapture();
		/**
		 * 获取圆角角度
		 */
		virtual int getCornerRadius();
		/**
		 * 设置圆角角度
		 */
		virtual void setCornerRadius(int value);
		/*
		* 获取鼠标形状
		*/
		virtual FCCursors getCursor();
		/*
		* 设置鼠标形状
		*/
		virtual void setCursor(FCCursors value);
		/**
		 * 获取是否允许偏移显示
		 */
		virtual bool displayOffset();
		/**
		 * 设置是否允许偏移显示
		 */
		virtual void setDisplayOffset(bool value);
		/**
		 * 获取虚拟显示的区域
		 */
		virtual FCRect getDisplayRect();
		/**
		 * 获取绑定边缘类型
		 */
		virtual FCDockStyle getDock();
		/**
		 * 设置绑定边缘类型
		 */
		virtual void setDock(FCDockStyle value);
		/**
		 * 获取视图是否可用
		 */
		virtual bool isEnabled();
		/**
		 * 设置视图是否可用
		 */
		virtual void setEnabled(bool value);
		/**
		 * 获取是否具有焦点
		 */
		virtual bool isFocused();
		/**
		 * 设置是否具有焦点
		 */
		virtual void setFocused(bool value);
		/**
		 * 获取字体
		 */
		virtual FCFont* getFont();
		/**
		 * 设置字体
		 */
		virtual void setFont(FCFont *value);
		/**
		 * 获取视图的高度
		 */
		virtual int getHeight();
		/**
		 * 设置视图的高度
		 */
		virtual void setHeight(int value);
		/**
		 * 获取或设置是否正被拖动
		 */
		virtual bool isDragging();
		/**
		 * 获取是否为窗体
		 */
		virtual bool isWindow();
		/**
		 * 设置是否为窗体
		 */
		virtual void setWindow(bool value);
		/**
		 * 获取距离左侧的位置
		 */
		virtual int getLeft();
		/**
		 * 设置距离左侧的位置
		 */
		virtual void setLeft(int value);
		/**
		 * 获取视图的位置
		 */
		virtual FCPoint getLocation();
		/**
		 * 设置视图的位置
		 */
		virtual void setLocation(const FCPoint& value);
		/**
		 * 获取外边距
		 */
		virtual FCPadding getMargin();
		/**
		 * 设置外边距
		 */
		virtual void setMargin(const FCPadding& value);
		/**
		 * 获取视图的最大尺寸
		 */
		virtual FCSize getMaximumSize();
		/**
		 * 设置视图的最大尺寸
		 */
		virtual void setMaximumSize(FCSize value);
		/**
		 * 获取视图的最小尺寸
		 */
		virtual FCSize getMinimumSize();
		/**
		 * 设置视图的最小尺寸
		 */
		virtual void setMinimumSize(FCSize value);
		/*
		* 获取触摸的点
		*/
		virtual FCPoint getTouchPoint();
		/*
		* 获取名称
		*/
		virtual String getName();
		/*
		* 设置名称
		*/
		virtual void setName(const String& value);
		/**
		 * 获取控制器
		 */
		virtual FCNative* getNative();
		/*
		* 设置控制器
		*/
		void setNative(FCNative *value);
		/**
		 * 获取透明度
		 */
		virtual float getOpacity();
		/**
		 * 设置透明度
		 */
		virtual void setOpacity(float value);
		/**
		 * 获取内边距
		 */
		virtual FCPadding getPadding();
		/**
		 * 设置内边距
		 */
		virtual void setPadding(const FCPadding& value);
		/**
		 * 获取父视图
		 */
		virtual FCView* getParent();
		/**
		 * 设置父视图
		 */
		virtual void setParent(FCView *value);
		/**
		 * 获取裁剪矩形
		 */
		virtual FCRect getRegion();
		/**
		 * 设置裁剪矩形
		 */
		virtual void setRegion(const FCRect& value);
		/**
		 * 获取距离右侧的距离
		 */
		virtual int getRight();
		/**
		 * 获取尺寸
		 */
		virtual FCSize getSize();
		/**
		 * 设置尺寸
		 */
		virtual void setSize(const FCSize& value);
		/*
		* 获取Tab索引
		*/
		virtual int getTabIndex();
		/*
		* 设置Tab索引
		*/
		virtual void setTabIndex(int value);
		/*
		* 是否支持Tab键
		*/
		virtual bool isTabStop();
		/*
		* 设置是否支持Tab键
		*/
		virtual void setTabStop(bool value);
		/**
		 * 获取TAG值
		 */
		virtual Object getTag();
		/**
		 * 设置TAG值
		 */
		virtual void setTag(Object value);
		/**
		 * 获取文字
		 */
		virtual String getText();
		/**
		 * 设置文字
		 */
		virtual void setText(const String& value);
		/**
		 * 获取前景色
		 */
		virtual Long getTextColor();
		/**
		 * 设置前景色
		 */
		virtual void setTextColor(Long value);
		/**
		 * 获取距离上侧的位置
		 */
		virtual int getTop();
		/**
		 * 设置距离上侧的位置
		 */
		virtual void setTop(int value);
		/**
		 * 获取是否置顶显示
		 */
		virtual bool isTopMost();
		/**
		 * 获取是否置顶显示
		 */
		virtual void setTopMost(bool value);
		/**
		 * 获取或设置是否设置裁剪
		 */
		virtual bool useRegion();
		/**
		 * 获取纵向排列方式
		 */
		virtual FCVerticalAlign getVerticalAlign();
		/**
		 * 设置纵向排列方式
		 */
		virtual void setVerticalAlign(FCVerticalAlign value);
		/**
		 * 获取视图是否可见
		 */
		virtual bool isVisible();
		/**
		 * 设置视图是否可见
		 */
		virtual void setVisible(bool value);
		/**
		 * 获取视图的宽度
		 */
		virtual int getWidth();
		/**
		 * 设置视图的宽度
		 */
		virtual void setWidth(int value);
	public:
	    /**
         * 添加视图
         * @param view  视图
        */
		virtual void addView(FCView *view);
		 /**
         * 在视图线程中调用方法
         * @param args  参数
        */
		virtual void addEvent(Object func, const String& eventName, Object pInvoke);
	    /**
         * 在视图线程中调用方法
         * @param args  参数
        */
		virtual void beginInvoke(Object args);
	    /**
         * 将子视图置于最前
         * @param childView  子视图
        */
		virtual void bringChildToFront(FCView *childView);
		/**
		 * 将视图放到最前显示
		 */
		virtual void bringToFront();
		/**
		 * 清除所有视图
		 */
		virtual void clearViews();
	    /**
         * 是否包含视图
         * @param view   视图
         * @returns  是否包含
        */
		virtual bool containsView(FCView *view);
	    /**
         * 是否包含视图
         * @param point   坐标
         * @returns  是否包含
        */
		virtual bool containsPoint(const FCPoint& mp);
		/**
		 * 设置焦点
		 */
		virtual void focus();
	    /**
         * 获取视图集合的拷贝
         * @returns 视图集合
        */
		virtual ArrayList<FCView*> getViews();
	    /**
         * 获取视图类型
         * @returns 视图类型
        */
		virtual String getViewType();
	    /**
         * 获取显示偏移坐标
         * @returns 坐标
        */
		virtual FCPoint getDisplayOffset();
	    /**
         * 获取新的秒表编号
         * @returns 新编号
        */
		static int getNewTimerID();
		/**
         * 获取属性值
		 */
		virtual String getAttribute(const String& name);
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
         * 获取方法列表
         */
        virtual ArrayList<String> getEventNames();
	    /**
         * 判断是否包含子视图
         * @returns  是否包含子视图
        */
		virtual bool hasChildren();
		/**
		 * 隐藏视图
		 */
		virtual void hide();
	    /**
         * 插入视图
         * @param index  索引
         * @param view  视图
        */
		virtual void insertView(int index, FCView *view);
		/**
		 * 启动绘制
		 */
		virtual void invalidate();
	    /**
         * 在视图线程中调用方法
         * @param args  参数
        */
		virtual void invoke(Object args);
	    /**
         * 判断是否绘制可用状态
         * @param view   视图
         * @returns  是否绘制可用状态
        */
		bool isPaintEnabled(FCView *view);
	    /**
         * 判断是否绘图时可见
         * @param view   视图
         * @returns  是否可见
        */
		bool isPaintVisible(FCView *view);
		/**
		 * 添加视图方法
		 */
		virtual void onAdd();
		/**
		 * 自动设置尺寸属性改变方法
		 */
		virtual void onAutoSizeChanged();
		/*
		* 背景色变化方法
		*/
		virtual void onBackColorChanged();
		/**
		 * 背景色改变方法
		 */
		virtual void onBackImageChanged();
		/*
		* 输入方法
		*/
		virtual void onChar(wchar_t ch);
		/**
		 * 字符输入
		 */
		virtual void onClick(FCTouchInfo touchInfo);
		/**
		 * 复制
		 */
		virtual void onCopy();
		/**
		 * 剪切
		 */
		virtual void onCut();
		/**
		 * 悬停改变方法
		 */
		virtual void onDockChanged();
	    /**
         * 触摸双击方法
         * @param touchInfo  触摸信息
        */
		virtual void onDoubleClick(FCTouchInfo touchInfo);
	    /**
         *  拖动开始方法
         * @returns  是否拖动
        */
		virtual bool onDragBegin();
		/**
		 * 拖动结束方法
		 */
		virtual void onDragEnd();
		/**
		 * 正在拖动方法
		 */
		virtual void onDragging();
		/*
         * 文件拖入方法
         */
        virtual void onDragInFiles(ArrayList<String> *files);
	    /**
         * 拖动准备方法
         * @param startOffset  可以拖动的偏移坐标量
        */
		virtual void onDragReady(FCPoint *startOffset);
		/**
		 * 可用改变方法
		 */
		virtual void onEnableChanged();
		/**
		 * 字体改变方法
		 */
		virtual void onFontChanged();
		/**
		 * 获得焦点方法
		 */
		virtual void onGotFocus();
	    /**
         * 在视图线程中调用方法
         * @param args  参数
        */
		virtual void onInvoke(Object args);
		/**
		 * 视图加载方法
		 */
		virtual void onLoad();
		/**
		 * 位置改变方法
		 */
		virtual void onLocationChanged();
		/**
		 * 丢失焦点方法
		 */
		virtual void onLostFocus();
		/*
		* 键盘按下方法
		*/
		virtual void onKeyDown(char key);
		/*
		* 键盘抬起方法
		*/
		virtual void onKeyUp(char key);
		/**
		 * 外边距改变方法
		 */
		virtual void onMarginChanged();
		/*
		* 处理缩放
		*/
		virtual void onScaling(double scaleFactorX, double scaleFactorY);
	    /**
         * 触摸按下方法
         * @param touchInfo  触摸信息
        */
		virtual void onTouchDown(FCTouchInfo touchInfo);
	    /**
         * 触摸进入方法
         * @param touchInfo  触摸信息
        */
		virtual void onTouchEnter(FCTouchInfo touchInfo);
	    /**
         * 触摸离开方法
         * @param touchInfo  触摸信息
        */
		virtual void onTouchLeave(FCTouchInfo touchInfo);
	    /**
         * 触摸移动调用方法
         * @param touchInfo  触摸信息
        */
		virtual void onTouchMove(FCTouchInfo touchInfo);
	    /**
         * 触摸抬起方法
         * @param touchInfo  触摸信息
        */
		virtual void onTouchUp(FCTouchInfo touchInfo);
		/*
		* 触摸滚动方法
		*/
		virtual void onTouchWheel(FCTouchInfo touchInfo);
		/**
		 * 内边距改变方法
		 */
		virtual void onPaddingChanged();
	    /**
         * 重绘方法
         * @param paint  绘图对象
         * @param clipRect   裁剪区域
        */
		virtual void onPaint(FCPaint *paint, const FCRect& clipRect);
	    /**
         * 重绘背景方法
         * @param paint  绘图对象
         * @param clipRect   裁剪区域
        */
		virtual void onPaintBackground(FCPaint *paint, const FCRect& clipRect);
	    /**
         * 重绘边线方法
         * @param paint  绘图对象
         * @param clipRect   裁剪区域
        */
		virtual void onPaintBorder(FCPaint *paint, const FCRect& clipRect);
	    /**
         * 重绘前景方法
         * @param paint  绘图对象
         * @param clipRect   裁剪区域
        */
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
		/**
		 * 父容器改变方法
		 */
		virtual void onParentChanged();
		/**
		 * 复制
		 */
		virtual void onPaste();
	    /**
         * 预绘图方法
         * @param paint  绘图对象
         * @param clipRect   裁剪区域
        */
		virtual bool onPrePaint(FCPaint *paint, const FCRect& clipRect);
		/*
		* 键盘预处理事件
		*/
		virtual bool onPreviewsKeyEvent(String eventName, char key);
	    /**
         * 键盘下按方法
         * @param eventName  事件ID
         * @param key      按键
         * @returns     状态
        */
		virtual bool onPreviewsTouchEvent(String eventName, FCTouchInfo touchInfo);
		/**
		 * 裁剪区域改变方法
		 */
		virtual void onRegionChanged();
		/**
		 * 移除视图方法
		 */
		virtual void onRemove();
		/**
		 * 尺寸改变方法
		 */
		virtual void onSizeChanged();
		/**
		 * TAB索引改变方法
		 */
		virtual void onTabIndexChanged();
		/**
		 * 被使用TAB切换方法
		 */
		virtual void onTabStop();
		/**
		 * 是否用TAB切换改变方法
		 */
		virtual void onTabStopChanged();
		/**
		 * 文本改变方法
		 */
		virtual void onTextChanged();
		/**
		 * 前景色改变方法
		 */
		virtual void onTextColorChanged();
	    /**
         * 秒表回调方法
         * @param timerID  编号
        */
		virtual void onTimer(int timerID);
		/**
		 * 可见状态改变方法
		 */
		virtual void onVisibleChanged();
		/*
		 * 转为相对坐标
		 */
		virtual FCPoint pointToView(const FCPoint& mp);
	    /**
         * 获取相对于视图的相对坐标
         * @param point  坐标
         * @returns  相对坐标
        */
		virtual FCPoint pointToNative(const FCPoint& mp);
	    /**
         * 移除视图
         * @param view 视图
        */
		virtual void removeView(FCView *view);
		/**
         * 取消注册事件
         * @param func  函数指针
         * @param eventName  事件名称
        */
		virtual void removeEvent(Object func, const String& eventName);
	    /**
         * 设置属性
         * @param name  属性名称
         * @param value 属性值
        */
		virtual void setAttribute(const String& name, const String& value);
		/**
		 * 显示视图
		 */
		virtual void show();
		/*
		* 在镜像以外显示
		*/
		virtual bool showOutOfMirror();
	    /**
         * 开始秒表
         * @param timerID  编号
         * @param interval 间隔
        */
		virtual void startTimer(int timerID, int interval);
	    /**
         * 停止秒表
         * @param timerID  编号
        */
		virtual void stopTimer(int timerID);
	    /**
         * 将视图置于最后
         * @param childView  子视图
        */
		virtual void sendChildToBack(FCView *childView);
		/**
		 * 将视图放到最下面显示
		 */
		virtual void sendToBack();
		/**
		 * 更新界面
		 */
		virtual void update();
	};
}