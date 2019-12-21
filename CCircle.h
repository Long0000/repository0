#pragma once
#include "CShape.h"
class CCircle :
	public CShape
{
public:
	CCircle();
	virtual ~CCircle();
	CCircle(int x, int y, int r);
	virtual void Draw(CDC*pDC);//����ͼ
	virtual bool IsMatched(CPoint pnt);//���ص�pnt�Ƿ�����ͼԪ��
	virtual void Serialize(CArchive& ar);//���л�ͼԪ

private:
	int radius;

	DECLARE_SERIAL(CCircle)//������֧�����л�

};

