#include "stdafx.h"
#include "resource.h"
//#ifndef ULONG_PTR  
//#define ULONG_PTR unsigned long
//#endif
#include "gdiplus.h"
#pragma comment(lib, "gdiplus.lib")
using namespace Gdiplus;

#include "GdiPlusPaintEx.h"
#include "WinHostEx.h"
#include "MainFrame.h"

WinHostEx *m_host = 0;
HWND m_hWnd = 0;
FCNative *m_native = 0;

HINSTANCE hInst;					     //实例句柄
// 此代码模块中包含的函数的前向声明:
ATOM			   MyRegisterClass(HINSTANCE hInstance);                 //注册窗口类
BOOL			   InitInstance(HINSTANCE, int);		         //初始化窗口各种控件
LRESULT CALLBACK   WndProc(HWND, UINT, WPARAM, LPARAM);                          //主窗口回调函数

class NativeInfo{
public:
	WinHostEx *m_host2;
	HWND m_hWnd2;
	String m_key;
	FCNative *m_native2;
public:
	NativeInfo(){
		m_host2 = 0;
		m_hWnd2 = 0;
		m_native2 = 0;
	}
	virtual ~NativeInfo(){
		if(m_native2){
			m_native2->getPaint()->clearCaches();
			delete m_native2;
		}
		m_host2 = 0;
		m_native2 = 0;
	}
};

vector<NativeInfo*> m_nativeInfos;

FCSize GetClientSizeN(HWND hwnd)
{
	FCRect rect;
	::GetClientRect(hwnd, &rect);
	FCSize size = {rect.right - rect.left, rect.bottom - rect.top};
	return size;
}

static double m_scaleFactor = 1;

extern "C" __declspec(dllexport) int createNativeN(HWND hWnd, const char *key, double scaleFactor){
	m_scaleFactor = scaleFactor;
	NativeInfo *nativeInfo = new NativeInfo;
	nativeInfo->m_key = FCTran::stringToString(key);
	nativeInfo->m_native2 = new FCNative;
	nativeInfo->m_native2->setPaint(new GdiPlusPaintEx);
	nativeInfo->m_host2 = new WinHostEx;
	nativeInfo->m_host2->setAllowOperate(true);
	nativeInfo->m_hWnd2 = hWnd;
	nativeInfo->m_native2->setHost(nativeInfo->m_host2);
	nativeInfo->m_host2->setNative(nativeInfo->m_native2);
	nativeInfo->m_host2->setHWnd(hWnd);
	FCSize clientSize = GetClientSizeN(hWnd);
	nativeInfo->m_native2->setSize(clientSize);
	nativeInfo->m_native2->setAllowScaleSize(true);
	FCSize scaleSize = {(int)(clientSize.cx * m_scaleFactor), (int)(clientSize.cy * m_scaleFactor)};
	nativeInfo->m_native2->setScaleSize(scaleSize);
	MainFrame *mainFrame = new MainFrame;
	String appPath = FCTran::stringToString(FCTran::getAppPath());
	mainFrame->setNative(nativeInfo->m_native2);
	mainFrame->loadFile(appPath + L"\\config\\facecat_cpp\\MainFrame.xml", 0);
	nativeInfo->m_native2->update();
	m_nativeInfos.push_back(nativeInfo);
	int id =  (int)m_nativeInfos.size() - 1;
	return id;
}

extern "C" __declspec(dllexport) int removeNativeN(int id){
	delete m_nativeInfos[id];
	m_nativeInfos[id] = 0;
	return 0;
}

extern "C" __declspec(dllexport) int callFunctionN(int id, const char *cmd){
	String strCmd = FCTran::stringToString(cmd);
	if(strCmd.find(L"setstyle:") == 0){
		int style = FCTran::strToInt(strCmd.substr(strCmd.find(L":") + 1));
		MyColor::setStyle(style);
		m_nativeInfos[id]->m_native2->update();
		m_nativeInfos[id]->m_native2->invalidate();
	}
	else if(strCmd.find(L"setfont:") == 0){
		String sysFont = strCmd.substr(strCmd.find(L":") + 1);
		MyColor::setSystemFont(sysFont);
		FCNative::addChangeID();
		m_nativeInfos[id]->m_native2->update();
		m_nativeInfos[id]->m_native2->invalidate();
	}
	return 0;
}

//程序入口
int APIENTRY _tWinMain(HINSTANCE hInstance,
					   HINSTANCE hPrevInstance,
					   LPTSTR    lpCmdLine,
					   int       nCmdShow)
{
	std::locale::global(std::locale(""));
	MSG msg;
	CoInitialize(0);
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, 0);
	MyRegisterClass(hInstance);
	// 执行应用程序初始化:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}
	// 主消息循环:
	while (GetMessage(&msg, 0, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, 0, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	CoUninitialize();
	GdiplusShutdown(gdiplusToken);
	return 0;
}

//注册窗口类
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(wcex);

	wcex.style			= CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	wcex.hCursor		= LoadCursor(0, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= 0;
	wcex.lpszClassName  = L"ICARD";
	wcex.hIconSm		= 0;

	return RegisterClassEx(&wcex);
}

FCSize GetClientSize()
{
	FCRect rect;
	::GetClientRect(m_hWnd, &rect);
	FCSize size = {rect.right - rect.left, rect.bottom - rect.top};
	return size;
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;
	hInst = hInstance; // 将实例句柄存储在全局变量中
	hWnd = CreateWindow(L"ICARD", L"facecat_cpp", WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, 750, 1154, 0, 0, hInstance, NULL);

	/*hWnd = CreateWindow(L"ICARD", L"捂脸猫", WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, 0, 0, hInstance, NULL);*/
	if (!hWnd)
	{
		return FALSE;
	}
	m_hWnd = hWnd;
	m_native = new FCNative;
	String appPath = FCTran::stringToString(FCTran::getAppPath());
	m_native->setResourcePath(appPath + L"\\");
	m_native->setPaint(new GdiPlusPaintEx);
	WinHostEx *host = new WinHostEx;
	host->setNative(m_native);
	m_native->setHost(host);
	host->setHWnd(m_hWnd);
	m_host = host;
	m_native->setSize(GetClientSize());

	MainFrame *mainFrame = new MainFrame;
	mainFrame->setNative(m_native);
	mainFrame->loadFile(appPath + L"\\config\\facecat_cpp\\MainFrame.xml", 0);

	UpdateWindow(m_hWnd);
	ShowWindow(hWnd, SW_MAXIMIZE);
	UpdateWindow(hWnd);
	return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if(message == WM_SETCURSOR)
	{
		if((int)lParam == 33554433)
		{
			return 1;
		}
	}
	switch (message)
	{
		//处理关闭窗口的消息
	case WM_CLOSE:
		{
			DestroyWindow(hWnd);
			PostQuitMessage(0);
			break;
		}
	default:
		int handle = 0;
		if(m_host)
		{
			handle = m_host->onMessage(hWnd, message, wParam, lParam);
		}
		if(handle == 0)
		{
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		else
		{
			return 1;
		}
	}
	return 0;
}

extern "C" __declspec(dllexport) int onMessageN(int id, HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	if(!m_nativeInfos[id]){
		return 0;
	}
	NativeInfo *nativeInfo = m_nativeInfos[id];
	if(message == WM_SETCURSOR)
	{
		if((int)lParam == 33554433)
		{
			return 1;
		}
	}
	switch (message)
	{
		//处理关闭窗口的消息
	case WM_CLOSE:
		{
			break;
		}
	case WM_SIZE:
		{    
			if (nativeInfo->m_host2)
            {
				FCSize clientSize = GetClientSizeN(nativeInfo->m_hWnd2);
				nativeInfo->m_native2->setSize(clientSize);
				FCSize scaleSize = {(int)(clientSize.cx * m_scaleFactor), (int)(clientSize.cy * m_scaleFactor)};
				nativeInfo->m_native2->setScaleSize(scaleSize);
				nativeInfo->m_native2->update();
				nativeInfo->m_native2->invalidate();
				::UpdateWindow(hWnd);
            }
			break;
		}
	default:
		int handle = 0;
		if(nativeInfo->m_host2)
		{
			handle = nativeInfo->m_host2->onMessage(hWnd, message, wParam, lParam);
		}
		return handle;
	}
	return 0;
}

extern "C" __declspec(dllexport) int exportToImageN(int id, const char *path){
	NativeInfo *nativeInfo = m_nativeInfos[id];
	nativeInfo->m_native2->exportToImage(FCTran::stringToString(path));
	return 0;
}

extern "C" __declspec(dllexport) int startCloudPaintN(int id){
	return 0;
}

extern "C" __declspec(dllexport) int endCloudPaintN(int id){
	return 0;
}