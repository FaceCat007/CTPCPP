/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCLOCK__H__
#else                                                                            
#define __FCLOCK__H__ _declspec(dllexport) 
#endif
#pragma once

namespace FaceCat
{
	/*
	* 同步锁
	*/
	class __FCLOCK__H__ FCLock
	{
	public:
		/*
		* 构造函数
		*/
		FCLock();
		/*
		* 析构函数
		*/
		~FCLock();
		/*
		* 锁
		*/
		void lock();
		/*
		* 解锁
		*/
		void unLock();
	private:
		CRITICAL_SECTION m_cs;
	};
}

