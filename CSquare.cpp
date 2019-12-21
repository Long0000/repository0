#include "stdafx.h"
#include "CSquare.h"

IMPLEMENT_SERIAL(CSquare, CObject, 1)//ʵ��������л���ָ���汾Ϊ1

CSquare::CSquare()
{
	Type = SQUARE;
	width = 50;
}


CSquare::~CSquare()
{
}

CSquare::CSquare(int x, int y, int w /*, COLORREF LineC, COLORREF FillC*/ )
{
	Type = (ElementType)SQUARE;
	OrgX = x;
	OrgY = y;
	width = w;
	//BorderColor = LineC;
	//FillColor = FillC;
}

void CSquare::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//ԭ������
		ar << width;
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
		ar >> BorderColor;//�߽���ɫ
		ar >> BorderType;
		ar >> BorderWidth;//�߽���
		ar >> FillColor;
		ar >> FillType;
	}
}


void CSquare::Draw(CDC* pDC)//����ͼ�κ���
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

	pDC->Rectangle(OrgX - width / 2, OrgY - width / 2, OrgX + width / 2, OrgY + width / 2);

	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

bool CSquare::IsMatched(CPoint pnt)//ͼԪƥ�亯��
{
	if ((pnt.x >= (OrgX - width / 2)) && (pnt.x <= (OrgX + width / 2)) && (pnt.y >= (OrgY - width / 2)) && (pnt.y <= (OrgY + width / 2)))
		return true;
	else
		return false;
}
