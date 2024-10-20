#include "UI.h"
#define ID_EDIT 1
static HWND hedit;
void UIpainter::PaintUI(HWND hwnd)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	TCHAR str[14] = TEXT("My Calculator");
	static const char* FTL[] = { TEXT("7"), TEXT("8"), TEXT("9"), TEXT("×") },//FTL: First Line
		* SCL[] = { TEXT("4"), TEXT("5"), TEXT("6"), TEXT("-") },//SCL: Second Line
		* TDL[] = { TEXT("1"), TEXT("2"), TEXT("3"), TEXT("＋") },//TDL: Third Line
		* FOL[] = { TEXT("负"), TEXT("0"), TEXT("."), TEXT("=") }, //FOL: Fourth Line
		* ADD1[] = { TEXT("％"), TEXT("CE"), TEXT("C"), TEXT("<-") },//ADD1: Addline 1
		* ADD2[] = { TEXT("1/x"), TEXT("平方"), TEXT("√x"), TEXT("÷") };//ADD2: Addline 2
	int cxChar, cyChar;
	hdc = BeginPaint(hwnd, &ps);
	GetClientRect(hwnd, &rect);
	cxChar = LOWORD(GetDialogBaseUnits());
	cyChar = HIWORD(GetDialogBaseUnits());
	MoveWindow(hwnd, 90, 30, 500, 780, TRUE);

	//创建按钮,共计24个，HMENU增加1，对应int增加4
	for (int i = 0; i < 4; i++)
		CreateWindow(TEXT("button"),
			ADD1[i],
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			125*i,270,125,80,hwnd,(HMENU)100+i, 
			(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE),
			NULL);
	for (int i = 0; i < 4; i++)
		CreateWindow(TEXT("button"),
			ADD2[i],
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			125 * i, 350, 125, 80, hwnd, (HMENU)200 + i,
			(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE),
			NULL);
	for (int i = 0; i < 4; i++)
		CreateWindow(TEXT("button"),
			FTL[i],
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			125 * i, 430, 125, 80, hwnd, (HMENU)300 + i,
			(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE),
			NULL);
	for (int i = 0; i < 4; i++)
		CreateWindow(TEXT("button"),
			SCL[i],
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			125 * i, 510, 125, 80, hwnd, (HMENU)400 + i,
			(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE),
			NULL);
	for (int i = 0; i < 4; i++)
		CreateWindow(TEXT("button"),
			TDL[i],
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			125 * i, 590, 125, 80, hwnd, (HMENU)500 + i,
			(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE),
			NULL);
	for (int i = 0; i < 4; i++)
		CreateWindow(TEXT("button"),
			FOL[i],
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			125 * i, 670, 125, 80, hwnd, (HMENU)600 + i,
			(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE),
			NULL);
	//设置字体加粗
    HFONT hFont = CreateFont(60, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS,
					CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("Arial"));
	//创建一个编辑框，用于显示计算结果
	hedit = CreateWindowA(TEXT("edit"),
		NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_READONLY | ES_RIGHT,
		1, 1, 480, 268,
		hwnd,
		(HMENU)ID_EDIT,
		(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE),
		NULL);
	SendMessage(hedit, WM_SETFONT, (WPARAM)hFont, 1);
	EndPaint(hwnd, &ps);
}
void UIpainter::ShowText(TCHAR* str)
{
	SetWindowText(hedit, str);
}
