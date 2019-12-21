#include "stdafx.h"
#include "CTriangle.h"

IMPLEMENT_SERIAL(CTriangle, CObject, 5)//ʵ��������л���ָ���汾Ϊ5

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
		ar << OrgX << OrgY;//ԭ������
		ar << edge;
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
		ar >> edge;
		ar >> BorderColor;//�߽���ɫ
		ar >> BorderType;
		ar >> BorderWidth;//�߽���
		ar >> FillColor;//
		ar >> FillType;
	}
}


void CTriangle::Draw(CDC* pDC)//����ͼ�κ���
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

bool CTriangle::IsMatched(CPoint pnt)//ͼԪƥ�亯��
{
	if ((pnt.x >= (OrgX - edge / 2)) && (pnt.x <= (OrgX + edge / 2)) && (pnt.y >= (OrgY - pow(3, 0.5)*edge / 3)) && (pnt.y <= (OrgY + pow(3, 0.5)*edge / 6)))
		return true;
	else
		return false;
}