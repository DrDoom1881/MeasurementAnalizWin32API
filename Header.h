#pragma once

LRESULT CALLBACK mainProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
WNDCLASS NewWndClass(HBRUSH BGcol, HCURSOR cursor, HINSTANCE hInst, HICON icon, LPCWSTR name, WNDPROC procedure);

enum callBackEvents {buttonClick, menuClick1, submenu1, helpClick1, helpClick2};

HWND editVar1, editVar2, SysErrorWin;

char* Buffer = new char[256];

void addMenu(HWND hWnd);
void addWigets(HWND hWnd);
void parcer(char* beffer);
