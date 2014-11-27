#include <windows.h>
#include "Application.h"

#include "MainWindow.h"
#include "Limbo.h"
using namespace Limbo;
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	Application app;
	app.Create();
	MainWindow mw;
	mw.Create();
	Engine::Instance()->Create(mw.GetHwnd());
	app.Run();
	Engine::Instance()->Destory();
	app.Destory();
}

