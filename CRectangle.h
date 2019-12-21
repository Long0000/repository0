#pragma once
#include "CShape.h"
class CRectangle :
	public CShape
{
public:
	CRectangle();
	virtual ~CRectangle();
	CRectangle(int x, int y, int w, int h);
	virtual void Draw(CDC*pDC);//���ƾ���
	virtual bool IsMatched(CPoint pnt);//���ص�pnt�Ƿ�����ͼԪ��
	virtual void Serialize(CArchive& ar);//���л�������ͼԪ

private:
	int width;
	int hight;

	DECLARE_SERIAL(CRectangle)//������֧�����л�

};

