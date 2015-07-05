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
;	�x�[�X�v���V�[�W���N���X
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
	// �R���X�g���N�^
	ClsBaseProc();
	
	// �f�X�g���N�^
	~ClsBaseProc();
	
	BOOL attach(HWND hwnd);
	
	HWND detach();
	
	// �C���X�^���X�n���h���擾����
	HINSTANCE get_hInstance();

private:
	static HINSTANCE m_hInstance;
	BOOL m_is_dlg;
	
	// �E�B���h�E�v���V�[�W��
	virtual LRESULT wnd_proc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) = 0;

public:
	friend BOOL regist_base_proc(HINSTANCE hInstance);
	
	// �E�B���h�E�Y�n���h���擾����
	HWND get_hWnd();
	
	static LRESULT CALLBACK call_wnd_proc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK call_mdi_proc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK call_dlg_proc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK call_proc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
};

#endif //_base_wnd_h_
