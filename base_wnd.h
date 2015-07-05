#ifndef _base_wnd_h_
#define _base_wnd_h_

#include "base_proc.h"

/********************************************************************
;[ClassName]
;	ClsBaseWnd
;[Description]
;	�x�[�X�E�B���h�E�N���X
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
	// �R���X�g���N�^
	ClsBaseWnd();
	
	// �f�X�g���N�^
	~ClsBaseWnd();
	
	// �E�B���h�E�쐬����
	BOOL create_wnd(DWORD dwExStyle, LPCTSTR lpWindowName, DWORD dwStyle,
		int x, int y, int width, int height, HWND hwndParent, HMENU hMenu);
	
	// �E�B���h�E�j������
	void destroy_wnd();
	
	// �E�B���h�E�v���V�[�W��
	LRESULT wnd_proc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
};

#endif //_base_wnd_h_
