#include <afxwin.h>
#include <math.h>

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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint Point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint Point);

	CPoint begin, end;
};

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
	Create(NULL, L"Absolutly Empty Window");

	begin.SetPoint(0, 0);
	end.SetPoint(1, 1);
}

BEGIN_MESSAGE_MAP(Win, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

void DrawLineBrezenham(HDC hDC, int x1, int y1, int x2, int y2, COLORREF color)
{
	int x = x1, y = y1, dx = x2 - x1, dy = y2 - y1;
	int x_step, y_step;

	if ((dx == 0) && (dy == 0))
	{
		;
	}
	else
	{
		if (x2 > x1)
		{
			x_step = 1;
		}
		else x_step = -1;

		if (y2 > y1)
		{
			y_step = 1;
		}
		else y_step = -1;

		if (abs(dx) > abs(dy))
		{
			double e = (double)dy / dx;

			while (abs(x-x1) <= abs(dx))
			{
				::SetPixel(hDC, x, y, color);
				if (e >= 0.5)
				{
					y += y_step; e -= 1;
				}
				if (e <= -0.5)
				{
					y += y_step; e += 1;
				}
				x += x_step; e += (double)dy / dx;
			}
		}
		else
		{
			double e = (double)dx / dy;

			while (abs(y - y1) <= abs(dy))
			{
				::SetPixel(hDC, x, y, color);
				if (e >= 0.5)
				{
					x += x_step; e -= 1;
				}
				if (e <= -0.5)
				{
					x += x_step; e += 1;
				}
				y += y_step; e += (double)dx / dy;
			}
		}
	}
}

void DiagonalStep(int &x, int &y, int &e)
{
	x++;
	y--;
	e += 2 * (x - y + 1);
}

void HorizontalStep(int &x, int &e)
{
	x++;
	e += 2 * x + 1;
}

void VerticalStep(int &y, int &e)
{
	y--;
	e -= 2 * y - 1;
}

void DrawCircleBrezenham(HDC hDC, int x_c, int y_c, int R, COLORREF color)
{
	int x = 0,  y = R, e = 2 * (1 - R);
	while (y >= 0)
	{
		::SetPixel(hDC, x + x_c, y + y_c, color);
		::SetPixel(hDC, -x + x_c, y + y_c, color);
		::SetPixel(hDC, x + x_c, -y + y_c, color);
		::SetPixel(hDC, -x + x_c, -y + y_c, color);
		if (e == 0) DiagonalStep(x, y, e);
		else
			if (e < 0)
				if (2 * (e + y) - 1 <= 0) HorizontalStep(x, e);
				else DiagonalStep(x, y, e);
			else
				if (2 * (e - x) - 1 <= 0) DiagonalStep(x, y, e);
				else VerticalStep(y, e);
	}
}

void Win::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	DrawLineBrezenham(dc, begin.x, begin.y, end.x, end.y, RGB(255 * (int)rand() / RAND_MAX, 255 * (int)rand() / RAND_MAX, 255 * (int)rand() / RAND_MAX));
	
	DrawCircleBrezenham(dc, begin.x, begin.y, (int)sqrt((double)((end.x - begin.x)*(end.x - begin.x) + (end.y - begin.y)*(end.y - begin.y))), RGB(255 * (int)rand() / RAND_MAX, 255 * (int)rand() / RAND_MAX, 255 * (int)rand() / RAND_MAX));
}

void Win::OnLButtonDown(UINT nFlags, CPoint Point)
{
	begin = Point;
	Invalidate();

	CFrameWnd::OnLButtonDown(nFlags, Point);
}


void Win::OnMouseMove(UINT nFlags, CPoint Point)
{
	if (nFlags == 1)
	{
		end = Point;
		Invalidate(FALSE);
	}

	CFrameWnd::OnLButtonDown(nFlags, Point);
}