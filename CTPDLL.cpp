#include "stdafx.h"
#include "CTPDLL.h"

HINSTANCE hdll = 0;
funcAskClose m_funcAskClose;
funcAskCloseToday m_funcAskCloseToday;
funcAskOpen m_funcAskOpen;
funcBidClose m_funcBidClose;
funcBidCloseToday m_funcBidCloseToday;
funcBidOpen m_funcBidOpen;
funcCancelOrder m_funcCancelOrder;
funcCreate m_funcCreate;
funcGenerateReqID m_funcGenerateReqID;
funcGetAccountData m_funcGetAccountData;
funcGetBrokerID m_funcGetBrokerID;
funcGetCommissionRate m_funcGetCommissionRate;
funcGetDepthMarketData m_funcGetDepthMarketData;
funcGetInstrumentsData m_funcGetInstrumentsData;
funcGetInvestorID m_funcGetInvestorID;
funcGetMarginRate m_funcGetMarginRate;
funcGetPositionData m_funcGetPositionData;
funcGetPositionDetailData m_funcGetPositionDetailData;
funcGetOrderInfo m_funcGetOrderInfo;
funcGetOrderInfos m_funcGetOrderInfos;
funcGetPassword m_funcGetPassword;
funcGetSessionID m_funcGetSessionID;
funcGetTradeRecord m_funcGetTradeRecord;
funcGetTradeRecords m_funcGetTradeRecords;
funcGetTradingDate m_funcGetTradingDate;
funcGetTradingTime m_funcGetTradingTime;
funcHasNewDatas m_funcHasNewDatas;
funcIsClearanced m_funcIsClearanced;
funcIsClearanceTime m_funcIsClearanceTime;
funcIsDataOk m_funcIsDataOk;
funcIsMdLogined m_funcIsMdLogined;
funcIsTdLogined m_funcIsTdLogined;
funcIsTradingTime m_funcIsTradingTime;
funcIsTradingTimeExact m_funcIsTradingTimeExact;
funcReqCommissionRate m_funcReqCommissionRate;
funcReqQrySettlementInfoConfirm m_funcReqQrySettlementInfoConfirm;
funcReqQrySettlementInfo m_funcReqQrySettlementInfo;
funcReqMarginRate m_funcReqMarginRate;
funcStart m_funcStart;
funcSubMarketDatas m_funcSubMarketDatas;
funcUnSubMarketDatas m_funcUnSubMarketDatas;

string CTPDLL::getProgramDir(){
	char exeFullPath[MAX_PATH]; 
	string strPath = "";
	GetModuleFileNameA(0, exeFullPath, MAX_PATH);
	strPath = (string)exeFullPath; 
	int pos = (int)strPath.find_last_of('\\', strPath.length());
	strPath = strPath.substr(0, pos);
	return strPath;
}

void CTPDLL::init(){
	string path = getProgramDir() + "\\iCTP.dll";
	hdll = LoadLibraryA(path.c_str());
	m_funcAskClose = (funcAskClose)GetProcAddress(hdll, "askClose");
	m_funcAskCloseToday = (funcAskCloseToday)GetProcAddress(hdll, "askCloseToday");
	m_funcAskOpen = (funcAskOpen)GetProcAddress(hdll, "askOpen");
	m_funcBidClose = (funcBidClose)GetProcAddress(hdll, "bidClose");
	m_funcBidCloseToday = (funcBidCloseToday)GetProcAddress(hdll, "bidCloseToday");
	m_funcBidOpen = (funcBidOpen)GetProcAddress(hdll, "bidOpen");
	m_funcCancelOrder = (funcCancelOrder)GetProcAddress(hdll, "cancelOrder");
	m_funcCreate = (funcCreate)GetProcAddress(hdll, "create");
	m_funcGenerateReqID = (funcGenerateReqID)GetProcAddress(hdll, "generateReqID");
	m_funcGetAccountData = (funcGetAccountData)GetProcAddress(hdll, "getAccountData");
	m_funcGetBrokerID = (funcGetBrokerID)GetProcAddress(hdll, "getBrokerID");
	m_funcGetCommissionRate = (funcGetCommissionRate)GetProcAddress(hdll, "getCommissionRate");
	m_funcGetDepthMarketData = (funcGetDepthMarketData)GetProcAddress(hdll, "getDepthMarketData");
	m_funcGetInstrumentsData = (funcGetInstrumentsData)GetProcAddress(hdll, "getInstrumentsData");
	m_funcGetInvestorID = (funcGetInvestorID)GetProcAddress(hdll, "getInvestorID");
	m_funcGetMarginRate = (funcGetMarginRate)GetProcAddress(hdll, "getMarginRate");
	m_funcGetPositionData = (funcGetPositionData)GetProcAddress(hdll, "getPositionData");
	m_funcGetPositionDetailData = (funcGetPositionDetailData)GetProcAddress(hdll, "getPositionDetailData");
	m_funcGetOrderInfo = (funcGetOrderInfo)GetProcAddress(hdll, "getOrderInfo");
	m_funcGetOrderInfos = (funcGetOrderInfos)GetProcAddress(hdll, "getOrderInfos");
	m_funcGetPassword = (funcGetPassword)GetProcAddress(hdll, "getPassword");
	m_funcGetSessionID = (funcGetSessionID)GetProcAddress(hdll, "getSessionID");
	m_funcGetTradeRecord = (funcGetTradeRecord)GetProcAddress(hdll, "getTradeRecord");
	m_funcGetTradeRecords = (funcGetTradeRecords)GetProcAddress(hdll, "getTradeRecords");
	m_funcGetTradingDate = (funcGetTradingDate)GetProcAddress(hdll, "getTradingDate");
	m_funcGetTradingTime = (funcGetTradingTime)GetProcAddress(hdll, "getTradingTime");
	m_funcHasNewDatas = (funcHasNewDatas)GetProcAddress(hdll, "hasNewDatas");
	m_funcIsClearanced = (funcIsClearanced)GetProcAddress(hdll, "isClearanced");
	m_funcIsClearanceTime = (funcIsClearanceTime)GetProcAddress(hdll, "isClearanceTime");
	m_funcIsDataOk = (funcIsDataOk)GetProcAddress(hdll, "isDataOk");
	m_funcIsMdLogined = (funcIsMdLogined)GetProcAddress(hdll, "isMdLogined");
	m_funcIsTdLogined = (funcIsTdLogined)GetProcAddress(hdll, "isTdLogined");
	m_funcIsTradingTime = (funcIsTradingTime)GetProcAddress(hdll, "isTradingTime");
	m_funcIsTradingTimeExact = (funcIsTradingTimeExact)GetProcAddress(hdll, "isTradingTimeExact");
	m_funcReqCommissionRate = (funcReqCommissionRate)GetProcAddress(hdll, "reqCommissionRate");
	m_funcReqQrySettlementInfoConfirm = (funcReqQrySettlementInfoConfirm)GetProcAddress(hdll, "reqQrySettlementInfoConfirm");
	m_funcReqQrySettlementInfo = (funcReqQrySettlementInfo)GetProcAddress(hdll, "reqQrySettlementInfo");
	m_funcReqMarginRate = (funcReqMarginRate)GetProcAddress(hdll, "reqMarginRate");
	m_funcStart = (funcStart)GetProcAddress(hdll, "start");
	m_funcSubMarketDatas = (funcSubMarketDatas)GetProcAddress(hdll, "subMarketDatas");
	m_funcUnSubMarketDatas = (funcUnSubMarketDatas)GetProcAddress(hdll, "unSubMarketDatas");
}

int CTPDLL::askClose(int ctpID, int requestID, char *code, char *exchangeID, double price, int qty, char timeCondition, char *orderRef){
	if(!hdll){
		init();
	}
	return m_funcAskClose(ctpID, requestID, code, exchangeID, price, qty, timeCondition, orderRef);
}

int CTPDLL::askCloseToday(int ctpID, int requestID, char *code, char *exchangeID, double price, int qty, char timeCondition, char *orderRef){
	if(!hdll){
		init();
	}
	return m_funcAskCloseToday(ctpID, requestID, code, exchangeID, price, qty, timeCondition, orderRef);
}

int CTPDLL::askOpen(int ctpID, int requestID, char *code, char *exchangeID, double price, int qty, char timeCondition, char *orderRef){
	if(!hdll){
		init();
	}
	return m_funcAskOpen(ctpID, requestID, code, exchangeID, price, qty, timeCondition, orderRef);
}

int CTPDLL::bidClose(int ctpID, int requestID, char* code, char *exchangeID, double price, int qty, char timeCondition, char* orderRef){
	if(!hdll){
		init();
	}
	return m_funcBidClose(ctpID, requestID, code, exchangeID, price, qty, timeCondition, orderRef);
}

int CTPDLL::bidCloseToday(int ctpID, int requestID, char* code, char *exchangeID, double price, int qty, char timeCondition, char* orderRef){
	if(!hdll){
		init();
	}
	return m_funcBidCloseToday(ctpID, requestID, code, exchangeID, price, qty, timeCondition, orderRef);
}

int CTPDLL::bidOpen(int ctpID, int requestID, char *code, char *exchangeID, double price, int qty, char timeCondition, char *orderRef){
	if(!hdll){
		init();
	}
	return m_funcBidOpen(ctpID, requestID, code, exchangeID, price, qty, timeCondition, orderRef);
}

int CTPDLL::cancelOrder(int ctpID, int requestID, char *exchangeID, char *orderSysID, char *orderRef){
	if(!hdll){
		init();
	}
	return m_funcCancelOrder(ctpID, requestID, exchangeID, orderSysID, orderRef);
}

int CTPDLL::create(){
	if(!hdll){
		init();
	}
	return m_funcCreate();
}

int CTPDLL::generateReqID(int ctpID){
	if(!hdll){
		init();
	}
	return m_funcGenerateReqID(ctpID);
}

int CTPDLL::getAccountData(int ctpID, char *data){
	if(!hdll){
		init();
	}
	return m_funcGetAccountData(ctpID, data);
}

int CTPDLL::getBrokerID(int ctpID, char *data){
	if(!hdll){
		init();
	}
	return m_funcGetBrokerID(ctpID, data);
}

int CTPDLL::getCommissionRate(int ctpID, char *code, char *data){
	if(!hdll){
		init();
	}
	return m_funcGetCommissionRate(ctpID, code, data);
}

int CTPDLL::getDepthMarketData(int ctpID, char *data){
	if(!hdll){
		init();
	}
	return m_funcGetDepthMarketData(ctpID, data);
}

int CTPDLL::getInstrumentsData(int ctpID, char *data){
	if(!hdll){
		init();
	}
	return m_funcGetInstrumentsData(ctpID, data);
}

int CTPDLL::getInvestorID(int ctpID, char* data){
	if(!hdll){
		init();
	}
	return m_funcGetInvestorID(ctpID, data);
}

int CTPDLL::getMarginRate(int ctpID, char* code, char* data){
	if(!hdll){
		init();
	}
	return m_funcGetMarginRate(ctpID, code, data);
}

int CTPDLL::getPositionData(int ctpID, char* data){
	if(!hdll){
		init();
	}
	return m_funcGetPositionData(ctpID, data);
}

int CTPDLL::getPositionDetailData(int ctpID, char* data){
	if(!hdll){
		init();
	}
	return m_funcGetPositionDetailData(ctpID, data);
}

int CTPDLL::getOrderInfo(int ctpID, char* data){
	if(!hdll){
		init();
	}
	return m_funcGetOrderInfo(ctpID, data);
}

int CTPDLL::getOrderInfos(int ctpID, char* data){
	if(!hdll){
		init();
	}
	return m_funcGetOrderInfos(ctpID, data);
}

int CTPDLL::getPassword(int ctpID, char* data){
	if(!hdll){
		init();
	}
	return m_funcGetPassword(ctpID, data);
}

int CTPDLL::getSessionID(int ctpID){
	if(!hdll){
		init();
	}
	return m_funcGetSessionID(ctpID);
}

int CTPDLL::getTradeRecord(int ctpID, char* data){
	if(!hdll){
		init();
	}
	return m_funcGetTradeRecord(ctpID, data);
}

int CTPDLL::getTradeRecords(int ctpID, char* data){
	if(!hdll){
		init();
	}
	return m_funcGetTradeRecords(ctpID, data);
}

int CTPDLL::getTradingDate(int ctpID, char* data){
	if(!hdll){
		init();
	}
	return m_funcGetTradingDate(ctpID, data);
}

int CTPDLL::getTradingTime(int ctpID, char* data){
	if(!hdll){
		init();
	}
	return m_funcGetTradingTime(ctpID, data);
}

int CTPDLL::hasNewDatas(int ctpID){
	if(!hdll){
		init();
	}
	return m_funcHasNewDatas(ctpID);
}

int CTPDLL::isClearanced(int ctpID){
	if(!hdll){
		init();
	}
	return m_funcIsClearanced(ctpID);
}

int CTPDLL::isClearanceTime(int ctpID){
	if(!hdll){
		init();
	}
	return m_funcIsClearanceTime(ctpID);
}

int CTPDLL::isDataOk(int ctpID){
	if(!hdll){
		init();
	}
	return m_funcIsDataOk(ctpID);
}

int CTPDLL::isMdLogined(int ctpID){
	if(!hdll){
		init();
	}
	return m_funcIsMdLogined(ctpID);
}

int CTPDLL::isTdLogined(int ctpID){
	if(!hdll){
		init();
	}
	return m_funcIsTdLogined(ctpID);
}

int CTPDLL::isTradingTime(int ctpID){
	if(!hdll){
		init();
	}
	return m_funcIsTradingTime(ctpID);
}

int CTPDLL::isTradingTimeExact(int ctpID, char* code){
	if(!hdll){
		init();
	}
	return m_funcIsTradingTimeExact(ctpID, code);
}

int CTPDLL::reqCommissionRate(int ctpID, char* code, int requestID){
	if(!hdll){
		init();
	}
	return m_funcReqCommissionRate(ctpID, code, requestID);
}

int CTPDLL::reqQrySettlementInfoConfirm(int ctpID, int requestID){
	if(!hdll){
		init();
	}
	return m_funcReqQrySettlementInfoConfirm(ctpID, requestID);
}

int CTPDLL::reqQrySettlementInfo(int ctpID, int requestID, char* tradingDate){
	if(!hdll){
		init();
	}
	return m_funcReqQrySettlementInfo(ctpID, requestID, tradingDate);
}

int CTPDLL::reqMarginRate(int ctpID, char* code, int requestID){
	if(!hdll){
		init();
	}
	return m_funcReqMarginRate(ctpID, code, requestID);
}

int CTPDLL::start(int ctpID, int requestID, char *appID, char *authCode, char* mdServer, char* tdServer, char* brokerID, char* investorID, char* password){
	if(!hdll){
		init();
	}
	return m_funcStart(ctpID, requestID, appID, authCode, mdServer, tdServer, brokerID, investorID, password);
}

int CTPDLL::subMarketDatas(int ctpID, int requestID, char* codes){
	if(!hdll){
		init();
	}
	return m_funcSubMarketDatas(ctpID, requestID, codes);
}

int CTPDLL::unSubMarketDatas(int ctpID, int requestID, char* codes){
	if(!hdll){
		init();
	}
	return m_funcUnSubMarketDatas(ctpID, requestID, codes);
}