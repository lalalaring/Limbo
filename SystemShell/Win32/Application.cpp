#include "Application.h"
#include "Limbo.h"
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CLOSE:
		//Limbo::Engine::Instance()->CallSystemCmd(SystemCmd_OnClose, 0, 0);
		//break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_SIZE:
		Limbo::Engine::Instance()->CallSystemCmd(SystemCmd_OnSize, wParam, lParam);
		break;
	case WM_CHAR:
		Limbo::Engine::Instance()->InputHandler((int)wParam);
		break;
	//case WM_TIMER:

	//	break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
bool Application::Create()
{


	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = GetModuleHandle(0);
	wcex.hIcon = NULL;// LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECT2));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;// MAKEINTRESOURCE(IDC_WIN32PROJECT2);
	wcex.lpszClassName = L"Win32App";
	wcex.hIconSm = NULL;//LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}
bool Application::Destory()
{
	UnregisterClass(L"Win32App", GetModuleHandle(0));
	return true;
}
int Application::Run()
{
	MSG msg;
	bool done = false;
	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		// 接收到WM_QUIT消息，退出程序. 
		if (msg.message == WM_QUIT)
		{
			done = true;
		}
		else
		{
			//result = bexit; //如果按了ESC,也退出程序

			Limbo::Engine::Instance()->Draw();
			//if (result)
			//{
			//	done = true;
			//}
		}
	}
	return (int)msg.wParam;
}