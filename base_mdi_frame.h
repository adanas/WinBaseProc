#ifndef _base_mdi_frame_h_
#define _base_mdi_frame_h_

#include "base_proc.h"

/********************************************************************
;[ClassName]
;	ClsBaseMDIFrame
;[Description]
;	ベースMDIフレームクラス
;
;coding :__/__/__:1.00:___:__________________________________________
;update :__/__/__:_.__:___:__________________________________________
;coding :__/__/__:_.__:___:__________________________________________
;bugfix :__/__/__:_.__:___:__________________________________________
;sysfix :__/__/__:_.__:___:__________________________________________
[MainTopic]
********************************************************************/
class ClsBaseMDIFrame : public ClsBaseProc
{
protected:
	HWND m_hwndClient;

protected:
	// コンストラクタ
	ClsBaseMDIFrame();
	
	// デストラクタ
	~ClsBaseMDIFrame();
	
	// ウィンドウ作成処理
	BOOL create_wnd(DWORD dwExStyle, LPCTSTR lpWindowName, DWORD dwStyle,
		int x, int y, int width, int height, HWND hwndParent, HMENU hMenu);
	
	// ウィンドウ破棄処理
	void destroy_wnd();
	
	// 子ウィンドウ作成処理
	BOOL create_client(HANDLE hWindowMenu, UINT idFirstChild);
	
	// 
	HWND get_hwndClient();
	
	//
	WORD cascade_window(UINT cKids, const HWND *lpKids);
	
	//
	WORD tile_window_v(UINT cKids, const HWND *lpKids);
	
	//
	WORD tile_window_h(UINT cKids, const HWND *lpKids);
	
	//
	UINT arrange_iconic();
	
	// ウィンドウプロシージャ
	virtual LRESULT wnd_proc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
	
	// 
	virtual BOOL Msg_OnEraseBkgnd(HWND hWnd, HDC hdc);
};

#endif //_base_mdi_frame_h_
