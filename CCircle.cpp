#include "stdafx.h"
#include "CCircle.h"

IMPLEMENT_SERIAL(CCircle, CObject, 3)//实现类的序列化，指定版本为3

CCircle::CCircle()
{
	Type = CIRCLE;
	radius = 50;
}


CCircle::~CCircle()
{
}

CCircle::CCircle(int x, int y, int r)
{
	Type = (ElementType)CIRCLE;
	OrgX = x;
	OrgY = y;
	radius = r;
}

void CCircle::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//原点坐标
		ar << radius;
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
		ar >> radius;
		ar >> BorderColor;//边界颜色
		ar >> BorderType;
		ar >> BorderWidth;//边界宽度
		ar >> FillColor;//
		ar >> FillType;
	}
}

void CCircle::Draw(CDC* pDC)//绘制图形函数
{
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderWidth, BorderColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);

	CBrush brush, *pOldBrush;
	if (FillType >= HS_HORIZONTAL && FillType <= HS_DIAGCROSS)
		brush.CreateHatchBrush(FillType = HS_DIAGCROSS, FillColor);
	else
		brush.CreateSolidBrush(FillColor);
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);

	pDC->Ellipse(OrgX - radius, OrgY - radius, OrgX + radius, OrgY + radius);
	//pDC->Arc(OrgX - radius, OrgY - radius, OrgX + radius, OrgY + radius, OrgX - radius, OrgY, OrgX - radius, OrgY);
	//若使用Arc函数绘制圆，由于系统无法确定图形是否封闭，故不能填充颜色

	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

bool CCircle::IsMatched(CPoint pnt)//图元匹配函数
{
	if ((pnt.x - OrgX)*(pnt.x - OrgX) + (pnt.y - OrgY)*(pnt.y - OrgY) <= (radius*radius))
		return true;
	else
		return false;
}