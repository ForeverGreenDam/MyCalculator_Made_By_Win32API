#pragma once
#include <windows.h>
#define ID_PERCENTAGE 100
#define ID_CE 104
#define ID_C 108
#define ID_BACKSPACE 112
#define ID_RECI 200
#define ID_SQUARE 204
#define ID_SQRT 208
#define ID_DIVIDE 212
#define ID_7 300
#define ID_8 304
#define ID_9 308
#define ID_MULTIPLY 312
#define ID_4 400
#define ID_5 404
#define ID_6 408
#define ID_MINUS 412
#define ID_1 500
#define ID_2 504
#define ID_3 508
#define ID_PLUS 512
#define ID_NEGATIVE 600
#define ID_0 604
#define ID_DOT 608
#define ID_EQUAL 612
class UIpainter
{
public:
	void PaintUI(HWND hwnd);
	void ShowText(TCHAR* str);

};