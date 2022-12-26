/*基于FaceCat(捂脸猫)框架 v1.0
 上海卷卷猫信息技术有限公司
 */

#ifndef __WINHOSTEX_H__
#define __WINHOSTEX_H__
#pragma once
#include "stdafx.h"
#include "GdiPlusPaintEx.h"

class ScrollButtonM : public FCButton{
public:
	int m_arrowType;
public:
    ScrollButtonM();
    virtual ~ScrollButtonM();
    virtual void onPaint(FCPaint *paint, const FCRect& clipRect);
    virtual void onPaintBorder(FCPaint *paint, const FCRect& clipRect);
};

//设备中心
class WinHostEx : public WinHost{
public:
	WinHostEx();
	virtual ~WinHostEx();
public:
	//创建内部控件
	virtual FCView* createInternalView(FCView *parent, const String& clsid);
public:
	HashMap<int, int> m_timeIDs;
	/*
	* 重启秒表
	*/
	virtual void reStartTimers();
	/**
	* 开启秒表
	* @param timerID  秒表ID
	* @param interval  间隔
	*/
    virtual void startTimer(int timerID, int interval);
	/**
	* 停止秒表
	* @param timerID  秒表ID
	*/
    virtual void stopTimer(int timerID);
};
#endif