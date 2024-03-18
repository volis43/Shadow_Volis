#include <iostream>
#include <Windows.h>
#include "Header.h"
#include "resource.h"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstt, LPSTR args, int ncmdshow)
{
    WNDCLASS SoftwareMainClass = NewWindowClass((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), hInst, 
        LoadIcon(hInst, MAKEINTRESOURCE(IDB_PNG1)), L"MainWndClass", SoftwareMainProcedure);

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
    case WM_COMMAND:
        switch (wp)
        {
        case OnMenuAction1:
            MessageBoxA(hWnd, "Menu click", "Menu startet", MB_OK);
            break;
        case OnMenuAction2:
            MessageBoxA(hWnd, "Menu click", "Menu startet", MB_OK);
            break;
        case OnMenuAction3:
            MessageBoxA(hWnd, "Menu click", "Menu startet", MB_OK);
            break;
        case OnButtonClicked1:
            MessageBoxA(hWnd,"Set result", "Shadow Volis", MB_OK);
            break;
        case OnExitMenu:
            PostQuitMessage(0);
            break;
        default: break;
        }
        break;
    case WM_CREATE:
        MainWndAddMenus(hWnd);
        MainWndAddWidget(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default: return DefWindowProc(hWnd, msg, wp, lp);
    }
    return 0;
}

void MainWndAddMenus(HWND hWnd)
{
    HMENU RootMenu = CreateMenu();
    HMENU SubMenu = CreateMenu();

    AppendMenu(RootMenu, MF_STRING, OnMenuAction1, L"Shadow Menu 1");
    AppendMenu(SubMenu, MF_STRING, OnMenuAction2, L"Shadow Menu 2");
    AppendMenu(SubMenu, MF_STRING, OnMenuAction3, L"Shadow Menu 3");
    
    /*AppendMenu(RootMenu, MF_SEPARATOR, NULL, NULL);*/

    AppendMenu(RootMenu, MF_POPUP, (UINT_PTR)SubMenu, L"Saving");
    
    AppendMenu(RootMenu, MF_STRING, OnExitMenu, L"Exit");

    SetMenu(hWnd, RootMenu);
}

void MainWndAddWidget(HWND hWnd)
{
    CreateWindowA("static", "Shadow-Volis", WS_VISIBLE | WS_CHILD | ES_CENTER, 5, 5, 490, 20, hWnd, NULL, NULL, NULL);

    CreateWindowA("edit", "c++", WS_VISIBLE | WS_CHILD, 5, 30, 450, 20, hWnd, NULL, NULL, NULL);

    CreateWindowA("button", "Save result", WS_VISIBLE | WS_CHILD | ES_CENTER, 5, 60, 120, 20, hWnd, (HMENU)OnButtonClicked1, NULL, NULL, NULL);
    
}