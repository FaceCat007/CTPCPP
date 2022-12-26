/*��������èFaceCat��� v1.0
�Ϻ����è��Ϣ�������޹�˾
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
* ��������
*/
class MainFrame : public FCUIXml, public FCTouchEventCallBack, public FCGridCellTouchEventCallBack, public FCTimerEventCallBack{
public:
	/*
	* ���캯��
	*/
	MainFrame();
	/*
	* ��������
	*/
	virtual ~MainFrame();
public:
	/*
	* �����ļ�
	* fileName �ļ���
	* view ��ͼ
	*/
	virtual void loadFile(const String& fileName, FCView *view);
	/*
    * ����ID
    */
    int m_ctpID;
    
    /*
    * ���ID
    */
    int m_timerID;
    
    /*
    * ��ǰ����
    */
    String m_currentCode;
	/*
    * ���еĴ�����Ϣ
    */
    map<String, Security> m_allCodes;
    /*
    * ���е�������Ϣ
    */
    map<String, SecurityLatestData> m_allDatas;
	/*
    * ���������
    * eventName �¼�����
    * sender ��������
    * cell ��Ԫ��
    * touchInfo ��������
    * invoke ���ö���
    */
    virtual void callGridCellTouchEvent(String eventName, Object sender, FCGridCell *cell, FCTouchInfo touchInfo, Object invoke);
	/**
     * ����¼�
     * 
     * @param eventName �¼�����
     * @param sender ������
     * @param timerID ���ID
     * @param invoke ���ö���
     */
    virtual void callTimerEvent(String eventName, Object sender, int timerID, Object invoke);
	/*
    * ���з���
    */
    void checkCTPData();
	/*
    * ��½��CTP
    * appID Ӧ��ID
    * authCode �û�ID
    * mdServer ���������
    * tdServer ���׷�����
    * brokerID ������
    * investorID Ͷ�����˺�
    * password ����
    */
    void loginCTP(String appID, String authCode, String mdServer, String tdServer, String brokerID, String investorID, String password);
	/*
    * ����¼�
    * eventName �¼�����
    * sender ���ö���
    * touchInfo ������Ϣ
    * invoke ���ö���
    */
    virtual void callTouchEvent(String eventName, Object sender, FCTouchInfo touchInfo, Object invoke);
	/*
    * �ʽ��˻���Ϣ�ص�
    * data �ʽ���Ϣ
    * ctpID ����ID
    */
	void onAccountDataCallBack(AccountData *data, int ctpID);
	/*
    * ���õ�Ԫ�����ʽ
    * cell ��Ԫ��
    * value1 ��ֵ1
    * value2 ��ֵ2
    */
	void setCellStyle2(FCGridCell *cell, double value1, double value2);
	/*
    * �������ݻص�
    * data �������ݼ���
    * ctpID ����ID
    */
    void onSecurityLatestDataCallBack(vector<SecurityLatestData> *data, int ctpID);
	/*
    * ���͵Ľ�����Ϣ�ص�
    * data �ɽ��ر�
    * ctpID ����ID
    */
    void onTradeRecordCallBack(TradeRecord *data, int ctpID);
	/*
    * ������ѯ�Ľ�����Ϣ�ص�
    * data �ɽ��ر�����
    * ctpID ����ID
    */
    void onTradeRecordsCallBack(vector<TradeRecord> *data, int ctpID);
	/*
    * ���͵�ί�лر��ص�
    * data ί�лر�
    * ctpID ����ID
    */
    void onOrderInfoCallBack(OrderInfo *data, int ctpID);
	/*
    * ������ѯ��ί�лر��ص�
    * data ί�лر�����
    * ctpID ����ID
    */
    void onOrderInfosCallBack(vector<OrderInfo> *data, int ctpID);
	/*
    * �ֲ���ϸ���ݻص�
    * data �ֲ���ϸ����
    * ctpID ����ID
    */
    void onInvestorPositionDetailCallBack(vector<InvestorPositionDetail> *data, int ctpID);
	/*
    * �ֲ����ݻص�
    * data �ֲ�����
    * ctpID ����ID
    */
    void onInvestorPositionCallBack(vector<InvestorPosition> *data, int ctpID);
	/*
    * ���ص�
    * data �����
    * ctpID ����ID
    */
    void onSecurityCallBack(vector<Security> *data, int ctpID);
};


#endif