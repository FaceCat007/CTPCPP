/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCMENU_H__
#else                                                                            
#define __FCMENU_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\div\\FCLayoutDiv.h"
#include "FCMenuItem.h"

namespace FaceCat{
	class __FCMENU_H__ FCMenuItem;
	/*
	* 点击菜单事件
	*/
    class __FCMENU_H__ FCMenuItemTouchEventCallBack {
	public:
		FCMenuItemTouchEventCallBack(){}
		virtual ~FCMenuItemTouchEventCallBack(){}
		virtual void callMenuItemTouchEvent(String eventName, Object sender, FCMenuItem *item, FCTouchInfo touchInfo, Object invoke){}
    };
	/*
	* 菜单
	*/
	class __FCMENU_H__ FCMenu : public FCLayoutDiv{
	private:
	    /**
		 * 秒表编号
		 */
		int m_timerID;
	public:
	    /**
		 * 是否自动隐藏
		 */
		bool m_autoHide;
		/**
		 * 父菜单项
		 */
		FCMenuItem *m_parentItem;
		/**
		 * 是否弹出
		 */
		bool m_popup;
		/**
		* 自动适应位置和大小
		* @param  menu  菜单
		*/
		virtual void adjust(FCMenu *menu);
		/**
		* 检查图层是否具有焦点
		* @param  items  视图集合
		*/
		virtual bool checkDivFocused(ArrayList<FCMenuItem*> items);
		/**
		* 检查焦点
		* @param  view  视图
		*/
		virtual bool checkFocused(FCView *view);
		/**
		* 关闭网格视图
		* @param  items  菜单集合
		*/
		virtual bool closeMenus(ArrayList<FCMenuItem*> items);
	public:
		/**
		* 调用菜单的触摸事件
		* @param  eventName   事件ID
		* @param  item   菜单项
         * @param  touchInfo   触摸信息
        */
		void callMenuItemTouchEvent(String eventName, FCMenuItem *item, FCTouchInfo touchInfo);
	public:
	    /**
		 * 菜单项
		 */
		ArrayList<FCMenuItem*> m_items;
		/*
		* 构造函数
		*/
		FCMenu();
		/*
		* 析构函数
		*/
		virtual ~FCMenu();
		/**
		 * 获取是否自动隐藏
		 */
		virtual bool autoHide();
		/**
		 * 设置是否自动隐藏
		 */
		virtual void setAutoHide(bool value);
		/**
		 * 获取父菜单项
		 */
		virtual FCMenuItem* getParentItem();
		/**
		 * 设置父菜单项
		 */
		virtual void setParentItem(FCMenuItem *value);
		/**
		 * 获取是否弹出
		 */
		virtual bool canPopup();
		/**
		 * 设置是否弹出
		 */
		virtual void setPopup(bool value);
	public:
		/**
		* 添加项
		* @param  item  菜单项
		*/
		virtual void addItem(FCMenuItem *item);
		/**
		 * 清除所有的项
		 */
		virtual void clearItems();
		/**
		 * 创建菜单
		 */
		virtual FCMenu* createDropDownMenu();
		/**
		 * 获取视图类型
		 */
		virtual String getViewType();
		/**
		 * 获取所有的菜单项
		 */
		virtual ArrayList<FCMenuItem*> getItems();
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
         * 获取方法列表
         */
        virtual ArrayList<String> getEventNames();
		/**
		* 插入项
		* @param  index  索引
		* @param  item   菜单项
		*/
		virtual void insertItem(int index, FCMenuItem *item);
		/**
		 * 是否不处理自动隐藏
		 */
		virtual bool onAutoHide();
		/*
		* 加载方法
		*/
		virtual void onLoad();
		/**
		* 菜单点击方法
		* @param  item   菜单项
         * @param  touchInfo   触摸信息
        */
		virtual void onMenuItemClick(FCMenuItem *item, FCTouchInfo touchInfo);
		/**
		* 菜单触摸移动方法
		* @param  item   菜单项
         * @param  touchInfo   触摸信息
        */
		virtual void onMenuItemTouchMove(FCMenuItem *item, FCTouchInfo touchInfo);
		/**
        * 触摸点击方法
        * @param  touchInfo   触摸信息
        */
		virtual void onTouchDown(FCTouchInfo touchInfo);
		/**
		* 秒表方法
		* @param  timerID   秒表ID
        */
		virtual void onTimer(int timerID);
		/**
		 * 可见状态改变方法
		 */
		virtual void onVisibleChanged();
		/**
		* 移除菜单项
		* @param  item   菜单项
        */
		virtual void removeItem(FCMenuItem *item);
		/**
		* 设置属性值
		* @param  name   属性名称
		* @param  value   属性值
		*/
		virtual void setAttribute(const String& name, const String& value);
		/*
		* 在镜像以外显示
		*/
		virtual bool showOutOfMirror();
	};
}
