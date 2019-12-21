#include "stdafx.h"
#include "CShape.h"


CShape::CShape()
{
}


CShape::~CShape()
{
}

void CShape::SetAttribute(int x, int y, int bw, int bt, COLORREF bc, int ft, COLORREF fc)
{
	OrgX = x;
	OrgY = y;
	BorderWidth = bw;
	BorderType = bt;
	BorderColor = bc;
	FillType = ft;
	FillColor = fc;
}