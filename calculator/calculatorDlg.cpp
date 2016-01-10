
// calculatorDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include "afxdialogex.h"
#include "iostream"
#include "time.h"
#include "cmath"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���


class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcalculatorDlg �Ի���




CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CcalculatorDlg::IDD, pParent)
	, QWER(_T(""))
	, m_h(_T(""))
	, m_m(_T(""))
	, m_s(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, QWER);
	DDX_Text(pDX, IDC_EDIT2, m_h);
	DDX_Text(pDX, IDC_EDIT3, m_m);
	DDX_Text(pDX, IDC_EDIT4, m_s);
}

BEGIN_MESSAGE_MAP(CcalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CcalculatorDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_Clear, &CcalculatorDlg::OnBnClickedClear)
	ON_BN_CLICKED(IDC_left, &CcalculatorDlg::OnBnClickedleft)
	ON_BN_CLICKED(IDC_Right, &CcalculatorDlg::OnBnClickedRight)
	ON_BN_CLICKED(IDC_ADD, &CcalculatorDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_1, &CcalculatorDlg::OnBnClicked1)
	ON_BN_CLICKED(IDC_2, &CcalculatorDlg::OnBnClicked2)
	ON_BN_CLICKED(IDC_3, &CcalculatorDlg::OnBnClicked3)
	ON_BN_CLICKED(IDC_SUB, &CcalculatorDlg::OnBnClickedSub)
	ON_BN_CLICKED(IDC_4, &CcalculatorDlg::OnBnClicked4)
	ON_BN_CLICKED(IDC_5, &CcalculatorDlg::OnBnClicked5)
	ON_BN_CLICKED(IDC_6, &CcalculatorDlg::OnBnClicked6)
	ON_BN_CLICKED(IDC_Division, &CcalculatorDlg::OnBnClickedDivision)
	ON_BN_CLICKED(IDC_7, &CcalculatorDlg::OnBnClicked7)
	ON_BN_CLICKED(IDC_8, &CcalculatorDlg::OnBnClicked8)
	ON_BN_CLICKED(IDC_9, &CcalculatorDlg::OnBnClicked9)
	ON_BN_CLICKED(IDC_BUTTON17, &CcalculatorDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_Percent, &CcalculatorDlg::OnBnClickedPercent)
	ON_BN_CLICKED(IDC_0, &CcalculatorDlg::OnBnClicked0)
	ON_BN_CLICKED(IDC_Point, &CcalculatorDlg::OnBnClickedPoint)
	ON_BN_CLICKED(IDC_equal_to, &CcalculatorDlg::OnBnClickedequalto)
	ON_BN_CLICKED(IDC_clear2, &CcalculatorDlg::OnBnClickedclear2)
	ON_BN_CLICKED(IDC_plus_or_minus, &CcalculatorDlg::OnBnClickedplusorminus)
	ON_BN_CLICKED(IDC_signofevolution, &CcalculatorDlg::OnBnClickedsignofevolution)
	ON_BN_CLICKED(IDC_X2, &CcalculatorDlg::OnBnClickedX2)
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_Time, &CcalculatorDlg::OnBnClickedTime)
END_MESSAGE_MAP()


// CcalculatorDlg ��Ϣ�������

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	SetTimer(1,1000,NULL);
	secag=-0.05;
	minag=-0.05;
	hag=-0.05;

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CcalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CcalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcalculatorDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcalculatorDlg::OnBnClickedClear()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	QWER="";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedleft()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	QWER=QWER+L"(";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedRight()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	QWER=QWER+L")";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag=1;
	UpdateData(true);
	temp=_ttof(QWER);
	QWER="";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	QWER=QWER+L"1";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	QWER=QWER+L"2";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	QWER=QWER+L"3";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedSub()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag=2;
	UpdateData(true);
	temp=_ttof(QWER);
	QWER="";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	QWER=QWER+L"4";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������\
UpdateData(true);
	QWER=QWER+L"5";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	QWER=QWER+L"6";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedDivision()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag=3;
	UpdateData(true);
	temp=_ttof(QWER);
	QWER="";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	QWER=QWER+L"7";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	QWER=QWER+L"8";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	QWER=QWER+L"9";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedButton17()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag=4;
	UpdateData(true);
	temp=_ttof(QWER);
	QWER="";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedPercent()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

}


void CcalculatorDlg::OnBnClicked0()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	QWER=QWER+L"0";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedPoint()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if(QWER.Find(L".")==-1)
		QWER=QWER+L".";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedequalto()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	TRACE(L"flag=%d\n",flag);
	UpdateData(true);
	if(flag==1)
	{
		temp=temp+_ttof(QWER);
	}
	else
	{
		if(flag==2)
		{
			temp=temp-_ttof(QWER);
		}
		else
		{
			if(flag==3)
			{
				temp=temp*_ttof(QWER);
			}
			else
			{
				if(flag==4)
				{
					temp=temp/_ttof(QWER);
				}
			}
		}
	}
	QWER.Format(L"%lf",temp);
	QWER.Right(1)=="0";
	QWER.Delete(QWER.GetAllocLength()-4,7);
	UpdateData(false);

}


void CcalculatorDlg::OnBnClickedclear2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	QWER.Delete(QWER.GetLength()-1,1);
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedplusorminus()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(QWER.Left(1)=="-")
		QWER.Delete(0,1);
	else
		QWER=L"-"+QWER;
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedsignofevolution()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(_ttof(QWER)<0)
	{
		OnBnClickedClear();
		MessageBox(L"Worry!Retry.");
	}
	temp=_ttof(QWER);
	double f=sqrt(temp);
	QWER.Format(L"%f",f);
	QWER.Right(1)=="0";
	QWER.Delete(QWER.GetAllocLength()-4,7);
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedX2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(_ttof(QWER)==0)
	{
		OnBnClickedClear();
		MessageBox(L"Worry!Retry.");
	}
	QWER.Format(L"%lf",1.0/_ttof(QWER));
	QWER.Right(1)=="0";
	QWER.Delete(QWER.GetAllocLength()-4,7);
	UpdateData(false);


}


void CcalculatorDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	TRACE("X=%d,Y=%d\n",point.x,point.y);
	CDialogEx::OnMouseMove(nFlags, point);
}


void CcalculatorDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDC *pdc;
	pdc=GetDC();
	pdc->SetWindowOrg(0-510,0-185);
	CPen *oldpen;
	CPen groundpen(PS_SOLID,4,RGB(255,255,255));
	CPen pen(PS_SOLID,3,RGB(color,color,color));
	oldpen=pdc->SelectObject(&pen);
	pdc->Ellipse(-100,100,100,-100);
	CPen ppen(PS_SOLID,3,RGB(color,color,color));
	oldpen=pdc->SelectObject(&ppen);
	pdc->Ellipse(-1,-1,1,1);
	pdc->TextOutW(90,-8,L"3");
	pdc->TextOutW(-98,-8,L"9");
	pdc->TextOutW(-8,-99.5,L"12");
	pdc->TextOutW(-2,83,L"6");
	for(int i=0;i<12;i++)
	{
		double l=90,ag=i*3.1415926/6;
		double a=l*sin(ag)+1,b=-l*cos(ag)+1,c=l*sin(ag)-1,d=-l*cos(ag)-1;
		pdc->Ellipse(a,b,c,d);
	}


    double L1=70,L2=60,L3=50;          //miaozhen
	oldpen=pdc->SelectObject(&groundpen);
	x=L1*sin(secag);
	y=-L1*cos(secag);
	pdc->MoveTo(0,0);
	pdc->LineTo(x,y);
	CPen secpen(PS_SOLID,2,RGB(150,150,150));
	oldpen=pdc->SelectObject(&secpen);
	secag=secag+3.1415926/30;
	x=L1*sin(secag);
	y=-L1*cos(secag);
	pdc->MoveTo(0,0);
	pdc->LineTo(x,y);
	if(secag>=6.2831852)
		secag=-3.1415926/30;


	oldpen=pdc->SelectObject(&groundpen);//fenzhen
	x=L2*sin(minag);
	y=-L2*cos(minag);
	pdc->MoveTo(0,0);
	pdc->LineTo(x,y);
	CPen minpen(PS_SOLID,3,RGB(0,255,150));
	oldpen=pdc->SelectObject(&minpen);
	minag=minag+3.1415926/1800;
	x=L2*sin(minag);
	y=-L2*cos(minag);
	pdc->MoveTo(0,0);
	pdc->LineTo(x,y);
	if(minag>=6.2831852)
		minag=-3.1415926/1800;


	oldpen=pdc->SelectObject(&groundpen);//shizhen
	x=L3*sin(hag);
	y=-L3*cos(hag);
	pdc->MoveTo(0,0);
	pdc->LineTo(x,y);
	CPen hpen(PS_SOLID,3,RGB(255,0,0));
	oldpen=pdc->SelectObject(&hpen);
	hag=hag+3.1415926/21600;
	x=L3*sin(hag);
	y=-L3*cos(hag);
	pdc->MoveTo(0,0);
	pdc->LineTo(x,y);
	if(hag>=6.2831852)
	hag=-3.1415926/21600;
	CDialogEx::OnTimer(nIDEvent);
}


void CcalculatorDlg::OnBnClickedTime()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	/*
	UpdateData(true);
	hag=m_h*(3.1415926/6)+m_m*(3.1415926/360)+m_s*(3.1415926/21600);
	minag=m_m*(3.1415926/30)+m_s*(3.1415926/1800);
	secag=m_s*(3.1415926/30);
	SetTimer(1,1000,NULL);
	*/
}
