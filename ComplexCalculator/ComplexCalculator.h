
// ComplexCalculator.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CComplexCalculatorApp:
// Сведения о реализации этого класса: ComplexCalculator.cpp
//

class CComplexCalculatorApp : public CWinApp
{
public:
	CComplexCalculatorApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CComplexCalculatorApp theApp;
