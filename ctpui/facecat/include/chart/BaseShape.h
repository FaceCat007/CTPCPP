/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __BASESHAPE_H__
#else                                                                            
#define __BASESHAPE_H__ _declspec(dllexport) 
#endif

#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCPaint.h"
#include "Enums.h"
#include "FCChart.h"
#include "ChartDiv.h"
#include "FCDataTable.h"

namespace FaceCat{
	class ChartDiv;
	class FCChart;
	/**
     * 所有线条的父类
     */
	class __BASESHAPE_H__ BaseShape : public FCAttribute{
	public:
		/*
		* 扩展颜色字段
		*/
		ArrayList<Long> m_extendColors;
		/*
		* 扩展字段
		*/
		ArrayList<int> m_extendFields;
	public:
		/*
		*是否允许用户绘图
		*/
		bool m_allowUserPaint;
		/*
		*依附于左轴还是右轴
		*/
		AttachVScale m_attachVScale;
		/*
		*是否填充满Y轴
		*/
		bool m_fillVScale;
		/*
		* 名称
		*/
		String m_name;
		/*
		*是否选中
		*/
		bool m_selected;
		/*
		* 标题
		*/
		String m_title;
		/*
		*是否可见
		*/
		bool m_visible;
		/*
		*绘图顺序
		*/
		int m_zOrder;
	public:
		/*
		* 构造函数
		*/
		BaseShape();
		/*
		* 析构函数
		*/
		virtual ~BaseShape();
		/**
	     * 获取是否允许用户绘图
	     */
		virtual bool allowUserPaint();
		/**
	     * 设置是否允许用户绘图
	     */
		virtual void setAllowUserPaint(bool value);
		/**
	     * 获取依附于左轴还是右轴
	     */
		virtual AttachVScale getAttachVScale();
		/**
	     * 设置依附于左轴还是右轴
	     */
		virtual void setAttachVScale(AttachVScale value);
		/*
		* 获取是否填充满Y轴
		*/
		virtual bool fillVScale();
		/*
		* 设置是否填充满Y轴
		*/
		virtual void setFillVScale(bool value);
		/*
		* 获取名称
		*/
		virtual String getName();
		/*
		* 设置名称
		*/ 
		virtual void setName(String value);
		/**
	     *  获取是否被选中
	     */
		virtual bool isSelected();
		/**
	     *  设置是否被选中
	     */
		virtual void setSelected(bool value);
		/**
	     *  获取是否被选中
	     */
		virtual String getTitle();
		/**
	     *  设置是否被选中
	     */
		virtual void setTitle(String value);

		/**
	     * 获取图形是否可见
	     */
		virtual bool isVisible();
		/**
	     * 设置图形是否可见
	     */
		virtual void setVisible(bool value);
		/**
	     * 获取绘图顺序
	     */
		virtual int getZOrder();
		/**
	     * 设置绘图顺序
	     */
		virtual void setZOrder(int value);
	public:
	    /**
	     * 获取基础字段
	     */
		virtual int getBaseField();
	    /**
        * 由字段名称获取字段标题
        * @param fieldName  字段名称
        * @returns 字段标题
        */
		virtual String getFieldText(int fieldName);
		/**
	     * 获取所有字段
	     */
		virtual int* getFields(int *length);
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
	     * 获取选中点的颜色
	     */
		virtual Long getSelectedColor();
	    /**
        * 重绘方法
        * @param paint  绘图对象
        * @param div    图层
        * @param rect   区域
        */
		virtual void onPaint(FCPaint *paint, ChartDiv *div, const FCRect& rect);
	    /**
        * 设置属性值
        * @param name  属性名称
        * @param value 属性值
        */
		virtual void setAttribute(const String& name, const String& value);
	};

	/*
	* K线
	*/
	class __BASESHAPE_H__ CandleShape : public BaseShape{
	public:
		/**
	     * 收盘价字段
	     */
		int m_closeField;
		/**
	     * 收盘价的显示文字
	     */
		String m_closeFieldText;
		/**
	     * 颜色的字段
	     */
		int m_colorField;
		/**
	     * 阴线的颜色
	     */
		Long m_downColor;
		/**
	     * 最高价字段
	     */
		int m_highField;
		/**
	     * 最高价的显示文字
	     */
		String m_highFieldText;
		/**
	     * 最低价字段
	     */
		int m_lowField;
		/**
	     * 最低价的显示文字
	     */
		String m_lowFieldText;
		/*
		* 中间的颜色
		*/
		Long m_midColor;
		/**
	     * 开盘价字段
	     */
		int m_openField;
		/**
	     * 开盘价的显示文字
	     */
		String m_openFieldText;
		/**
	     * 是否显示最大最小值
	     */
		bool m_showMaxMin;
		/*
		* 样式
		*/
		CandleStyle m_style;
		/**
	     * 样式字段
	     */
		int m_styleField;
		/**
	     * 最大最小值标签的颜色
	     */
		Long m_tagColor;
		/**
	     * 阳线颜色
	     */
		Long m_upColor;
	public:
		/*
		* 构造函数
		*/
		CandleShape();
		/**
	     *  获取颜色的字段
	     */
		int getCloseField();
		/**
	     *  设置颜色的字段
	     */
		void setCloseField(int value);
		/**
	     * 获取收盘价的显示文字
	     */
		String getCloseFieldText();
		/**
	     * 设置收盘价的显示文字
	     */
		void setCloseFieldText(const String& value);
		/**
	     *  获取颜色的字段
	     */
		int getColorField();
		/**
	     *  设置颜色的字段
	     */
		void setColorField(int value);
		/**
	     * 获取阴线的颜色
	     */
		Long getDownColor();
		/**
	     * 设置阴线的颜色
	     */
		void setDownColor(Long value);
		/**
	     * 获取最高价字段
	     */
		int getHighField();
		/**
	     * 设置最高价字段
	     */
		void setHighField(int value);
		/**
	     * 获取最高价的显示文字
	     */
		String getHighFieldText();
		/**
	     * 设置最高价的显示文字
	     */
		void setHighFieldText(const String& value);
		/**
	     * 获取最低价字段
	     */
		int getLowField();
		/**
	     * 设置最低价字段
	     */
		void setLowField(int value);
		/**
	     * 获取最低价的显示文字
	     */
		String getLowFieldText();
		/**
	     * 设置最低价的显示文字
	     */
		void setLowFieldText(const String& value);
		/*
		* 获取中间的颜色
		*/
		Long getMidColor();
		/*
		* 设置中间的颜色
		*/
		void setMidColor(Long value);
		/**
	     * 获取开盘价字段
	     */
		int getOpenField();
		/**
	     * 设置开盘价字段
	     */
		void setOpenField(int value);
		/**
	     * 获取开盘价的显示文字
	     */
		String getOpenFieldText();
		/**
	     * 设置开盘价的显示文字
	     */
		void setOpenFieldText(const String& value);
		/**
	     * 获取是否显示最大最小值
	     */
		bool getShowMaxMin();
		/**
	     * 设置是否显示最大最小值
	     */
		void setShowMaxMin(bool value);
		/**
	     * 获取线柱的类型
	     */
		CandleStyle getStyle();
		/**
	     * 设置线柱的类型
	     */
		void setStyle(CandleStyle value);
		/**
	     * 获取样式字段
	     */
		int getStyleField();
		/**
	     * 设置样式字段
	     */
		void setStyleField(int value);
		/**
	     * 获取最大最小值标签的颜色
	     */
		Long getTagColor();
		/**
	     * 设置最大最小值标签的颜色
	     */
		void setTagColor(Long value);
		/**
	     * 获取阳线颜色
	     */
		Long getUpColor();
		/**
	     * 设置阳线颜色
	     */
		void setUpColor(Long value);
	public:
	    /**
	     * 获取基础字段
	     */
		virtual int getBaseField();
	    /**
         * 由字段名称获取字段标题
         * @param fieldName  字段名称
         * @returns 字段标题
        */
		virtual String getFieldText(int fieldName);
		/**
	     * 获取所有字段
	     */
		virtual int* getFields(int *length);
	    /**
         * 设置属性值
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
        *获取选中点的颜色
        * @returns 颜色
        */
		virtual Long getSelectedColor();
	    /**
         * 获取属性值
         * @param name  属性名称
         * @param value 属性值
        */
		virtual void setAttribute(const String& name, const String& value);
	};

	/*
	* 柱状图
	*/
	class __BASESHAPE_H__ BarShape : public BaseShape{
	public:
	    /**
	     * 颜色的字段
	     */
		int m_colorField;
		/**
	     * 阴线的颜色
	     */
		Long m_downColor;
		/**
	     * 字段名称
	     */
		int m_fieldName;
		/**
	     * 字段名称2
	     */
		int m_fieldName2;
		/**
	     * 显示的标题名称
	     */
		String m_fieldText;
		/**
	     * 显示的标题名称2
	     */
		String m_fieldText2;
		/**
	     * 线的宽度
	     */
		float m_lineWidth;
		/**
	     * 条的样式
	     */
		BarStyle m_style;
		/**
	     * 样式字段
	     */
		int m_styleField;
		/**
	     * 阳线的颜色
	     */
		Long m_upColor;
	public:
		/*
		* 构造函数
		*/
		BarShape();
		/**
	     * 获取颜色的字段
	     */
		int getColorField();
		/**
	     * 设置颜色的字段
	     */
		void setColorField(int value);
		/**
	     * 获取阴线的颜色
	     */
		Long getDownColor();
		/**
	     * 设置阴线的颜色
	     */
		void setDownColor(Long value);
		/**
	     * 获取字段名称
	     */
		int getFieldName();
		/**
	     * 设置字段名称
	     */
		void setFieldName(int value);
		/**
	     * 获取字段名称2
	     */
		int getFieldName2();
		/**
	     * 设置字段名称2
	     */
		void setFieldName2(int value);
		/**
	     *  获取显示的标题名称
	     */
		String getFieldText();
		/**
	     *  设置显示的标题名称
	     */
		void setFieldText(const String& value);
		/**
	     * 获取显示的标题名称2
	     */
		String getFieldText2();
		/**
	     * 设置显示的标题名称2
	     */
		void setFieldText2(const String& value);
		/**
	     * 获取线的宽度
	     */
		float getLineWidth();
		/**
	     * 设置线的宽度
	     */
		void setLineWidth(float value);
		/**
	     * 获取线条的样式
	     */
		BarStyle getStyle();
		/**
	     * 设置线条的样式
	     */
		void setStyle(BarStyle value);
		/**
	     * 获取样式字段
	     */
		int getStyleField();
		/**
	     * 设置样式字段
	     */
		void setStyleField(int value);
		/**
	     * 获取阳线的颜色
	     */
		Long getUpColor();
		/**
	     * 设置阳线的颜色
	     */
		void setUpColor(Long value);
	public:
	    /**
	     * 获取基础字段
	     */
		virtual int getBaseField();
	    /**
		 * 由字段名称获取字段标题
		 * @param fieldName  字段名称
		 * @returns 字段标题
        */
		virtual String getFieldText(int fieldName);
		/**
	     * 获取所有字段
	     */
		virtual int* getFields(int *length);
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
        *获取选中点的颜色
        * @returns 颜色
        */
		virtual Long getSelectedColor();
	    /**
		 * 设置属性值
		 * @param name  属性名称
		 * @param value 属性值
        */
		virtual void setAttribute(const String& name, const String& value);
	};

	/*
	* 线条
	*/
	class __BASESHAPE_H__ PolylineShape : public BaseShape{
	public:
	    /**
	     * 线的颜色
	     */
		Long m_color;
		/**
	     * 颜色的字段
	     */
		int m_colorField;
		/**
	     * 字段名称
	     */
		int m_fieldName;
		/**
	     * 显示的标题名称
	     */
		String m_fieldText;
		/**
	     * 填充色
	     */
		Long m_fillColor;
		/**
	     * 样式
	     */
		PolylineStyle m_style;
		/**
	     * 线的宽度
	     */
		float m_width;
	public:
		/*
		* 构造函数
		*/
		PolylineShape();
		/**
	     * 获取线的颜色
	     */
		Long getColor();
		/**
	     * 设置线的颜色
	     */
		void setColor(Long color);
		/**
	     * 获取颜色的字段
	     */
		int getColorField();
		/**
	     * 设置颜色的字段
	     */
		void setColorField(int colorField);
		/**
	     * 获取字段名称
	     */
		int getFieldName();
		/**
	     * 设置字段名称
		 * @param fieldName 字段名称
	     */
		void setFieldName(int fieldName);
		/**
	     * 获取显示的标题名称
	     */
		String getFieldText();
		/**
	     * 设置显示的标题名称
		 * @param fieldText 标题名称
	     */
		void setFieldText(const String& fieldText);
		/**
	     * 获取填充色
	     */
		Long getFillColor();
		/**
	     * 设置填充色
	     */
		void setFillColor(Long fillColor);
		/**
	     * 获取样式
	     */
		PolylineStyle getStyle();
		/**
	     * 设置样式
	     */
		void setStyle(PolylineStyle style);
		/**
	     * 获取线的宽度
	     */
		float getWidth();
		/**
	     * 设置线的宽度
	     */
		void setWidth(float width);
	public:
	    /**
	     * 获取基础字段
	     */
		virtual int getBaseField();
		/**
	     * 由字段名称获取字段标题
	     */
		virtual String getFieldText(int fieldName);
		/**
	     * 获取所有字段
	     */
		virtual int* getFields(int *length);
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
	     * 获取选中点的颜色
	     */
		virtual Long getSelectedColor();
		/**
	     * 设置属性
	     */
		virtual void setAttribute(const String& name, const String& value);
	};

	/*
	* 文字
	*/
	class __BASESHAPE_H__ TextShape:public BaseShape{
	public:
	    /**
	     * 颜色字段
	     */
		int m_colorField;
		/**
	     * 字段
	     */
		int m_fieldName;
		/**
	     * 字体
	     */
		FCFont *m_font;
		/**
	     * 样式字段
	     */
		int m_styleField;
		/**
	     * 绘制的文字
	     */
		String m_text;
		/**
	     * 绘制的文字
	     */
		Long m_textColor;
	public:
		/*
		* 构造函数
		*/
		TextShape();
		/**
	     * 创建文字
	     */
		virtual ~TextShape();
		/**
	     * 获取颜色字段
	     */
		int getColorField();
		/**
	     * 设置颜色字段
	     */
		void setColorField(int colorField);
		/**
	     * 获取字段
	     */
		int getFieldName();
		/**
	     * 设置字段
	     */
		void setFieldName(int fieldName);
		/**
	     * 获取字体
	     */
		FCFont* getFont();
		/**
	     * 设置字体
	     */
		void setFont(FCFont *font);
		/**
	     * 获取样式字段
	     */
		int getStyleField();
		/**
	     * 设置样式字段
	     */
		void setStyleField(int styleField);
		/**
	     * 获取绘制的文字
	     */
		String getText();
		/**
	     * 设置绘制的文字
	     */
		void setText(const String& text);
		/**
	     * 获取前景色
	     */
		Long getTextColor();
		/**
	     * 设置前景色
	     */
		void setTextColor(Long textColor);
	public:
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
		/*
		* 处理缩放
		*/
		virtual void onScaling(double scaleFactorX, double scaleFactorY);
	    /**
         * 设置属性值
         * @param name  属性名称
         * @param value 属性值
        */
		virtual void setAttribute(const String& name, const String& value);
	};
}