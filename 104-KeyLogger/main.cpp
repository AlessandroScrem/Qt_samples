#include <QCoreApplication>
#include <QDebug>
#include <QTime>
#include <QChar>
#include <iostream>
#include <Windows.h>
#pragma comment(lib, "user32.lib")

HHOOK hHook = NULL;

using namespace std;

void UpdateKeyState(BYTE *keystate, int keycode)
{
    keystate[keycode] = GetKeyState(keycode);
}

LRESULT CALLBACK  MyLowLevelKeyboardProc(int nCode, WPARAM wParam  ,LPARAM lParam)
{

    // wParam
    // can be one of the following messages:  WM_KEYDOWN, WM_KEYUP, WM_SYSKEYDOWN, or WM_SYSKEYUP.
    // lParam
    // A pointer to a KBDLLHOOKSTRUCT

    if(wParam != WM_KEYDOWN )
        return CallNextHookEx(hHook, nCode, wParam, lParam );


    qDebug() << "Key Pressed";

    // Get the key information
    KBDLLHOOKSTRUCT cKey = *((KBDLLHOOKSTRUCT*)lParam);

    wchar_t buffer[5];

    // get the keyboard state
    BYTE keyboard_state[256];
    GetKeyboardState(keyboard_state);
    UpdateKeyState(keyboard_state, VK_SHIFT);
    UpdateKeyState(keyboard_state, VK_CAPITAL);
    UpdateKeyState(keyboard_state, VK_CONTROL);
    UpdateKeyState(keyboard_state, VK_MENU);

    // get keyboard layout
    HKL keyboard_layout = GetKeyboardLayout(0);

    // get the name
    char lpszName[0x100] = {0};

    DWORD dwMsg = 1;
    dwMsg += cKey.scanCode << 16;
    dwMsg += cKey.flags << 24;

    int i = GetKeyNameText(dwMsg, (LPTSTR)lpszName, 255);

    // try to convert key info
    int result = ToUnicodeEx(cKey.vkCode, cKey.scanCode, keyboard_state, buffer, 4, 0, keyboard_layout);
    buffer[4] = L'\0';

    // print the output
    qDebug() << "key: " << cKey.vkCode << " " << QString::fromUtf16((ushort*)buffer) << " " << QString::fromUtf16((ushort*)lpszName);

    return CallNextHookEx(hHook, nCode, wParam, lParam );
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    hHook = SetWindowsHookEx(WH_KEYBOARD_LL, MyLowLevelKeyboardProc, NULL, 0);
    if(hHook == NULL)
    {
        qDebug() << "Hook Failed!";
    }

    return a.exec();
}
