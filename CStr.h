/*基于捂脸猫FaceCat框架 v1.0
上海卷卷猫信息技术有限公司
 */

#ifndef __FCSTREX_H__
#define __FCSTREX_H__
#pragma once
#include "stdafx.h"

class CodeConvert_Win{
public:
	CodeConvert_Win(const char* input, unsigned int fromCodePage, unsigned int toCodePage);
	~CodeConvert_Win(){
		delete [] wcharBuf;        
		delete [] charBuf;    
		};    
		const char * toString(){    
			return charBuf;    
		};
private:    
		wchar_t * wcharBuf;    
		char * charBuf;
};

class FCStrEx{
public:
	static void ANSCToUnicode(string& out, const char* inSrc);
	static void contact(wchar_t *str, LPCTSTR str1, LPCTSTR str2 = L"", LPCTSTR str3 = L"");
	static string convertDBCodeToFileName(const string& code);
	static string convertDBCodeToSinaCode(const string& code);
	static string convertDBCodeToTencentCode(const string& code);
	static String convertSinaCodeToDBCode(const String& code);
	static double convertStrToDouble(const wchar_t *str);
	static int convertStrToInt(const wchar_t *str);
	static String convertTencentCodeToDBCode(const String& code);
	static String getDBString(const String& strSrc);
	static string getGuid();
	static int getStringCapacity(const string& str);
	static int getStringCapacity(const String& str);
	static void getValueByDigit(double value, int digit, wchar_t *str);
	static string replace(const string& str, const string& src, const string& dest);
	static String replace(const String& str, const String& src, const String& dest);
	static vector<string> split(string str, string pattern);
	static vector<String> split(String str, String pattern);
	static String stringTowstring(const string& strSrc);
	static String toLower(const String& str);
	static String toUpper(const String& str);
	static void unicodeToANSC(string& out, const char* inSrc);
	static string urlEncode(const std::string& szToEncode);
	static string urlDecode(const std::string& szToDecode);
	static string wstringTostring(const String& strSrc);
	static string getProgramDir();
};
#endif