#pragma once
#include "CShape.h"

class CSquare :public CShape
{
public:
	CSquare();
	~CSquare();
	CSquare(int x, int y, int w /*, COLORREF LineC, COLORREF FillC*/ );
	virtual void Draw(CDC*pDC);//绘制正方形
	virtual bool IsMatched(CPoint pnt);//重载点pnt是否落在图元内
	virtual void Serialize(CArchive& ar);//序列化正方形图元

private:
	int width;

	DECLARE_SERIAL(CSquare)//声明类支持序列化

};

