#include "stdafx.h"
#include "CText.h"

IMPLEMENT_SERIAL(CText, CObject, 6)//ʵ��������л���ָ���汾Ϊ6

CText::CText()
{
	Type = TEXT;
}


CText::~CText()
{
}

CText::CText(int x, int y, int w, int h, int a, CString t)
{
	Type = (ElementType)TEXT;
	OrgX = x;
	OrgY = y;
	width = w;
	hight = h;
	angle = a;
	text = t;
}

void CText::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//ԭ������
		ar << width;
		ar << hight;
		ar << angle;
		ar << text;
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
		ar >> angle;
		ar >> text;
		ar >> BorderColor;//�߽���ɫ
		ar >> BorderType;
		ar >> BorderWidth;//�߽���
		ar >> FillColor;//
		ar >> FillType;
	}
}

void CText::Draw(CDC*pDC)//�ı����ƺ���
{
	CFont font, *pOldFont;
	font.CreateFontW(
		hight,//�ַ��߼��߶�
		width,//�ַ��߼����
		angle*10,//��10������ѧ����ѧ�ĽǶ����
		angle*10,//��10������ѧ����ѧ�ĽǶ����
		200,
		FALSE,
		FALSE,
		0,
		ANSI_CHARSET,
		OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH&FF_SWISS,
		_T("Aerial")
	);
	pOldFont = (CFont*)pDC->SelectObject(&font);
	pDC->SetBkColor(RGB(200,200,200));//��ֵ��ͬ����(0,0,0)����(n,n,n)����(255,255,255)
	pDC->SetTextColor(BorderColor);
	pDC->TextOutW(OrgX, OrgY, text);//���ı������Ͻ�Ϊ���
	pDC->SelectObject(pOldFont);
}

bool CText::IsMatched(CPoint pnt)//ͼԪƥ�亯��
{
	if ((pnt.x >= OrgX) && (pnt.x <= (OrgX + width*10)) && (pnt.y >= (OrgY - hight*10)) && (pnt.y <= (OrgY + hight)))
		return true;
	else
		return false;
}