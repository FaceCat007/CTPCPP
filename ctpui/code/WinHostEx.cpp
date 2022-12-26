#include "stdafx.h"
#include "WinHostEx.h"

ScrollButtonM::ScrollButtonM(){
    m_arrowType = 0;
}

ScrollButtonM::~ScrollButtonM(){
    
}

void ScrollButtonM::onPaint(FCPaint *paint, const FCRect& clipRect){
    int width = getWidth(), heigth = getHeight();
    FCRect drawRect = {0, 0, width, heigth};
    if(m_arrowType == 5){
        if(MyColor::getStyle() == 1){
            if(this == m_native->getHoveredView()){
                paint->fillRoundRect(USERCOLOR5, drawRect, 4);
            }else{
                paint->fillRoundRect(USERCOLOR16, drawRect, 4);
            }
        }else{
            if(this == m_native->getHoveredView()){
                paint->fillRoundRect(USERCOLOR5, drawRect, 4);
            }else{
                paint->fillRoundRect(USERCOLOR74, drawRect, 4);
            }
        }
    }else if(m_arrowType == 6){
        if(this == m_native->getHoveredView()){
            paint->fillRect(USERCOLOR6, drawRect);
        }
    }
    else{
		if(allowDrag() && this == m_native->getHoveredView()){
            paint->fillRect(USERCOLOR5, drawRect);
		}else{
			if(MyColor::getStyle() == 0 || MyColor::getStyle() == 1){
				paint->fillRect(FCColor_Border, drawRect);
			}else{
				paint->fillRect(USERCOLOR74, drawRect);
			}
		}
    }
}

void ScrollButtonM::onPaintBorder(FCPaint *paint, const FCRect& clipRect){
    
}


WinHostEx::WinHostEx(){
}

WinHostEx::~WinHostEx(){
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

FCView* WinHostEx::createInternalView(FCView *parent, const String& clsid){
	FCCalendar *calendar = dynamic_cast<FCCalendar*>(parent);
    if (calendar){
        if (clsid == L"datetitle"){
            return new DateTitle(calendar);
        }
        else if (clsid == L"headdiv"){
            HeadDiv *headDiv = new HeadDiv(calendar);
            headDiv->setWidth(parent->getWidth());
            headDiv->setDock(FCDockStyle_Top);
            return headDiv;
        }
        else if (clsid == L"lastbutton"){
            return new ArrowButton(calendar);
        }
        else if (clsid == L"nextbutton"){
            ArrowButton *nextBtn = new ArrowButton(calendar);
            nextBtn->setToLast(false);
            return nextBtn;
        }
    }
    FCSplitLayoutDiv *splitLayoutDiv = dynamic_cast<FCSplitLayoutDiv*>(parent);
    if (splitLayoutDiv){
        if (clsid == L"splitter"){
            FCButton *splitter = new FCButton;
			splitter->setBackColor(FCColor_Border);
            splitter->setBorderColor(FCColor_Border);
            FCSize size = {5, 5};
            splitter->setSize(size);
            return splitter;
        }
    }
    FCScrollBar *scrollBar = dynamic_cast<FCScrollBar*>(parent);
    if (scrollBar){
		scrollBar->setBackColor(FCColor_None);
		scrollBar->setBorderColor(FCColor_None);
		FCSize scrollBarSize = {10, 10};
		scrollBar->setSize(scrollBarSize);
        if (clsid == L"addbutton"){
            FCButton *addButton = new FCButton;
            FCSize size = {0, 0};
			if (dynamic_cast<FCHScrollBar*>(scrollBar)){
				size.cy = 5;
            }
            else{
				size.cx = 5;
            }
            addButton->setSize(size);
			if (dynamic_cast<FCHScrollBar*>(scrollBar)){
                //addButton->setArrowType(2);
            }
            else{
                //addButton->setArrowType(4);
            }
            return addButton;
        }
        else if (clsid == L"backbutton"){
            ScrollButtonM *backButton = new ScrollButtonM;
			backButton->setBackColor(FCColor_None);
			backButton->setBorderColor(FCColor_None);
			backButton->m_arrowType = 6;
            return backButton;
        }
        else if (clsid == L"scrollbutton"){
            ScrollButtonM *scrollButton = new ScrollButtonM;
            scrollButton->setAllowDrag(true);
			scrollButton->setBackColor(USERCOLOR74);
            scrollButton->setBorderColor(FCColor_None);
			scrollButton->setCornerRadius(4);
			scrollButton->m_arrowType = 5;
            return scrollButton;
        }
        else if (clsid == L"reducebutton"){
            FCButton *reduceButton = new FCButton;
            FCSize size = {0, 0};
			if (dynamic_cast<FCHScrollBar*>(scrollBar)){
				size.cy = 5;
            }
            else{
				size.cx = 5;
            }
            reduceButton->setSize(size);
			if (dynamic_cast<FCHScrollBar*>(scrollBar)){
                //reduceButton->setArrowType(1);
            }
            else{
                //reduceButton->setArrowType(3);
            }
            return reduceButton;
        }
    }
    FCTabPage *tabPage = dynamic_cast<FCTabPage*>(parent);
    if (tabPage){
        if (clsid == L"headerbutton"){
            FCButton *button = new FCButton;
            button->setAllowDrag(true);
            FCSize size = {100, 20};
            button->setSize(size);
            return button;
        }
    }
    FCComboBox *comboBox = dynamic_cast<FCComboBox*>(parent);
    if (comboBox){
        if (clsid == L"dropdownbutton"){
            FCButton *dropDownButton = new FCButton;
			//dropDownButton->setArrowType(4);
			dropDownButton->setDisplayOffset(false);
            int width = comboBox->getWidth();
            int height = comboBox->getHeight();
            FCPoint location = {width - 16, 0};
            dropDownButton->setLocation(location);
            FCSize size = {16, height};
            dropDownButton->setSize(size);
            return dropDownButton;
        }
        else if (clsid == L"dropdownmenu"){
            FCComboBoxMenu *comboBoxMenu = new FCComboBoxMenu;
            comboBoxMenu->setComboBox(comboBox);
            comboBoxMenu->setPopup(true);
            FCSize size = {100, 200};
            comboBoxMenu->setSize(size);
            return comboBoxMenu;
        }
    }
    FCDateTimePicker *datePicker = dynamic_cast<FCDateTimePicker*>(parent);
    if (datePicker){
        if (clsid == L"dropdownbutton"){
            FCButton *dropDownButton = new FCButton;
			//dropDownButton->setArrowType(4);
            dropDownButton->setDisplayOffset(false);
            int width = datePicker->getWidth();
            int height = datePicker->getHeight();
            FCPoint location = {width - 16, 0};
            dropDownButton->setLocation(location);
            FCSize size = {16, height};
            dropDownButton->setSize(size);
            return dropDownButton;
        }
        else if (clsid == L"dropdownmenu"){
            FCMenu *dropDownMenu = new FCMenu();
            FCPadding padding(1);
            dropDownMenu->setPadding(padding);
            dropDownMenu->setPopup(true);
            FCSize size = {200, 200};
            dropDownMenu->setSize(size);
            return dropDownMenu;
        }
    }
    FCSpin *spin = dynamic_cast<FCSpin*>(parent);
    if (spin){
        if (clsid == L"downbutton"){
            FCButton *downButton = new FCButton;
			//downButton->setArrowType(4);
			downButton->setDisplayOffset(false);
            FCSize size = {16, 16};
            downButton->setSize(size);
            return downButton;
        }
        else if (clsid == L"upbutton"){
            FCButton *upButton = new FCButton;
			//upButton->setArrowType(3);
			upButton->setDisplayOffset(false);
            FCSize size = {16, 16};
            upButton->setSize(size);
            return upButton;
        }
    }
	FCDiv *div = dynamic_cast<FCDiv*>(parent);
    if (div){
        if (clsid == L"hscrollbar"){
            FCHScrollBar *hScrollBar = new FCHScrollBar;
            hScrollBar->setVisible(false);
            FCSize size = {13, 13};
            hScrollBar->setSize(size);
            return hScrollBar;
        }
        else if (clsid == L"vscrollbar"){
            FCVScrollBar *vScrollBar = new FCVScrollBar;
            vScrollBar->setVisible(false);
            FCSize size = {13, 13};
            vScrollBar->setSize(size);
            return vScrollBar;
        }
    }
	FCGrid *grid = dynamic_cast<FCGrid*>(parent);
	if(grid){
		if(clsid == L"edittextbox"){
			FCTextBox *editTextBox = new FCTextBox;
			return editTextBox;
		}
	}
    return 0;
}

void WinHostEx::reStartTimers(){
	HashMap<int, int> idsCopy;
	lock();
	idsCopy = m_timeIDs;
	m_timeIDs.clear();
	unLock();
	int timeIDsSize = idsCopy.size();
	for(int i = 0; i < timeIDsSize; i++){
		startTimer(idsCopy.getKey(i), idsCopy.getValue(i));
	}
	idsCopy.clear();
}

void WinHostEx::startTimer(int timerID, int interval){
	WinHost::startTimer(timerID, interval);
	lock();
	m_timeIDs.put(timerID, interval);
	unLock();
}

void WinHostEx::stopTimer(int timerID){
	WinHost::stopTimer(timerID);
	lock();
	if(m_timeIDs.containsKey(timerID)){
		m_timeIDs.remove(timerID);
	}
	unLock();
}
