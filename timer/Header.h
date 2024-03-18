#pragma once
#pragma once

LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure);

#define ID_MENU_CLICKED 1001

void MainWndAddMenus(HWND hWnd);
WndAddMenus(HWND hWnd);
