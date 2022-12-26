/*基于捂脸猫FaceCat框架 v1.0
上海卷卷猫信息技术有限公司
 */

#ifndef __MAINFRAME_H__
#define __MAINFRAME_H__
#pragma once
#include "stdafx.h"
#include "..\\facecat\\include\\xml\\FCUIXml.h"
#include "..\\..\\CStr.h"
#include "..\\..\\CTPDLL.h"
#include "..\\..\\Security.h"

/*
* 主窗体框架
*/
class MainFrame : public FCUIXml, public FCTouchEventCallBack, public FCGridCellTouchEventCallBack, public FCTimerEventCallBack{
public:
	/*
	* 构造函数
	*/
	MainFrame();
	/*
	* 析构函数
	*/
	virtual ~MainFrame();
public:
	/*
	* 加载文件
	* fileName 文件名
	* view 视图
	*/
	virtual void loadFile(const String& fileName, FCView *view);
	/*
    * 交易ID
    */
    int m_ctpID;
    
    /*
    * 秒表ID
    */
    int m_timerID;
    
    /*
    * 当前代码
    */
    String m_currentCode;
	/*
    * 所有的代码信息
    */
    map<String, Security> m_allCodes;
    /*
    * 所有的行情信息
    */
    map<String, SecurityLatestData> m_allDatas;
	/*
    * 表格点击方法
    * eventName 事件名称
    * sender 触发对象
    * cell 单元格
    * touchInfo 触摸参数
    * invoke 引用对象
    */
    virtual void callGridCellTouchEvent(String eventName, Object sender, FCGridCell *cell, FCTouchInfo touchInfo, Object invoke);
	/**
     * 秒表事件
     * 
     * @param eventName 事件名称
     * @param sender 发送者
     * @param timerID 秒表ID
     * @param invoke 引用对象
     */
    virtual void callTimerEvent(String eventName, Object sender, int timerID, Object invoke);
	/*
    * 运行方法
    */
    void checkCTPData();
	/*
    * 登陆到CTP
    * appID 应用ID
    * authCode 用户ID
    * mdServer 行情服务器
    * tdServer 交易服务器
    * brokerID 机构号
    * investorID 投资者账号
    * password 密码
    */
    void loginCTP(String appID, String authCode, String mdServer, String tdServer, String brokerID, String investorID, String password);
	/*
    * 点击事件
    * eventName 事件名称
    * sender 调用对象
    * touchInfo 触摸信息
    * invoke 引用对象
    */
    virtual void callTouchEvent(String eventName, Object sender, FCTouchInfo touchInfo, Object invoke);
	/*
    * 资金账户信息回调
    * data 资金信息
    * ctpID 交易ID
    */
	void onAccountDataCallBack(AccountData *data, int ctpID);
	/*
    * 设置单元格的样式
    * cell 单元格
    * value1 数值1
    * value2 数值2
    */
	void setCellStyle2(FCGridCell *cell, double value1, double value2);
	/*
    * 最新数据回调
    * data 最新数据集合
    * ctpID 交易ID
    */
    void onSecurityLatestDataCallBack(vector<SecurityLatestData> *data, int ctpID);
	/*
    * 推送的交易信息回调
    * data 成交回报
    * ctpID 交易ID
    */
    void onTradeRecordCallBack(TradeRecord *data, int ctpID);
	/*
    * 主动查询的交易信息回调
    * data 成交回报集合
    * ctpID 交易ID
    */
    void onTradeRecordsCallBack(vector<TradeRecord> *data, int ctpID);
	/*
    * 推送的委托回报回调
    * data 委托回报
    * ctpID 交易ID
    */
    void onOrderInfoCallBack(OrderInfo *data, int ctpID);
	/*
    * 主动查询的委托回报回调
    * data 委托回报集合
    * ctpID 交易ID
    */
    void onOrderInfosCallBack(vector<OrderInfo> *data, int ctpID);
	/*
    * 持仓明细数据回调
    * data 持仓明细数据
    * ctpID 交易ID
    */
    void onInvestorPositionDetailCallBack(vector<InvestorPositionDetail> *data, int ctpID);
	/*
    * 持仓数据回调
    * data 持仓数据
    * ctpID 交易ID
    */
    void onInvestorPositionCallBack(vector<InvestorPosition> *data, int ctpID);
	/*
    * 码表回调
    * data 码表集合
    * ctpID 交易ID
    */
    void onSecurityCallBack(vector<Security> *data, int ctpID);
};


#endif