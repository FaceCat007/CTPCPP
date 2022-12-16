#include "stdafx.h"
#include "CStr.h"

CodeConvert_Win::CodeConvert_Win( const char* input, unsigned int fromCodePage, unsigned int toCodePage ){
	int len = MultiByteToWideChar(fromCodePage, 0, input, -1, 0, 0);
	wcharBuf = new wchar_t[len + 1];
	memset(wcharBuf,0,sizeof(wchar_t)*(len + 1));
	MultiByteToWideChar(fromCodePage, 0, input, -1, wcharBuf, len);
	len = WideCharToMultiByte(toCodePage, 0, wcharBuf, -1, 0, 0, 0, 0);
	charBuf = new char[len + 1];
	memset(charBuf,0,sizeof(char)*(len + 1));
	WideCharToMultiByte(toCodePage, 0, wcharBuf, -1, charBuf, len, 0, 0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void FCStrEx::ANSCToUnicode(string& out, const char* inSrc){
	if (!inSrc){
		return ;
	}
	out = CodeConvert_Win(inSrc, CP_UTF8, CP_ACP).toString();
}

void FCStrEx::contact(wchar_t *str, LPCTSTR str1, LPCTSTR str2, LPCTSTR str3){
	str[0] = _T('\0');
	lstrcat(str, str1);
	if(lstrlen(str2) > 0){
		lstrcat(str, str2);
	}
	if(lstrlen(str3) > 0){
		lstrcat(str, str3);
	}
}

string FCStrEx::convertDBCodeToFileName(const string& code){
	string fileName = code;
	if (fileName.find(".") != -1){
        fileName = fileName.substr(fileName.find('.') + 1) + fileName.substr(0, fileName.find('.'));
    }
	fileName += ".txt";
	return fileName;
}

string FCStrEx::convertDBCodeToSinaCode(const string& code){
	string securityCode = code;
	int index = (int)securityCode.find(".SH");
    if (index > 0){
        securityCode = "sh" + securityCode.substr(0, securityCode.find("."));
    }
    else{
        securityCode = "sz" + securityCode.substr(0, securityCode.find("."));
    }
	return securityCode;
}

string FCStrEx::convertDBCodeToTencentCode(const string& code){
	string securityCode = code;
	int index = (int)securityCode.find(".");
	if(index > 0){
		index = (int)securityCode.find(".SH");
		if (index > 0){
			securityCode = "sh" + securityCode.substr(0, securityCode.find("."));
		}
		else{
			securityCode = "sz" + securityCode.substr(0, securityCode.find("."));
		}
	}
	return securityCode;
}

String FCStrEx::convertSinaCodeToDBCode(const String& code){
	int equalIndex = (int)code.find(L"=");
	int startIndex = (int)code.find(L"var hq_str_") + 11;
	String securityCode = equalIndex > 0 ?code.substr(startIndex, equalIndex - startIndex) : code;
	securityCode = securityCode.substr(2) + L"." + toUpper(securityCode.substr(0, 2));
    return securityCode;
}	

double FCStrEx::convertStrToDouble(const wchar_t *str){
	return _wtof(str);
}

int FCStrEx::convertStrToInt(const wchar_t *str){
	return _wtoi(str);
}

String FCStrEx::convertTencentCodeToDBCode(const String& code){
	int equalIndex = (int)code.find(L'=');
	String securityCode = equalIndex > 0 ? code.substr(0, equalIndex) : code;
	if (securityCode.find(L"v_sh") == 0){
		securityCode = securityCode.substr(4) + L".SH";
	}
	else if (securityCode.find(L"v_sz") == 0){
		securityCode = securityCode.substr(4) + L".SZ";
	}
	return securityCode;
}

String FCStrEx::getDBString(const String& strSrc){
	String str = replace(strSrc, L"'", L"''");
	return str;
}

string FCStrEx::getGuid(){
	static char buf[64] ={0};
	GUID guid;
	if (S_OK == ::CoCreateGuid(&guid)){
		_snprintf(buf, sizeof(buf)
			, "{%08X-%04X-%04x-%02X%02X-%02X%02X%02X%02X%02X%02X}"
			, guid.Data1
			, guid.Data2
			, guid.Data3
			, guid.Data4[0], guid.Data4[1]
		, guid.Data4[2], guid.Data4[3], guid.Data4[4], guid.Data4[5]
		, guid.Data4[6], guid.Data4[7]);
	}
	return buf;
}

int FCStrEx::getStringCapacity(const string& str){
	return (int)str.length() + 1 + sizeof(_int64);
}

int FCStrEx::getStringCapacity(const String& str){
	return ((int)str.length() + 1) * 2 + sizeof(_int64);
}

void FCStrEx::getValueByDigit(double value, int digit, wchar_t *str){
	switch(digit){
	case 1:
		_stprintf_s(str, 99, L"%.f", value);
		break;
	case 2:
		_stprintf_s(str, 99, L"%.2f", value);
		break;
	case 3:
		_stprintf_s(str, 99, L"%.3f", value);
		break;
	case 4:
		_stprintf_s(str, 99, L"%.4f", value);
		break;
	case 5:
		_stprintf_s(str, 99, L"%.5f", value);
		break;
	default:
		_stprintf_s(str, 99, L"%d", (long)value);
	}
	str = 0;
}

string FCStrEx::replace(const string& str, const string& src, const string& dest){
	string newStr = str;
	std::string::size_type pos = 0;
	while( (pos = newStr.find(src, pos)) != string::npos ){
		newStr.replace(pos, src.length(), dest);
		pos += dest.length();
	}
	return newStr;
}

String FCStrEx::replace(const String& str, const String& src, const String& dest){
	String newStr = str;
	String::size_type pos = 0;
	while( (pos = newStr.find(src, pos)) != string::npos ){
		newStr.replace(pos, src.length(), dest);
		pos += dest.length();
	}
	return newStr;
}

vector<string> FCStrEx::split(string str, string pattern){
		int pos = -1;
		vector<string> result;
		string newStr = str;
		newStr += pattern;
		int size = (int)str.size();
		for(int i = 0; i < size; i++){
		pos = (int)newStr.find(pattern, i);
		if((int)pos <= size){
			string s = newStr.substr(i, pos - i);
			if(s.length() > 0){
				result.push_back(s);
			}
			i = pos + (int)pattern.size() - 1;
		}
	}
	return result;
}

vector<String> FCStrEx::split(String str, String pattern){
		int pos = -1;
		vector<String> result;
		String newStr = str;
		newStr += pattern;
		int size = (int)str.size();
		for(int i = 0; i < size; i++){
		pos = (int)newStr.find(pattern, i);
		if((int)pos <= size){
			String s = newStr.substr(i, pos - i);
			result.push_back(s);
			i = pos + (int)pattern.size() - 1;
		}
	}
	return result;
}

String FCStrEx::stringTowstring(const string& strSrc){
	int  unicodeLen = ::MultiByteToWideChar(CP_ACP, 0, strSrc.c_str(), -1, 0, 0);
	wchar_t *pUnicode = new  wchar_t[unicodeLen + 1];
	memset(pUnicode,0,(unicodeLen + 1) * sizeof(wchar_t));
	::MultiByteToWideChar(CP_ACP, 0, strSrc.c_str(), - 1, (LPWSTR)pUnicode, unicodeLen);
	String strDest = ( wchar_t* )pUnicode;
	delete[] pUnicode;
	return strDest;
}

String FCStrEx::toLower(const String& str){
	String lowerStr = str;
	transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), tolower);
	return lowerStr;
}

String FCStrEx::toUpper(const String& str){
	String upperStr = str;
	transform(upperStr.begin(), upperStr.end(), upperStr.begin(), toupper);
	return upperStr;
}

void FCStrEx::unicodeToANSC(string& out, const char* inSrc){
	if (!inSrc){
		return ;
	}
	out = CodeConvert_Win(inSrc, CP_ACP, CP_UTF8).toString();
}
	
string FCStrEx::urlEncode(const std::string& szToEncode){
	string src = szToEncode;  
	char hex[] = "0123456789ABCDEF";  
	string dst; 
	for (size_t i = 0; i < src.size(); ++i){  
		unsigned char cc = src[i];  
		if ( cc >= 'A' && cc <= 'Z'   
					|| cc >='a' && cc <= 'z'  
					|| cc >='0' && cc <= '9'  
					|| cc == '.'  
					|| cc == '_'  
					|| cc == '-'  
					|| cc == '*'){  
			if (cc == ' '){  
				dst += "+";  
			}  
			else  
				dst += cc;  
		}  
		else{  
			unsigned char c = static_cast<unsigned char>(src[i]);  
			dst += '%';  
			dst += hex[c / 16];  
			dst += hex[c % 16];  
		}  
	}  
	return dst;  
}

string FCStrEx::urlDecode(const std::string& szToDecode){
	string result;  
	int hex = 0;  
	for (size_t i = 0; i < szToDecode.length(); ++i){  
		switch (szToDecode[i]){  
		case '+':  
			result += ' ';  
			break;  
		case '%':  
			if (isxdigit(szToDecode[i + 1]) && isxdigit(szToDecode[i + 2])){  
				std::string hexStr = szToDecode.substr(i + 1, 2);  
				hex = strtol(hexStr.c_str(), 0, 16);  
				//字母和数字[0-9a-zA-Z]、一些特殊符号[$-_.+!*'(),] 、以及某些保留字[$&+,/:;=?@]  
				//可以不经过编码直接用于URL  
				if (!((hex >= 48 && hex <= 57) || //0-9  
					(hex >=97 && hex <= 122) ||   //a-z  
					(hex >=65 && hex <= 90) ||    //A-Z  
					//一些特殊符号及保留字[$-_.+!*'(),]  [$&+,/:;=?@]  
					hex == 0x21 || hex == 0x24 || hex == 0x26 || hex == 0x27 || hex == 0x28 || hex == 0x29  
					|| hex == 0x2a || hex == 0x2b|| hex == 0x2c || hex == 0x2d || hex == 0x2e || hex == 0x2f  
					|| hex == 0x3A || hex == 0x3B|| hex == 0x3D || hex == 0x3f || hex == 0x40 || hex == 0x5f  
					)){  
					result += char(hex);  
					i += 2;  
				}  
				else result += '%';  
			}else{  
				result += '%';  
			}  
			break;  
		default:  
			result += szToDecode[i];  
			break;  
		}  
	}  
	return result;  
}

string FCStrEx::wstringTostring(const String& strSrc){
	int iTextLen = WideCharToMultiByte(CP_ACP, 0, strSrc.c_str(), -1, NULL, 0, NULL, NULL);
	char *pElementText = new char[iTextLen + 1];
	memset( ( void* )pElementText, 0, sizeof( char ) * ( iTextLen + 1 ) );
	::WideCharToMultiByte(CP_ACP, 0, strSrc.c_str(), - 1, pElementText, iTextLen, 0, 0);
	string strDest = pElementText;
	delete[] pElementText;
	return strDest;
}