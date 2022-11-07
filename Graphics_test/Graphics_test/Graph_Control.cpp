// Graph_Control.cpp: файл реализации
//

#include "stdafx.h"
#include "Graphics_test.h"
#include "Graph_Control.h"
#include <gdiplus.h>
#include <cstring>

using namespace Gdiplus;

ULONG_PTR token;

// Graph_Control

IMPLEMENT_DYNAMIC(Graph_Control, CStatic)

Graph_Control::Graph_Control()
{
	GdiplusStartupInput input;
	Status s;

	s = GdiplusStartup(&token, &input, NULL);
	if (s != Ok)
	{
		MessageBox(L"Ошибка Загрузки Библиотеки", L"Ошибка", MB_OK | MB_ICONERROR);
	}
}

Graph_Control::~Graph_Control()
{
	GdiplusShutdown(token);
}


BEGIN_MESSAGE_MAP(Graph_Control, CStatic)
END_MESSAGE_MAP()



// обработчики сообщений Graph_Control




void Graph_Control::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	Graphics Gr_(lpDrawItemStruct->hDC);
	Bitmap BM(lpDrawItemStruct->rcItem.right - lpDrawItemStruct->rcItem.left + 1.0f,
		lpDrawItemStruct->rcItem.bottom - lpDrawItemStruct->rcItem.top + 1.0f, &Gr_);
	Graphics Gr(&BM);
	Gr.SetSmoothingMode(SmoothingModeAntiAlias);
	Gr.Clear(Color::White);
	float free_place_kof = 80;
	float Kof_M = 4.0f * M_PI / delta_frequency;
	float kof_x_transform = (lpDrawItemStruct->rcItem.right - lpDrawItemStruct->rcItem.left + 1.0f - free_place_kof) / Kof_M;
	float kof_y_transform = (lpDrawItemStruct->rcItem.bottom - lpDrawItemStruct->rcItem.top + 1.0f - free_place_kof) / 4.0f;
	Matrix M;
	M.Translate(free_place_kof / 2, free_place_kof / 2);
	M.Scale(kof_x_transform, -kof_y_transform);
	M.Translate(0.0f, -2.0f);
	Gr.SetTransform(&M);
	Pen Aqua_Pen(Color::Aqua, -1.0f);
	Pen Darkness_Pen(Color::Yellow, -1.0f);
	Pen Megumin_Pen(Color::Red, -1.0f);
	Pen YunYun_Pen(Color::LightGray, -1.0f);
	SolidBrush Wiz(Color::Black);

	// Отрисовка сетки
	int greed_size = 10;
	float delta_x_greed = Kof_M / greed_size;
	float delta_y_greed = 4.0 / greed_size;

	// (Создание шрифта)
	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 12, FontStyleRegular, UnitPixel);

	for (int i = 0; i <= greed_size; i++)
	{
		float x = i*delta_x_greed;
		float y = i*delta_y_greed - 2;
		Gr.DrawLine(&YunYun_Pen, x, -2., x, 2.);
		Gr.DrawLine(&YunYun_Pen, 0., y, Kof_M, y);

		Gr.ResetTransform();

		CString str_x, str_y;
		str_x.Format(L"%.2f", x);
		str_y.Format(L"%.2f", y);

		PointF x_cor(x, -2), y_cor(0, y);

		M.TransformPoints(&x_cor);
		M.TransformPoints(&y_cor);

		y_cor.X -= 32;
		y_cor.Y -= 10;
		x_cor.X -= 16;
		x_cor.Y += 10;

		Gr.DrawString(str_x, -1, &font, x_cor, &Wiz);
		Gr.DrawString(str_y, -1, &font, y_cor, &Wiz);

		Gr.SetTransform(&M);
	}

	//Отрисовка графика
	int N = 400;
	float delta_x = Kof_M / N;
	float x1 = 0;
	float y1 = function_harmonic(x1);

	for (int i = 0; i < N; i++)
	{
		float x2 = x1 + delta_x;
		float y2 = function_harmonic(x2);
		Gr.DrawLine(&Aqua_Pen, x1, y1, x2, y2);
		y1 = y2;
		x1 = x2;
	}
	Gr_.DrawImage(&BM, 0, 0);
}

float Graph_Control::function_harmonic(float x)
{
	return cos(frequecy*x + phase) + cos((frequecy + delta_frequency)*x);
}

void Graph_Control::Data_Control(double frequecy, double delta_frequency, double Phase)
{
	this->frequecy = frequecy;
	this->delta_frequency = delta_frequency;
	phase = Phase;
	Invalidate(FALSE);
}
