#include "base/NativeApp.h"
#include "input/input_state.h"
#include "input/keycodes.h"
#include "util/const_map.h"
#include "KeyMap.h"
#include "ControlMapping.h"
#include "Windows/WndMainWindow.h"
#include "KeyboardDevice.h"
#include "../Common/CommonTypes.h"
#include "../Core/HLE/sceCtrl.h"
#include "WinUser.h"


// TODO: More keys need to be added, but this is more than
// a fair start.
std::map<int, int> windowsTransTable = InitConstMap<int, int>
	('A', NKCODE_A)
	('B', NKCODE_B)
	('C', NKCODE_C)
	('D', NKCODE_D)
	('E', NKCODE_E)
	('F', NKCODE_F)
	('G', NKCODE_G)
	('H', NKCODE_H)
	('I', NKCODE_I)
	('J', NKCODE_J)
	('K', NKCODE_K)
	('L', NKCODE_L)
	('M', NKCODE_M)
	('N', NKCODE_N)
	('O', NKCODE_O)
	('P', NKCODE_P)
	('Q', NKCODE_Q)
	('R', NKCODE_R)
	('S', NKCODE_S)
	('T', NKCODE_T)
	('U', NKCODE_U)
	('V', NKCODE_V)
	('W', NKCODE_W)
	('X', NKCODE_X)
	('Y', NKCODE_Y)
	('Z', NKCODE_Z)
	('0', NKCODE_0)
	('1', NKCODE_1)
	('2', NKCODE_2)
	('3', NKCODE_3)
	('4', NKCODE_4)
	('5', NKCODE_5)
	('6', NKCODE_6)
	('7', NKCODE_7)
	('8', NKCODE_8)
	('9', NKCODE_9)
	(VK_OEM_PERIOD, NKCODE_PERIOD)
	(VK_OEM_COMMA, NKCODE_COMMA)
	(VK_NUMPAD0, NKCODE_NUMPAD_0)
	(VK_NUMPAD1, NKCODE_NUMPAD_1)
	(VK_NUMPAD2, NKCODE_NUMPAD_2)
	(VK_NUMPAD3, NKCODE_NUMPAD_3)
	(VK_NUMPAD4, NKCODE_NUMPAD_4)
	(VK_NUMPAD5, NKCODE_NUMPAD_5)
	(VK_NUMPAD6, NKCODE_NUMPAD_6)
	(VK_NUMPAD7, NKCODE_NUMPAD_7)
	(VK_NUMPAD8, NKCODE_NUMPAD_8)
	(VK_NUMPAD9, NKCODE_NUMPAD_9)
	(VK_DECIMAL, NKCODE_NUMPAD_DOT)
	(VK_DIVIDE, NKCODE_NUMPAD_DIVIDE)
	(VK_MULTIPLY, NKCODE_NUMPAD_MULTIPLY)
	(VK_SUBTRACT, NKCODE_NUMPAD_SUBTRACT)
	(VK_ADD, NKCODE_NUMPAD_ADD)
	(VK_SEPARATOR, NKCODE_NUMPAD_COMMA)
	(VK_OEM_MINUS, NKCODE_MINUS)
	(VK_OEM_PLUS, NKCODE_PLUS)
	(VK_LCONTROL, NKCODE_CTRL_LEFT)
	(VK_RCONTROL, NKCODE_CTRL_RIGHT)
	(VK_LSHIFT, NKCODE_SHIFT_LEFT)
	(VK_RSHIFT, NKCODE_SHIFT_RIGHT)
	(VK_LMENU, NKCODE_ALT_LEFT)
	(VK_RMENU, NKCODE_ALT_RIGHT)
	(VK_BACK, NKCODE_BACK)
	(VK_SPACE, NKCODE_SPACE)
	(VK_ESCAPE, NKCODE_ESCAPE)
	(VK_UP, NKCODE_DPAD_UP)
	(VK_INSERT, NKCODE_INSERT)
	(VK_HOME, NKCODE_MOVE_HOME)
	(VK_PRIOR, NKCODE_PAGE_UP)
	(VK_NEXT, NKCODE_PAGE_DOWN)
	(VK_DELETE, NKCODE_DEL)
	(VK_END, NKCODE_MOVE_END)
	(VK_TAB, NKCODE_TAB)
	(VK_DOWN, NKCODE_DPAD_DOWN)
	(VK_LEFT, NKCODE_DPAD_LEFT)
	(VK_RIGHT, NKCODE_DPAD_RIGHT)
	(VK_CAPITAL, NKCODE_CAPS_LOCK)
	(VK_CLEAR, NKCODE_CLEAR)
	(VK_SNAPSHOT, NKCODE_SYSRQ)
	(VK_SCROLL, NKCODE_SCROLL_LOCK)
	(VK_OEM_1, NKCODE_SEMICOLON)
	(VK_OEM_2, NKCODE_SLASH)
	(VK_OEM_3, NKCODE_GRAVE)
	(VK_OEM_4, NKCODE_LEFT_BRACKET)
	(VK_OEM_5, NKCODE_BACKSLASH)
	(VK_OEM_6, NKCODE_RIGHT_BRACKET)
	(VK_OEM_7, NKCODE_APOSTROPHE)
	(VK_RETURN, NKCODE_ENTER)
	(VK_APPS, NKCODE_MENU) // Context menu key, let's call this "menu".
	(VK_PAUSE, NKCODE_BREAK)
	(VK_F1, NKCODE_F1)
	(VK_F2, NKCODE_F2)
	(VK_F3, NKCODE_F3)
	(VK_F4, NKCODE_F4)
	(VK_F5, NKCODE_F5)
	(VK_F6, NKCODE_F6)
	(VK_F7, NKCODE_F7)
	(VK_F8, NKCODE_F8)
	(VK_F9, NKCODE_F9)
	(VK_F10, NKCODE_F10)
	(VK_F11, NKCODE_F11)
	(VK_F12, NKCODE_F12)
	(VK_OEM_102, NKCODE_EXT_PIPE)
	(VK_LBUTTON, NKCODE_EXT_MOUSEBUTTON_1)
	(VK_RBUTTON, NKCODE_EXT_MOUSEBUTTON_2);

int KeyboardDevice::UpdateState(InputState &input_state) {
	// Nothing to do, all done in WM_INPUT
	return 0;
}
