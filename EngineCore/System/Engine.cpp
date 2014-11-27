#include "Engine.h"
//#include <windows.h>
#include <windows.h>
#include "../Interface/IFactory.h"
#include "PluginMgr.h"
namespace Limbo
{
	bool Engine::Create(int32_t bindWnd)
	{
		m_system.reset(new System());
		m_system->Create();
		m_input.reset(new Input());
		int32_t hm = PluginMgr::Instance()->Load(L"Render_D3d11.dll");
		m_render.reset((IRender*)PluginMgr::Instance()->CreateInstance(PluginType_Render,hm));
		int32_t hm1 = PluginMgr::Instance()->Load(L"Sound_Dsound.dll");
		m_sound.reset((ISound*)PluginMgr::Instance()->CreateInstance(PluginType_Sound,hm1));
		m_sound->Create();
		m_render->Create(bindWnd, 800, 600);
		return true;
	}
	bool Engine::Destory()
	{
		m_system->Destory();
		m_system.reset();
		m_input.reset();
		m_render->Destory();
		m_render.reset();
		m_sound->Destory();
		m_sound.reset();
		return true;
	}
	void Engine::Update(float deltatime)
	{

	}
	void Engine::Draw()
	{
		m_render->Draw();
	}
	bool Engine::CallSystemCmd(SystemCmd cmd, int32_t para0, int32_t para1)
	{
		switch (cmd)
		{
		case SystemCmd_OnClose:
			//PostQuitMessage(0);
			break;
		case SystemCmd_OnMinimized:
			break;
		case SystemCmd_OnMaximized:
			break;
		case 	SystemCmd_OnSize:
			m_render->OnSize(para0, para1);
			break;
		default:
			break;
		}
		return true;
	}
	bool Engine::InputHandler(int inputkey)
	{
		int s = inputkey;
		return true;
	}
}