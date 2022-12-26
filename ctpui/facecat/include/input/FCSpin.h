/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCSPIN_H__
#else                                                                            
#define __FCSPIN_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCTran.h"
#include "FCTextBox.h"
#include "..\\btn\\FCButton.h"

namespace FaceCat{
	/*
	* 数值选择
	*/
	class __FCSPIN_H__ FCSpin : public FCTextBox{
	private:
	    /**
		 * 秒表ID
		 */
		int m_timerID;
		/**
		 * TICK值
		 */
		int m_tick;
	public:
	    /**
		 * 是否自动格式化
		 */
		bool m_autoFormat;
		/**
         * 是否自动格式化输入
         */
        bool m_autoFormatInput;
		/**
		 * 保留小数的位数
		 */
		int m_digit;
		/**
		 * 向下按钮
		 */
		FCButton *m_downButton;
		/**
		 * 是否正在增量
		 */
		bool m_isAdding;
		/**
		 * 是否正在减量
		 */
		bool m_isReducing;
		/**
		 * 最大值
		 */
		double m_maximum;
		/**
		 * 最小值
		 */
		double m_minimum;
		/**
		 * 是否显示千分位
		 */
		bool m_showThousands;
		/**
		 * 数值增减幅度
		 */
		double m_step;
		/**
		 * 获取向上按钮
		 */
		FCButton *m_upButton;
	public:
		/*
		* 构造函数
		*/
		FCSpin();
		/*
		* 析构函数
		*/
		virtual ~FCSpin();
		/**
		 * 获取是否自动格式化
		 */
		virtual bool autoFormat();
		/**
		 * 设置是否自动格式化
		 */
		virtual void setAutoFormat(bool value);
		/**
         * 获取是否自动格式化输入
         */
        virtual bool autoFormatInput();
        /**
         * 设置是否自动格式化输入
         */
        virtual void setAutoFormatInput(bool value);
		/**
		 * 获取保留小数的位数
		 */
		virtual int getDigit();
		/**
		 * 设置保留小数的位数
		 */
		virtual void setDigit(int value);
		/**
		 * 获取向下按钮
		 */
		virtual FCButton* getDownButton();
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
		 * 获取最大值
		 */
		virtual double getMaximum();
		/**
		 * 设置最大值
		 */
		virtual void setMaximum(double value);
		/**
		 * 获取最小值
		 */
		virtual double getMinimum();
		/**
		 * 设置最小值
		 */
		virtual void setMinimum(double value);
		/**
		 * 获取是否显示千分位
		 */
		virtual bool showThousands();
		/**
		 * 设置是否显示千分位
		 */
		virtual void setShowThousands(bool value);
		/**
		 * 获取数值增减幅度
		 */
		virtual double getStep();
		/**
		 * 设置数值增减幅度
		 */
		virtual void setStep(double value);
		/**
		 * 设置文本
		 */
		virtual void setText(const String& value);
		/**
		 * 获取向上按钮
		 */
		virtual FCButton* getUpButton();
		/**
		 * 获取当的数值
		 */
		virtual double getValue();
		/**
		 * 设置当的数值
		 */
		virtual void setValue(double value);
	public:
	    /**
		 *
		 * 增加指定幅度的数值
		 */
		virtual void add();
		/*
		* 触发事件
		*/
		virtual void callTouchEvent(String eventName, Object sender, FCTouchInfo touchInfo, Object invoke);
		/**
		 * 将文本转化为千分位显示
		 */
		virtual String formatNum(String inputText);
		/**
         * 获取方法列表
         */
        virtual ArrayList<String> getEventNames();
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
		 * 输入文字方法
		 */
		virtual void onChar(wchar_t ch);
		/**
		 * 键盘按下方法
		 */
		virtual void onKeyDown(char key);
		/*
         * 丢失焦点方法
         */
        virtual void onLostFocus();
		/**
		 * 添加视图方法
		 */
		virtual void onLoad();
		/**
		 * 触摸滚动方法
		 */
		virtual void onTouchWheel(FCTouchInfo touchInfo);
		/**
		 * 粘贴方法
		 */
		virtual void onPaste();
		/**
		 * 秒表事件
		 */
		virtual void onTimer(int timerID);
		/**
		 * 数值改变方法
		 */
		virtual void onValueChanged();
		/**
		 * 减少指定幅度的数值
		 */
		virtual void reduce();
		/**
		* 设置属性
		* @param  name  属性名称
		* @param  value  属性值
		*/
		virtual void setAttribute(const String& name, const String& value);
		/**
		 * 设置区域
		 */
		virtual void setRegion();
		/**
		 * 更新布局方法
		 */
		virtual void update();
	};
}
