#include "keyHook.h"

extern KeyHook* keyHook = new KeyHook();

int setKeyHook()
{
    hook = SetWindowsHookExW(WH_KEYBOARD_LL, keyHookProc, GetModuleHandle(nullptr), NULL);
}

LRESULT keyHookProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    KBDLLHOOKSTRUCT* key = (KBDLLHOOKSTRUCT*) lParam;
    if(key ->vkCode == VK_F1)
    {
        emit keyHook ->keyDown();
    }
    return CallNextHookEx(nullptr, nCode, wParam, lParam);
}

void unloadKeyHook()
{
    UnhookWindowsHookEx(hook);
}
