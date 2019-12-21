#include "stdafx.h"
#include "CEllipse.h"

IMPLEMENT_SERIAL(CEllipse, CObject, 4)//实现类的序列化，指定版本为4

CEllipse::CEllipse()
{
	Type = ELLIPSE;
	width = 100;
	hight = 50;
}


CEllipse::~CEllipse()
{
}

CEllipse::CEllipse(int x, int y, int w, int h)
{
	Type = (ElementType)RECTANGLE;
	OrgX = x;
	OrgY = y;
	width = w;
	hight = h;
}

void CEllipse::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//原点坐标
		ar << width;
		ar << hight;
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
		ar >> width;
		ar >> hight;
		ar >> BorderColor;//边界颜色
		ar >> BorderType;
		ar >> BorderWidth;//边界宽度
		ar >> FillColor;//
		ar >> FillType;
	}
}
void CEllipse::Draw(CDC* pDC)//绘制图形函数
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

	pDC->Ellipse(OrgX - width / 2, OrgY - hight / 2, OrgX + width / 2, OrgY + hight / 2);

	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

bool CEllipse::IsMatched(CPoint pnt)//图元匹配函数
{
	if ((pnt.x >= (OrgX - width / 2)) && (pnt.x <= (OrgX + width / 2)) && (pnt.y >= (OrgY - hight / 2)) && (pnt.y <= (OrgY + hight / 2)))
		return true;
	else
		return false;
}