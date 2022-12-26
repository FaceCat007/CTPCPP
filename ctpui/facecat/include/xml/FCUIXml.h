/*
 * FaceCat框架(非开源)
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __UIXML_H__
#else                                                                            
#define __UIXML_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCUIEvent.h"
#include "FCUIScript.h"
#include <atlstr.h>  
#import <msxml3.dll>
#include "..\\core\\FCLib.h"

namespace FaceCat{
	#define HRCALL(a, errmsg) \
	do { \
		hr = (a); \
		if (FAILED(hr)) { \
			dprintf( "%s:%d  HRCALL Failed: %s\n  0x%.8x = %s\n", \
					__FILE__, __LINE__, errmsg, hr, #a ); \
			goto clean; \
		} \
	} while (0)

	class FCUIEvent;
	class FCUIScript;

	/*
	* XML处理
	*/
	class __UIXML_H__ FCUIXml{
	public:
		/*
		* 是否允许名称
		*/
		bool m_allowName;
		/*
		* 名称
		*/
		String m_name;
	    /**
		 * 视图列表
		 */
		ArrayList<FCView*> m_views;
		/**
		 * 事件
		 */
		FCUIEvent *m_event;
		/**
		 * 方法库
		 */
		FCNative *m_native;
		/**
		 * 脚本
		 */
		FCUIScript *m_script;
		/**
		 * CSS样式
		 */
		HashMap<String, String> m_styles;
		/*
		* 创建FCGridBand
		*/
		virtual void createBandedGridBands(IXMLDOMNode *node, FCView *view);
		/*
		 * 创建表格列
		 */
		virtual void createBandedGridColumns(IXMLDOMNode *node, FCView *view);
		/*
		 * 创建图形的子属性 
		 */
		virtual void createChartSubAttribute(IXMLDOMNode *node, FCChart *chart);
		/**
		 * 创建菜单项
		 */
		virtual void createMenuItem(IXMLDOMNode *node, FCMenu *menu, FCMenuItem *parentItem);
		/*
		 * 创建表格列
		 */
		virtual void createGridColumns(IXMLDOMNode *node, FCView *view);
		/*
		 * 创建表格行
		 */
		virtual void createGridRow(IXMLDOMNode *node, FCView *view);
		/*
		 * 创建表格行
		 */
		virtual void createGridRows(IXMLDOMNode *node, FCView *view);
		/**
		 * 创建分割布局视图
		 */
		virtual void createSplitLayoutSubAttribute(IXMLDOMNode *node, FCSplitLayoutDiv *splitLayoutDiv);
		/**
		 * 创建视图
		 */
		virtual void createTableLayoutSubAttribute(IXMLDOMNode *node, FCTableLayoutDiv *tableLayoutDiv);
		/**
		 * 创建多页夹的页
		 */
		virtual void createTabPage(IXMLDOMNode *node, FCView *view);
		/**
		 * 创建树的节点
		 */
		virtual void createTreeNode(IXMLDOMNode *node, FCView *view, FCTreeNode *treeNode);
		/**
		 * 创建树的节点
		 */
		virtual void createTreeNodes(IXMLDOMNode *node, FCView *view);
		/**
		 * 创建用户视图
		 */
		virtual FCView* createCustomView(IXMLDOMNode *node);
		static void dprintf(char *format, ...);
		static IXMLDOMDocument* domFromCOM();	
	public:
		/*
		* 构造函数
		*/
		FCUIXml();
		/*
		* 析构函数
		*/
		virtual ~FCUIXml();
		/**
		 * 获取事件
		 */
		virtual FCUIEvent* getEvent();
		/**
		 * 设置事件
		 */
		virtual void setEvent(FCUIEvent *value);
		/**
		 * 获取方法库
		 */
		virtual FCNative* getNative();
		/**
		 * 设置方法库
		 */
		virtual void setNative(FCNative *value);
		/**
		 * 获取脚本
		 */
		virtual FCUIScript* getScript();
		/**
		 * 设置脚本
		 */
		virtual void setScript(FCUIScript *value);
		/*
		 * 获取XML的路径
		 */
		String getXmlPath();
	public:
		/**
		* 获取按钮
		* @params name   视图名称
		*/
		virtual FCButton* getButton(const String& name);
		/**
		 * 获取图形视图
		 */
		virtual FCChart* getChart(const String& name);
		/**
		 * 获取复选框
		 */
		virtual FCCheckBox* getCheckBox(const String& name);
		/**
		 * 获取下拉视图
		 */
		virtual FCComboBox* getComboBox(const String& name);
		/*
		 * 获取日期时间视图
		 */
		virtual FCDateTimePicker* getDateTimePicker(const String& name);
		/**
		 * 获取图层
		 */
		virtual FCDiv* getDiv(const String& name);
		/**
		 * 获取表格
		 */
		virtual FCGrid* getGrid(const String& name);
		/**
		 * 获取组视图
		 */
		virtual FCGroupBox* getGroupBox(const String& name);
		/**
		 * 获取标签
		 */
		virtual FCLabel* getLabel(const String& name);
		/**
		 * 获取布局层
		 */
		virtual FCLayoutDiv* getLayoutDiv(const String& name);
		/**
		 * 获取名称相似视图
		 */
		virtual ArrayList<FCView*> getLikeViews(const String& name);
		/**
		 * 获取菜单视图
		 */
		virtual FCMenu* getMenu(const String& name);
		/**
		 * 获取菜单项视图
		 */
		virtual FCMenuItem* getMenuItem(const String& name);
		/**
		 * 获取单选按钮
		 */
		virtual FCRadioButton* getRadioButton(const String& name);
		/**
		 * 获取数值视图
		 */
		virtual FCSpin* getSpin(const String& name);
		/**
		 * 获取分割层
		 */
		virtual FCSplitLayoutDiv* getSplitLayoutDiv(const String& name);
		/**
		 * 获取多页夹视图
		 */
		virtual FCTabView* getTabView(const String& name);
		/**
		 * 获取表格层
		 */
		virtual FCTableLayoutDiv* getTableLayoutDiv(const String& name);
		/**
		 * 获取夹视图
		 */
		virtual FCTabPage* getTabPage(const String& name);
		/**
		 * 获取文本框
		 */
		virtual FCTextBox* getTextBox(const String& name);
		/**
		 * 获取树视图
		 */
		virtual FCTree* getTree(const String& name);
		/**
		 * 获取窗体
		 */
		virtual FCWindow* getWindow(const String& name);
		/*
		* 获取命名的Xml对象
		*/
		static FCUIXml* getNameXml(const String& name);
	public:
		/**
		* 是否包含视图
		* @params view  视图
		* @params node  节点
		*/
		virtual bool containsView(FCView *view);
		/**
		 * 创建视图
		 */
		virtual FCView* createView(IXMLDOMNode *node, const String& type);
		/**
		 * 创建视图框架
		 */
		virtual void createNative();
		/**
		 * 创建子属性
		 */
		virtual void createSubAttribute(IXMLDOMNode *node, FCView *view);
		/**
		 * 查找视图
		 */
		virtual FCView* findView(const String& name);
		/**
		 * 获取属性
		 */
		virtual HashMap<String, String> getAttributes(IXMLDOMNode *node);
		/**
		 * 获取所有的视图
		 */
		virtual ArrayList<FCView*> getViews();
		/**
		 * 判断是否后设置属性
		 */
		virtual bool isAfterSetingAttribute(const String& name);
		/**
		 * 读取文件，加载到视图中
		 */
		virtual void loadFile(const String& fileName, FCView *view);
		/**
		 * 添加视图
		 */
		virtual void onAddView(FCView *view, IXMLDOMNode *node);
		/**
		 * 读取文件体
		 */
		virtual void readBody(IXMLDOMNode *node, FCView *view);
		/**
		 * 读取子节点
		 */
		virtual void readChildNodes(IXMLDOMNode *node, FCView *view);
		/**
		 * 读取头部
		 */
		virtual void readHead(IXMLDOMNode *node, FCView *view);
		/**
		 * 读取XML
		 */
		virtual FCView* readNode(IXMLDOMNode *node, FCView* parent);
		/**
		 * 读取样式
		 */
		virtual void readStyle(IXMLDOMNode *node, FCView *view);
		/**
		 * 后设置属性
		 */
		virtual void setAttributesAfter(IXMLDOMNode *node, FCAttribute *view);
		/**
		 * 前设置属性
		 */
		virtual void setAttributesBefore(IXMLDOMNode *node, FCAttribute *view);
		/**
		 * 设置事件
		 */
		virtual void setEvents(IXMLDOMNode *node, FCAttribute *view);
		/**
		 * 设置CSS样式
		 */
		virtual void setStyle(const String& style, FCAttribute *view);
	};
}