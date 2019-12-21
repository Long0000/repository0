
// DrawingView.cpp: CDrawingView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Drawing.h"
#endif

#include "DrawingDoc.h"
#include "DrawingView.h"

#include"CShape.h"
#include"CSquare.h"
#include"CCircle.h"
#include"CRectangle.h"
#include"CEllipse.h"
#include"CTriangle.h"
#include"CText.h"
#include"CShapeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawingView

IMPLEMENT_DYNCREATE(CDrawingView, CScrollView)

BEGIN_MESSAGE_MAP(CDrawingView, CScrollView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDrawingView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDBLCLK()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CDrawingView 构造/析构

CDrawingView::CDrawingView() noexcept
{
	// TODO: 在此处添加构造代码

}

CDrawingView::~CDrawingView()
{
}

BOOL CDrawingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CScrollView::PreCreateWindow(cs);
}

// CDrawingView 绘图

void CDrawingView::OnDraw(CDC* pDC)
{
	CDrawingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	for (int i = 0; i < pDoc->m_Elements.GetCount(); i++)
	{
		CShape* p = (CShape*)pDoc->m_Elements[i];
		p->Draw(pDC);
	}

}

void CDrawingView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 计算此视图的合计大小
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CDrawingView 打印


void CDrawingView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDrawingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDrawingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDrawingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CDrawingView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDrawingView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
// theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);//删除后取消IDR_POPUP_EDIT的功能
#endif
}


// CDrawingView 诊断

#ifdef _DEBUG
void CDrawingView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CDrawingView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CDrawingDoc* CDrawingView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawingDoc)));
	return (CDrawingDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawingView 消息处理程序


void CDrawingView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
		if ((nFlags&MK_CONTROL) == MK_CONTROL)//Ctrl键按下
		{
			CDrawingDoc* pDoc = GetDocument();
			ASSERT_VALID(pDoc);
			if (!pDoc)	return;

			CClientDC dc(this);
			CPoint pntLogical = point;
			OnPrepareDC(&dc);
			dc.DPtoLP(&pntLogical);//DP->LP进行转换

			CShape *p = NULL;

			shapeDlg.m_ShapeX = pntLogical.x;//光标位置
			shapeDlg.m_ShapeY = pntLogical.y;//光标位置
			shapeDlg.DoModal();//创建对话框

			switch (shapeDlg.m_ComboIndex)
			{
			case(0):
				//p = new CSquare(pntLogical.x, pntLogical.y, shapeDlg.m_Edge);//正方形
				p = new CSquare(pntLogical.x, pntLogical.y, shapeDlg.m_Edge);//正方形
				break;
			case(1):
				p = new CRectangle(pntLogical.x, pntLogical.y, shapeDlg.m_ShapeWidth, shapeDlg.m_ShapeHight);//矩形
				break;
			case(2):
				p = new CCircle(pntLogical.x, pntLogical.y, shapeDlg.m_Radius);//圆形
				break;
			case(3):
				p = new CEllipse(pntLogical.x, pntLogical.y, shapeDlg.m_ShapeWidth, shapeDlg.m_ShapeHight);//椭圆
				break;
			case(4):
				p = new CTriangle(pntLogical.x, pntLogical.y, shapeDlg.m_Edge);//正三角形
				break;
			case(5):
				p = new CText(pntLogical.x, pntLogical.y, shapeDlg.m_ShapeWidth, shapeDlg.m_ShapeHight, shapeDlg.m_Angle, shapeDlg.m_Text);//文本
				break;
			}

			//实验
			//BYTE r = GetRValue(shapeDlg.m_BorderColorIndex);
			//BYTE g = GetGValue(shapeDlg.m_BorderColorIndex);
			//BYTE b = GetBValue(shapeDlg.m_BorderColorIndex);
			//p->BorderColor = RGB(r, g, b);

			p->BorderWidth = shapeDlg.m_BorderWidth;
			p->BorderType = shapeDlg.m_LineTypeIndex;
			//实验
			//p->BorderColor = shapeDlg.m_BorderColorIndex;
			p->BorderColor = shapeDlg.m_BorderC;

			p->FillType = shapeDlg.m_FillTypeIndex;
			//实验
			//p->FillColor = shapeDlg.m_FillColorIndex;
			p->FillColor = shapeDlg.m_FillC;

			pDoc->m_Elements.Add(p);
			pDoc->SetModifiedFlag();
			pDoc->UpdateAllViews(NULL);
			// ----- 测试代码 end -----
		}
	CScrollView::OnLButtonDown(nFlags, point);
}


void CDrawingView::OnRButtonDblClk(UINT nFlags, CPoint point)//删除图元
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDrawingDoc* pDoc = GetDocument();
	CClientDC	dc(this);
	CPoint pntLogical = point;
	OnPrepareDC(&dc);
	dc.DPtoLP(&pntLogical);//DP->LP进行坐标转换 

	CShape* p;
	for (int i = 0; i < pDoc->m_Elements.GetCount(); i++)
	{
		p = (CShape*)pDoc->m_Elements[i];
		if (p->IsMatched(pntLogical)) //鼠标点point是否落在图元p之中
		{
			//AfxMessageBox(L"Matched!"); //选中图元p，在此编写处理代码
			pDoc->m_Elements.RemoveAt(i);
			delete(p);
			pDoc->UpdateAllViews(NULL);
		}
	}

	CScrollView::OnRButtonDblClk(nFlags, point);
}


void CDrawingView::OnLButtonDblClk(UINT nFlags, CPoint point)//修改图元属性
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDrawingDoc *pDoc = GetDocument();
	CClientDC dc(this);
	CPoint pntLogical = point;
	OnPrepareDC(&dc);
	dc.DPtoLP(&pntLogical);//DP->LP进行坐标转换 

	CShape *p;
	//shapeDlg.m_ShapeX = point.x;//此时我们需要图元中心的坐标，而不是光标的坐标
	//shapeDlg.m_ShapeY = point.y;//此时我们需要图元中心的坐标，而不是光标的坐标
	for (int i = pDoc->m_Elements.GetCount() - 1; i >= 0; i--)
	{
		p = (CShape*)pDoc->m_Elements[i];
		if (p->IsMatched(pntLogical))
		{

			if (shapeDlg.DoModal() == IDOK)
			{
				p->SetAttribute(
					shapeDlg.m_ShapeX,
					shapeDlg.m_ShapeY,
					shapeDlg.m_BorderWidth,
					shapeDlg.m_LineTypeIndex,
					shapeDlg.m_BorderC,
					shapeDlg.m_FillTypeIndex,
					shapeDlg.m_FillC
				);
				pDoc->UpdateAllViews(NULL);
			}
		}
	}

	CScrollView::OnLButtonDblClk(nFlags, point);
}
