#ifndef _base_ctrl_h_
#define _base_ctrl_h_

#include "base_proc.h"

/********************************************************************
;[ClassName]
;	ClsBaseCtrl
;[Description]
;	ベースコントロールクラス
;
;coding :__/__/__:1.00:___:__________________________________________
;update :__/__/__:_.__:___:__________________________________________
;coding :__/__/__:_.__:___:__________________________________________
;bugfix :__/__/__:_.__:___:__________________________________________
;sysfix :__/__/__:_.__:___:__________________________________________
[MainTopic]
********************************************************************/
class ClsBaseCtrl : public ClsBaseProc
{
private:
	BOOL m_isCreate;

protected:
	// コンストラクタ
	ClsBaseCtrl();
	
	// デストラクタ
	~ClsBaseCtrl();
	
	// コントロール作成処理
	BOOL create_ctrl(DWORD dwExStyle, LPCTSTR lpClassName, DWORD dwStyle,
		int x, int y, int width, int height, HWND hwndParent, UINT id);
	
	// コントロール作成処理
	BOOL create_ctrl(HWND hWnd);
	
	// コントロール破棄処理
	void destroy_ctrl();
	
	// ウィンドウプロシージャ
	virtual LRESULT wnd_proc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
};

#endif //_base_ctrl_h_
