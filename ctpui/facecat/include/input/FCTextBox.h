/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCTEXTBOX_H__
#else                                                                            
#define __FCTEXTBOX_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\scroll\\FCHScrollBar.h"
#include "..\\scroll\\FCVScrollBar.h"
#include "..\\div\\FCDiv.h"
#include <stack>

namespace FaceCat{
	/*
	* 行
	*/
	struct __FCTEXTBOX_H__ FCWordLine{
	public:
	    /**
		 * 结束索引
		 */
		int m_end;
		/**
		 * 开始索引
		 */
		int m_start;
		/*
         * 行号
         */
        int m_line;
		FCWordLine(int start, int end){
			m_start = start;
			m_end = end;
			m_line = 0;
		}
	};

	/*
	* 撤销重复信息
	*/
	class __FCTEXTBOX_H__ FCRedoUndoInfo
    {
	public:
		/*
		* 选中开始位置
		*/
        int m_selectionStart;

        /*
		* 选中长度
		*/
        int m_selectionLength;

        /*
		* 文字
		*/
        String m_text;

        /*
		* 创建信息
		*/
        FCRedoUndoInfo(String text, int selectionStart, int selectionLength)
        {
            m_text = text;
            m_selectionStart = selectionStart;
            m_selectionLength = selectionLength;
        }
    };

	/*
	* 文本框
	*/
	class __FCTEXTBOX_H__ FCTextBox : public FCDiv{
	private:
		/*
		* TICK值
		*/
		int m_tick;
		/**
		 * 秒表ID
		 */
		int m_timerID;
	public:
		/*
         * 改变ID
         */
        int m_changeID;
		/*
		* 光标的坐标
		*/
		FCPoint m_cursorPoint;
		/*
		* 是否正在复制
		*/
		bool m_isCopy;
	    /**
		 * 键盘是否按下
		 */
		bool m_isKeyDown;
		/**
		 * 是否触摸按下
		 */
		bool m_isTouchDown;
		/**
		 * 行高
		 */
		int m_lineHeight;
		/**
		 * 行数
		 */
		vector<FCWordLine> m_lines;
		/**
		 * 是否多行显示
		 */
		bool m_multiline;
		/**
		 * 横向偏移量
		 */
		int m_offsetX;
		/**
		 * 密码字符
		 */
		wchar_t m_passwordChar;
		/**
		 * 文字矩形范围
		 */
		vector<FCRectF> m_ranges;
		/**
		 * 重做栈
		 */
		stack<FCRedoUndoInfo> m_redoStack;
		/**
		 * 是否只读
		 */
		bool m_readOnly;
		/**
		 * 是否从右向左绘制
		 */
		bool m_rightToLeft;
		/**
		 * 选中的背景色
		 */
		Long m_selectionBackColor;
		/**
		 * 选中的前景色
		 */
		Long m_selectionTextColor;
		/**
		 * 选中长度
		 */
		int m_selectionLength;
		/**
		 * 选中开始位置
		 */
		int m_selectionStart;
		/**
		 * 是否显示光标
		 */
		bool m_showCursor;
		/**
		 * 开始移动的坐标
		 */
		int m_startMovingIndex;
		/**
		 * 结束移动的坐标
		 */
		int m_stopMovingIndex;
		/**
		 * 临时文字
		 */
		String m_tempText;
		/**
		 * 临时文字的颜色
		 */
		Long m_tempTextColor;
		/**
		 * 内容的横向排列样式
		 */
		FCHorizontalAlign m_textAlign;
		/**
		 * 文字是否改变
		 */
		bool m_textChanged;
		/**
		 * 光标闪烁频率
		 */
		int TICK;
		/**
		 * 撤销栈
		 */
		stack<FCRedoUndoInfo> m_undoStack;
		/**
		 * 文字大小
		 */
		vector<FCSizeF> m_wordsSize;
		/**
		 * 多行编辑视图是否启动换行
		 */
		bool m_wordWrap;
		/**
		 * 光标向下移动
		 */
		virtual void cursorDown();
		/**
		 * 光标移动到最右端
		 */
		virtual void cursorEnd();
		/**
		 * 光标移动到最左端
		 */
		virtual void cursorHome();
		/**
		 * 光标向左移动
		 */
		virtual void cursorLeft();
		/**
		 * 光标向右移动
		 */
		virtual void cursorRight();
		/**
		 * 光标向上移动
		 */
		virtual void cursorUp();
		/**
		 * 删除字符
		 */
		virtual void deleteWord();
		/**
		 * 插入字符
		 */
		virtual void insertWord(const String& str);
		/**
		 * 判断字符索引所在行是否可见
		 */
		virtual bool isLineVisible(int indexTop, int indexBottom, int cell, int floor, int lineHeight, double visiblePercent);
		/*
		* 判断字符索引所在行是否可见
		*/
		virtual bool isLineVisible(int index, double visiblePercent);
		/**
		 * 设置移动索引
		 */
		virtual void setMovingIndex(int sIndex, int eIndex);
	public:
		/*
		* 构造函数
		*/
		FCTextBox();
		/*
		* 析构函数
		*/
		virtual ~FCTextBox();
		/*
		* 获取光标的坐标
		*/
		virtual FCPoint getCursorPoint();
		/*
		* 设置光标的坐标
		*/
		virtual void setCursorPoint(const FCPoint& value);
		/**
		 * 获取行数
		 */
		virtual int getLinesCount();
		/**
		 * 获取行高
		 */
		virtual int getLineHeight();
		/**
		 * 设置行高
		 */
		virtual void setLineHeight(int value);
		/**
		 * 获取行数
		 */
		virtual vector<FCWordLine> getLines();
		/**
		 * 获取是否多行显示
		 */
		virtual bool isMultiline();
		/**
		 * 设置是否多行显示
		 */
		virtual void setMultiline(bool value);
		/**
		 * 获取密码字符
		 */
		virtual wchar_t getPasswordChar();
		/**
		 * 设置密码字符
		 */
		virtual void setPasswordChar(wchar_t value);
		/**
		 * 获取是否只读
		 */
		virtual bool isReadOnly();
		/**
		 * 设置是否只读
		 */
		virtual void setReadOnly(bool value);
		/**
		 * 获取是否从右向左绘制
		 */
		virtual bool isRightToLeft();
		/**
		 * 设置是否从右向左绘制
		 */
		virtual void setRightToLeft(bool value);
		/**
		 * 获取选中的背景色
		 */
		virtual Long getSelectionBackColor();
		/**
		 * 设置选中的背景色
		 */
		virtual void setSelectionBackColor(Long value);
		/**
		 * 获取选中的前景色
		 */
		virtual Long getSelectionTextColor();
		/**
		 * 设置选中的前景色
		 */
		void setSelectionTextColor(Long value);
		/**
		 * 获取选中长度
		 */
		virtual int getSelectionLength();
		/**
		 * 设置选中长度
		 */
		virtual void setSelectionLength(int value);
		/**
		 * 获取选中开始位置
		 */
		virtual int getSelectionStart();
		/**
		 * 设置选中开始位置
		 */
		virtual void setSelectionStart(int value);
		/**
		 * 获取临时文字
		 */
		virtual String getTempText();
		/**
		 * 设置临时文字
		 */
		virtual void setTempText(const String& value);
		/**
		 * 获取临时文字的颜色
		 */
		virtual Long getTempTextColor();
		/**
		 * 设置临时文字的颜色
		 */
		virtual void setTempTextColor(Long value);
		/**
		 * 获取内容的横向排列样式
		 */
		virtual FCHorizontalAlign getTextAlign();
		/**
		 * 设置内容的横向排列样式
		 */
		virtual void setTextAlign(FCHorizontalAlign value);
		/**
		 * 获取多行编辑视图是否启动换行
		 */
		virtual bool isWordWrap();
		/**
		 * 设置多行编辑视图是否启动换行
		 */
		virtual void setWordWrap(bool value);
	public:
	    /**
		 * 判断是否可以重复
		 */
		virtual bool canRedo();
		/**
		 * 判断是否可以撤销
		 */
		virtual bool canUndo();
		/**
		 * 重置
		 */
		virtual void clearRedoUndo();
		/**
		 * 获取内容的高度
		 */
		virtual int getContentHeight();
		/**
		 * 获取内容的宽度
		 */
		virtual int getContentWidth();
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
		 * 获取选中的文字
		 */
		virtual String getSelectionText();
		/**
		 * 文本输入方法
		 */
		virtual void onChar(wchar_t ch);
		/**
		 * 复制文字
		 */
		virtual void onCopy();
		/**
		 * 剪切
		 */
		virtual void onCut();
		/**
		 * 获取焦点方法
		 */
		virtual void onGotFocus();
		/**
		 * 键盘方法
		 */
		virtual void onKeyDown(char key);
		/**
		 * 键盘抬起方法
		 */
		virtual void onKeyUp(char key);
		/**
		 * 丢失焦点方法
		 */
		virtual void onLostFocus();
		/**
		 * 触摸按下方法
		 */
		virtual void onTouchDown(FCTouchInfo touchInfo);
		/**
		 * 触摸移动方法
		 */
		virtual void onTouchMove(FCTouchInfo touchInfo);
		/**
		 * 触摸抬起方法
		 */
		virtual void onTouchUp(FCTouchInfo touchInfo);
		/**
		 * 重绘前景方法
		 */
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
		/**
		 * 粘贴方法
		 */
		virtual void onPaste();
		/**
		 * 文字尺寸改变事件
		 */
		virtual void onSizeChanged();
		/**
		 * 被使用TAB切换方法
		 */
		virtual void onTabStop();
		/**
		 * 文字改变方法
		 */
		virtual void onTextChanged();
		/**
		 * 秒表回调方法
		 */
		virtual void onTimer(int timerID);
		/**
		 * 重复
		 */
		virtual void redo();
		/**
		 * 全选
		 */
		virtual void selectAll();
		/**
		* 设置属性
		* @param  name  属性名称
		* @param  value  属性值
		*/
		virtual void setAttribute(const String& name, const String& value);
		/**
		 * 撤销
		 */
		virtual void undo();
		/**
		 * 更新布局方法
		 */
		virtual void update();
	};
}