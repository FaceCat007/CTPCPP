/*基于捂脸猫FaceCat框架 v1.0
上海卷卷猫信息技术有限公司
 */

#ifndef __SECURITY_H__
#define __SECURITY_H__
#pragma once
#include "stdafx.h"
using namespace std;

//CTP资金账户类定义
class AccountData{
public:
	// 投资者帐号
	String accountID;
	// 可用资金
	double available;
	// 期货结算准备金
	double balance;
	// 经纪公司代码
	String brokerID;
	// 资金差额
	double cashIn;
	// 平仓盈亏
	double closeProfit;
	// 手续费
	double commission;
	// 信用额度
	double credit;
	// 币种代码
	String currencyID;
	// 当前保证金总额
	double currMargin;
	// 投资者交割保证金
	double deliveryMargin;
	// 入金金额
	double deposit;
	//动态权益
	double dynamicBalance;
	// 交易所交割保证金
	double exchangeDeliveryMargin;
	// 交易所保证金
	double exchangeMargin;
	// 浮动盈亏
	double floatProfit;
	// 冻结的资金
	double frozenCash;
	// 冻结的手续费
	double frozenCommission;
	// 冻结的保证金
	double frozenMargin;
	// 货币质押余额
	double fundMortgageAvailable;
	// 货币质入金额
	double fundMortgageIn;
	// 货币质出金额
	double fundMortgageOut;
	// 利息收入
	double interest;
	// 利息基数
	double interestBase;
	// 质押金额
	double mortgage;
	// 可质押货币金额
	double mortgageableFund;
	// 持仓盈亏
	double positionProfit;
	// 上次结算准备金
	double preBalance;
	// 上次信用额度
	double preCredit;
	// 上次存款额
	double preDeposit;
	// 上次货币质入金额
	double preFundMortgageIn;
	// 上次货币质出金额
	double preFundMortgageOut;
	// 上次占用的保证金
	double preMargin;
	// 上次质押金额
	double preMortgage;
	// 基本准备金
	double reserve;
	// 保底期货结算准备金
	double reserveBalance;
	// 风险度
	double risk;
	// 结算编号
	int settlementID;
	// 特殊产品平仓盈亏
	double specProductCloseProfit;
	// 特殊产品手续费
	double specProductCommission;
	// 特殊产品交易所保证金
	double specProductExchangeMargin;
	// 特殊产品冻结手续费
	double specProductFrozenCommission;
	// 特殊产品冻结保证金
	double specProductFrozenMargin;
	// 特殊产品占用保证金
	double specProductMargin;
	// 特殊产品持仓盈亏
	double specProductPositionProfit;
	// 根据持仓盈亏算法计算的特殊产品持仓盈亏
	double specProductPositionProfitByAlg;
	// 交易日
	String tradingDay;
	// 出金金额
	double withdraw;
	// 可取资金
	double withdrawQuota;
};

//合约手续费率
class CommissionRate{
public:
	//经纪公司代码
	String brokerID;
	//收费方式
	String calculateMode;
	//平仓手续费率
	double closeRatioByMoney;
	//平仓手续费
	double closeRatioByVolume;
	//平今手续费率
	double closeTodayRatioByMoney;
	//平今手续费
	double closeTodayRatioByVolume;
	//平今费
	double closeTodayFee;
	//合约代码
	String code;
	//代码
	String commodityNo;
	//类型
	String commodityType;
	//交易所编号
	String exchangeNo;
	//投资者代码
	String investorID;
	//投资者范围
	String investorRange;
	//来源
	String matchSource;
	//开平费
	double openCloseFee;
	//开仓手续费率
	double openRatioByMoney;
	//开仓手续费
	double openRatioByVolume;
};

//合约保证金率
class MarginRate{
public:
	//经纪公司代码
	String brokerID;
	//收费方式
	String calculateMode;
	//看涨看跌标示
	String callOrPutFlag;
	//合约代码
	String code;
	//代码
	String commodityNo;
	//类型
	String commodityType;
	//合约
	String contractNo;
	//投机套保标志
	String hedgeFlag;
	double initialMargin;
	//投资者代码
	String investorID;
	//多头保证金率
	double longMarginRatioByMoney;
	//多头保证金费
	double longMarginRatioByVolume;
	//投资者范围
	String investorRange;
	//是否相对交易所收取
	int isRelativel;
	double lockMargin;
	double maintenanceMargin;
	double sellInitialMargin;
	double sellMaintenanceMargin;
	//空头保证金率
	double shortMarginRatioByMoney;
	//空头保证金费
	double shortMarginRatioByVolume;
	String strikePrice;
};

//合约数据定义
class Security{
public:
	// 组合类型
	String combinationType;
	//创建日
	String createDate;
	//交割月
	int deliveryMonth;
	//交割年份
	int deliveryYear;
	//结束交割日
	String endDelivDate;
	//交易所代码
	String exchangeID;
	//合约在交易所的代码
	String exchangeInstID;
	//到期日
	String expireDate;
	//保留小数位数
	int digit;
	//合约生命周期状态
	String instLifePhase;
	//合约代码
	String instrumentID;
	//合约名称
	String instrumentName;
	//当前是否交易
	String isTrading;
	//多头保证金率
	double longMarginRatio;
	//限价单最大下单量
	int maxLimitOrderVolume;
	//是否使用大额单边保证金算法
	String maxMarginSideAlgorithm;
	//市价单最大下单量
	int maxMarketOrderVolume;
	//限价单最小下单量
	int minLimitOrderVolume;
	//市价单最小下单量
	int minMarketOrderVolume;
	//上市日
	String openDate;
	//期权类型
	String optionsType;
	//持仓日期类型
	String positionDateType;
	//持仓类型
	String positionType;
	//最小变动价位
	double priceTick;
	//产品类型
	String productClass;
	//产品代码
	String productID;
	//空头保证金率
	double shortMarginRatio;
	//开始交割日
	String startDelivDate;
	//执行价
	double strikePrice;
	//基础商品代码
	String underlyingInstrID;
	//基础商品名称
	String underlyingInstrName;
	//合约基础商品乘数
	double underlyingMultiple;
	//合约数量乘数
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

//投资者持仓定义
class InvestorPosition{
public:
	//放弃执行冻结
	int abandonFrozen;
	// 经纪公司代码
	String brokerID;
	// 资金差额
	double cashIn;
	// 平仓金额
	double closeAmount;
	// 平仓盈亏
	double closeProfit;
	// 逐日盯市平仓盈亏
	double closeProfitByDate;
	// 逐笔对冲平仓盈亏
	double closeProfitByTrade;
	// 平仓量
	int closeVolume;
	// 合约代码
	String code;
	// 组合多头冻结
	int combLongFrozen;
	// 组合成交形成的持仓
	int combPosition;
	// 组合空头冻结
	int combShortFrozen;
	// 手续费
	double commission;
	// 交易所保证金
	double exchangeMargin;
	// 冻结的资金
	double frozenCash;
	// 冻结的手续费
	double frozenCommission;
	// 冻结的保证金
	double frozenMargin;
	// 投机套保标志
	String hedgeFlag;
	// 投资者代码
	String investorID;
	// 多头冻结
	int longFrozen;
	// 多头冻结金额
	double longFrozenAmount;
	// 保证金率
	double marginRateByMoney;
	// 保证金率(按手数)
	double marginRateByVolume;
	// 开仓金额
	double openAmount;
	// 开仓成本
	double openCost;
	// 开仓量
	int openVolume;
	// 今日持仓
	int position;
	// 持仓日期
	String positionDate;
	// 持仓多空方向
	String posiDirection;
	// 持仓成本
	double positionCost;
	// 持仓盈亏
	double positionProfit;
	// 上次占用的保证金
	double preMargin;	
	// 上次结算价
	double preSettlementPrice;
	// 结算编号
	int settlementID;
	// 本次结算价
	double settlementPrice;
	// 空头冻结
	int shortFrozen;
	// 空头冻结金额
	double shortFrozenAmount;
	// 执行冻结
	int strikeFrozen;
	// 执行冻结金额
	double strikeFrozenAmount;
	// 今日持仓
	int todayPosition;
	//交易日
	String tradingDate;
	//占用的保证金
	double useMargin;
	//上日持仓
	int ydPosition;

	//获取可用仓位
	int getAvailablePosition(){
		int position = 0;
		position = position - getFrozenAmount();
		return position;
	};

	int getFrozenAmount(){
		int position = 0;
		if (posiDirection == L"多"){
			position = longFrozen;
		}
		else if (posiDirection == L"空"){
			position = shortFrozen;
		}
		return position;
	};
};

//持仓明细
class InvestorPositionDetail{
public:
	//经纪公司代码
	String brokerID;
	//平仓金额
	double closeAmount;
	//平仓盈亏
	double closeProfit;
	//逐日盯市持仓盈亏
	double closeProfitByDate;
	//逐笔对冲持仓盈亏
	double closeProfitByTrade;
	//平仓量
	double closeVolume;
	//合约代码
	String code;
	//组合合约代码
	String combInstrumentID;
	//买卖
	String direction;
	//交易所代码
	String exchangeID;
	//交易所保证金
	double exchMargin;
	//浮动盈亏
	double floatProfit;
	//投机套保标志
	String hedgeFlag;
	//投资者代码
	String investorID;
	//昨收盘
	double lastPrice;
	//昨结算价
	double lastSettlementPrice;
	//投资者保证金
	double margin;
	//保证金率
	double marginRateByMoney;
	//保证金率(按手数)
	double marginRateByVolume;
	//内部编号
	String orderRef;
	//开仓日期
	String openDate;
	//开仓价
	double openPrice;
	//开仓量
	int openVolume;
	//本地持仓号，服务器编写
	String positionNo;
	//持仓盈亏
	double positionProfit;
	//逐日盯市持仓利润
	double positionProfitByDate;
	//逐笔对冲持仓利润
	double positionProfitByTrade;
	//持仓流号
	int positionStreamId;
	//昨结算价
	double preSettlementPrice;
	//持仓盈亏基准价
	double profitBasePrice;
	//结算编号
	int settlementID;
	//结算价
	double settlementPrice;
	//成交日期
	String tradingDay;
	//成交编号
	String tradeID;
	//成交类型
	String tradeType;
	//数量
	int volume;
};

//报单定义
class OrderInfo{
public:
	//激活时间	
	String activeTime;
	//最后修改交易所交易员代码	
	String activeTraderID;
	//操作用户代码	
	String activeUserID;
	//经纪公司代码	
	String brokerID;
	//经纪公司报单编号	
	int brokerOrderSeq;
	//业务单元	
	String businessUnit;
	//撤销时间	
	String cancelTime;
	//结算会员编号	
	String clearingPartID;
	//客户代码	
	String clientID;
	//合约代码	
	String code;
	//组合投机套保标志	
	String combHedgeFlag;
	//组合开平标志	
	String combOffsetFlag;
	//触发条件	
	String contingentCondition;
	//买卖方向	
	String direction;
	//交易所代码	
	String exchangeID;
	//合约在交易所的代码	
	String exchangeInstID;
	//强平原因	
	String forceCloseReason;
	//前置编号	
	int frontID;
	//GTD日期	
	String gTDDate;
	//价格	
	double limitPrice;
	//报单日期	
	String insertDate;
	//委托时间	
	String insertTime;
	//安装编号	
	String installID;
	//投资者代码	
	String investorID;
	//自动挂起标志	
	int isAutoSuspend;
	//互换单标志	
	int isSwapOrder;
	//最小成交量	
	int minVolume;
	//报单提示序号	
	int notifySequence;
	//本地报单编号	
	String orderLocalID;
	//报单价格条件	
	String orderPriceType;
	//报单引用	
	String orderRef;
	//报单状态	
	String orderStatus;
	//报单来源	
	String orderSource;
	//报单提交状态	
	String orderSubmitStatus;
	//报单编号	
	String orderSysID;
	//报单类型	
	String orderType;
	//会员代码	
	String participantID;
	//相关报单	
	String relativeOrderSysID;
	//请求编号	
	int requestID;
	//序号	
	int sequenceNo;
	//会话编号	
	int sessionID;
	//结算编号	
	int settlementID;
	//状态信息	
	String statusMsg;
	//止损价	
	double stopPrice;
	//挂起时间	
	String suspendTime;
	//有效期类型	
	String timeCondition;
	//交易所交易员代码	
	String traderID;
	//交易日	
	String tradingDay;
	//最后修改时间	
	String updateTime;
	//用户强评标志	
	int userForceClose;
	//用户代码	
	String userID;
	//用户端产品信息	
	String userProductInfo;
	//成交量类型	
	String volumeCondition;
	//剩余数量	
	int volumeTotal;
	//数量	
	int volumeTotalOriginal;
	//今成交数量	
	int volumeTraded;
	//郑商所成交数量	
	int zCETotalTradedVolume;
};

//最新数据
class SecurityLatestData{
public:
	//触发日
	String actionDay;
	//卖价
    double askPrice1;
	//卖价
    double askPrice2;
	//卖价
    double askPrice3;
	//卖价
    double askPrice4;
	//卖价
    double askPrice5;
	//卖量
    int askVolume1;
	//卖量
    int askVolume2;
	//卖量
    int askVolume3;
	//卖量
    int askVolume4;
	//卖量
    int askVolume5;
	//平均价格
    double averagePrice;
	//买价
    double bidPrice1;
	//买价
    double bidPrice2;
	//买价
    double bidPrice3;
	//买价
    double bidPrice4;
	//买价
    double bidPrice5;
	//买量
    int bidVolume1;
	//买量
    int bidVolume2;
	//买量
    int bidVolume3;
	//买量
    int bidVolume4;
	//买量
    int bidVolume5;
	//最新价
    double close;
	//合约代码
    String code;
	//今虚实度
    double currDelta;
	//交易所ID
    String exchangeID;
	//交易所InstID
    String exchangeInstID;
	//最高价
    double high;
	//昨日收盘价
    double lastClose;
	//最低价
    double low;
	//跌停价
    double lowerLimit;
	//开盘价
    double open;
	//持仓量
    double openInterest;
	//昨收盘
    double preClose;
	//昨虚实度
    double preDelta;
	//昨持仓量
    double preOpenInterest;
	//上次结算价
    double preSettlementPrice;
	//本次结算价
    double settlementPrice;
	//交易日
    String tradingDay;
	//成交金额
    double turnover;
	//最后修改毫秒
    int updateMillisec;
	//最后修改时间
    String updateTime;
	//涨停价
    double upperLimit;
	//成交量
    int volume;
};

//CTP交易定义
class TradeRecord{
public:
	//经纪公司代码
	String brokerID;
	///经纪公司报单编号
	int brokerOrderSeq;
	///业务单元
	String businessUnit;
	///结算会员编号
	String clearingPartID;
	///客户代码
	String clientID;
	//合约代码
	String code;
	//买卖方向
	String direction;
	//市场代码
	String exchangeID;
	//合约在交易所的代码
	String exchangeInstID;
	//投机套保标志
	String hedgeFlag;
	//投资者代码
	String investorID;
	//开平标志
	String offsetFlag;
	//本地报单编号
	String orderLocalID;
	//报单引用
	String orderRef;
	//报单编号
	String orderSysID;
	//会员代码
	String participantID;
	//价格
	double price;
	//成交价来源
	String priceSource;
	//序号
	int sequenceNo;
	//结算编号
	int settlementID;
	//成交编号
	String tradeID;
	//交易所交易员代码
	String traderID;
	//成交时期
	String tradeDate;
	//成交来源
	String tradeSource;
	//成交时间
	String tradeTime;
	//交易日
	String tradingDay;
	//成交类型
	String tradeType;
	//交易角色
	String tradingRole;
	//数量
	int volume;
	//用户代码
	String userID;
};

class CTPConvert{
public:
	//转换成CTP资金账户
	static AccountData convertToCTPTradingAccount(String result);
	//转换CTP合约信息
	static vector<Security> convertToCTPInstrumentDatas(String str);
	//转换CTP深度市场数据
	static vector<SecurityLatestData> convertToCTPDepthMarketData(String result);
	//转换CTP持仓信息
	static vector<InvestorPosition> convertToCTPInvestorPosition(String result);
	//转换CTP持仓明细信息
	static vector<InvestorPositionDetail> convertToCTPInvestorPositionDetail(String result);
	// 转换CTP报单信息
	static vector<OrderInfo> convertToCTPOrderList(String result);
	// 转换CTP报单信息
	static OrderInfo convertToCTPOrder(String result);
	//转换CTP交易信息
	static TradeRecord convertToCTPTrade(String result);
	//转换CTP交易信息列表
	static vector<TradeRecord> convertToCTPTradeRecords(String result);
};

#endif