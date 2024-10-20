#include"UI.h"
#include"计算.h"
#include<cmath>
#include <iostream>
#include <String>
#include <tchar.h> // Add this include for _tcscpy_s
#include<Windows.h>
Calculator::Calculator(TCHAR* str)
{
	input = new TCHAR[100];
	tempBuffer = new TCHAR[100];
	output = new TCHAR[100];
	_tcscpy_s(input, 100, str);
	num1 = 0;
	num2 = 0;
	ans = 0;

}

Calculator::Calculator()
{
	input = new TCHAR[100];
	tempBuffer = new TCHAR[100];
	output = new TCHAR[100];
	num1 = 0;
	num2 = 0;
	ans = 0;
}

BOOL Calculator::StrToNum(TCHAR* str, double* num)
{
    *num = _tcstod(str, NULL);
    return TRUE;
}

BOOL Calculator::NumToStr(double num, TCHAR* str)
{
    _stprintf_s(str, 100, _T("%f"), num);
    return TRUE;
}
BOOL Calculator::Calculate()
{
	return 0;
}

void Calculator::ReSetAll()
{
	num1 = 0;
	num2 = 0;
	ans = 0;
	for (int i = 0; i < 100; i++)
	{
		input[i] = '\0';
		tempBuffer[i] = '\0';
		output[i] = '\0';
	}
}
Calculator::~Calculator()
{
	
}

void Calculator::ADD()
{
	ans = num1 + num2;
	NumToStr(ans,output);
}

void Calculator::MINUS()
{
	ans = num1 - num2;
	NumToStr(ans, output);
}

void Calculator::MULTIPLY()
{
	ans = num1 * num2;
	NumToStr(ans, output);
}

void Calculator::DIVIDE()
{
	if (num2==0)
	{
		MessageBox(NULL, TEXT("除数不能为0"), TEXT("Error"), MB_OK);
		return;
	}
	ans = num1 / num2;
	NumToStr(ans, output);
}

void Calculator::PERCENTAGE()
{
	num2 = num1 * (num2 / 100);
}



void Calculator::SQUARE()
{
	ans = num1 * num1;
}

void Calculator::SQRT()
{
	ans = sqrt(num1);
}

void Calculator::RECI()
{
	ans = 1 / num1;
}

void Calculator::NEGATIVE()
{
	ans = -num1;
}

TCHAR* Calculator::SimpleTranslater(TCHAR* str, int Opflag)
{
	input = str;
	tempBuffer = str+Opflag+1;
	StrToNum(tempBuffer, &num2);
	TCHAR OP = input[Opflag];
	for (int i = Opflag; i < 100; i++)
	{
		input[i] = '\0';
	}
	StrToNum(input, &num1);

	switch (OP)
	{
	case '+':
		ADD();
		break;
	case '-':
		MINUS();
		break;
	case '*':
		MULTIPLY();
		break;
	case '/':
		DIVIDE();
		break;
	default:
		break;
	}
	return output;
}

TCHAR* Calculator::CompleaxTranslater(TCHAR* str, int Opflag,int flag)
{

	int i = 0;
	input = str;
	if (Opflag>0)
	{//如果Opflag>0，说明有操作符
		tempBuffer = input+Opflag+1;
	}
	else
		tempBuffer = input;
	output = input;
	StrToNum(tempBuffer, &num1);
	switch (flag)
	{
	case ID_SQRT:
		SQRT();
		break;
	case ID_SQUARE:
		SQUARE();
		break;
	case ID_RECI:
		RECI();
		break;
	case ID_NEGATIVE:
		NEGATIVE();
		break;
	default:
		break;
	}
	
	NumToStr(ans,tempBuffer);
	int j = 0;
	if (Opflag>0)
	{
		Opflag++;
	}
    for (int i=Opflag; i <=_tcslen(tempBuffer) ; i++)
	{
		output[i] = tempBuffer[j];
		j++;

	}
	return output;
}

TCHAR* Calculator::PerCentageTranslater(TCHAR* str, int Opflag)
{
	//处理百分号
	input = str;
	tempBuffer = str + Opflag + 1;
	StrToNum(tempBuffer, &num2);
	TCHAR OP = input[Opflag];
	for (int i = Opflag; i < 100; i++)
	{
		input[i] = '\0';
	}
	StrToNum(input, &num1);
	
	PERCENTAGE();
	switch (OP)
	{
	case '+':
		ADD();
		break;
	case '-':
		MINUS();
		break;
	case '*':
		MULTIPLY();
		break;
	case '/':
		DIVIDE();
		break;
	default:
		break;
	}

	return output;
}

