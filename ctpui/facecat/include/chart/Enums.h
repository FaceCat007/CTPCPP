/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __ENUMS_H__
#else                                                                            
#define __ENUMS_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"

namespace FaceCat{
	/*
	* 动作类型
	*/
	enum _declspec(dllexport) ActionType{
		ActionType_AT1 = 1, //第一个点的动作
		ActionType_AT2 = 2, //第二个点的动作
		ActionType_AT3 = 3, //第三个点的动作
		ActionType_AT4 = 4, //第四个点的动作
		ActionType_MOVE = 0, //移动
		ActionType_NO = -1 //不移动
	};

	/*
	* 纵轴的类型
	*/
	enum _declspec(dllexport) AttachVScale{
		AttachVScale_Left, //左轴
		AttachVScale_Right //右轴
	};

	/*
	* 柱状图样式
	*/
	enum _declspec(dllexport) BarStyle{
		BarStyle_Line, //线条
		BarStyle_Rect //矩形
	};

	/*
	* 线的样式
	*/
	enum _declspec(dllexport) CandleStyle{
		CandleStyle_American, //美国线
		CandleStyle_CloseLine, //收盘线
		CandleStyle_Rect, //矩形
		CandleStyle_Tower //宝塔线
	};

	/*
	* 十字线的移动方式
	*/
	enum _declspec(dllexport) CrossLineMoveMode{
		CrossLineMoveMode_AfterClick, //触摸点击后移动
		CrossLineMoveMode_FollowTouch //跟随触摸
	};

	/*
	* 日期的类型
	*/
	enum _declspec(dllexport) DateType{
		DateType_Day = 2, //日
		DateType_Hour = 3, //小时
		DateType_Millisecond = 6, //毫秒
		DateType_Minute = 4, //分钟
		DateType_Month = 1, //月
		DateType_Second = 5, //秒
		DateType_Year = 0 //年
	};

	/*
	* X轴的类型
	*/
	enum _declspec(dllexport) HScaleType{
		HScaleType_Date, //日期
		HScaleType_Number //数字
	};

	/*
	* 数字的样式
	*/
	enum _declspec(dllexport) NumberStyle{
		NumberStyle_Standard, //标准
		NumberStyle_Underline //加下划线数字
	};

	/*
	* 折线的样式
	*/
	enum _declspec(dllexport) PolylineStyle{
		PolylineStyle_Cycle, //圆圈
		PolylineStyle_DashLine, //虚线
		PolylineStyle_DotLine, //细点图
		PolylineStyle_SolidLine //实线
	};

	/*
	* 滚动类型
	*/
	enum _declspec(dllexport) ScrollType{
		ScrollType_None, //无
		ScrollType_Left, //向左
		ScrollType_Right, //向右
		ScrollType_ZoomIn, //缩小
		ScrollType_ZoomOut //放大
	};

	/*
	* 选中点样式
	*/
	enum _declspec(dllexport) SelectPoint{
		SelectPoint_Ellipse, //圆
		SelectPoint_Rect //矩形
	};

	/*
	* 图形标题的模式
	*/
	enum _declspec(dllexport) TextMode{
		TextMode_Field, //显示字段
		TextMode_Full, //显示完整
		TextMode_None, //不显示
		TextMode_Value //显示值
	};

	/*
	* 纵轴坐标系
	*/
	enum _declspec(dllexport) VScaleSystem{
		VScaleSystem_Logarithmic, //对数坐标
		VScaleSystem_Standard //标准
	};

	/*
	* 纵坐标轴类型
	*/
	enum _declspec(dllexport) VScaleType{
		VScaleType_Divide, //等分
		VScaleType_EqualDiff, //等差
		VScaleType_EqualRatio, //等比
		VScaleType_GoldenRatio, //黄金分割
		VScaleType_Percent //黄金分割
	};
}