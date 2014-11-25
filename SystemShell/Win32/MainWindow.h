#include "pch.h"

class MainWindow
{
public:
	bool Create();
	bool Destory();


protected:
private:
	HWND hWnd = NULL;
	wchar_t* szTitle = L"Demo";
};