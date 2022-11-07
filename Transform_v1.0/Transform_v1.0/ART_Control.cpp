// ART_Control.cpp: файл реализации
//

#include "stdafx.h"
#include "Transform_v1.0.h"
#include "ART_Control.h"
#include <gdiplus.h>
#include "Transform_v1.0Dlg.h"

using namespace Gdiplus;

ULONG_PTR token;
// ART_Control

IMPLEMENT_DYNAMIC(ART_Control, CStatic)

ART_Control::ART_Control()
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif
	GdiplusStartupInput input;
	Status s;

	s = GdiplusStartup(&token, &input, NULL);
	if (s != Ok)
	{
		MessageBox(L"Ошибка Загрузки Библиотеки", L"Ошибка", MB_OK|MB_ICONERROR);
	}
	coord_x = coord_y = angle = 0;
}

ART_Control::~ART_Control()
{
	GdiplusShutdown(token);
}


BEGIN_MESSAGE_MAP(ART_Control, CStatic)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



// обработчики сообщений ART_Control




void ART_Control::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	Graphics Gr(lpDrawItemStruct->hDC);
	Gr.Clear(Color::White);
	Pen Aqua_Pen(Color::Aqua, 10.0f);
	SolidBrush Megumin_Brush(Color::Red);
	SolidBrush Darkness_Brush(Color::Yellow);
	Matrix m;
	m.RotateAt(angle, PointF(coord_x, coord_y));
	Gr.SetTransform(&m);
	Gr.FillEllipse(&Megumin_Brush, 50, 50, 250, 200);
	Gr.DrawEllipse(&Aqua_Pen, 50, 50, 250, 200);
	Gr.FillRectangle(&Megumin_Brush, 500, 260, 250, 200);
	Gr.DrawRectangle(&Aqua_Pen, 500, 260, 250, 200);
	Gr.FillEllipse(&Darkness_Brush, 220, 220, 170, 150);
	Gr.DrawEllipse(&Aqua_Pen, 220, 220, 170, 150);
	Gr.ResetTransform();
	Gr.DrawEllipse(&Aqua_Pen, coord_x-5, coord_y-5, 10, 10);
	// TODO:  Добавьте исходный код для отображения указанного элемента
}


void ART_Control::angle_set(int angle_data)
{
	angle = angle_data;
	Invalidate(FALSE);
}


void ART_Control::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	coord_x = point.x;
	coord_y = point.y;
	Invalidate(FALSE);
	((CTransform_v10Dlg*)GetParent())->Point_data(coord_x, coord_y);
	CStatic::OnLButtonDown(nFlags, point);
}
