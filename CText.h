#pragma once
#include "CShape.h"
class CText :
	public CShape
{
public:
	CText();
	virtual ~CText();
	CText(int x, int y, int w, int h, int a, CString t);
	virtual void Draw(CDC*pDC);//绘制矩形
	virtual bool IsMatched(CPoint pnt);//重载点pnt是否落在图元内
	virtual void Serialize(CArchive& ar);//序列化图元

private:
	int width;
	int hight;
	int angle;
	CString text;

	DECLARE_SERIAL(CText)//声明类支持序列化

};

