/*
 * FaceCat框架(非开源)
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __UIEVENT_H__
#else                                                                            
#define __UIEVENT_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCUIScript.h"
#include "FCUIXml.h"
#include "..\\core\\FCLib.h"

namespace FaceCat{
	class FCUIScript;
	class FCUIXml;

	/*
	* 事件信息
	*/
	class __UIEVENT_H__ FCEventInfo{
	private:
	    /**
		 * 方法
		 */
		HashMap<String, String> m_functions;
	public:
		/*
		* 构造函数
		*/
		FCEventInfo();
		/*
		* 析构函数
		*/
		virtual ~FCEventInfo();
	public:
		/**
		* 添加事件
		* @params eventName  事件ID
		* @params function  方法
		*/
		void addEvent(String eventName, const String& function);
		/**
		 * 获取方法
		 */
		String getFunction(String eventName);
		/**
		 * 移除事件
		 */
		void removeEvent(String eventName);
	};

	/*
	* 事件
	*/
	class __UIEVENT_H__ FCUIEvent : public FCEventCallBack, public FCTouchEventCallBack, public FCInvokeEventCallBack, 
        public FCKeyEventCallBack, public FCPaintEventCallBack, public FCTimerEventCallBack, 
        public FCGridCellEventCallBack, public FCGridCellTouchEventCallBack, 
        public FCMenuItemTouchEventCallBack, public FCWindowClosingEventCallBack{
	private:
	    /**
		 * 脚本
		 */
		FCUIScript *m_script;
		/**
		 * 发送者
		 */
		String m_sender;
		/*
         * 点击对象
         */
        FCTouchInfo m_touchInfo;
		/**
		 * XML对象
		 */
		FCUIXml *m_xml;
	public:
	    /**
		 * 事件集合
		 */
		map<FCView*, FCEventInfo*> m_events;
	public:
	    /**
		 * 创建事件
		 */
		FCUIEvent(FCUIXml *xml);
		/*
		* 析构函数
		*/
		virtual ~FCUIEvent();
		/**
		 * 获取脚本
		 */
		FCUIScript* getScript();
		/**
		 * 设置脚本
		 */
		void setScript(FCUIScript *value);
		/**
		 * 获取发送者
		 */
		String getSender();
		/**
		 * 设置发送者
		 */
		void setSender(const String& value);
		/*
         * 获取触摸的点击信息
         */
        FCTouchInfo getTouchInfo();
        /*
         * 设置触摸的点击信息
         */
        void setTouchInfo(FCTouchInfo value);
		/**
		 * 获取XML对象
		 */
		FCUIXml* getXml();
		/**
		 * 设置XML对象
		 */
		void setXml(FCUIXml *value);
	public:
		/*
		* 调用服务
		*/
        static String callFunction(Object sender, String eventName, Object pInvoke);
		/*
		* 调用事件
		*/
		void callEvent(String eventName, Object sender, Object invoke) {
            callFunction(sender, eventName, invoke);
		}
		/*
		* 调用跨线程事件
		*/
        void callInvokeEvent(String eventName, Object sender, Object args, Object invoke) {
            callFunction(sender, eventName, invoke);
        }
		/*
		* 调用键盘事件
		*/
        void callKeyEvent(String eventName, Object sender, char key, Object invoke) {
            callFunction(sender, eventName, invoke);
        }
		/*
		* 调用触摸事件
		*/
        void callTouchEvent(String eventName, Object sender, FCTouchInfo touchInfo, Object invoke) {
			m_touchInfo = touchInfo;
            callFunction(sender, eventName, invoke);
        }
		/*
		* 调用绘图事件
		*/
        bool callPaintEvent(String eventName, Object sender, FCPaint *paint, const FCRect& clipRect, Object invoke) {
            callFunction(sender, eventName, invoke);
            return false;
        }
		/*
		* 调用秒表事件
		*/
        void callTimerEvent(String eventName, Object sender, int timerID, Object invoke) {
            callFunction(sender, eventName, invoke);
        }
		/*
		* 调用单元格事件
		*/
        void callGridCellEvent(String eventName, Object sender, FCGridCell *cell, Object invoke) {
            callFunction(sender, eventName, invoke);
        }
		/*
		* 调用单元格触摸事件
		*/
        void callGridCellTouchEvent(String eventName, Object sender, FCGridCell *cell, FCTouchInfo touchInfo, Object invoke) {
            callFunction(sender, eventName, invoke);
        }
		/*
		* 调用菜单触摸事件
		*/
        void callMenuItemTouchEvent(String eventName, Object sender, FCMenuItem *item, FCTouchInfo touchInfo, Object invoke) {
            callFunction(sender, eventName, invoke);
        }
		/*
		* 调用窗体关闭事件
		*/
        void callWindowClosingEvent(String eventName, Object sender, bool *cancel, Object invoke) {
            callFunction(sender, eventName, invoke);
        }
		/**
		 * 添加事件
		 */
		virtual void addEvent(FCView *view, const String& eventName, const String& function);
	};
}