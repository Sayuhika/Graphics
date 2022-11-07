
// Graphics_testDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "Graphics_test.h"
#include "Graphics_testDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// диалоговое окно CGraphics_testDlg



CGraphics_testDlg::CGraphics_testDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGraphics_testDlg::IDD, pParent)
	, Frequency_Value(100)
	, Delta_Frequency_Value(10)
	, Phase_Value(0)
	, Animation_MOD(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGraphics_testDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Frequency_Value);
	DDX_Text(pDX, IDC_EDIT2, Delta_Frequency_Value);
	DDX_Check(pDX, IDC_CHECK1, Animation_MOD);
	DDX_Control(pDX, IDC_GR_COTR, Graphoman);
}

BEGIN_MESSAGE_MAP(CGraphics_testDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CGraphics_testDlg::OnBnClickedButton1)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_CHECK1, &CGraphics_testDlg::OnBnClickedCheck1)
END_MESSAGE_MAP()


// обработчики сообщений CGraphics_testDlg

BOOL CGraphics_testDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	Graphoman.Data_Control(Frequency_Value, Delta_Frequency_Value, 0);
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CGraphics_testDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CGraphics_testDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGraphics_testDlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	Graphoman.Data_Control(Frequency_Value, Delta_Frequency_Value, Phase_Value);
}


void CGraphics_testDlg::OnTimer(UINT_PTR nIDEvent)
{
	Phase_Value += 0.1;
	Graphoman.Data_Control(Frequency_Value, Delta_Frequency_Value, Phase_Value);
	CDialogEx::OnTimer(nIDEvent);
}


void CGraphics_testDlg::OnBnClickedCheck1()
{
	UpdateData(TRUE);
	if (Animation_MOD){ SetTimer(1, USER_TIMER_MINIMUM, NULL); }
	else{ KillTimer(1); }
}
