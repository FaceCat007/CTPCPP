/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCHTTPEASYSERVICE_H__
#else                                                                            
#define __FCHTTPEASYSERVICE_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCHttpMonitor.h"

using namespace std;

namespace FaceCat{
	class FCHttpData;

	/*
	* 简单的HTTP服务
	*/
	class __FCHTTPEASYSERVICE_H__ FCHttpEasyService{
	public:
	    /**
		 * HTTP的GET服务
		 */
		FCHttpEasyService();
		/*
		* 删除服务
		*/
		virtual ~FCHttpEasyService();
	public:
		/**
		* 请求数据
		* @param  data  请求数据
		*/
		virtual void onReceive(FCHttpData* data);
	};
}
