/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCLINKLABEL_H__
#else                                                                            
#define __FCLINKLABEL_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCLabel.h"

namespace FaceCat{
    /**
	 * 超链接视图行为
	 */
	enum __FCLINKLABEL_H__ FCLinkBehavior{
	    /**
		 * 总是显示下划线
		 */
		LinkBehaviorA_AlwaysUnderLine,
		/**
		 * 触摸悬停时显示下划线
		 */
		LinkBehaviorA_HoverUnderLine,
		/**
		 * 总是不显示下划线
		 */
		LinkBehaviorA_NeverUnderLine
	};

	class FCLabel;

	/*
	* 链接标签
	*/
	class __FCLINKLABEL_H__ FCLinkLabel : public FCLabel{
	public:
	    /**
		 * 单击超链接时的颜色
		 */
		Long m_activeLinkColor;
		/**
		 * 超链接被禁用时的颜色
		 */
		Long m_disabledLinkColor;
		/**
		 * 下划线的显示方式
		 */
		FCLinkBehavior m_linkBehavior;
		/**
		 * 超链接处于默认时的颜色
		 */
		Long m_linkColor;
		/**
		 * 是否按照已访问的样式显示超链接颜色
		 */
		bool m_linkVisited;
		/**
		 * 是否已访问
		 */
		bool m_visited;
		/**
		 * 已访问的超链接的颜色
		 */
		Long m_visitedLinkColor;
	public:
	    /**
		 * 获取要绘制的超链接颜色
		 */
		virtual Long getPaintingLinkColor();
	public:
		/*
		* 构造函数
		*/
		FCLinkLabel();
		/*
		* 析构函数
		*/
		virtual ~FCLinkLabel();
		/**
		 * 获取单击超链接时的颜色
		 */
		virtual Long getActiveLinkColor();
		/**
		 * 设置单击超链接时的颜色
		 */
		virtual void setActiveLinkColor(Long value);
		/**
		 * 获取超链接被禁用时的颜色
		 */
		virtual Long getDisabledLinkColor();
		/**
		 * 设置超链接被禁用时的颜色
		 */
		virtual void setDisabledLinkColor(Long value);
		/**
		 * 获取下划线的显示方式
		 */
		virtual FCLinkBehavior getLinkBehavior();
		/**
		 * 设置下划线的显示方式
		 */
		virtual void setLinkBehavior(FCLinkBehavior value);
		/**
		 * 获取超链接处于默认时的颜色
		 */
		virtual Long getLinkColor();
		/**
		 * 设置超链接处于默认时的颜色
		 */
		virtual void setLinkColor(Long value);
		/**
		 * 获取是否按照已访问的样式显示超链接颜色
		 */
		virtual bool isLinkVisited();
		/**
		 * 设置是否按照已访问的样式显示超链接颜色
		 */
		virtual void setLinkVisited(bool value);
		/**
		 * 获取的超链接的颜色
		 */
		virtual Long getVisitedLinkColor();
		/**
		 * 访问的超链接的颜色
		 */
		virtual void setVisitedLinkColor(Long value);
	public:
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
		 * 触摸点击方法
		 */
		virtual void onClick(FCTouchInfo touchInfo);
		/**
		 * 触摸按下方法
		 */
		virtual void onTouchDown(FCTouchInfo touchInfo);
		/**
		 * 触摸进入方法
		 */
		virtual void onTouchEnter(FCTouchInfo touchInfo);
		/**
		 * 触摸离开方法
		 */
		virtual void onTouchLeave(FCTouchInfo touchInfo);
		/**
		 * 触摸抬起方法
		 */
		virtual void onTouchUp(FCTouchInfo touchInfo);
		/**
		 * 重绘前景方法
		 */
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
		/**
		* 设置属性
		* @param  name  属性名称
		* @param  value  属性值
		*/
		virtual void setAttribute(const String& name, const String& value);
	};
}