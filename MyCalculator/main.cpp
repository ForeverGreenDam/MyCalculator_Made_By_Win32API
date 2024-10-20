
#include <windows.h>
#include <tchar.h>
#include "计算.h"
#include"UI.h"

static LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
 int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PSTR szCmdLine, _In_ int iCmdShow) {

    static TCHAR szAppName[11] = TEXT("普通计算器");
    HWND hwnd = 0;
    MSG msg;
    WNDCLASS wndclass;

    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = WndProc;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = hInstance;
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = szAppName;

    if (!RegisterClass(&wndclass)) {
        MessageBox(hwnd, TEXT("抱歉，本程序需要在Windows NT上运行！"), szAppName, MB_ICONERROR);
        return 0;
    }
    hwnd = CreateWindow(szAppName, TEXT("普通计算器"),
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
        CW_USEDEFAULT, CW_USEDEFAULT,
        CW_USEDEFAULT, CW_USEDEFAULT,
        NULL, NULL, hInstance, NULL);
    ShowWindow(hwnd, iCmdShow);
    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}	
 UIpainter UI;
static LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    HDC hdc;
    PAINTSTRUCT ps;
    RECT rect;
	static Calculator MyCalculator;
	static int CharNum = 0;
	static TCHAR* szBuffer = new TCHAR[1000];//用于存储输入的字符
	static int OperatorFlag = 0;
	static int OpNum = 0;//用于存储运算符的数量
	//初始化szBuffer，只执行一次
	static bool flag = false;
	for (int i = 0; i < 100; i++)
	{
		if (flag)
		{
			break;
		}
		szBuffer[i] = '\0';
	}
	flag = true;


	int num = 0;
    int id = 0;

		switch (message) {
	case WM_CREATE:
		 UI.PaintUI(hwnd);
		 return 0;
    case WM_COMMAND:
		 id = LOWORD(wParam);
        switch (id)
        {
        case ID_PERCENTAGE:
			if (OperatorFlag == 0)
			{
				MessageBox(NULL, TEXT("%只能用于第二位运算数"), TEXT("ERROR"), MB_OK);
			}
			else
			{
				szBuffer = MyCalculator.PerCentageTranslater(szBuffer, OperatorFlag);
				CharNum = _tcslen(szBuffer);
				OperatorFlag = 0;
				OpNum = 0;
				UI.ShowText(szBuffer);
				
			}
			break;
		case ID_CE://清空运算符之后的输入
			//如果没有运算符，则清空整个输入框
			if (OpNum==0)
			{
				SendMessage(hwnd, WM_COMMAND, ID_C, 0);
			}
			else {
				for (int i = OperatorFlag + 1; i < CharNum; i++)
				{
					szBuffer[i] = '\0';
				}
				CharNum = OperatorFlag + 1;
				UI.ShowText(szBuffer);
			}
			break;
		case ID_C://清空输入框
			MyCalculator.ReSetAll();
			for (int i = 0; i < CharNum; i++)
			{
				szBuffer[i] = '\0';
			}
			CharNum = 0;
			OperatorFlag = 0;
			OpNum = 0;
			UI.ShowText(szBuffer);
			break;
		case ID_BACKSPACE:
			if (CharNum!=0)
			{
				CharNum--;
			}
			szBuffer[CharNum] = '\0';
			UI.ShowText(szBuffer);
			break;
		case ID_RECI:
			szBuffer = MyCalculator.CompleaxTranslater(szBuffer, OperatorFlag,ID_RECI);
			CharNum = _tcslen(szBuffer);
			UI.ShowText(szBuffer);
			break;
		case ID_SQUARE:
			szBuffer = MyCalculator.CompleaxTranslater(szBuffer, OperatorFlag, ID_SQUARE);
			CharNum = _tcslen(szBuffer);
			UI.ShowText(szBuffer);


			break;
		case ID_SQRT:
			szBuffer = MyCalculator.CompleaxTranslater(szBuffer, OperatorFlag, ID_SQRT);
			CharNum = _tcslen(szBuffer);
			UI.ShowText(szBuffer);
			break;
		case ID_DIVIDE:
			if (OpNum==0)
			{
				szBuffer[CharNum] = '/';
				OperatorFlag = CharNum;
				UI.ShowText(szBuffer);
				CharNum++;
				OpNum++;
			}
			else
			{
				szBuffer = MyCalculator.SimpleTranslater(szBuffer, OperatorFlag);
				CharNum = _tcslen(szBuffer);
				szBuffer[CharNum] = '/';
				OperatorFlag = CharNum;
				CharNum++;
				OpNum = 1;
				UI.ShowText(szBuffer);
			}
			
			break;
		case ID_7:
			szBuffer[CharNum] = '7';
			UI.ShowText(szBuffer);
			CharNum++;
			break;
		case ID_8:
			szBuffer[CharNum] = '8';
			UI.ShowText(szBuffer);
			CharNum++;
			break;
		case ID_9:
			szBuffer[CharNum] = '9';
			UI.ShowText(szBuffer);
			CharNum++;
			break;
		case ID_MULTIPLY:
			if (OpNum == 0)
			{
				szBuffer[CharNum] = '*';
				OperatorFlag = CharNum;
				UI.ShowText(szBuffer);
				CharNum++;
				OpNum++;
			}
			else
			{
				szBuffer = MyCalculator.SimpleTranslater(szBuffer, OperatorFlag);
				CharNum = _tcslen(szBuffer);
				szBuffer[CharNum] = '*';
				OperatorFlag = CharNum;
				CharNum++;
				OpNum = 1;
				UI.ShowText(szBuffer);
			}
			break;
		case ID_4:
			szBuffer[CharNum] = '4';
			UI.ShowText(szBuffer);
			CharNum++;
			break;
		case ID_5:
			szBuffer[CharNum] = '5';
			UI.ShowText(szBuffer);
			CharNum++;
			break;
		case ID_6:
			szBuffer[CharNum] = '6';
			UI.ShowText(szBuffer);
			CharNum++;
			break;
		case ID_MINUS:
                
			if (OpNum == 0)
			{
				szBuffer[CharNum] = '-';
				OperatorFlag = CharNum;
				UI.ShowText(szBuffer);
				CharNum++;
				OpNum++;
			}
			else
			{
				szBuffer = MyCalculator.SimpleTranslater(szBuffer, OperatorFlag);
				CharNum = _tcslen(szBuffer);
				szBuffer[CharNum] = '-';
				OperatorFlag = CharNum;
				CharNum++;
				OpNum = 1;
				UI.ShowText(szBuffer);
			}
			break;
		case ID_1:
			szBuffer[CharNum] = '1';
			UI.ShowText(szBuffer);
			CharNum++;
			break;
		case ID_2:
			szBuffer[CharNum] = '2';
			UI.ShowText(szBuffer);
			CharNum++;
			break;
		case ID_3:
			szBuffer[CharNum] = '3';
			UI.ShowText(szBuffer);
			CharNum++;
			break;
		case ID_PLUS:
			if (OpNum == 0)
			{
				szBuffer[CharNum] = '+';
				OperatorFlag = CharNum;
				UI.ShowText(szBuffer);
				CharNum++;
				OpNum++;
			}
			else
			{
				szBuffer=MyCalculator.SimpleTranslater(szBuffer, OperatorFlag);
				CharNum = _tcslen(szBuffer) ;
				szBuffer[CharNum] = '+';
				OperatorFlag = CharNum;
				CharNum++;
				OpNum = 1;
				UI.ShowText(szBuffer);
			}
			break;
		case ID_NEGATIVE:
			szBuffer = MyCalculator.CompleaxTranslater(szBuffer, OperatorFlag, ID_NEGATIVE);
			CharNum = _tcslen(szBuffer);
			UI.ShowText(szBuffer);
			break;
		case ID_0:
			szBuffer[CharNum] = '0';
			UI.ShowText(szBuffer);
			CharNum++;
			break;
		case ID_DOT:
			szBuffer[CharNum] = '.';
			UI.ShowText(szBuffer);
			CharNum++;
			break;
		case ID_EQUAL:
			if (OpNum==1)
			{
				szBuffer = MyCalculator.SimpleTranslater(szBuffer, OperatorFlag);
				CharNum = _tcslen(szBuffer);
				OperatorFlag = 0;
				OpNum = 0;
				UI.ShowText(szBuffer);
			}
			break;
		default:
			break;
        }
        return 0;
    case WM_DESTROY:
		if (szBuffer != nullptr) {
			delete[] szBuffer;
			szBuffer = nullptr;
		}
		
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, message, wParam, lParam);
}