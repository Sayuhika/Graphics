
// Graphics_testDlg.h : файл заголовка
//

#pragma once
#include "Graph_Control.h"


// диалоговое окно CGraphics_testDlg
class CGraphics_testDlg : public CDialogEx
{
// Создание
public:
	CGraphics_testDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
	enum { IDD = IDD_GRAPHICS_TEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	double Frequency_Value;
	double Delta_Frequency_Value;
	double Phase_Value;
	BOOL Animation_MOD;
	afx_msg void OnBnClickedButton1();
	Graph_Control Graphoman;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedCheck1();
};
