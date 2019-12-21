#include "stdafx.h"
#include "CTriangle.h"

IMPLEMENT_SERIAL(CTriangle, CObject, 5)//实现类的序列化，指定版本为5

CTriangle::CTriangle()
{
	Type = TRIANGLE;
	edge = 100;
}


CTriangle::~CTriangle()
{
}

CTriangle::CTriangle(int x, int y, int e)
{
	Type = (ElementType)SQUARE;
	OrgX = x;
	OrgY = y;
	edge = e;
}

void CTriangle::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//原点坐标
		ar << edge;
		ar << BorderColor;//边界颜色
		ar << BorderType;
		ar << BorderWidth;//边界宽度
		ar << FillColor;
		ar << FillType;

	}
	else
	{
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;//原点坐标
		ar >> edge;
		ar >> BorderColor;//边界颜色
		ar >> BorderType;
		ar >> BorderWidth;//边界宽度
		ar >> FillColor;//
		ar >> FillType;
	}
}


void CTriangle::Draw(CDC* pDC)//绘制图形函数
{
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderWidth, BorderColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);

	CBrush brush, *pOldBrush;
	if (FillType >= HS_HORIZONTAL && FillType <= HS_DIAGCROSS)
		brush.CreateHatchBrush(FillType, FillColor);
	else
		brush.CreateSolidBrush(FillColor);
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);

	POINT polygon[3] = { {OrgX,OrgY - pow(3,0.5)*edge / 3},{OrgX - edge / 2.0,OrgY + pow(3, 0.5)*edge / 6} ,{OrgX + edge / 2.0,OrgY + pow(3, 0.5)*edge / 6} };
	pDC->Polygon(polygon, 3);

	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

bool CTriangle::IsMatched(CPoint pnt)//图元匹配函数
{
	if ((pnt.x >= (OrgX - edge / 2)) && (pnt.x <= (OrgX + edge / 2)) && (pnt.y >= (OrgY - pow(3, 0.5)*edge / 3)) && (pnt.y <= (OrgY + pow(3, 0.5)*edge / 6)))
		return true;
	else
		return false;
}