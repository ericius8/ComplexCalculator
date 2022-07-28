
// ComplexCalculatorDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "ComplexCalculator.h"
#include "ComplexCalculatorDlg.h"
#include "afxdialogex.h"
#include "complexlib.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CComplexCalculatorDlg



CComplexCalculatorDlg::CComplexCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_COMPLEXCALCULATOR_DIALOG, pParent)
	, FirstNumb(_T(""))
	, SecondNumb(_T(""))
	, Result(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CComplexCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_FIRST, FirstNumb);
	DDX_Text(pDX, IDC_EDIT_SECOND, SecondNumb);
	DDX_Text(pDX, IDC_EDIT_RESULT, Result);
	DDX_Control(pDX, IDC_COMBO_OPER, ComboControl);
}

BEGIN_MESSAGE_MAP(CComplexCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_RESULT, &CComplexCalculatorDlg::OnClickedButtonResult)
	ON_BN_CLICKED(IDC_BUTTON_w1, &CComplexCalculatorDlg::OnClickedButtonW1)
//	ON_EN_CHANGE(IDC_EDIT_FIRST, &CComplexCalculatorDlg::OnChangeEditFirst)
//	ON_EN_CHANGE(IDC_EDIT_SECOND, &CComplexCalculatorDlg::OnChangeEditSecond)
ON_EN_SETFOCUS(IDC_EDIT_FIRST, &CComplexCalculatorDlg::OnSetfocusEditFirst)
ON_EN_SETFOCUS(IDC_EDIT_SECOND, &CComplexCalculatorDlg::OnSetfocusEditSecond)
ON_BN_CLICKED(IDC_BUTTON_w0, &CComplexCalculatorDlg::OnClickedButtonW0)
ON_BN_CLICKED(IDC_BUTTON_w11, &CComplexCalculatorDlg::OnClickedButtonW11)
ON_BN_CLICKED(IDC_BUTTON_w12, &CComplexCalculatorDlg::OnClickedButtonW12)
ON_BN_CLICKED(IDC_BUTTON_w13, &CComplexCalculatorDlg::OnClickedButtonW13)
ON_BN_CLICKED(IDC_BUTTON_w14, &CComplexCalculatorDlg::OnClickedButtonW14)
ON_BN_CLICKED(IDC_BUTTON_w15, &CComplexCalculatorDlg::OnClickedButtonW15)
ON_BN_CLICKED(IDC_BUTTON_w16, &CComplexCalculatorDlg::OnClickedButtonW16)
ON_BN_CLICKED(IDC_BUTTON_w17, &CComplexCalculatorDlg::OnClickedButtonW17)
ON_BN_CLICKED(IDC_BUTTON_w2, &CComplexCalculatorDlg::OnClickedButtonW2)
ON_BN_CLICKED(IDC_BUTTON_w3, &CComplexCalculatorDlg::OnClickedButtonW3)
ON_BN_CLICKED(IDC_BUTTON_w4, &CComplexCalculatorDlg::OnClickedButtonW4)
ON_BN_CLICKED(IDC_BUTTON_w5, &CComplexCalculatorDlg::OnClickedButtonW5)
ON_BN_CLICKED(IDC_BUTTON_w6, &CComplexCalculatorDlg::OnClickedButtonW6)
ON_BN_CLICKED(IDC_BUTTON_w7, &CComplexCalculatorDlg::OnClickedButtonW7)
ON_BN_CLICKED(IDC_BUTTON_w8, &CComplexCalculatorDlg::OnClickedButtonW8)
ON_BN_CLICKED(IDC_BUTTON_w9, &CComplexCalculatorDlg::OnClickedButtonW9)
END_MESSAGE_MAP()


// Обработчики сообщений CComplexCalculatorDlg

BOOL CComplexCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	
	ComboControl.AddString(_T("+"));
	ComboControl.AddString(_T("-"));
	ComboControl.AddString(_T("*"));
	ComboControl.AddString(_T("/"));
	ComboControl.AddString(_T("sop"));
	ComboControl.AddString(_T("^"));
	ComboControl.AddString(_T("sqrt"));


	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CComplexCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CComplexCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CComplexCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CComplexCalculatorDlg::OnClickedButtonResult()
{
	UpdateData(TRUE);
	complex first = complex();
complex second = complex();
complex result = complex();
	first.Set(FirstNumb);
	second.Set(SecondNumb);
	switch (ComboControl.GetCurSel())
	{
	case 0:
	{	result = first + second;
		Result = output(result);
	}break;

	case 1:
	{
		Result = output(first - second);
	}break;

	case 2:
	{
		Result = output(first * second);
	}break;

	case 3:
	{
		result = first / second;
		Result = output(result);
	}break;

	case 4:
	{
		if (((SecondNumb.GetLength() != 0) && (FirstNumb.GetLength() != 0)) || ((SecondNumb.GetLength() == 0) && (FirstNumb.GetLength() == 0)))
		{
			AfxMessageBox(_T("odno"));
		}
		else
		{
			if (FirstNumb.GetLength() != 0)
			{
				Result = output(sop(first));;
			}
			if (SecondNumb.GetLength() != 0)
			{
				Result = output(sop(second));
			}
		}
	}break;

	case 5:
	{
		Result = output(pow(first, second));
	}break;

	case 6:
	{
		complex x1 = complex();
		complex x2 = complex();
		if (((SecondNumb.GetLength() != 0) && (FirstNumb.GetLength() != 0)) || ((SecondNumb.GetLength() == 0) && (FirstNumb.GetLength() == 0)))
		{
			AfxMessageBox(_T("odno2"));
		}
		else
		{
			if (FirstNumb.GetLength() != 0)
			{
				sqrt(first, x1, x2);
			}
			if (SecondNumb.GetLength() != 0)
			{
				sqrt(second, x1, x2);
			}
			Result = output(x1) + _T("  ") + output(x2);
		}
	}break;
	}
	UpdateData(FALSE);
}
	

bool ch=1;


void CComplexCalculatorDlg::OnSetfocusEditFirst()
{
	ch = 0;
}


void CComplexCalculatorDlg::OnSetfocusEditSecond()
{
	ch = 1;
}

void CComplexCalculatorDlg::OnClickedButtonW1()
{
	UpdateData(TRUE);
	if (ch)SecondNumb = SecondNumb + '1';
	else FirstNumb= FirstNumb + '1';
	UpdateData(FALSE);
}

void CComplexCalculatorDlg::OnClickedButtonW0()
{
	UpdateData(TRUE);
	if (ch)SecondNumb = SecondNumb + '0';
	else FirstNumb = FirstNumb + '0';
	UpdateData(FALSE);
}


void CComplexCalculatorDlg::OnClickedButtonW11()
{
	UpdateData(TRUE);
	if (ch)SecondNumb = SecondNumb + '(';
	else FirstNumb = FirstNumb + '(';
	UpdateData(FALSE);
}


void CComplexCalculatorDlg::OnClickedButtonW12()
{
	UpdateData(TRUE);
	if (ch)SecondNumb = SecondNumb + ')';
	else FirstNumb = FirstNumb + ')';
	UpdateData(FALSE);
}


void CComplexCalculatorDlg::OnClickedButtonW13()
{
	UpdateData(TRUE);
	if (ch)SecondNumb = SecondNumb + '+';
	else FirstNumb = FirstNumb + '+';
	UpdateData(FALSE);
}


void CComplexCalculatorDlg::OnClickedButtonW14()
{
	UpdateData(TRUE);
	if (ch)SecondNumb = SecondNumb + '-';
	else FirstNumb = FirstNumb + '-';
	UpdateData(FALSE);
}


void CComplexCalculatorDlg::OnClickedButtonW15()
{
	UpdateData(TRUE);
	if (ch)SecondNumb = SecondNumb + _T("sin(");
	else FirstNumb = FirstNumb + _T("sin(");
	UpdateData(FALSE);
}


void CComplexCalculatorDlg::OnClickedButtonW16()
{
	UpdateData(TRUE);
	if (ch)SecondNumb = SecondNumb + _T("cos(");
	else FirstNumb = FirstNumb + _T("cos(");
	UpdateData(FALSE);
}


void CComplexCalculatorDlg::OnClickedButtonW17()
{
	UpdateData(TRUE);
	if (ch)SecondNumb = SecondNumb + 'i';
	else FirstNumb = FirstNumb + 'i';
	UpdateData(FALSE);
}


void CComplexCalculatorDlg::OnClickedButtonW2()
{
	UpdateData(TRUE);
	if (ch)SecondNumb = SecondNumb + '2';
	else FirstNumb = FirstNumb + '2';
	UpdateData(FALSE);
}


void CComplexCalculatorDlg::OnClickedButtonW3()
{
	UpdateData(TRUE);
	if (ch)SecondNumb = SecondNumb + '3';
	else FirstNumb = FirstNumb + '3';
	UpdateData(FALSE);
}


void CComplexCalculatorDlg::OnClickedButtonW4()
{
	UpdateData(TRUE);
	if (ch)SecondNumb = SecondNumb + '4';
	else FirstNumb = FirstNumb + '4';
	UpdateData(FALSE);
}


void CComplexCalculatorDlg::OnClickedButtonW5()
{
	UpdateData(TRUE);
	if (ch)SecondNumb = SecondNumb + '5';
	else FirstNumb = FirstNumb + '5';
	UpdateData(FALSE);
}


void CComplexCalculatorDlg::OnClickedButtonW6()
{
	UpdateData(TRUE);
	if (ch)SecondNumb = SecondNumb + '6';
	else FirstNumb = FirstNumb + '6';
	UpdateData(FALSE);
}


void CComplexCalculatorDlg::OnClickedButtonW7()
{
	UpdateData(TRUE);
	if (ch)SecondNumb = SecondNumb + '7';
	else FirstNumb = FirstNumb + '7';
	UpdateData(FALSE);
}


void CComplexCalculatorDlg::OnClickedButtonW8()
{
	UpdateData(TRUE);
	if (ch)SecondNumb = SecondNumb + '8';
	else FirstNumb = FirstNumb + '8';
	UpdateData(FALSE);
}


void CComplexCalculatorDlg::OnClickedButtonW9()
{
	UpdateData(TRUE);
	if (ch)SecondNumb = SecondNumb + '9';
	else FirstNumb = FirstNumb + '9';
	UpdateData(FALSE);
}
