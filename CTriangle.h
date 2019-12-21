#pragma once
#include "CShape.h"
class CTriangle :
	public CShape
{
public:
	CTriangle();
	virtual ~CTriangle();
	CTriangle(int x, int y, int e);
	virtual void Draw(CDC*pDC);//绘制正方形
	virtual bool IsMatched(CPoint pnt);//重载点pnt是否落在图元内
	virtual void Serialize(CArchive& ar);//序列化正方形图元

private:
	int edge;

	DECLARE_SERIAL(CTriangle)//声明类支持序列化
};

