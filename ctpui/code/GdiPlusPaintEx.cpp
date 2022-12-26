#include "stdafx.h"
#include "GdiPlusPaintEx.h"

MyColor::MyColor(){
    m_lastStyle = -1;
}
MyColor::~MyColor(){
    
}

static String m_systemFont;

void MyColor::setSystemFont(String value){
    m_systemFont = value;
}

String MyColor::getSystemFont(){
    if ((int)m_systemFont.length() == 0)
    {
        m_systemFont = L"Segoe UI";
    }
    return m_systemFont;
}

static int m_style = 0;

int MyColor::getStyle(){
    return m_style;
}
void MyColor::setStyle(int value){
    m_style = value;
}

void MyColor::createColors(){ 
	m_userColors.clear();
	if (m_style == 1)
    {
        m_userColors.put(USERCOLOR, FCColor::rgb(0, 0, 0));
        m_userColors.put(USERCOLOR1, FCColor::rgb(0, 0, 0));
        m_userColors.put(USERCOLOR2, FCColor::rgba(0, 0, 0, 100)); //1
        m_userColors.put(USERCOLOR3, FCColor::rgb(0, 0, 0)); //1
        m_userColors.put(USERCOLOR4, FCColor::rgb(0, 0, 0)); //1
        m_userColors.put(USERCOLOR5, FCColor::rgb(42, 138, 195));
        m_userColors.put(USERCOLOR6, FCColor::rgba(0, 0, 0, 25)); //1
        m_userColors.put(USERCOLOR7, FCColor::rgb(255, 255, 255)); //1
        m_userColors.put(USERCOLOR8, FCColor::rgb(200, 200, 200)); //1
        m_userColors.put(USERCOLOR9, FCColor::rgb(255, 255, 255)); //1
        m_userColors.put(USERCOLOR10, FCColor::rgb(43, 138, 195));
        m_userColors.put(USERCOLOR11, FCColor::rgba(0, 0, 0, 200)); //1
        m_userColors.put(USERCOLOR12, FCColor::rgb(255, 255, 255)); //1
        m_userColors.put(USERCOLOR13, FCColor::rgba(200, 200, 200, 240)); //1
        m_userColors.put(USERCOLOR14, FCColor::rgba(200, 200, 200, 100)); //1
        m_userColors.put(USERCOLOR15, FCColor::rgb(200, 200, 200)); //1
        m_userColors.put(USERCOLOR16, FCColor::rgb(200, 200, 200)); //1
        m_userColors.put(USERCOLOR17, FCColor::rgb(150, 150, 150)); //1
        m_userColors.put(USERCOLOR18, FCColor::rgba(0, 0, 0, 5)); //1
        m_userColors.put(USERCOLOR19, FCColor::rgba(0, 0, 0, 50)); //1
        m_userColors.put(USERCOLOR20, FCColor::rgb(50, 50, 50)); //1
        m_userColors.put(USERCOLOR21, FCColor::rgb(175, 175, 175)); //1
        m_userColors.put(USERCOLOR22, FCColor::rgb(0, 0, 0));
        m_userColors.put(USERCOLOR23, FCColor::rgba(43, 138, 195, 100));
        m_userColors.put(USERCOLOR24, FCColor::rgb(150, 150, 150)); //1
        m_userColors.put(USERCOLOR25, FCColor::rgb(255, 82, 82));
        m_userColors.put(USERCOLOR26, FCColor::rgb(50, 105, 217));
        m_userColors.put(USERCOLOR27, FCColor::rgb(0, 0, 0)); //1
        m_userColors.put(USERCOLOR28, FCColor::rgb(50, 50, 50)); //1
        m_userColors.put(USERCOLOR29, FCColor::rgb(175, 175, 175));
        m_userColors.put(USERCOLOR30, FCColor::rgb(225, 225, 225));
        m_userColors.put(USERCOLOR31, FCColor::rgb(255, 0, 0)); //1
        m_userColors.put(USERCOLOR32, FCColor::rgb(139, 180, 248));
        m_userColors.put(USERCOLOR33, FCColor::rgb(0, 165, 137));
        m_userColors.put(USERCOLOR34, FCColor::rgb(0, 0, 0));
        m_userColors.put(USERCOLOR35, FCColor::rgba(150, 150, 150, 200)); //1
        m_userColors.put(USERCOLOR36, FCColor::rgba(43, 138, 195, 200));
        m_userColors.put(USERCOLOR37, FCColor::rgb(255, 80, 80));
        m_userColors.put(USERCOLOR38, FCColor::rgba(43, 138, 195, 25));
        m_userColors.put(USERCOLOR39, FCColor::rgba(51, 153, 255, 75));
        m_userColors.put(USERCOLOR40, FCColor::rgb(0, 200, 0));
        m_userColors.put(USERCOLOR41, FCColor::rgba(255, 255, 255, 10)); //1
        m_userColors.put(USERCOLOR42, FCColor::rgba(200, 200, 200, 50)); //1
        m_userColors.put(USERCOLOR43, FCColor::rgb(0, 105, 217));
        m_userColors.put(USERCOLOR44, FCColor::rgba(0, 0, 0, 150)); //1
        m_userColors.put(USERCOLOR45, FCColor::rgba(255, 0, 0, 200));
        m_userColors.put(USERCOLOR46, FCColor::rgba(170, 178, 189, 50));
        m_userColors.put(USERCOLOR47, FCColor::rgba(170, 178, 189, 200));
        m_userColors.put(USERCOLOR48, FCColor::rgb(219, 68, 83));
        m_userColors.put(USERCOLOR49, FCColor::rgb(255, 80, 80));
        m_userColors.put(USERCOLOR50, FCColor::rgb(246, 187, 67));
        m_userColors.put(USERCOLOR51, FCColor::rgb(59, 174, 218));
        m_userColors.put(USERCOLOR52, FCColor::rgb(216, 112, 173));
        m_userColors.put(USERCOLOR53, FCColor::rgb(140, 192, 81));
        m_userColors.put(USERCOLOR54, FCColor::rgb(80, 255, 80));
        m_userColors.put(USERCOLOR55, FCColor::rgba(255, 80, 80, 200));
        m_userColors.put(USERCOLOR56, FCColor::rgba(200, 200, 200, 150)); //1
        m_userColors.put(USERCOLOR57, FCColor::rgba(0, 105, 217, 240));
        m_userColors.put(USERCOLOR58, FCColor::rgba(255, 255, 255, 25)); //1
        m_userColors.put(USERCOLOR59, FCColor::rgb(255, 215, 0));
        m_userColors.put(USERCOLOR60, FCColor::rgb(100, 100, 100)); //1
        m_userColors.put(USERCOLOR61, FCColor::rgba(255, 255, 255, 200)); //1
        m_userColors.put(USERCOLOR62, FCColor::rgba(43, 138, 195, 50));
        m_userColors.put(USERCOLOR63, FCColor::rgb(10, 36, 106));
        m_userColors.put(USERCOLOR64, FCColor::rgb(255, 255, 255)); //1
        m_userColors.put(USERCOLOR65, FCColor::rgba(255, 255, 255, 100)); //1
        m_userColors.put(USERCOLOR66, FCColor::rgba(255, 255, 255, 50)); //1
        m_userColors.put(USERCOLOR67, FCColor::rgb(20, 20, 20)); //1
        m_userColors.put(USERCOLOR68, FCColor::rgb(220, 220, 220)); //1
        m_userColors.put(USERCOLOR69, FCColor::rgb(248, 73, 96));
        m_userColors.put(USERCOLOR70, FCColor::rgb(15, 193, 118));
        m_userColors.put(USERCOLOR71, FCColor::rgba(248, 73, 96, 150));
        m_userColors.put(USERCOLOR72, FCColor::rgba(15, 193, 118, 150));
        m_userColors.put(USERCOLOR73, FCColor::rgb(130, 140, 150));
        m_userColors.put(USERCOLOR74, FCColor::rgba(94, 102, 115, 200));
        m_userColors.put(USERCOLOR75, FCColor::rgb(83, 195, 42));
        m_userColors.put(USERCOLOR76, FCColor::rgb(231, 192, 42));
        m_userColors.put(USERCOLOR77, FCColor::rgb(254, 89, 82));
        m_userColors.put(USERCOLOR78, FCColor::rgba(42, 138, 195, 100));
        m_userColors.put(USERCOLOR79, FCColor::rgb(200, 200, 200)); //1
        m_userColors.put(USERCOLOR80, FCColor::rgba(200, 200, 200, 150)); //1
        m_userColors.put(USERCOLOR81, FCColor::rgb(16, 95, 205));
        m_userColors.put(USERCOLOR82, FCColor::rgba(16, 95, 205, 100));
        m_userColors.put(USERCOLOR83, FCColor::rgb(150, 150, 150)); //1
        m_userColors.put(USERCOLOR84, FCColor::rgb(20, 20, 20)); //1
        m_userColors.put(USERCOLOR85, FCColor::rgb(70, 76, 79));
        m_userColors.put(USERCOLOR86, FCColor::rgb(200, 200, 200));
        m_userColors.put(USERCOLOR87, FCColor::rgb(210, 210, 210)); //1
        m_userColors.put(USERCOLOR88, FCColor::rgb(184, 185, 186));
        m_userColors.put(USERCOLOR89, FCColor::rgb(100, 100, 100)); //1
        m_userColors.put(USERCOLOR90, FCColor::rgb(255, 255, 80));
        m_userColors.put(USERCOLOR91, FCColor::rgba(42, 138, 195, 200));  //1
        m_userColors.put(USERCOLOR92, FCColor::rgba(220, 220, 220, 50));
        m_userColors.put(USERCOLOR93, FCColor::rgba(200, 200, 200, 25));
        m_userColors.put(USERCOLOR94, FCColor::rgb(220, 220, 220)); //1
        m_userColors.put(USERCOLOR95, FCColor::rgb(128, 128, 128));
        m_userColors.put(USERCOLOR96, FCColor::rgb(150, 0, 0));
        m_userColors.put(USERCOLOR97, FCColor::rgb(80, 255, 255));
        m_userColors.put(USERCOLOR98, FCColor::rgb(217, 217, 68));
        m_userColors.put(USERCOLOR99, FCColor::rgb(112, 112, 112));
        m_userColors.put(USERCOLOR100, FCColor::rgb(192, 192, 192));
        m_userColors.put(USERCOLOR101, FCColor::rgb(255, 255, 0));
        m_userColors.put(USERCOLOR102, FCColor::rgba(255, 255, 255, 200));
        m_userColors.put(USERCOLOR103, FCColor::rgba(43, 138, 195, 240));
        m_userColors.put(USERCOLOR104, FCColor::rgba(230, 230, 230, 240));
        m_userColors.put(USERCOLOR105, FCColor::rgba(0, 0, 0, 12)); //1
        m_userColors.put(USERCOLOR106, FCColor::rgb(222, 86, 122));
        m_userColors.put(USERCOLOR107, FCColor::rgb(115, 183, 72));
        m_userColors.put(USERCOLOR108, FCColor::rgba(219, 68, 83, 200));
        m_userColors.put(USERCOLOR109, FCColor::rgba(140, 192, 81, 200));
        m_userColors.put(USERCOLOR110, FCColor::rgb(15, 193, 118));
        m_userColors.put(USERCOLOR111, FCColor::rgba(220, 220, 220, 100));
        m_userColors.put(USERCOLOR112, FCColor::rgba(42, 138, 195, 230));
        m_userColors.put(USERCOLOR113, FCColor::rgba(15, 193, 118, 50));
        m_userColors.put(USERCOLOR114, FCColor::rgba(248, 73, 96, 50));
        m_userColors.put(USERCOLOR115, FCColor::rgba(170, 178, 189, 25));
        m_userColors.put(USERCOLOR116, FCColor::rgb(217, 218, 223));
        m_userColors.put(USERCOLOR117, FCColor::rgb(167, 171, 184));
        m_userColors.put(FCColor_Back, FCColor::rgb(255, 255, 255)); //1
        m_userColors.put(FCColor_Border, FCColor::rgb(200, 200, 200)); //1
        m_userColors.put(FCColor_Text, FCColor::rgb(0, 0, 0)); //1
        m_userColors.put(FCColor_DisabledBack, FCColor::rgba(0, 0, 0, 25)); //1
        m_userColors.put(FCColor_DisabledText, 3289650);
        m_userColors.put(FCColor_Hovered, FCColor::rgba(43, 138, 195, 150));
        m_userColors.put(FCColor_Pushed, FCColor::rgba(43, 138, 195, 100));
    }
    else if (m_style == 2)
    {
        m_userColors.put(USERCOLOR, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR1, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR2, FCColor::rgba(255, 255, 255, 100));
        m_userColors.put(USERCOLOR3, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR4, FCColor::rgb(0, 0, 0));
        m_userColors.put(USERCOLOR5, FCColor::rgb(219, 68, 83)); //1
        m_userColors.put(USERCOLOR6, FCColor::rgba(255, 255, 255, 25));
        m_userColors.put(USERCOLOR7, FCColor::rgb(19, 21, 26));
        m_userColors.put(USERCOLOR8, FCColor::rgb(50, 50, 50));
        m_userColors.put(USERCOLOR9, FCColor::rgb(0, 0, 0));
        m_userColors.put(USERCOLOR10, FCColor::rgb(219, 68, 83)); //1
        m_userColors.put(USERCOLOR11, FCColor::rgba(255, 255, 255, 200));
        m_userColors.put(USERCOLOR12, FCColor::rgb(19, 21, 26));
        m_userColors.put(USERCOLOR13, FCColor::rgba(50, 50, 50, 240));
        m_userColors.put(USERCOLOR14, FCColor::rgba(50, 50, 50, 100));
        m_userColors.put(USERCOLOR15, FCColor::rgb(46, 47, 49));
        m_userColors.put(USERCOLOR16, FCColor::rgb(50, 50, 50));
        m_userColors.put(USERCOLOR17, FCColor::rgb(100, 100, 100));
        m_userColors.put(USERCOLOR18, FCColor::rgba(255, 255, 255, 5));
        m_userColors.put(USERCOLOR19, FCColor::rgba(255, 255, 255, 50));
        m_userColors.put(USERCOLOR20, FCColor::rgb(255, 255, 255)); 
        m_userColors.put(USERCOLOR21, FCColor::rgba(219, 68, 83, 100)); //1
        m_userColors.put(USERCOLOR22, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR23, FCColor::rgba(219, 68, 83, 100)); //1
        m_userColors.put(USERCOLOR24, FCColor::rgb(100, 100, 100));
        m_userColors.put(USERCOLOR25, FCColor::rgb(255, 82, 82));
        m_userColors.put(USERCOLOR26, FCColor::rgb(50, 105, 217));
        m_userColors.put(USERCOLOR27, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR28, FCColor::rgb(200, 200, 200));
        m_userColors.put(USERCOLOR29, FCColor::rgb(80, 80, 80));
        m_userColors.put(USERCOLOR30, FCColor::rgb(25, 25, 25));
        m_userColors.put(USERCOLOR31, FCColor::rgb(255, 0, 0));
        m_userColors.put(USERCOLOR32, FCColor::rgb(139, 180, 248));
        m_userColors.put(USERCOLOR33, FCColor::rgb(0, 165, 137));
        m_userColors.put(USERCOLOR34, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR35, FCColor::rgba(100, 100, 100, 200));
        m_userColors.put(USERCOLOR36, FCColor::rgba(219, 68, 83, 200)); //1
        m_userColors.put(USERCOLOR37, FCColor::rgb(255, 80, 80));
        m_userColors.put(USERCOLOR38, FCColor::rgba(43, 138, 195, 25));
        m_userColors.put(USERCOLOR39, FCColor::rgba(51, 153, 255, 75));
        m_userColors.put(USERCOLOR40, FCColor::rgb(0, 200, 0));
        m_userColors.put(USERCOLOR41, FCColor::rgba(0, 0, 0, 10));
        m_userColors.put(USERCOLOR42, FCColor::rgba(50, 50, 50, 50));
        m_userColors.put(USERCOLOR43, FCColor::rgb(0, 105, 217));
        m_userColors.put(USERCOLOR44, FCColor::rgba(255, 255, 255, 150));
        m_userColors.put(USERCOLOR45, FCColor::rgba(255, 0, 0, 200));
        m_userColors.put(USERCOLOR46, FCColor::rgba(170, 178, 189, 50));
        m_userColors.put(USERCOLOR47, FCColor::rgba(170, 178, 189, 200));
        m_userColors.put(USERCOLOR48, FCColor::rgb(219, 68, 83));
        m_userColors.put(USERCOLOR49, FCColor::rgb(255, 80, 80));
        m_userColors.put(USERCOLOR50, FCColor::rgb(246, 187, 67));
        m_userColors.put(USERCOLOR51, FCColor::rgb(59, 174, 218));
        m_userColors.put(USERCOLOR52, FCColor::rgb(216, 112, 173));
        m_userColors.put(USERCOLOR53, FCColor::rgb(140, 192, 81));
        m_userColors.put(USERCOLOR54, FCColor::rgb(80, 255, 80));
        m_userColors.put(USERCOLOR55, FCColor::rgba(255, 80, 80, 200));
        m_userColors.put(USERCOLOR56, FCColor::rgba(50, 50, 50, 150));
        m_userColors.put(USERCOLOR57, FCColor::rgba(0, 105, 217, 240));
        m_userColors.put(USERCOLOR58, FCColor::rgba(0, 0, 0, 25));
        m_userColors.put(USERCOLOR59, FCColor::rgb(255, 215, 0));
        m_userColors.put(USERCOLOR60, FCColor::rgb(150, 150, 150));
        m_userColors.put(USERCOLOR61, FCColor::rgba(0, 0, 0, 200));
        m_userColors.put(USERCOLOR62, FCColor::rgba(219, 68, 83, 50)); //1
        m_userColors.put(USERCOLOR63, FCColor::rgb(10, 36, 106));
        m_userColors.put(USERCOLOR64, FCColor::rgb(21, 24, 28));
        m_userColors.put(USERCOLOR65, FCColor::rgba(0, 0, 0, 100));
        m_userColors.put(USERCOLOR66, FCColor::rgba(0, 0, 0, 50));
        m_userColors.put(USERCOLOR67, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR68, FCColor::rgba(219, 68, 83, 200)); //1
        m_userColors.put(USERCOLOR69, FCColor::rgb(248, 73, 96));
        m_userColors.put(USERCOLOR70, FCColor::rgb(15, 193, 118));
        m_userColors.put(USERCOLOR71, FCColor::rgba(248, 73, 96, 150));
        m_userColors.put(USERCOLOR72, FCColor::rgba(15, 193, 118, 150));
        m_userColors.put(USERCOLOR73, FCColor::rgb(130, 140, 150));
        m_userColors.put(USERCOLOR74, FCColor::rgba(219, 68, 83, 200)); //1
        m_userColors.put(USERCOLOR75, FCColor::rgb(83, 195, 42));
        m_userColors.put(USERCOLOR76, FCColor::rgb(231, 192, 42));
        m_userColors.put(USERCOLOR77, FCColor::rgb(254, 89, 82));
        m_userColors.put(USERCOLOR78, FCColor::rgba(42, 138, 195, 100));
        m_userColors.put(USERCOLOR79, FCColor::rgb(219, 68, 83));; //1
        m_userColors.put(USERCOLOR80, FCColor::rgba(52, 53, 58, 150));
        m_userColors.put(USERCOLOR81, FCColor::rgb(219, 68, 83)); //1
        m_userColors.put(USERCOLOR82, FCColor::rgba(16, 95, 205, 100));
        m_userColors.put(USERCOLOR83, FCColor::rgb(107, 107, 107));
        m_userColors.put(USERCOLOR84, FCColor::rgb(233, 233, 233));
        m_userColors.put(USERCOLOR85, FCColor::rgb(70, 76, 79));
        m_userColors.put(USERCOLOR86, FCColor::rgba(219, 68, 83, 100)); //1
        m_userColors.put(USERCOLOR87, FCColor::rgb(39, 41, 46));
         m_userColors.put(USERCOLOR88, FCColor::rgb(184, 185, 186));
        m_userColors.put(USERCOLOR89, FCColor::rgb(150, 150, 150));
        m_userColors.put(USERCOLOR90, FCColor::rgb(255, 255, 80));
        m_userColors.put(USERCOLOR91, FCColor::rgba(219, 68, 83, 200)); //1
        m_userColors.put(USERCOLOR92, FCColor::rgba(219, 68, 83, 50));//1
        m_userColors.put(USERCOLOR93, FCColor::rgba(50, 50, 50, 25));
        m_userColors.put(USERCOLOR94, FCColor::rgba(219, 68, 83, 200)); //1
        m_userColors.put(USERCOLOR95, FCColor::rgba(219, 68, 83, 100)); //1
        m_userColors.put(USERCOLOR96, FCColor::rgb(150, 0, 0));
        m_userColors.put(USERCOLOR97, FCColor::rgb(80, 255, 255));
        m_userColors.put(USERCOLOR98, FCColor::rgb(217, 217, 68));
        m_userColors.put(USERCOLOR99, FCColor::rgb(112, 112, 112));
        m_userColors.put(USERCOLOR100, FCColor::rgb(192, 192, 192));
        m_userColors.put(USERCOLOR101, FCColor::rgb(255, 255, 0));
        m_userColors.put(USERCOLOR102, FCColor::rgba(0, 0, 0, 200));
        m_userColors.put(USERCOLOR103, FCColor::rgba(43, 138, 195, 240));
        m_userColors.put(USERCOLOR104, FCColor::rgba(21, 24, 28, 240));
        m_userColors.put(USERCOLOR105, FCColor::rgba(255, 255, 255, 12));
        m_userColors.put(USERCOLOR106, FCColor::rgb(222, 86, 122));
        m_userColors.put(USERCOLOR107, FCColor::rgb(115, 183, 72));
        m_userColors.put(USERCOLOR108, FCColor::rgba(219, 68, 83, 200));
        m_userColors.put(USERCOLOR109, FCColor::rgba(140, 192, 81, 200));
        m_userColors.put(USERCOLOR110, FCColor::rgb(219, 68, 83));
        m_userColors.put(USERCOLOR111, FCColor::rgba(32, 36, 38, 100));
        m_userColors.put(USERCOLOR112, FCColor::rgba(42, 138, 195, 230));
        m_userColors.put(USERCOLOR113, FCColor::rgba(15, 193, 118, 50));
        m_userColors.put(USERCOLOR114, FCColor::rgba(248, 73, 96, 50));
        m_userColors.put(USERCOLOR115, FCColor::rgba(170, 178, 189, 25));
        m_userColors.put(USERCOLOR116, FCColor::rgb(217, 218, 223));
        m_userColors.put(USERCOLOR117, FCColor::rgb(167, 171, 184));
        m_userColors.put(FCColor_Back, FCColor::rgb(19, 21, 26));
        m_userColors.put(FCColor_Border, FCColor::rgb(50, 50, 50));
        m_userColors.put(FCColor_Text, FCColor::rgb(255, 255, 255));
        m_userColors.put(FCColor_DisabledBack, FCColor::rgba(255, 255, 255, 25));
        m_userColors.put(FCColor_DisabledText, 3289650);
        m_userColors.put(FCColor_Hovered, FCColor::rgba(219, 68, 83, 150)); //1
        m_userColors.put(FCColor_Pushed, FCColor::rgba(219, 68, 83, 100)); //1
    }
    else if (m_style == 3)
    {
        m_userColors.put(USERCOLOR, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR1, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR2, FCColor::rgba(255, 255, 255, 100));
        m_userColors.put(USERCOLOR3, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR4, FCColor::rgb(0, 0, 0));
        m_userColors.put(USERCOLOR5, FCColor::rgb(15, 193, 118)); //1
        m_userColors.put(USERCOLOR6, FCColor::rgba(255, 255, 255, 25));
        m_userColors.put(USERCOLOR7, FCColor::rgb(19, 21, 26));
        m_userColors.put(USERCOLOR8, FCColor::rgb(50, 50, 50));
        m_userColors.put(USERCOLOR9, FCColor::rgb(0, 0, 0));
        m_userColors.put(USERCOLOR10, FCColor::rgb(15, 193, 118)); //1
        m_userColors.put(USERCOLOR11, FCColor::rgba(255, 255, 255, 200));
        m_userColors.put(USERCOLOR12, FCColor::rgb(19, 21, 26));
        m_userColors.put(USERCOLOR13, FCColor::rgba(50, 50, 50, 240));
        m_userColors.put(USERCOLOR14, FCColor::rgba(50, 50, 50, 100));
        m_userColors.put(USERCOLOR15, FCColor::rgb(46, 47, 49));
        m_userColors.put(USERCOLOR16, FCColor::rgb(50, 50, 50));
        m_userColors.put(USERCOLOR17, FCColor::rgb(100, 100, 100));
        m_userColors.put(USERCOLOR18, FCColor::rgba(255, 255, 255, 5));
        m_userColors.put(USERCOLOR19, FCColor::rgba(255, 255, 255, 50));
        m_userColors.put(USERCOLOR20, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR21, FCColor::rgba(15, 193, 118, 100)); //1
        m_userColors.put(USERCOLOR22, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR23, FCColor::rgba(15, 193, 118, 100)); //1
        m_userColors.put(USERCOLOR24, FCColor::rgb(100, 100, 100));
        m_userColors.put(USERCOLOR25, FCColor::rgb(255, 82, 82));
        m_userColors.put(USERCOLOR26, FCColor::rgb(50, 105, 217));
        m_userColors.put(USERCOLOR27, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR28, FCColor::rgb(200, 200, 200));
        m_userColors.put(USERCOLOR29, FCColor::rgb(80, 80, 80));
        m_userColors.put(USERCOLOR30, FCColor::rgb(25, 25, 25));
        m_userColors.put(USERCOLOR31, FCColor::rgb(255, 0, 0));
        m_userColors.put(USERCOLOR32, FCColor::rgb(139, 180, 248));
        m_userColors.put(USERCOLOR33, FCColor::rgb(0, 165, 137));
        m_userColors.put(USERCOLOR34, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR35, FCColor::rgba(100, 100, 100, 200));
        m_userColors.put(USERCOLOR36, FCColor::rgba(15, 193, 118, 200)); //1
        m_userColors.put(USERCOLOR37, FCColor::rgb(255, 80, 80));
        m_userColors.put(USERCOLOR38, FCColor::rgba(43, 138, 195, 25));
        m_userColors.put(USERCOLOR39, FCColor::rgba(51, 153, 255, 75));
        m_userColors.put(USERCOLOR40, FCColor::rgb(0, 200, 0));
        m_userColors.put(USERCOLOR41, FCColor::rgba(0, 0, 0, 10));
        m_userColors.put(USERCOLOR42, FCColor::rgba(50, 50, 50, 50));
        m_userColors.put(USERCOLOR43, FCColor::rgb(0, 105, 217));
        m_userColors.put(USERCOLOR44, FCColor::rgba(255, 255, 255, 150));
        m_userColors.put(USERCOLOR45, FCColor::rgba(255, 0, 0, 200));
        m_userColors.put(USERCOLOR46, FCColor::rgba(170, 178, 189, 50));
        m_userColors.put(USERCOLOR47, FCColor::rgba(170, 178, 189, 200));
        m_userColors.put(USERCOLOR48, FCColor::rgb(219, 68, 83));
        m_userColors.put(USERCOLOR49, FCColor::rgb(255, 80, 80));
        m_userColors.put(USERCOLOR50, FCColor::rgb(246, 187, 67));
        m_userColors.put(USERCOLOR51, FCColor::rgb(59, 174, 218));
        m_userColors.put(USERCOLOR52, FCColor::rgb(216, 112, 173));
        m_userColors.put(USERCOLOR53, FCColor::rgb(140, 192, 81));
        m_userColors.put(USERCOLOR54, FCColor::rgb(80, 255, 80));
        m_userColors.put(USERCOLOR55, FCColor::rgba(255, 80, 80, 200));
        m_userColors.put(USERCOLOR56, FCColor::rgba(50, 50, 50, 150));
        m_userColors.put(USERCOLOR57, FCColor::rgba(0, 105, 217, 240));
        m_userColors.put(USERCOLOR58, FCColor::rgba(0, 0, 0, 25));
        m_userColors.put(USERCOLOR59, FCColor::rgb(255, 215, 0));
        m_userColors.put(USERCOLOR60, FCColor::rgb(150, 150, 150));
        m_userColors.put(USERCOLOR61, FCColor::rgba(0, 0, 0, 200));
        m_userColors.put(USERCOLOR62, FCColor::rgba(15, 193, 118, 50)); //1
        m_userColors.put(USERCOLOR63, FCColor::rgb(10, 36, 106));
        m_userColors.put(USERCOLOR64, FCColor::rgb(21, 24, 28));
        m_userColors.put(USERCOLOR65, FCColor::rgba(0, 0, 0, 100));
        m_userColors.put(USERCOLOR66, FCColor::rgba(0, 0, 0, 50));
        m_userColors.put(USERCOLOR67, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR68, FCColor::rgba(15, 193, 118, 200)); //1
        m_userColors.put(USERCOLOR69, FCColor::rgb(248, 73, 96));
        m_userColors.put(USERCOLOR70, FCColor::rgb(15, 193, 118));
        m_userColors.put(USERCOLOR71, FCColor::rgba(248, 73, 96, 150));
        m_userColors.put(USERCOLOR72, FCColor::rgba(15, 193, 118, 150));
        m_userColors.put(USERCOLOR73, FCColor::rgb(130, 140, 150));
        m_userColors.put(USERCOLOR74, FCColor::rgba(15, 193, 118, 200)); //1
        m_userColors.put(USERCOLOR75, FCColor::rgb(83, 195, 42));
        m_userColors.put(USERCOLOR76, FCColor::rgb(231, 192, 42));
        m_userColors.put(USERCOLOR77, FCColor::rgb(254, 89, 82));
        m_userColors.put(USERCOLOR78, FCColor::rgba(42, 138, 195, 100));
        m_userColors.put(USERCOLOR79, FCColor::rgb(15, 193, 118));; //1
        m_userColors.put(USERCOLOR80, FCColor::rgba(52, 53, 58, 150));
        m_userColors.put(USERCOLOR81, FCColor::rgb(15, 193, 118)); //1
        m_userColors.put(USERCOLOR82, FCColor::rgba(16, 95, 205, 100));
        m_userColors.put(USERCOLOR83, FCColor::rgb(107, 107, 107));
        m_userColors.put(USERCOLOR84, FCColor::rgb(233, 233, 233));
        m_userColors.put(USERCOLOR85, FCColor::rgb(70, 76, 79));
        m_userColors.put(USERCOLOR86, FCColor::rgba(15, 193, 118, 100)); //1
        m_userColors.put(USERCOLOR87, FCColor::rgb(39, 41, 46));
         m_userColors.put(USERCOLOR88, FCColor::rgb(184, 185, 186));
        m_userColors.put(USERCOLOR89, FCColor::rgb(150, 150, 150));
        m_userColors.put(USERCOLOR90, FCColor::rgb(255, 255, 80));
        m_userColors.put(USERCOLOR91, FCColor::rgba(15, 193, 118, 200)); //1
        m_userColors.put(USERCOLOR92, FCColor::rgba(15, 193, 118, 50));//1
        m_userColors.put(USERCOLOR93, FCColor::rgba(50, 50, 50, 25));
        m_userColors.put(USERCOLOR94, FCColor::rgba(15, 193, 118, 200)); //1
        m_userColors.put(USERCOLOR95, FCColor::rgba(15, 193, 118, 100)); //1
        m_userColors.put(USERCOLOR96, FCColor::rgb(150, 0, 0));
        m_userColors.put(USERCOLOR97, FCColor::rgb(80, 255, 255));
        m_userColors.put(USERCOLOR98, FCColor::rgb(217, 217, 68));
        m_userColors.put(USERCOLOR99, FCColor::rgb(112, 112, 112));
        m_userColors.put(USERCOLOR100, FCColor::rgb(192, 192, 192));
        m_userColors.put(USERCOLOR101, FCColor::rgb(255, 255, 0));
        m_userColors.put(USERCOLOR102, FCColor::rgba(0, 0, 0, 200));
        m_userColors.put(USERCOLOR103, FCColor::rgba(43, 138, 195, 240));
        m_userColors.put(USERCOLOR104, FCColor::rgba(21, 24, 28, 240));
        m_userColors.put(USERCOLOR105, FCColor::rgba(255, 255, 255, 12));
        m_userColors.put(USERCOLOR106, FCColor::rgb(222, 86, 122));
        m_userColors.put(USERCOLOR107, FCColor::rgb(115, 183, 72));
        m_userColors.put(USERCOLOR108, FCColor::rgba(219, 68, 83, 200));
        m_userColors.put(USERCOLOR109, FCColor::rgba(140, 192, 81, 200));
        m_userColors.put(USERCOLOR110, FCColor::rgb(15, 193, 118));
        m_userColors.put(USERCOLOR111, FCColor::rgba(32, 36, 38, 100));
        m_userColors.put(USERCOLOR112, FCColor::rgba(42, 138, 195, 230));
        m_userColors.put(USERCOLOR113, FCColor::rgba(15, 193, 118, 50));
        m_userColors.put(USERCOLOR114, FCColor::rgba(248, 73, 96, 50));
        m_userColors.put(USERCOLOR115, FCColor::rgba(170, 178, 189, 25));
        m_userColors.put(USERCOLOR116, FCColor::rgb(217, 218, 223));
        m_userColors.put(USERCOLOR117, FCColor::rgb(167, 171, 184));
        m_userColors.put(FCColor_Back, FCColor::rgb(19, 21, 26));
        m_userColors.put(FCColor_Border, FCColor::rgb(50, 50, 50));
        m_userColors.put(FCColor_Text, FCColor::rgb(255, 255, 255));
        m_userColors.put(FCColor_DisabledBack, FCColor::rgba(255, 255, 255, 25));
        m_userColors.put(FCColor_DisabledText, 3289650);
        m_userColors.put(FCColor_Hovered, FCColor::rgba(15, 193, 118, 150)); //1
        m_userColors.put(FCColor_Pushed, FCColor::rgba(15, 193, 118, 100)); //1

    }
    else if (m_style == 4)
    {
        m_userColors.put(USERCOLOR, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR1, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR2, FCColor::rgba(255, 255, 255, 100));
        m_userColors.put(USERCOLOR3, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR4, FCColor::rgb(0, 0, 0));
        m_userColors.put(USERCOLOR5, FCColor::rgb(185, 63, 150)); //1
        m_userColors.put(USERCOLOR6, FCColor::rgba(255, 255, 255, 25));
        m_userColors.put(USERCOLOR7, FCColor::rgb(19, 21, 26));
        m_userColors.put(USERCOLOR8, FCColor::rgb(50, 50, 50));
        m_userColors.put(USERCOLOR9, FCColor::rgb(0, 0, 0));
        m_userColors.put(USERCOLOR10, FCColor::rgb(185, 63, 150)); //1
        m_userColors.put(USERCOLOR11, FCColor::rgba(255, 255, 255, 200));
        m_userColors.put(USERCOLOR12, FCColor::rgb(19, 21, 26));
        m_userColors.put(USERCOLOR13, FCColor::rgba(50, 50, 50, 240));
        m_userColors.put(USERCOLOR14, FCColor::rgba(50, 50, 50, 100));
        m_userColors.put(USERCOLOR15, FCColor::rgb(46, 47, 49));
        m_userColors.put(USERCOLOR16, FCColor::rgb(50, 50, 50));
        m_userColors.put(USERCOLOR17, FCColor::rgb(100, 100, 100));
        m_userColors.put(USERCOLOR18, FCColor::rgba(255, 255, 255, 5));
        m_userColors.put(USERCOLOR19, FCColor::rgba(255, 255, 255, 50));
        m_userColors.put(USERCOLOR20, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR21, FCColor::rgba(185, 63, 150, 100)); //1
        m_userColors.put(USERCOLOR22, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR23, FCColor::rgba(185, 63, 150, 100)); //1
        m_userColors.put(USERCOLOR24, FCColor::rgb(100, 100, 100));
        m_userColors.put(USERCOLOR25, FCColor::rgb(255, 82, 82));
        m_userColors.put(USERCOLOR26, FCColor::rgb(50, 105, 217));
        m_userColors.put(USERCOLOR27, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR28, FCColor::rgb(200, 200, 200));
        m_userColors.put(USERCOLOR29, FCColor::rgb(80, 80, 80));
        m_userColors.put(USERCOLOR30, FCColor::rgb(25, 25, 25));
        m_userColors.put(USERCOLOR31, FCColor::rgb(255, 0, 0));
        m_userColors.put(USERCOLOR32, FCColor::rgb(139, 180, 248));
        m_userColors.put(USERCOLOR33, FCColor::rgb(0, 165, 137));
        m_userColors.put(USERCOLOR34, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR35, FCColor::rgba(100, 100, 100, 200));
        m_userColors.put(USERCOLOR36, FCColor::rgba(185, 63, 150, 200)); //1
        m_userColors.put(USERCOLOR37, FCColor::rgb(255, 80, 80));
        m_userColors.put(USERCOLOR38, FCColor::rgba(43, 138, 195, 25));
        m_userColors.put(USERCOLOR39, FCColor::rgba(51, 153, 255, 75));
        m_userColors.put(USERCOLOR40, FCColor::rgb(0, 200, 0));
        m_userColors.put(USERCOLOR41, FCColor::rgba(0, 0, 0, 10));
        m_userColors.put(USERCOLOR42, FCColor::rgba(50, 50, 50, 50));
        m_userColors.put(USERCOLOR43, FCColor::rgb(0, 105, 217));
        m_userColors.put(USERCOLOR44, FCColor::rgba(255, 255, 255, 150));
        m_userColors.put(USERCOLOR45, FCColor::rgba(255, 0, 0, 200));
        m_userColors.put(USERCOLOR46, FCColor::rgba(170, 178, 189, 50));
        m_userColors.put(USERCOLOR47, FCColor::rgba(170, 178, 189, 200));
        m_userColors.put(USERCOLOR48, FCColor::rgb(219, 68, 83));
        m_userColors.put(USERCOLOR49, FCColor::rgb(255, 80, 80));
        m_userColors.put(USERCOLOR50, FCColor::rgb(246, 187, 67));
        m_userColors.put(USERCOLOR51, FCColor::rgb(59, 174, 218));
        m_userColors.put(USERCOLOR52, FCColor::rgb(216, 112, 173));
        m_userColors.put(USERCOLOR53, FCColor::rgb(140, 192, 81));
        m_userColors.put(USERCOLOR54, FCColor::rgb(80, 255, 80));
        m_userColors.put(USERCOLOR55, FCColor::rgba(255, 80, 80, 200));
        m_userColors.put(USERCOLOR56, FCColor::rgba(50, 50, 50, 150));
        m_userColors.put(USERCOLOR57, FCColor::rgba(0, 105, 217, 240));
        m_userColors.put(USERCOLOR58, FCColor::rgba(0, 0, 0, 25));
        m_userColors.put(USERCOLOR59, FCColor::rgb(255, 215, 0));
        m_userColors.put(USERCOLOR60, FCColor::rgb(150, 150, 150));
        m_userColors.put(USERCOLOR61, FCColor::rgba(0, 0, 0, 200));
        m_userColors.put(USERCOLOR62, FCColor::rgba(185, 63, 150, 50)); //1
        m_userColors.put(USERCOLOR63, FCColor::rgb(10, 36, 106));
        m_userColors.put(USERCOLOR64, FCColor::rgb(21, 24, 28));
        m_userColors.put(USERCOLOR65, FCColor::rgba(0, 0, 0, 100));
        m_userColors.put(USERCOLOR66, FCColor::rgba(0, 0, 0, 50));
        m_userColors.put(USERCOLOR67, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR68, FCColor::rgba(185, 63, 150, 200)); //1
        m_userColors.put(USERCOLOR69, FCColor::rgb(248, 73, 96));
        m_userColors.put(USERCOLOR70, FCColor::rgb(15, 193, 118));
        m_userColors.put(USERCOLOR71, FCColor::rgba(248, 73, 96, 150));
        m_userColors.put(USERCOLOR72, FCColor::rgba(15, 193, 118, 150));
        m_userColors.put(USERCOLOR73, FCColor::rgb(130, 140, 150));
        m_userColors.put(USERCOLOR74, FCColor::rgba(185, 63, 150, 200)); //1
        m_userColors.put(USERCOLOR75, FCColor::rgb(83, 195, 42));
        m_userColors.put(USERCOLOR76, FCColor::rgb(231, 192, 42));
        m_userColors.put(USERCOLOR77, FCColor::rgb(254, 89, 82));
        m_userColors.put(USERCOLOR78, FCColor::rgba(42, 138, 195, 100));
        m_userColors.put(USERCOLOR79, FCColor::rgb(185, 63, 150));; //1
        m_userColors.put(USERCOLOR80, FCColor::rgba(52, 53, 58, 150));
        m_userColors.put(USERCOLOR81, FCColor::rgb(185, 63, 150)); //1
        m_userColors.put(USERCOLOR82, FCColor::rgba(16, 95, 205, 100));
        m_userColors.put(USERCOLOR83, FCColor::rgb(107, 107, 107));
        m_userColors.put(USERCOLOR84, FCColor::rgb(233, 233, 233));
        m_userColors.put(USERCOLOR85, FCColor::rgb(70, 76, 79));
        m_userColors.put(USERCOLOR86, FCColor::rgba(185, 63, 150, 100)); //1
        m_userColors.put(USERCOLOR87, FCColor::rgb(39, 41, 46));
         m_userColors.put(USERCOLOR88, FCColor::rgb(184, 185, 186));
        m_userColors.put(USERCOLOR89, FCColor::rgb(150, 150, 150));
        m_userColors.put(USERCOLOR90, FCColor::rgb(255, 255, 80));
        m_userColors.put(USERCOLOR91, FCColor::rgba(185, 63, 150, 200)); //1
        m_userColors.put(USERCOLOR92, FCColor::rgba(185, 63, 150, 50));//1
        m_userColors.put(USERCOLOR93, FCColor::rgba(50, 50, 50, 25));
        m_userColors.put(USERCOLOR94, FCColor::rgba(185, 63, 150, 200)); //1
        m_userColors.put(USERCOLOR95, FCColor::rgba(185, 63, 150, 100)); //1
        m_userColors.put(USERCOLOR96, FCColor::rgb(150, 0, 0));
        m_userColors.put(USERCOLOR97, FCColor::rgb(80, 255, 255));
        m_userColors.put(USERCOLOR98, FCColor::rgb(217, 217, 68));
        m_userColors.put(USERCOLOR99, FCColor::rgb(112, 112, 112));
        m_userColors.put(USERCOLOR100, FCColor::rgb(192, 192, 192));
        m_userColors.put(USERCOLOR101, FCColor::rgb(255, 255, 0));
        m_userColors.put(USERCOLOR102, FCColor::rgba(0, 0, 0, 200));
        m_userColors.put(USERCOLOR103, FCColor::rgba(43, 138, 195, 240));
        m_userColors.put(USERCOLOR104, FCColor::rgba(21, 24, 28, 240));
        m_userColors.put(USERCOLOR105, FCColor::rgba(255, 255, 255, 12));
        m_userColors.put(USERCOLOR106, FCColor::rgb(222, 86, 122));
        m_userColors.put(USERCOLOR107, FCColor::rgb(115, 183, 72));
        m_userColors.put(USERCOLOR108, FCColor::rgba(219, 68, 83, 200));
        m_userColors.put(USERCOLOR109, FCColor::rgba(140, 192, 81, 200));
        m_userColors.put(USERCOLOR110, FCColor::rgb(216, 112, 173));
        m_userColors.put(USERCOLOR111, FCColor::rgba(32, 36, 38, 100));
        m_userColors.put(USERCOLOR112, FCColor::rgba(42, 138, 195, 230));
        m_userColors.put(USERCOLOR113, FCColor::rgba(15, 193, 118, 50));
        m_userColors.put(USERCOLOR114, FCColor::rgba(248, 73, 96, 50));
        m_userColors.put(USERCOLOR115, FCColor::rgba(170, 178, 189, 25));
        m_userColors.put(USERCOLOR116, FCColor::rgb(217, 218, 223));
        m_userColors.put(USERCOLOR117, FCColor::rgb(167, 171, 184));
        m_userColors.put(FCColor_Back, FCColor::rgb(19, 21, 26));
        m_userColors.put(FCColor_Border, FCColor::rgb(50, 50, 50));
        m_userColors.put(FCColor_Text, FCColor::rgb(255, 255, 255));
        m_userColors.put(FCColor_DisabledBack, FCColor::rgba(255, 255, 255, 25));
        m_userColors.put(FCColor_DisabledText, 3289650);
        m_userColors.put(FCColor_Hovered, FCColor::rgba(185, 63, 150, 150)); //1
        m_userColors.put(FCColor_Pushed, FCColor::rgba(185, 63, 150, 100)); //1

    }
    else if (m_style == 5)
    {
        m_userColors.put(USERCOLOR, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR1, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR2, FCColor::rgba(255, 255, 255, 100));
        m_userColors.put(USERCOLOR3, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR4, FCColor::rgb(0, 0, 0));
        m_userColors.put(USERCOLOR5, FCColor::rgb(75, 137, 220)); //1
        m_userColors.put(USERCOLOR6, FCColor::rgba(255, 255, 255, 25));
        m_userColors.put(USERCOLOR7, FCColor::rgb(19, 21, 26));
        m_userColors.put(USERCOLOR8, FCColor::rgb(50, 50, 50));
        m_userColors.put(USERCOLOR9, FCColor::rgb(0, 0, 0));
        m_userColors.put(USERCOLOR10, FCColor::rgb(75, 137, 220)); //1
        m_userColors.put(USERCOLOR11, FCColor::rgba(255, 255, 255, 200));
        m_userColors.put(USERCOLOR12, FCColor::rgb(19, 21, 26));
        m_userColors.put(USERCOLOR13, FCColor::rgba(50, 50, 50, 240));
        m_userColors.put(USERCOLOR14, FCColor::rgba(50, 50, 50, 100));
        m_userColors.put(USERCOLOR15, FCColor::rgb(46, 47, 49));
        m_userColors.put(USERCOLOR16, FCColor::rgb(50, 50, 50));
        m_userColors.put(USERCOLOR17, FCColor::rgb(100, 100, 100));
        m_userColors.put(USERCOLOR18, FCColor::rgba(255, 255, 255, 5));
        m_userColors.put(USERCOLOR19, FCColor::rgba(255, 255, 255, 50));
        m_userColors.put(USERCOLOR20, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR21, FCColor::rgba(75, 137, 220, 100)); //1
        m_userColors.put(USERCOLOR22, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR23, FCColor::rgba(75, 137, 220, 100)); //1
        m_userColors.put(USERCOLOR24, FCColor::rgb(100, 100, 100));
        m_userColors.put(USERCOLOR25, FCColor::rgb(255, 82, 82));
        m_userColors.put(USERCOLOR26, FCColor::rgb(50, 105, 217));
        m_userColors.put(USERCOLOR27, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR28, FCColor::rgb(200, 200, 200));
        m_userColors.put(USERCOLOR29, FCColor::rgb(80, 80, 80));
        m_userColors.put(USERCOLOR30, FCColor::rgb(25, 25, 25));
        m_userColors.put(USERCOLOR31, FCColor::rgb(255, 0, 0));
        m_userColors.put(USERCOLOR32, FCColor::rgb(139, 180, 248));
        m_userColors.put(USERCOLOR33, FCColor::rgb(0, 165, 137));
        m_userColors.put(USERCOLOR34, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR35, FCColor::rgba(100, 100, 100, 200));
        m_userColors.put(USERCOLOR36, FCColor::rgba(75, 137, 220, 200)); //1
        m_userColors.put(USERCOLOR37, FCColor::rgb(255, 80, 80));
        m_userColors.put(USERCOLOR38, FCColor::rgba(43, 138, 195, 25));
        m_userColors.put(USERCOLOR39, FCColor::rgba(51, 153, 255, 75));
        m_userColors.put(USERCOLOR40, FCColor::rgb(0, 200, 0));
        m_userColors.put(USERCOLOR41, FCColor::rgba(0, 0, 0, 10));
        m_userColors.put(USERCOLOR42, FCColor::rgba(50, 50, 50, 50));
        m_userColors.put(USERCOLOR43, FCColor::rgb(0, 105, 217));
        m_userColors.put(USERCOLOR44, FCColor::rgba(255, 255, 255, 150));
        m_userColors.put(USERCOLOR45, FCColor::rgba(255, 0, 0, 200));
        m_userColors.put(USERCOLOR46, FCColor::rgba(170, 178, 189, 50));
        m_userColors.put(USERCOLOR47, FCColor::rgba(170, 178, 189, 200));
        m_userColors.put(USERCOLOR48, FCColor::rgb(219, 68, 83));
        m_userColors.put(USERCOLOR49, FCColor::rgb(255, 80, 80));
        m_userColors.put(USERCOLOR50, FCColor::rgb(246, 187, 67));
        m_userColors.put(USERCOLOR51, FCColor::rgb(59, 174, 218));
        m_userColors.put(USERCOLOR52, FCColor::rgb(216, 112, 173));
        m_userColors.put(USERCOLOR53, FCColor::rgb(140, 192, 81));
        m_userColors.put(USERCOLOR54, FCColor::rgb(80, 255, 80));
        m_userColors.put(USERCOLOR55, FCColor::rgba(255, 80, 80, 200));
        m_userColors.put(USERCOLOR56, FCColor::rgba(50, 50, 50, 150));
        m_userColors.put(USERCOLOR57, FCColor::rgba(0, 105, 217, 240));
        m_userColors.put(USERCOLOR58, FCColor::rgba(0, 0, 0, 25));
        m_userColors.put(USERCOLOR59, FCColor::rgb(255, 215, 0));
        m_userColors.put(USERCOLOR60, FCColor::rgb(150, 150, 150));
        m_userColors.put(USERCOLOR61, FCColor::rgba(0, 0, 0, 200));
        m_userColors.put(USERCOLOR62, FCColor::rgba(75, 137, 220, 50)); //1
        m_userColors.put(USERCOLOR63, FCColor::rgb(10, 36, 106));
        m_userColors.put(USERCOLOR64, FCColor::rgb(21, 24, 28));
        m_userColors.put(USERCOLOR65, FCColor::rgba(0, 0, 0, 100));
        m_userColors.put(USERCOLOR66, FCColor::rgba(0, 0, 0, 50));
        m_userColors.put(USERCOLOR67, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR68, FCColor::rgba(75, 137, 220, 200)); //1
        m_userColors.put(USERCOLOR69, FCColor::rgb(248, 73, 96));
        m_userColors.put(USERCOLOR70, FCColor::rgb(15, 193, 118));
        m_userColors.put(USERCOLOR71, FCColor::rgba(248, 73, 96, 150));
        m_userColors.put(USERCOLOR72, FCColor::rgba(15, 193, 118, 150));
        m_userColors.put(USERCOLOR73, FCColor::rgb(130, 140, 150));
        m_userColors.put(USERCOLOR74, FCColor::rgba(75, 137, 220, 200)); //1
        m_userColors.put(USERCOLOR75, FCColor::rgb(83, 195, 42));
        m_userColors.put(USERCOLOR76, FCColor::rgb(231, 192, 42));
        m_userColors.put(USERCOLOR77, FCColor::rgb(254, 89, 82));
        m_userColors.put(USERCOLOR78, FCColor::rgba(42, 138, 195, 100));
        m_userColors.put(USERCOLOR79, FCColor::rgb(75, 137, 220));; //1
        m_userColors.put(USERCOLOR80, FCColor::rgba(52, 53, 58, 150));
        m_userColors.put(USERCOLOR81, FCColor::rgb(75, 137, 220)); //1
        m_userColors.put(USERCOLOR82, FCColor::rgba(16, 95, 205, 100));
        m_userColors.put(USERCOLOR83, FCColor::rgb(107, 107, 107));
        m_userColors.put(USERCOLOR84, FCColor::rgb(233, 233, 233));
        m_userColors.put(USERCOLOR85, FCColor::rgb(70, 76, 79));
        m_userColors.put(USERCOLOR86, FCColor::rgba(75, 137, 220, 100)); //1
        m_userColors.put(USERCOLOR87, FCColor::rgb(39, 41, 46));
         m_userColors.put(USERCOLOR88, FCColor::rgb(184, 185, 186));
        m_userColors.put(USERCOLOR89, FCColor::rgb(150, 150, 150));
        m_userColors.put(USERCOLOR90, FCColor::rgb(255, 255, 80));
        m_userColors.put(USERCOLOR91, FCColor::rgba(75, 137, 220, 200)); //1
        m_userColors.put(USERCOLOR92, FCColor::rgba(75, 137, 220, 50));//1
        m_userColors.put(USERCOLOR93, FCColor::rgba(50, 50, 50, 25));
        m_userColors.put(USERCOLOR94, FCColor::rgba(75, 137, 220, 200)); //1
        m_userColors.put(USERCOLOR95, FCColor::rgba(75, 137, 220, 100)); //1
        m_userColors.put(USERCOLOR96, FCColor::rgb(150, 0, 0));
        m_userColors.put(USERCOLOR97, FCColor::rgb(80, 255, 255));
        m_userColors.put(USERCOLOR98, FCColor::rgb(217, 217, 68));
        m_userColors.put(USERCOLOR99, FCColor::rgb(112, 112, 112));
        m_userColors.put(USERCOLOR100, FCColor::rgb(192, 192, 192));
        m_userColors.put(USERCOLOR101, FCColor::rgb(255, 255, 0));
        m_userColors.put(USERCOLOR102, FCColor::rgba(0, 0, 0, 200));
        m_userColors.put(USERCOLOR103, FCColor::rgba(43, 138, 195, 240));
        m_userColors.put(USERCOLOR104, FCColor::rgba(21, 24, 28, 240));
        m_userColors.put(USERCOLOR105, FCColor::rgba(255, 255, 255, 12));
        m_userColors.put(USERCOLOR106, FCColor::rgb(222, 86, 122));
        m_userColors.put(USERCOLOR107, FCColor::rgb(115, 183, 72));
        m_userColors.put(USERCOLOR108, FCColor::rgba(219, 68, 83, 200));
        m_userColors.put(USERCOLOR109, FCColor::rgba(140, 192, 81, 200));
        m_userColors.put(USERCOLOR110, FCColor::rgb(75, 137, 220));
        m_userColors.put(USERCOLOR111, FCColor::rgba(32, 36, 38, 100));
        m_userColors.put(USERCOLOR112, FCColor::rgba(42, 138, 195, 230));
        m_userColors.put(USERCOLOR113, FCColor::rgba(15, 193, 118, 50));
        m_userColors.put(USERCOLOR114, FCColor::rgba(248, 73, 96, 50));
        m_userColors.put(USERCOLOR115, FCColor::rgba(170, 178, 189, 25));
        m_userColors.put(USERCOLOR116, FCColor::rgb(217, 218, 223));
        m_userColors.put(USERCOLOR117, FCColor::rgb(167, 171, 184));
        m_userColors.put(FCColor_Back, FCColor::rgb(19, 21, 26));
        m_userColors.put(FCColor_Border, FCColor::rgb(50, 50, 50));
        m_userColors.put(FCColor_Text, FCColor::rgb(255, 255, 255));
        m_userColors.put(FCColor_DisabledBack, FCColor::rgba(255, 255, 255, 25));
        m_userColors.put(FCColor_DisabledText, 3289650);
        m_userColors.put(FCColor_Hovered, FCColor::rgba(75, 137, 220, 150)); //1
        m_userColors.put(FCColor_Pushed, FCColor::rgba(75, 137, 220, 100)); //1
    }
    else if (m_style == 6)
    {
        m_userColors.put(USERCOLOR, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR1, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR2, FCColor::rgba(255, 255, 255, 100));
        m_userColors.put(USERCOLOR3, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR4, FCColor::rgb(0, 0, 0));
        m_userColors.put(USERCOLOR5, FCColor::rgb(255, 215, 0)); //1
        m_userColors.put(USERCOLOR6, FCColor::rgba(255, 255, 255, 25));
        m_userColors.put(USERCOLOR7, FCColor::rgb(19, 21, 26));
        m_userColors.put(USERCOLOR8, FCColor::rgb(50, 50, 50));
        m_userColors.put(USERCOLOR9, FCColor::rgb(0, 0, 0));
        m_userColors.put(USERCOLOR10, FCColor::rgba(255, 215, 0, 200)); //1
        m_userColors.put(USERCOLOR11, FCColor::rgba(255, 255, 255, 200));
        m_userColors.put(USERCOLOR12, FCColor::rgb(19, 21, 26));
        m_userColors.put(USERCOLOR13, FCColor::rgba(50, 50, 50, 240));
        m_userColors.put(USERCOLOR14, FCColor::rgba(50, 50, 50, 100));
        m_userColors.put(USERCOLOR15, FCColor::rgb(46, 47, 49));;
        m_userColors.put(USERCOLOR16, FCColor::rgb(50, 50, 50));
        m_userColors.put(USERCOLOR17, FCColor::rgb(100, 100, 100));
        m_userColors.put(USERCOLOR18, FCColor::rgba(255, 255, 255, 5));
        m_userColors.put(USERCOLOR19, FCColor::rgba(255, 255, 255, 50));
        m_userColors.put(USERCOLOR20, FCColor::rgb(200, 200, 200));
        m_userColors.put(USERCOLOR21, FCColor::rgb(75, 75, 75));
        m_userColors.put(USERCOLOR22, FCColor::rgb(170, 178, 189));
        m_userColors.put(USERCOLOR23, FCColor::rgba(255, 215, 0, 100)); //1
        m_userColors.put(USERCOLOR24, FCColor::rgb(100, 100, 100));
        m_userColors.put(USERCOLOR25, FCColor::rgb(255, 82, 82));
        m_userColors.put(USERCOLOR26, FCColor::rgb(50, 105, 217));
        m_userColors.put(USERCOLOR27, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR28, FCColor::rgb(200, 200, 200));
        m_userColors.put(USERCOLOR29, FCColor::rgb(80, 80, 80));
        m_userColors.put(USERCOLOR30, FCColor::rgb(25, 25, 25));
        m_userColors.put(USERCOLOR31, FCColor::rgb(255, 0, 0));
        m_userColors.put(USERCOLOR32, FCColor::rgb(139, 180, 248));
        m_userColors.put(USERCOLOR33, FCColor::rgb(0, 165, 137));
        m_userColors.put(USERCOLOR34, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR35, FCColor::rgba(100, 100, 100, 200));
        m_userColors.put(USERCOLOR36, FCColor::rgba(255, 215, 0, 150)); //1
        m_userColors.put(USERCOLOR37, FCColor::rgb(255, 80, 80));
        m_userColors.put(USERCOLOR38, FCColor::rgba(255, 215, 0, 25)); //1
        m_userColors.put(USERCOLOR39, FCColor::rgba(51, 153, 255, 75));
        m_userColors.put(USERCOLOR40, FCColor::rgb(0, 200, 0));
        m_userColors.put(USERCOLOR41, FCColor::rgba(0, 0, 0, 10));
        m_userColors.put(USERCOLOR42, FCColor::rgba(50, 50, 50, 50));
        m_userColors.put(USERCOLOR43, FCColor::rgb(0, 105, 217));
        m_userColors.put(USERCOLOR44, FCColor::rgba(255, 255, 255, 150));
        m_userColors.put(USERCOLOR45, FCColor::rgba(255, 0, 0, 200));
        m_userColors.put(USERCOLOR46, FCColor::rgba(170, 178, 189, 50));
        m_userColors.put(USERCOLOR47, FCColor::rgba(170, 178, 189, 200));
        m_userColors.put(USERCOLOR48, FCColor::rgb(219, 68, 83));
        m_userColors.put(USERCOLOR49, FCColor::rgb(255, 80, 80));
        m_userColors.put(USERCOLOR50, FCColor::rgb(246, 187, 67));
        m_userColors.put(USERCOLOR51, FCColor::rgb(59, 174, 218));
        m_userColors.put(USERCOLOR52, FCColor::rgb(216, 112, 173));
        m_userColors.put(USERCOLOR53, FCColor::rgb(140, 192, 81));
        m_userColors.put(USERCOLOR54, FCColor::rgb(80, 255, 80));
        m_userColors.put(USERCOLOR55, FCColor::rgba(255, 80, 80, 200));
        m_userColors.put(USERCOLOR56, FCColor::rgba(50, 50, 50, 150));
        m_userColors.put(USERCOLOR57, FCColor::rgba(0, 105, 217, 240));
        m_userColors.put(USERCOLOR58, FCColor::rgba(0, 0, 0, 25));
        m_userColors.put(USERCOLOR59, FCColor::rgb(255, 215, 0));
        m_userColors.put(USERCOLOR60, FCColor::rgb(150, 150, 150));
        m_userColors.put(USERCOLOR61, FCColor::rgba(0, 0, 0, 200));
        m_userColors.put(USERCOLOR62, FCColor::rgba(255, 215, 0, 50)); //1
        m_userColors.put(USERCOLOR63, FCColor::rgb(10, 36, 106));
        m_userColors.put(USERCOLOR64, FCColor::rgb(21, 24, 28));
        m_userColors.put(USERCOLOR65, FCColor::rgba(0, 0, 0, 100));
        m_userColors.put(USERCOLOR66, FCColor::rgba(0, 0, 0, 50));
        m_userColors.put(USERCOLOR67, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR68, FCColor::rgb(32, 36, 38));
        m_userColors.put(USERCOLOR69, FCColor::rgb(248, 73, 96));
        m_userColors.put(USERCOLOR70, FCColor::rgb(15, 193, 118));
        m_userColors.put(USERCOLOR71, FCColor::rgba(248, 73, 96, 150));
        m_userColors.put(USERCOLOR72, FCColor::rgba(15, 193, 118, 150));
        m_userColors.put(USERCOLOR73, FCColor::rgb(130, 140, 150));
        m_userColors.put(USERCOLOR74, FCColor::rgba(94, 102, 115, 200));
        m_userColors.put(USERCOLOR75, FCColor::rgb(83, 195, 42));
        m_userColors.put(USERCOLOR76, FCColor::rgb(231, 192, 42));
        m_userColors.put(USERCOLOR77, FCColor::rgb(254, 89, 82));
        m_userColors.put(USERCOLOR78, FCColor::rgba(42, 138, 195, 100));
        m_userColors.put(USERCOLOR79, FCColor::rgb(52, 53, 58));
        m_userColors.put(USERCOLOR80, FCColor::rgba(52, 53, 58, 150));
        m_userColors.put(USERCOLOR81, FCColor::rgb(16, 95, 205));
        m_userColors.put(USERCOLOR82, FCColor::rgba(16, 95, 205, 100));
        m_userColors.put(USERCOLOR83, FCColor::rgb(107, 107, 107));
        m_userColors.put(USERCOLOR84, FCColor::rgb(233, 233, 233));
        m_userColors.put(USERCOLOR85, FCColor::rgb(70, 76, 79));
        m_userColors.put(USERCOLOR86, FCColor::rgb(50, 82, 114));
        m_userColors.put(USERCOLOR87, FCColor::rgb(39, 41, 46));
        m_userColors.put(USERCOLOR88, FCColor::rgb(184, 185, 186));
        m_userColors.put(USERCOLOR89, FCColor::rgb(150, 150, 150));
        m_userColors.put(USERCOLOR90, FCColor::rgb(255, 255, 80));
        m_userColors.put(USERCOLOR91, FCColor::rgba(42, 138, 195, 200));
        m_userColors.put(USERCOLOR92, FCColor::rgba(32, 36, 38, 50));;
        m_userColors.put(USERCOLOR93, FCColor::rgba(50, 50, 50, 25));
        m_userColors.put(USERCOLOR94, FCColor::rgb(50, 50, 50));
        m_userColors.put(USERCOLOR95, FCColor::rgb(128, 128, 128));
        m_userColors.put(USERCOLOR96, FCColor::rgb(150, 0, 0));
        m_userColors.put(USERCOLOR97, FCColor::rgb(80, 255, 255));
        m_userColors.put(USERCOLOR98, FCColor::rgb(217, 217, 68));
        m_userColors.put(USERCOLOR99, FCColor::rgb(112, 112, 112));
        m_userColors.put(USERCOLOR100, FCColor::rgb(192, 192, 192));
        m_userColors.put(USERCOLOR101, FCColor::rgb(255, 255, 0));
        m_userColors.put(USERCOLOR102, FCColor::rgba(0, 0, 0, 200));
        m_userColors.put(USERCOLOR103, FCColor::rgba(43, 138, 195, 240));
        m_userColors.put(USERCOLOR104, FCColor::rgba(21, 24, 28, 240));
        m_userColors.put(USERCOLOR105, FCColor::rgba(255, 255, 255, 12));
        m_userColors.put(USERCOLOR106, FCColor::rgb(222, 86, 122));
        m_userColors.put(USERCOLOR107, FCColor::rgb(115, 183, 72));
        m_userColors.put(USERCOLOR108, FCColor::rgba(219, 68, 83, 200));
        m_userColors.put(USERCOLOR109, FCColor::rgba(140, 192, 81, 200));
        m_userColors.put(USERCOLOR110, FCColor::rgb(15, 193, 118));
        m_userColors.put(USERCOLOR111, FCColor::rgba(32, 36, 38, 100));
        m_userColors.put(USERCOLOR112, FCColor::rgba(42, 138, 195, 230));
        m_userColors.put(USERCOLOR113, FCColor::rgba(15, 193, 118, 50));
        m_userColors.put(USERCOLOR114, FCColor::rgba(248, 73, 96, 50));
        m_userColors.put(USERCOLOR115, FCColor::rgba(170, 178, 189, 25));
        m_userColors.put(USERCOLOR116, FCColor::rgb(217, 218, 223));
        m_userColors.put(USERCOLOR117, FCColor::rgb(167, 171, 184));
        m_userColors.put(FCColor_Back, FCColor::rgb(19, 21, 26));
        m_userColors.put(FCColor_Border, FCColor::rgb(50, 50, 50));
        m_userColors.put(FCColor_Text, FCColor::rgb(255, 255, 255));
        m_userColors.put(FCColor_DisabledBack, FCColor::rgba(255, 255, 255, 25));
        m_userColors.put(FCColor_DisabledText, 3289650);
        m_userColors.put(FCColor_Hovered, FCColor::rgba(43, 138, 195, 150));
        m_userColors.put(FCColor_Pushed, FCColor::rgba(43, 138, 195, 100));

    }else{
        m_userColors.put(USERCOLOR, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR1, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR2, FCColor::rgba(255, 255, 255, 100));
        m_userColors.put(USERCOLOR3, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR4, FCColor::rgb(0, 0, 0));
        m_userColors.put(USERCOLOR5, FCColor::rgb(42, 138, 195));
        m_userColors.put(USERCOLOR6, FCColor::rgba(255, 255, 255, 25));
        m_userColors.put(USERCOLOR7, FCColor::rgb(19, 21, 26));
        m_userColors.put(USERCOLOR8, FCColor::rgb(50, 50, 50));
        m_userColors.put(USERCOLOR9, FCColor::rgb(0, 0, 0));
        m_userColors.put(USERCOLOR10, FCColor::rgb(43, 138, 195));
        m_userColors.put(USERCOLOR11, FCColor::rgba(255, 255, 255, 200));
        m_userColors.put(USERCOLOR12, FCColor::rgb(19, 21, 26));
        m_userColors.put(USERCOLOR13, FCColor::rgba(50, 50, 50, 240));
        m_userColors.put(USERCOLOR14, FCColor::rgba(50, 50, 50, 100));
        m_userColors.put(USERCOLOR15, FCColor::rgb(46, 47, 49));;
        m_userColors.put(USERCOLOR16, FCColor::rgb(50, 50, 50));
        m_userColors.put(USERCOLOR17, FCColor::rgb(100, 100, 100));
        m_userColors.put(USERCOLOR18, FCColor::rgba(255, 255, 255, 5));
        m_userColors.put(USERCOLOR19, FCColor::rgba(255, 255, 255, 50));
        m_userColors.put(USERCOLOR20, FCColor::rgb(200, 200, 200));
        m_userColors.put(USERCOLOR21, FCColor::rgb(75, 75, 75));
        m_userColors.put(USERCOLOR22, FCColor::rgb(170, 178, 189));
        m_userColors.put(USERCOLOR23, FCColor::rgba(43, 138, 195, 100));
        m_userColors.put(USERCOLOR24, FCColor::rgb(100, 100, 100));
        m_userColors.put(USERCOLOR25, FCColor::rgb(255, 82, 82));
        m_userColors.put(USERCOLOR26, FCColor::rgb(50, 105, 217));
        m_userColors.put(USERCOLOR27, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR28, FCColor::rgb(200, 200, 200));
        m_userColors.put(USERCOLOR29, FCColor::rgb(80, 80, 80));
        m_userColors.put(USERCOLOR30, FCColor::rgb(25, 25, 25));
        m_userColors.put(USERCOLOR31, FCColor::rgb(255, 0, 0));
        m_userColors.put(USERCOLOR32, FCColor::rgb(139, 180, 248));
        m_userColors.put(USERCOLOR33, FCColor::rgb(0, 165, 137));
        m_userColors.put(USERCOLOR34, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR35, FCColor::rgba(100, 100, 100, 200));
        m_userColors.put(USERCOLOR36, FCColor::rgba(43, 138, 195, 200));
        m_userColors.put(USERCOLOR37, FCColor::rgb(255, 80, 80));
        m_userColors.put(USERCOLOR38, FCColor::rgba(43, 138, 195, 25));
        m_userColors.put(USERCOLOR39, FCColor::rgba(51, 153, 255, 75));
        m_userColors.put(USERCOLOR40, FCColor::rgb(0, 200, 0));
        m_userColors.put(USERCOLOR41, FCColor::rgba(0, 0, 0, 10));
        m_userColors.put(USERCOLOR42, FCColor::rgba(50, 50, 50, 50));
        m_userColors.put(USERCOLOR43, FCColor::rgb(0, 105, 217));
        m_userColors.put(USERCOLOR44, FCColor::rgba(255, 255, 255, 150));
        m_userColors.put(USERCOLOR45, FCColor::rgba(255, 0, 0, 200));
        m_userColors.put(USERCOLOR46, FCColor::rgba(170, 178, 189, 50));
        m_userColors.put(USERCOLOR47, FCColor::rgba(170, 178, 189, 200));
        m_userColors.put(USERCOLOR48, FCColor::rgb(219, 68, 83));
        m_userColors.put(USERCOLOR49, FCColor::rgb(255, 80, 80));
        m_userColors.put(USERCOLOR50, FCColor::rgb(246, 187, 67));
        m_userColors.put(USERCOLOR51, FCColor::rgb(59, 174, 218));
        m_userColors.put(USERCOLOR52, FCColor::rgb(216, 112, 173));
        m_userColors.put(USERCOLOR53, FCColor::rgb(140, 192, 81));
        m_userColors.put(USERCOLOR54, FCColor::rgb(80, 255, 80));
        m_userColors.put(USERCOLOR55, FCColor::rgba(255, 80, 80, 200));
        m_userColors.put(USERCOLOR56, FCColor::rgba(50, 50, 50, 150));
        m_userColors.put(USERCOLOR57, FCColor::rgba(0, 105, 217, 240));
        m_userColors.put(USERCOLOR58, FCColor::rgba(0, 0, 0, 25));
        m_userColors.put(USERCOLOR59, FCColor::rgb(255, 215, 0));
        m_userColors.put(USERCOLOR60, FCColor::rgb(150, 150, 150));
        m_userColors.put(USERCOLOR61, FCColor::rgba(0, 0, 0, 200));
        m_userColors.put(USERCOLOR62, FCColor::rgba(43, 138, 195, 50));
        m_userColors.put(USERCOLOR63, FCColor::rgb(10, 36, 106));
        m_userColors.put(USERCOLOR64, FCColor::rgb(21, 24, 28));
        m_userColors.put(USERCOLOR65, FCColor::rgba(0, 0, 0, 100));
        m_userColors.put(USERCOLOR66, FCColor::rgba(0, 0, 0, 50));
        m_userColors.put(USERCOLOR67, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR68, FCColor::rgb(32, 36, 38));
        m_userColors.put(USERCOLOR69, FCColor::rgb(248, 73, 96));
        m_userColors.put(USERCOLOR70, FCColor::rgb(15, 193, 118));
        m_userColors.put(USERCOLOR71, FCColor::rgba(248, 73, 96, 150));
        m_userColors.put(USERCOLOR72, FCColor::rgba(15, 193, 118, 150));
        m_userColors.put(USERCOLOR73, FCColor::rgb(130, 140, 150));
        m_userColors.put(USERCOLOR74, FCColor::rgba(94, 102, 115, 200));
        m_userColors.put(USERCOLOR75, FCColor::rgb(83, 195, 42));
        m_userColors.put(USERCOLOR76, FCColor::rgb(231, 192, 42));
        m_userColors.put(USERCOLOR77, FCColor::rgb(254, 89, 82));
        m_userColors.put(USERCOLOR78, FCColor::rgba(42, 138, 195, 100));
        m_userColors.put(USERCOLOR79, FCColor::rgb(52, 53, 58));
        m_userColors.put(USERCOLOR80, FCColor::rgba(52, 53, 58, 150));
        m_userColors.put(USERCOLOR81, FCColor::rgb(16, 95, 205));
        m_userColors.put(USERCOLOR82, FCColor::rgba(16, 95, 205, 100));
        m_userColors.put(USERCOLOR83, FCColor::rgb(107, 107, 107));
        m_userColors.put(USERCOLOR84, FCColor::rgb(233, 233, 233));
        m_userColors.put(USERCOLOR85, FCColor::rgb(70, 76, 79));
        m_userColors.put(USERCOLOR86, FCColor::rgb(50, 82, 114));
        m_userColors.put(USERCOLOR87, FCColor::rgb(39, 41, 46));
        m_userColors.put(USERCOLOR88, FCColor::rgb(184, 185, 186));
        m_userColors.put(USERCOLOR89, FCColor::rgb(150, 150, 150));
        m_userColors.put(USERCOLOR90, FCColor::rgb(255, 255, 80));
        m_userColors.put(USERCOLOR91, FCColor::rgba(42, 138, 195, 200));
        m_userColors.put(USERCOLOR92, FCColor::rgba(32, 36, 38, 50));;
        m_userColors.put(USERCOLOR93, FCColor::rgba(50, 50, 50, 25));
        m_userColors.put(USERCOLOR94, FCColor::rgb(50, 50, 50));
        m_userColors.put(USERCOLOR95, FCColor::rgb(128, 128, 128));
        m_userColors.put(USERCOLOR96, FCColor::rgb(150, 0, 0));
        m_userColors.put(USERCOLOR97, FCColor::rgb(80, 255, 255));
        m_userColors.put(USERCOLOR98, FCColor::rgb(217, 217, 68));
        m_userColors.put(USERCOLOR99, FCColor::rgb(112, 112, 112));
        m_userColors.put(USERCOLOR100, FCColor::rgb(192, 192, 192));
        m_userColors.put(USERCOLOR101, FCColor::rgb(255, 255, 0));
        m_userColors.put(USERCOLOR102, FCColor::rgba(0, 0, 0, 200));
        m_userColors.put(USERCOLOR103, FCColor::rgba(43, 138, 195, 240));
        m_userColors.put(USERCOLOR104, FCColor::rgba(21, 24, 28, 240));
        m_userColors.put(USERCOLOR105, FCColor::rgba(255, 255, 255, 12));
        m_userColors.put(USERCOLOR106, FCColor::rgb(222, 86, 122));
        m_userColors.put(USERCOLOR107, FCColor::rgb(115, 183, 72));
        m_userColors.put(USERCOLOR108, FCColor::rgba(219, 68, 83, 200));
        m_userColors.put(USERCOLOR109, FCColor::rgba(140, 192, 81, 200));
        m_userColors.put(USERCOLOR110, FCColor::rgb(15, 193, 118));
        m_userColors.put(USERCOLOR111, FCColor::rgba(32, 36, 38, 100));
        m_userColors.put(USERCOLOR112, FCColor::rgba(42, 138, 195, 230));
        m_userColors.put(USERCOLOR113, FCColor::rgba(15, 193, 118, 50));
        m_userColors.put(USERCOLOR114, FCColor::rgba(248, 73, 96, 50));
        m_userColors.put(USERCOLOR115, FCColor::rgba(170, 178, 189, 25));
        m_userColors.put(USERCOLOR116, FCColor::rgb(217, 218, 223));
        m_userColors.put(USERCOLOR117, FCColor::rgb(167, 171, 184));
        m_userColors.put(FCColor_Back, FCColor::rgb(19, 21, 26));
        m_userColors.put(FCColor_Border, FCColor::rgb(50, 50, 50));
        m_userColors.put(FCColor_Text, FCColor::rgb(255, 255, 255));
        m_userColors.put(FCColor_DisabledBack, FCColor::rgba(255, 255, 255, 25));
        m_userColors.put(FCColor_DisabledText, 3289650);
        m_userColors.put(FCColor_Hovered, FCColor::rgba(43, 138, 195, 150));
        m_userColors.put(FCColor_Pushed, FCColor::rgba(43, 138, 195, 100));
    }
}

Long MyColor::getUserColor(Long color){
    if (m_lastStyle != m_style)
    {
        m_lastStyle = m_style;
       createColors();
    }
    if (m_userColors.containsKey(color))
    {
       color = m_userColors.get(color);
    }
    return color;
}

void GdiPlusPaintEx::affectScaleFactor(Rect *gdiplusRect){
	if (m_scaleFactorX != 1 || m_scaleFactorY != 1){
        gdiplusRect->X = (int)(gdiplusRect->X * m_scaleFactorX);
        gdiplusRect->Y = (int)(gdiplusRect->Y * m_scaleFactorY);
        gdiplusRect->Width = (int)(gdiplusRect->Width * m_scaleFactorX);
        gdiplusRect->Height = (int)(gdiplusRect->Height * m_scaleFactorY);
    }
}

void GdiPlusPaintEx::affectScaleFactor(RectF *gdiplusRect){
	if (m_scaleFactorX != 1 || m_scaleFactorY != 1){
        gdiplusRect->X = (float)(gdiplusRect->X * m_scaleFactorX);
        gdiplusRect->Y = (float)(gdiplusRect->Y * m_scaleFactorY);
        gdiplusRect->Width = (float)(gdiplusRect->Width * m_scaleFactorX);
        gdiplusRect->Height = (float)(gdiplusRect->Height * m_scaleFactorY);
    }
}

SolidBrush* GdiPlusPaintEx::getBrush(Long dwPenColor){
    Color gdiColor = getGdiPlusColor(dwPenColor);
    if (!m_brush){
        m_brush = new SolidBrush(gdiColor);
        if (m_opacity == 1){
            m_brushColor = dwPenColor;
        }
        else{
            m_brushColor = FCColor_None;
        }
    }
    else{
        if (m_brushColor == FCColor_None || m_brushColor != dwPenColor){
            m_brush->SetColor(gdiColor);
            m_brushColor = dwPenColor;
        }
		if(m_opacity != 1){
			m_brushColor = FCColor_None;
		}
    }
    return m_brush;
}

Color GdiPlusPaintEx::getGdiPlusColor(Long dwPenColor){
	dwPenColor = getPaintColor(dwPenColor);
	int a = 255;
	if(dwPenColor < 0){
		dwPenColor = -dwPenColor;
		if(dwPenColor < 1){
			a = 255;
		}
		else{
			a = (int)(dwPenColor - dwPenColor / 1000 * 1000);
		}
		dwPenColor /= 1000;
	}
	int r = (int)(dwPenColor & 0xff);
	int g = (int)((dwPenColor >> 8) & 0xff);
	int b = (int)((dwPenColor >> 0x10) & 0xff);
	Color gdiColor(a, r, g, b);
	if(m_opacity < 1){
		Color opacityColor((BYTE)(a * m_opacity), r, g, b);
		return opacityColor;
	}
	return gdiColor;
}

int GdiPlusPaintEx::getEncoderClsid(const WCHAR *format, CLSID *pClsid){
	UINT  num = 0;          
	UINT  size = 0;         
	ImageCodecInfo *pImageCodecInfo = 0;
	GetImageEncodersSize(&num, &size);
	if(size == 0)
		return -1;  
	pImageCodecInfo = (ImageCodecInfo*)(malloc(size));
	if(pImageCodecInfo == 0)
		return -1; 
	GetImageEncoders(num, size, pImageCodecInfo);
	for(UINT j = 0; j < num; ++j){
		if( wcscmp(pImageCodecInfo[j].MimeType, format) == 0 ){
			*pClsid = pImageCodecInfo[j].Clsid;
			free(pImageCodecInfo);
			return j;  
		}    
	}
	free(pImageCodecInfo);
	return -1;  
}

Gdiplus::Font* GdiPlusPaintEx::getFont(FCFont *font){
	String fontFamily = font->m_fontFamily;
	if(fontFamily == L"Default"){
		fontFamily = MyColor::getSystemFont();
	}
	Gdiplus::Font *gdiFont = 0;
	int fontSize = (int)(font->m_fontSize);
	//font->m_fontFamily = L"华文彩云";
	//fontSize = (int)(font->m_fontSize * 1.15);
	if(font->m_strikeout){
		if (font->m_bold && font->m_underline && font->m_italic){
			gdiFont = new Gdiplus::Font(fontFamily.c_str(), fontSize, FontStyleBold | FontStyleUnderline | FontStyleItalic | FontStyleStrikeout, UnitPixel);
		}
		else if (font->m_bold && font->m_underline){
			gdiFont = new Gdiplus::Font(fontFamily.c_str(), fontSize, FontStyleBold | FontStyleUnderline | FontStyleStrikeout, UnitPixel);
		}
		else if (font->m_bold && font->m_italic){
			gdiFont = new Gdiplus::Font(fontFamily.c_str(), fontSize, FontStyleBold | FontStyleItalic | FontStyleStrikeout, UnitPixel);
		}
		else if (font->m_underline && font->m_italic){
			gdiFont = new Gdiplus::Font(fontFamily.c_str(), fontSize, FontStyleUnderline | FontStyleItalic | FontStyleStrikeout, UnitPixel);
		}
		else if (font->m_bold){
			gdiFont = new Gdiplus::Font(fontFamily.c_str(), fontSize, FontStyleBold | FontStyleStrikeout, UnitPixel);
		}
		else if(font->m_underline){
			gdiFont = new Gdiplus::Font(fontFamily.c_str(), fontSize, FontStyleUnderline | FontStyleStrikeout, UnitPixel);
		}
		else if (font->m_italic){
			gdiFont = new Gdiplus::Font(fontFamily.c_str(), fontSize, FontStyleItalic| FontStyleStrikeout, UnitPixel);
		}
		else{
			gdiFont = new Gdiplus::Font(fontFamily.c_str(), fontSize, FontStyleRegular| FontStyleStrikeout, UnitPixel);
		}
	}
	else{
		if (font->m_bold && font->m_underline && font->m_italic){
			gdiFont = new Gdiplus::Font(fontFamily.c_str(), fontSize, FontStyleBold | FontStyleUnderline | FontStyleItalic, UnitPixel);
		}
		else if (font->m_bold && font->m_underline){
			gdiFont = new Gdiplus::Font(fontFamily.c_str(), fontSize, FontStyleBold | FontStyleUnderline, UnitPixel);
		}
		else if (font->m_bold && font->m_italic){
			gdiFont = new Gdiplus::Font(fontFamily.c_str(), fontSize, FontStyleBold | FontStyleItalic, UnitPixel);
		}
		else if (font->m_underline && font->m_italic){
			gdiFont = new Gdiplus::Font(fontFamily.c_str(), fontSize, FontStyleUnderline | FontStyleItalic, UnitPixel);
		}
		else if (font->m_bold){
			gdiFont = new Gdiplus::Font(fontFamily.c_str(), fontSize, FontStyleBold, UnitPixel);
		}
		else if(font->m_underline){
			gdiFont = new Gdiplus::Font(fontFamily.c_str(), fontSize, FontStyleUnderline, UnitPixel);
		}
		else if (font->m_italic){
			gdiFont = new Gdiplus::Font(fontFamily.c_str(), fontSize, FontStyleItalic, UnitPixel);
		}
		else{
			gdiFont = new Gdiplus::Font(fontFamily.c_str(), fontSize, FontStyleRegular, UnitPixel);
		}
	}
	return gdiFont;
}

Pen* GdiPlusPaintEx::getPen(Long dwPenColor, float width, int style){
    Color gdiColor = getGdiPlusColor(dwPenColor);
    if (!m_pen ){
        m_pen = new Pen(gdiColor, (REAL)width);
        if (style == 0){
			m_pen->SetDashStyle(DashStyleSolid);  
        }
        else if (style == 1){
            m_pen->SetDashStyle(DashStyleDash);
        }
        else if (style == 2){
			m_pen->SetDashStyle(::DashStyleDot);
        }
        m_penWidth = width;
        m_penStyle = style;
		if (m_opacity == 1){
            m_penColor = dwPenColor;
        }
        else{
            m_penColor = FCColor_None;
        }
		switch(m_startLineCap){
		case 0:
			m_pen->SetStartCap(LineCapFlat);
			break;
		case 1:
			m_pen->SetStartCap(LineCapSquare);
			break;
		case 2:
			m_pen->SetStartCap(LineCapRound);
			break;
		case 3:
			m_pen->SetStartCap(LineCapTriangle);
			break;
		case 4:
			m_pen->SetStartCap(LineCapNoAnchor);
			break;
		case 5:
			m_pen->SetStartCap(LineCapSquareAnchor);
			break;
		case 6:
			m_pen->SetStartCap(LineCapRoundAnchor);
			break;
		case 7:
			m_pen->SetStartCap(LineCapDiamondAnchor);
			break;
		case 8:
			m_pen->SetStartCap(LineCapArrowAnchor);
			break;
		case 9:
			m_pen->SetStartCap(LineCapAnchorMask);
			break;
		case 10:
			m_pen->SetStartCap(LineCapCustom);
			break;
		}
		switch(m_endLineCap){
		case 0:
			m_pen->SetEndCap(LineCapFlat);
			break;
		case 1:
			m_pen->SetEndCap(LineCapSquare);
			break;
		case 2:
			m_pen->SetEndCap(LineCapRound);
			break;
		case 3:
			m_pen->SetEndCap(LineCapTriangle);
			break;
		case 4:
			m_pen->SetEndCap(LineCapNoAnchor);
			break;
		case 5:
			m_pen->SetEndCap(LineCapSquareAnchor);
			break;
		case 6:
			m_pen->SetEndCap(LineCapRoundAnchor);
			break;
		case 7:
			m_pen->SetEndCap(LineCapDiamondAnchor);
			break;
		case 8:
			m_pen->SetEndCap(LineCapArrowAnchor);
			break;
		case 9:
			m_pen->SetEndCap(LineCapAnchorMask);
			break;
		case 10:
			m_pen->SetEndCap(LineCapCustom);
			break;
		}
    }
    else{
        if (m_penColor == FCColor_None || m_penColor != dwPenColor){
            m_pen->SetColor(gdiColor);
            m_penColor = dwPenColor;
        }
		if(m_opacity != 1){
			m_penColor = FCColor_None;
		}
        if (m_penWidth != width){
            m_pen->SetWidth((REAL)width);
            m_penWidth = width;
        }
        if (m_penStyle != style){
			if (style == 0){
				m_pen->SetDashStyle(DashStyleSolid);
			}
			else if (style == 1){
				m_pen->SetDashStyle(DashStyleDash);
			}
			else if (style == 2){
				m_pen->SetDashStyle(DashStyleDot);
			}
            m_penStyle = style;
        }
    }
    return m_pen;
}

GraphicsPath* GdiPlusPaintEx::getRoundRectPath(Rect gdiPlusRect, int cornerRadius){
    GraphicsPath *gdiPlusPath = new GraphicsPath;
    gdiPlusPath->AddArc(gdiPlusRect.X, gdiPlusRect.Y, cornerRadius * 2, cornerRadius * 2, 180, 90);
	gdiPlusPath->AddLine(gdiPlusRect.X + cornerRadius, gdiPlusRect.Y, gdiPlusRect.GetRight() - cornerRadius * 2, gdiPlusRect.Y);
    gdiPlusPath->AddArc(gdiPlusRect.X + gdiPlusRect.Width - cornerRadius * 2, gdiPlusRect.Y, cornerRadius * 2, cornerRadius * 2, 270, 90);
	gdiPlusPath->AddLine(gdiPlusRect.GetRight(), gdiPlusRect.Y + cornerRadius * 2, gdiPlusRect.GetRight(), gdiPlusRect.Y + gdiPlusRect.Height - cornerRadius * 2);
    gdiPlusPath->AddArc(gdiPlusRect.X + gdiPlusRect.Width - cornerRadius * 2, gdiPlusRect.Y + gdiPlusRect.Height - cornerRadius * 2, cornerRadius * 2, cornerRadius * 2, 0, 90);
	gdiPlusPath->AddLine(gdiPlusRect.GetRight() - cornerRadius * 2, gdiPlusRect.GetBottom(), gdiPlusRect.X + cornerRadius * 2, gdiPlusRect.GetBottom());
    gdiPlusPath->AddArc(gdiPlusRect.X, gdiPlusRect.GetBottom() - cornerRadius * 2, cornerRadius * 2, cornerRadius * 2, 90, 90);
    gdiPlusPath->AddLine(gdiPlusRect.X, gdiPlusRect.GetBottom() - cornerRadius * 2, gdiPlusRect.X, gdiPlusRect.Y + cornerRadius * 2);
    gdiPlusPath->CloseFigure();
    return gdiPlusPath;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

GdiPlusPaintEx::GdiPlusPaintEx(){
	m_bitmap = 0;
	m_brush = 0;
	m_brushColor = 0;
	m_emptyStringFormat = 0;
	m_endLineCap = 0;
	m_exportPath = L"";
	m_g = 0;
	m_hDC = 0;
	m_offsetX = 0;
	m_offsetY = 0;
	m_opacity = 1;
	m_path = 0;
	m_pen = 0;
	m_penColor = 0;
	m_penWidth = 0;
	m_penStyle = 0;
	m_pRect.left = 0;
	m_pRect.top = 0;
	m_pRect.right = 0;
	m_pRect.bottom = 0;
	m_resourcePath = L"";
	m_rotateAngle = 0;
	m_scaleFactorX = 0;
	m_scaleFactorY = 0;
	m_startLineCap = 0;
	m_startTime = 0;
	m_wRect.left = 0;
	m_wRect.top = 0;
	m_wRect.right = 0;
	m_wRect.bottom = 0;
	m_myColor = new MyColor;
	m_useCloud = false;
}

GdiPlusPaintEx::~GdiPlusPaintEx(){
	if(m_g){
		delete m_g;
		m_g = 0;
	}
	if(m_bitmap){
		delete m_bitmap;
		m_bitmap = 0;
	}
	clearCaches();
	if(m_myColor){
		delete m_myColor;
		m_myColor = 0;
	}
}

void GdiPlusPaintEx::addArc(const FCRect& rect, float startAngle, float sweepAngle){
    int rw = rect.right - rect.left - 1;
    if (rw < 1) rw = 1;
    int rh = rect.bottom - rect.top - 1;
    if (rh < 1) rh = 1;
    Rect gdiPlusRect(rect.left + m_offsetX, rect.top + m_offsetY, rw, rh);
    affectScaleFactor(&gdiPlusRect);
    m_path->AddArc(gdiPlusRect, startAngle, sweepAngle);
}

void GdiPlusPaintEx::addBezier(FCPoint *apt, int cpt){
	Point *points = new Point[cpt];
	for(int i = 0; i < cpt; i++){
		int x = apt[i].x + m_offsetX;
		int y = apt[i].y + m_offsetY;
		if (m_scaleFactorX != 1 || m_scaleFactorY != 1){
			x = (int)(m_scaleFactorX * x);
			y = (int)(m_scaleFactorY * y);
		}
		Point newPoint(x, y);
		points[i] = newPoint;
	}
    m_path->AddBezier(points[0], points[1], points[2], points[3]);
	delete[] points;
	points = 0;
}

void GdiPlusPaintEx::addCurve(FCPoint *apt, int cpt){
	Point *points = new Point[cpt];
	for(int i = 0; i < cpt; i++){
		int x = apt[i].x + m_offsetX;
		int y = apt[i].y + m_offsetY;
		if (m_scaleFactorX != 1 || m_scaleFactorY != 1){
			x = (int)(m_scaleFactorX * x);
			y = (int)(m_scaleFactorY * y);
		}
		Point newPoint(x, y);
		points[i] = newPoint;
	}
    m_path->AddCurve(points, cpt);
	delete[] points;
	points = 0;
}

void GdiPlusPaintEx::addEllipse(const FCRect& rect){
    int rw = rect.right - rect.left - 1;
    if (rw < 1) rw = 1;
    int rh = rect.bottom - rect.top - 1;
    if (rh < 1) rh = 1;
    Rect gdiPlusRect(rect.left + m_offsetX, rect.top + m_offsetY, rw, rh);
    affectScaleFactor(&gdiPlusRect);
    m_path->AddEllipse(gdiPlusRect);
}

void GdiPlusPaintEx::addLine(int x1, int y1, int x2, int y2){
    int lx1 = x1 + m_offsetX;
    int ly1 = y1 + m_offsetY;
    int lx2 = x2 + m_offsetX;
    int ly2 = y2 + m_offsetY;
    if (m_scaleFactorX != 1 || m_scaleFactorY != 1){
        lx1 = (int)(m_scaleFactorX * lx1);
        ly1 = (int)(m_scaleFactorY * ly1);
        lx2 = (int)(m_scaleFactorX * lx2);
        ly2 = (int)(m_scaleFactorY * ly2);
    }
    m_path->AddLine(lx1, ly1, lx2, ly2);
}

void GdiPlusPaintEx::addRect(const FCRect& rect){
    int rw = rect.right - rect.left - 1;
    if (rw < 1) rw = 1;
    int rh = rect.bottom - rect.top - 1;
    if (rh < 1) rh = 1;
	Rect gdiPlusRect(rect.left + m_offsetX, rect.top + m_offsetY, rw, rh);
    affectScaleFactor(&gdiPlusRect);
	m_path->AddRectangle(gdiPlusRect);
}

void GdiPlusPaintEx::addPie(const FCRect& rect, float startAngle, float sweepAngle){
    int rw = rect.right - rect.left - 1;
    if (rw < 1) rw = 1;
    int rh = rect.bottom - rect.top - 1;
    if (rh < 1) rh = 1;
	Rect gdiPlusRect(rect.left + m_offsetX, rect.top + m_offsetY, rw, rh);
    affectScaleFactor(&gdiPlusRect);
    m_path->AddPie(gdiPlusRect, startAngle, sweepAngle);
}

void GdiPlusPaintEx::addText(String strText, FCFont *font, const FCRect& rect, int width){
	if(!m_emptyStringFormat){
		m_emptyStringFormat = (StringFormat*)StringFormat::GenericTypographic();
		//m_emptyStringFormat->SetFormatFlags(::StringFormatFlagsMeasureTrailingSpaces);
    }
	if (m_scaleFactorX != 1 || m_scaleFactorY != 1){
		int strX = (int)(m_scaleFactorX * (rect.left + m_offsetX));
		int strY = (int)(m_scaleFactorY * (rect.top + m_offsetY));
		float fontSize = (float)(font->m_fontSize * (m_scaleFactorX + m_scaleFactorY) / 2);
		FCFont scaleFont(font->m_fontFamily, fontSize, font->m_bold, font->m_underline, font->m_italic);
		Gdiplus::Font *gdiFont = getFont(&scaleFont);
		FontFamily fontFamily;
		gdiFont->GetFamily(&fontFamily);
		if(width == -1){
			PointF gdiPlusPoint((REAL)strX, (REAL)strY);
			m_path->AddString(strText.c_str(), -1, &fontFamily, gdiFont->GetStyle(), gdiFont->GetSize(), gdiPlusPoint, m_emptyStringFormat);
		}else{
			RectF gdiRect(strX, strY, 
                    (float)((rect.right - rect.left) * m_scaleFactorX), 
                    (float)((rect.bottom - rect.top) * m_scaleFactorY));
			m_path->AddString(strText.c_str(), -1, &fontFamily, gdiFont->GetStyle(), gdiFont->GetSize(), gdiRect, m_emptyStringFormat);
		}
		delete gdiFont;
		gdiFont = 0;
	}
	else{
		Gdiplus::Font *gdiFont = getFont(font);
		FontFamily fontFamily;
		gdiFont->GetFamily(&fontFamily);
		if(width == -1){
			PointF gdiPlusPoint((REAL)(rect.left + m_offsetX), (REAL)(rect.top + m_offsetY));
			m_path->AddString(strText.c_str(), -1, &fontFamily, gdiFont->GetStyle(), gdiFont->GetSize(), gdiPlusPoint, m_emptyStringFormat);
		}else{
			RectF gdiRect((REAL)(rect.left + m_offsetX), (REAL)(rect.top + m_offsetY), (REAL)(rect.right - rect.left), (REAL)(rect.bottom - rect.top));
			m_path->AddString(strText.c_str(), -1, &fontFamily, gdiFont->GetStyle(), gdiFont->GetSize(), gdiRect, m_emptyStringFormat);
		}
		delete gdiFont;
		gdiFont = 0;
	}
}

void GdiPlusPaintEx::beginExport(const wstring& exportPath, const FCRect& rect){
	m_exportPath = exportPath;
    int imageW = rect.right - rect.left;
    int imageH = rect.bottom - rect.top;
    if (imageW == 0) imageW = 1;
    if (imageH == 0) imageH = 1;
	if(m_bitmap){
		delete m_bitmap;
	}
	if(m_g){
		delete m_g;
	}
    m_bitmap = new Bitmap(imageW, imageH);
	m_g = Graphics::FromImage(m_bitmap);
    m_opacity = 1;
    m_resourcePath = L"";
}

void GdiPlusPaintEx::beginPaint(HDC hDC, const FCRect& wRect, const FCRect& pRect){
	m_pRect = pRect;
	m_wRect = wRect;
	int width = m_wRect.right - m_wRect.left;
	int height = m_wRect.bottom - m_wRect.top;
	if(!m_bitmap || width > (int)m_bitmap->GetWidth() || height > (int)m_bitmap->GetHeight()){
		int oldWidth = 0, oldHeight = 0;
		if(m_bitmap){
			oldWidth = (int)m_bitmap->GetWidth();
			oldHeight = (int)m_bitmap->GetHeight();
			delete m_bitmap;
		}
		if(m_g){
			delete m_g;
		}
		m_bitmap = new Bitmap(max(width, oldWidth), max(height, oldHeight));
		m_g = Graphics::FromImage(m_bitmap);
	}
	m_g->SetSmoothingMode(SmoothingModeAntiAlias);
	m_g->SetTextRenderingHint(TextRenderingHintClearTypeGridFit);
	m_hDC = hDC;
	m_opacity = 1;
	m_resourcePath = L"";
	if(m_useCloud){
		//m_cloudInfos.clear();
		CloudInfo ci;
        ci.m_type = L"0";
        ci.m_param1 = wRect.right - wRect.left;
		DWORD time2 = ::GetTickCount();
        ci.m_param3 = (int)(time2 - m_startTime);
        ci.m_param2 = wRect.bottom - wRect.top;
        ci.m_font = L"";
        ci.m_lineWidth = 0;
        m_cloudInfos.push_back(ci);
	}
}

void GdiPlusPaintEx::beginPath(){
	m_path = new GraphicsPath;
}

void GdiPlusPaintEx::clearCaches(){
	if(m_brush){
		delete m_brush;
		m_brush = 0;
	}
	std::map<wstring, Bitmap*>::iterator sIter = m_images.begin(); 
	for(;sIter != m_images.end(); ++sIter){
		delete sIter->second;
	}
	m_images.clear();
	if(m_pen){
		delete m_pen;
		m_pen = 0;
	}
	if(m_path){
		delete m_path;
		m_path = 0;
	}
}

void GdiPlusPaintEx::clipPath(){
	m_g->SetClip(m_path);
}

void GdiPlusPaintEx::closeFigure(){
    m_path->CloseFigure();
}

void GdiPlusPaintEx::closePath(){
    delete m_path;
    m_path = 0;
}

void GdiPlusPaintEx::drawArc(Long dwPenColor, float width, int style, const FCRect& rect, float startAngle, float sweepAngle){
	if(dwPenColor == FCColor_None) return;
	int rw = rect.right - rect.left - 1;
    if (rw < 1) rw = 1;
    int rh = rect.bottom - rect.top - 1;
    if (rh < 1) rh = 1;
    Rect gdiPlusRect(rect.left + m_offsetX, rect.top + m_offsetY, rw, rh);
    affectScaleFactor(&gdiPlusRect);
	//m_g->SetSmoothingMode(SmoothingModeAntiAlias);
    m_g->DrawArc(getPen(dwPenColor, width, style), gdiPlusRect, startAngle, sweepAngle);
	//m_g->SetSmoothingMode(SmoothingModeNone);
}

void GdiPlusPaintEx::drawBezier(Long dwPenColor, float width, int style, FCPoint *apt, int cpt){
	if(dwPenColor == FCColor_None) return;
	Point *points = new Point[cpt];
	for(int i = 0; i < cpt; i++){
		int x = apt[i].x + m_offsetX;
		int y = apt[i].y + m_offsetY;
		if (m_scaleFactorX != 1 || m_scaleFactorY != 1){
			x = (int)(m_scaleFactorX * x);
			y = (int)(m_scaleFactorY * y);
		}
		Point newPoint(x, y);
		points[i] = newPoint;
	}
	//m_g->SetSmoothingMode(SmoothingModeAntiAlias);
    m_g->DrawBezier(getPen(dwPenColor, width, style), points[0], points[1], points[2], points[3]);
	//m_g->SetSmoothingMode(SmoothingModeNone);
	delete[] points;
	points = 0;
}

void GdiPlusPaintEx::drawCurve(Long dwPenColor, float width, int style, FCPoint *apt, int cpt){
	if(dwPenColor == FCColor_None) return;
	Point *points = new Point[cpt];
	for(int i = 0; i < cpt; i++){
		int x = apt[i].x + m_offsetX;
		int y = apt[i].y + m_offsetY;
		if (m_scaleFactorX != 1 || m_scaleFactorY != 1){
			x = (int)(m_scaleFactorX * x);
			y = (int)(m_scaleFactorY * y);
		}
		Point newPoint(x, y);
		points[i] = newPoint;
	}
	//m_g->SetSmoothingMode(SmoothingModeAntiAlias);
    m_g->DrawCurve(getPen(dwPenColor, width, style), points, cpt);
	//m_g->SetSmoothingMode(SmoothingModeNone);
	delete[] points;
	points = 0;
}

void GdiPlusPaintEx::drawEllipse(Long dwPenColor, float width, int style, const FCRect& rect){
	if(dwPenColor == FCColor_None) return;
	int rw = rect.right - rect.left - 1;
	if(rw < 1) rw = 1;
	int rh = rect.bottom - rect.top - 1;
	if(rh < 1) rh = 1;
    Rect gdiPlusRect(rect.left + m_offsetX, rect.top + m_offsetY, rw, rh);
	affectScaleFactor(&gdiPlusRect);
	//m_g->SetSmoothingMode(SmoothingModeAntiAlias);
    m_g->DrawEllipse(getPen(dwPenColor, width, style), gdiPlusRect);
	//m_g->SetSmoothingMode(SmoothingModeNone);

	if (m_useCloud)
    {
        CloudInfo ci;
        ci.m_type = L"6";
        Color color = getGdiPlusColor(dwPenColor);
		ci.m_color = FCTran::colorToStr(FCColor::rgba(color.GetR(), color.GetG(), color.GetB(), color.GetA()));
		ci.m_param1 = gdiPlusRect.GetLeft();
		ci.m_param2 = gdiPlusRect.GetTop();
		ci.m_param3 = gdiPlusRect.GetRight();
		ci.m_param4 = gdiPlusRect.GetBottom();
        ci.m_lineWidth = width;
        m_cloudInfos.push_back(ci);
    }
}

void GdiPlusPaintEx::drawDotLine(Long dwPenColor, const FCPoint& p1, const FCPoint& p2){
	drawDotLine(dwPenColor, p1.x, p1.y, p2.x, p2.y);
}

void GdiPlusPaintEx::drawDotLine(Long dwPenColor, int x1, int y1, int x2, int y2){
	if(dwPenColor == FCColor_None) return;
	int lx1 = x1 + m_offsetX;
    int ly1 = y1 + m_offsetY;
    int lx2 = x2 + m_offsetX;
    int ly2 = y2 + m_offsetY;
    if (m_scaleFactorX != 1 || m_scaleFactorY != 1){
        lx1 = (int)(m_scaleFactorX * (x1 + m_offsetX));
        ly1 = (int)(m_scaleFactorY * (y1 + m_offsetY));
        lx2 = (int)(m_scaleFactorX * (x2 + m_offsetX));
        ly2 = (int)(m_scaleFactorY * (y2 + m_offsetY));
    }
	SolidBrush *brush = getBrush(dwPenColor);
	//m_g->SetSmoothingMode(SmoothingModeNone);
	vector<Rect> vecRect;
	int x = lx1, y = ly1;
	if(x == lx2){
		while(y < ly2){
			Rect rect(x, y, 1, 1);
			vecRect.push_back(rect);
			y += 6;
		}
	}
	else if(y == ly2){
		while(x < lx2){
			Rect rect(x, y, 1, 1);
			vecRect.push_back(rect);
			x += 6;
		}
	}
	int recSize = (int)vecRect.size();
	if(recSize > 0){
		Rect* rects = new Rect[recSize];
		for(int i = 0; i < recSize; i++){
			rects[i] = vecRect[i];
		}
		m_g->FillRectangles(brush, rects, recSize);
		delete [] rects;
		rects = 0;
	}
	vecRect.clear();
}

void GdiPlusPaintEx::drawEllipse(Long dwPenColor, float width, int style, int left, int top, int right, int bottom){
	FCRect rect = {left, top, right, bottom};
    drawEllipse(dwPenColor, width, style, rect);
}

void GdiPlusPaintEx::drawImage(String imagePath, const FCRect& rect){
	//m_g->SetSmoothingMode(SmoothingModeNone);
	wstring imageKey = m_resourcePath + imagePath;
    Bitmap *drawImage = 0;
	int rw = rect.right - rect.left;
	if(rw < 1) rw = 1;
	int rh = rect.bottom - rect.top;
	if(rh < 1) rh = 1;
    Rect gdiPlusRect(rect.left + m_offsetX, rect.top + m_offsetY, rw, rh);
    if (m_images.find(imageKey) != m_images.end()){
        drawImage = m_images[imageKey];
    }
    else{
        wstring attributes[5];
		attributes[0] = L"file";
		attributes[1] = L"corner";
		attributes[2] = L"source";
		attributes[3] = L"highcolor";
		attributes[4] = L"lowcolor";
		wstring values[5];
		values[0] = imagePath;
		values[1] = L"";
		values[2] = L"";
		values[3] = L"";
		values[4] = L"";
		wstring wPath = imagePath;
		if ((int)wPath.find(L"=") >= 0){
			for (int i = 0; i < 5; i++){
				wstring attribute = attributes[i];
				int alength = (int)attribute.length() + 2;
				int pos = (int)wPath.find(attribute + L"=\'");
				if (pos >= 0){
					int rpos = (int)wPath.find(L"\'", pos + alength);
					values[i] = wPath.substr(pos + alength, rpos - pos - alength);
				}
			}
		}
		wstring file = values[0];
		string strFile = FCTran::StringTostring(file);
		if(_access(strFile.c_str(), 0) == -1){
			if(m_resourcePath.length() > 0){
				if((int)m_resourcePath.find(L"\\") == (int)m_resourcePath.length() - 1){
					file = m_resourcePath + file;
				}
				else{
					file = m_resourcePath + L"\\" + file;
				}
			}
		}
		Bitmap *image = 0;
		if(values[2].length() > 0){
			int source[4];
			ArrayList<wstring> strs = FCTran::split(values[2], L",");
			int size = (int)strs.size();
			for (int i = 0; i < size; i++){
				int pos = FCTran::strToInt(strs.get(i).c_str());
				source[i] = pos;
			}
			Rect gdiPlusSourceRect(source[0], source[1], source[2] - source[0], source[3] - source[1]);
			Bitmap *sourceImage = (Bitmap*)Bitmap::FromFile(file.c_str());
			if (sourceImage){
				image = new Bitmap(gdiPlusSourceRect.Width, gdiPlusSourceRect.Height);
				Graphics *sg = Graphics::FromImage(image);
				sg->SetSmoothingMode(SmoothingModeAntiAlias);
				Rect srcRect(0, 0, gdiPlusSourceRect.Width, gdiPlusSourceRect.Height);
				sg->DrawImage(sourceImage, srcRect, gdiPlusSourceRect.GetLeft(), gdiPlusSourceRect.GetTop(), gdiPlusSourceRect.Width, gdiPlusSourceRect.Height, UnitPixel);
				delete sg;
				delete sourceImage;
			}
		}
		else{
			image = (Bitmap*)Bitmap::FromFile(file.c_str());
		}
		if(image){
			Gdiplus::ImageAttributes imageAttr;
			Long highColor = FCColor_None, lowColor = FCColor_None;
            if (values[3].length() != 0 && values[4].length() != 0){
				highColor = FCTran::strToColor(values[3]);
				lowColor = FCTran::strToColor(values[4]);
            }
            if (highColor != FCColor_None && lowColor != FCColor_None){
				int A = 0, R = 0, G = 0, B = 0;
				FCColor::toRgba(this, highColor, &R, &G, &B, &A);
                Color gdiPlusHighColor((BYTE)A, (BYTE)R, (BYTE)G, (BYTE)B);
                FCColor::toRgba(this, highColor, &R, &G, &B, &A);
                Color gdiPlusLowColor((BYTE)A, (BYTE)R, (BYTE)G, (BYTE)B);
                imageAttr.SetColorKey(gdiPlusLowColor, gdiPlusHighColor);
            }
			int iw = image->GetWidth();
			int ih = image->GetHeight();
			drawImage = new Bitmap(iw, ih);
			Graphics *g = Graphics::FromImage(drawImage);
			g->SetSmoothingMode(SmoothingModeAntiAlias);
			if (values[1].length() == 0){
				Rect drawImageRect(0, 0, iw, ih);
				g->DrawImage(image, drawImageRect, 0, 0, iw, ih, UnitPixel, &imageAttr);
			}
			else{
				int corners[4];
				ArrayList<wstring> strs = FCTran::split(values[1], L",");
				int size = (int)strs.size();
				for (int i = 0; i < size; i++){
					int corner = FCTran::strToInt(strs.get(i).c_str());
					corners[i] = corner;
				}
				int left = 0;
				int top = 0;
				int right = iw;
				int bottom = ih;
				if (corners[0] > 0){
					Rect destRect(left, top, corners[0], ih);
					g->DrawImage(image, destRect, 0, 0, corners[0], ih, UnitPixel, &imageAttr);
				}
				if (corners[1] > 0){
					Rect destRect(left, top, iw, corners[1]);
					g->DrawImage(image, destRect, 0, 0, iw, corners[1], UnitPixel, &imageAttr);
				}
				if (corners[2] > 0){
					Rect destRect(right - corners[2], top, corners[2], ih);
					g->DrawImage(image, destRect, iw - corners[2], 0, corners[2], ih, UnitPixel, &imageAttr);
				}
				if (corners[3] > 0){
					Rect destRect(left, bottom - corners[3], iw, corners[3]);
					g->DrawImage(image, destRect, 0, ih - corners[3], iw, corners[3], UnitPixel, &imageAttr);
				}
				int cwdest = iw - corners[0] - corners[2];
				int chdest = ih - corners[1] - corners[3];
				int cwsrc = iw - corners[0] - corners[2];
				int chsrc = ih - corners[1] - corners[3];
				if (cwdest > 0 && chdest > 0 && cwsrc > 0 && chsrc > 0){
					Rect destRect(left + corners[0], top + corners[1], cwdest, chdest);
					g->DrawImage(image, destRect, corners[0], corners[1], cwsrc, chsrc, UnitPixel, &imageAttr);
				}
			}
			delete image;
			delete g;
			m_images[imageKey] = drawImage;
		}
	}
	if(drawImage){
		affectScaleFactor(&gdiPlusRect);
		InterpolationMode oldMode = m_g->GetInterpolationMode();
        CompositingQuality oldQuality = m_g->GetCompositingQuality();
        m_g->SetInterpolationMode(InterpolationModeHighQualityBicubic);//高质量
		if(m_opacity < 1){
			Gdiplus::ColorMatrix colorMatrix = {
				 1, 0, 0, 0, 0,
				 0, 1, 0, 0, 0,
				 0, 0, 1, 0, 0,
				 0, 0, 0, m_opacity, 0,
				 0, 0, 0, 0, 1
			};
			Gdiplus::ImageAttributes imageAtt;
			imageAtt.SetColorMatrix(&colorMatrix);
			m_g->DrawImage(drawImage, gdiPlusRect, 0, 0, drawImage->GetWidth(), drawImage->GetHeight(), UnitPixel, &imageAtt);
		}
		else{
			m_g->DrawImage(drawImage, gdiPlusRect, 0, 0, drawImage->GetWidth(), drawImage->GetHeight(), UnitPixel);
		}
		m_g->SetInterpolationMode(oldMode);//高质量
        m_g->SetCompositingQuality(oldQuality);
	}
}

void GdiPlusPaintEx::drawLine(Long dwPenColor, float width, int style, const FCPoint& x, const FCPoint& y){
	drawLine(dwPenColor, width, style, x.x, x.y, y.x, y.y);
}

void GdiPlusPaintEx::drawLine(Long dwPenColor, float width, int style, int x1, int y1, int x2, int y2){
	if(dwPenColor == FCColor_None) return;
	int lx1 = x1 + m_offsetX;
    int ly1 = y1 + m_offsetY;
    int lx2 = x2 + m_offsetX;
    int ly2 = y2 + m_offsetY;
    if (m_scaleFactorX != 1 || m_scaleFactorY != 1){
        lx1 = (int)(m_scaleFactorX * (x1 + m_offsetX));
        ly1 = (int)(m_scaleFactorY * (y1 + m_offsetY));
        lx2 = (int)(m_scaleFactorX * (x2 + m_offsetX));
        ly2 = (int)(m_scaleFactorY * (y2 + m_offsetY));
    }
	//m_g->SetSmoothingMode(SmoothingModeAntiAlias);
	m_g->DrawLine(getPen(dwPenColor, width, style), lx1, ly1, lx2, ly2);
	//m_g->SetSmoothingMode(SmoothingModeNone);
	if (m_useCloud) {
		CloudInfo ci;
		ci.m_type = L"1";
		Color color = getGdiPlusColor(dwPenColor);
		ci.m_color = FCTran::colorToStr(FCColor::rgba(color.GetR(), color.GetG(), color.GetB(), color.GetA()));
		ci.m_param1 = lx1;
		ci.m_param2 = ly1;
		ci.m_param3 = lx2;
		ci.m_param4 = ly2;
		ci.m_lineWidth = width;
		m_cloudInfos.push_back(ci);
	}
}

void GdiPlusPaintEx::drawPath(Long dwPenColor, float width, int style){
	if(dwPenColor == FCColor_None) return;
    m_g->DrawPath(getPen(dwPenColor, width, style), m_path);
}

void GdiPlusPaintEx::drawPie(Long dwPenColor, float width, int style, const FCRect& rect, float startAngle, float sweepAngle){
	int rw = rect.right - rect.left - 1;
    if (rw < 1) rw = 1;
    int rh = rect.bottom - rect.top - 1;
    if (rh < 1) rh = 1;
	Rect gdiPlusRect(rect.left + m_offsetX, rect.top + m_offsetY, rw, rh);
    affectScaleFactor(&gdiPlusRect);
	//m_g->SetSmoothingMode(SmoothingModeAntiAlias);
    m_g->DrawPie(getPen(dwPenColor, width, style), gdiPlusRect, startAngle, sweepAngle);
	//m_g->SetSmoothingMode(SmoothingModeNone);
}

void GdiPlusPaintEx::drawPolygon(Long dwPenColor, float width, int style, FCPoint *apt, int cpt){
	if(dwPenColor == FCColor_None) return;
	Point *points = new Point[cpt];
	for(int i = 0; i < cpt; i++){
		int x = apt[i].x + m_offsetX;
		int y = apt[i].y + m_offsetY;
		if (m_scaleFactorX != 1 || m_scaleFactorY != 1){
			x = (int)(m_scaleFactorX * x);
			y = (int)(m_scaleFactorY * y);
		}
		Point newPoint(x, y);
		points[i] = newPoint;
	}
	//m_g->SetSmoothingMode(SmoothingModeAntiAlias);
	m_g->DrawPolygon(getPen(dwPenColor, width, style), points, cpt);
	//m_g->SetSmoothingMode(SmoothingModeNone);
	delete[] points;
	points = 0;
}

void GdiPlusPaintEx::drawPolyline(Long dwPenColor, float width, int style, FCPoint *apt, int cpt){
	if(dwPenColor == FCColor_None) return;
	Point *points = new Point[cpt];
	int lx = 0, ly = 0;
	for(int i = 0; i < cpt; i++){
		int x = apt[i].x + m_offsetX;
		int y = apt[i].y + m_offsetY;
		if (m_scaleFactorX != 1 || m_scaleFactorY != 1){
			x = (int)(m_scaleFactorX * x);
			y = (int)(m_scaleFactorY * y);
		}
		Point newPoint(x, y);
		points[i] = newPoint;
		if (m_useCloud)
        {
            if (i > 0)
            {
                CloudInfo ci;
                ci.m_type = L"1";
                Color color = getGdiPlusColor(dwPenColor);
                ci.m_color = FCTran::colorToStr(FCColor::rgba(color.GetR(), color.GetG(), color.GetB(), color.GetA()));
                ci.m_param1 = x;
                ci.m_param2 = y;
                ci.m_param3 = lx;
                ci.m_param4 = ly;
                ci.m_lineWidth = width;
                m_cloudInfos.push_back(ci);
            }
            lx = x;
            ly = y;
        }
	}
	//m_g->SetSmoothingMode(SmoothingModeAntiAlias);
	m_g->DrawLines(getPen(dwPenColor, width, style), points, cpt);
	//m_g->SetSmoothingMode(SmoothingModeNone);
	delete[] points;
	points = 0;
}

void GdiPlusPaintEx::drawRect(Long dwPenColor, float width, int style, int left, int top, int right, int bottom){
	FCRect rect = {left, top, right, bottom};
    drawRect(dwPenColor, width, style, rect);
}

void GdiPlusPaintEx::drawRect(Long dwPenColor, float width, int style, const FCRect& rect){
	if(dwPenColor == FCColor_None) return;
	int rw = rect.right - rect.left - 1;
	if(rw < 1) rw = 1;
	int rh = rect.bottom - rect.top - 1;
	if(rh < 1) rh = 1;
	Rect gdiPlusRect(rect.left + m_offsetX, rect.top + m_offsetY, rw, rh);
	affectScaleFactor(&gdiPlusRect);
	//m_g->SetSmoothingMode(SmoothingModeNone);
    m_g->DrawRectangle(getPen(dwPenColor, width, style), gdiPlusRect);

	if (m_useCloud) {
		CloudInfo ci;
        ci.m_type = L"2";
        Color color = getGdiPlusColor(dwPenColor);
		ci.m_color = FCTran::colorToStr(FCColor::rgba(color.GetR(), color.GetG(), color.GetB(), color.GetA()));
		ci.m_param1 = gdiPlusRect.GetLeft();
		ci.m_param2 = gdiPlusRect.GetTop();
		ci.m_param3 = gdiPlusRect.GetRight();
		ci.m_param4 = gdiPlusRect.GetBottom();
        ci.m_lineWidth = width;
        m_cloudInfos.push_back(ci);
	}
}

void GdiPlusPaintEx::drawRoundRect(Long dwPenColor, float width, int style, const FCRect& rect, int cornerRadius){
	if(dwPenColor == FCColor_None) return;
	int rw = rect.right - rect.left - 1;
	if(rw < 1) rw = 1;
	int rh = rect.bottom - rect.top - 1;
	if(rh < 1) rh = 1;
	Rect gdiPlusRect(rect.left + m_offsetX, rect.top + m_offsetY, rw, rh);
	affectScaleFactor(&gdiPlusRect);
	if(cornerRadius != 0){
		GraphicsPath *gdiPlusPath = getRoundRectPath(gdiPlusRect, (int)(cornerRadius * min(m_scaleFactorX, m_scaleFactorY)));
		//m_g->SetSmoothingMode(SmoothingModeAntiAlias);
		m_g->DrawPath(getPen(dwPenColor, width, style), gdiPlusPath);
		//m_g->SetSmoothingMode(SmoothingModeNone);
		delete gdiPlusPath;
	}
	else{
		//m_g->SetSmoothingMode(SmoothingModeNone);
		m_g->DrawRectangle(getPen(dwPenColor, width, style), gdiPlusRect);
	}
	if (m_useCloud) {
		CloudInfo ci;
        ci.m_type = L"2";
        Color color = getGdiPlusColor(dwPenColor);
		ci.m_color = FCTran::colorToStr(FCColor::rgba(color.GetR(), color.GetG(), color.GetB(), color.GetA()));
		ci.m_param1 = gdiPlusRect.GetLeft();
		ci.m_param2 = gdiPlusRect.GetTop();
		ci.m_param3 = gdiPlusRect.GetRight();
		ci.m_param4 = gdiPlusRect.GetBottom();
        ci.m_lineWidth = width;
        m_cloudInfos.push_back(ci);
	}
}

void GdiPlusPaintEx::drawText(String strText, Long dwPenColor, FCFont *font, const FCRect& rect, int width){
	if(dwPenColor == FCColor_None) return;
	//m_g->SetSmoothingMode(SmoothingModeNone);
	if(!m_emptyStringFormat){
		m_emptyStringFormat = (StringFormat*)StringFormat::GenericTypographic();
		//m_emptyStringFormat->SetFormatFlags(::StringFormatFlagsMeasureTrailingSpaces);
    }
	if (m_scaleFactorX != 1 || m_scaleFactorY != 1){
		int strX = (int)(m_scaleFactorX * (rect.left + m_offsetX));
		int strY = (int)(m_scaleFactorY * (rect.top + m_offsetY));
		float fontSize = (float)(font->m_fontSize * (m_scaleFactorX + m_scaleFactorY) / 2);
		FCFont scaleFont(font->m_fontFamily, fontSize, font->m_bold, font->m_underline, font->m_italic);
		Gdiplus::Font *gdiFont = getFont(&scaleFont);
		if(width == -1){
			PointF gdiPlusPoint((REAL)strX, (REAL)strY);
			m_g->DrawString(strText.c_str(), -1, gdiFont, gdiPlusPoint, m_emptyStringFormat, getBrush(dwPenColor));
		}else{
			RectF gdiRect(strX, strY, 
                        (float)((rect.right - rect.left) * m_scaleFactorX), 
                        (float)((rect.bottom - rect.top) * m_scaleFactorY));
			m_g->DrawString(strText.c_str(), -1, gdiFont, gdiRect, m_emptyStringFormat, getBrush(dwPenColor));
		}
		delete gdiFont;
		gdiFont = 0;
	}
	else{
		Gdiplus::Font *gdiFont = getFont(font);
		if(width == -1){
			PointF gdiPlusPoint((REAL)(rect.left + m_offsetX), (REAL)(rect.top + m_offsetY));
			m_g->DrawString(strText.c_str(), -1, gdiFont, gdiPlusPoint, m_emptyStringFormat, getBrush(dwPenColor));

			if (m_useCloud)
            {
                CloudInfo ci;
                ci.m_type = L"4";
                Color color = getGdiPlusColor(dwPenColor);
                ci.m_color = FCTran::colorToStr(FCColor::rgba(color.GetR(), color.GetG(), color.GetB(), color.GetA()));
                ci.m_param1 = gdiPlusPoint.X;
                ci.m_str = strText;
                ci.m_param2 = gdiPlusPoint.Y;
				ci.m_font = FCTran::fontToStr(font);
                ci.m_lineWidth = 1;
                m_cloudInfos.push_back(ci);
            }
		}else{
			RectF gdiRect((REAL)(rect.left + m_offsetX), (REAL)(rect.top + m_offsetY), (REAL)(rect.right - rect.left), (REAL)(rect.bottom - rect.top));
			m_g->DrawString(strText.c_str(), -1, gdiFont, gdiRect, m_emptyStringFormat, getBrush(dwPenColor));
		}
		delete gdiFont;
		gdiFont = 0;
	}
}

void GdiPlusPaintEx::drawTextEx(String strText, Long dwPenColor, FCFont *font, const FCRect& rect, int width){
	if(dwPenColor == FCColor_None) return;
	if(!m_emptyStringFormat){
		m_emptyStringFormat = (StringFormat*)StringFormat::GenericTypographic();
		//m_emptyStringFormat->SetFormatFlags(::StringFormatFlagsMeasureTrailingSpaces);
    }
	if (m_scaleFactorX != 1 || m_scaleFactorY != 1){
		int strX = (int)(m_scaleFactorX * (rect.left + m_offsetX));
		int strY = (int)(m_scaleFactorY * (rect.top + m_offsetY));
		PointF gdiPlusPoint((REAL)strX, (REAL)strY);
		float fontSize = (float)(font->m_fontSize * (m_scaleFactorX + m_scaleFactorY) / 2);
		FCFont scaleFont(font->m_fontFamily, fontSize, font->m_bold, font->m_underline, font->m_italic);
		Gdiplus::Font *gdiFont = getFont(&scaleFont);
		GraphicsState state = m_g->Save();
		m_g->TranslateTransform((REAL)gdiPlusPoint.X, (REAL)(gdiPlusPoint.Y + (int)(m_scaleFactorX * 1.8 * (rect.bottom - rect.top))));
		m_g->RotateTransform((REAL)3);
		m_g->ScaleTransform((REAL)1, (REAL)-1);
		Long color = getColor(dwPenColor);
		int a = 0, r = 0, g = 0, b = 0;
		FCColor::toRgba(0, color, &r, &g, &b, &a);
		PointF bkPoint((REAL)0, (REAL)0);
		m_g->DrawString(strText.c_str(), -1, gdiFont, bkPoint, m_emptyStringFormat, getBrush(FCColor::rgba(r, g, b, (int)(a * 0.2))));
		m_g->Restore(state);
		m_g->DrawString(strText.c_str(), -1, gdiFont, gdiPlusPoint, m_emptyStringFormat, getBrush(dwPenColor));
		delete gdiFont;
		gdiFont = 0;
	}
	else{
		PointF gdiPlusPoint((REAL)(rect.left + m_offsetX), (REAL)(rect.top + m_offsetY));
		Gdiplus::Font *gdiFont = getFont(font);
		GraphicsState state = m_g->Save();
		m_g->TranslateTransform((REAL)gdiPlusPoint.X, (REAL)(gdiPlusPoint.Y + 1.8 * (rect.bottom - rect.top)));
		m_g->RotateTransform((REAL)3);
		m_g->ScaleTransform((REAL)1, (REAL)-1);
		Long color = getColor(dwPenColor);
		int a = 0, r = 0, g = 0, b = 0;
		FCColor::toRgba(0, color, &r, &g, &b, &a);
		PointF bkPoint((REAL)0, (REAL)0);
		m_g->DrawString(strText.c_str(), -1, gdiFont, bkPoint, m_emptyStringFormat, getBrush(FCColor::rgba(r, g, b, (int)(a * 0.2))));
		m_g->Restore(state);
		m_g->DrawString(strText.c_str(), -1, gdiFont, gdiPlusPoint, m_emptyStringFormat, getBrush(dwPenColor));

		if (m_useCloud)
        {
            CloudInfo ci;
            ci.m_type = L"4";
            Color color = getGdiPlusColor(dwPenColor);
            ci.m_color = FCTran::colorToStr(FCColor::rgba(color.GetR(), color.GetG(), color.GetB(), color.GetA()));
            ci.m_param1 = gdiPlusPoint.X;
            ci.m_str = strText;
            ci.m_param2 = gdiPlusPoint.Y;
			ci.m_font = FCTran::fontToStr(font);
            ci.m_lineWidth = 1;
            m_cloudInfos.push_back(ci);
        }
		delete gdiFont;
		gdiFont = 0;
	}
}

void GdiPlusPaintEx::drawText(String strText, Long dwPenColor, FCFont *font, const FCRectF& rect, int width){
	if(dwPenColor == FCColor_None) return;
	//m_g->SetSmoothingMode(SmoothingModeNone);
	if(!m_emptyStringFormat){
		m_emptyStringFormat = (StringFormat*)StringFormat::GenericTypographic();
		//m_emptyStringFormat->SetFormatFlags(::StringFormatFlagsMeasureTrailingSpaces);
    }
	if (m_scaleFactorX != 1 || m_scaleFactorY != 1){
		float strX = (float)(m_scaleFactorX * (rect.left + m_offsetX));
		float strY = (float)(m_scaleFactorY * (rect.top + m_offsetY));
		float fontSize = (float)(font->m_fontSize * (m_scaleFactorX + m_scaleFactorY) / 2);
		FCFont scaleFont(font->m_fontFamily, fontSize, font->m_bold, font->m_underline, font->m_italic);
		Gdiplus::Font *gdiFont = getFont(&scaleFont);
		if(width == -1){
			PointF gdiPlusPoint((REAL)strX, (REAL)strY);
			m_g->DrawString(strText.c_str(), -1, gdiFont, gdiPlusPoint, m_emptyStringFormat, getBrush(dwPenColor));
		}else{
			RectF gdiRect(strX, strY, 
                        (float)((rect.right - rect.left) * m_scaleFactorX), 
                        (float)((rect.bottom - rect.top) * m_scaleFactorY));
			m_g->DrawString(strText.c_str(), -1, gdiFont, gdiRect, m_emptyStringFormat, getBrush(dwPenColor));
		}
		delete gdiFont;
		gdiFont = 0;
	}
	else{
		Gdiplus::Font *gdiFont = getFont(font);
		if(width == -1){
			PointF gdiPlusPoint((REAL)(rect.left + m_offsetX), (REAL)(rect.top + m_offsetY));
			m_g->DrawString(strText.c_str(), -1, gdiFont, gdiPlusPoint, m_emptyStringFormat, getBrush(dwPenColor));

			if (m_useCloud)
            {
                CloudInfo ci;
                ci.m_type = L"4";
                Color color = getGdiPlusColor(dwPenColor);
                ci.m_color = FCTran::colorToStr(FCColor::rgba(color.GetR(), color.GetG(), color.GetB(), color.GetA()));
                ci.m_param1 = gdiPlusPoint.X;
                ci.m_str = strText;
                ci.m_param2 = gdiPlusPoint.Y;
				ci.m_font = FCTran::fontToStr(font);
                ci.m_lineWidth = 1;
                m_cloudInfos.push_back(ci);
            }
		}else{
			RectF gdiRect((REAL)(rect.left + m_offsetX), (REAL)(rect.top + m_offsetY), (REAL)(rect.right - rect.left), (REAL)(rect.bottom - rect.top));
			m_g->DrawString(strText.c_str(), -1, gdiFont, gdiRect, m_emptyStringFormat, getBrush(dwPenColor));
		}
		delete gdiFont;
		gdiFont = 0;
	}
}

void GdiPlusPaintEx::drawTextAutoEllipsis(String strText, Long dwPenColor, FCFont *font, const FCRect& rect){
	if(dwPenColor == FCColor_None) return;
	//m_g->SetSmoothingMode(SmoothingModeNone);
	if(!m_emptyStringFormat){
		m_emptyStringFormat = (StringFormat*)StringFormat::GenericTypographic();
		//m_emptyStringFormat->SetFormatFlags(::StringFormatFlagsMeasureTrailingSpaces);
    }
	int rw = rect.right - rect.left - 1;
	if(rw < 1) rw = 1;
	int rh = rect.bottom - rect.top - 1;
	if(rh < 1) rh = 1;
	Rect gdiPlusRect(rect.left + m_offsetX, rect.top + m_offsetY, rw, rh);
	m_emptyStringFormat->SetTrimming(::StringTrimmingEllipsisCharacter);
	m_emptyStringFormat->SetFormatFlags(::StringFormatFlagsMeasureTrailingSpaces);
    if (m_scaleFactorX != 1 || m_scaleFactorY != 1){
        affectScaleFactor(&gdiPlusRect);
		float fontSize = (float)(font->m_fontSize * (m_scaleFactorX + m_scaleFactorY) / 2);
		FCFont scaleFont(font->m_fontFamily, fontSize, font->m_bold, font->m_underline, font->m_italic);
		Gdiplus::Font *gdiFont = getFont(&scaleFont);
		RectF fRect((REAL)gdiPlusRect.X, (REAL)gdiPlusRect.Y, (REAL)gdiPlusRect.Width, (REAL)gdiPlusRect.Height);
		m_g->DrawString(strText.c_str(), -1, gdiFont, fRect, m_emptyStringFormat, getBrush(dwPenColor));
		delete gdiFont;
		gdiFont = 0;
    }
    else{
		
		RectF fRect((REAL)gdiPlusRect.X, (REAL)gdiPlusRect.Y, (REAL)gdiPlusRect.Width, (REAL)gdiPlusRect.Height);
		Gdiplus::Font *gdiFont = getFont(font);
        m_g->DrawString(strText.c_str(), -1, gdiFont, fRect, m_emptyStringFormat, getBrush(dwPenColor));
		if (m_useCloud)
        {
            CloudInfo ci;
            ci.m_type = L"4";
            Color color = getGdiPlusColor(dwPenColor);
            ci.m_color = FCTran::colorToStr(FCColor::rgba(color.GetR(), color.GetG(), color.GetB(), color.GetA()));
            ci.m_param1 = fRect.GetLeft();
            ci.m_str = strText;
            ci.m_param2 = fRect.GetTop();
			ci.m_font = FCTran::fontToStr(font);
            ci.m_lineWidth = 1;
            m_cloudInfos.push_back(ci);
        }
		delete gdiFont;
		gdiFont = 0;
    }
	m_emptyStringFormat->SetFormatFlags(::StringFormatFlagsNoClip | ::StringFormatFlagsLineLimit | StringFormatFlagsNoFitBlackBox);
	m_emptyStringFormat->SetTrimming(::StringTrimmingNone);
}

void GdiPlusPaintEx::endExport(){
	if (m_bitmap){
		CLSID encoder;
		if (getEncoderClsid(L"image/jpeg", &encoder)){
			m_bitmap->Save(m_exportPath.c_str(), &encoder, 0);
		}
    }
    if (m_g){
        delete m_g;
        m_g = 0;
    }
    if (m_bitmap){
        delete m_bitmap;
        m_bitmap = 0;
    }
    m_offsetX = 0;
    m_offsetY = 0;
    m_opacity = 1;
    m_resourcePath = L"";
}

HBITMAP create_hbitmap_from_gdiplus_bitmap(Gdiplus::Bitmap *bitmap_ptr, Gdiplus::Rect rect){
	Gdiplus::Rect newRect(0, 0, bitmap_ptr->GetWidth(), bitmap_ptr->GetHeight());
	rect.Intersect(newRect);
	if(rect.Width > 0 && rect.Height > 0){
		BITMAP bm;
		Gdiplus::BitmapData bmpdata;
		HBITMAP hBitmap;
		if (bitmap_ptr->LockBits(&rect, Gdiplus::ImageLockModeRead, PixelFormat32bppPARGB, &bmpdata) != Gdiplus::Ok){
			return 0;
		}
		bm.bmType = 0;
		bm.bmWidth = bmpdata.Width;
		bm.bmHeight = bmpdata.Height;
		bm.bmWidthBytes = bmpdata.Stride;
		bm.bmPlanes = 1;
		bm.bmBitsPixel = 32;
		bm.bmBits = bmpdata.Scan0;
		hBitmap = CreateBitmapIndirect(&bm);
		bitmap_ptr->UnlockBits(&bmpdata);
		return hBitmap;
	}
	else{
	return 0;
	}
}

void GdiPlusPaintEx::endPaint(){
	Rect clipRect(m_pRect.left, m_pRect.top, m_pRect.right - m_pRect.left, m_pRect.bottom - m_pRect.top);
	affectScaleFactor(&clipRect);
	int width = m_wRect.right - m_wRect.left;
	int height = m_wRect.bottom - m_wRect.top;
	if(clipRect.Width < width || clipRect.Height < height){
		if(clipRect.X < m_wRect.left){
			clipRect.Width += clipRect.X;
			clipRect.X = m_wRect.left;
		}
		if(clipRect.Y < m_wRect.top){
			clipRect.Height += clipRect.Y;
			clipRect.Y = m_wRect.top;
		}
		if(clipRect.GetRight() > m_wRect.right){
			clipRect.Width -= abs(clipRect.GetRight() - m_wRect.right);
		}
		if(clipRect.GetBottom() > m_wRect.bottom){
			clipRect.Height -= abs(clipRect.GetBottom() - m_wRect.bottom);
		}
		if (clipRect.Width > 0 && clipRect.Height > 0){
		HBITMAP bitmap = create_hbitmap_from_gdiplus_bitmap(m_bitmap, clipRect);
		if(bitmap){
		HDC hdcsource = CreateCompatibleDC(m_hDC);
		SelectObject(hdcsource, bitmap);
		StretchBlt(m_hDC, clipRect.X, clipRect.Y, clipRect.Width, clipRect.Height, hdcsource, 0, 0, clipRect.Width, clipRect.Height, 13369376);
		DeleteObject(bitmap);
		DeleteObject(hdcsource);
		}
}
	}
	else{
if (clipRect.Width > 0 && clipRect.Height > 0){
		HBITMAP bitmap = create_hbitmap_from_gdiplus_bitmap(m_bitmap, clipRect);
		if(bitmap){
		HDC hdcsource = CreateCompatibleDC(m_hDC);
		SelectObject(hdcsource, bitmap);
		StretchBlt(m_hDC, clipRect.X, clipRect.Y, clipRect.Width, clipRect.Height, hdcsource, 0, 0, width, height, 13369376);
		DeleteObject(bitmap);
		DeleteObject(hdcsource);
		}
}
	}
	m_hDC = 0;
	m_offsetX = 0;
	m_offsetY = 0;
	m_opacity = 1;
	m_resourcePath = L"";
}

void GdiPlusPaintEx::excludeClipPath(){
	Gdiplus::Region region(m_path);
	m_g->ExcludeClip(&region);
}

void GdiPlusPaintEx::fillEllipse(Long dwPenColor, const FCRect& rect){
	if(dwPenColor == FCColor_None) return;
	Rect gdiPlusRect(rect.left + m_offsetX, rect.top + m_offsetY, rect.right - rect.left, rect.bottom - rect.top);
	affectScaleFactor(&gdiPlusRect);
	//m_g->SetSmoothingMode(SmoothingModeAntiAlias);
	m_g->FillEllipse(getBrush(dwPenColor), gdiPlusRect);
	//m_g->SetSmoothingMode(SmoothingModeNone);
	if (m_useCloud)
    {
        CloudInfo ci;
        ci.m_type = L"7";
        Color color = getGdiPlusColor(dwPenColor);
		ci.m_color = FCTran::colorToStr(FCColor::rgba(color.GetR(), color.GetG(), color.GetB(), color.GetA()));
		ci.m_param1 = gdiPlusRect.GetLeft();
		ci.m_param2 = gdiPlusRect.GetTop();
		ci.m_param3 = gdiPlusRect.GetRight();
		ci.m_param4 = gdiPlusRect.GetBottom();
        ci.m_lineWidth = 0;
        m_cloudInfos.push_back(ci);
    }
}

void GdiPlusPaintEx::fillGradientEllipse(Long dwFirst, Long dwSecond, const FCRect& rect, int angle){
	int rw = rect.right - rect.left - 1;
	if(rw < 1) rw = 1;
	int rh = rect.bottom - rect.top - 1;
	if(rh < 1) rh = 1;
	Rect gdiPlusRect(rect.left + m_offsetX, rect.top + m_offsetY, rw, rh);
	affectScaleFactor(&gdiPlusRect);
    LinearGradientBrush lgb(gdiPlusRect, getGdiPlusColor(dwFirst), getGdiPlusColor(dwSecond), (REAL)angle, true);
    //m_g->SetSmoothingMode(SmoothingModeAntiAlias);
	m_g->FillEllipse(&lgb, gdiPlusRect);
	//m_g->SetSmoothingMode(SmoothingModeNone);
	if (m_useCloud)
    {
        CloudInfo ci;
        ci.m_type = L"7";
        Color color = getGdiPlusColor(dwFirst);
		ci.m_color = FCTran::colorToStr(FCColor::rgba(color.GetR(), color.GetG(), color.GetB(), color.GetA()));
		ci.m_param1 = gdiPlusRect.GetLeft();
		ci.m_param2 = gdiPlusRect.GetTop();
		ci.m_param3 = gdiPlusRect.GetRight();
		ci.m_param4 = gdiPlusRect.GetBottom();
        ci.m_lineWidth = 0;
        m_cloudInfos.push_back(ci);
    }
}

void GdiPlusPaintEx::fillGradientPath(Long dwFirst, Long dwSecond, const FCRect& rect, int angle){
	int rw = rect.right - rect.left - 1;
	if(rw < 1) rw = 1;
	int rh = rect.bottom - rect.top - 1;
	if(rh < 1) rh = 1;
	Rect gdiPlusRect(rect.left + m_offsetX, rect.top + m_offsetY, rw, rh);
	affectScaleFactor(&gdiPlusRect);
    LinearGradientBrush lgb(gdiPlusRect, getGdiPlusColor(dwFirst), getGdiPlusColor(dwSecond), (REAL)angle, true);
	//m_g->SetSmoothingMode(SmoothingModeAntiAlias);       
	m_g->FillPath(&lgb, m_path);
	//m_g->SetSmoothingMode(SmoothingModeNone);
}

void GdiPlusPaintEx::fillGradientPolygon(Long dwFirst, Long dwSecond, FCPoint *apt, int cpt, int angle){
	int left = 0, top = 0, right = 0, bottom = 0;
	Point *points = new Point[cpt];
	for(int i = 0; i < cpt; i++){
		int x = apt[i].x + m_offsetX;
		int y = apt[i].y + m_offsetY;
		if (m_scaleFactorX != 1 || m_scaleFactorY != 1){
			x = (int)(m_scaleFactorX * x);
			y = (int)(m_scaleFactorY * y);
		}
		if (i == 0){
            left = x;
            top = y;
            right = x;
            bottom = y;
        }
        else{
            if (x < left){
                left = x;
            }
            if (y < top){
                top = y;
            }
            if (x > right){
                right = x;
            }
            if (y > bottom){
                bottom = y;
            }
        }
		Point newPoint(x, y);
		points[i] = newPoint;
	}
	Rect gdiPlusRect(left, top, right - left, bottom - top);
	if(gdiPlusRect.Height > 0){
		LinearGradientBrush lgb(gdiPlusRect, getGdiPlusColor(dwFirst), getGdiPlusColor(dwSecond), (REAL)angle, true);
		//m_g->SetSmoothingMode(SmoothingModeAntiAlias);
		m_g->FillPolygon(&lgb, points, cpt);
		//m_g->SetSmoothingMode(SmoothingModeNone);
	}
	delete[] points;
	points = 0;
}

void GdiPlusPaintEx::fillGradientRect(Long dwFirst, Long dwSecond, const FCRect& rect, int cornerRadius, int angle){
	int rw = rect.right - rect.left - 1;
	if(rw < 1) rw = 1;
	int rh = rect.bottom - rect.top - 1;
	if(rh < 1) rh = 1;
	Rect gdiPlusRect(rect.left + m_offsetX, rect.top + m_offsetY, rw, rh);
	affectScaleFactor(&gdiPlusRect);
    LinearGradientBrush lgb(gdiPlusRect, getGdiPlusColor(dwFirst), getGdiPlusColor(dwSecond), (REAL)angle, true);
	if(cornerRadius != 0){
		GraphicsPath *gdiPlusPath = getRoundRectPath(gdiPlusRect, (int)(cornerRadius * min(m_scaleFactorX, m_scaleFactorY)));
		//m_g->SetSmoothingMode(SmoothingModeAntiAlias);
		m_g->FillPath(&lgb, gdiPlusPath);
		//m_g->SetSmoothingMode(SmoothingModeNone);
		delete gdiPlusPath;
	}
	else{
		m_g->FillRectangle(&lgb, gdiPlusRect);
	}
	if (m_useCloud) {
		CloudInfo ci;
        ci.m_type = L"3";
        Color color = getGdiPlusColor(dwFirst);
		ci.m_color = FCTran::colorToStr(FCColor::rgba(color.GetR(), color.GetG(), color.GetB(), color.GetA()));
		ci.m_param1 = gdiPlusRect.GetLeft();
		ci.m_param2 = gdiPlusRect.GetTop();
		ci.m_param3 = gdiPlusRect.GetRight();
		ci.m_param4 = gdiPlusRect.GetBottom();
        ci.m_lineWidth = 0;
        m_cloudInfos.push_back(ci);
	}
}

void GdiPlusPaintEx::fillPath(Long dwPenColor){
	if(dwPenColor == FCColor_None) return;
	m_g->FillPath(getBrush(dwPenColor), m_path);
}

void GdiPlusPaintEx::fillPie(Long dwPenColor, const FCRect& rect, float startAngle, float sweepAngle){
	if(dwPenColor == FCColor_None) return;
	int rw = rect.right - rect.left - 1;
    if (rw < 1) rw = 1;
    int rh = rect.bottom - rect.top - 1;
    if (rh < 1) rh = 1;
	Rect gdiPlusRect(rect.left + m_offsetX, rect.top + m_offsetY, rw, rh);
    affectScaleFactor(&gdiPlusRect);
	//m_g->SetSmoothingMode(SmoothingModeAntiAlias);
    m_g->FillPie(getBrush(dwPenColor), gdiPlusRect, startAngle, sweepAngle);
	//m_g->SetSmoothingMode(SmoothingModeNone);
}

void GdiPlusPaintEx::fillPolygon(Long dwPenColor, FCPoint *apt, int cpt){
	if(dwPenColor == FCColor_None) return;
	Point *points = new Point[cpt];
	for(int i = 0; i < cpt; i++){
		int x = apt[i].x + m_offsetX;
		int y = apt[i].y + m_offsetY;
		if (m_scaleFactorX != 1 || m_scaleFactorY != 1){
			x = (int)(m_scaleFactorX * x);
			y = (int)(m_scaleFactorY * y);
		}
		Point newPoint(x, y);
		points[i] = newPoint;
	}
	//m_g->SetSmoothingMode(SmoothingModeAntiAlias);
	m_g->FillPolygon(getBrush(dwPenColor), points, cpt);
	//m_g->SetSmoothingMode(SmoothingModeNone);
	delete[] points;
	points = 0;
}

void GdiPlusPaintEx::fillRect(Long dwPenColor, const FCRect& rect){
	fillRect(dwPenColor, rect.left, rect.top, rect.right, rect.bottom);
}

void GdiPlusPaintEx::fillRect(Long dwPenColor, int left, int top, int right, int bottom){
	if(dwPenColor == FCColor_None) return;
	Rect gdiPlusRect(left + m_offsetX, top + m_offsetY, right - left, bottom - top);
	affectScaleFactor(&gdiPlusRect);
	//m_g->SetSmoothingMode(SmoothingModeNone);
	m_g->FillRectangle(getBrush(dwPenColor), gdiPlusRect);

	if (m_useCloud) {
		CloudInfo ci;
        ci.m_type = L"3";
        Color color = getGdiPlusColor(dwPenColor);
		ci.m_color = FCTran::colorToStr(FCColor::rgba(color.GetR(), color.GetG(), color.GetB(), color.GetA()));
		ci.m_param1 = gdiPlusRect.GetLeft();
		ci.m_param2 = gdiPlusRect.GetTop();
		ci.m_param3 = gdiPlusRect.GetRight();
		ci.m_param4 = gdiPlusRect.GetBottom();
        ci.m_lineWidth = 0;
        m_cloudInfos.push_back(ci);
	}
}

void GdiPlusPaintEx::fillRoundRect(Long dwPenColor, const FCRect& rect, int cornerRadius){
	if(dwPenColor == FCColor_None) return;
	Rect gdiPlusRect(rect.left + m_offsetX, rect.top + m_offsetY, rect.right - rect.left, rect.bottom - rect.top);
	affectScaleFactor(&gdiPlusRect);
	if(cornerRadius != 0){
		GraphicsPath *gdiPlusPath = getRoundRectPath(gdiPlusRect, (int)(cornerRadius * min(m_scaleFactorX, m_scaleFactorY)));
		//m_g->SetSmoothingMode(SmoothingModeAntiAlias);
		m_g->FillPath(getBrush(dwPenColor), gdiPlusPath);
		//m_g->SetSmoothingMode(SmoothingModeNone);
		delete gdiPlusPath;
	}
	else{
		m_g->SetSmoothingMode(SmoothingModeNone);
		m_g->FillRectangle(getBrush(dwPenColor), gdiPlusRect);
	}

	if (m_useCloud) {
		CloudInfo ci;
        ci.m_type = L"3";
        Color color = getGdiPlusColor(dwPenColor);
		ci.m_color = FCTran::colorToStr(FCColor::rgba(color.GetR(), color.GetG(), color.GetB(), color.GetA()));
		ci.m_param1 = gdiPlusRect.GetLeft();
		ci.m_param2 = gdiPlusRect.GetTop();
		ci.m_param3 = gdiPlusRect.GetRight();
		ci.m_param4 = gdiPlusRect.GetBottom();
        ci.m_lineWidth = 0;
        m_cloudInfos.push_back(ci);
	}
}

Long GdiPlusPaintEx::getColor(Long dwPenColor){
	return m_myColor->getUserColor(dwPenColor);
}

Long GdiPlusPaintEx::getPaintColor(Long dwPenColor){
	return getColor(dwPenColor);
}

FCPoint GdiPlusPaintEx::getOffset(){
	FCPoint offset = {m_offsetX, m_offsetY};
	return offset;
}

void GdiPlusPaintEx::getScaleFactor(double *scaleFactorX, double *scaleFactorY){
	*scaleFactorX = m_scaleFactorX;
	*scaleFactorY = m_scaleFactorY;
}

FCPoint GdiPlusPaintEx::rotate(const FCPoint& op, const FCPoint& mp, int angle){
    float PI = 3.14159265f;
	FCPoint pt = {0};
    pt.x = (int)((mp.x - op.x) * cos(angle * PI / 180) - (mp.y - op.y) * sin(angle * PI / 180) + op.x);
    pt.y = (int)((mp.x - op.x) * sin(angle * PI / 180) + (mp.y - op.y) * cos(angle * PI / 180) + op.y);
    return pt;
}

void GdiPlusPaintEx::setClip(const FCRect& rect){
	Rect gdiPlusRect(rect.left + m_offsetX, rect.top + m_offsetY, rect.right - rect.left, rect.bottom - rect.top);
	if (m_scaleFactorX != 1 || m_scaleFactorY != 1){
        gdiPlusRect.X = (int)floor(gdiPlusRect.X * m_scaleFactorX);
        gdiPlusRect.Y = (int)floor(gdiPlusRect.Y * m_scaleFactorY);
        gdiPlusRect.Width = (int)ceil(gdiPlusRect.Width * m_scaleFactorX);
        gdiPlusRect.Height = (int)ceil(gdiPlusRect.Height * m_scaleFactorY);
    }
	m_g->SetClip(gdiPlusRect);
	if (m_useCloud) {
		CloudInfo ci;
		ci.m_type = L"5";
		ci.m_param1 = gdiPlusRect.GetLeft();
		ci.m_param2 = gdiPlusRect.GetTop();
		ci.m_param3 = gdiPlusRect.GetRight();
		ci.m_param4 = gdiPlusRect.GetBottom();
		m_cloudInfos.push_back(ci);
	}
}

void GdiPlusPaintEx::setLineCap(int startLineCap, int endLineCap){
    m_startLineCap = startLineCap;
	m_endLineCap = endLineCap;
    if (m_pen){
		switch(m_startLineCap){
		case 0:
			m_pen->SetStartCap(LineCapFlat);
			break;
		case 1:
			m_pen->SetStartCap(LineCapSquare);
			break;
		case 2:
			m_pen->SetStartCap(LineCapRound);
			break;
		case 3:
			m_pen->SetStartCap(LineCapTriangle);
			break;
		case 4:
			m_pen->SetStartCap(LineCapNoAnchor);
			break;
		case 5:
			m_pen->SetStartCap(LineCapSquareAnchor);
			break;
		case 6:
			m_pen->SetStartCap(LineCapRoundAnchor);
			break;
		case 7:
			m_pen->SetStartCap(LineCapDiamondAnchor);
			break;
		case 8:
			m_pen->SetStartCap(LineCapArrowAnchor);
			break;
		case 9:
			m_pen->SetStartCap(LineCapAnchorMask);
			break;
		case 10:
			m_pen->SetStartCap(LineCapCustom);
			break;
		}
		switch(m_endLineCap){
		case 0:
			m_pen->SetEndCap(LineCapFlat);
			break;
		case 1:
			m_pen->SetEndCap(LineCapSquare);
			break;
		case 2:
			m_pen->SetEndCap(LineCapRound);
			break;
		case 3:
			m_pen->SetEndCap(LineCapTriangle);
			break;
		case 4:
			m_pen->SetEndCap(LineCapNoAnchor);
			break;
		case 5:
			m_pen->SetEndCap(LineCapSquareAnchor);
			break;
		case 6:
			m_pen->SetEndCap(LineCapRoundAnchor);
			break;
		case 7:
			m_pen->SetEndCap(LineCapDiamondAnchor);
			break;
		case 8:
			m_pen->SetEndCap(LineCapArrowAnchor);
			break;
		case 9:
			m_pen->SetEndCap(LineCapAnchorMask);
			break;
		case 10:
			m_pen->SetEndCap(LineCapCustom);
			break;
		}
    }
}

void GdiPlusPaintEx::setOffset(const FCPoint& offset){
	m_offsetX = offset.x;
	m_offsetY = offset.y;
}

void GdiPlusPaintEx::setOpacity(float opacity){
	if(m_opacity != opacity){
		m_opacity = opacity;
	    if (m_brush)
        {
            delete m_brush;
            m_brush = 0;
        }
        if (m_pen)
        {
            delete m_pen;
            m_pen = 0;
        }
	}
}

void GdiPlusPaintEx::setResourcePath(const wstring& resourcePath){
	m_resourcePath = resourcePath;
}

void GdiPlusPaintEx::setRotateAngle(int rotateAngle){
	m_rotateAngle = rotateAngle;
}

void GdiPlusPaintEx::setScaleFactor(double scaleFactorX, double scaleFactorY){
	m_scaleFactorX = scaleFactorX;
	m_scaleFactorY = scaleFactorY;
}

bool GdiPlusPaintEx::supportTransparent(){
	return true;
}

FCSize GdiPlusPaintEx::textSize(String strText, FCFont *font, int width){
	if(!m_emptyStringFormat){
		m_emptyStringFormat = (StringFormat*)StringFormat::GenericTypographic();
		////m_emptyStringFormat->SetFormatFlags(::StringFormatFlagsMeasureTrailingSpaces);
	}
	if(strText == L" "){
		m_emptyStringFormat->SetFormatFlags(::StringFormatFlagsMeasureTrailingSpaces);
	}
	SizeF gdiPlusSize;
	Gdiplus::Font *gdiFont = getFont(font);
	if(width == -1){
		SizeF layoutSize(0, 0);
		m_g->MeasureString(strText.c_str(), -1, gdiFont, layoutSize, m_emptyStringFormat, &gdiPlusSize);
	}else{
		SizeF layoutSize(width, 2100000000);
		m_g->MeasureString(strText.c_str(), -1, gdiFont, layoutSize, m_emptyStringFormat, &gdiPlusSize);
	}
	if(strText == L" "){
		m_emptyStringFormat->SetFormatFlags(::StringFormatFlagsNoClip | ::StringFormatFlagsLineLimit | StringFormatFlagsNoFitBlackBox);
	}
	FCSize size = {(long)gdiPlusSize.Width, (long)gdiPlusSize.Height};
	delete gdiFont;
	gdiFont = 0;
	return size;
}

FCSizeF GdiPlusPaintEx::textSizeF(String strText, FCFont *font, int width){
	if(!m_emptyStringFormat){
		m_emptyStringFormat = (StringFormat*)StringFormat::GenericTypographic();
		////m_emptyStringFormat->SetFormatFlags(::StringFormatFlagsMeasureTrailingSpaces);
	}
	if(strText == L" "){
		m_emptyStringFormat->SetFormatFlags(::StringFormatFlagsMeasureTrailingSpaces);
	}
	SizeF gdiPlusSize;
	Gdiplus::Font *gdiFont = getFont(font);
	if(width == -1){
		SizeF layoutSize(0, 0);
		m_g->MeasureString(strText.c_str(), -1, gdiFont, layoutSize, m_emptyStringFormat, &gdiPlusSize);
	}else{
		SizeF layoutSize(width, 2100000000);
		m_g->MeasureString(strText.c_str(), -1, gdiFont, layoutSize, m_emptyStringFormat, &gdiPlusSize);
	}
	if(strText == L" "){
			m_emptyStringFormat->SetFormatFlags(::StringFormatFlagsNoClip | ::StringFormatFlagsLineLimit | StringFormatFlagsNoFitBlackBox);
	}
	FCSizeF size = {gdiPlusSize.Width, gdiPlusSize.Height};
	delete gdiFont;
	gdiFont = 0;
	return size;
}