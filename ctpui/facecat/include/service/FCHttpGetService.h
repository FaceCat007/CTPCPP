/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCHTTPGETSERVICE_H__
#else                                                                            
#define __FCHTTPGETSERVICE_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
namespace FaceCat{
    /**
	 * HTTP的GET服务
	 */
    class __FCHTTPGETSERVICE_H__ FCHttpGetService{
    public:
		static BOOL _TryHttpSendRequest(LPVOID hRequest, int nMaxTryTimes);
		static string GetHttpWebRequest(string strUrl, int bufferSize);
		/**
		* 获取网页数据
		* @param  url  地址
		*/
        static string get(const string url);
    };
}
