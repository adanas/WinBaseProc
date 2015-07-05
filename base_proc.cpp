#include "base_proc.h"

#define PROPKEY_CLASS	_T("cls_ptr")

HINSTANCE ClsBaseProc::m_hInstance = NULL;

/********************************************************************
;[Name]
;	ClsBaseProc
;[Action]
;	コンストラクタ
;[Input]
;	なし
;[Output]
;	なし
;
;coding :__/__/__:1.00:___:__________________________________________
;update :__/__/__:_.__:___:__________________________________________
;coding :__/__/__:_.__:___:__________________________________________
;bugfix :__/__/__:_.__:___:__________________________________________
;sysfix :__/__/__:_.__:___:__________________________________________
[MainTopic]
********************************************************************/
ClsBaseProc::ClsBaseProc()
{
	m_hWnd     = NULL;
	m_org_proc = NULL;
	m_is_dlg   = FALSE;
} // End Of Fnc

/********************************************************************
;[Name]
;	~ClsBaseProc
;[Action]
;	デストラクタ
;[Input]
;	なし
;[Output]
;	なし
;
;coding :__/__/__:1.00:___:__________________________________________
;update :__/__/__:_.__:___:__________________________________________
;coding :__/__/__:_.__:___:__________________________________________
;bugfix :__/__/__:_.__:___:__________________________________________
;sysfix :__/__/__:_.__:___:__________________________________________
[MainTopic]
********************************************************************/
ClsBaseProc::~ClsBaseProc()
{
} // End Of Fnc

BOOL ClsBaseProc::attach(HWND hWnd)
{
	if (!hWnd)
		return FALSE;

	m_hWnd = hWnd;

	m_is_dlg = (GetWindowLong(m_hWnd, DWL_DLGPROC) != 0);

	SetProp(m_hWnd, PROPKEY_CLASS, (HANDLE) this);

	int nIndex = m_is_dlg ? DWL_DLGPROC : GWL_WNDPROC;

	LONG proc = GetWindowLong(m_hWnd, nIndex);

	if (proc != (LONG) call_wnd_proc && proc != (LONG) call_mdi_proc && proc != (LONG) call_dlg_proc)
		m_org_proc = (WNDPROC) SetWindowLong(m_hWnd, nIndex, (LONG) call_proc);

	return TRUE;
} // End Of Fnc

HWND ClsBaseProc::detach()
{
	if (!m_hWnd)
		return NULL;

	if (m_org_proc)
		SetWindowLong(m_hWnd, (m_is_dlg ? DWL_DLGPROC : GWL_WNDPROC), (LONG) m_org_proc);

	RemoveProp(m_hWnd, PROPKEY_CLASS);

	HWND hWnd = m_hWnd;
	m_hWnd = NULL;

	return hWnd;
} // End Of Fnc

LRESULT CALLBACK ClsBaseProc::call_wnd_proc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	ClsBaseProc *cls_ptr = (ClsBaseProc *) GetProp(hWnd, PROPKEY_CLASS);

	if (!cls_ptr) {
		if ((Msg == WM_CREATE) || (Msg == WM_NCCREATE))
			cls_ptr = (ClsBaseProc *) ((LPCREATESTRUCT) lParam)->lpCreateParams;

		if (cls_ptr)
			cls_ptr->attach(hWnd);
	}

	if (cls_ptr) {
		LRESULT result = cls_ptr->wnd_proc(hWnd, Msg, wParam, lParam);

		if (Msg == WM_DESTROY)
			cls_ptr->detach();

		return result;
	}

	return DefWindowProc(hWnd, Msg, wParam, lParam);
} // End Of Fnc

LRESULT CALLBACK ClsBaseProc::call_mdi_proc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	ClsBaseProc *cls_ptr = (ClsBaseProc *) GetProp(hWnd, PROPKEY_CLASS);

	if (!cls_ptr) {
		if (Msg == WM_CREATE || Msg == WM_NCCREATE) {
			LPVOID lp = ((LPCREATESTRUCT) lParam)->lpCreateParams;
			cls_ptr = (ClsBaseProc *) ((LPMDICREATESTRUCT) lp)->lParam;
		}

		if (cls_ptr)
			cls_ptr->attach(hWnd);
	}

	if (cls_ptr) {
		LRESULT result = cls_ptr->wnd_proc(hWnd, Msg, wParam, lParam);

		if (Msg == WM_DESTROY)
			cls_ptr->detach();

		return result;
	}

	return DefWindowProc(hWnd, Msg, wParam, lParam);
} // End Of Fnc

LRESULT CALLBACK ClsBaseProc::call_dlg_proc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	ClsBaseProc *cls_ptr = (ClsBaseProc *) GetProp(hWnd, PROPKEY_CLASS);

	if (!cls_ptr) {
		if (Msg == WM_INITDIALOG)
			cls_ptr = (ClsBaseProc *) lParam;

		if (cls_ptr)
			cls_ptr->attach(hWnd);
	}

	if (cls_ptr) {
		LRESULT result = cls_ptr->wnd_proc(hWnd, Msg, wParam, lParam);

		SetDlgMsgResult(hWnd, Msg, result);

		if (Msg == WM_DESTROY)
			cls_ptr->detach();

		return result;
	}

	return DefWindowProc(hWnd, Msg, wParam, lParam);
} // End Of Fnc

LRESULT CALLBACK ClsBaseProc::call_proc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	ClsBaseProc *cls_ptr = (ClsBaseProc *) GetProp(hWnd, PROPKEY_CLASS);

	if (cls_ptr) {
		LRESULT result = cls_ptr->wnd_proc(hWnd, Msg, wParam, lParam);

		if (cls_ptr->m_is_dlg)
			SetDlgMsgResult(hWnd, Msg, result);

		if (Msg == WM_DESTROY)
			cls_ptr->detach();

		return result;
	}

	return DefWindowProc(hWnd, Msg, wParam, lParam);
} // End Of Fnc

/********************************************************************
;[Name]
;	get_hInstance
;[Action]
;	インスタンスハンドルを取得する
;[Input]
;	なし
;[Output]
;	インスタンスハンドル
;
;coding :__/__/__:1.00:___:__________________________________________
;update :__/__/__:_.__:___:__________________________________________
;coding :__/__/__:_.__:___:__________________________________________
;bugfix :__/__/__:_.__:___:__________________________________________
;sysfix :__/__/__:_.__:___:__________________________________________
[MainTopic]
********************************************************************/
HINSTANCE ClsBaseProc::get_hInstance()
{
	return m_hInstance;
} // End Of Fnc

/********************************************************************
;[Name]
;	get_hWnd
;[Action]
;	ウィンドウズハンドルを取得する
;[Input]
;	なし
;[Output]
;	ウィンドウズハンドル
;
;coding :__/__/__:1.00:___:__________________________________________
;update :__/__/__:_.__:___:__________________________________________
;coding :__/__/__:_.__:___:__________________________________________
;bugfix :__/__/__:_.__:___:__________________________________________
;sysfix :__/__/__:_.__:___:__________________________________________
[MainTopic]
********************************************************************/
HWND ClsBaseProc::get_hWnd()
{
	return m_hWnd;
} // End Of Fnc
