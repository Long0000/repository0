#pragma once


// CShapeDlg 对话框

class CShapeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CShapeDlg)

public:
	CShapeDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CShapeDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHAPE_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnCbnSelchangeCombo1();
	float m_ShapeX;
	float m_ShapeY;
	float m_ShapeWidth;
	float m_ShapeHight;
	CComboBox m_Combo;
	int m_ComboIndex;
	float m_Edge;
	float m_Radius;
	int m_BorderWidth;
	CMFCColorButton m_FillColor;
	CMFCColorButton m_BorderColor;

	BOOL CShapeDlg::OnInitDialog();

	CListBox m_LineType;
	CListBox m_FillType;
	int m_LineTypeIndex;
	int m_FillTypeIndex;
	COLORREF m_BorderColorIndex;
	COLORREF m_FillColorIndex;

	//实验
	COLORREF m_FillC;
	COLORREF m_BorderC;

	afx_msg void OnBnClickedMfccolorbutton1();
	afx_msg void OnBnClickedMfccolorbutton2();
	int m_Angle;
	CString m_Text;
};
