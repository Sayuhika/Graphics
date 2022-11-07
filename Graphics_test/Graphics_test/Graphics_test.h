
// Graphics_test.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CGraphics_testApp:
// О реализации данного класса см. Graphics_test.cpp
//

class CGraphics_testApp : public CWinApp
{
public:
	CGraphics_testApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CGraphics_testApp theApp;