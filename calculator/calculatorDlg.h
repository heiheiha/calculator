
// calculatorDlg.h : 头文件
//

#pragma once


// CcalculatorDlg 对话框
class CcalculatorDlg : public CDialogEx
{
// 构造
public:
	CcalculatorDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CALCULATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	double x,y,secag,hag,minag;
	int color;
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CString QWER;
	afx_msg void OnBnClickedClear();
	afx_msg void OnBnClickedleft();
	afx_msg void OnBnClickedRight();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClicked1();
	afx_msg void OnBnClicked2();
	afx_msg void OnBnClicked3();
	afx_msg void OnBnClickedSub();
	afx_msg void OnBnClicked4();
	afx_msg void OnBnClicked5();
	afx_msg void OnBnClicked6();
	afx_msg void OnBnClickedDivision();
	afx_msg void OnBnClicked7();
	afx_msg void OnBnClicked8();
	afx_msg void OnBnClicked9();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedPercent();
	afx_msg void OnBnClicked0();
	afx_msg void OnBnClickedPoint();
	afx_msg void OnBnClickedequalto();
	double temp;
	int flag;
	afx_msg void OnBnClickedclear2();
	afx_msg void OnBnClickedplusorminus();
	afx_msg void OnBnClickedsignofevolution();
	afx_msg void OnBnClickedX2();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
