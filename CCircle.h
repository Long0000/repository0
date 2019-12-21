#pragma once
#include "CShape.h"
class CCircle :
	public CShape
{
public:
	CCircle();
	virtual ~CCircle();
	CCircle(int x, int y, int r);
	virtual void Draw(CDC*pDC);//绘制图
	virtual bool IsMatched(CPoint pnt);//重载点pnt是否落在图元内
	virtual void Serialize(CArchive& ar);//序列化图元

private:
	int radius;

	DECLARE_SERIAL(CCircle)//声明类支持序列化

};

