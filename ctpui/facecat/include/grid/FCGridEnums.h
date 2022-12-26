/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifdef __FCGRIDENUMS_H__
#else                                                                            
#define __FCGRIDENUMS_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"

namespace FaceCat{
    /**
	 * 表格列排序方式
	 */
	enum __FCGRIDENUMS_H__ FCGridColumnSortMode{
		/**
		 * 升序
		 */
		FCGridColumnSortMode_Asc,
		/**
		 * 降序
		 */
		FCGridColumnSortMode_Desc,
		/**
		 * 不排序
		 */
		FCGridColumnSortMode_None
	};

    /**
	 * 表格选中模式
	 */
	enum __FCGRIDENUMS_H__ FCGridSelectionMode{
	    /**
		 * 选中单元格
		 */
		FCGridSelectionMode_SelectCell,
		/**
		 * 选中整列
		 */
		FCGridSelectionMode_SelectFullColumn,
		/**
		 * 选中整行
		 */
		FCGridSelectionMode_SelectFullRow,
		/**
		 * 不选中
		 */
		FCGridSelectionMode_SelectNone
	};

    /**
	 * 单元格编辑模式
	 */
	enum __FCGRIDENUMS_H__ FCGridCellEditMode{
	    /**
		 * 双击
		 */
        FCGridCellEditMode_DoubleClick,
        /**
		 * 无效
		 */
        FCGridCellEditMode_None,
        /**
		 * 单击
		 */
        FCGridCellEditMode_SingleClick
	};
}
