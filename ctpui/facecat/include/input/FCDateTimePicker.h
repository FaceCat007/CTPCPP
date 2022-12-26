/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCDATETIMEPICKER_H__
#else                                                                            
#define __FCDATETIMEPICKER_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCTextBox.h"
#include "..\\btn\\FCButton.h"
#include "..\\div\\FCMenu.h"
#include "..\\div\\FCMenuItem.h"
#include "..\\date\\FCCalendar.h"

namespace FaceCat{
	/*
	* 日历选择视图
	*/
	class __FCDATETIMEPICKER_H__ FCDateTimePicker : public FCTextBox{
	public:
	    /**
		 * 获取日历
		 */
		FCCalendar *m_calendar;
		/**
		 * 日期格式
		 */
		String m_customFormat;
		/**
		 * 下拉按钮
		 */
		FCButton *m_dropDownButton;
		/**
		 * 下拉菜单
		 */
		FCMenu *m_dropDownMenu;
		/**
		 * 是否显示时间
		 */
		bool m_showTime;
	public:
		/*
		* 构造函数
		*/
		FCDateTimePicker();
		/*
		* 析构函数
		*/
		virtual ~FCDateTimePicker();
		/**
		 * 获取日历
		 */
		virtual FCCalendar* getCalendar();
		/**
		 * 获取日期格式
		 */
		virtual String getCustomFormat();
		/**
		 * 设置日期格式
		 */
		virtual void setCustomFormat(const String& value);
		/**
		 * 获取下拉按钮
		 */
		virtual FCButton* getDropDownButton();
		/**
		 * 获取下拉菜单
		 */
		virtual FCMenu* getDropDownMenu();
		/**
		 * 获取是否显示时间
		 */
		virtual bool showTime();
		/**
		 * 设置是否显示时间
		 */
		virtual void setShowTime(bool value);
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
		 * 获取视图类型
		 */
		virtual String getViewType();
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
		 * 下拉菜单显示方法
		 */
		virtual void onDropDownOpening();
		/**
		 * 添加视图方法
		 */
		virtual void onLoad();
		/**
		 * 数值改变方法
		 */
		virtual void onSelectedTimeChanged();
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