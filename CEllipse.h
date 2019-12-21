#pragma once
#include "CShape.h"
class CEllipse :
	public CShape
{
public:
	CEllipse();
	virtual ~CEllipse();
	CEllipse(int x, int y, int w, int h);
	virtual void Draw(CDC*pDC);//������Բ��
	virtual bool IsMatched(CPoint pnt);//���ص�pnt�Ƿ�����ͼԪ��
	virtual void Serialize(CArchive& ar);//���л�������ͼԪ

private:
	int width;
	int hight;

	DECLARE_SERIAL(CEllipse)//������֧�����л�
};

