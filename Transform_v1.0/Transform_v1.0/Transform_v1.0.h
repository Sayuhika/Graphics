
// Transform_v1.0.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CTransform_v10App:
// О реализации данного класса см. Transform_v1.0.cpp
//

class CTransform_v10App : public CWinApp
{
public:
	CTransform_v10App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CTransform_v10App theApp;