#include "stdafx.h"
#include "MainFrame.h"

MainFrame::MainFrame(){
	m_timerID = FCView::getNewTimerID();
	m_ctpID = 0;
}

MainFrame::~MainFrame(){
}



void MainFrame::loadFile(const String& fileName, FCView *view){
	FCUIXml::loadFile(fileName, view);
	findView(L"cbInvestorPosition")->addEvent((FCTouchEventCallBack*)this, FCEventID_Click, this);
    findView(L"cbInvestorPositionDetail")->addEvent((FCTouchEventCallBack*)this, FCEventID_Click, this);
    findView(L"btnOrder")->addEvent((FCTouchEventCallBack*)this, FCEventID_Click, this);
    findView(L"btnCancelOrder2")->addEvent((FCTouchEventCallBack*)this, FCEventID_Click, this);

    getGrid(L"gridLatestData")->addEvent((FCGridCellTouchEventCallBack*)this, FCEventID_GridCellClick, this);
    getGrid(L"gridInvestorPosition")->addEvent((FCGridCellTouchEventCallBack*)this, FCEventID_GridCellClick, this);
    getGrid(L"gridInvestorPositionDetail")->addEvent((FCGridCellTouchEventCallBack*)this, FCEventID_GridCellClick, this);

    FCChart *chart = getChart(L"chart");
    chart->setRightVScaleWidth(80);
    chart->setLeftVScaleWidth(0);

    ChartDiv *candleDiv = chart->addDiv(60);
    candleDiv->getHScale()->setHeight(0);
    candleDiv->getHScale()->setVisible(false);
    candleDiv->setBackColor(FCColor_Back);
    ChartDiv *volDiv = chart->addDiv(40);
    volDiv->getHScale()->setHeight(20);
    volDiv->getHScale()->setVisible(true);
    volDiv->setBackColor(FCColor_Back);
	candleDiv->getTitleBar()->m_titles.add(new ChartTitle(0, L"CLOSE", FCColor::rgb(255, 255, 255), 0, true));
	volDiv->getTitleBar()->m_titles.add(new ChartTitle(1, L"VOL", FCColor::rgb(255, 255, 255), 0, true));

    FCDataTable *dataSource = chart->getDataSource();
    dataSource->addColumn(0);
    dataSource->addColumn(1);

    PolylineShape *ps = new PolylineShape();
    ps->setFieldName(0);
    ps->setFieldText(L"CLOSE");
    candleDiv->addShape(ps);

    BarShape *bs = new BarShape();
    bs->setFieldName(1);
    bs->setFieldText(L"VOL");
    volDiv->addShape(bs);
    loginCTP(L"simnow_client_test", L"0000000000000000", L"180.168.146.187:10212", L"180.168.146.187:10202", L"9999", L"021739", L"123456");
}

void MainFrame::callGridCellTouchEvent(String eventName, Object sender, FCGridCell *cell, FCTouchInfo touchInfo, Object invoke){
	FCGrid *grid = (FCGrid*)sender;
    String gridName = grid->getName();
    if (gridName == L"gridLatestData")
    {
        FCChart *chart = getChart(L"chart");
        chart->clear();
        chart->update();
        String code = cell->getRow()->getCell(0)->getString();
        m_currentCode = code;
        String price = cell->getRow()->getCell(2)->getString();
        FCView *txtIssueCode = findView(L"txtIssueCode");
        FCView *spinPrice = findView(L"spinPrice");
        FCView *spinVolume = findView(L"spinVolume");
        txtIssueCode->setText(code);
        spinPrice->setText(price);
        spinVolume->setText(L"1");
        getNative()->invalidate();
    }
    else if (gridName == L"gridInvestorPosition")
    {
        String code = cell->getRow()->getCell(0)->getString();
        FCView *txtIssueCode = findView(L"txtIssueCode");
        FCView *spinPrice = findView(L"spinPrice");
        FCView *spinVolume = findView(L"spinVolume");
        String price = L"";
		int digit = 0;
		if (m_allCodes.find(code) != m_allCodes.end())
        {
			digit = m_allCodes[code].digit;
		}
        if (m_allDatas.find(code) != m_allDatas.end())
        {
			price = FCTran::getValueByDigit(m_allDatas[code].close, digit);
        }
        txtIssueCode->setText(code);
        spinPrice->setText(price);
        spinVolume->setText(L"1");
        getNative()->invalidate();
    }
    else if (gridName == L"gridInvestorPositionDetail")
    {
        String code = cell->getRow()->getCell(1)->getString();
        FCView *txtIssueCode = findView(L"txtIssueCode");
        FCView *spinPrice = findView(L"spinPrice");
        FCView *spinVolume = findView(L"spinVolume");
        String price = L"";
        int digit = 0;
		if (m_allCodes.find(code) != m_allCodes.end())
        {
			digit = m_allCodes[code].digit;
		}
        if (m_allDatas.find(code) != m_allDatas.end())
        {
			price = FCTran::getValueByDigit(m_allDatas[code].close, digit);
        }
        txtIssueCode->setText(code);
        spinPrice->setText(price);
        spinVolume->setText(L"1");
        getNative()->invalidate();
    }
}

void MainFrame::checkCTPData(){
	char *data = new char[102400];
	memset(data, '\0', 102400);
	while (CTPDLL::hasNewDatas(m_ctpID) > 0){
		memset(data, '\0', 102400);
		if (CTPDLL::getDepthMarketData(m_ctpID, data) > 0){
			String str = FCStrEx::stringTowstring(data);
			vector<SecurityLatestData> latestData = CTPConvert::convertToCTPDepthMarketData(str);
			onSecurityLatestDataCallBack(&latestData, m_ctpID);
			continue;
		}
		if (CTPDLL::getAccountData(m_ctpID, data) > 0){
			String str = FCStrEx::stringTowstring(data);
			AccountData accountData = CTPConvert::convertToCTPTradingAccount(str);
			onAccountDataCallBack(&accountData, m_ctpID);
			continue;
		}
		if (CTPDLL::getOrderInfo(m_ctpID, data) > 0){
			String str = FCStrEx::stringTowstring(data);
			OrderInfo orderInfo = CTPConvert::convertToCTPOrder(str);
			onOrderInfoCallBack(&orderInfo, m_ctpID);
			continue;
		}
		if (CTPDLL::getTradeRecord(m_ctpID, data) > 0){
			String str = FCStrEx::stringTowstring(data);
			TradeRecord tradeRecord = CTPConvert::convertToCTPTrade(str);
			onTradeRecordCallBack(&tradeRecord, m_ctpID);
			continue;
		}
		if (CTPDLL::getPositionData(m_ctpID, data) > 0){
			String str = FCStrEx::stringTowstring(data);
			vector<InvestorPosition> investorPositions = CTPConvert::convertToCTPInvestorPosition(str);
			onInvestorPositionCallBack(&investorPositions, m_ctpID);
			continue;
		}
		if (CTPDLL::getPositionDetailData(m_ctpID, data) > 0){
			String str = FCStrEx::stringTowstring(data);
			vector<InvestorPositionDetail> investorPositionDetails = CTPConvert::convertToCTPInvestorPositionDetail(str);
			onInvestorPositionDetailCallBack(&investorPositionDetails, m_ctpID);
			continue;
		}
		break;
	}
	delete[] data;
	data = 0;
}

void MainFrame::callTimerEvent(String eventName, Object sender, int timerID, Object invoke){
	if(timerID == m_timerID){
        checkCTPData();
    }
}

void MainFrame::loginCTP(String appID, String authCode, String mdServer, String tdServer, String brokerID, String investorID, String password){
	m_ctpID = CTPDLL::create();
	int reqID = CTPDLL::generateReqID(m_ctpID);
	CTPDLL::start(m_ctpID, reqID, (char*)FCTran::StringTostring(appID).c_str(), (char*)FCTran::StringTostring(authCode).c_str(), (char*)FCTran::StringTostring(mdServer).c_str(), (char*)FCTran::StringTostring(tdServer).c_str(), (char*)FCTran::StringTostring(brokerID).c_str(), (char*)FCTran::StringTostring(investorID).c_str(), (char*)FCTran::StringTostring(password).c_str());
	while (CTPDLL::isDataOk(m_ctpID) <= 0)
    {
        ::Sleep(1);
    }
	char *bigData = new char[1024 * 1024 * 10];
	memset(bigData, '\0', 1024 * 1024 * 10);
	if (CTPDLL::getInstrumentsData(m_ctpID, bigData) > 0){
		String str = FCStrEx::stringTowstring(bigData);
		vector<Security> instrumentDatas = CTPConvert::convertToCTPInstrumentDatas(str);
		onSecurityCallBack(&instrumentDatas, m_ctpID);
	}
	memset(bigData, '\0', 1024 * 1024 * 10);
	if (CTPDLL::getOrderInfos(m_ctpID, bigData) > 0){
		String str = FCStrEx::stringTowstring(bigData);
		vector<OrderInfo> orderInfos = CTPConvert::convertToCTPOrderList(str);
		onOrderInfosCallBack(&orderInfos, m_ctpID);
	}
	memset(bigData, '\0', 1024 * 1024 * 10);
	if (CTPDLL::getTradeRecords(m_ctpID, bigData) > 0){
		String str = FCStrEx::stringTowstring(bigData);
		vector<TradeRecord> tradeRecords = CTPConvert::convertToCTPTradeRecords(str);
		onTradeRecordsCallBack(&tradeRecords, m_ctpID);
	}
	delete[] bigData;
	bigData = 0;
	reqID = CTPDLL::generateReqID(m_ctpID);
	CTPDLL::subMarketDatas(m_ctpID, reqID, "cu2301,cu2302,cu2303,rb2301,rb2302,rb2304,ru2301,ru2302,ru2303");
    FCChart *chart = getChart(L"chart");
    chart->addEvent((FCTimerEventCallBack*)this, FCEventID_Timer, this);
    chart->startTimer(m_timerID, 1);
}

void MainFrame::callTouchEvent(String eventName, Object sender, FCTouchInfo touchInfo, Object invoke){
	if (touchInfo.m_firstTouch && touchInfo.m_clicks == 1)
    {
        FCView *control = (FCView*)sender;
        String name = control->getName();
        if (name == L"cbInvestorPosition")
        {
            FCGrid *gridInvestorPosition = getGrid(L"gridInvestorPosition");
            FCGrid *gridInvestorPositionDetail = getGrid(L"gridInvestorPositionDetail");
            gridInvestorPosition->m_visible = true;
            gridInvestorPositionDetail->m_visible = false;
            gridInvestorPosition->update();
            gridInvestorPosition->invalidate();
        }
        else if (name == L"cbInvestorPositionDetail")
        {
            FCGrid *gridInvestorPosition = getGrid(L"gridInvestorPosition");
            FCGrid *gridInvestorPositionDetail = getGrid(L"gridInvestorPositionDetail");
            gridInvestorPosition->m_visible = false;
            gridInvestorPositionDetail->m_visible = true;
            gridInvestorPositionDetail->update();
            gridInvestorPositionDetail->invalidate();
        }
        else if (name == L"btnOrder")
        {
            FCView *txtIssueCode = findView(L"txtIssueCode");
            FCView *spinVolume = findView(L"spinVolume");
            FCView *spinPrice = findView(L"spinPrice");
            FCRadioButton *rbBuy = getRadioButton(L"rbBuy");
            FCRadioButton *rbSell = getRadioButton(L"rbSell");
            FCRadioButton *rbOpen = getRadioButton(L"rbOpen");
            FCRadioButton *rbCloseToday = getRadioButton(L"rbCloseToday");
            FCRadioButton *rbClose = getRadioButton(L"rbClose");
            String issueCode = txtIssueCode->getText();
            if (m_allCodes.find(issueCode) != m_allCodes.end())
            {
                String exchangeID = m_allCodes[issueCode].exchangeID;
				int volume = FCTran::strToInt(spinVolume->getText());
				double price = FCTran::strToDouble(spinPrice->getText());
                String bCode = issueCode;
                String bExchangeID = exchangeID;
                double bPrice = price;
                int bVolume = volume;
                char bCondition = '3';
                if (rbBuy->isChecked())
                {
                    if (rbOpen->isChecked())
                    {
						CTPDLL::bidOpen(m_ctpID, CTPDLL::generateReqID(m_ctpID), (char*)FCTran::StringTostring(bCode).c_str(), (char*)FCTran::StringTostring(bExchangeID).c_str(), bPrice, bVolume, bCondition, "");
                    }
                    else if (rbCloseToday->isChecked())
                    {
						CTPDLL::bidCloseToday(m_ctpID, CTPDLL::generateReqID(m_ctpID), (char*)FCTran::StringTostring(bCode).c_str(), (char*)FCTran::StringTostring(bExchangeID).c_str(), bPrice, bVolume, bCondition, "");
                    }
                    else if (rbClose->isChecked())
                    {
						CTPDLL::bidClose(m_ctpID, CTPDLL::generateReqID(m_ctpID), (char*)FCTran::StringTostring(bCode).c_str(), (char*)FCTran::StringTostring(bExchangeID).c_str(), bPrice, bVolume, bCondition, "");
                    }
                }
                else
                {
                    if (rbOpen->isChecked())
                    {
						CTPDLL::askOpen(m_ctpID, CTPDLL::generateReqID(m_ctpID), (char*)FCTran::StringTostring(bCode).c_str(), (char*)FCTran::StringTostring(bExchangeID).c_str(), bPrice, bVolume, bCondition, "");
                    }
                    else if (rbCloseToday->isChecked())
                    {
						CTPDLL::askCloseToday(m_ctpID, CTPDLL::generateReqID(m_ctpID), (char*)FCTran::StringTostring(bCode).c_str(), (char*)FCTran::StringTostring(bExchangeID).c_str(), bPrice, bVolume, bCondition, "");
                    }
                    else if (rbClose->isChecked())
                    {
						CTPDLL::askClose(m_ctpID, CTPDLL::generateReqID(m_ctpID), (char*)FCTran::StringTostring(bCode).c_str(), (char*)FCTran::StringTostring(bExchangeID).c_str(), bPrice, bVolume, bCondition, "");
                    }
                }
            }
        }else if (name == L"btnCancelOrder2")
        {
            FCGrid *gridOrder = getGrid(L"gridOrder");
            ArrayList<FCGridRow*> selectedRows = gridOrder->getSelectedRows();
            if (selectedRows.size() > 0)
            {
                String orderSysID = selectedRows.get(0)->getCell(0)->getString();
                String exchangeID = selectedRows.get(0)->getCell(16)->getString();
				CTPDLL::cancelOrder(m_ctpID, CTPDLL::generateReqID(m_ctpID), (char*)FCTran::StringTostring(exchangeID).c_str(), (char*)FCTran::StringTostring(orderSysID).c_str(), "");
            }
        }
    }
}

void MainFrame::onAccountDataCallBack(AccountData *data, int ctpID){
	FCGrid *gridTradeAccount = getGrid(L"gridTradeAccount");
    gridTradeAccount->m_headerHeight = 30;
    gridTradeAccount->m_showHScrollBar = true;
    gridTradeAccount->getRowStyle()->setSelectedBackColor(FCColor_None);
    gridTradeAccount->setGridLineColor(FCColor_None);
    for (int i = 0; i < gridTradeAccount->m_columns.size(); i++)
    {
        gridTradeAccount->m_columns.get(i)->m_allowSort = false;
        gridTradeAccount->m_columns.get(i)->setWidth(140);
    }
    FCGridRow *row = 0;
    if (gridTradeAccount->m_rows.size() == 0)
    {
        row = new FCGridRow();
        row->setHeight(30);
        gridTradeAccount->addRow(row);
        for (int i = 0; i < gridTradeAccount->m_columns.size(); i++)
        {
            FCGridStringCell *cell1 = new FCGridStringCell();
            row->addCell(i, cell1);
        }
    }
    gridTradeAccount->m_rows.get(0)->m_cells.get(0)->setString(FCTran::getValueByDigit(data->balance, 0));
    gridTradeAccount->m_rows.get(0)->m_cells.get(1)->setString(FCTran::getValueByDigit(data->closeProfit, 0));
    setCellStyle2(gridTradeAccount->m_rows.get(0)->m_cells.get(1), data->closeProfit, 0);
    gridTradeAccount->m_rows.get(0)->m_cells.get(2)->setString(FCTran::getValueByDigit(data->floatProfit, 0));
    setCellStyle2(gridTradeAccount->m_rows.get(0)->m_cells.get(2), data->floatProfit, 0);
    gridTradeAccount->m_rows.get(0)->m_cells.get(3)->setString(FCTran::getValueByDigit(data->positionProfit, 0));
    setCellStyle2(gridTradeAccount->m_rows.get(0)->m_cells.get(3), data->positionProfit, 0);
    gridTradeAccount->m_rows.get(0)->m_cells.get(4)->setString(FCTran::getValueByDigit(data->dynamicBalance, 0));
    gridTradeAccount->m_rows.get(0)->m_cells.get(5)->setString(FCTran::getValueByDigit(data->currMargin, 0));
    gridTradeAccount->m_rows.get(0)->m_cells.get(6)->setString(FCTran::getValueByDigit(data->frozenCash, 0));
    gridTradeAccount->m_rows.get(0)->m_cells.get(7)->setString(FCTran::getValueByDigit(data->available, 0));
    gridTradeAccount->m_rows.get(0)->m_cells.get(8)->setString(FCTran::getValueByDigit(data->risk * 100, 2) + L"%");
    gridTradeAccount->m_rows.get(0)->m_cells.get(9)->setString(FCTran::getValueByDigit(data->frozenMargin, 0));
    gridTradeAccount->m_rows.get(0)->m_cells.get(10)->setString(FCTran::getValueByDigit(data->frozenCommission, 0));
    gridTradeAccount->m_rows.get(0)->m_cells.get(11)->setString(FCTran::getValueByDigit(data->commission, 0));
    gridTradeAccount->m_rows.get(0)->m_cells.get(12)->setString(FCTran::getValueByDigit(data->preBalance, 0));
    gridTradeAccount->m_rows.get(0)->m_cells.get(13)->setString(FCTran::getValueByDigit(data->preCredit, 0));
    gridTradeAccount->m_rows.get(0)->m_cells.get(14)->setString(FCTran::getValueByDigit(data->preMortgage, 0));
    gridTradeAccount->m_rows.get(0)->m_cells.get(15)->setString(FCTran::getValueByDigit(data->mortgage, 0));
    gridTradeAccount->m_rows.get(0)->m_cells.get(16)->setString(FCTran::getValueByDigit(data->withdraw, 0));
    gridTradeAccount->m_rows.get(0)->m_cells.get(17)->setString(FCTran::getValueByDigit(data->deposit, 0));
    gridTradeAccount->m_rows.get(0)->m_cells.get(18)->setString(FCTran::getValueByDigit(data->credit, 0));
    gridTradeAccount->m_rows.get(0)->m_cells.get(19)->setString(FCTran::getValueByDigit(data->reserveBalance, 0));
    gridTradeAccount->m_rows.get(0)->m_cells.get(20)->setString(FCTran::getValueByDigit(data->withdrawQuota, 0));
    gridTradeAccount->update();
    gridTradeAccount->invalidate();
}

void MainFrame::setCellStyle2(FCGridCell *cell, double value1, double value2){
	Long color = FCColor::rgb(255, 255, 255);
    if (value1 > value2)
    {
		color = FCColor::rgb(255, 0, 0);
    }
    else if (value1 < value2)
    {
		color = FCColor::rgb(0, 255, 0);
    }
    FCGridCellStyle *style = cell->getStyle();
    if (style == 0)
    {
		FCGridCellStyle newStyle;
		newStyle.m_textColor = color;
        cell->setStyle(&newStyle);
	}else{
		style->m_textColor = color;
	}
}

void MainFrame::onSecurityLatestDataCallBack(vector<SecurityLatestData> *data, int ctpID){
	FCGrid *gridLatestData = getGrid(L"gridLatestData");
    gridLatestData->setGridLineColor(FCColor_None);
    FCChart *chart = getChart(L"chart");
    FCDataTable *dataSource = chart->getDataSource();
    for (int d = 0; d < data->size(); d++)
    {
		SecurityLatestData &latestData = (*data)[d];
        FCGridRow *row = 0;
        for (int i = 0; i < gridLatestData->m_rows.size(); i++)
        {
            if (gridLatestData->m_rows.get(i)->m_cells.get(0)->getString() == latestData.code)
            {
                row = gridLatestData->m_rows.get(i);
                break;
            }
        }
        if (row == 0)
        {
            row = new FCGridRow();
            row->setHeight(30);
            gridLatestData->addRow(row);
            for (int j = 0; j < gridLatestData->m_columns.size(); j++)
            {
                FCGridStringCell *cell1 = new FCGridStringCell();
                row->addCell(j, cell1);
            }
        }
        row->m_cells.get(0)->setString(latestData.code);
        double newVol = 0;
        if (m_allDatas.find(latestData.code) != m_allDatas.end())
        {
            newVol = latestData.volume - m_allDatas[latestData.code].volume;
        }
        m_allDatas[latestData.code] = (*data)[d];
        int digit = 0;
        if (m_allCodes.find(latestData.code) != m_allCodes.end())
        {
            row->m_cells.get(1)->setString(m_allCodes[latestData.code].instrumentName);
            digit = m_allCodes[latestData.code].digit;
        }
		setCellStyle2(row->m_cells.get(2), FCTran::strToDouble(row->m_cells.get(2)->getString()), latestData.close);
        row->m_cells.get(2)->setString(FCTran::getValueByDigit(latestData.close, digit));
        double diff = latestData.close - latestData.preSettlementPrice;
        setCellStyle2(row->m_cells.get(3), diff, 0);
        row->m_cells.get(3)->setString(FCTran::getValueByDigit(diff, digit));
        setCellStyle2(row->m_cells.get(4), FCTran::strToDouble(row->m_cells.get(4)->getString()), latestData.bidPrice1);
        row->m_cells.get(4)->setString(FCTran::getValueByDigit(latestData.bidPrice1, digit));
		row->m_cells.get(5)->setString(FCTran::intToStr((int)latestData.bidVolume1));
        setCellStyle2(row->m_cells.get(6), FCTran::strToDouble(row->m_cells.get(6)->getString()), latestData.askPrice1);
        row->m_cells.get(6)->setString(FCTran::getValueByDigit(latestData.askPrice1, digit));
		row->m_cells.get(7)->setString(FCTran::intToStr((int)latestData.askVolume1));
		row->m_cells.get(8)->setString(FCTran::intToStr((int)latestData.volume));
        row->m_cells.get(9)->setString(FCTran::getValueByDigit(latestData.openInterest, digit));
        row->m_cells.get(10)->setString(FCTran::getValueByDigit(latestData.upperLimit, digit));
        row->m_cells.get(11)->setString(FCTran::getValueByDigit(latestData.lowerLimit, digit));
        setCellStyle2(row->m_cells.get(12), FCTran::strToDouble(row->m_cells.get(12)->getString()), latestData.open);
        row->m_cells.get(12)->setString(FCTran::getValueByDigit(latestData.open, digit));
        row->m_cells.get(13)->setString(FCTran::getValueByDigit(latestData.preSettlementPrice, digit));
        setCellStyle2(row->m_cells.get(14), FCTran::strToDouble(row->m_cells.get(14)->getString()), latestData.high);
        row->m_cells.get(14)->setString(FCTran::getValueByDigit(latestData.high, digit));
        setCellStyle2(row->m_cells.get(15), FCTran::strToDouble(row->m_cells.get(15)->getString()), latestData.low);
        row->m_cells.get(15)->setString(FCTran::getValueByDigit(latestData.low, digit));
		row->m_cells.get(16)->setString(FCTran::intToStr((int)latestData.bidVolume1));
        double rangeValue = 0;
        if (latestData.preSettlementPrice != 0)
        {
            rangeValue = 100 * (latestData.close - latestData.preSettlementPrice) / latestData.preSettlementPrice;
        }
        row->m_cells.get(17)->setString(FCTran::getValueByDigit(rangeValue, 2) + L"%");
        setCellStyle2(row->m_cells.get(17), rangeValue, 0);
        row->m_cells.get(18)->setString(FCTran::getValueByDigit(latestData.preClose, digit));
		row->m_cells.get(19)->setString(FCTran::intToStr((int)latestData.turnover));
        row->m_cells.get(20)->setString(latestData.exchangeID);
        row->m_cells.get(21)->setString(latestData.updateTime);
        row->m_cells.get(22)->setString(FCTran::getValueByDigit(latestData.preOpenInterest, digit));
        row->m_cells.get(23)->setString(FCTran::getValueByDigit(latestData.close, digit));
        row->m_cells.get(24)->setString(FCTran::getValueByDigit(latestData.settlementPrice, digit));
        row->m_cells.get(25)->setString(FCTran::getValueByDigit(latestData.averagePrice, digit));
		row->m_cells.get(26)->setString(L"0");
        row->m_cells.get(27)->setString(L"0");
        row->m_cells.get(28)->setString(L"0");
        row->m_cells.get(29)->setString(L"0");
        row->m_cells.get(30)->setString(L"0");
        row->m_cells.get(31)->setString(L"0");
        if (newVol > 0)
        {
            if (latestData.code == m_currentCode)
            {
                int rowsSize = dataSource->getRowsCount();
                dataSource->set(rowsSize + 1, 0, latestData.close);
                dataSource->set(rowsSize + 1, 1, newVol);
                chart->update();
                chart->invalidate();
            }
        }
    }
    gridLatestData->update();
    gridLatestData->invalidate();
}

void MainFrame::onTradeRecordCallBack(TradeRecord *data, int ctpID){
	if((int)data->tradeID.length() == 0){
        return;
    }
    FCGrid *gridTradeRecord = getGrid(L"gridTradeRecord");
    gridTradeRecord->setGridLineColor(FCColor_None);
    FCGridRow *row = new FCGridRow();
    row->setHeight(30);
    gridTradeRecord->insertRow(0, row);
    FCGridStringCell *cell1 = new FCGridStringCell();
    cell1->setString(data->tradeID);
    row->addCell(0, cell1);
    FCGridStringCell *cell2 = new FCGridStringCell();
    cell2->setString(data->code);
    row->addCell(1, cell2);
    FCGridStringCell *cell3 = new FCGridStringCell();
    cell3->setString(data->direction);
    row->addCell(2, cell3);
    FCGridStringCell *cell4 = new FCGridStringCell();
    cell4->setString(data->offsetFlag);
    row->addCell(3, cell4);
    FCGridStringCell *cell5 = new FCGridStringCell();
    cell5->setString(FCTran::getValueByDigit(data->price, 0));
    row->addCell(4, cell5);
    FCGridStringCell *cell6 = new FCGridStringCell();
    cell6->setString(FCTran::getValueByDigit(data->volume, 0));
    row->addCell(5, cell6);
    FCGridStringCell *cell7 = new FCGridStringCell();
    cell7->setString(data->tradeTime);
    row->addCell(6, cell7);
    FCGridStringCell *cell8 = new FCGridStringCell();
    cell8->setString(data->orderSysID);
    row->addCell(7, cell8);
    FCGridStringCell *cell9 = new FCGridStringCell();
    cell9->setString(L"普通成交");
    row->addCell(8, cell9);
    FCGridStringCell *cell10 = new FCGridStringCell();
    cell10->setString(data->hedgeFlag);
    row->addCell(9, cell10);
    FCGridStringCell *cell11 = new FCGridStringCell();
    cell11->setString(data->exchangeID);
    row->addCell(10, cell11);
    FCGridStringCell *cell12 = new FCGridStringCell();
	cell12->setString(FCTran::doubleToStr(data->commission));
    row->addCell(11, cell12);
    gridTradeRecord->update();
    gridTradeRecord->invalidate();
}

void MainFrame::onTradeRecordsCallBack(vector<TradeRecord> *data, int ctpID){
	FCGrid *gridTradeRecord = getGrid(L"gridTradeRecord");
	gridTradeRecord->clearRows();
    gridTradeRecord->setGridLineColor(FCColor_None);
    for (int i = 0; i < data->size(); i++)
    {
		TradeRecord &tradeRecord = (*data)[i];
        if((int)tradeRecord.tradeID.length() == 0){
            return;
        }
        FCGridRow *row = new FCGridRow();
        row->setHeight(30);
        gridTradeRecord->insertRow(0, row);
        FCGridStringCell *cell1 = new FCGridStringCell();
        cell1->setString(tradeRecord.tradeID);
        row->addCell(0, cell1);
        FCGridStringCell *cell2 = new FCGridStringCell();
        cell2->setString(tradeRecord.code);
        row->addCell(1, cell2);
        FCGridStringCell *cell3 = new FCGridStringCell();
        cell3->setString(tradeRecord.direction);
        row->addCell(2, cell3);
        FCGridStringCell *cell4 = new FCGridStringCell();
        cell4->setString(tradeRecord.offsetFlag);
        row->addCell(3, cell4);
        FCGridStringCell *cell5 = new FCGridStringCell();
		cell5->setString(FCTran::getValueByDigit(tradeRecord.price, 0));
        row->addCell(4, cell5);
        FCGridStringCell *cell6 = new FCGridStringCell();
		cell6->setString(FCTran::getValueByDigit(tradeRecord.volume, 0));
        row->addCell(5, cell6);
        FCGridStringCell *cell7 = new FCGridStringCell();
        cell7->setString(tradeRecord.tradeTime);
        row->addCell(6, cell7);
        FCGridStringCell *cell8 = new FCGridStringCell();
        cell8->setString(tradeRecord.orderSysID);
        row->addCell(7, cell8);
        FCGridStringCell *cell9 = new FCGridStringCell();
        cell9->setString(L"普通成交");
        row->addCell(8, cell9);
        FCGridStringCell *cell10 = new FCGridStringCell();
        cell10->setString(tradeRecord.hedgeFlag);
        row->addCell(9, cell10);
        FCGridStringCell *cell11 = new FCGridStringCell();
        cell11->setString(tradeRecord.exchangeID);
        row->addCell(10, cell11);
        FCGridStringCell *cell12 = new FCGridStringCell();
		cell12->setString(FCTran::doubleToStr(tradeRecord.commission));
        row->addCell(11, cell12);
    }
    gridTradeRecord->update();
    gridTradeRecord->invalidate();
}

void MainFrame::onOrderInfoCallBack(OrderInfo *data, int ctpID){
	if (data->orderStatus == L"未知")
    {
        return;
    }
    if ((int)data->orderSysID.length() == 0)
    {
        return;
    }
    FCGrid *gridOrder = getGrid(L"gridOrder");
    gridOrder->setGridLineColor(FCColor_None);
    FCGridRow *row = 0;
    for (int i = 0; i < gridOrder->m_rows.size(); i++)
    {
        if (gridOrder->m_rows.get(i)->m_cells.get(0)->getString() == data->orderSysID)
        {
            row = gridOrder->m_rows.get(i);
            break;
        }
    }
    if (row == 0)
    {
        row = new FCGridRow();
        row->setHeight(30);
        gridOrder->insertRow(0, row);
        for (int j = 0; j < gridOrder->m_columns.size(); j++)
        {
            FCGridStringCell *cell1 = new FCGridStringCell();
            row->addCell(j, cell1);
        }
    }
    row->m_cells.get(0)->setString(data->orderSysID);
    row->m_cells.get(1)->setString(data->code);
    row->m_cells.get(2)->setString(data->direction);
    row->m_cells.get(3)->setString(data->combOffsetFlag);
    row->m_cells.get(4)->setString(data->orderStatus);
    row->m_cells.get(5)->setString(FCTran::getValueByDigit(data->limitPrice, 0));
    row->m_cells.get(6)->setString(FCTran::doubleToStr(data->volumeTotalOriginal));
    row->m_cells.get(7)->setString(FCTran::doubleToStr(data->volumeTotal));
    row->m_cells.get(8)->setString(FCTran::doubleToStr(data->volumeTotal));
    row->m_cells.get(9)->setString(FCTran::doubleToStr(data->volumeTraded));
    row->m_cells.get(10)->setString(data->insertTime);
    row->m_cells.get(11)->setString(data->updateTime);
    row->m_cells.get(12)->setString(FCTran::getValueByDigit(data->limitPrice, 0));
	row->m_cells.get(13)->setString(L"0");
    row->m_cells.get(14)->setString(L"0");
    row->m_cells.get(15)->setString(data->combHedgeFlag);
    row->m_cells.get(16)->setString(data->exchangeID);
    row->m_cells.get(17)->setString(data->orderPriceType);
    row->m_cells.get(18)->setString(data->timeCondition);
    row->m_cells.get(19)->setString(data->orderType);
    row->m_cells.get(20)->setString(FCTran::doubleToStr(data->userForceClose));
    row->m_cells.get(21)->setString(data->forceCloseReason);
    row->m_cells.get(22)->setString(L"");
    row->m_cells.get(23)->setString(L"");
    gridOrder->update();
    gridOrder->invalidate();
}

void MainFrame::onOrderInfosCallBack(vector<OrderInfo> *data, int ctpID){
	FCGrid *gridOrder = getGrid(L"gridOrder");
	gridOrder->clearRows();
    gridOrder->setGridLineColor(FCColor_None);
    for (int i = 0; i < data->size(); i++)
    {
		OrderInfo &orderInfo = (*data)[i];
        if (orderInfo.orderStatus == L"未知")
        {
            return;
        }
        if ((int)orderInfo.orderSysID.length() == 0)
        {
            return;
        }
        FCGridRow *row = 0;
        for (int j = 0; j < gridOrder->m_rows.size(); j++)
        {
            if (gridOrder->m_rows.get(j)->m_cells.get(i)->getString() == orderInfo.orderSysID)
            {
                row = gridOrder->m_rows.get(j);
                break;
            }
        }
        if (row == 0)
        {
            row = new FCGridRow();
            row->setHeight(30);
            gridOrder->insertRow(0, row);
            for (int j = 0; j < gridOrder->m_columns.size(); j++)
            {
                FCGridStringCell *cell1 = new FCGridStringCell();
                row->addCell(j, cell1);
            }
        }
        row->m_cells.get(0)->setString(orderInfo.orderSysID);
        row->m_cells.get(1)->setString(orderInfo.code);
        row->m_cells.get(2)->setString(orderInfo.direction);
        row->m_cells.get(3)->setString(orderInfo.combOffsetFlag);
        row->m_cells.get(4)->setString(orderInfo.orderStatus);
        row->m_cells.get(5)->setString(FCTran::getValueByDigit(orderInfo.limitPrice, 0));
        row->m_cells.get(6)->setString(FCTran::doubleToStr(orderInfo.volumeTotalOriginal));
        row->m_cells.get(7)->setString(FCTran::doubleToStr(orderInfo.volumeTotal));
        row->m_cells.get(8)->setString(FCTran::doubleToStr(orderInfo.volumeTotal));
        row->m_cells.get(9)->setString(FCTran::doubleToStr(orderInfo.volumeTraded));
        row->m_cells.get(10)->setString(orderInfo.insertTime);
        row->m_cells.get(11)->setString(orderInfo.updateTime);
        row->m_cells.get(12)->setString(FCTran::getValueByDigit(orderInfo.limitPrice, 0));
        row->m_cells.get(13)->setString(L"0");
        row->m_cells.get(14)->setString(L"0");
        row->m_cells.get(15)->setString(orderInfo.combHedgeFlag);
        row->m_cells.get(16)->setString(orderInfo.exchangeID);
        row->m_cells.get(17)->setString(orderInfo.orderPriceType);
        row->m_cells.get(18)->setString(orderInfo.timeCondition);
        row->m_cells.get(19)->setString(orderInfo.orderType);
        row->m_cells.get(20)->setString(FCTran::doubleToStr(orderInfo.userForceClose));
        row->m_cells.get(21)->setString(orderInfo.forceCloseReason);
        row->m_cells.get(22)->setString(L"");
        row->m_cells.get(23)->setString(L"");
    }
    gridOrder->update();
    gridOrder->invalidate();
}

void MainFrame::onInvestorPositionDetailCallBack(vector<InvestorPositionDetail> *data, int ctpID){
	FCGrid *gridInvestorPositionDetail = getGrid(L"gridInvestorPositionDetail");
    gridInvestorPositionDetail->setGridLineColor(FCColor_None);
    for (int i = 0; i < data->size(); i++)
    {
		InvestorPositionDetail &ipdData = (*data)[i];
        FCGridRow *row = 0;
        for (int j = 0; j < gridInvestorPositionDetail->m_rows.size(); j++)
        {
            if (gridInvestorPositionDetail->m_rows.get(j)->m_cells.get(0)->getString() == ipdData.tradeID)
            {
                row = gridInvestorPositionDetail->m_rows.get(j);
                break;
            }
        }
        if (row == 0)
        {
            row = new FCGridRow();
            row->setHeight(30);
            gridInvestorPositionDetail->addRow(row);
            for (int j = 0; j < gridInvestorPositionDetail->m_columns.size(); j++)
            {
                FCGridStringCell *cell1 = new FCGridStringCell();
                row->addCell(j, cell1);
            }
        }
        row->m_cells.get(0)->setString(ipdData.tradeID);
        row->m_cells.get(1)->setString(ipdData.code);
        row->m_cells.get(2)->setString(ipdData.direction);
        row->m_cells.get(3)->setString(FCTran::getValueByDigit(ipdData.volume, 0));
        row->m_cells.get(4)->setString(FCTran::getValueByDigit(ipdData.openPrice, 0));
        row->m_cells.get(5)->setString(FCTran::getValueByDigit(ipdData.margin, 0));
        row->m_cells.get(6)->setString(ipdData.tradeType);
        row->m_cells.get(7)->setString(ipdData.hedgeFlag);
        row->m_cells.get(8)->setString(ipdData.openDate);
        row->m_cells.get(9)->setString(FCTran::getValueByDigit(ipdData.positionProfit, 0));
        row->m_cells.get(10)->setString(FCTran::getValueByDigit(ipdData.closeProfitByTrade, 0));
        row->m_cells.get(11)->setString(ipdData.exchangeID);
        row->m_cells.get(12)->setString(L"普通持仓");
        row->m_cells.get(13)->setString(FCTran::getValueByDigit(ipdData.preSettlementPrice, 0));
        row->m_cells.get(14)->setString(FCTran::getValueByDigit(ipdData.closeVolume, 0));
        row->m_cells.get(15)->setString(FCTran::getValueByDigit(ipdData.floatProfit, 0));
        row->m_cells.get(16)->setString(FCTran::getValueByDigit(ipdData.openPrice, 0));
        row->m_cells.get(17)->setString(ipdData.combInstrumentID);
    }
    int rowsSize = gridInvestorPositionDetail->m_rows.size();
        for (int i = 0; i < rowsSize; i++)
        {
            FCGridRow *row = gridInvestorPositionDetail->m_rows.get(i);
            if (row->getCell(3)->getString() == L"0")
            {
                gridInvestorPositionDetail->removeRow(row);
                delete row;
                i--;
                rowsSize--;
            }
        }
    gridInvestorPositionDetail->update();
    gridInvestorPositionDetail->invalidate();
}

void MainFrame::onInvestorPositionCallBack(vector<InvestorPosition> *data, int ctpID){
	FCGrid *gridInvestorPosition = getGrid(L"gridInvestorPosition");
    gridInvestorPosition->setGridLineColor(FCColor_None);
    for (int i = 0; i < data->size(); i++)
    {
		InvestorPosition &ipData = (*data)[i];
        FCGridRow *row = 0;
        for (int j = 0; j < gridInvestorPosition->m_rows.size(); j++)
        {
            if (gridInvestorPosition->m_rows.get(j)->m_cells.get(0)->getString() + gridInvestorPosition->m_rows.get(j)->m_cells.get(1)->getString() == ipData.code + ipData.posiDirection)
            {
                row = gridInvestorPosition->m_rows.get(j);
                break;
            }
        }
        if (row == 0)
        {
            row = new FCGridRow();
            row->setHeight(30);
            gridInvestorPosition->addRow(row);
            for (int j = 0; j < gridInvestorPosition->m_columns.size(); j++)
            {
                FCGridStringCell *cell1 = new FCGridStringCell();
                row->addCell(j, cell1);
            }
        }
        row->m_cells.get(0)->setString(ipData.code);
        row->m_cells.get(1)->setString(ipData.posiDirection);
        row->m_cells.get(2)->setString(FCTran::intToStr(ipData.ydPosition + ipData.todayPosition));
        row->m_cells.get(3)->setString(FCTran::intToStr(ipData.ydPosition));
        row->m_cells.get(4)->setString(FCTran::intToStr(ipData.todayPosition));
        row->m_cells.get(5)->setString(FCTran::intToStr(ipData.getAvailablePosition()));
        row->m_cells.get(6)->setString(FCTran::getValueByDigit(ipData.positionCost, 0));
        row->m_cells.get(7)->setString(FCTran::getValueByDigit(ipData.positionProfit, 0));
        setCellStyle2(row->m_cells.get(7), ipData.positionProfit, 0);
        row->m_cells.get(8)->setString(FCTran::getValueByDigit(ipData.margin, 0));
        row->m_cells.get(9)->setString(ipData.hedgeFlag);
        if (m_allCodes.find(ipData.code) != m_allCodes.end())
        {
            row->m_cells.get(10)->setString(m_allCodes[ipData.code].exchangeID);
        }
        else
        {
            row->m_cells.get(10)->setString(L"0");
        }
        row->m_cells.get(11)->setString(L"0");
        row->m_cells.get(12)->setString(L"0");
        row->m_cells.get(13)->setString(L"0");
        row->m_cells.get(14)->setString(L"0");
        row->m_cells.get(15)->setString(L"0");
        row->m_cells.get(16)->setString(L"0");
        row->m_cells.get(17)->setString(L"0");
        row->m_cells.get(18)->setString(L"0");
        row->m_cells.get(19)->setString(L"0");
        row->m_cells.get(20)->setString(L"0");
        row->m_cells.get(21)->setString(L"0");
        row->m_cells.get(22)->setString(L"0");
        row->m_cells.get(23)->setString(L"0");
        row->m_cells.get(24)->setString(L"0");
        row->m_cells.get(25)->setString(FCTran::getValueByDigit(ipData.floatProfit, 0));
        setCellStyle2(row->m_cells.get(25), ipData.floatProfit, 0);
        row->m_cells.get(26)->setString(L"0");
        row->m_cells.get(27)->setString(L"0");
        row->m_cells.get(28)->setString(L"0");
        row->m_cells.get(29)->setString(L"0");
        row->m_cells.get(30)->setString(L"0");
    }
    int rowsSize = gridInvestorPosition->m_rows.size();
    for (int i = 0; i < rowsSize; i++)
    {
        FCGridRow *row = gridInvestorPosition->m_rows.get(i);
        if (row->getCell(2)->getString() == L"0")
        {
            gridInvestorPosition->removeRow(row);
			delete row;
            i--;
            rowsSize--;
        }
    }
    gridInvestorPosition->update();
    gridInvestorPosition->invalidate();
}

void MainFrame::onSecurityCallBack(vector<Security> *data, int ctpID){
	FCGrid *contractGrid = getGrid(L"gridContracts");
	contractGrid->clearRows();
    contractGrid->setGridLineColor(FCColor_None);
    for (int i = 0; i < data->size(); i++)
    {
		Security &security = (*data)[i];
        m_allCodes[security.instrumentID] = (*data)[i];
        FCGridRow *row = new FCGridRow();
        row->setHeight(30);
        contractGrid->addRow(row);
        FCGridStringCell *cell1 = new FCGridStringCell();
        cell1->setString(security.productID);
        row->addCell(0, cell1);
        FCGridStringCell *cell2 = new FCGridStringCell();
        cell2->setString(security.instrumentID);
        row->addCell(1, cell2);
        FCGridStringCell *cell3 = new FCGridStringCell();
        cell3->setString(security.instrumentName);
        row->addCell(2, cell3);
        FCGridStringCell *cell4 = new FCGridStringCell();
        cell4->setString(security.exchangeID);
        row->addCell(3, cell4);
        FCGridStringCell *cell5 = new FCGridStringCell();
        cell5->setString(FCTran::doubleToStr(security.volumeMultiple));
        row->addCell(4, cell5);
        FCGridStringCell *cell6 = new FCGridStringCell();
        cell6->setString(FCTran::doubleToStr(security.priceTick));
        row->addCell(5, cell6);
        FCGridStringCell *cell7 = new FCGridStringCell();
        cell7->setString(L"期货");
        row->addCell(6, cell7);
        FCGridStringCell *cell8 = new FCGridStringCell();
        cell8->setString(security.expireDate);
        row->addCell(7, cell8);
        FCGridStringCell *cell9 = new FCGridStringCell();
        cell9->setString(FCTran::doubleToStr(security.longMarginRatio));
        row->addCell(8, cell9);
        FCGridStringCell *cell10 = new FCGridStringCell();
        cell10->setString(FCTran::doubleToStr(security.shortMarginRatio));
        row->addCell(9, cell10);
        FCGridStringCell *cell11 = new FCGridStringCell();
        cell11->setString(L"0");
        row->addCell(10, cell11);
        FCGridStringCell *cell12 = new FCGridStringCell();
        cell12->setString(L"0");
        row->addCell(11, cell12);
        FCGridStringCell *cell13 = new FCGridStringCell();
        cell13->setString(L"0");
        row->addCell(12, cell13);
        FCGridStringCell *cell14 = new FCGridStringCell();
        cell14->setString(L"0");
        row->addCell(13, cell14);
        FCGridStringCell *cell15 = new FCGridStringCell();
        cell15->setString(L"0");
        row->addCell(14, cell15);
        FCGridStringCell *cell16 = new FCGridStringCell();
        cell16->setString(L"0");
        row->addCell(15, cell16);
        FCGridStringCell *cell17 = new FCGridStringCell();
        cell17->setString(FCTran::doubleToStr(security.maxMarketOrderVolume));
        row->addCell(16, cell17);
        FCGridStringCell *cell18 = new FCGridStringCell();
        cell18->setString(FCTran::doubleToStr(security.maxLimitOrderVolume));
        row->addCell(17, cell18);
    }
    contractGrid->invalidate();
    contractGrid->invalidate();
}
