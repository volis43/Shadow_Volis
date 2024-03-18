#include <iostream>
#include <string>
#include <windows.h>
//#include "Header.h"
//
//
//int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow)
//{
//    WNDCLASS SoftwareMainClass = {};
//
//    SoftwareMainClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
//    SoftwareMainClass.hCursor = LoadCursor(NULL, IDC_ARROW);
//    SoftwareMainClass.hInstance = hInst;
//    SoftwareMainClass.lpszClassName = L"MainWndClass";
//    SoftwareMainClass.lpfnWndProc = SoftwareMainProcedure;
//
//    if (!RegisterClassW(&SoftwareMainClass)) { return -1; }
//
//    MSG SoftwareMainMessage = { 0 };
//
//    CreateWindow(L"MainWndClass", L"Shadow c++", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 250, NULL, NULL, hInst, NULL);
//
//    while (GetMessage(&SoftwareMainMessage, NULL, 0, 0))
//    {
//        TranslateMessage(&SoftwareMainMessage);
//        DispatchMessage(&SoftwareMainMessage);
//    }
//
//    return 0;
//}
//
//WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure)
//{
//    WNDCLASS NWC = {};
//    NWC.hIcon = Icon;
//    NWC.hCursor = Cursor;
//    NWC.hInstance = hInst;
//    NWC.lpszClassName = Name;
//    NWC.hbrBackground = BGColor;
//    NWC.lpfnWndProc = Procedure;
//
//    return NWC;
//}
//
//LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
//{
//    switch (msg)
//    {
//    case WM_COMMAND:
//        switch (wp)
//        {
//        case OnMenuClicked:
//            MessageBoxA(hWnd, "Menu was clicked!", "Menu worked", MB_OK);
//            break;
//        default: break;
//        }
//
//    case WM_CREATE:
//        MainWndAddMenus(hWnd);
//        break;
//    case WM_DESTROY:
//        PostQuitMessage(0);
//        break;
//    default:
//        return DefWindowProc(hWnd, msg, wp, lp);
//    }
//    return 0; 
//}
//
//void MainWndAddMenus(HWND hWnd)
//{
//    HMENU RootMenu = CreateMenu();
//
//    AppendMenu(RootMenu, MF_STRING, OnMenuClicked, L"OUR MENU");
//    SetMenu(hWnd, RootMenu);
//}

int main()
{
	int sec = 0;
	int min = 0;
	int hour = 0;

	for (int i = 0;; sec++)
	{
		system("cls");
		std::cout << "seconds " << sec << std::endl;
		
		if (sec == 60
		{
			min++;
			sec = 0;
		}
		std::cout << "min " << min << std::endl;

		if (min == 60)
		{
			hour++;
			min = 0;
			
		}
		std::cout << "hour " << hour << std::endl;
		Sleep(970);
	}
	
	return 0;
}

// ------
//int main()
//{
//	int sec = 0;
//	int min = 0;
//	int hour = 0;
//
//	for (int i = 0;; sec++)
//	{
//		system("cls");
//		std::cout << "seconds " << sec << std::endl;
//
//		if (sec == 60)
//		{
//			min++;
//			sec = 0;
//		}
//		std::cout << "min " << min << std::endl;
//
//		if (min == 60)
//		{
//			hour++;
//			min = 0;
//
//		}
//		std::cout << "hour " << hour << std::endl;
//		Sleep(970);
//	}
//
//	return 0;
//}