#include "pch.h"

class MainWindow
{
public:
	bool Create();
	bool Destory();

	int32_t GetHwnd(){ return (int32_t)hWnd; }
protected:
private:
	HWND hWnd = NULL;
	wchar_t* szTitle = L"Demo";
};