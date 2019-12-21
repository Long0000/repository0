#pragma once
#include "CShape.h"
class CTriangle :
	public CShape
{
public:
	CTriangle();
	virtual ~CTriangle();
	CTriangle(int x, int y, int e);
	virtual void Draw(CDC*pDC);//����������
	virtual bool IsMatched(CPoint pnt);//���ص�pnt�Ƿ�����ͼԪ��
	virtual void Serialize(CArchive& ar);//���л�������ͼԪ

private:
	int edge;

	DECLARE_SERIAL(CTriangle)//������֧�����л�
};

