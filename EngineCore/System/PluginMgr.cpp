#include "PluginMgr.h"
#include <windows.h>
#include "../Interface/IFactory.h"
typedef int(*pgettype)();
typedef IRenderFactory* (*lp_render_createfactory)();
typedef ISoundFactory* (*lp_sound_createfactory)();
typedef IInputFactory* (*lp_input_createfactory)();
int32_t PluginMgr::Load(wchar_t* name)
{
	HMODULE hm = LoadLibrary(name);
	return (int32_t)hm;
}
IInterface* PluginMgr::CreateInstance(int32_t module)
{
	pgettype funcget = (pgettype)GetProcAddress((HMODULE)module, "GetType");
	int type = funcget();
	if (type == PluginType_Render)
	{
		lp_render_createfactory func0 = (lp_render_createfactory)GetProcAddress((HMODULE)module, "Create");
		IRenderFactory* fctory0 = func0();
		IRender* render = fctory0->Create();
		return render;
	}
	if (type == PluginType_Sound)
	{
		lp_sound_createfactory func1 = (lp_sound_createfactory)GetProcAddress((HMODULE)module, "Create");
		ISoundFactory* fctory1 = func1();
		ISound* sound = fctory1->Create();
		return sound;
	}
	if (type == PluginType_Input)
	{
		lp_input_createfactory func2 = (lp_input_createfactory)GetProcAddress((HMODULE)module, "Create");
		IInputFactory* fctory2 = func2();
		IInput* input = fctory2->Create();
		return input;
	}
}
void PluginMgr::Free(int32_t module)
{
	FreeLibrary((HMODULE)module);
}