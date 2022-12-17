/*��������èFaceCat��� v1.0
�Ϻ����è��Ϣ�������޹�˾
 */

#ifndef __CTPDLL_H__
#define __CTPDLL_H__
#pragma once
#include "stdafx.h"
using namespace std;

typedef int(*funcAskClose)(int, int, char*, char*, double, int, char, char*);
typedef int(*funcAskCloseToday)(int, int, char*, char*, double, int, char, char*);
typedef int(*funcAskOpen)(int, int, char*, char*, double, int, char, char*);
typedef int(*funcBidClose)(int, int, char*, char*, double, int, char, char*);
typedef int(*funcBidCloseToday)(int, int, char*, char*, double, int, char, char*);
typedef int(*funcBidOpen)(int, int, char*, char*, double, int, char, char*);
typedef int(*funcCancelOrder)(int, int, char*, char*, char*);
typedef int(*funcCreate)(void);
typedef int(*funcGenerateReqID)(int);
typedef int(*funcGetAccountData)(int, char*);
typedef int(*funcGetBrokerID)(int, char*);
typedef int(*funcGetCommissionRate)(int, char *, char*);
typedef int(*funcGetDepthMarketData)(int, char*);
typedef int(*funcGetInstrumentsData)(int, char*);
typedef int(*funcGetInvestorID)(int, char*);
typedef int(*funcGetMarginRate)(int, char *, char*);
typedef int(*funcGetPositionData)(int, char*);
typedef int(*funcGetPositionDetailData)(int, char*);
typedef int(*funcGetOrderInfo)(int, char*);
typedef int(*funcGetOrderInfos)(int, char*);
typedef int(*funcGetPassword)(int, char*);
typedef int(*funcGetSessionID)(int);
typedef int(*funcGetTradeRecord)(int, char*);
typedef int(*funcGetTradeRecords)(int, char*);
typedef int(*funcGetTradingDate)(int, char*);
typedef int(*funcGetTradingTime)(int , char *);
typedef int(*funcHasNewDatas)(int);
typedef int(*funcIsClearanced)(int);
typedef int(*funcIsClearanceTime)(int);
typedef int(*funcIsDataOk)(int);
typedef int(*funcIsMdLogined)(int);
typedef int(*funcIsTdLogined)(int);
typedef int(*funcIsTradingTime)(int);
typedef int(*funcIsTradingTimeExact)(int, char*);
typedef int(*funcReqCommissionRate)(int, char*, int);
typedef int(*funcReqQrySettlementInfoConfirm)(int, int);
typedef int(*funcReqQrySettlementInfo)(int, int, char*);
typedef int(*funcReqMarginRate)(int, char*, int);
typedef int(*funcStart)(int, int, char *, char*, char*, char*, char*, char*, char*);
typedef int(*funcSubMarketDatas)(int, int, char*);
typedef int(*funcUnSubMarketDatas)(int, int, char*);

class CTPDLL{
public:
	static void init();
public:
	/*
	��ƽ���൥ƽ��
	ctpID ΨһID
	requestID ����ID
	code ����
	exchangeID ������ID
	price �۸�
	qty ����
	timeCondition ��Ч�� 
	orderRef ������Ϣ 
	*/
	static int askClose(int ctpID, int requestID, char *code, char *exchangeID, double price, int qty, char timeCondition, char *orderRef);
	/*
	��ƽ��֣�ƽ����Ŀ��ֵĿյ�
	ctpID ΨһID
	requestID ����ID
	code ����
	exchangeID ������ID
	price �۸�
	qty ����
	timeCondition ��Ч��
	orderRef ������Ϣ
	*/
	static int askCloseToday(int ctpID, int requestID, char *code, char *exchangeID, double price, int qty, char timeCondition, char *orderRef);
	/*
	�������յ�����
	ctpID ΨһID
	requestID ����ID
	code ����
	exchangeID ������ID
	price �۸�
	qty ����
	timeCondition ��Ч��
	orderRef ������Ϣ
	*/
	static int askOpen(int ctpID, int requestID, char *code, char *exchangeID, double price, int qty, char timeCondition, char *orderRef);
	/*
	��ƽ���յ�ƽ��
	ctpID ΨһID
	requestID ����ID
	code ����
	exchangeID ������ID
	price �۸�
	qty ����
	timeCondition ��Ч��
	orderRef ������Ϣ
	*/
	static int bidClose(int ctpID, int requestID, char* code, char *exchangeID, double price, int qty, char timeCondition, char* orderRef);
	/*
	��ƽ��֣�ƽ����Ŀ��ֵĿյ�
	ctpID ΨһID
	requestID ����ID
	code ����
	exchangeID ������ID
	price �۸�
	qty ����
	timeCondition ��Ч��
	orderRef ������Ϣ
	*/
	static int bidCloseToday(int ctpID, int requestID, char* code, char *exchangeID, double price, int qty, char timeCondition, char* orderRef);
	/*
	�򿪣��൥����
	ctpID ΨһID
	requestID ����ID
	code ����
	exchangeID ������ID
	price �۸�
	qty ����
	timeCondition ��Ч��
	orderRef ������Ϣ
	*/
	static int bidOpen(int ctpID, int requestID, char *code, char *exchangeID, double price, int qty, char timeCondition, char *orderRef);
	/*
	����
	ctpID ΨһID
	requestID ����ID
	exchangeID ������ID
	orderSysID ί�б��
	orderRef ������Ϣ
	*/
	static int cancelOrder(int ctpID, int requestID, char *exchangeID, char *orderSysID, char *orderRef);
	/*
	��������
	*/
	static int create();
	/*
	����ctp������
	ctpID ΨһID
	*/
	static int generateReqID(int ctpID);
	/*
	��ȡ�ʽ��˻���Ϣ
	ctpID ΨһID
	data ��������
	*/
	static int getAccountData(int ctpID, char *data);
	/*
	��ȡ���͹�˾ID
	ctpID ΨһID
	data ��������
	*/
	static int getBrokerID(int ctpID, char *data);
	/*
	��ȡ��������
	ctpID ΨһID
	code ����
	data ��������
	*/
	static int getCommissionRate(int ctpID, char *code, char *data);
	/*
	��ȡ����г�����
	ctpID ΨһID
	data ��������
	*/
	static int getDepthMarketData(int ctpID, char *data);
	/*
	��ȡ��Լ����
	ctpID ΨһID
	data ��������
	*/
	static int getInstrumentsData(int ctpID, char *data);
	/*
	��ȡͶ����ID
	ctpID ΨһID
	data ��������
	*/
	static int getInvestorID(int ctpID, char* data);
	/*
	��ȡ��֤����
	ctpID ΨһID
	code ����
	data ��������
	*/
	static int getMarginRate(int ctpID, char* code, char* data);
	/*
	��ȡͶ���ֲ߳�����
	ctpID ΨһID
	data ��������
	*/
	static int getPositionData(int ctpID, char* data);
	/*
	��ȡͶ���ֲ߳���ϸ����
	ctpID ΨһID
	data ��������
	*/
	static int getPositionDetailData(int ctpID, char* data);
	/*
	��ȡ���µ�ί�лر�����һ��)
	ctpID ΨһID
	data ��������
	*/
	static int getOrderInfo(int ctpID, char* data);
	/*
	��ȡ���е�����ί�лر������������ί�У�
	ctpID ΨһID
	data ��������
	*/
	static int getOrderInfos(int ctpID, char* data);
	/*
	��ȡͶ��������
	ctpID ΨһID
	data ��������
	*/
	static int getPassword(int ctpID, char* data);
	/*
	��ȡsessionID
	ctpID ΨһID
	*/
	static int getSessionID(int ctpID);
	/*
	��ȡ���³ɽ���¼����һ����
	ctpID ΨһID
	data ��������
	*/
	static int getTradeRecord(int ctpID, char* data);
	/*
	��ȡ���½��׼�¼����������н��ף�
	ctpID ΨһID
	data ��������
	*/
	static int getTradeRecords(int ctpID, char* data);
	/* 
	��ȡ��������
	ctpID ΨһID
	data ��������
	*/
	static int getTradingDate(int ctpID, char* data);
	/*
	��ȡ����ʱ��
	ctpID ΨһID
	data ��������
	*/
	static int getTradingTime(int ctpID, char* data);
	/*
	�Ƿ�����������
	ctpID ΨһID
	*/
	static int hasNewDatas(int ctpID);
	/*
	�����Ƿ��Ѿ�����
	ctpID ΨһID
	*/
	static int isClearanced(int ctpID);
	/*
	�Ƿ��ǽ���ʱ��
	ctpID ΨһID
	*/
	static int isClearanceTime(int ctpID);
	/*
	�����Ƿ�ok
	ctpID ΨһID
	*/
	static int isDataOk(int ctpID);
	/*
	�������ݷ������Ƿ��Ѿ���¼
	ctpID ΨһID
	*/
	static int isMdLogined(int ctpID);
	/*
	�����Ƿ��Ѿ���¼
	ctpID ΨһID
	*/
	static int isTdLogined(int ctpID);
	/*
	�Ƿ��ǽ���ʱ��
	ctpID ΨһID
	*/
	static int isTradingTime(int ctpID);
	/*
	�Ƿ��Ǿ�ȷ����ʱ��(ȥ�����Ͼ���ʱ�����Ϣʱ��)
	ctpID ΨһID
	code ����
	*/
	static int isTradingTimeExact(int ctpID, char* code);
	/*
	������������
	ctpID ΨһID
	code ����
	requestID ����ID
	*/
	static int reqCommissionRate(int ctpID, char* code, int requestID);
	/*
	����ȷ�Ͻ�����Ϣ
	ctpID ΨһID
	requestID ����ID
	*/
	static int reqQrySettlementInfoConfirm(int ctpID, int requestID);
	/*
	���������Ϣ
	ctpID ΨһID
	requestID ����ID
	tradingDate ������
	*/
	static int reqQrySettlementInfo(int ctpID, int requestID, char* tradingDate);
	/*
	����֤����
	ctpID ΨһID
	code ����
	requestID ����ID
	*/
	static int reqMarginRate(int ctpID, char* code, int requestID);
	/*
	��������������(��create��ִ��)
	ctpID ΨһID
	requestID ����ID
	appID APPID
	authCode �û�ID
	mdServer �����ַ
	tdServer ���׵�ַ
	brokerID ������
	investorID Ͷ�����˺�
	password ����
	*/
	static int start(int ctpID, int requestID, char *appID, char *authCode, char* mdServer, char* tdServer, char* brokerID, char* investorID, char* password);
	/*
	���Ķ����Լ����������
	ctpID ΨһID
	requestID ����ID
	codes �����б�
	*/
	static int subMarketDatas(int ctpID, int requestID, char* codes);
	/*
	ȡ�����Ķ����Լ����������
	ctpID ΨһID
	requestID ����ID
	codes �����б�
	*/
	static int unSubMarketDatas(int ctpID, int requestID, char* codes);
};

#endif