#ifndef _base_ctrl_h_
#define _base_ctrl_h_

#include "base_proc.h"

/********************************************************************
;[ClassName]
;	ClsBaseCtrl
;[Description]
;	�x�[�X�R���g���[���N���X
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
	// �R���X�g���N�^
	ClsBaseCtrl();
	
	// �f�X�g���N�^
	~ClsBaseCtrl();
	
	// �R���g���[���쐬����
	BOOL create_ctrl(DWORD dwExStyle, LPCTSTR lpClassName, DWORD dwStyle,
		int x, int y, int width, int height, HWND hwndParent, UINT id);
	
	// �R���g���[���쐬����
	BOOL create_ctrl(HWND hWnd);
	
	// �R���g���[���j������
	void destroy_ctrl();
	
	// �E�B���h�E�v���V�[�W��
	virtual LRESULT wnd_proc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
};

#endif //_base_ctrl_h_
