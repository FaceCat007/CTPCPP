/*基于捂脸猫FaceCat框架 v1.0
上海卷卷猫信息技术有限公司
 */
#ifndef __CTP_H__
#define __CTP_H__
#pragma once
#include "stdafx.h"
#include "Security.h"
using namespace std;

class CTP{
private:
	int m_ctpID;
public:
	CTP();
	~CTP();
	int getCtpID();
	void run();
	void setCtpID(int ctpID);
public:
	//资金账户信息回调
	virtual void onAccountDataCallBack(AccountData *data, int ctpID);
	//持仓数据回调
	virtual void onInvestorPositionCallBack(vector<InvestorPosition> *data, int ctpID);
	//持仓数据回调
	virtual void onInvestorPositionDetailCallBack(vector<InvestorPositionDetail> *data, int ctpID);
	//推送的委托回报回调
	virtual void onOrderInfoCallBack(OrderInfo *data, int ctpID);
	//主动查询的委托回报回调
	virtual void onOrderInfosCallBack(vector<OrderInfo> *data, int ctpID);
	//码表回调
	virtual void onSecurityCallBack(vector<Security> *data, int ctpID);
	//最新数据回调
	virtual void onSecurityLatestDataCallBack(vector<SecurityLatestData> *data, int ctpID);
	//推送的交易信息回调
	virtual void onTradeRecordCallBack(TradeRecord *data, int ctpID);
	//主动查询的交易信息回调
	virtual void onTradeRecordsCallBack(vector<TradeRecord> *tradeRecords, int ctpID);
};

#endif
