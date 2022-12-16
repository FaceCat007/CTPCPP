#include "stdafx.h"
#include "CTP.h"
#include "CTPDLL.h"

CTP::CTP(){
	m_ctpID = 0;
}

CTP::~CTP(){

}

int CTP::getCtpID(){
	return m_ctpID;
}

void CTP::run(){
    int ctpID = CTPDLL::create();
    int ctpRequestID = CTPDLL::generateReqID(ctpID);
    CTPDLL::start(ctpID, ctpRequestID, "simnow_client_test", "0000000000000000", "180.168.146.187:10212", "180.168.146.187:10202", "9999", "021739", "123456");
	while (CTPDLL::isDataOk(ctpID) <= 0){
        Sleep(1000);
    }
    ctpRequestID = CTPDLL::generateReqID(ctpID);
    CTPDLL::subMarketDatas(ctpID, ctpRequestID, "cu2301,cu2302");
    while (true){
		if(CTPDLL::hasNewDatas(ctpID) > 0){
			char data[1024000] ={0};
			if (CTPDLL::getDepthMarketData(ctpID, data) > 0){
				String str = FCStrEx::stringTowstring(data);
				vector<SecurityLatestData> latestData = CTPConvert::convertToCTPDepthMarketData(str);
				onSecurityLatestDataCallBack(&latestData, ctpID);
				continue;
			}
			if (CTPDLL::getInstrumentsData(ctpID, data) > 0){
				String str = FCStrEx::stringTowstring(data);
				vector<Security> instrumentDatas = CTPConvert::convertToCTPInstrumentDatas(str);
				onSecurityCallBack(&instrumentDatas, ctpID);
				continue;
			}
			if (CTPDLL::getAccountData(ctpID, data) > 0){
				String str = FCStrEx::stringTowstring(data);
				AccountData accountData = CTPConvert::convertToCTPTradingAccount(str);
				onAccountDataCallBack(&accountData, ctpID);
				continue;
			}
			if (CTPDLL::getOrderInfo(ctpID, data) > 0){
				String str = FCStrEx::stringTowstring(data);
				OrderInfo orderInfo = CTPConvert::convertToCTPOrder(str);
				onOrderInfoCallBack(&orderInfo, ctpID);
				continue;
			}
			if (CTPDLL::getOrderInfos(ctpID, data) > 0){
				String str = FCStrEx::stringTowstring(data);
				vector<OrderInfo> orderInfos = CTPConvert::convertToCTPOrderList(str);
				onOrderInfosCallBack(&orderInfos, ctpID);
				continue;
			}
			if (CTPDLL::getTradeRecord(ctpID, data) > 0){
				String str = FCStrEx::stringTowstring(data);
				TradeRecord tradeRecord = CTPConvert::convertToCTPTrade(str);
				onTradeRecordCallBack(&tradeRecord, ctpID);
				continue;
			}
			if (CTPDLL::getTradeRecords(ctpID, data) > 0){
				String str = FCStrEx::stringTowstring(data);
				vector<TradeRecord> tradeRecords = CTPConvert::convertToCTPTradeRecords(str);
				onTradeRecordsCallBack(&tradeRecords, ctpID);
				continue;
			}
			if (CTPDLL::getPositionData(ctpID, data) > 0){
				String str = FCStrEx::stringTowstring(data);
				vector<InvestorPosition> investorPositions = CTPConvert::convertToCTPInvestorPosition(str);
				onInvestorPositionCallBack(&investorPositions, ctpID);
				continue;
			}
			if (CTPDLL::getPositionDetailData(ctpID, data) > 0){
				String str = FCStrEx::stringTowstring(data);
				vector<InvestorPositionDetail> investorPositionDetails = CTPConvert::convertToCTPInvestorPositionDetail(str);
				onInvestorPositionDetailCallBack(&investorPositionDetails, ctpID);
				continue;
			}
		}else{
			Sleep(1);
		}
    }
}

void CTP::setCtpID(int ctpID){
	m_ctpID = ctpID;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CTP::onAccountDataCallBack(AccountData *data, int ctpID){

}
void CTP::onInvestorPositionCallBack(vector<InvestorPosition> *data, int ctpID){

}
void CTP::onInvestorPositionDetailCallBack(vector<InvestorPositionDetail> *data, int ctpID){

}
void CTP::onOrderInfoCallBack(OrderInfo *data, int ctpID){

}
void CTP:: onOrderInfosCallBack(vector<OrderInfo> *data, int ctpID){

}

void CTP::onSecurityCallBack(vector<Security> *data, int ctpID){
}

void CTP::onSecurityLatestDataCallBack(vector<SecurityLatestData> *data, int ctpID){
	for(int i = 0; i < data->size(); i++){
		SecurityLatestData lData = (*data)[i];
		printf("%s=%.2f\r\n", lData.code.c_str(), lData.close);
	}
}
void CTP::onTradeRecordCallBack(TradeRecord *data, int ctpID){

}
void CTP::onTradeRecordsCallBack(vector<TradeRecord> *tradeRecords, int ctpID){

}