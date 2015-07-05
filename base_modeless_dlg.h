#ifndef _base_modeless_dlg_h_
#define _base_modeless_dlg_h_

#include "base_proc.h"
#include "command_cracker.h"

/********************************************************************
;[ClassName]
;	ClsBaseModelessDlg
;[Description]
;	�x�[�X���[�h���X�_�C�A���O�N���X
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
	// �R���X�g���N�^
	ClsBaseModelessDlg();
	
	// �f�X�g���N�^
	~ClsBaseModelessDlg();
	
	// �_�C�A���O�쐬����
	BOOL create_dlg(LPCTSTR lpTempleteName, HWND hwndParent);
	
	// �_�C�A���O�j������
	void destroy_dlg();
	
	// �E�B���h�E�v���V�[�W��
	virtual LRESULT wnd_proc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
};

#endif //_base_modeless_dlg_h_
