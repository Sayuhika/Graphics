#pragma once


// ART_Control

class ART_Control : public CStatic
{
	DECLARE_DYNAMIC(ART_Control)

public:
	ART_Control();
	virtual ~ART_Control();
	int coord_x, coord_y, angle;
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	void angle_set(int angle_data);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
//	void Point_data(int data_x, int data_y);
};


