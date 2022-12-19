#include "stdafx.h"
#include "Security.h"

AccountData CTPConvert::convertToCTPTradingAccount(String result){
	AccountData cTPTradingAccount;
	//资金账号信息返回
	vector<String> results = FCStrEx::split(result,L",");
	if (results.size() >= 46){
		int i = 0;
		//经纪公司代码
		cTPTradingAccount.brokerID = results[i++];
		///投资者帐号
		cTPTradingAccount.accountID = results[i++];
		///上次质押金额
		cTPTradingAccount.preMortgage = FCStrEx::convertStrToDouble(results[i++].c_str());
		///上次信用额度
		cTPTradingAccount.preCredit = FCStrEx::convertStrToDouble(results[i++].c_str());
		///上次存款额
		cTPTradingAccount.preDeposit = FCStrEx::convertStrToDouble(results[i++].c_str());
		///上次结算准备金
		cTPTradingAccount.preBalance = FCStrEx::convertStrToDouble(results[i++].c_str());
		///上次占用的保证金
		cTPTradingAccount.preMargin = FCStrEx::convertStrToDouble(results[i++].c_str());
		///利息基数
		cTPTradingAccount.interestBase = FCStrEx::convertStrToDouble(results[i++].c_str());
		///利息收入
		cTPTradingAccount.interest = FCStrEx::convertStrToDouble(results[i++].c_str());
		///入金金额
		cTPTradingAccount.deposit = FCStrEx::convertStrToDouble(results[i++].c_str());
		///出金金额
		cTPTradingAccount.withdraw = FCStrEx::convertStrToDouble(results[i++].c_str());
		///冻结的保证金
		cTPTradingAccount.frozenMargin = FCStrEx::convertStrToDouble(results[i++].c_str());
		///冻结的资金
		cTPTradingAccount.frozenCash = FCStrEx::convertStrToDouble(results[i++].c_str());
		///冻结的手续费
		cTPTradingAccount.frozenCommission = FCStrEx::convertStrToDouble(results[i++].c_str());
		///当前保证金总额
		cTPTradingAccount.currMargin = FCStrEx::convertStrToDouble(results[i++].c_str());
		///资金差额
		cTPTradingAccount.cashIn = FCStrEx::convertStrToDouble(results[i++].c_str());
		///手续费
		cTPTradingAccount.commission = FCStrEx::convertStrToDouble(results[i++].c_str());
		///平仓盈亏
		cTPTradingAccount.closeProfit = FCStrEx::convertStrToDouble(results[i++].c_str());
		///持仓盈亏
		cTPTradingAccount.positionProfit = FCStrEx::convertStrToDouble(results[i++].c_str());
		///期货结算准备金
		cTPTradingAccount.balance = FCStrEx::convertStrToDouble(results[i++].c_str());
		///可用资金
		cTPTradingAccount.available = FCStrEx::convertStrToDouble(results[i++].c_str());
		///可取资金
		cTPTradingAccount.withdrawQuota = FCStrEx::convertStrToDouble(results[i++].c_str());
		///基本准备金
		cTPTradingAccount.reserve = FCStrEx::convertStrToDouble(results[i++].c_str());
		///交易日
		cTPTradingAccount.tradingDay = results[i++];
		///结算编号
		cTPTradingAccount.settlementID = FCStrEx::convertStrToInt(results[i++].c_str());
		///信用额度
		cTPTradingAccount.credit = FCStrEx::convertStrToDouble(results[i++].c_str());
		///质押金额
		cTPTradingAccount.mortgage = FCStrEx::convertStrToDouble(results[i++].c_str());
		///交易所保证金
		cTPTradingAccount.exchangeMargin = FCStrEx::convertStrToDouble(results[i++].c_str());
		///投资者交割保证金
		cTPTradingAccount.deliveryMargin = FCStrEx::convertStrToDouble(results[i++].c_str());
		///交易所交割保证金
		cTPTradingAccount.exchangeDeliveryMargin = FCStrEx::convertStrToDouble(results[i++].c_str());
		///保底期货结算准备金
		cTPTradingAccount.reserveBalance = FCStrEx::convertStrToDouble(results[i++].c_str());
		///币种代码
		cTPTradingAccount.currencyID = results[i++];
		///上次货币质入金额
		cTPTradingAccount.preFundMortgageIn = FCStrEx::convertStrToDouble(results[i++].c_str());
		///上次货币质出金额
		cTPTradingAccount.preFundMortgageOut = FCStrEx::convertStrToDouble(results[i++].c_str());
		///货币质入金额
		cTPTradingAccount.fundMortgageIn = FCStrEx::convertStrToDouble(results[i++].c_str());
		///货币质出金额
		cTPTradingAccount.fundMortgageOut = FCStrEx::convertStrToDouble(results[i++].c_str());
		///货币质押余额
		cTPTradingAccount.fundMortgageAvailable = FCStrEx::convertStrToDouble(results[i++].c_str());
		///可质押货币金额
		cTPTradingAccount.mortgageableFund = FCStrEx::convertStrToDouble(results[i++].c_str());
		///特殊产品占用保证金
		cTPTradingAccount.specProductMargin = FCStrEx::convertStrToDouble(results[i++].c_str());
		///特殊产品冻结保证金
		cTPTradingAccount.specProductFrozenMargin = FCStrEx::convertStrToDouble(results[i++].c_str());
		///特殊产品手续费
		cTPTradingAccount.specProductCommission = FCStrEx::convertStrToDouble(results[i++].c_str());
		///特殊产品冻结手续费
		cTPTradingAccount.specProductFrozenCommission = FCStrEx::convertStrToDouble(results[i++].c_str());
		///特殊产品持仓盈亏
		cTPTradingAccount.specProductPositionProfit = FCStrEx::convertStrToDouble(results[i++].c_str());
		///特殊产品平仓盈亏
		cTPTradingAccount.specProductCloseProfit = FCStrEx::convertStrToDouble(results[i++].c_str());
		///根据持仓盈亏算法计算的特殊产品持仓盈亏
		cTPTradingAccount.specProductPositionProfitByAlg = FCStrEx::convertStrToDouble(results[i++].c_str());
		///特殊产品交易所保证金
		cTPTradingAccount.specProductExchangeMargin = FCStrEx::convertStrToDouble(results[i++].c_str());
	    ///动态权益
        cTPTradingAccount.dynamicBalance = FCStrEx::convertStrToDouble(results[i++].c_str());
        ///风险度
        cTPTradingAccount.risk = FCStrEx::convertStrToDouble(results[i++].c_str());
		//浮动盈亏
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
			//合约代码
			security.instrumentID = result[j++];
			///交易所代码
			security.exchangeID = result[j++];
			///合约名称
			security.instrumentName = result[j++];
			///合约在交易所的代码
			security.exchangeInstID = result[j++];
			///产品代码
			security.productID = result[j++];
			///产品类型
			security.productClass = result[j++];
			///交割年份
			security.deliveryYear = FCStrEx::convertStrToInt(result[j++].c_str());
			///交割月
			security.deliveryMonth = FCStrEx::convertStrToInt(result[j++].c_str());
			///市价单最大下单量
			security.maxMarketOrderVolume = FCStrEx::convertStrToInt(result[j++].c_str());
			///市价单最小下单量
			security.minMarketOrderVolume = FCStrEx::convertStrToInt(result[j++].c_str());
			///限价单最大下单量
			security.maxLimitOrderVolume = FCStrEx::convertStrToInt(result[j++].c_str());
			///限价单最小下单量
			security.minLimitOrderVolume = FCStrEx::convertStrToInt(result[j++].c_str());
			///合约数量乘数
			security.volumeMultiple = FCStrEx::convertStrToInt(result[j++].c_str());
			///最小变动价位
			security.priceTick = FCStrEx::convertStrToDouble(result[j++].c_str());
			///创建日
			security.createDate = result[j++];
			///上市日
			security.openDate = result[j++];
			///到期日
			security.expireDate = result[j++];
			///开始交割日
			security.startDelivDate = result[j++];
			///结束交割日
			security.endDelivDate = result[j++];
			///合约生命周期状态
			security.instLifePhase = result[j++];
			///当前是否交易
			security.isTrading = result[j++];
			///持仓类型
			security.positionType = result[j++];
			///持仓日期类型
			security.positionDateType = result[j++];
			///多头保证金率  
			security.longMarginRatio = FCStrEx::convertStrToDouble(result[j++].c_str());
			///空头保证金率
			security.shortMarginRatio = FCStrEx::convertStrToDouble(result[j++].c_str());
			///是否使用大额单边保证金算法
			security.maxMarginSideAlgorithm = result[j++];
			///基础商品代码
			security.underlyingInstrID = result[j++];
			///执行价
			security.strikePrice = FCStrEx::convertStrToDouble(result[j++].c_str());
			///期权类型
			security.optionsType = result[j++];
			///合约基础商品乘数
			security.underlyingMultiple = FCStrEx::convertStrToDouble(result[j++].c_str());
			///组合类型
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
			///合约代码
			investorPosition.code = result[k++];
			///经纪公司代码
			investorPosition.brokerID = result[k++];
			///投资者代码
			investorPosition.investorID = result[k++];
			///持仓多空方向
			investorPosition.posiDirection = result[k++];
			///投机套保标志
			investorPosition.hedgeFlag = result[k++];
			///持仓日期
			investorPosition.positionDate = result[k++];
			///上日持仓
			investorPosition.ydPosition = FCStrEx::convertStrToInt(result[k++].c_str());
			///今日持仓
			investorPosition.position = FCStrEx::convertStrToInt(result[k++].c_str());
			///多头冻结
			investorPosition.longFrozen = FCStrEx::convertStrToInt(result[k++].c_str());
			///空头冻结
			investorPosition.shortFrozen = FCStrEx::convertStrToInt(result[k++].c_str());
			///开仓冻结金额
			investorPosition.longFrozenAmount = FCStrEx::convertStrToDouble(result[k++].c_str());
			///开仓冻结金额
			investorPosition.shortFrozenAmount = FCStrEx::convertStrToDouble(result[k++].c_str());
			///开仓量
			investorPosition.openVolume = FCStrEx::convertStrToInt(result[k++].c_str());
			///平仓量
			investorPosition.closeVolume = FCStrEx::convertStrToInt(result[k++].c_str());
			///开仓金额
			investorPosition.openAmount = FCStrEx::convertStrToDouble(result[k++].c_str());
			///平仓金额
			investorPosition.closeAmount = FCStrEx::convertStrToDouble(result[k++].c_str());
			///持仓成本
			investorPosition.positionCost = FCStrEx::convertStrToDouble(result[k++].c_str());
			///上次占用的保证金
			investorPosition.preMargin = FCStrEx::convertStrToDouble(result[k++].c_str());
			///占用的保证金
			investorPosition.useMargin = FCStrEx::convertStrToDouble(result[k++].c_str());
			///冻结的保证金
			investorPosition.frozenMargin = FCStrEx::convertStrToDouble(result[k++].c_str());
			///冻结的资金
			investorPosition.frozenCash = FCStrEx::convertStrToDouble(result[k++].c_str());
			///冻结的手续费
			investorPosition.frozenCommission = FCStrEx::convertStrToDouble(result[k++].c_str());
			///资金差额
			investorPosition.cashIn = FCStrEx::convertStrToDouble(result[k++].c_str());
			///手续费
			investorPosition.commission = FCStrEx::convertStrToDouble(result[k++].c_str());
			///平仓盈亏
			investorPosition.closeProfit = FCStrEx::convertStrToDouble(result[k++].c_str());
			///持仓盈亏
			investorPosition.positionProfit = FCStrEx::convertStrToDouble(result[k++].c_str());
			///上次结算价
			investorPosition.preSettlementPrice = FCStrEx::convertStrToDouble(result[k++].c_str());
			///本次结算价
			investorPosition.settlementPrice = FCStrEx::convertStrToDouble(result[k++].c_str());
			///交易日
			investorPosition.tradingDate = result[k++];
			///结算编号
			investorPosition.settlementID = FCStrEx::convertStrToInt(result[k++].c_str());
			///开仓成本
			investorPosition.openCost = FCStrEx::convertStrToDouble(result[k++].c_str());
			///交易所保证金
			investorPosition.exchangeMargin = FCStrEx::convertStrToDouble(result[k++].c_str());
			///组合成交形成的持仓
			investorPosition.combPosition = FCStrEx::convertStrToInt(result[k++].c_str());
			///组合多头冻结
			investorPosition.combLongFrozen = FCStrEx::convertStrToInt(result[k++].c_str());
			///组合空头冻结
			investorPosition.combShortFrozen = FCStrEx::convertStrToInt(result[k++].c_str());
			///逐日盯市平仓盈亏
			investorPosition.closeProfitByDate = FCStrEx::convertStrToDouble(result[k++].c_str());
			///逐笔对冲平仓盈亏
			investorPosition.closeProfitByTrade = FCStrEx::convertStrToDouble(result[k++].c_str());
			///今日持仓
			investorPosition.todayPosition = FCStrEx::convertStrToInt(result[k++].c_str());
			///保证金率
			investorPosition.marginRateByMoney = FCStrEx::convertStrToDouble(result[k++].c_str());
			///保证金率(按手数)
			investorPosition.marginRateByVolume = FCStrEx::convertStrToDouble(result[k++].c_str());
			///执行冻结
			investorPosition.strikeFrozen = FCStrEx::convertStrToInt(result[k++].c_str());
			///执行冻结金额
			investorPosition.strikeFrozenAmount = FCStrEx::convertStrToDouble(result[k++].c_str());
			///放弃执行冻结
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
		///经纪公司代码
		orderInfo.brokerID = result[i++];
		///投资者代码
		orderInfo.investorID = result[i++];
		///合约代码
		orderInfo.code = result[i++];
		///报单引用
		orderInfo.orderRef = result[i++];
		///用户代码
		orderInfo.userID = result[i++];
		///报单价格条件
		orderInfo.orderPriceType = result[i++];
		///买卖方向
		orderInfo.direction = result[i++];
		///组合开平标志
		orderInfo.combOffsetFlag = result[i++];
		///组合投机套保标志
		orderInfo.combHedgeFlag = result[i++];
		///价格
		orderInfo.limitPrice = FCStrEx::convertStrToDouble(result[i++].c_str());
		///数量
		orderInfo.volumeTotalOriginal = FCStrEx::convertStrToInt(result[i++].c_str());
		///有效期类型
		orderInfo.timeCondition = result[i++];
		///GTD日期
		orderInfo.gTDDate = result[i++];
		///成交量类型
		orderInfo.volumeCondition = result[i++];
		///最小成交量
		orderInfo.minVolume = FCStrEx::convertStrToInt(result[i++].c_str());
		///触发条件
		orderInfo.contingentCondition = result[i++];
		///止损价
		orderInfo.stopPrice = FCStrEx::convertStrToDouble(result[i++].c_str());
		///强平原因
		orderInfo.forceCloseReason = result[i++];
		///自动挂起标志
		orderInfo.isAutoSuspend = FCStrEx::convertStrToInt(result[i++].c_str());
		///业务单元
		orderInfo.businessUnit = result[i++];
		///请求编号
		orderInfo.requestID = FCStrEx::convertStrToInt(result[i++].c_str());
		///本地报单编号
		orderInfo.orderLocalID = result[i++];
		///交易所代码
		orderInfo.exchangeID = result[i++];
		///会员代码
		orderInfo.participantID = result[i++];
		///客户代码
		orderInfo.clientID = result[i++];
		///合约在交易所的代码
		orderInfo.exchangeInstID = result[i++];
		///交易所交易员代码
		orderInfo.traderID = result[i++];
		///安装编号
		orderInfo.installID = result[i++];
		///报单提交状态
		orderInfo.orderSubmitStatus = result[i++];
		///报单提示序号
		orderInfo.notifySequence = FCStrEx::convertStrToInt(result[i++].c_str());
		///交易日
		orderInfo.tradingDay = result[i++];
		///结算编号
		orderInfo.settlementID = FCStrEx::convertStrToInt(result[i++].c_str());
		///报单编号
		orderInfo.orderSysID = result[i++];
		///报单来源
		orderInfo.orderSource = result[i++];
		///报单状态
		orderInfo.orderStatus = result[i++];
		///报单类型
		orderInfo.orderType = result[i++];
		///今成交数量
		orderInfo.volumeTraded = FCStrEx::convertStrToInt(result[i++].c_str());
		///剩余数量
		orderInfo.volumeTotal = FCStrEx::convertStrToInt(result[i++].c_str());
		///报单日期
		orderInfo.insertDate = result[i++];
		///委托时间
		orderInfo.insertTime = result[i++];
		///激活时间
		orderInfo.activeTime = result[i++];
		///挂起时间
		orderInfo.suspendTime = result[i++];
		///最后修改时间
		orderInfo.updateTime = result[i++];
		///撤销时间
		orderInfo.cancelTime = result[i++];
		///最后修改交易所交易员代码
		orderInfo.activeTraderID = result[i++];
		///结算会员编号
		orderInfo.clearingPartID = result[i++];
		///序号
		orderInfo.sequenceNo = FCStrEx::convertStrToInt(result[i++].c_str());
		///前置编号
		orderInfo.frontID = FCStrEx::convertStrToInt(result[i++].c_str());
		///会话编号
		orderInfo.sessionID = FCStrEx::convertStrToInt(result[i++].c_str());
		///用户端产品信息
		orderInfo.userProductInfo = result[i++];
		///状态信息
		orderInfo.statusMsg = result[i++];
		///用户强评标志
		orderInfo.userForceClose = FCStrEx::convertStrToInt(result[i++].c_str());
		///操作用户代码
		orderInfo.activeUserID = result[i++];
		///经纪公司报单编号
		orderInfo.brokerOrderSeq = FCStrEx::convertStrToInt(result[i++].c_str());
		///相关报单
		orderInfo.relativeOrderSysID = result[i++];
		///郑商所成交数量
		orderInfo.zCETotalTradedVolume = FCStrEx::convertStrToInt(result[i++].c_str());
		///互换单标志
		orderInfo.isSwapOrder = FCStrEx::convertStrToInt(result[i++].c_str());
	}
	return orderInfo;
}

TradeRecord CTPConvert::convertToCTPTrade(String str){
	TradeRecord tradeRecord;
	vector<String> result = FCStrEx::split(str, L",");
	if(result.size() >= 30){
		int i = 0;
		///经纪公司代码
		tradeRecord.brokerID = result[i++];
		///投资者代码
		tradeRecord.investorID = result[i++];
		///合约代码
		tradeRecord.code = result[i++];
		///报单引用
		tradeRecord.orderRef = result[i++];
		///用户代码
		tradeRecord.userID = result[i++];
		///交易所代码
		tradeRecord.exchangeID = result[i++];
		///成交编号
		tradeRecord.tradeID = result[i++];
		///买卖方向
		tradeRecord.direction = result[i++];
		///报单编号
		tradeRecord.orderSysID = result[i++];
		///会员代码
		tradeRecord.participantID = result[i++];
		///客户代码
		tradeRecord.clientID = result[i++];
		///交易角色
		tradeRecord.tradingRole = result[i++];
		///合约在交易所的代码
		tradeRecord.exchangeInstID = result[i++];
		///开平标志
		tradeRecord.offsetFlag = result[i++];
		///投机套保标志
		tradeRecord.hedgeFlag = result[i++];
		///价格
		tradeRecord.price = FCStrEx::convertStrToDouble(result[i++].c_str());
		///数量
		tradeRecord.volume = FCStrEx::convertStrToInt(result[i++].c_str());
		///成交时期
		tradeRecord.tradeDate = result[i++];
		///成交时间
		tradeRecord.tradeTime = result[i++];
		///成交类型
		tradeRecord.tradeType = result[i++];
		///成交价来源
		tradeRecord.priceSource = result[i++];
		///交易所交易员代码
		tradeRecord.traderID = result[i++];
		///本地报单编号
		tradeRecord.orderLocalID = result[i++];
		///结算会员编号
		tradeRecord.clearingPartID = result[i++];
		///业务单元
		tradeRecord.businessUnit = result[i++];
		///序号
		tradeRecord.sequenceNo = FCStrEx::convertStrToInt(result[i++].c_str());
		///交易日
		tradeRecord.tradingDay = result[i++];
		///结算编号
		tradeRecord.settlementID = FCStrEx::convertStrToInt(result[i++].c_str());
		///经纪公司报单编号
		tradeRecord.brokerOrderSeq = FCStrEx::convertStrToInt(result[i++].c_str());
		///成交来源
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