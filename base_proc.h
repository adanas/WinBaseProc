#ifndef _base_proc_h_
#define _base_proc_h_

#include <windows.h>
#include <windowsx.h>
#include <tchar.h>

#define BASE_WND		_T("base_wnd_proc")
#define BASE_MDI		_T("base_mdi_proc")

/********************************************************************
;[ClassName]
;	ClsBaseProc
;[Description]
;	ベースプロシージャクラス
;
;coding :__/__/__:1.00:___:__________________________________________
;update :__/__/__:_.__:___:__________________________________________
;coding :__/__/__:_.__:___:__________________________________________
;bugfix :__/__/__:_.__:___:__________________________________________
;sysfix :__/__/__:_.__:___:__________________________________________
[MainTopic]
********************************************************************/
class ClsBaseProc
{
protected:
	HWND m_hWnd;
	WNDPROC m_org_proc;

protected:
	// コンストラクタ
	ClsBaseProc();
	
	// デストラクタ
	~ClsBaseProc();
	
	BOOL attach(HWND hwnd);
	
	HWND detach();
	
	// インスタンスハンドル取得処理
	HINSTANCE get_hInstance();

private:
	static HINSTANCE m_hInstance;
	BOOL m_is_dlg;
	
	// ウィンドウプロシージャ
	virtual LRESULT wnd_proc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) = 0;

public:
	friend BOOL regist_base_proc(HINSTANCE hInstance);
	
	// ウィンドウズハンドル取得処理
	HWND get_hWnd();
	
	static LRESULT CALLBACK call_wnd_proc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK call_mdi_proc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK call_dlg_proc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK call_proc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
};

#endif //_base_wnd_h_
