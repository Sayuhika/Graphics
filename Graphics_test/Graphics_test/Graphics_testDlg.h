
// Graphics_testDlg.h : ���� ���������
//

#pragma once
#include "Graph_Control.h"


// ���������� ���� CGraphics_testDlg
class CGraphics_testDlg : public CDialogEx
{
// ��������
public:
	CGraphics_testDlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
	enum { IDD = IDD_GRAPHICS_TEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
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
