#pragma once


// Graph_Control

class Graph_Control : public CStatic
{
	DECLARE_DYNAMIC(Graph_Control)

public:
	Graph_Control();
	virtual ~Graph_Control();
	double phase;
	double frequecy;
	double delta_frequency;
	float function_harmonic(float x);

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	void Data_Control(double frequecy, double delta_frequency, double Phase);
};


