/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCTOOLTIP_H__
#else                                                                            
#define __FCTOOLTIP_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\Label\\FCLabel.h"

namespace FaceCat{
	/*
	* 提示层
	*/
	class __FCTOOLTIP_H__ FCToolTip : public FCLabel{
	private:
	    /**
		 * 秒表ID
		 */
		int m_timerID;
	public:
	    /**
		 * 显示的时间长度
		 */
		int m_autoPopDelay;
		/**
		 * 触摸静止时延迟显示的毫秒数
		 */
		int m_initialDelay;
		/**
		 * 上一次触摸的位置
		 */
		FCPoint m_lastTouchPoint;
		/**
		 * 是否总是显示
		 */
		bool m_showAlways;
		/**
		 * 是否在显示隐藏时使用动画
		 */
		bool m_useAnimation;
	public:
	    /**
		 * 剩余保留显示毫秒数
		 */
		int m_remainAutoPopDelay;
		/**
		 * 剩余延迟显示毫秒数
		 */
		int m_remainInitialDelay;
	public:
		/*
		* 构造函数
		*/
		FCToolTip();
		/*
		* 析构函数
		*/
		virtual ~FCToolTip();
		/**
		 * 提示显示的时间长度
		 */
		virtual int getAutoPopDelay();
		/**
		 * 保留显示的时间长度
		 */
		virtual void setAutoPopDelay(int value);
		/**
		 * 获取触摸静止时延迟显示的毫秒数
		 */
		virtual int getInitialDelay();
		/**
		 * 设置触摸静止时延迟显示的毫秒数
		 */
		virtual void setInitialDelay(int value);
		/**
		 * 获取是否总是显示
		 */
		virtual bool showAlways();
		/**
		 * 设置是否总是显示
		 */
		virtual void setShowAlways(bool value);
		/**
		 * 获取是否在显示隐藏时使用动画
		 */
		virtual bool useAnimation();
		/**
		 * 设置是否在显示隐藏时使用动画
		 */
		virtual void setUseAnimation(bool value);
	public:
	    /**
		 * 获取视图类型
		 */
		virtual String getViewType();
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
		 * 隐藏视图
		 */
		virtual void hide();
		/**
		 * 添加视图方法
		 */
		virtual void onLoad();
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
		 * 显示视图
		 */
		virtual void show();
		/**
		* 设置属性值
		* @param  name   属性名称
		* @param  value   属性值
		*/
		virtual void setAttribute(const String& name, const String& value);
	};
}