#include "stdafx.h"
#include "CCircle.h"

IMPLEMENT_SERIAL(CCircle, CObject, 3)//ʵ��������л���ָ���汾Ϊ3

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
		ar << OrgX << OrgY;//ԭ������
		ar << radius;
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
		ar >> radius;
		ar >> BorderColor;//�߽���ɫ
		ar >> BorderType;
		ar >> BorderWidth;//�߽���
		ar >> FillColor;//
		ar >> FillType;
	}
}

void CCircle::Draw(CDC* pDC)//����ͼ�κ���
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
	//��ʹ��Arc��������Բ������ϵͳ�޷�ȷ��ͼ���Ƿ��գ��ʲ��������ɫ

	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

bool CCircle::IsMatched(CPoint pnt)//ͼԪƥ�亯��
{
	if ((pnt.x - OrgX)*(pnt.x - OrgX) + (pnt.y - OrgY)*(pnt.y - OrgY) <= (radius*radius))
		return true;
	else
		return false;
}