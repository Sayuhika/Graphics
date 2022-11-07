#define WINVER 0x601	// Windows 7
#include <afxwin.h>
#include <gl/GL.h>
#include <ctime>

class App : public CWinApp
{
public:
	virtual BOOL InitInstance();
};


App OpenGradientApp;


class Win : public CFrameWnd
{
public:
	Win();
	DECLARE_MESSAGE_MAP()

	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	HGLRC glRC;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

	CPoint end, begin;
//	afx_msg void OnTimer(UINT_PTR nIDEvent);
};


BOOL App::InitInstance()
{
	m_pMainWnd = new Win;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return CWinApp::InitInstance();
}


Win::Win()
{
	// Создание окна:
	Create(AfxRegisterWndClass(CS_OWNDC), L"OpenGL");
	glRC = 0;
}


BEGIN_MESSAGE_MAP(Win, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
//	ON_WM_TIMER()
END_MESSAGE_MAP()


void Win::OnPaint()
{
	CPaintDC dc(this);
	::wglMakeCurrent(dc, glRC);

	std::clock_t start;
	double duration;
	start = std::clock();
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glEnable(GL_CULL_FACE);

	CRect rect;
	GetClientRect(&rect);

	if (rect.Width() > rect.Height())
	{ 
		glViewport((rect.Width() - rect.Height()) / 2, 0, rect.Height(), rect.Height()); 
	}
	else
	{
		glViewport(0, (rect.Height() - rect.Width()) / 2, rect.Width(), rect.Width());
	}
	

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glRotatef((begin.x - end.x), 0.0, 1.0, 0.0);
	glRotatef((begin.y - end.y), 1.0, 0.0, 0.0);
	glRotatef(duration, 1.0, 1.0, 0.0);

	glOrtho(-1, 1, -1, 1, -1, 1);

	glBegin(GL_POLYGON);
	glColor3d(rand() / (double)RAND_MAX, rand() / (double)RAND_MAX, rand() / (double)RAND_MAX); glVertex3d(0.4, 0.4, 0.4);
	glColor3d(rand() / (double)RAND_MAX, rand() / (double)RAND_MAX, rand() / (double)RAND_MAX); glVertex3d(-0.4, 0.4, 0.4);
	glColor3d(rand() / (double)RAND_MAX, rand() / (double)RAND_MAX, rand() / (double)RAND_MAX); glVertex3d(-0.4, -0.4, 0.4);
	glColor3d(rand() / (double)RAND_MAX, rand() / (double)RAND_MAX, rand() / (double)RAND_MAX); glVertex3d(0.4, -0.4, 0.4);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3d(rand() / (double)RAND_MAX, rand() / (double)RAND_MAX, rand() / (double)RAND_MAX); glVertex3d(0.4, -0.4, -0.4);
	glColor3d(rand() / (double)RAND_MAX, rand() / (double)RAND_MAX, rand() / (double)RAND_MAX); glVertex3d(-0.4, -0.4, -0.4);
	glColor3d(rand() / (double)RAND_MAX, rand() / (double)RAND_MAX, rand() / (double)RAND_MAX); glVertex3d(-0.4, 0.4, -0.4);
	glColor3d(rand() / (double)RAND_MAX, rand() / (double)RAND_MAX, rand() / (double)RAND_MAX); glVertex3d(0.4, 0.4, -0.4);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3d(rand() / (double)RAND_MAX, rand() / (double)RAND_MAX, rand() / (double)RAND_MAX); glVertex3d(0.4, 0.4, -0.4);
	glColor3d(rand() / (double)RAND_MAX, rand() / (double)RAND_MAX, rand() / (double)RAND_MAX); glVertex3d(-0.4, 0.4, -0.4);
	glColor3d(rand() / (double)RAND_MAX, rand() / (double)RAND_MAX, rand() / (double)RAND_MAX); glVertex3d(-0.4, 0.4, 0.4);
	glColor3d(rand() / (double)RAND_MAX, rand() / (double)RAND_MAX, rand() / (double)RAND_MAX); glVertex3d(0.4, 0.4, 0.4);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3d(rand() / (double)RAND_MAX, rand() / (double)RAND_MAX, rand() / (double)RAND_MAX); glVertex3d(0.4, -0.4, 0.4);
	glColor3d(rand() / (double)RAND_MAX, rand() / (double)RAND_MAX, rand() / (double)RAND_MAX); glVertex3d(-0.4, -0.4, 0.4);
	glColor3d(rand() / (double)RAND_MAX, rand() / (double)RAND_MAX, rand() / (double)RAND_MAX); glVertex3d(-0.4, -0.4, -0.4);
	glColor3d(rand() / (double)RAND_MAX, rand() / (double)RAND_MAX, rand() / (double)RAND_MAX); glVertex3d(0.4, -0.4, -0.4);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3d(rand() / (double)RAND_MAX, rand() / (double)RAND_MAX, rand() / (double)RAND_MAX); glVertex3d(0.4, 0.4, -0.4);
	glColor3d(rand() / (double)RAND_MAX, rand() / (double)RAND_MAX, rand() / (double)RAND_MAX); glVertex3d(0.4, 0.4, 0.4);
	glColor3d(rand() / (double)RAND_MAX, rand() / (double)RAND_MAX, rand() / (double)RAND_MAX); glVertex3d(0.4, -0.4, 0.4);
	glColor3d(rand() / (double)RAND_MAX, rand() / (double)RAND_MAX, rand() / (double)RAND_MAX);; glVertex3d(0.4, -0.4, -0.4);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3d(rand() / (double)RAND_MAX, rand() / (double)RAND_MAX, rand() / (double)RAND_MAX); glVertex3d(-0.4, -0.4, -0.4);
	glColor3d(rand() / (double)RAND_MAX, rand() / (double)RAND_MAX, rand() / (double)RAND_MAX); glVertex3d(-0.4, -0.4, 0.4);
	glColor3d(rand() / (double)RAND_MAX, rand() / (double)RAND_MAX, rand() / (double)RAND_MAX); glVertex3d(-0.4, 0.4, 0.4);
	glColor3d(rand() / (double)RAND_MAX, rand() / (double)RAND_MAX, rand() / (double)RAND_MAX); glVertex3d(-0.4, 0.4, -0.4);
	glEnd();
	glFlush();

	SwapBuffers(dc);

	::wglMakeCurrent(NULL, NULL);
}

void Win::OnSize(UINT nType, int cx, int cy)
{
	CFrameWnd::OnSize(nType, cx, cy);

	// TODO: добавьте свой код обработчика сообщений
	CDC* dc_ = GetDC();
	
	if (glRC != 0)
	{
		::wglDeleteContext(glRC);
	};

	PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR), 1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA, 32 };
	pfd.cDepthBits = 24;

	int format = ::ChoosePixelFormat(*dc_, &pfd);
	::SetPixelFormat(*dc_, format, &pfd);

	glRC = ::wglCreateContext(*dc_);

	ReleaseDC(dc_);

	Invalidate(FALSE);
}


void Win::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	if (nFlags == 1)
	{
		end = point;
		Invalidate(FALSE);
	}

	CFrameWnd::OnMouseMove(nFlags, point);
}


void Win::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	begin = point;
	Invalidate();

	CFrameWnd::OnLButtonDown(nFlags, point);
}


