#include "stdafx.h"
#include "Security.h"

AccountData CTPConvert::convertToCTPTradingAccount(String result){
	AccountData cTPTradingAccount;
	//�ʽ��˺���Ϣ����
	vector<String> results = FCStrEx::split(result,L",");
	if (results.size() >= 46){
		int i = 0;
		//���͹�˾����
		cTPTradingAccount.brokerID = results[i++];
		///Ͷ�����ʺ�
		cTPTradingAccount.accountID = results[i++];
		///�ϴ���Ѻ���
		cTPTradingAccount.preMortgage = FCStrEx::convertStrToDouble(results[i++].c_str());
		///�ϴ����ö��
		cTPTradingAccount.preCredit = FCStrEx::convertStrToDouble(results[i++].c_str());
		///�ϴδ���
		cTPTradingAccount.preDeposit = FCStrEx::convertStrToDouble(results[i++].c_str());
		///�ϴν���׼����
		cTPTradingAccount.preBalance = FCStrEx::convertStrToDouble(results[i++].c_str());
		///�ϴ�ռ�õı�֤��
		cTPTradingAccount.preMargin = FCStrEx::convertStrToDouble(results[i++].c_str());
		///��Ϣ����
		cTPTradingAccount.interestBase = FCStrEx::convertStrToDouble(results[i++].c_str());
		///��Ϣ����
		cTPTradingAccount.interest = FCStrEx::convertStrToDouble(results[i++].c_str());
		///�����
		cTPTradingAccount.deposit = FCStrEx::convertStrToDouble(results[i++].c_str());
		///������
		cTPTradingAccount.withdraw = FCStrEx::convertStrToDouble(results[i++].c_str());
		///����ı�֤��
		cTPTradingAccount.frozenMargin = FCStrEx::convertStrToDouble(results[i++].c_str());
		///������ʽ�
		cTPTradingAccount.frozenCash = FCStrEx::convertStrToDouble(results[i++].c_str());
		///�����������
		cTPTradingAccount.frozenCommission = FCStrEx::convertStrToDouble(results[i++].c_str());
		///��ǰ��֤���ܶ�
		cTPTradingAccount.currMargin = FCStrEx::convertStrToDouble(results[i++].c_str());
		///�ʽ���
		cTPTradingAccount.cashIn = FCStrEx::convertStrToDouble(results[i++].c_str());
		///������
		cTPTradingAccount.commission = FCStrEx::convertStrToDouble(results[i++].c_str());
		///ƽ��ӯ��
		cTPTradingAccount.closeProfit = FCStrEx::convertStrToDouble(results[i++].c_str());
		///�ֲ�ӯ��
		cTPTradingAccount.positionProfit = FCStrEx::convertStrToDouble(results[i++].c_str());
		///�ڻ�����׼����
		cTPTradingAccount.balance = FCStrEx::convertStrToDouble(results[i++].c_str());
		///�����ʽ�
		cTPTradingAccount.available = FCStrEx::convertStrToDouble(results[i++].c_str());
		///��ȡ�ʽ�
		cTPTradingAccount.withdrawQuota = FCStrEx::convertStrToDouble(results[i++].c_str());
		///����׼����
		cTPTradingAccount.reserve = FCStrEx::convertStrToDouble(results[i++].c_str());
		///������
		cTPTradingAccount.tradingDay = results[i++];
		///������
		cTPTradingAccount.settlementID = FCStrEx::convertStrToInt(results[i++].c_str());
		///���ö��
		cTPTradingAccount.credit = FCStrEx::convertStrToDouble(results[i++].c_str());
		///��Ѻ���
		cTPTradingAccount.mortgage = FCStrEx::convertStrToDouble(results[i++].c_str());
		///��������֤��
		cTPTradingAccount.exchangeMargin = FCStrEx::convertStrToDouble(results[i++].c_str());
		///Ͷ���߽��֤��
		cTPTradingAccount.deliveryMargin = FCStrEx::convertStrToDouble(results[i++].c_str());
		///���������֤��
		cTPTradingAccount.exchangeDeliveryMargin = FCStrEx::convertStrToDouble(results[i++].c_str());
		///�����ڻ�����׼����
		cTPTradingAccount.reserveBalance = FCStrEx::convertStrToDouble(results[i++].c_str());
		///���ִ���
		cTPTradingAccount.currencyID = results[i++];
		///�ϴλ���������
		cTPTradingAccount.preFundMortgageIn = FCStrEx::convertStrToDouble(results[i++].c_str());
		///�ϴλ����ʳ����
		cTPTradingAccount.preFundMortgageOut = FCStrEx::convertStrToDouble(results[i++].c_str());
		///����������
		cTPTradingAccount.fundMortgageIn = FCStrEx::convertStrToDouble(results[i++].c_str());
		///�����ʳ����
		cTPTradingAccount.fundMortgageOut = FCStrEx::convertStrToDouble(results[i++].c_str());
		///������Ѻ���
		cTPTradingAccount.fundMortgageAvailable = FCStrEx::convertStrToDouble(results[i++].c_str());
		///����Ѻ���ҽ��
		cTPTradingAccount.mortgageableFund = FCStrEx::convertStrToDouble(results[i++].c_str());
		///�����Ʒռ�ñ�֤��
		cTPTradingAccount.specProductMargin = FCStrEx::convertStrToDouble(results[i++].c_str());
		///�����Ʒ���ᱣ֤��
		cTPTradingAccount.specProductFrozenMargin = FCStrEx::convertStrToDouble(results[i++].c_str());
		///�����Ʒ������
		cTPTradingAccount.specProductCommission = FCStrEx::convertStrToDouble(results[i++].c_str());
		///�����Ʒ����������
		cTPTradingAccount.specProductFrozenCommission = FCStrEx::convertStrToDouble(results[i++].c_str());
		///�����Ʒ�ֲ�ӯ��
		cTPTradingAccount.specProductPositionProfit = FCStrEx::convertStrToDouble(results[i++].c_str());
		///�����Ʒƽ��ӯ��
		cTPTradingAccount.specProductCloseProfit = FCStrEx::convertStrToDouble(results[i++].c_str());
		///���ݳֲ�ӯ���㷨����������Ʒ�ֲ�ӯ��
		cTPTradingAccount.specProductPositionProfitByAlg = FCStrEx::convertStrToDouble(results[i++].c_str());
		///�����Ʒ��������֤��
		cTPTradingAccount.specProductExchangeMargin = FCStrEx::convertStrToDouble(results[i++].c_str());
	    ///��̬Ȩ��
        cTPTradingAccount.dynamicBalance = FCStrEx::convertStrToDouble(results[i++].c_str());
        ///���ն�
        cTPTradingAccount.risk = FCStrEx::convertStrToDouble(results[i++].c_str());
		//����ӯ��
		cTPTradingAccount.floatProfit = FCStrEx::convertStrToDouble(results[i++].c_str());
	}
	return cTPTradingAccount;
}

vector<Security> CTPConvert::convertToCTPInstrumentDatas(String str){
	vector<Security> securitis;
	vector<String> results = FCStrEx::split(str, L":");
	int size = (int)results.size();
	for(int i = 0;i < size; i++){
		vector<String> result = FCStrEx::split(results[i], L",");
		if(result.size() >= 31){
			Security security;
			int j = 0;
			//��Լ����
			security.instrumentID = result[j++];
			///����������
			security.exchangeID = result[j++];
			///��Լ����
			security.instrumentName = result[j++];
			///��Լ�ڽ������Ĵ���
			security.exchangeInstID = result[j++];
			///��Ʒ����
			security.productID = result[j++];
			///��Ʒ����
			security.productClass = result[j++];
			///�������
			security.deliveryYear = FCStrEx::convertStrToInt(result[j++].c_str());
			///������
			security.deliveryMonth = FCStrEx::convertStrToInt(result[j++].c_str());
			///�м۵�����µ���
			security.maxMarketOrderVolume = FCStrEx::convertStrToInt(result[j++].c_str());
			///�м۵���С�µ���
			security.minMarketOrderVolume = FCStrEx::convertStrToInt(result[j++].c_str());
			///�޼۵�����µ���
			security.maxLimitOrderVolume = FCStrEx::convertStrToInt(result[j++].c_str());
			///�޼۵���С�µ���
			security.minLimitOrderVolume = FCStrEx::convertStrToInt(result[j++].c_str());
			///��Լ��������
			security.volumeMultiple = FCStrEx::convertStrToInt(result[j++].c_str());
			///��С�䶯��λ
			security.priceTick = FCStrEx::convertStrToDouble(result[j++].c_str());
			///������
			security.createDate = result[j++];
			///������
			security.openDate = result[j++];
			///������
			security.expireDate = result[j++];
			///��ʼ������
			security.startDelivDate = result[j++];
			///����������
			security.endDelivDate = result[j++];
			///��Լ��������״̬
			security.instLifePhase = result[j++];
			///��ǰ�Ƿ���
			security.isTrading = result[j++];
			///�ֲ�����
			security.positionType = result[j++];
			///�ֲ���������
			security.positionDateType = result[j++];
			///��ͷ��֤����  
			security.longMarginRatio = FCStrEx::convertStrToDouble(result[j++].c_str());
			///��ͷ��֤����
			security.shortMarginRatio = FCStrEx::convertStrToDouble(result[j++].c_str());
			///�Ƿ�ʹ�ô��߱�֤���㷨
			security.maxMarginSideAlgorithm = result[j++];
			///������Ʒ����
			security.underlyingInstrID = result[j++];
			///ִ�м�
			security.strikePrice = FCStrEx::convertStrToDouble(result[j++].c_str());
			///��Ȩ����
			security.optionsType = result[j++];
			///��Լ������Ʒ����
			security.underlyingMultiple = FCStrEx::convertStrToDouble(result[j++].c_str());
			///�������
			security.combinationType = result[j++];
			security.getNnderlyingInstrName();
			securitis.push_back(security);
		}
	}
	return securitis;
}

vector<SecurityLatestData> CTPConvert::convertToCTPDepthMarketData(String str){
	vector<String> strs = FCStrEx::split(str, L";");
	vector<SecurityLatestData> datas;
	for(int j = 0; j < (int)strs.size(); j++){
		vector<String> results = FCStrEx::split(strs[j], L",");
		if (results.size() >= 44){
			int i = 0;
			SecurityLatestData cTPDepthMarketData;
			cTPDepthMarketData.tradingDay = results[i++];
			cTPDepthMarketData.code = results[i++];
			cTPDepthMarketData.exchangeID = results[i++];
			cTPDepthMarketData.exchangeInstID = results[i++];
			cTPDepthMarketData.lastClose = FCStrEx::convertStrToDouble(results[i++].c_str());
			cTPDepthMarketData.preSettlementPrice = FCStrEx::convertStrToDouble(results[i++].c_str());
			cTPDepthMarketData.preClose = FCStrEx::convertStrToDouble(results[i++].c_str());
			cTPDepthMarketData.preOpenInterest = FCStrEx::convertStrToDouble(results[i++].c_str());
			cTPDepthMarketData.open = FCStrEx::convertStrToDouble(results[i++].c_str());
			cTPDepthMarketData.high = FCStrEx::convertStrToDouble(results[i++].c_str());
			cTPDepthMarketData.low = FCStrEx::convertStrToDouble(results[i++].c_str());
			cTPDepthMarketData.volume = FCStrEx::convertStrToInt(results[i++].c_str());
			cTPDepthMarketData.turnover = FCStrEx::convertStrToDouble(results[i++].c_str());
			cTPDepthMarketData.openInterest = FCStrEx::convertStrToDouble(results[i++].c_str());
			cTPDepthMarketData.close = FCStrEx::convertStrToDouble(results[i++].c_str());
			cTPDepthMarketData.settlementPrice = FCStrEx::convertStrToDouble(results[i++].c_str());
			cTPDepthMarketData.upperLimit = FCStrEx::convertStrToDouble(results[i++].c_str());
			cTPDepthMarketData.lowerLimit = FCStrEx::convertStrToDouble(results[i++].c_str());
			cTPDepthMarketData.preDelta = FCStrEx::convertStrToDouble(results[i++].c_str());
			cTPDepthMarketData.currDelta = FCStrEx::convertStrToDouble(results[i++].c_str());
			cTPDepthMarketData.updateTime = results[i++];
			cTPDepthMarketData.updateMillisec = FCStrEx::convertStrToInt(results[i++].c_str());
			cTPDepthMarketData.bidPrice1 = FCStrEx::convertStrToDouble(results[i++].c_str());
			cTPDepthMarketData.bidVolume1 = FCStrEx::convertStrToInt(results[i++].c_str());
			cTPDepthMarketData.askPrice1 = FCStrEx::convertStrToDouble(results[i++].c_str());
			cTPDepthMarketData.askVolume1 = FCStrEx::convertStrToInt(results[i++].c_str());
			cTPDepthMarketData.bidPrice2 = FCStrEx::convertStrToDouble(results[i++].c_str());
			cTPDepthMarketData.bidVolume2 = FCStrEx::convertStrToInt(results[i++].c_str());
			cTPDepthMarketData.askPrice2 = FCStrEx::convertStrToDouble(results[i++].c_str());
			cTPDepthMarketData.askVolume2 = FCStrEx::convertStrToInt(results[i++].c_str());
			cTPDepthMarketData.bidPrice3 = FCStrEx::convertStrToDouble(results[i++].c_str());
			cTPDepthMarketData.bidVolume3 = FCStrEx::convertStrToInt(results[i++].c_str());
			cTPDepthMarketData.askPrice3 = FCStrEx::convertStrToDouble(results[i++].c_str());
			cTPDepthMarketData.askVolume3 = FCStrEx::convertStrToInt(results[i++].c_str());
			cTPDepthMarketData.bidPrice4 = FCStrEx::convertStrToDouble(results[i++].c_str());
			cTPDepthMarketData.bidVolume4 = FCStrEx::convertStrToInt(results[i++].c_str());
			cTPDepthMarketData.askPrice4 = FCStrEx::convertStrToDouble(results[i++].c_str());
			cTPDepthMarketData.askVolume4 = FCStrEx::convertStrToInt(results[i++].c_str());
			cTPDepthMarketData.bidPrice5 = FCStrEx::convertStrToDouble(results[i++].c_str());
			cTPDepthMarketData.bidVolume5 = FCStrEx::convertStrToInt(results[i++].c_str());
			cTPDepthMarketData.askPrice5 = FCStrEx::convertStrToDouble(results[i++].c_str());
			cTPDepthMarketData.askVolume5 = FCStrEx::convertStrToInt(results[i++].c_str());
			cTPDepthMarketData.averagePrice = FCStrEx::convertStrToDouble(results[i++].c_str());
			cTPDepthMarketData.actionDay = results[i++];
			datas.push_back(cTPDepthMarketData);
		}
	}
	return datas;
}

vector<InvestorPosition> CTPConvert::convertToCTPInvestorPosition(String str){
	vector<InvestorPosition> investorPositions;
	vector<String> results = FCStrEx::split(str, L";");
	int size = (int)results.size();
	for(int i = 0; i < size; i++){
		vector<String> result = FCStrEx::split(results[i], L",");
		if(result.size() >= 43){
			InvestorPosition investorPosition;
			int k = 0;
			///��Լ����
			investorPosition.code = result[k++];
			///���͹�˾����
			investorPosition.brokerID = result[k++];
			///Ͷ���ߴ���
			investorPosition.investorID = result[k++];
			///�ֲֶ�շ���
			investorPosition.posiDirection = result[k++];
			///Ͷ���ױ���־
			investorPosition.hedgeFlag = result[k++];
			///�ֲ�����
			investorPosition.positionDate = result[k++];
			///���ճֲ�
			investorPosition.ydPosition = FCStrEx::convertStrToInt(result[k++].c_str());
			///���ճֲ�
			investorPosition.position = FCStrEx::convertStrToInt(result[k++].c_str());
			///��ͷ����
			investorPosition.longFrozen = FCStrEx::convertStrToInt(result[k++].c_str());
			///��ͷ����
			investorPosition.shortFrozen = FCStrEx::convertStrToInt(result[k++].c_str());
			///���ֶ�����
			investorPosition.longFrozenAmount = FCStrEx::convertStrToDouble(result[k++].c_str());
			///���ֶ�����
			investorPosition.shortFrozenAmount = FCStrEx::convertStrToDouble(result[k++].c_str());
			///������
			investorPosition.openVolume = FCStrEx::convertStrToInt(result[k++].c_str());
			///ƽ����
			investorPosition.closeVolume = FCStrEx::convertStrToInt(result[k++].c_str());
			///���ֽ��
			investorPosition.openAmount = FCStrEx::convertStrToDouble(result[k++].c_str());
			///ƽ�ֽ��
			investorPosition.closeAmount = FCStrEx::convertStrToDouble(result[k++].c_str());
			///�ֲֳɱ�
			investorPosition.positionCost = FCStrEx::convertStrToDouble(result[k++].c_str());
			///�ϴ�ռ�õı�֤��
			investorPosition.preMargin = FCStrEx::convertStrToDouble(result[k++].c_str());
			///ռ�õı�֤��
			investorPosition.useMargin = FCStrEx::convertStrToDouble(result[k++].c_str());
			///����ı�֤��
			investorPosition.frozenMargin = FCStrEx::convertStrToDouble(result[k++].c_str());
			///������ʽ�
			investorPosition.frozenCash = FCStrEx::convertStrToDouble(result[k++].c_str());
			///�����������
			investorPosition.frozenCommission = FCStrEx::convertStrToDouble(result[k++].c_str());
			///�ʽ���
			investorPosition.cashIn = FCStrEx::convertStrToDouble(result[k++].c_str());
			///������
			investorPosition.commission = FCStrEx::convertStrToDouble(result[k++].c_str());
			///ƽ��ӯ��
			investorPosition.closeProfit = FCStrEx::convertStrToDouble(result[k++].c_str());
			///�ֲ�ӯ��
			investorPosition.positionProfit = FCStrEx::convertStrToDouble(result[k++].c_str());
			///�ϴν����
			investorPosition.preSettlementPrice = FCStrEx::convertStrToDouble(result[k++].c_str());
			///���ν����
			investorPosition.settlementPrice = FCStrEx::convertStrToDouble(result[k++].c_str());
			///������
			investorPosition.tradingDate = result[k++];
			///������
			investorPosition.settlementID = FCStrEx::convertStrToInt(result[k++].c_str());
			///���ֳɱ�
			investorPosition.openCost = FCStrEx::convertStrToDouble(result[k++].c_str());
			///��������֤��
			investorPosition.exchangeMargin = FCStrEx::convertStrToDouble(result[k++].c_str());
			///��ϳɽ��γɵĳֲ�
			investorPosition.combPosition = FCStrEx::convertStrToInt(result[k++].c_str());
			///��϶�ͷ����
			investorPosition.combLongFrozen = FCStrEx::convertStrToInt(result[k++].c_str());
			///��Ͽ�ͷ����
			investorPosition.combShortFrozen = FCStrEx::convertStrToInt(result[k++].c_str());
			///���ն���ƽ��ӯ��
			investorPosition.closeProfitByDate = FCStrEx::convertStrToDouble(result[k++].c_str());
			///��ʶԳ�ƽ��ӯ��
			investorPosition.closeProfitByTrade = FCStrEx::convertStrToDouble(result[k++].c_str());
			///���ճֲ�
			investorPosition.todayPosition = FCStrEx::convertStrToInt(result[k++].c_str());
			///��֤����
			investorPosition.marginRateByMoney = FCStrEx::convertStrToDouble(result[k++].c_str());
			///��֤����(������)
			investorPosition.marginRateByVolume = FCStrEx::convertStrToDouble(result[k++].c_str());
			///ִ�ж���
			investorPosition.strikeFrozen = FCStrEx::convertStrToInt(result[k++].c_str());
			///ִ�ж�����
			investorPosition.strikeFrozenAmount = FCStrEx::convertStrToDouble(result[k++].c_str());
			///����ִ�ж���
			investorPosition.abandonFrozen = FCStrEx::convertStrToInt(result[k++].c_str());
			investorPositions.push_back(investorPosition);
		}
	}
	return investorPositions;
}

vector<InvestorPositionDetail> CTPConvert::convertToCTPInvestorPositionDetail(String str){
	vector<InvestorPositionDetail> investorPositionDetails;
	vector<String> results = FCStrEx::split(str, L";");
	int size = (int)results.size();
	for(int i = 0; i < size; i++){
		vector<String> result = FCStrEx::split(results[i], L",");
		if(result.size() >= 43){
			InvestorPositionDetail investorPositionDetail;
			int k = 0;
			investorPositionDetail.code = result[k++];
			investorPositionDetail.brokerID = result[k++];
			investorPositionDetail.investorID = result[k++];
			investorPositionDetail.hedgeFlag = result[k++];
			investorPositionDetail.direction = result[k++];
			investorPositionDetail.openDate = result[k++];
			investorPositionDetail.tradeID = result[k++];
			investorPositionDetail.volume = FCStrEx::convertStrToInt(result[k++].c_str());
			investorPositionDetail.openPrice = FCStrEx::convertStrToDouble(result[k++].c_str());
			investorPositionDetail.tradingDay = result[k++];
			investorPositionDetail.settlementID = FCStrEx::convertStrToInt(result[k++].c_str());
			investorPositionDetail.tradeType = result[k++];
			investorPositionDetail.combInstrumentID = result[k++];
			investorPositionDetail.exchangeID = result[k++];
			investorPositionDetail.closeProfitByDate = FCStrEx::convertStrToDouble(result[k++].c_str());
			investorPositionDetail.closeProfitByTrade = FCStrEx::convertStrToDouble(result[k++].c_str());
			investorPositionDetail.positionProfitByDate = FCStrEx::convertStrToDouble(result[k++].c_str());
			investorPositionDetail.positionProfitByTrade = FCStrEx::convertStrToDouble(result[k++].c_str());
			investorPositionDetail.margin = FCStrEx::convertStrToDouble(result[k++].c_str());
			investorPositionDetail.exchMargin = FCStrEx::convertStrToDouble(result[k++].c_str());
			investorPositionDetail.marginRateByMoney = FCStrEx::convertStrToDouble(result[k++].c_str());
			investorPositionDetail.marginRateByVolume = FCStrEx::convertStrToDouble(result[k++].c_str());
			investorPositionDetail.lastSettlementPrice = FCStrEx::convertStrToDouble(result[k++].c_str());
			investorPositionDetail.lastSettlementPrice = FCStrEx::convertStrToDouble(result[k++].c_str());
			investorPositionDetail.settlementPrice = FCStrEx::convertStrToDouble(result[k++].c_str());
			investorPositionDetail.closeVolume = FCStrEx::convertStrToInt(result[k++].c_str());
			investorPositionDetails.push_back(investorPositionDetail);
		}
	}
	return investorPositionDetails;
}

vector<OrderInfo> CTPConvert::convertToCTPOrderList(String str){
	vector<OrderInfo> orderInfos;
	vector<String> results = FCStrEx::split(str, L";");
	int size = (int)results.size();
	for(int i = 0; i < size; i++){
		if(results[i].size() != 0){	
			OrderInfo orderInfo = convertToCTPOrder(results[i]);
			orderInfos.push_back(orderInfo);
		}
	}
	return orderInfos;
}

OrderInfo CTPConvert::convertToCTPOrder(String str){
	OrderInfo orderInfo;
	vector<String> result = FCStrEx::split(str, L",");
	int size = (int)result.size();
	if(size >= 57){
		int i = 0;
		///���͹�˾����
		orderInfo.brokerID = result[i++];
		///Ͷ���ߴ���
		orderInfo.investorID = result[i++];
		///��Լ����
		orderInfo.code = result[i++];
		///��������
		orderInfo.orderRef = result[i++];
		///�û�����
		orderInfo.userID = result[i++];
		///�����۸�����
		orderInfo.orderPriceType = result[i++];
		///��������
		orderInfo.direction = result[i++];
		///��Ͽ�ƽ��־
		orderInfo.combOffsetFlag = result[i++];
		///���Ͷ���ױ���־
		orderInfo.combHedgeFlag = result[i++];
		///�۸�
		orderInfo.limitPrice = FCStrEx::convertStrToDouble(result[i++].c_str());
		///����
		orderInfo.volumeTotalOriginal = FCStrEx::convertStrToInt(result[i++].c_str());
		///��Ч������
		orderInfo.timeCondition = result[i++];
		///GTD����
		orderInfo.gTDDate = result[i++];
		///�ɽ�������
		orderInfo.volumeCondition = result[i++];
		///��С�ɽ���
		orderInfo.minVolume = FCStrEx::convertStrToInt(result[i++].c_str());
		///��������
		orderInfo.contingentCondition = result[i++];
		///ֹ���
		orderInfo.stopPrice = FCStrEx::convertStrToDouble(result[i++].c_str());
		///ǿƽԭ��
		orderInfo.forceCloseReason = result[i++];
		///�Զ������־
		orderInfo.isAutoSuspend = FCStrEx::convertStrToInt(result[i++].c_str());
		///ҵ��Ԫ
		orderInfo.businessUnit = result[i++];
		///������
		orderInfo.requestID = FCStrEx::convertStrToInt(result[i++].c_str());
		///���ر������
		orderInfo.orderLocalID = result[i++];
		///����������
		orderInfo.exchangeID = result[i++];
		///��Ա����
		orderInfo.participantID = result[i++];
		///�ͻ�����
		orderInfo.clientID = result[i++];
		///��Լ�ڽ������Ĵ���
		orderInfo.exchangeInstID = result[i++];
		///����������Ա����
		orderInfo.traderID = result[i++];
		///��װ���
		orderInfo.installID = result[i++];
		///�����ύ״̬
		orderInfo.orderSubmitStatus = result[i++];
		///������ʾ���
		orderInfo.notifySequence = FCStrEx::convertStrToInt(result[i++].c_str());
		///������
		orderInfo.tradingDay = result[i++];
		///������
		orderInfo.settlementID = FCStrEx::convertStrToInt(result[i++].c_str());
		///�������
		orderInfo.orderSysID = result[i++];
		///������Դ
		orderInfo.orderSource = result[i++];
		///����״̬
		orderInfo.orderStatus = result[i++];
		///��������
		orderInfo.orderType = result[i++];
		///��ɽ�����
		orderInfo.volumeTraded = FCStrEx::convertStrToInt(result[i++].c_str());
		///ʣ������
		orderInfo.volumeTotal = FCStrEx::convertStrToInt(result[i++].c_str());
		///��������
		orderInfo.insertDate = result[i++];
		///ί��ʱ��
		orderInfo.insertTime = result[i++];
		///����ʱ��
		orderInfo.activeTime = result[i++];
		///����ʱ��
		orderInfo.suspendTime = result[i++];
		///����޸�ʱ��
		orderInfo.updateTime = result[i++];
		///����ʱ��
		orderInfo.cancelTime = result[i++];
		///����޸Ľ���������Ա����
		orderInfo.activeTraderID = result[i++];
		///�����Ա���
		orderInfo.clearingPartID = result[i++];
		///���
		orderInfo.sequenceNo = FCStrEx::convertStrToInt(result[i++].c_str());
		///ǰ�ñ��
		orderInfo.frontID = FCStrEx::convertStrToInt(result[i++].c_str());
		///�Ự���
		orderInfo.sessionID = FCStrEx::convertStrToInt(result[i++].c_str());
		///�û��˲�Ʒ��Ϣ
		orderInfo.userProductInfo = result[i++];
		///״̬��Ϣ
		orderInfo.statusMsg = result[i++];
		///�û�ǿ����־
		orderInfo.userForceClose = FCStrEx::convertStrToInt(result[i++].c_str());
		///�����û�����
		orderInfo.activeUserID = result[i++];
		///���͹�˾�������
		orderInfo.brokerOrderSeq = FCStrEx::convertStrToInt(result[i++].c_str());
		///��ر���
		orderInfo.relativeOrderSysID = result[i++];
		///֣�����ɽ�����
		orderInfo.zCETotalTradedVolume = FCStrEx::convertStrToInt(result[i++].c_str());
		///��������־
		orderInfo.isSwapOrder = FCStrEx::convertStrToInt(result[i++].c_str());
	}
	return orderInfo;
}

TradeRecord CTPConvert::convertToCTPTrade(String str){
	TradeRecord tradeRecord;
	vector<String> result = FCStrEx::split(str, L",");
	if(result.size() >= 30){
		int i = 0;
		///���͹�˾����
		tradeRecord.brokerID = result[i++];
		///Ͷ���ߴ���
		tradeRecord.investorID = result[i++];
		///��Լ����
		tradeRecord.code = result[i++];
		///��������
		tradeRecord.orderRef = result[i++];
		///�û�����
		tradeRecord.userID = result[i++];
		///����������
		tradeRecord.exchangeID = result[i++];
		///�ɽ����
		tradeRecord.tradeID = result[i++];
		///��������
		tradeRecord.direction = result[i++];
		///�������
		tradeRecord.orderSysID = result[i++];
		///��Ա����
		tradeRecord.participantID = result[i++];
		///�ͻ�����
		tradeRecord.clientID = result[i++];
		///���׽�ɫ
		tradeRecord.tradingRole = result[i++];
		///��Լ�ڽ������Ĵ���
		tradeRecord.exchangeInstID = result[i++];
		///��ƽ��־
		tradeRecord.offsetFlag = result[i++];
		///Ͷ���ױ���־
		tradeRecord.hedgeFlag = result[i++];
		///�۸�
		tradeRecord.price = FCStrEx::convertStrToDouble(result[i++].c_str());
		///����
		tradeRecord.volume = FCStrEx::convertStrToInt(result[i++].c_str());
		///�ɽ�ʱ��
		tradeRecord.tradeDate = result[i++];
		///�ɽ�ʱ��
		tradeRecord.tradeTime = result[i++];
		///�ɽ�����
		tradeRecord.tradeType = result[i++];
		///�ɽ�����Դ
		tradeRecord.priceSource = result[i++];
		///����������Ա����
		tradeRecord.traderID = result[i++];
		///���ر������
		tradeRecord.orderLocalID = result[i++];
		///�����Ա���
		tradeRecord.clearingPartID = result[i++];
		///ҵ��Ԫ
		tradeRecord.businessUnit = result[i++];
		///���
		tradeRecord.sequenceNo = FCStrEx::convertStrToInt(result[i++].c_str());
		///������
		tradeRecord.tradingDay = result[i++];
		///������
		tradeRecord.settlementID = FCStrEx::convertStrToInt(result[i++].c_str());
		///���͹�˾�������
		tradeRecord.brokerOrderSeq = FCStrEx::convertStrToInt(result[i++].c_str());
		///�ɽ���Դ
		tradeRecord.tradeSource = result[i++];
	}
	return tradeRecord;
}

vector<TradeRecord> CTPConvert::convertToCTPTradeRecords(String str){
	vector<TradeRecord> tradeRecords;
	vector<String> results = FCStrEx::split(str, L";");
	int size = (int)results.size();
	for(int i = 0 ; i < size ; i++){
		if(results[i].size() != 0){
			TradeRecord tradeRecord =  convertToCTPTrade(results[i]);
			tradeRecords.push_back(tradeRecord);
		}
	}
	return  tradeRecords;
}