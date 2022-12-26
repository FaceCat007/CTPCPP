/*基于FaceCat(捂脸猫)框架 v1.0
 上海卷卷猫信息技术有限公司
 */

#ifndef __GDIPLUSPAINTEX_H__
#define __GDIPLUSPAINTEX_H__
#pragma once
#include "stdafx.h"

#define USERCOLOR (Long)-200000000100
#define USERCOLOR1  (Long)-200000000100
#define USERCOLOR2  (Long)-200000000101
#define USERCOLOR3  (Long)-200000000102
#define USERCOLOR4  (Long)-200000000103
#define USERCOLOR5  (Long)-200000000104
#define USERCOLOR6  (Long)-200000000105
#define USERCOLOR7  (Long)-200000000106
#define USERCOLOR8  (Long)-200000000107
#define USERCOLOR9  (Long)-200000000108
#define USERCOLOR10 (Long)-200000000109
#define USERCOLOR11 (Long)-200000000110
#define USERCOLOR12 (Long)-200000000111
#define USERCOLOR13 (Long)-200000000112
#define USERCOLOR14 (Long)-200000000113
#define USERCOLOR15 (Long)-200000000114
#define USERCOLOR16 (Long)-200000000115
#define USERCOLOR17 (Long)-200000000116
#define USERCOLOR18 (Long)-200000000117
#define USERCOLOR19 (Long)-200000000118
#define USERCOLOR20 (Long)-200000000119
#define USERCOLOR21 (Long)-200000000120
#define USERCOLOR22 (Long)-200000000121
#define USERCOLOR23 (Long)-200000000122
#define USERCOLOR24 (Long)-200000000123
#define USERCOLOR25 (Long)-200000000124
#define USERCOLOR26 (Long)-200000000125
#define USERCOLOR27 (Long)-200000000126
#define USERCOLOR28 (Long)-200000000127
#define USERCOLOR29 (Long)-200000000128
#define USERCOLOR30 (Long)-200000000129
#define USERCOLOR31 (Long)-200000000130
#define USERCOLOR32 (Long)-200000000131
#define USERCOLOR33 (Long)-200000000132
#define USERCOLOR34 (Long)-200000000133
#define USERCOLOR35 (Long)-200000000134
#define USERCOLOR36 (Long)-200000000135
#define USERCOLOR37 (Long)-200000000136
#define USERCOLOR38 (Long)-200000000137
#define USERCOLOR39 (Long)-200000000138
#define USERCOLOR40 (Long)-200000000139
#define USERCOLOR41 (Long)-200000000140
#define USERCOLOR42 (Long)-200000000141
#define USERCOLOR43 (Long)-200000000142
#define USERCOLOR44 (Long)-200000000143
#define USERCOLOR45 (Long)-200000000144
#define USERCOLOR46 (Long)-200000000145
#define USERCOLOR47 (Long)-200000000146
#define USERCOLOR48 (Long)-200000000147
#define USERCOLOR49 (Long)-200000000148
#define USERCOLOR50 (Long)-200000000149
#define USERCOLOR51 (Long)-200000000150
#define USERCOLOR52 (Long)-200000000151
#define USERCOLOR53 (Long)-200000000152
#define USERCOLOR54 (Long)-200000000153
#define USERCOLOR55 (Long)-200000000154
#define USERCOLOR56 (Long)-200000000155
#define USERCOLOR57 (Long)-200000000156
#define USERCOLOR58 (Long)-200000000157
#define USERCOLOR59 (Long)-200000000158
#define USERCOLOR60 (Long)-200000000159
#define USERCOLOR61 (Long)-200000000160
#define USERCOLOR62 (Long)-200000000161
#define USERCOLOR63 (Long)-200000000162
#define USERCOLOR64 (Long)-200000000163
#define USERCOLOR65 (Long)-200000000164
#define USERCOLOR66 (Long)-200000000165
#define USERCOLOR67 (Long)-200000000166
#define USERCOLOR68 (Long)-200000000167
#define USERCOLOR69 (Long)-200000000168
#define USERCOLOR70 (Long)-200000000169
#define USERCOLOR71 (Long)-200000000170
#define USERCOLOR72 (Long)-200000000171
#define USERCOLOR73 (Long)-200000000172
#define USERCOLOR74 (Long)-200000000173
#define USERCOLOR75 (Long)-200000000174
#define USERCOLOR76 (Long)-200000000175
#define USERCOLOR77 (Long)-200000000176
#define USERCOLOR78 (Long)-200000000177
#define USERCOLOR79 (Long)-200000000178
#define USERCOLOR80 (Long)-200000000179
#define USERCOLOR81 (Long)-200000000180
#define USERCOLOR82 (Long)-200000000181
#define USERCOLOR83 (Long)-200000000182
#define USERCOLOR84 (Long)-200000000183
#define USERCOLOR85 (Long)-200000000184
#define USERCOLOR86 (Long)-200000000185
#define USERCOLOR87 (Long)-200000000186
#define USERCOLOR88 (Long)-200000000187
#define USERCOLOR89 (Long)-200000000188
#define USERCOLOR90 (Long)-200000000189
#define USERCOLOR91 (Long)-200000000190
#define USERCOLOR92 (Long)-200000000191
#define USERCOLOR93 (Long)-200000000192
#define USERCOLOR94 (Long)-200000000193
#define USERCOLOR95 (Long)-200000000194
#define USERCOLOR96 (Long)-200000000195
#define USERCOLOR97 (Long)-200000000196
#define USERCOLOR98 (Long)-200000000197
#define USERCOLOR99 (Long)-200000000198
#define USERCOLOR100 (Long)-200000000199
#define USERCOLOR101 (Long)-200000000200
#define USERCOLOR102 (Long)-200000000201
#define USERCOLOR103 (Long)-200000000202
#define USERCOLOR104 (Long)-200000000203
#define USERCOLOR105 (Long)-200000000204
#define USERCOLOR106 (Long)-200000000205
#define USERCOLOR107 (Long)-200000000206
#define USERCOLOR108 (Long)-200000000207
#define USERCOLOR109 (Long)-200000000208
#define USERCOLOR110 (Long)-200000000209
#define USERCOLOR111 (Long)-200000000210
#define USERCOLOR112 (Long)-200000000211
#define USERCOLOR113 (Long)-200000000212
#define USERCOLOR114 (Long)-200000000213
#define USERCOLOR115 (Long)-200000000214
#define USERCOLOR116 (Long)-200000000215
#define USERCOLOR117 (Long)-200000000217

class MyColor{
public:
    MyColor();
    virtual ~MyColor();
    int m_lastStyle;
    HashMap<double, Long> m_userColors;
    static int getStyle();
    static void setStyle(int value);
    virtual void createColors();
    virtual Long getUserColor(Long color);
	static void setSystemFont(String value);
    static String getSystemFont();
};

class CloudInfo {
public:
    String m_type;
    String m_color;
    String m_font;
    float m_lineWidth;
    int m_param1;
    int m_param2;
    int m_param3;
    int m_param4;
    String m_str;
public:
	CloudInfo(){
		m_lineWidth = 1;
		m_param1 = 0;
		m_param2 = 0;
		m_param3 = 0;
		m_param4 = 0;
	}
};

class GdiPlusPaintEx : public FCPaint {
public:
	Bitmap *m_bitmap;
	SolidBrush *m_brush;
	Long m_brushColor;
	StringFormat *m_emptyStringFormat;
	int m_endLineCap;
	wstring m_exportPath;
	Graphics *m_g;
	HDC m_hDC;
	map<wstring, Bitmap*> m_images;
	MyColor *m_myColor;
	int m_offsetX;
	int m_offsetY;
	float m_opacity;
	GraphicsPath *m_path;
	Pen *m_pen;
	FCRect m_pRect;
	Long m_penColor;
	float m_penWidth;
	int m_penStyle;
	wstring m_resourcePath;
	int m_rotateAngle;
	double m_scaleFactorX;
	double m_scaleFactorY;
	int m_startLineCap;
	FCRect m_wRect;
protected:
	void affectScaleFactor(Rect *gdiplusRect);
	void affectScaleFactor(RectF *gdiplusRect);
	SolidBrush* getBrush(Long dwPenColor);
	Color getGdiPlusColor(Long dwPenColor);
	int getEncoderClsid(const WCHAR *format, CLSID *pClsid);
	Gdiplus::Font* getFont(FCFont *font);
	Pen* getPen(Long dwPenColor, float width, int style);
	GraphicsPath* getRoundRectPath(Rect gdiPlusRect, int cornerRadius);
public:
	GdiPlusPaintEx();
	virtual ~GdiPlusPaintEx();
	vector<CloudInfo> m_cloudInfos;
	DWORD m_startTime;
	bool m_useCloud;
public:
	virtual void addArc(const FCRect& rect, float startAngle, float sweepAngle);
	virtual void addBezier(FCPoint *apt, int cpt);
	virtual void addCurve(FCPoint *apt, int cpt);
	virtual void addEllipse(const FCRect& rect);
	virtual void addLine(int x1, int y1, int x2, int y2);
	virtual void addRect(const FCRect& rect);
	virtual void addPie(const FCRect& rect, float startAngle, float sweepAngle);
	virtual void addText(String strText, FCFont *font, const FCRect& rect, int width);
	virtual void beginExport(const wstring& exportPath, const FCRect& rect);
	virtual void beginPaint(HDC hDC, const FCRect& wRect, const FCRect& pRect);
	virtual void beginPath();
	virtual void clipPath();
	virtual void clearCaches();
	virtual void closeFigure();
	virtual void closePath();
	virtual void drawArc(Long dwPenColor, float width, int style, const FCRect& rect, float startAngle, float sweepAngle);
	virtual void drawBezier(Long dwPenColor, float width, int style, FCPoint *apt, int cpt);
	virtual void drawCurve(Long dwPenColor, float width, int style, FCPoint *apt, int cpt);
	virtual void drawDotLine(Long dwPenColor, const FCPoint& p1, const FCPoint& p2);
	virtual void drawDotLine(Long dwPenColor, int x1, int y1, int x2, int y2);
	virtual void drawEllipse(Long dwPenColor, float width, int style, const FCRect& rect);
	virtual void drawEllipse(Long dwPenColor, float width, int style, int left, int top, int right, int bottom);
	virtual void drawImage(String imagePath, const FCRect& rect);
	virtual void drawLine(Long dwPenColor, float width, int style, const FCPoint& x, const FCPoint& y);
	virtual void drawLine(Long dwPenColor, float width, int style, int x1, int y1, int x2, int y2);
	virtual void drawPath(Long dwPenColor, float width, int style);
	virtual void drawPie(Long dwPenColor, float width, int style, const FCRect& rect, float startAngle, float sweepAngle);
	virtual void drawPolygon(Long dwPenColor, float width, int style, FCPoint *apt, int cpt);
	virtual void drawPolyline(Long dwPenColor, float width, int style, FCPoint *apt, int cpt);
	virtual void drawRect(Long dwPenColor, float width, int style, int left, int top, int right, int bottom);
	virtual void drawRect(Long dwPenColor, float width, int style, const FCRect& rect);
	virtual void drawRoundRect(Long dwPenColor, float width, int style, const FCRect& rect, int cornerRadius);
	virtual void drawText(String strText, Long dwPenColor, FCFont *font, const FCRect& rect, int width);
	virtual void drawText(String strText, Long dwPenColor, FCFont *font, const FCRectF& rect, int width);
	//绘制有倒影的文字
	virtual void drawTextEx(String strText, Long dwPenColor, FCFont *font, const FCRect& rect, int width);
	virtual void drawTextAutoEllipsis(String strText, Long dwPenColor, FCFont *font, const FCRect& rect);
	virtual void endExport();
	virtual void endPaint();
	virtual void excludeClipPath();
	virtual void fillEllipse(Long dwPenColor, const FCRect& rect);
	virtual void fillGradientEllipse(Long dwFirst, Long dwSecond, const FCRect& rect, int angle);
	virtual void fillGradientPath(Long dwFirst, Long dwSecond, const FCRect& rect, int angle);
	virtual void fillGradientPolygon(Long dwFirst, Long dwSecond, FCPoint *apt, int cpt, int angle);
	virtual void fillGradientRect(Long dwFirst, Long dwSecond, const FCRect& rect, int cornerRadius, int angle);
	virtual void fillPath(Long dwPenColor);
	virtual void fillPie(Long dwPenColor, const FCRect& rect, float startAngle, float sweepAngle);
	virtual void fillPolygon(Long dwPenColor, FCPoint *apt, int cpt);
	virtual void fillRect(Long dwPenColor, const FCRect& rect);
	virtual void fillRect(Long dwPenColor, int left, int top, int right, int bottom);
	virtual void fillRoundRect(Long dwPenColor, const FCRect& rect, int cornerRadius);
	virtual Long getColor(Long dwPenColor);
	virtual Long getPaintColor(Long dwPenColor);
	virtual FCPoint getOffset();
	virtual void getScaleFactor(double *scaleFactorX, double *scaleFactorY);
	virtual FCPoint rotate(const FCPoint& op, const FCPoint& mp, int angle);
	virtual void setClip(const FCRect& rect);
	virtual void setLineCap(int startLineCap, int endLineCap);
	virtual void setOffset(const FCPoint& offset);
	virtual void setOpacity(float opacity);
    virtual void setResourcePath(const wstring& resourcePath);
	virtual void setRotateAngle(int rotateAngle);
	virtual void setScaleFactor(double scaleFactorX, double scaleFactorY);
	virtual bool supportTransparent();
	virtual FCSize textSize(String strText, FCFont *font, int width);
	virtual FCSizeF textSizeF(String strText, FCFont *font, int width);
};
#endif