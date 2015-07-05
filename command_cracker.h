#ifndef _command_cracker_h_
#define _command_cracker_h_

#define HANDLE_CMD(hwnd, id, fn) \
	case (id): return (fn)((hwnd), (hwndCtl), (codeNotify))

#endif //_command_cracker_h_
