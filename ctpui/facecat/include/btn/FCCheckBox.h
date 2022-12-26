/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCCHECKBOX_H__
#else                                                                            
#define __FCCHECKBOX_H__ _declspec(dllexport) 
#endif

#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCTran.h"
#include "FCButton.h"

namespace FaceCat{
	/**
     * 复选框视图
     */
	class __FCCHECKBOX_H__ FCCheckBox : public FCButton{
	public:
		/**
	     * 获取或设置内容的横向排列样式
	     */
		FCHorizontalAlign m_buttonAlign;
		/**
	     * 获取或设置按钮的背景色
	     */
		Long m_buttonBackColor;
		/**
	     * 获取或设置按钮的边线颜色
	     */
		Long m_buttonBorderColor;
		/**
	     * 获取或设置按钮的尺寸
	     */
		FCSize m_buttonSize;
		/**
	     * 获取或设置是否被选中
	     */
		bool m_checked;
		/**
	     * 获取或设置选中时的背景图
	     */
		String m_checkedBackImage;
		/**
	     * 获取或设置触摸悬停且选中时的背景图片
	     */
		String m_checkHoveredBackImage;
		/**
	     * 获取或设置触摸按下且选中时的背景图片
	     */
		String m_checkPushedBackImage;
		/**
	     * 获取或设置不可用时的选中背景图片
	     */
		String m_disableCheckedBackImage;
	public:
	    /**
	     * 获取或设置的背景色
	     */
		virtual Long getPaintingBackColor();
		/**
	     * 获取要绘制的按钮的背景色
	     */
		virtual Long getPaintingButtonBackColor();
		/**
	     * 获取要绘制的按钮边线颜色
	     */
		virtual Long getPaintingButtonBorderColor();
		/**
	     * 获取用于绘制的背景图片
	     */
		virtual String getPaintingBackImage();
	public:
		/*
		* 构造函数
		*/
		FCCheckBox();
		/*
		* 析构函数
		*/
		virtual ~FCCheckBox();
		/**
	     * 获取内容的横向排列样式
	     */
		virtual FCHorizontalAlign getButtonAlign();
		/**
	     * 设置内容的横向排列样式
	     */
		virtual void setButtonAlign(FCHorizontalAlign value);
		/**
	     * 获取按钮的背景色
	     */
		virtual Long getButtonBackColor();
		/**
	     * 设置按钮的背景色
	     */
		virtual void setButtonBackColor(Long value);
		/**
	     * 获取按钮的边线颜色
	     */
		virtual Long getButtonBorderColor();
		/**
	     * 设置按钮的边线颜色
	     */
		virtual void setButtonBorderColor(Long value);
		/**
	     * 获取按钮的尺寸
	     */
		virtual FCSize getButtonSize();
		/**
	     * 设置按钮的尺寸
	     */
		virtual void setButtonSize(FCSize value);
		/**
	     * 获取是否被选中
	     */
		virtual bool isChecked();
		/**
	     * 设置是否被选中
	     */
		virtual void setChecked(bool value);
		/**
	     * 获取选中时的背景图
	     */
		virtual String getCheckedBackImage();
		/**
	     * 设置选中时的背景图
	     */
		virtual void setCheckedBackImage(const String& value);
		/**
	     * 获取触摸悬停且选中时的背景图片
	     */
		virtual String getCheckHoveredBackImage();
		/**
	     * 设置触摸悬停且选中时的背景图片
	     */
		virtual void setCheckHoveredBackImage(const String& value);
		/**
	     * 获取触摸按下且选中时的背景图片
	     */
		virtual String getCheckPushedBackImage();
		/**
	     * 设置触摸按下且选中时的背景图片
	     */
		virtual void setCheckPushedBackImage(const String& value);
		/**
	     * 获取不可用时的选中背景图片
	     */
		virtual String getDisableCheckedBackImage();
		/**
	     * 设置不可用时的选中背景图片
	     */
		virtual void setDisableCheckedBackImage(const String& value);
	public:
	    /**
	     * 获取视图类型
	     */
		virtual String getViewType();
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
	      * 选中改变方法
	     */
		virtual void onCheckedChanged();
	    /**
         * 点击方法
         * @param touchInfo 触摸信息
        */
		virtual void onClick(FCTouchInfo touchInfo);
	    /**
         * 重绘背景方法
         * @param paint    绘图对象
         * @param clipRect 裁剪区域
        */
		virtual void onPaintBackground(FCPaint *paint, const FCRect& clipRect);
	    /**
         * 重绘选中按钮方法
         * @param paint    绘图对象
         * @param clipRect 裁剪区域
        */
		virtual void onPaintCheckButton(FCPaint *paint, const FCRect& clipRect);
	    /**
         * 重绘前景方法
         * @param paint    绘图对象
         * @param clipRect 裁剪区域
        */
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
		/*
		* 处理缩放
		*/
		virtual void onScaling(double scaleFactorX, double scaleFactorY);
	    /**
         * 设置属性
         * @param name    属性名称
         * @param value   属性值
        */
		virtual void setAttribute(const String& name, const String& value);
	};
}
