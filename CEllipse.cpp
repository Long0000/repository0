#include "stdafx.h"
#include "CEllipse.h"

IMPLEMENT_SERIAL(CEllipse, CObject, 4)//ʵ��������л���ָ���汾Ϊ4

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
void CEllipse::Draw(CDC* pDC)//����ͼ�κ���
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

bool CEllipse::IsMatched(CPoint pnt)//ͼԪƥ�亯��
{
	if ((pnt.x >= (OrgX - width / 2)) && (pnt.x <= (OrgX + width / 2)) && (pnt.y >= (OrgY - hight / 2)) && (pnt.y <= (OrgY + hight / 2)))
		return true;
	else
		return false;
}