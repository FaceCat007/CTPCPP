/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __CBASE_H__
#else                                                                            
#define __CBASE_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include <string>
using namespace std;

namespace FaceCat{
	/*
	* 64位加密
	*/
	class __CBASE_H__ CBase64{  
	private:  
		/*
		* 创建加密
		*/
		CBase64();
		/*
		* 销毁对象
		*/
		virtual ~CBase64();  
	public:  
		/*
		* 加密
		*/
		static string encode(const unsigned char *Data,int DataByte);  
		/*
		* 解密
		*/
		static string decode(const char *Data,int DataByte,int& OutByte);  
	};
}
