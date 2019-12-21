#pragma once
#include "CShape.h"
class CText :
	public CShape
{
public:
	CText();
	virtual ~CText();
	CText(int x, int y, int w, int h, int a, CString t);
	virtual void Draw(CDC*pDC);//���ƾ���
	virtual bool IsMatched(CPoint pnt);//���ص�pnt�Ƿ�����ͼԪ��
	virtual void Serialize(CArchive& ar);//���л�ͼԪ

private:
	int width;
	int hight;
	int angle;
	CString text;

	DECLARE_SERIAL(CText)//������֧�����л�

};

