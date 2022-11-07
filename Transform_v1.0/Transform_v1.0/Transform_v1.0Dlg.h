
// Transform_v1.0Dlg.h : ���� ���������
//

#pragma once
#include "ART_Control.h"
#include "afxcmn.h"


// ���������� ���� CTransform_v10Dlg
class CTransform_v10Dlg : public CDialogEx
{
// ��������
public:
	CTransform_v10Dlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
	enum { IDD = IDD_TRANSFORM_V10_DIALOG };

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

private:
	ART_Control A_C_Value;
public:
	CSliderCtrl angle;
	int coord_x;
	int coord_y;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
//	void Point_data(int data_x);
	void Point_data(int data_x, int data_y);
};
