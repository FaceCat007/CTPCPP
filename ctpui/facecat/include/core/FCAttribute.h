/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCATTRIBUTE_H__
#else                                                                            
#define __FCATTRIBUTE_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"

namespace FaceCat{
	/*
	* 属性
	*/
	class __FCATTRIBUTE_H__ FCAttribute{
	public:
		/**
         * 调用方法
         * @param funcName  方法名称
         * @param parameters 参数
        */
		virtual String callFunction(const String& funcName, const String& parameters){
			return L"";
		}
	    /**
         * 根据属性名称获取属性值
         * @param name  属性名称
         * @param value 返回属性值
         * @param type  返回属性类型
        */
		virtual void getAttribute(const String& name, String *value, String *type){
		}
		/**
		 * 获取属性名称列表
		 */
		virtual ArrayList<String> getAttributeNames(){
			ArrayList<String> attributeNames;
			return attributeNames;
		}
		/**
         * 获取方法列表
         */
        virtual ArrayList<String> getEventNames(){
            ArrayList<String> eventNames;
            return eventNames;
        }
	    /**
         * 设置属性值
         * @param name  属性名称
         * @param value 属性值
        */
		virtual void setAttribute(const String& name, const String& value){
		}
	};
}