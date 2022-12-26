/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCCOMBOBOX_H__
#else                                                                            
#define __FCCOMBOBOX_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCTextBox.h"
#include "..\\btn\\FCButton.h"
#include "..\\div\\FCMenu.h"
#include "..\\div\\FCMenuItem.h"

namespace FaceCat{
	class FCComboBox;

	/*
	* 下拉列表的菜单
	*/
	class __FCCOMBOBOX_H__ FCComboBoxMenu : public FCMenu{
	public:
	    /**
		 * 列表视图
		 */
		FCComboBox *m_comboBox;
	public:
		/*
		* 构造函数
		*/
		FCComboBoxMenu();
		/*
		* 析构函数
		*/
		virtual ~FCComboBoxMenu();
		/**
		 * 获取列表视图
		 */
		FCComboBox* getComboBox();
		/**
		 * 设置列表视图
		 */
		void setComboBox(FCComboBox *value);
		/**
		 * 是否自动隐藏
		 */
		virtual bool onAutoHide();
	};

	/*
	* 下拉列表
	*/
	class __FCCOMBOBOX_H__ FCComboBox : public FCTextBox, public FCMenuItemTouchEventCallBack{
	public:
		/*
		* 下拉按钮
		*/
		FCButton* m_dropDownButton;
		/*
		* 下拉菜单
		*/
		FCComboBoxMenu* m_dropDownMenu;
	public:
		/*
		* 构造函数
		*/
		FCComboBox();
		/*
		* 析构函数
		*/
		virtual ~FCComboBox();
		/**
		 * 获取下拉按钮
		 */
		virtual FCButton* getDropDownButton();
		/**
		 * 获取下拉菜单
		 */
		virtual FCComboBoxMenu* getDropDownMenu();
		/**
		 * 获取选中的索引
		 */
		virtual int getSelectedIndex();
		/**
		 * 设置选中的索引
		 */
		virtual void setSelectedIndex(int value);
		/**
		 * 获取选中的文字
		 */
		virtual String getSelectedText();
		/**
		 * 设置选中的文字
		 */
		virtual void setSelectedText(const String& value);
		/**
		 * 获取选中的值
		 */
		virtual String getSelectedValue();
		/**
		 * 设置选中的值
		 */
		virtual void setSelectedValue(const String& value);
	public:
	    /**
		 * 添加菜单项
		 */
		void addItem(FCMenuItem *item);
		/*
		* 触发事件
		*/
		virtual void callTouchEvent(String eventName, Object sender, FCTouchInfo touchInfo, Object invoke);
		/*
		* 触发菜单项事件
		*/
		virtual void callMenuItemTouchEvent(String eventName, Object sender, FCMenuItem *item, FCTouchInfo touchInfo, Object invoke);
		/*
		* 调用键盘事件
		*/
		virtual void callKeyEvent(String eventName, Object sender, char key, Object invoke);
		/**
		 * 清除所有菜单项
		 */
		void clearItems();
		/**
		 * 获取视图类型
		 */
		virtual String getViewType();
		/**
         * 获取方法列表
         */
        virtual ArrayList<String> getEventNames();
		/**
		 * 获取菜单项
		 */
		ArrayList<FCMenuItem*> getItems();
		/**
		* 获取属性值
		* @param  name  属性名称
		* @param  value  返回属性值
		* @param  type  返回属性类型
		*/
		virtual void getAttribute(const String& name, String *value, String *type);
		/**
		 * 获取属性名称列表
		 */
		virtual ArrayList<String> getAttributeNames();
		/**
		 * 插入菜单项
		 */
		virtual void insertItem(int index, FCMenuItem *item);
		/**
		 * 菜单下拉方法
		 */
		virtual void onDropDownOpening();
		/**
		 * 键盘按下方法
		 */
		virtual void onKeyDown(char key);
		/**
		 * 添加视图方法
		 */
		virtual void onLoad();
		/**
		 * 选中索引改变方法
		 */
		virtual void onSelectedIndexChanged();
		/**
		 * 触摸滚轮方法
		 */
		virtual void onTouchWheel(FCTouchInfo touchInfo);
		/**
		 * 移除菜单项
		 */
		virtual void removeItem(FCMenuItem *item);
		/**
		* 设置属性
		* @param  name  属性名称
		* @param  value  属性值
		*/
		virtual void setAttribute(const String& name, const String& value);
		/**
		 * 更新布局方法
		 */
		virtual void update();
	};
}