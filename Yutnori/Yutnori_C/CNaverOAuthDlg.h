﻿#pragma once
#include "afxdhtml.h"

#ifdef _WIN32_WCE
#error "Windows CE에서는 CDHtmlDialog가 지원되지 않습니다."
#endif

// CNaverOAuthDlg 대화 상자

class CNaverOAuthDlg : public CDHtmlDialog
{
	DECLARE_DYNCREATE(CNaverOAuthDlg)

public:
	CNaverOAuthDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CNaverOAuthDlg();
// 재정의입니다.
	HRESULT OnButtonOK(IHTMLElement *pElement);
	HRESULT OnButtonCancel(IHTMLElement *pElement);

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NAVEROAUTH_DIALOG, IDH = 104 };
#endif


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
	DECLARE_DHTML_EVENT_MAP()

public:
	CString m_RequestURl;
	CString m_strStateCode;
	CString m_ResultCode;
	CString m_Code;
	CString m_State;
	virtual void OnNavigateComplete(LPDISPATCH pDisp, LPCTSTR szUrl);
	virtual void OnDocumentComplete(LPDISPATCH pDisp, LPCTSTR szUrl);
	void SetRequestUrl(CString szURl) { m_RequestURl = szURl; }
	void SetResultCode(CString szResultCode) { m_ResultCode = szResultCode; }
	void SetCode(CString szCode) { m_Code = szCode; }
	void SetState(CString szState) { m_State = szState; }
	BOOL CallbackUrlExtractHtml(LPDISPATCH pDisp, LPCTSTR szUrl);
	CString ExtractUrl(LPCTSTR szUrl);
	CString FindCode(LPCTSTR szUrl);
	CString GetRequestUrl() { return m_RequestURl; }
	CString GetResultCode() { return m_ResultCode; }
	CString GetCode() { return m_Code; }
	CString GetState() { return m_State; }
	CString m_Token;
	CString UserID;
	CString UserNick;
};
