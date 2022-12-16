// iCTP_cpp.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "CTP.h"
#include "CStr.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CTP *ctp = new CTP;
    ctp->run();
	while(true)
	{
		char *input = new char[1024];
		cin >> input;
		if(strcmp(input, "exit") == 0)
		{
			break;
		}
	}
	return 0;
}

