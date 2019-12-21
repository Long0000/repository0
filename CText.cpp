#include "stdafx.h"
#include "CText.h"

IMPLEMENT_SERIAL(CText, CObject, 6)//实现类的序列化，指定版本为6

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
		ar << OrgX << OrgY;//原点坐标
		ar << width;
		ar << hight;
		ar << angle;
		ar << text;
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
		ar >> angle;
		ar >> text;
		ar >> BorderColor;//边界颜色
		ar >> BorderType;
		ar >> BorderWidth;//边界宽度
		ar >> FillColor;//
		ar >> FillType;
	}
}

void CText::Draw(CDC*pDC)//文本绘制函数
{
	CFont font, *pOldFont;
	font.CreateFontW(
		hight,//字符逻辑高度
		width,//字符逻辑宽度
		angle*10,//乘10后与数学几何学的角度相符
		angle*10,//乘10后与数学几何学的角度相符
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
	pDC->SetBkColor(RGB(200,200,200));//三值相同，黑(0,0,0)，灰(n,n,n)，白(255,255,255)
	pDC->SetTextColor(BorderColor);
	pDC->TextOutW(OrgX, OrgY, text);//以文本的左上角为起点
	pDC->SelectObject(pOldFont);
}

bool CText::IsMatched(CPoint pnt)//图元匹配函数
{
	if ((pnt.x >= OrgX) && (pnt.x <= (OrgX + width*10)) && (pnt.y >= (OrgY - hight*10)) && (pnt.y <= (OrgY + hight)))
		return true;
	else
		return false;
}