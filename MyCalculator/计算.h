#pragma once
#include <iostream>
#include <string>
#include<Windows.h>

class Calculator
{
public:
	Calculator(TCHAR* str);
	Calculator();
	BOOL StrToNum(TCHAR* str, double* num);
	BOOL NumToStr(double num, TCHAR* str);
	BOOL Calculate();
	void ReSetAll();
	~Calculator();
	void ADD();
	void MINUS();
	void MULTIPLY();
	void DIVIDE();
	void PERCENTAGE();
	void SQUARE();
	void SQRT();
	void RECI();
	void NEGATIVE();
	TCHAR* SimpleTranslater(TCHAR*str,int Opflag);
	TCHAR* CompleaxTranslater(TCHAR* str,int Opflag,int flag);
	TCHAR* PerCentageTranslater(TCHAR* str, int Opflag);
	
private:
	TCHAR* input;
	TCHAR* tempBuffer;
	TCHAR* output;
	double num1;
	double num2;
	double ans;
};


