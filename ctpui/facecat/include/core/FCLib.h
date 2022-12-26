/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCLIB_H__
#else                                                                            
#define __FCLIB_H__ _declspec(dllexport) 
#endif
#pragma once
typedef std::wstring String;
typedef __int64 Long;
typedef int Integer;
typedef double Double;
typedef float Float;
typedef void* Object;

#include "FCPaint.h"
#include "FCView.h"
#include "GdiPaint.h"
#include "GdiPlusPaint.h"
#include "FCTran.h"
#include "FCNative.h"
#include "FCHost.h"
#include "WinHost.h"
#include "FCBinary.h"
#include "FCLock.h"
#include "FCFile.h"
#include "..\\btn\\FCButton.h"
#include "..\\btn\\FCCheckBox.h"
#include "..\\btn\\FCRadioButton.h"
#include "..\\date\\ArrowButton.h"
#include "..\\date\\CYears.h"
#include "..\\date\\CDay.h"
#include "..\\date\\CMonth.h"
#include "..\\date\\CYear.h"
#include "..\\date\\DateTitle.h"
#include "..\\date\\DayButton.h"
#include "..\\date\\DayDiv.h"
#include "..\\date\\HeadDiv.h"
#include "..\\date\\MonthButton.h"
#include "..\\date\\MonthDiv.h"
#include "..\\date\\YearButton.h"
#include "..\\date\\YearDiv.h"
#include "..\\date\\FCCalendar.h"
#include "..\\chart\\BaseShape.h"
#include "..\\chart\\ChartDiv.h"
#include "..\\chart\\FCChart.h"
#include "..\\chart\\FCPlot.h"
#include "..\\chart\\CrossLine.h"
#include "..\\chart\\CrossLineTip.h"
#include "..\\chart\\FCDataTable.h"
#include "..\\chart\\ChartToolTip.h"
#include "..\\chart\\Enums.h"
#include "..\\chart\\ScaleGrid.h"
#include "..\\chart\\HScale.h"
#include "..\\chart\\FCPlot.h"
#include "..\\chart\\SelectArea.h"
#include "..\\chart\\ChartTitleBar.h"
#include "..\\chart\\VScale.h"
#include "..\\chart\\FCScript.h"
#include "..\\grid\\FCGridCell.h"
#include "..\\grid\\FCGridCellExtends.h"
#include "..\\grid\\FCGridColumn.h"
#include "..\\grid\\FCGridEnums.h"
#include "..\\grid\\FCGridRow.h"
#include "..\\grid\\FCGrid.h"
#include "..\\grid\\FCBandedGrid.h"
#include "..\\grid\\FCBandedGridColumn.h"
#include "..\\grid\\FCGridBand.h"
#include "..\\div\\FCDiv.h"
#include "..\\div\\FCGroupBox.h"
#include "..\\div\\FCLayoutDiv.h"
#include "..\\div\\FCSplitLayoutDiv.h"
#include "..\\div\\FCTableLayoutDiv.h"
#include "..\\div\\FCMenu.h"
#include "..\\div\\FCMenuItem.h"
#include "..\\scroll\\FCHScrollBar.h"
#include "..\\scroll\\FCScrollBar.h"
#include "..\\scroll\\FCVScrollBar.h"
#include "..\\tab\\FCTabView.h"
#include "..\\tab\\FCTabPage.h"
#include "..\\input\\FCComboBox.h"
#include "..\\input\\FCDateTimePicker.h"
#include "..\\input\\FCSpin.h"
#include "..\\input\\FCTextBox.h"
#include "..\\grid\\FCTree.h"
#include "..\\grid\\FCTreeNode.h"
#include "..\\Label\\FCLabel.h"
#include "..\\Label\\FCLinkLabel.h"
#include "..\\div\\FCWindow.h"
#include "..\\div\\FCWindow.h"
#include "..\\chart\\PExtend.h"
#include "..\\service\\FCServerService.h"
#include "..\\service\\FCClientService.h"
#include "..\\sock\\FCClientSocket.h"
#include "..\\sock\\FCServerSocket.h"
#include "..\\d2d\\FCEllipse2D.h"
#include "..\\d2d\\FCRect2D.h"
#include "..\\d2d\\FCLine2D.h"

using namespace FaceCat;