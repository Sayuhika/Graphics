
// Transform_v1.0.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CTransform_v10App:
// � ���������� ������� ������ ��. Transform_v1.0.cpp
//

class CTransform_v10App : public CWinApp
{
public:
	CTransform_v10App();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CTransform_v10App theApp;