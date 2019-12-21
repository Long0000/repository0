#pragma once
#include "CShape.h"

class CSquare :public CShape
{
public:
	CSquare();
	~CSquare();
	CSquare(int x, int y, int w /*, COLORREF LineC, COLORREF FillC*/ );
	virtual void Draw(CDC*pDC);//����������
	virtual bool IsMatched(CPoint pnt);//���ص�pnt�Ƿ�����ͼԪ��
	virtual void Serialize(CArchive& ar);//���л�������ͼԪ

private:
	int width;

	DECLARE_SERIAL(CSquare)//������֧�����л�

};

