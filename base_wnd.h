#ifndef _base_wnd_h_
#define _base_wnd_h_

#include "base_proc.h"

/********************************************************************
;[ClassName]
;	ClsBaseWnd
;[Description]
;	ベースウィンドウクラス
;
;coding :__/__/__:1.00:___:__________________________________________
;update :__/__/__:_.__:___:__________________________________________
;coding :__/__/__:_.__:___:__________________________________________
;bugfix :__/__/__:_.__:___:__________________________________________
;sysfix :__/__/__:_.__:___:__________________________________________
[MainTopic]
********************************************************************/
class ClsBaseWnd : public ClsBaseProc
{
protected:
	// コンストラクタ
	ClsBaseWnd();
	
	// デストラクタ
	~ClsBaseWnd();
	
	// ウィンドウ作成処理
	BOOL create_wnd(DWORD dwExStyle, LPCTSTR lpWindowName, DWORD dwStyle,
		int x, int y, int width, int height, HWND hwndParent, HMENU hMenu);
	
	// ウィンドウ破棄処理
	void destroy_wnd();
	
	// ウィンドウプロシージャ
	LRESULT wnd_proc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
};

#endif //_base_wnd_h_
