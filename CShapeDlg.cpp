// CShapeDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "Drawing.h"
#include "CShapeDlg.h"
#include "afxdialogex.h"


// CShapeDlg 对话框

IMPLEMENT_DYNAMIC(CShapeDlg, CDialogEx)

CShapeDlg::CShapeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SHAPE_DLG, pParent)
	, m_ShapeX(0)
	, m_ShapeY(0)
	, m_ShapeWidth(0)
	, m_ShapeHight(0)
	, m_ComboIndex(0)
	, m_Edge(0)
	, m_Radius(0)
	, m_BorderWidth(1)
	, m_LineTypeIndex(0)
	, m_FillTypeIndex(0)
	, m_Angle(0)
	, m_Text(_T("长江大学"))
{

}

CShapeDlg::~CShapeDlg()
{
}


BOOL CShapeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CComboBox* pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO1);
	pComboBox->AddString(L"正方形");
	pComboBox->AddString(L"矩形");
	pComboBox->AddString(L"圆形");
	pComboBox->AddString(L"椭圆");
	pComboBox->AddString(L"正三角形");
	pComboBox->AddString(L"文本");

	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LIST2);
	pListBox->AddString(L"SOLID");
	pListBox->AddString(L"DASH");
	pListBox->AddString(L"DASHDOT");

	pListBox = (CListBox*)GetDlgItem(IDC_LIST3);
	pListBox->AddString(L"SOLID");
	pListBox->AddString(L"BDIALOGAL");
	pListBox->AddString(L"CROSS");

	/*
	m_BorderColor.EnableAutomaticButton(_T("默认值"), RGB(0, 0, 0));
	m_BorderColor.EnableOtherButton(_T("其余颜色"));
	m_BorderColor.SetColor((COLORREF)-1);
	m_BorderColor.SetColumnsNumber(10);

	m_FillColor.EnableAutomaticButton(_T("默认值"), RGB(0, 0, 0));
	m_FillColor.EnableOtherButton(_T("其余颜色"));
	m_FillColor.SetColor((COLORREF)-1);
	m_FillColor.SetColumnsNumber(10);
	*/

	return TRUE;
}


void CShapeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_ShapeX);
	DDX_Text(pDX, IDC_EDIT2, m_ShapeY);
	DDX_Text(pDX, IDC_EDIT3, m_ShapeWidth);
	DDX_Text(pDX, IDC_EDIT4, m_ShapeHight);
	DDX_Control(pDX, IDC_COMBO1, m_Combo);
	DDX_CBIndex(pDX, IDC_COMBO1, m_ComboIndex);
	DDX_Text(pDX, IDC_EDIT11, m_Edge);
	DDX_Text(pDX, IDC_EDIT8, m_Radius);
	DDX_Text(pDX, IDC_EDIT5, m_BorderWidth);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON2, m_FillColor);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, m_BorderColor);
	DDX_Control(pDX, IDC_LIST2, m_LineType);
	DDX_Control(pDX, IDC_LIST3, m_FillType);
	DDX_LBIndex(pDX, IDC_LIST2, m_LineTypeIndex);
	DDX_LBIndex(pDX, IDC_LIST3, m_FillTypeIndex);
	DDX_Text(pDX, IDC_MFCCOLORBUTTON1, m_BorderColorIndex);
	DDX_Text(pDX, IDC_MFCCOLORBUTTON2, m_FillColorIndex);
	DDX_Text(pDX, IDC_EDIT9, m_Angle);
	DDX_Text(pDX, IDC_EDIT10, m_Text);
}


BEGIN_MESSAGE_MAP(CShapeDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &CShapeDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CShapeDlg::OnBnClickedButton4)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CShapeDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON1, &CShapeDlg::OnBnClickedMfccolorbutton1)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON2, &CShapeDlg::OnBnClickedMfccolorbutton2)
END_MESSAGE_MAP()


// CShapeDlg 消息处理程序


void CShapeDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码

	m_ComboIndex = m_Combo.GetCurSel();//获取下拉框的索引
	m_LineTypeIndex = m_LineType.GetCurSel();//获取线型列表框选择内容
	m_FillTypeIndex = m_FillType.GetCurSel();//获取填充类型列表框选择内容
	//m_BorderColorIndex = m_BorderColor.GetColor();
	//m_FillColorIndex = m_FillColor.GetColor();

	OnOK();
}


void CShapeDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	OnCancel();
}


void CShapeDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CShapeDlg::OnBnClickedMfccolorbutton1()
{
	// TODO: 在此添加控件通知处理程序代码

	//实验
	//m_BorderColorIndex = m_BorderColor.GetColor();
	m_BorderC = m_BorderColor.GetColor();

	if (m_BorderColorIndex == -1)
	{
		m_BorderColorIndex = m_BorderColor.GetAutomaticColor();
	}
}


void CShapeDlg::OnBnClickedMfccolorbutton2()
{
	// TODO: 在此添加控件通知处理程序代码

	//实验
	//m_FillColorIndex = m_FillColor.GetColor();
	m_FillC = m_FillColor.GetColor();

	if (m_FillColorIndex == -1)
	{
		m_FillColorIndex = m_FillColor.GetAutomaticColor();
	}
}
