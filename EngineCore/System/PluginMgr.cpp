#include "PluginMgr.h"
#include <windows.h>
#include "../Interface/IFactory.h"
typedef IRenderFactory* (*lp_render_createfactory)();
typedef ISoundFactory* (*lp_sound_createfactory)();
int32_t PluginMgr::Load(wchar_t* name)
{
	HMODULE hm = LoadLibrary(name);
	return (int32_t)hm;
}
IInterface* PluginMgr::CreateInstance(PluginType type, int32_t module)
{

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
}
void PluginMgr::Free(int32_t module)
{
	FreeLibrary((HMODULE)module);
}