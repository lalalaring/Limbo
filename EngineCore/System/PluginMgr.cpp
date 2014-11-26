#include "PluginMgr.h"
#include <windows.h>
#include "../Interface/IFactory.h"
typedef IRenderFactory* (*lp_Func_createfactory)();
int32_t PluginMgr::Load(wchar_t* name)
{
	HMODULE hm = LoadLibrary(name);

	return (int32_t)hm;
}
IInterface* PluginMgr::CreateInstance(int32_t module)
{
	lp_Func_createfactory func = (lp_Func_createfactory)GetProcAddress((HMODULE)module, "Create");
	IRenderFactory* fctory = func();
	IRender* render = fctory->Create();
	return render;
}
void PluginMgr::Free(int32_t module)
{

}