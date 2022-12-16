/*��������èFaceCat��� v1.0
�Ϻ����è��Ϣ�������޹�˾
 */

#ifndef __SECURITY_H__
#define __SECURITY_H__
#pragma once
#include "stdafx.h"
using namespace std;

//CTP�ʽ��˻��ඨ��
class AccountData{
public:
	// Ͷ�����ʺ�
	String accountID;
	// �����ʽ�
	double available;
	// �ڻ�����׼����
	double balance;
	// ���͹�˾����
	String brokerID;
	// �ʽ���
	double cashIn;
	// ƽ��ӯ��
	double closeProfit;
	// ������
	double commission;
	// ���ö��
	double credit;
	// ���ִ���
	String currencyID;
	// ��ǰ��֤���ܶ�
	double currMargin;
	// Ͷ���߽��֤��
	double deliveryMargin;
	// �����
	double deposit;
	//��̬Ȩ��
	double dynamicBalance;
	// ���������֤��
	double exchangeDeliveryMargin;
	// ��������֤��
	double exchangeMargin;
	// ����ӯ��
	double floatProfit;
	// ������ʽ�
	double frozenCash;
	// �����������
	double frozenCommission;
	// ����ı�֤��
	double frozenMargin;
	// ������Ѻ���
	double fundMortgageAvailable;
	// ����������
	double fundMortgageIn;
	// �����ʳ����
	double fundMortgageOut;
	// ��Ϣ����
	double interest;
	// ��Ϣ����
	double interestBase;
	// ��Ѻ���
	double mortgage;
	// ����Ѻ���ҽ��
	double mortgageableFund;
	// �ֲ�ӯ��
	double positionProfit;
	// �ϴν���׼����
	double preBalance;
	// �ϴ����ö��
	double preCredit;
	// �ϴδ���
	double preDeposit;
	// �ϴλ���������
	double preFundMortgageIn;
	// �ϴλ����ʳ����
	double preFundMortgageOut;
	// �ϴ�ռ�õı�֤��
	double preMargin;
	// �ϴ���Ѻ���
	double preMortgage;
	// ����׼����
	double reserve;
	// �����ڻ�����׼����
	double reserveBalance;
	// ���ն�
	double risk;
	// ������
	int settlementID;
	// �����Ʒƽ��ӯ��
	double specProductCloseProfit;
	// �����Ʒ������
	double specProductCommission;
	// �����Ʒ��������֤��
	double specProductExchangeMargin;
	// �����Ʒ����������
	double specProductFrozenCommission;
	// �����Ʒ���ᱣ֤��
	double specProductFrozenMargin;
	// �����Ʒռ�ñ�֤��
	double specProductMargin;
	// �����Ʒ�ֲ�ӯ��
	double specProductPositionProfit;
	// ���ݳֲ�ӯ���㷨����������Ʒ�ֲ�ӯ��
	double specProductPositionProfitByAlg;
	// ������
	String tradingDay;
	// ������
	double withdraw;
	// ��ȡ�ʽ�
	double withdrawQuota;
};

//��Լ��������
class CommissionRate{
public:
	//���͹�˾����
	String brokerID;
	//�շѷ�ʽ
	String calculateMode;
	//ƽ����������
	double closeRatioByMoney;
	//ƽ��������
	double closeRatioByVolume;
	//ƽ����������
	double closeTodayRatioByMoney;
	//ƽ��������
	double closeTodayRatioByVolume;
	//ƽ���
	double closeTodayFee;
	//��Լ����
	String code;
	//����
	String commodityNo;
	//����
	String commodityType;
	//���������
	String exchangeNo;
	//Ͷ���ߴ���
	String investorID;
	//Ͷ���߷�Χ
	String investorRange;
	//��Դ
	String matchSource;
	//��ƽ��
	double openCloseFee;
	//������������
	double openRatioByMoney;
	//����������
	double openRatioByVolume;
};

//��Լ��֤����
class MarginRate{
public:
	//���͹�˾����
	String brokerID;
	//�շѷ�ʽ
	String calculateMode;
	//���ǿ�����ʾ
	String callOrPutFlag;
	//��Լ����
	String code;
	//����
	String commodityNo;
	//����
	String commodityType;
	//��Լ
	String contractNo;
	//Ͷ���ױ���־
	String hedgeFlag;
	double initialMargin;
	//Ͷ���ߴ���
	String investorID;
	//��ͷ��֤����
	double longMarginRatioByMoney;
	//��ͷ��֤���
	double longMarginRatioByVolume;
	//Ͷ���߷�Χ
	String investorRange;
	//�Ƿ���Խ�������ȡ
	int isRelativel;
	double lockMargin;
	double maintenanceMargin;
	double sellInitialMargin;
	double sellMaintenanceMargin;
	//��ͷ��֤����
	double shortMarginRatioByMoney;
	//��ͷ��֤���
	double shortMarginRatioByVolume;
	String strikePrice;
};

//��Լ���ݶ���
class Security{
public:
	// �������
	String combinationType;
	//������
	String createDate;
	//������
	int deliveryMonth;
	//�������
	int deliveryYear;
	//����������
	String endDelivDate;
	//����������
	String exchangeID;
	//��Լ�ڽ������Ĵ���
	String exchangeInstID;
	//������
	String expireDate;
	//����С��λ��
	int digit;
	//��Լ��������״̬
	String instLifePhase;
	//��Լ����
	String instrumentID;
	//��Լ����
	String instrumentName;
	//��ǰ�Ƿ���
	String isTrading;
	//��ͷ��֤����
	double longMarginRatio;
	//�޼۵�����µ���
	int maxLimitOrderVolume;
	//�Ƿ�ʹ�ô��߱�֤���㷨
	String maxMarginSideAlgorithm;
	//�м۵�����µ���
	int maxMarketOrderVolume;
	//�޼۵���С�µ���
	int minLimitOrderVolume;
	//�м۵���С�µ���
	int minMarketOrderVolume;
	//������
	String openDate;
	//��Ȩ����
	String optionsType;
	//�ֲ���������
	String positionDateType;
	//�ֲ�����
	String positionType;
	//��С�䶯��λ
	double priceTick;
	//��Ʒ����
	String productClass;
	//��Ʒ����
	String productID;
	//��ͷ��֤����
	double shortMarginRatio;
	//��ʼ������
	String startDelivDate;
	//ִ�м�
	double strikePrice;
	//������Ʒ����
	String underlyingInstrID;
	//������Ʒ����
	String underlyingInstrName;
	//��Լ������Ʒ����
	double underlyingMultiple;
	//��Լ��������
	int volumeMultiple;

	void getNnderlyingInstrName(){
		int size = instrumentName.size();
		underlyingInstrName = L"";
		for (int i = 0; i < size ; i++){
			char sz = instrumentName[i];
			if (!(sz == '0' || sz == '1' || sz == '2' || sz == '3' || sz == '4' ||
				sz == '5' || sz == '6' || sz == '7' || sz == '8' || sz == '9')){
				underlyingInstrName += sz;
			}
		}
	}
};

//Ͷ���ֲֶ߳���
class InvestorPosition{
public:
	//����ִ�ж���
	int abandonFrozen;
	// ���͹�˾����
	String brokerID;
	// �ʽ���
	double cashIn;
	// ƽ�ֽ��
	double closeAmount;
	// ƽ��ӯ��
	double closeProfit;
	// ���ն���ƽ��ӯ��
	double closeProfitByDate;
	// ��ʶԳ�ƽ��ӯ��
	double closeProfitByTrade;
	// ƽ����
	int closeVolume;
	// ��Լ����
	String code;
	// ��϶�ͷ����
	int combLongFrozen;
	// ��ϳɽ��γɵĳֲ�
	int combPosition;
	// ��Ͽ�ͷ����
	int combShortFrozen;
	// ������
	double commission;
	// ��������֤��
	double exchangeMargin;
	// ������ʽ�
	double frozenCash;
	// �����������
	double frozenCommission;
	// ����ı�֤��
	double frozenMargin;
	// Ͷ���ױ���־
	String hedgeFlag;
	// Ͷ���ߴ���
	String investorID;
	// ��ͷ����
	int longFrozen;
	// ��ͷ������
	double longFrozenAmount;
	// ��֤����
	double marginRateByMoney;
	// ��֤����(������)
	double marginRateByVolume;
	// ���ֽ��
	double openAmount;
	// ���ֳɱ�
	double openCost;
	// ������
	int openVolume;
	// ���ճֲ�
	int position;
	// �ֲ�����
	String positionDate;
	// �ֲֶ�շ���
	String posiDirection;
	// �ֲֳɱ�
	double positionCost;
	// �ֲ�ӯ��
	double positionProfit;
	// �ϴ�ռ�õı�֤��
	double preMargin;	
	// �ϴν����
	double preSettlementPrice;
	// ������
	int settlementID;
	// ���ν����
	double settlementPrice;
	// ��ͷ����
	int shortFrozen;
	// ��ͷ������
	double shortFrozenAmount;
	// ִ�ж���
	int strikeFrozen;
	// ִ�ж�����
	double strikeFrozenAmount;
	// ���ճֲ�
	int todayPosition;
	//������
	String tradingDate;
	//ռ�õı�֤��
	double useMargin;
	//���ճֲ�
	int ydPosition;

	//��ȡ���ò�λ
	int getAvailablePosition(){
		int position = 0;
		position = position - getFrozenAmount();
		return position;
	};

	int getFrozenAmount(){
		int position = 0;
		if (posiDirection == L"��"){
			position = longFrozen;
		}
		else if (posiDirection == L"��"){
			position = shortFrozen;
		}
		return position;
	};
};

//�ֲ���ϸ
class InvestorPositionDetail{
public:
	//���͹�˾����
	String brokerID;
	//ƽ�ֽ��
	double closeAmount;
	//ƽ��ӯ��
	double closeProfit;
	//���ն��гֲ�ӯ��
	double closeProfitByDate;
	//��ʶԳ�ֲ�ӯ��
	double closeProfitByTrade;
	//ƽ����
	double closeVolume;
	//��Լ����
	String code;
	//��Ϻ�Լ����
	String combInstrumentID;
	//����
	String direction;
	//����������
	String exchangeID;
	//��������֤��
	double exchMargin;
	//����ӯ��
	double floatProfit;
	//Ͷ���ױ���־
	String hedgeFlag;
	//Ͷ���ߴ���
	String investorID;
	//������
	double lastPrice;
	//������
	double lastSettlementPrice;
	//Ͷ���߱�֤��
	double margin;
	//��֤����
	double marginRateByMoney;
	//��֤����(������)
	double marginRateByVolume;
	//�ڲ����
	String orderRef;
	//��������
	String openDate;
	//���ּ�
	double openPrice;
	//������
	int openVolume;
	//���سֲֺţ���������д
	String positionNo;
	//�ֲ�ӯ��
	double positionProfit;
	//���ն��гֲ�����
	double positionProfitByDate;
	//��ʶԳ�ֲ�����
	double positionProfitByTrade;
	//�ֲ�����
	int positionStreamId;
	//������
	double preSettlementPrice;
	//�ֲ�ӯ����׼��
	double profitBasePrice;
	//������
	int settlementID;
	//�����
	double settlementPrice;
	//�ɽ�����
	String tradingDay;
	//�ɽ����
	String tradeID;
	//�ɽ�����
	String tradeType;
	//����
	int volume;
};

//��������
class OrderInfo{
public:
	//����ʱ��	
	String activeTime;
	//����޸Ľ���������Ա����	
	String activeTraderID;
	//�����û�����	
	String activeUserID;
	//���͹�˾����	
	String brokerID;
	//���͹�˾�������	
	int brokerOrderSeq;
	//ҵ��Ԫ	
	String businessUnit;
	//����ʱ��	
	String cancelTime;
	//�����Ա���	
	String clearingPartID;
	//�ͻ�����	
	String clientID;
	//��Լ����	
	String code;
	//���Ͷ���ױ���־	
	String combHedgeFlag;
	//��Ͽ�ƽ��־	
	String combOffsetFlag;
	//��������	
	String contingentCondition;
	//��������	
	String direction;
	//����������	
	String exchangeID;
	//��Լ�ڽ������Ĵ���	
	String exchangeInstID;
	//ǿƽԭ��	
	String forceCloseReason;
	//ǰ�ñ��	
	int frontID;
	//GTD����	
	String gTDDate;
	//�۸�	
	double limitPrice;
	//��������	
	String insertDate;
	//ί��ʱ��	
	String insertTime;
	//��װ���	
	String installID;
	//Ͷ���ߴ���	
	String investorID;
	//�Զ������־	
	int isAutoSuspend;
	//��������־	
	int isSwapOrder;
	//��С�ɽ���	
	int minVolume;
	//������ʾ���	
	int notifySequence;
	//���ر������	
	String orderLocalID;
	//�����۸�����	
	String orderPriceType;
	//��������	
	String orderRef;
	//����״̬	
	String orderStatus;
	//������Դ	
	String orderSource;
	//�����ύ״̬	
	String orderSubmitStatus;
	//�������	
	String orderSysID;
	//��������	
	String orderType;
	//��Ա����	
	String participantID;
	//��ر���	
	String relativeOrderSysID;
	//������	
	int requestID;
	//���	
	int sequenceNo;
	//�Ự���	
	int sessionID;
	//������	
	int settlementID;
	//״̬��Ϣ	
	String statusMsg;
	//ֹ���	
	double stopPrice;
	//����ʱ��	
	String suspendTime;
	//��Ч������	
	String timeCondition;
	//����������Ա����	
	String traderID;
	//������	
	String tradingDay;
	//����޸�ʱ��	
	String updateTime;
	//�û�ǿ����־	
	int userForceClose;
	//�û�����	
	String userID;
	//�û��˲�Ʒ��Ϣ	
	String userProductInfo;
	//�ɽ�������	
	String volumeCondition;
	//ʣ������	
	int volumeTotal;
	//����	
	int volumeTotalOriginal;
	//��ɽ�����	
	int volumeTraded;
	//֣�����ɽ�����	
	int zCETotalTradedVolume;
};

//��������
class SecurityLatestData{
public:
	//������
	String actionDay;
	//����
    double askPrice1;
	//����
    double askPrice2;
	//����
    double askPrice3;
	//����
    double askPrice4;
	//����
    double askPrice5;
	//����
    int askVolume1;
	//����
    int askVolume2;
	//����
    int askVolume3;
	//����
    int askVolume4;
	//����
    int askVolume5;
	//ƽ���۸�
    double averagePrice;
	//���
    double bidPrice1;
	//���
    double bidPrice2;
	//���
    double bidPrice3;
	//���
    double bidPrice4;
	//���
    double bidPrice5;
	//����
    int bidVolume1;
	//����
    int bidVolume2;
	//����
    int bidVolume3;
	//����
    int bidVolume4;
	//����
    int bidVolume5;
	//���¼�
    double close;
	//��Լ����
    String code;
	//����ʵ��
    double currDelta;
	//������ID
    String exchangeID;
	//������InstID
    String exchangeInstID;
	//��߼�
    double high;
	//�������̼�
    double lastClose;
	//��ͼ�
    double low;
	//��ͣ��
    double lowerLimit;
	//���̼�
    double open;
	//�ֲ���
    double openInterest;
	//������
    double preClose;
	//����ʵ��
    double preDelta;
	//��ֲ���
    double preOpenInterest;
	//�ϴν����
    double preSettlementPrice;
	//���ν����
    double settlementPrice;
	//������
    String tradingDay;
	//�ɽ����
    double turnover;
	//����޸ĺ���
    int updateMillisec;
	//����޸�ʱ��
    String updateTime;
	//��ͣ��
    double upperLimit;
	//�ɽ���
    int volume;
};

//CTP���׶���
class TradeRecord{
public:
	//���͹�˾����
	String brokerID;
	///���͹�˾�������
	int brokerOrderSeq;
	///ҵ��Ԫ
	String businessUnit;
	///�����Ա���
	String clearingPartID;
	///�ͻ�����
	String clientID;
	//��Լ����
	String code;
	//��������
	String direction;
	//�г�����
	String exchangeID;
	//��Լ�ڽ������Ĵ���
	String exchangeInstID;
	//Ͷ���ױ���־
	String hedgeFlag;
	//Ͷ���ߴ���
	String investorID;
	//��ƽ��־
	String offsetFlag;
	//���ر������
	String orderLocalID;
	//��������
	String orderRef;
	//�������
	String orderSysID;
	//��Ա����
	String participantID;
	//�۸�
	double price;
	//�ɽ�����Դ
	String priceSource;
	//���
	int sequenceNo;
	//������
	int settlementID;
	//�ɽ����
	String tradeID;
	//����������Ա����
	String traderID;
	//�ɽ�ʱ��
	String tradeDate;
	//�ɽ���Դ
	String tradeSource;
	//�ɽ�ʱ��
	String tradeTime;
	//������
	String tradingDay;
	//�ɽ�����
	String tradeType;
	//���׽�ɫ
	String tradingRole;
	//����
	int volume;
	//�û�����
	String userID;
};

class CTPConvert{
public:
	//ת����CTP�ʽ��˻�
	static AccountData convertToCTPTradingAccount(String result);
	//ת��CTP��Լ��Ϣ
	static vector<Security> convertToCTPInstrumentDatas(String str);
	//ת��CTP����г�����
	static vector<SecurityLatestData> convertToCTPDepthMarketData(String result);
	//ת��CTP�ֲ���Ϣ
	static vector<InvestorPosition> convertToCTPInvestorPosition(String result);
	//ת��CTP�ֲ���ϸ��Ϣ
	static vector<InvestorPositionDetail> convertToCTPInvestorPositionDetail(String result);
	// ת��CTP������Ϣ
	static vector<OrderInfo> convertToCTPOrderList(String result);
	// ת��CTP������Ϣ
	static OrderInfo convertToCTPOrder(String result);
	//ת��CTP������Ϣ
	static TradeRecord convertToCTPTrade(String result);
	//ת��CTP������Ϣ�б�
	static vector<TradeRecord> convertToCTPTradeRecords(String result);
};

#endif