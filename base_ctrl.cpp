#include "base_ctrl.h"

/********************************************************************
;[Name]
;	ClsBaseCtrl
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
ClsBaseCtrl::ClsBaseCtrl()
{
	m_isCreate = FALSE;
} // End Of Fnc

/********************************************************************
;[Name]
;	~ClsBaseCtrl
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
ClsBaseCtrl::~ClsBaseCtrl()
{
} // End Of Fnc

/********************************************************************
;[Name]
;	create_ctrl
;[Action]
;	コントロールを作成する
;[Input]
;	dwExStyle		拡張スタイル
;	lpClassName		クラス名
;	dwStyle			ウィンドウスタイル
;	x				x座標
;	y				y座標
;	width			コントロールの幅
;	height			コントロールの高さ
;	hwndParent		親ウィンドウハンドル
;	id				コントロールID
;[Output]
;	処理結果
;
;coding :__/__/__:1.00:___:__________________________________________
;update :__/__/__:_.__:___:__________________________________________
;coding :__/__/__:_.__:___:__________________________________________
;bugfix :__/__/__:_.__:___:__________________________________________
;sysfix :__/__/__:_.__:___:__________________________________________
[MainTopic]
********************************************************************/
BOOL ClsBaseCtrl::create_ctrl(DWORD dwExStyle, LPCTSTR lpClassName, DWORD dwStyle,
							  int x, int y, int width, int height, HWND hwndParent, UINT id)
{
	if(m_hWnd)
	{
		return FALSE;
	} // End Of If
	
	m_isCreate = attach(CreateWindowEx(dwExStyle, lpClassName, NULL, dwStyle,
		x, y, width, height, hwndParent, (HMENU) id, get_hInstance(), NULL));

	return m_isCreate;
} // End Of Fnc

/********************************************************************
;[Name]
;	create_ctrl
;[Action]
;	コントロールを作成する
;[Input]
;	hWnd	ウィンドウハンドル
;[Output]
;	処理結果
;
;coding :__/__/__:1.00:___:__________________________________________
;update :__/__/__:_.__:___:__________________________________________
;coding :__/__/__:_.__:___:__________________________________________
;bugfix :__/__/__:_.__:___:__________________________________________
;sysfix :__/__/__:_.__:___:__________________________________________
[MainTopic]
********************************************************************/
BOOL ClsBaseCtrl::create_ctrl(HWND hWnd)
{
	if(m_hWnd)
	{
		return FALSE;
	} // End Of If
	
	return attach(hWnd);
} // End Of Fnc

/********************************************************************
;[Name]
;	destroy_ctrl
;[Action]
;	コントロールを破棄する
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
void ClsBaseCtrl::destroy_ctrl()
{
	if(m_hWnd)
	{
		if(m_isCreate)
		{
			DestroyWindow(m_hWnd);
		}
		else
		{
			detach();
		} // End Of If
		
		m_hWnd = NULL;
	} // End Of If
} // End Of Fnc

/********************************************************************
;[Name]
;	wnd_proc
;[Action]
;	ウィンドウプロシージャ
;[Input]
;	hWnd	ウィンドウハンドル
;	Msg		メッセージ
;	wParam	WPARAM
;	lParam	LPARAM
;[Output]
;	処理結果
;
;coding :__/__/__:1.00:___:__________________________________________
;update :__/__/__:_.__:___:__________________________________________
;coding :__/__/__:_.__:___:__________________________________________
;bugfix :__/__/__:_.__:___:__________________________________________
;sysfix :__/__/__:_.__:___:__________________________________________
[MainTopic]
********************************************************************/
LRESULT ClsBaseCtrl
::wnd_proc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	return CallWindowProc(m_org_proc, hWnd, Msg, wParam, lParam);
} // End Of Fnc
