#pragma once
#include "CShape.h"
class CRectangle :
	public CShape
{
public:
	CRectangle();
	virtual ~CRectangle();
	CRectangle(int x, int y, int w, int h);
	virtual void Draw(CDC*pDC);//绘制矩形
	virtual bool IsMatched(CPoint pnt);//重载点pnt是否落在图元内
	virtual void Serialize(CArchive& ar);//序列化正方形图元

private:
	int width;
	int hight;

	DECLARE_SERIAL(CRectangle)//声明类支持序列化

};

