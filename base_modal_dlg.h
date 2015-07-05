#ifndef _base_modal_dlg_h_
#define _base_modal_dlg_h_

#include "base_proc.h"
#include "command_cracker.h"

/********************************************************************
;[ClassName]
;	ClsBaseModalDlg
;[Description]
;	ベースモーダルダイアログクラス
;
;coding :__/__/__:1.00:___:__________________________________________
;update :__/__/__:_.__:___:__________________________________________
;coding :__/__/__:_.__:___:__________________________________________
;bugfix :__/__/__:_.__:___:__________________________________________
;sysfix :__/__/__:_.__:___:__________________________________________
[MainTopic]
********************************************************************/
class ClsBaseModalDlg : public ClsBaseProc
{
protected:
	int m_nResult;

	// コンストラクタ
	ClsBaseModalDlg();
	
	// デストラクタ
	~ClsBaseModalDlg();
	
	//
	INT_PTR dialog_box(LPCTSTR lpTempleteName, HWND hwndParent);
	
	// ダイアログ終了処理
	BOOL end_dialog();
	
	// ウィンドウプロシージャ
	virtual LRESULT wnd_proc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
};

#endif //_base_modal_dlg_h_
