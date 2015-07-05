#include "base_proc.h"

/********************************************************************
;[Name]
;	regist_base_proc
;[Action]
;	ウィンドウクラスの登録を行う
;[Input]
;	hInstance インスタンスハンドル
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
BOOL regist_base_proc(HINSTANCE hInstance)
{
	WNDCLASSEX wndc_ex;
	ATOM ret_wnd, ret_mdi;
	BOOL ret;

	memset(&wndc_ex, 0, sizeof(wndc_ex));

	wndc_ex.cbSize = sizeof(WNDCLASSEX);
	wndc_ex.style = 0;
	wndc_ex.lpfnWndProc = ClsBaseProc::call_wnd_proc;
	wndc_ex.cbClsExtra = 0;
	wndc_ex.cbWndExtra = 0;
	wndc_ex.hInstance = hInstance;
	wndc_ex.hIcon = NULL;
	wndc_ex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndc_ex.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
	wndc_ex.lpszMenuName = NULL;
	wndc_ex.lpszClassName = BASE_WND;
	wndc_ex.hIconSm = NULL;

	ret_wnd = RegisterClassEx(&wndc_ex);

	wndc_ex.lpfnWndProc = ClsBaseProc::call_mdi_proc;
	wndc_ex.lpszClassName = BASE_MDI;

	ret_mdi = RegisterClassEx(&wndc_ex);

	if((ret = (ret_wnd != 0 && ret_mdi != 0)))
	{
		ClsBaseProc::m_hInstance = hInstance;
	} // End Of If
	
	return ret;
} // End Of Fnc
