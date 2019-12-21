#include "stdafx.h"
#include "CRectangle.h"

IMPLEMENT_SERIAL(CRectangle, CObject, 2)//ʵ��������л���ָ���汾Ϊ2

CRectangle::CRectangle()
{
	Type = RECTANGLE;
	width = 100;
	hight = 50;
}


CRectangle::~CRectangle()
{
}

CRectangle::CRectangle(int x, int y, int w, int h)
{
	Type = (ElementType)RECTANGLE;
	OrgX = x;
	OrgY = y;
	width = w;
	hight = h;
}

void CRectangle::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//ԭ������
		ar << width;
		ar << hight;
		ar << BorderColor;//�߽���ɫ
		ar << BorderType;
		ar << BorderWidth;//�߽���
		ar << FillColor;
		ar << FillType;

	}
	else
	{
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;//ԭ������
		ar >> width;
		ar >> hight;
		ar >> BorderColor;//�߽���ɫ
		ar >> BorderType;
		ar >> BorderWidth;//�߽���
		ar >> FillColor;//
		ar >> FillType;
	}
}
void CRectangle::Draw(CDC* pDC)//����ͼ�κ���
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

	pDC->Rectangle(OrgX - width / 2, OrgY - hight / 2, OrgX + width / 2, OrgY + hight / 2);

	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

bool CRectangle::IsMatched(CPoint pnt)//ͼԪƥ�亯��
{
	if ((pnt.x >= (OrgX - width / 2)) && (pnt.x <= (OrgX + width / 2)) && (pnt.y >= (OrgY - hight / 2)) && (pnt.y <= (OrgY + hight / 2)))
		return true;
	else
		return false;
}