#include "MainWindow.h"


bool MainWindow::Create()
{
	hWnd = CreateWindow(L"Win32App", szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, 800, 600, NULL, NULL, GetModuleHandle(0), NULL);

	if (!hWnd)
	{
		return FALSE;
	}
	ShowWindow(hWnd, SW_NORMAL);
	UpdateWindow(hWnd);
}

