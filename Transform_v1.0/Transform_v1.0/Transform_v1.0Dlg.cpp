
// Transform_v1.0Dlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "Transform_v1.0.h"
#include "Transform_v1.0Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���������� ���� CTransform_v10Dlg



CTransform_v10Dlg::CTransform_v10Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTransform_v10Dlg::IDD, pParent)
	, coord_x(0)
	, coord_y(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTransform_v10Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ST_PIC, A_C_Value);
	DDX_Control(pDX, IDC_SLIDER1, angle);
	DDX_Text(pDX, IDC_COORD_X, coord_x);
	DDX_Text(pDX, IDC_COORD_Y, coord_y);
}

BEGIN_MESSAGE_MAP(CTransform_v10Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// ����������� ��������� CTransform_v10Dlg

BOOL CTransform_v10Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ������ ������ ��� ����� ����������� ����.  ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	// TODO: �������� �������������� �������������
	angle.SetRange(-180, 180);
	angle.SetPos(0);
	angle.SetTicFreq(5);
	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������.  ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void CTransform_v10Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CTransform_v10Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CTransform_v10Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �������� ���� ��� ����������� ��������� ��� ����� ������������
	A_C_Value.angle_set(angle.GetPos());
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


//void CTransform_v10Dlg::Point_data(int data_x)
//{
//}


void CTransform_v10Dlg::Point_data(int data_x, int data_y)
{
	coord_x = data_x;
	coord_y = data_y;
	UpdateData(FALSE);
}
