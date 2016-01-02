
// calculatorDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include "afxdialogex.h"
#include "iostream"

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
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, QWER);
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
END_MESSAGE_MAP()


// CcalculatorDlg ��Ϣ��������

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵������ӵ�ϵͳ�˵��С�

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

	// TODO: �ڴ����Ӷ���ĳ�ʼ������

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

// �����Ի���������С����ť������Ҫ����Ĵ���
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

	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
}


void CcalculatorDlg::OnBnClickedClear()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	QWER="";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedleft()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	QWER=QWER+L"(";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedRight()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	QWER=QWER+L")";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedAdd()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	flag=1;
	UpdateData(true);
	temp=_ttof(QWER);
	QWER="";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked1()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	QWER=QWER+L"1";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked2()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	QWER=QWER+L"2";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked3()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	QWER=QWER+L"3";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedSub()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	flag=2;
	UpdateData(true);
	temp=_ttof(QWER);
	QWER="";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked4()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	QWER=QWER+L"4";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked5()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������\
UpdateData(true);
	QWER=QWER+L"5";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked6()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	QWER=QWER+L"6";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedDivision()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	flag=3;
	UpdateData(true);
	temp=_ttof(QWER);
	QWER="";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked7()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	QWER=QWER+L"7";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked8()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	QWER=QWER+L"8";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked9()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	QWER=QWER+L"9";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedButton17()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	flag=4;
	UpdateData(true);
	temp=_ttof(QWER);
	QWER="";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedPercent()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������

}


void CcalculatorDlg::OnBnClicked0()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	QWER=QWER+L"0";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedPoint()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	if(QWER.Find(L".")==-1)
		QWER=QWER+L".";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedequalto()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
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
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	QWER.Delete(QWER.GetLength()-1,1);
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedplusorminus()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	if(QWER.Left(1)=="-")
		QWER.Delete(0,1);
	else
		QWER=L"-"+QWER;
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedsignofevolution()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
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
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
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