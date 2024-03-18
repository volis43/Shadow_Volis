#include <iostream>
#include <Windows.h>

LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstt, LPSTR args, int ncmdshow)
{
    WNDCLASS SoftwareMainClass = NewWindowClass((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), hInst, LoadIcon(NULL, IDI_QUESTION),
        L"MainWndClass", SoftwareMainProcedure);

    if (!RegisterClassW(&SoftwareMainClass)) { return -1; }
    MSG SoftwareMainMessage = { 0 };

    CreateWindow(SoftwareMainClass.lpszClassName, L"Shadow_Timer_C++", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 250, NULL, NULL, hInst, NULL);

    while (GetMessage(&SoftwareMainMessage, NULL, NULL, NULL))
    {
        TranslateMessage(&SoftwareMainMessage);
        DispatchMessage(&SoftwareMainMessage);
    }
    return 0;
}

WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure)
{
    WNDCLASS NWC = { 0 };

    NWC.hIcon = Icon;
    NWC.hCursor = Cursor;
    NWC.hInstance = hInst;
    NWC.lpszClassName = Name;
    NWC.hbrBackground = BGColor;
    NWC.lpfnWndProc = Procedure;

    return NWC;
}

LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
    switch (msg)
    {
    case WM_CREATE:
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default: return DefWindowProc(hWnd, msg, wp, lp);
    }
}
