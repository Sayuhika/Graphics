
// Graphics_test.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CGraphics_testApp:
// � ���������� ������� ������ ��. Graphics_test.cpp
//

class CGraphics_testApp : public CWinApp
{
public:
	CGraphics_testApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CGraphics_testApp theApp;