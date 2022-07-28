
// ComplexCalculatorDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CComplexCalculatorDlg
class CComplexCalculatorDlg : public CDialogEx
{
// Создание
public:
	CComplexCalculatorDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COMPLEXCALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString FirstNumb;
	CString SecondNumb;
	CString Result;
	CComboBox ComboControl;
	afx_msg void OnClickedButtonResult();
	afx_msg void OnClickedButtonW1();
//	afx_msg void OnChangeEditFirst();
//	afx_msg void OnChangeEditSecond();
	afx_msg void OnSetfocusEditFirst();
	afx_msg void OnSetfocusEditSecond();
	afx_msg void OnClickedButtonW0();
	afx_msg void OnClickedButtonW11();
	afx_msg void OnClickedButtonW12();
	afx_msg void OnClickedButtonW13();
	afx_msg void OnClickedButtonW14();
	afx_msg void OnClickedButtonW15();
	afx_msg void OnClickedButtonW16();
	afx_msg void OnClickedButtonW17();
	afx_msg void OnClickedButtonW2();
	afx_msg void OnClickedButtonW3();
	afx_msg void OnClickedButtonW4();
	afx_msg void OnClickedButtonW5();
	afx_msg void OnClickedButtonW6();
	afx_msg void OnClickedButtonW7();
	afx_msg void OnClickedButtonW8();
	afx_msg void OnClickedButtonW9();
};
