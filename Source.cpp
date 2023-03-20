#include <Windows.h>
#include "Header.h"
#include "Measurement.h"
/ttt

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow)
{
	WNDCLASS wnd = NewWndClass((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), hInst, 
		LoadIcon(NULL, IDI_QUESTION), L"MainWin", mainProc);
	if (!RegisterClassW(&wnd)) { return -1; }
	MSG wndMsg = { 0 };

	CreateWindow(L"MainWin", L"Pohibkoanalizator v 0.1", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 710, 400, NULL, NULL, NULL, NULL);
	while (GetMessage(&wndMsg, NULL, NULL, NULL)) 
	{
		TranslateMessage(&wndMsg);

		DispatchMessage(&wndMsg);
		

	}
	return 0;
}
 
WNDCLASS NewWndClass(HBRUSH BGcol, HCURSOR cursor, HINSTANCE hInst, HICON icon, LPCWSTR name, WNDPROC procedure)
{
	WNDCLASS WC{ 0 };
	WC.hCursor = cursor;
	WC.hIcon = icon;
	WC.hInstance = hInst;
	WC.lpszClassName = name;
	WC.hbrBackground = BGcol;
	WC.lpfnWndProc = procedure;

	return WC;
}

LRESULT CALLBACK mainProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	int read;
	int n;
	switch (msg)
	{
	case WM_COMMAND:
		switch (wp) {
		case menuClick1:
			MessageBoxA(hWnd, "was clicked", "menu", MB_OK);
			break;
		case helpClick1:
			MessageBoxA(hWnd, "Pohibkoanalizator V0.1 \r\n All rights reserved \r\n ©2020-2023, Serhii Tarasenko" , "About", MB_OK);
			break;
		case helpClick2:
			MessageBoxA(hWnd, "Insert your data in the top box, like:\r\n 1\r\n 2\r\n 3\r\n 4\r\n and click <Calculate> ", "Instruction", MB_OK);
			break;
		case submenu1:
			
			//aver(Buffer, read);
			//parcer(Buffer);
			//SetWindowTextA(editVar2, Buffer);
			break;
		case buttonClick:
			//MessageBoxA(hWnd, "was clicked","button", MB_OK);
			//SetWindowTextA(editVar1, "nice");
			read = GetWindowTextA(editVar1, Buffer, 15);
			SetWindowTextA(editVar2, output(Buffer, read));
			break;
		default: break;
		}
	break;
	case WM_CREATE:
		addMenu(hWnd);
		addWigets(hWnd);
		break;
	case WM_DESTROY: 
		PostQuitMessage(0);
		break;

	default: return DefWindowProc(hWnd, msg, wp, lp);
	}
 }
void addMenu(HWND hWnd)
{
	HMENU RootMenu = CreateMenu();
	HMENU HelpMenu = CreateMenu();

	HMENU HelpSubMenu = CreateMenu();
	HMENU SubMenu = CreateMenu();

	HMENU SubMenuAction= CreateMenu();
	//HMENU HelpSubMenuAction = CreateMenu();

	

	AppendMenu(SubMenuAction, MF_STRING, menuClick1, L" Sub menu");
	//AppendMenu(HelpSubMenuAction, MF_STRING, menuClick1, L" Sub menu");

	AppendMenu(SubMenu, MF_STRING, submenu1, L" test");
	AppendMenu(SubMenu, MF_POPUP, (UINT_PTR)SubMenuAction, L" test #2");
	AppendMenu(HelpSubMenu, MF_POPUP, helpClick1, L" About");
	AppendMenu(HelpSubMenu, MF_POPUP, helpClick2, L" Instuction");


	AppendMenu(RootMenu, MF_POPUP, (UINT_PTR)SubMenu, L" Menu");
	AppendMenu(RootMenu, MF_POPUP, (UINT_PTR)HelpSubMenu, L" Help");

	SetMenu(hWnd, RootMenu);

}

void addWigets(HWND hWnd)
{
	CreateWindowA("static", "Calculation data:", WS_VISIBLE | WS_CHILD, 5, 5, 480, 20, hWnd, NULL, NULL, NULL);
	editVar1 = CreateWindowA("edit", "", WS_VISIBLE | WS_CHILD | ES_MULTILINE| WS_VSCROLL, 5, 30, 400, 100, hWnd, NULL, NULL, NULL);
	editVar2 = CreateWindowA("edit", "", WS_VISIBLE | WS_CHILD | ES_MULTILINE | WS_VSCROLL, 5, 161, 400, 100, hWnd, NULL, NULL, NULL);

	CreateWindowA("static", "Systematic inaccuracy:", WS_VISIBLE | WS_CHILD, 420, 30, 160, 20, hWnd, NULL, NULL, NULL);
	SysErrorWin = CreateWindowA("edit", "0", WS_VISIBLE | WS_CHILD, 580, 30, 100, 20, hWnd, NULL, NULL, NULL);

	CreateWindowA("button", "Calculate", WS_VISIBLE | WS_CHILD, 5, 135, 400, 20, hWnd, (HMENU)buttonClick, NULL, NULL);
}
void parcer(char* beffer)
{
	
	for(int i = 0; i < 15; ++i)
		if (beffer[i] == '\n')
		{
			beffer[i] = '\n';
		}
}


