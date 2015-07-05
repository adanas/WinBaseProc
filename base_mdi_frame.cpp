#include "base_mdi_frame.h"

/********************************************************************
;[Name]
;	ClsBaseMDIFrame
;[Action]
;	�R���X�g���N�^
;[Input]
;	�Ȃ�
;[Output]
;	�Ȃ�
;
;coding :__/__/__:1.00:___:__________________________________________
;update :__/__/__:_.__:___:__________________________________________
;coding :__/__/__:_.__:___:__________________________________________
;bugfix :__/__/__:_.__:___:__________________________________________
;sysfix :__/__/__:_.__:___:__________________________________________
[MainTopic]
********************************************************************/
ClsBaseMDIFrame::ClsBaseMDIFrame()
{
	m_hwndClient = NULL;
} // End Of Fnc

/********************************************************************
;[Name]
;	~ClsBaseMDIFrame
;[Action]
;	�f�X�g���N�^
;[Input]
;	�Ȃ�
;[Output]
;	�Ȃ�
;
;coding :__/__/__:1.00:___:__________________________________________
;update :__/__/__:_.__:___:__________________________________________
;coding :__/__/__:_.__:___:__________________________________________
;bugfix :__/__/__:_.__:___:__________________________________________
;sysfix :__/__/__:_.__:___:__________________________________________
[MainTopic]
********************************************************************/
ClsBaseMDIFrame::~ClsBaseMDIFrame()
{
} // End Of Fnc

/********************************************************************
;[Name]
;	create_wnd
;[Action]
;	�E�B���h�E���쐬����
;[Input]
;	dwExStyle		�g���X�^�C��
;	lpWindowName	�E�B���h�E�^�C�g��
;	dwStyle			�E�B���h�E�X�^�C��
;	x				x���W
;	y				y���W
;	width			��
;	height			����
;	hwndParent		�e�E�B���h�E�n���h��
;	hMenu			���j���[�n���h��
;[Output]
;	��������
;
;coding :__/__/__:1.00:___:__________________________________________
;update :__/__/__:_.__:___:__________________________________________
;coding :__/__/__:_.__:___:__________________________________________
;bugfix :__/__/__:_.__:___:__________________________________________
;sysfix :__/__/__:_.__:___:__________________________________________
[MainTopic]
********************************************************************/
BOOL ClsBaseMDIFrame::create_wnd(DWORD dwExStyle, LPCTSTR lpWindowName, DWORD dwStyle,
							int x, int y, int width, int height, HWND hwndParent, HMENU hMenu)
{
	if(m_hWnd)
	{
		return FALSE;
	} // End Of If

	if(CreateWindowEx(dwExStyle, BASE_WND, lpWindowName, dwStyle,
		x, y, width, height, hwndParent, hMenu, get_hInstance(), this))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	} // End Of If
} // End Of Fnc

/********************************************************************
;[Name]
;	destroy_wnd
;[Action]
;	�E�B���h�E��j������
;[Input]
;	�Ȃ�
;[Output]
;	�Ȃ�
;
;coding :__/__/__:1.00:___:__________________________________________
;update :__/__/__:_.__:___:__________________________________________
;coding :__/__/__:_.__:___:__________________________________________
;bugfix :__/__/__:_.__:___:__________________________________________
;sysfix :__/__/__:_.__:___:__________________________________________
[MainTopic]
********************************************************************/
void ClsBaseMDIFrame::destroy_wnd()
{
	if(m_hwndClient)
	{
		DestroyWindow(m_hwndClient);
		m_hwndClient = NULL;
	} // End Of If

	if(m_hWnd)
	{
		DestroyWindow(m_hWnd);
		m_hWnd = NULL;
	} // End Of If
} // End Of Fnc

/********************************************************************
;[Name]
;	create_client
;[Action]
;	�q�E�B���h�E���쐬����
;[Input]
;	hWindowMenu		���j���[�n���h��
;	idFirstChild	�qID
;[Output]
;	��������
;
;coding :__/__/__:1.00:___:__________________________________________
;update :__/__/__:_.__:___:__________________________________________
;coding :__/__/__:_.__:___:__________________________________________
;bugfix :__/__/__:_.__:___:__________________________________________
;sysfix :__/__/__:_.__:___:__________________________________________
[MainTopic]
********************************************************************/
BOOL ClsBaseMDIFrame
::create_client(HANDLE hWindowMenu, UINT idFirstChild)
{
	CLIENTCREATESTRUCT ccs;

	ccs.hWindowMenu = hWindowMenu;
	ccs.idFirstChild = idFirstChild;

	DWORD dwStyle = WS_CHILD | WS_CLIPCHILDREN | WS_VISIBLE/* | MDIS_ALLCHILDSTYLES*/;

	m_hwndClient = CreateWindowEx(0, _T("MDICLIENT"), NULL, dwStyle,
		0, 0, 0, 0, m_hWnd, NULL, get_hInstance(), &ccs);

	return TRUE;
} // End Of Fnc

HWND ClsBaseMDIFrame::get_hwndClient()
{
	return m_hwndClient;
} // End Of Fnc

WORD ClsBaseMDIFrame::cascade_window(UINT cKids, const HWND *lpKids)
{
	if(!m_hwndClient)
	{
		return 0;
	} // End Of If

	RECT rc;
	GetClientRect(m_hWnd, &rc);

	return CascadeWindows(m_hwndClient, MDITILE_SKIPDISABLED, &rc, cKids, lpKids);
} // End Of Fnc

WORD ClsBaseMDIFrame::tile_window_v(UINT cKids, const HWND *lpKids)
{
	if(!m_hwndClient)
	{
		return 0;
	} // End Of If

	RECT rc;
	GetClientRect(m_hWnd, &rc);

	UINT wHow = MDITILE_SKIPDISABLED | MDITILE_VERTICAL;
	return TileWindows(m_hwndClient, wHow, &rc, cKids, lpKids);
} // End Of Fnc

WORD ClsBaseMDIFrame::tile_window_h(UINT cKids, const HWND *lpKids)
{
	if(!m_hwndClient)
	{
		return 0;
	} // End Of If

	RECT rc;
	GetClientRect(m_hWnd, &rc);

	UINT wHow = MDITILE_SKIPDISABLED | MDITILE_HORIZONTAL;
	return TileWindows(m_hwndClient, wHow, &rc, cKids, lpKids);
} // End Of Fnc

UINT ClsBaseMDIFrame::arrange_iconic()
{
	return ArrangeIconicWindows(m_hwndClient);
} // End Of Fnc

LRESULT ClsBaseMDIFrame::wnd_proc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	switch(Msg)
	{
	HANDLE_MSG(hWnd, WM_ERASEBKGND, Msg_OnEraseBkgnd);
	} // End Of Switch
	
	return DefFrameProc(hWnd, m_hwndClient, Msg, wParam, lParam);
} // End Of Fnc

BOOL ClsBaseMDIFrame::Msg_OnEraseBkgnd(HWND hWnd, HDC hdc)
{
	RECT rc;

	GetClientRect(hWnd, &rc);

	return FillRect(hdc, &rc, (HBRUSH) (COLOR_APPWORKSPACE + 1));
} // End Of Fnc
