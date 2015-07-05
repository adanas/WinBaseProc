#ifndef _base_modal_dlg_h_
#define _base_modal_dlg_h_

#include "base_proc.h"
#include "command_cracker.h"

/********************************************************************
;[ClassName]
;	ClsBaseModalDlg
;[Description]
;	�x�[�X���[�_���_�C�A���O�N���X
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

	// �R���X�g���N�^
	ClsBaseModalDlg();
	
	// �f�X�g���N�^
	~ClsBaseModalDlg();
	
	//
	INT_PTR dialog_box(LPCTSTR lpTempleteName, HWND hwndParent);
	
	// �_�C�A���O�I������
	BOOL end_dialog();
	
	// �E�B���h�E�v���V�[�W��
	virtual LRESULT wnd_proc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
};

#endif //_base_modal_dlg_h_
