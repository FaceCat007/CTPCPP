/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCSPLITLAYOUTDIV_H__
#else                                                                            
#define __FCSPLITLAYOUTDIV_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\btn\\FCButton.h"
#include "FCDiv.h"
#include "FCLayoutDiv.h"
#include "FCTableLayoutDiv.h"

namespace FaceCat{
	/*
	* 分割层
	*/
	class __FCSPLITLAYOUTDIV_H__ FCSplitLayoutDiv : public FCLayoutDiv{
	public:
	    /**
		 * 第一个视图
		 */
		FCView *m_firstView;
		/**
		 * 第二个视图
		 */
		FCView *m_secondView;
		/*
		* 基准尺寸
		*/
		FCSize m_datumSize;
		/**
		 * 分割模式
		 */
		FCSizeType m_splitMode;
		/**
		 * 分割百分比
		 */
		float m_splitPercent;
		/**
		 * 分割按钮
		 */
		FCButton *m_splitter;
	public:
		/*
		* 构造函数
		*/
		FCSplitLayoutDiv();
		/*
		* 析构函数
		*/
		virtual ~FCSplitLayoutDiv();
		/*
		* 获取基准尺寸
		*/
		virtual FCSize getDatumSize();
		/*
		* 设置基准尺寸
		*/
		virtual void setDatumSize(FCSize value);
		/**
		 * 获取第一个视图
		 */
		virtual FCView* getFirstView();
		/**
		 * 设置第一个视图
		 */
		virtual void setFirstView(FCView *value);
		/**
		 * 获取第二个视图
		 */
		virtual FCView* getSecondView();
		/**
		 * 设置第二个视图
		 */
		virtual void setSecondView(FCView *value);
		/**
		 * 获取分割模式
		 */
		virtual FCSizeType getSplitMode();
		/**
		 * 设置分割模式
		 */
		virtual void setSplitMode(FCSizeType value);
		/**
		 * 获取分割按钮
		 */
		virtual FCButton* getSplitter();
	public:
		/*
		* 触发事件
		*/
		virtual void callEvent(String eventName, Object sender, Object invoke);
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
		 * 添加视图方法
		 */
		virtual void onLoad();
		/**
		 * 重置布局
		 */
		virtual bool onResetLayout();
		/**
		 * 布局更新方法
		 */
		virtual void update();
		/**
		* 设置属性
		* @param  name   属性名称
		* @param  value   返回属性值
		*/
		virtual void setAttribute(const String& name, const String& value);
	};
}
