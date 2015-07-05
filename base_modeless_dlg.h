#ifndef _base_modeless_dlg_h_
#define _base_modeless_dlg_h_

#include "base_proc.h"
#include "command_cracker.h"

/********************************************************************
;[ClassName]
;	ClsBaseModelessDlg
;[Description]
;	ベースモードレスダイアログクラス
;
;coding :__/__/__:1.00:___:__________________________________________
;update :__/__/__:_.__:___:__________________________________________
;coding :__/__/__:_.__:___:__________________________________________
;bugfix :__/__/__:_.__:___:__________________________________________
;sysfix :__/__/__:_.__:___:__________________________________________
[MainTopic]
********************************************************************/
class ClsBaseModelessDlg : public ClsBaseProc
{
protected:
	// コンストラクタ
	ClsBaseModelessDlg();
	
	// デストラクタ
	~ClsBaseModelessDlg();
	
	// ダイアログ作成処理
	BOOL create_dlg(LPCTSTR lpTempleteName, HWND hwndParent);
	
	// ダイアログ破棄処理
	void destroy_dlg();
	
	// ウィンドウプロシージャ
	virtual LRESULT wnd_proc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
};

#endif //_base_modeless_dlg_h_
