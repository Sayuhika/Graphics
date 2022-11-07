#include <afxwin.h>
#include <gdiplus.h>
#include <math.h>
#include "math3d.h"

using namespace Gdiplus;
using namespace math3d;

class App : public CWinApp
{

public:
//	virtual void AddToRecentFileList(LPCTSTR lpszPathName);
	virtual BOOL InitInstance();
};

App app;

class Win : public CFrameWnd
{

public:
	Win();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
private:
	float angleY, angleZ;
};

//void App::AddToRecentFileList(LPCTSTR lpszPathName)
//{
//	// TODO: добавьте специализированный код или вызов базового класса
//
//	CWinApp::AddToRecentFileList(lpszPathName);
//}


BOOL App::InitInstance()
{
	// TODO: добавьте специализированный код или вызов базового класса
	m_pMainWnd = new Win;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return CWinApp::InitInstance();
}


Win::Win()
{
	ULONG_PTR token;
	GdiplusStartupInput input;
	Status status;
	angleY = angleZ = 0;

	status = GdiplusStartup(&token, &input, NULL);
	
	Create(NULL, L"Absolutly Empty Window");
}
BEGIN_MESSAGE_MAP(Win, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

float F_z(float x, float y)
{
	return (cos(x*x + y*y) / (x*x + y*y + 1));
}

void Win::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	Graphics TPoNA_(this->GetSafeHwnd());
	
	int N = 40;
	float turn = 4. / N;

	CRect WinFrame;
	this->GetClientRect(WinFrame);

	Gdiplus::Bitmap BMP(WinFrame.Width(), WinFrame.Height(), &TPoNA_);
	Graphics TPoNA(&BMP);
	TPoNA.Clear(Color::Black);

	float free_place_kof = 80;
	
	float kof_y_transform = (WinFrame.Width()/ 4.);
	float kof_z_transform = (WinFrame.Height()/ 2.);

	Matrix M;

	M.Scale(kof_y_transform, -kof_z_transform);
	M.Translate(2.0f, -1.5f);
	TPoNA.SetTransform(&M);

	Pen Aqua_Pen(Color::Aqua, -1.0f);
	SolidBrush Megumin_Brush(Color::Red);

	float x1, x2, x3, x4, y1, y2, y3, y4, z1, z2, z3, z4;

	for (int i = 0; i < N; i++)
	{
		x1 = i*turn - 2;
		x2 = x1+turn;
		x3 = x2;
		x4 = x1;
		for (int j = 0; j < N; j++)
		{
			y1 = j*turn - 2;
			y2 = y1;
			y3 = y2 + turn;
			y4 = y3;
			z1 = F_z(x1, y1);
			z2 = F_z(x2, y2);
			z3 = F_z(x3, y3);
			z4 = F_z(x4, y4);

			vec4 v1(x1, y1, z1);
			vec4 v2(x2, y2, z2);
			vec4 v3(x3, y3, z3);
			vec4 v4(x4, y4, z4);

			mat4 M4;

			M4.scale(0.7, 0.7, 0.7);
			M4.translate(0, 0, 0.25);
			M4.perspective(10);
			M4.rotateY(angleY).rotateZ(angleZ);

			v1 = v1*M4;
			v2 = v2*M4;
			v3 = v3*M4;
			v4 = v4*M4;

			PointF pf[] = { PointF(v1.y(), v1.z()), PointF(v2.y(), v2.z()), PointF(v3.y(), v3.z()), PointF(v4.y(), v4.z()) };

			TPoNA.FillPolygon(&Megumin_Brush, pf, 4);
			TPoNA.DrawPolygon(&Aqua_Pen, pf, 4);
		}
	}
	TPoNA_.DrawImage(&BMP,0,0);
	// TODO: добавьте свой код обработчика сообщений
	// Не вызывать CFrameWnd::OnPaint() для сообщений рисования
}


void Win::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	switch (nChar)
	{
	case VK_LEFT:
		angleZ--; 
		break;

	case VK_RIGHT:
		angleZ++; 
		break;

	case VK_UP:
		angleY--; 
		break;

	case VK_DOWN:
		angleY++; 
		break;

	default:
		break;
	}
	Invalidate(FALSE);
	CFrameWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}
