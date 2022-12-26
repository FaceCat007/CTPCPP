/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCTREENODE_H__
#else                                                                            
#define __FCTREENODE_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\grid\\FCGrid.h"
#include "..\\grid\\FCGridRow.h"
#include "..\\grid\\FCGridCell.h"
#include "..\\btn\\FCCheckBox.h"
#include "FCTree.h"

namespace FaceCat{
	class FCTree;

	/*
	* 树节点
	*/
	class __FCTREENODE_H__ FCTreeNode : public FCGridViewCell{
	public:
	    /**
		 * 是否可以拖入节点
		 */
		bool m_allowDragIn;
		/**
		 * 是否可以拖出节点
		 */
		bool m_allowDragOut;
		/**
		 * 复选框是否选中
		 */
		bool m_checked;
		/**
		 * 子节点
		 */
		ArrayList<FCTreeNode*> m_nodes;
		/**
		 * 是否展开节点
		 */
		bool m_expended;
		/**
		 * 文字缩进距离
		 */
		int m_indent;
		/**
		 * 父节点
		 */
		FCTreeNode *m_parent;
		/**
		 * 目标列
		 */
		FCGridColumn *m_targetColumn;
		/**
		 * 文字
		 */
		String m_text;
		/**
		 * 树视图
		 */
		FCTree *m_tree;
		/**
		 * 值
		 */
		String m_value;
		/**
		 * 选中所有子节点
		 */
		void checkChildNodes(ArrayList<FCTreeNode*> nodes, bool isChecked);
		/**
		 * 折叠子节点
		 */
		void collapseChildNodes(ArrayList<FCTreeNode*> nodes, bool collapseAll);
		/**
		 * 展开所有的节点
		 */
		void expendChildNodes(ArrayList<FCTreeNode*> nodes, bool parentExpened, bool expendAll);
		/**
		 * 获取最后节点的索引
		 */
		FCTreeNode* getLastNode(ArrayList<FCTreeNode*> nodes);
	public:
		/*
		* 构造函数
		*/
		FCTreeNode();
		/*
		* 析构函数
		*/
		virtual ~FCTreeNode();
		/**
		 * 获取是否可以拖入节点
		 */
		virtual bool allowDragIn();
		/**
		 * 设置是否可以拖入节点
		 */
		virtual void setAllowDragIn(bool value);
		/**
		 * 获取是否可以拖出节点
		 */
		virtual bool allowDragOut();
		/**
		 * 设置是否可以拖出节点
		 */
		virtual void setAllowDragOut(bool value);
		/**
		 * 获取复选框是否选中
		 */
		virtual bool isChecked();
		/**
		 * 设置复选框是否选中
		 */
		virtual void setChecked(bool value);
		/**
		 * 获取是否展开节点
		 */
		virtual bool isExpended();
		/**
		 * 设置是否展开节点
		 */
		virtual void setExpended(bool value);
		/**
		 * 获取文字缩进距离
		 */
		virtual int getIndent();
		/**
		 * 获取父节点
		 */
		virtual FCTreeNode* getParent();
		/**
		 * 设置父节点
		 */
		virtual void setParent(FCTreeNode *value);
		/**
		 * 获取目标列
		 */
		virtual FCGridColumn* getTargetColumn();
		/**
		 * 设置目标列
		 */
		virtual void setTargetColumn(FCGridColumn *value);
		/**
		 * 获取树视图
		 */
		virtual FCTree* getTree();
		/**
		 * 设置树视图
		 */
		virtual void setTree(FCTree *value);
		/**
		 * 获取值
		 */
		virtual String getValue();
		/**
		 * 设置值
		 */
		virtual void setValue(const String& value);
	public:
	    /**
		 * 添加节点
		 */
		void appendNode(FCTreeNode *node);
		/**
		 * 清除所有节点
		 */
		void clearNodes();
		/**
		 * 折叠节点
		 */
		void collapse();
		/**
		 * 折叠所有节点
		 */
		void collapseAll();
		/**
		 * 展开节点
		 */
		void expend();
		/**
		 * 展开所有节点
		 */
		void expendAll();
		/**
		 * 获取子节点
		 */
		ArrayList<FCTreeNode*> getChildNodes();
		/**
		 * 获取节点的索引
		 */
		int getNodeIndex(FCTreeNode *node);
		/**
		 * 获取要绘制的文本
		 */
		virtual String getPaintText();
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
		 * 获取字符型数值
		 */
		virtual String getString();
		/**
		 * 插入节点
		 */
		void insertNode(int index, FCTreeNode *node);
		/**
		 * 父节点是否可见
		 */
		bool isNodeVisible(FCTreeNode *node);
		/**
		 * 添加节点
		 */
		virtual void onAddingNode(int index);
		/**
		 * 绘制复选框
		 */
		virtual void onPaintCheckBox(FCPaint *paint, const FCRect& rect);
		/**
		 * 绘制节点
		 */
		virtual void onPaintNode(FCPaint *paint, const FCRect& rect);
		/**
		 * 重绘方法
		 */
		virtual void onPaint(FCPaint *paint, const FCRect& rect, const FCRect& clipRect, bool isAlternate);
		/**
		 * 移除节点方法
		 */
		virtual void onRemovingNode();
		/**
		 * 移除节点
		 */
		void removeNode(FCTreeNode *node);
		/**
		* 设置属性
		* @param  name  属性名称
		* @param  value  属性值
		*/
		virtual void setAttribute(const String& name, const String& value);
		/**
		 * 设置字符型数值
		 */
		virtual void setString(const String& value);
	};
}
